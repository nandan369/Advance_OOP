#include "Conference.h"
#include <sstream>

Conference::Conference(const string& eventName, const string& eventDate, const string& location, const vector<string>& speakers, const string& topic)
    : Event(eventName, eventDate, location), speakers(speakers), topic(topic) {}

string Conference::getDetails() const {
    ostringstream speakerList;
    for (size_t i = 0; i < speakers.size(); ++i) {
        speakerList << speakers[i];
        if (i != speakers.size() - 1) { 
            speakerList << ", ";
        }
    }

    return "Conference: " + eventName + "\nDate: " + eventDate + "\nLocation: " + location + 
           "\nSpeakers: " + speakerList.str() + "\nTopic: " + topic;
}


