/* --------------------------------------------------------
 * File: DesignPattern.h
 * Description: This header file defines the EventFactory and search strategies 
 * for managing events in the Event Management System. It includes the declaration 
 * of the EventFactory class for creating events and the SearchStrategy interface 
 * along with its concrete implementations for searching events by date, type, or location.
 * ---------------------------------------------------------
 */

#ifndef DESIGNPATTERN_H
#define DESIGNPATTERN_H

#include "Event.h"
#include "Workshop.h"
#include "Concert.h"
#include "Conference.h"
#include <memory>
#include<vector>

class EventFactory {
public:
    static unique_ptr<Event> createEvent(const string& eventType);
};

class SearchStrategy {
public:
    virtual vector<Event*> search(const vector<unique_ptr<Event>>& events) const = 0;
    virtual ~SearchStrategy() = default;
};


class SearchByDate : public SearchStrategy {
    private:
        string targetDate;

    public:
        SearchByDate(const string& date);
        vector<Event*> search(const vector<unique_ptr<Event>>& events) const override;
};

class SearchByType : public SearchStrategy {
    private:
        string targetType;

    public:
        SearchByType(const string& type);
        vector<Event*> search(const vector<unique_ptr<Event>>& events) const override;
};

class SearchByLocation : public SearchStrategy {
    private:
        string targetLocation;

    public:
        SearchByLocation(const string& location);
        vector<Event*> search(const vector<unique_ptr<Event>>& events) const override;
};
#endif

