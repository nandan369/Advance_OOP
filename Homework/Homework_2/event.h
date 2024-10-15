/*
 * File : event.h
 * Abstract Base Class: Event
 * This class represents a generic event with details such as event name, date, location, and RSVP list. 
 * It includes functions for managing attendees, checking if the event is upcoming, and handling notification preferences.
 */

#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/*
* Base Class: Event{}
*/
class Event {
protected:
    string eventName;
    string eventDate;
    string location;
    vector<string> rsvpList;
    string notificationPreference;

public:
    Event(const string& eventName, const string& eventDate, const string& location);
    virtual ~Event();

    virtual string getDetails() const = 0;
    bool isUpcoming() const;
    string getLocation() const;

    string getEventName() const {return eventName;}
    void addRSVP(const string& userName);
    bool isAttendee(const string& userName) const;
    vector<string> getAttendees() const; 
    
    void setNotificationPreference(const string& preference); // Set preference (Daily/Weekly)
    string getNotificationPreference() const; // Get notification preference
    string getEventDate() const { return eventDate; } //get EventDate
};

#endif
