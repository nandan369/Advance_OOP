#ifndef NOTIFICATIONSYSTEM_H
#define NOTIFICATIONSYSTEM_H

#include "event.h"
#include <vector>
#include <string>
#include <chrono>
#include "DesignPattern.h"

class NotificationSystem {
public:
    void sendNotifications(const vector<unique_ptr<Event>>& events, const string& currentDate);
    
    bool isWithinNextDay(const string& eventDate, const string& currentDate);
    bool isWithinNextWeek(const string& eventDate, const string& currentDate);
};

#endif
