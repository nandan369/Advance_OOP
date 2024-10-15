#include "NotificationSystem.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

// Parse date in YYYY-MM-DD format into a struct tm
tm parseDate(const string& date) {
    tm tm = {};
    istringstream ss(date);
    ss >> get_time(&tm, "%Y-%m-%d");
    return tm;
}

// Calculate days between two dates
int daysBetween(const tm& date1, const tm& date2) {
    time_t time1 = mktime(const_cast<tm*>(&date1));
    time_t time2 = mktime(const_cast<tm*>(&date2));
    double difference = difftime(time2, time1) / (60 * 60 * 24);
    return static_cast<int>(difference);
}

// Check if the event is within the next day
bool NotificationSystem::isWithinNextDay(const string& eventDate, const string& currentDate) {
    tm eventTm = parseDate(eventDate);
    tm currentTm = parseDate(currentDate);
    return daysBetween(currentTm, eventTm) == 1;
}

// Check if the event is within the next week
bool NotificationSystem::isWithinNextWeek(const string& eventDate, const string& currentDate) {
    tm eventTm = parseDate(eventDate);
    tm currentTm = parseDate(currentDate);
    int days = daysBetween(currentTm, eventTm);
    return days > 0 && days <= 7;
}

// Send notifications to users based on their preferences (daily or weekly)
void NotificationSystem::sendNotifications(const vector<unique_ptr<Event>>& events, const string& currentDate) {
    for (const auto& event : events) {
        string preference = event->getNotificationPreference();

        if (preference == "Daily" && isWithinNextDay(event->getEventDate(), currentDate)) {
            cout << "Reminder: The event '" << event->getDetails() << "' is happening tomorrow!\n";
        } else if (preference == "Weekly" && isWithinNextWeek(event->getEventDate(), currentDate)) {
            cout << "Reminder: The event '" << event->getDetails() << "' is happening this week!\n";
        }
    }
}
