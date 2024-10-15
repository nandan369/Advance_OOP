#ifndef CONCERT_H
#define CONCERT_H

#include "Event.h"

/*
* Derived Class: Concert{} derived from Event class
*/
class Concert : public Event {
private:
    string bandName;
    string genre;

public:
    Concert(const string& eventName, const string& eventDate, const string& location, const string& bandName, const string& genre);
    string getDetails() const override;
};

#endif
