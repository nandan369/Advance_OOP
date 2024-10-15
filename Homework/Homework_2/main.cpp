/* --------------------------------------------------------
 * File : Main.cpp
 * This file implements the main Event Management System with a console-based interface.
 * It allows users to create events, search, RSVP, manage notification preferences, view attendees, and send event notifications.
 * The system uses various design patterns like Factory and Strategy, providing dynamic functionality for event handling.
 * --------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <memory>
#include "DesignPattern.h"
#include "NotificationSystem.h"

/* --------------------------------------------------------
 * Function: rsvpToEvent
 * Usage: rsvpToEvent(events)
 * --------------------------------------------------------
 * This function allows a user to RSVP to a specific event by entering the event's name and their own name.
 * It searches for the event in the list of events, adds the user's RSVP if found, and provides feedback on the success or failure of the RSVP process.
 * ---------------------------------------------------------
 */
void rsvpToEvent(const vector<unique_ptr<Event>>& events) {
    string eventName;
    cout << "\nEnter the name of the event you'd like to RSVP to: ";
    cin.ignore();
    getline(cin, eventName);

    cout << "\nEnter your name: ";
    string userName;
    cin.ignore();
    getline(cin, userName);

    bool eventFound = false;

    for (const auto& event : events) {
        if (event->getDetails().find(eventName) != string::npos) {
            event->addRSVP(userName);
            eventFound = true;
            break;
        }
    }

    if (!eventFound) {
        cout << "Event not found.\n";
    }
}

void displayAttendees(const vector<unique_ptr<Event>>& events) {
    cout << "Enter the name of the event to view : ";
    string eventName;
    cin.ignore();
    getline(cin, eventName);

    bool eventFound = false;

    for (const auto& event : events) {
        // Find event by matching event name
        if (event->getDetails().find(eventName) != string::npos) {
            vector<string> rsvpList = event->getAttendees();  

            if (rsvpList.empty()) {
                cout << "No one has RSVP'd for this event yet.\n";
            } else {
                cout << "RSVP List for " << eventName << ":\n";
                for (const auto& attendee : rsvpList) {
                    cout << "- " << attendee << "\n";
                }
            }
            eventFound = true;
            break;
        }
    }

    if (!eventFound) {
        cout << "Event not found.\n";
    }
}

/* --------------------------------------------------------
 * Function: displayAttendees
 * Usage: displayAttendees(events)
 * --------------------------------------------------------
 * This function displays the list of attendees for a specified event.
 * It prompts the user to enter the event name, searches for the event in the list,
 * and if found, retrieves and displays the RSVP list. If no attendees are found or the event is not found, it provides appropriate feedback.
 * ---------------------------------------------------------
 */
void setNotificationPreference(vector<unique_ptr<Event>>& events) {
    string eventName;
    cout << "Enter the name of the event to set notification preference: ";
    cin.ignore();
    getline(cin, eventName);

    bool eventFound = false;

    for (auto& event : events) {
        if (event->getDetails().find(eventName) != string::npos) {
            string preference;
            cout << "\nEnter notification preference (Daily/Weekly): ";
            getline(cin, preference);

            event->setNotificationPreference(preference);
            cout << "\nNotification preference set to " << preference << " for " << eventName << ".\n";
            eventFound = true;
            break;
        }
    }

    if (!eventFound) {
        cout << "Event not found.\n";
    }
}


/* --------------------------------------------------------
 * Function: sendEventNotifications
 * Usage: sendEventNotifications(notificationSystem, events)
 * --------------------------------------------------------
 * This function sends notifications for upcoming events based on the current date provided by the user.
 * It prompts the user to enter the current date in the format YYYY-MM-DD and calls the 
 * sendNotifications method of the NotificationSystem to process and send the notifications for all relevant events.
 * ---------------------------------------------------------
 */
void sendEventNotifications(NotificationSystem& notificationSystem, const vector<unique_ptr<Event>>& events) {
    string currentDate;
    cout << "Enter the current date (YYYY-MM-DD): ";
    cin.ignore();
    getline(cin, currentDate);

    notificationSystem.sendNotifications(events, currentDate);
}

void displayMenu() {
    cout << "\nEvent Management System\n";
    cout << "1. Create a new event\n";
    cout << "2. Search for events\n";
    cout << "3. Display details of a specific event\n";
    cout << "4. List all upcoming events\n";
    cout << "5. RSVP to Event\n"; 
    cout << "6. Display Attendees\n";
    cout << "7. Set Notification Preference\n";
    cout << "8. Send Notifications\n";
    cout << "9. Exit\n";
    cout << "Select an option: ";
}

/* --------------------------------------------------------
 * Function: createNewEvent
 * Usage: createNewEvent(events)
 * --------------------------------------------------------
 * This function allows the user to create a new event by specifying the event type (Workshop, Concert, or Conference).
 * It uses the EventFactory to create the event and adds it to the list of events, providing confirmation upon successful creation.
 * ---------------------------------------------------------
 */

void createNewEvent(vector<unique_ptr<Event>>& events) {
    cout << "\nEnter event type (Workshop/Concert/Conference): ";
    string eventType;
    cin >> eventType;
    events.push_back(EventFactory::createEvent(eventType));
    cout << "Event created successfully!\n";
}

/* --------------------------------------------------------
 * Function: searchForEvents
 * Usage: searchForEvents(events)
 * --------------------------------------------------------
 * This function provides a user interface for searching events based on specified criteria: date, type, or location.
 * It prompts the user to select a search option, creates the appropriate search strategy using the Strategy pattern, 
 * and prepares to search the event list. If an invalid option is selected, it displays an error message.
 * ---------------------------------------------------------
 */
void searchForEvents(const vector<unique_ptr<Event>>& events) {
    cout << "\nSearch criteria:\n";
    cout << "1. Search by date\n";
    cout << "2. Search by type\n";
    cout << "3. Search by location\n";
    cout << "Select a search option: ";
    int option;
    cin >> option;

    unique_ptr<SearchStrategy> searchStrategy;

    if (option == 1) {
        string date;
        cout << "Enter date (YYYY-MM-DD): ";
        cin >> date;
        searchStrategy = make_unique<SearchByDate>(date);
    } else if (option == 2) {
        string eventType;
        cout << "Enter event type (Workshop/Concert/Conference): ";
        cin >> eventType;
        searchStrategy = make_unique<SearchByType>(eventType);
    } else if (option == 3) {
        string location;
        cout << "Enter Location : ";
        cin >> location;
        searchStrategy = make_unique<SearchByType>(location); 
    } else {
        cout << "Invalid option!\n";
        return;
    }

    auto results = searchStrategy->search(events);
    if (results.empty()) {
        cout << "No events found.\n";
    } else {
        for (const auto& event : results) {
            cout << event->getDetails() << endl;
        }
    }
}

/* --------------------------------------------------------
 * Function: displayEventDetails
 * Usage: displayEventDetails(events)
 * --------------------------------------------------------
 * This function displays the details of a specific event based on the index provided by the user.
 * It prompts the user to enter an event index, checks if the index is valid, 
 * and if so, retrieves and prints the event details; otherwise, it notifies the user of an invalid index.
 * ---------------------------------------------------------
 */
void displayEventDetails(const vector<unique_ptr<Event>>& events) {
    cout << "\nEnter event index (0 to " << events.size() - 1 << "): ";
    int index;
    cin >> index;

    if (index >= 0 && index < events.size()) {
        cout << events[index]->getDetails() << endl;
    } else {
        cout << "Invalid event index!\n";
    }
}

void listAllUpcomingEvents(const vector<unique_ptr<Event>>& events) {
    cout << "\nUpcoming Events:\n";
    for (const auto& event : events) {
        cout<<"\n";
        cout << event->getDetails() << endl;
    }
}

int main() {
    vector<unique_ptr<Event>> events;
    NotificationSystem notificationSystem;

    int option = 0;
    while (option != 9) {
        displayMenu();
        cin >> option;
        cin.ignore();

        switch (option) {
            case 1:
                createNewEvent(events);
                break;
            case 2:
                searchForEvents(events);
                break;
            case 3:
                displayEventDetails(events);
                break;
            case 4:
                listAllUpcomingEvents(events);
                break;
            case 5:
                rsvpToEvent(events);
                break; 
            case 6:
                displayAttendees(events);
                break;
            case 7:
                setNotificationPreference(events);
                break;
            case 8:
                sendEventNotifications(notificationSystem, events);
                break;
            case 9:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option! Please try again.\n";
        }
    }

    return 0;
}
