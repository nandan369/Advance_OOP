#ifndef WORKSHOP_H
#define WORKSHOP_H

#include "Event.h"

/*
* Derived Class: Workshop{} derived from Event class
*/
class Workshop : public Event {
private:
    int duration;
    string instructor;

public:
    Workshop(const string& eventName, const string& eventDate, const string& location, int duration, const string& instructor);
    string getDetails() const override;
};

#endif
