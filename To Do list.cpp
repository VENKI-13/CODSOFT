#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask() {
    string desc;
    cin.ignore(); // clear buffer
    cout << "Enter task description: ";
    getline(cin, desc);
    tasks.push_back({desc, false});
    cout << "Task added successfully!" << endl;
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }
    cout << "\nTo-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}

void markCompleted() {
    int index;
    viewTasks();
    if (tasks.empty()) return;

    cout << "Enter task number to mark as completed: ";
    cin >> index;

    if (index > 0 && index <= (int)tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void removeTask() {
    int index;
    viewTasks();
    if (tasks.empty()) return;

    cout << "Enter task number to remove: ";
    cin >> index;

    if (index > 0 && index <= (int)tasks.size()) {
        tasks.erase(tasks.begin() + (index - 1));
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n==== To-Do List Manager ====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting... Goodbye!" << endl; break;
            default: cout << "Invalid choice. Try again!" << endl;
        }
    } while (choice != 5);

    return 0;
}
