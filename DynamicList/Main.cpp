#include "List.h"
#include <iostream>

using namespace std;
int main() {
    List myList;

    int choice;
    int number, index;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add element\n";
        cout << "2. Add element with index\n";
        cout << "3. Remove element\n";
        cout << "4. Set element\n";
        cout << "5. Display list\n";
        cout << "6. Check if list is empty\n";
        cout << "7. Check the size of list\n";
        cout << "8. Check if list contains element\n";
        cout << "9. Check the index of element\n";
        cout << "10. Clear list\n";
        cout << "0. Quit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number to add: ";
            cin >> number;
            myList.add(number);
            break;
        case 2:
            cout << "Enter number to add: ";
            cin >> number;
            cout << "Enter index: ";
            cin >> index;
            myList.add(number, index);
            break;
        case 3:
            cout << "Enter index to remove: ";
            cin >> index;
            myList.remove(index);
            break;
        case 4:
            cout << "Enter index to set: ";
            cin >> index;
            cout << "Enter new number: ";
            cin >> number;
            myList.set(number, index);
            break;
        case 5:
            cout << "List: " << myList << endl;
            break;
        case 6:
            cout << (myList.isEmpty() ? "List is empty" : "List is not empty") << endl;
            break;
        case 7:
            cout << "The size of the list is " << myList.size() << endl;
            break;
        case 8:
            cout << "Enter number to check: ";
            cin >> number;
            cout << (myList.contains(number) ? "List contains the number" : "List does not contain the number") << endl;
            break;
        case 9:
            cout << "Enter the number: ";
            cin >> number;
            if (myList.indexOf(number) == -1) {
                cout << "List does not contain the number " << number << endl;
            }
            else {
                cout << "the index of the number " << number << " is " << myList.indexOf(number) << endl;
            }
            break;
        case 10:
            myList.clear();
            cout << "List cleared" << endl;
            break;
        case 0:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

