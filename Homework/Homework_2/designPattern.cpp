/* --------------------------------------------------------
 * File: DesignPattern.cpp
 * Description: This file implements the EventFactory and search strategies for managing events.
 * It contains functions to create events of different types (Workshop, Concert, Conference) 
 * and search for events based on date, type, or location.
 * ---------------------------------------------------------
 */

#include "DesignPattern.h"

unique_ptr<Event> EventFactory::createEvent(const string& eventType) {
    if (eventType == "Workshop") {
        return make_unique<Workshop>("C++ Workshop", "2024-11-28", "Room A", 3, "John Doe");
    } else if (eventType == "Concert") {
        return make_unique<Concert>("Rock Concert", "2024-12-02", "Stadium", "The Band", "Rock");
    } else if (eventType == "Conference") {
        return make_unique<Conference>("Tech Conference", "2024-12-10", "Convention Center", vector<string>{"Alice", "Bob"}, "AI & Robotics");
    }
    return nullptr;
}

SearchByDate::SearchByDate(const string& date) : targetDate(date) {};

vector<Event*> SearchByDate::search(const vector<unique_ptr<Event>>& events) const {
    vector<Event*> result;
    for (const auto& event : events) {
        if (event->getDetails().find(targetDate) != string::npos) {
            result.push_back(event.get());
        }
    }
    return result;
}

// Constructor
SearchByType::SearchByType(const std::string& type) : targetType(type) {}

// Search Implementation
std::vector<Event*> SearchByType::search(const std::vector<std::unique_ptr<Event>>& events) const {
    std::vector<Event*> result;
    for (const auto& event : events) {
        // Check the type by trying dynamic_cast for each derived class
        if ((targetType == "Workshop" && dynamic_cast<Workshop*>(event.get())) ||
            (targetType == "Concert" && dynamic_cast<Concert*>(event.get())) ||
            (targetType == "Conference" && dynamic_cast<Conference*>(event.get()))) {
            result.push_back(event.get());
        }
    }
    return result;
}

// Constructor
SearchByLocation::SearchByLocation(const std::string& location) : targetLocation(location) {}

// Search Implementation
std::vector<Event*> SearchByLocation::search(const std::vector<std::unique_ptr<Event>>& events) const {
    std::vector<Event*> result;
    for (const auto& event : events) {
        // Check if the location matches the target location
        if (event->getLocation() == targetLocation) {
            result.push_back(event.get());
        }
    }
    return result;
}