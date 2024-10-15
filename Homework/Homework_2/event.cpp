/*
 * File: event.cpp
 * Implementation of the Event class
 * Provides functionality for managing event details, checking if an event is upcoming, adding RSVP, and handling notification preferences.
 * Includes date comparison to determine if the event is in the future and RSVP management for attendees.
 */

#include "Event.h"
#include <algorithm>
#include <ctime>  // For getting the current date
#include <sstream> // For converting dates

using namespace std;

Event::Event(const string& eventName, const string& eventDate, const string& location)
    : eventName(eventName), eventDate(eventDate), location(location) {}

Event::~Event() {}

/* --------------------------------------------------------
 * Function: isUpcoming
 * Usage: event.isUpcoming()
 * --------------------------------------------------------
 * This function checks if the event's date is in the future compared to the current date.
 * It retrieves the current date in the YYYY-MM-DD format and compares it with the event date.
 * If the event date is later than the current date, it returns true, indicating the event is upcoming.
 * ---------------------------------------------------------*/

bool Event::isUpcoming() const {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    stringstream currentDateStream;
    currentDateStream << (1900 + ltm->tm_year) << "-" 
                      << (1 + ltm->tm_mon) << "-" 
                      << ltm->tm_mday;
    return eventDate > currentDateStream.str(); 
}

string Event::getLocation() const {
    return location;
}

/* --------------------------------------------------------
 * Function: addRSVP
 * Usage: event.addRSVP(userName)
 * --------------------------------------------------------
 * This function adds a user to the RSVP list for the event if they have not already RSVP'd.
 * It first checks whether the user is already in the RSVP list, and if not, adds them and displays a confirmation message.
 * If the user has already RSVP'd, it displays a message indicating that.
 * ---------------------------------------------------------*/
void Event::addRSVP(const string& userName) {
    if (!isAttendee(userName)) {
        rsvpList.push_back(userName);
        cout << userName << " has successfully RSVP'd to " << eventName << "!\n";
    } else {
        cout << userName << " has already RSVP'd.\n";
    }
}

/* --------------------------------------------------------
 * Function: isRSVPed
 * Usage: event.isRSVPed(userName)
 * --------------------------------------------------------
 * This function checks whether a specific user has already RSVP'd to the event.
 * ---------------------------------------------------------
*/

bool Event::isAttendee(const string& userName) const {
    return find(rsvpList.begin(), rsvpList.end(), userName) != rsvpList.end();
}

vector<string> Event::getAttendees() const {
    return rsvpList; // Return the list of attendees
}

void Event::setNotificationPreference(const std::string& preference) {
    notificationPreference = preference;
}

// Notification preference getter
std::string Event::getNotificationPreference() const {
    return notificationPreference;
}
