#include "Workshop.h"


Workshop::Workshop(const string& eventName, const string& eventDate, const string& location, int duration, const string& instructor)
    : Event(eventName, eventDate, location), duration(duration), instructor(instructor) {}

string Workshop::getDetails() const {
    return "Workshop: " + eventName + "\nDate: " + eventDate + "\nLocation: " + location + 
           "\nDuration: " + to_string(duration) + " hours\nInstructor: " + instructor;
}
