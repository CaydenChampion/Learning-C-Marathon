#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Class
class ToDoList {
private:
    vector<string> tasks; // STL data structure

public:
    // Function: Load tasks from file
    void loadFromFile() {
        ifstream file("tasks.txt");
        string task;

        while (getline(file, task)) {
            tasks.push_back(task);
        }

        file.close();
    }

    // Function: Save tasks to file
    void saveToFile() {
        ofstream file("tasks.txt");

        for (string task : tasks) {
            file << task << endl;
        }

        file.close();
    }

    // Function: Add a task
    void addTask() {
        string task;
        cout << "Enter a task: ";
        getline(cin, task);
        tasks.push_back(task);
        cout << "Task added!\n";
    }

    // Function: Remove a task
    void removeTask() {
        if (tasks.empty()) {
            cout << "No tasks to remove.\n";
            return;
        }

        int index;
        displayTasks();
        cout << "Enter task number to remove: ";
        cin >> index;
        cin.ignore();

        // Conditional
        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed.\n";
        } else {
            cout << "Invalid number.\n";
        }
    }

    // Function: Display tasks
    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }

        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
};

int main() {
    ToDoList todo;
    todo.loadFromFile();

    int choice;

    // Loop
    while (true) {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Remove Task\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        // Conditionals
        if (choice == 1) {
            todo.displayTasks();
        }
        else if (choice == 2) {
            todo.addTask();
        }
        else if (choice == 3) {
            todo.removeTask();
        }
        else if (choice == 4) {
            todo.saveToFile();
            cout << "Tasks saved. Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
