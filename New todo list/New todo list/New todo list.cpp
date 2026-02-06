// New todo list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class ToDoList {
private:
    vector<string> tasks;

public:
    void loadFromFile() {
        ifstream file("tasks.txt");
        string task;

        while (getline(file, task)) {
            tasks.push_back(task);
        }

        file.close();
    }

    void saveToFile() {
        ofstream file("tasks.txt");

        for (string task : tasks) {
            file << task << endl;
        }

        file.close();
    }

    
    void addTask() {
        string task;
        cout << "Enter a task: ";
        getline(cin, task);
        tasks.push_back(task);
        cout << "Task added!\n";
    }

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

        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed.\n";
        }
        else {
            cout << "Invalid number.\n";
        }
    }

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

    while (true) {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. View Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Remove Task\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
