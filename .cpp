#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string username;
    string password;

public:
    User(const string& username, const string& password)
        : username(username), password(password) {}

    string getUsername() const {
        return username;
    }
};

class Task {
private:
    string title;
    string description;
    string dueDate;
    int priority;  
    double duration;  
    User* user;

public:
    Task(const string& title, const string& description, const string& dueDate, int priority, double duration, User* user)
        : title(title), description(description), dueDate(dueDate), priority(priority), duration(duration), user(user) {}

    string getTitle() const {
        return title;
    }

    string getDescription() const {
        return description;
    }

    string getDueDate() const {
        return dueDate;
    }

    int getPriority() const {
        return priority;
    }

    double getDuration() const {
        return duration;
    }

    User* getUser() const {
        return user;
    }
};

int main() {
    string username, password, taskTitle, taskDescription, taskDueDate;
    int taskPriority;
    double taskDuration;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    User user(username, password);

    cout << "Enter task details:" << endl;
    cout << "Title: ";
    cin.ignore();
    getline(cin, taskTitle);
    cout << "Description: ";
    getline(cin, taskDescription);
    cout << "Due Date: ";
    getline(cin, taskDueDate);
    cout << "Priority (1-5): ";
    cin >> taskPriority;

    
    if (taskPriority < 1 || taskPriority > 5) {
        cout << "Invalid priority level. Setting priority to 1." << endl;
        taskPriority = 1;
    }

    cout << "Duration (in hours): ";
    cin >> taskDuration;

    
    if (taskDuration <= 0) {
        cout << "Invalid duration. Setting duration to 1 hour." << endl;
        taskDuration = 1.0;
    }

    Task task(taskTitle, taskDescription, taskDueDate, taskPriority, taskDuration, &user);

    cout << "\nTask Details:" << endl;
    cout << "Title: " << task.getTitle() << endl;
    cout << "Description: " << task.getDescription() << endl;
    cout << "Due Date: " << task.getDueDate() << endl;
    cout << "Priority: " << task.getPriority() << endl;
    cout << "Duration: " << task.getDuration() << " hours" << endl;
    cout << "Assigned User: " << task.getUser()->getUsername() << endl;

    return 0;
}
