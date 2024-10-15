#include "Concert.h"

Concert::Concert(const string& eventName, const string& eventDate, const string& location, const string& bandName, const string& genre)
    : Event(eventName, eventDate, location), bandName(bandName), genre(genre) {}

string Concert::getDetails() const {
    return "Concert: " + eventName + "\nDate: " + eventDate + "\nLocation: " + location + 
           "\nBand Name: " + bandName + " hours\ngenre: " + genre;
}
