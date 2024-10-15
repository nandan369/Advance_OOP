#ifndef CONFERENCE_H
#define CONFERENCE_H

#include "Event.h"
#include <vector>

/*
* Derived Class: Conference{} derived from Event class
*/
class Conference : public Event {
private:
    vector<string> speakers;
    string topic;

public:
    Conference(const string& eventName, const string& eventDate, const string& location, const vector<string>& speakers, const string& topic);
    string getDetails() const override;
};

#endif
