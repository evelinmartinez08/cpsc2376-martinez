#include <iostream>
#include <list>
#include <string>

void showMenu() {
    std::cout << "\n1. Add Task\n";
    std::cout << "2. Remove Task\n";
    std::cout << "3. Show Tasks\n";
    std::cout << "4. Exit\n";
    std::cout << "Choice: ";
}

void addTask(std::list<std::string>& tasks) {
    std::string task;
    std::cout << "Enter task: ";
    std::cin.ignore();
    std::getline(std::cin, task);
    tasks.push_back(task);
    std::cout << "Task added!\n";
}

void removeTask(std::list<std::string>& tasks) {
    int taskNumber;
    std::cout << "Enter task number to remove: ";
    std::cin >> taskNumber;
    
    if (taskNumber <= 0 || taskNumber > tasks.size()) {
        std::cout << "Invalid task number!\n";
        return;
    }
    
    auto it = tasks.begin();
    std::advance(it, taskNumber - 1);
    tasks.erase(it);
    std::cout << "Task removed!\n";
}

void showTasks(const std::list<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to show!\n";
        return;
    }
    std::cout << "Tasks:\n";
    int taskNumber = 1;
    for (const auto& task : tasks) {
        std::cout << taskNumber++ << ". " << task << '\n';
    }
}

int main() {
    std::list<std::string> tasks;
    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                removeTask(tasks);
                break;
            case 3:
                showTasks(tasks);
                break;
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}