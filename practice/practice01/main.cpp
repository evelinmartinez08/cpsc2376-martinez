#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& vec);
void doubleVector(vector<int>& vec);
int caculateSum(const vector<int>& vec);
void printMultiples(const vector<int>& vec, int num);

int main() {
    vector<int> vec;
    int choice;
    
    do {
        // menu
        cout << "\nMenu Options: \n";
        cout << "1. Add an item to the vector\n";
        cout << "2. Print the vector\n";
        cout << "3. Double the vector\n";
        cout << "4. Find sum\n";
        cout << "5. Print multiples of a number\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int num;
                cout << "Enter a number to add: ";
                cin >> num;
                vec.push_back(num);
                break;
            }
            case 2:
                // print vector
                printVector(vec);
                break;
            case 3:
                // vector doubled
                doubleVector(vec);
                cout << "Vector doubled.\n";
                break;
            case 4: {
                // sum of al elements
                int sum = caculateSum(vec);
                cout << "The sum of all elements is: " << sum << endl;
                break;
            }
            case 5: {
                // prints multiples
                int num;
                cout << "Enter a number to find multiples: ";
                cin >> num;
                printMultiples(vec, num);
                break;
            }
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6.\n";
        }
    } while (choice != 6);

    return 0;
}

// function prints vector
void printVector(const vector<int>& vec) {
    if (vec.empty()) {
        cout << "The vector is empty.\n";
        return;
    }
    
    cout << "Vector contents: ";
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// function to double the vectors elements
void doubleVector(vector<int>& vec) {
    for (int& num : vec) {
        num *= 2;
    }
}

// function to calculate the sum of vectors elements
int caculateSum(const vector<int>& vec) {
    int sum = 0;
    for (int num : vec) {
        sum += num;
    }
    return sum;
}

// function to print elements that are multiples of a  number
void printMultiples(const vector<int>& vec, int num) {
    cout << "Multiples of " << num << ": ";
    bool found = false;
    for (int element : vec) {
        if (element % num == 0) {
            cout << element << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "No multiples found.";
    }
    cout << endl;
}