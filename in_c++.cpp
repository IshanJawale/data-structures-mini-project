#include <iostream>
#include <string>

using namespace std;

// Structure to represent a contact
struct Contact {
    string name;
    string phoneNumber;
    Contact* next; // Pointer to the next contact in the linked list
};

// Class for managing the phone book using linked list
class PhoneBook {
private:
    Contact* head; // Pointer to the head of the linked list

public:
    // Constructor to initialize an empty phone book
    PhoneBook() : head(nullptr) {}

    // Destructor to free memory when the phone book is destroyed
    ~PhoneBook() {
        clearPhoneBook();
    }

    // Function to add a contact to the phone book
    void addContact() {
        Contact* newContact = new Contact;
        cout << "Enter name: ";
        getline(cin >> ws, newContact->name);
        cout << "Enter phone number: ";
        cin >> newContact->phoneNumber;
        newContact->next = head;
        head = newContact;
        cout << "Contact added successfully!\n";
    }

    // Function to display all contacts in the phone book
    void displayContacts() const {
        if (head == nullptr) {
            cout << "Phone book is empty.\n";
        } else {
            cout << "Contacts in the phone book:\n";
            Contact* current = head;
            while (current != nullptr) {
                cout << "Name: " << current->name << "\tPhone Number: " << current->phoneNumber << "\n";
                current = current->next;
            }
        }
    }

    // Function to search for a contact by name
    void searchContact() const {
        string searchName;
        cout << "Enter the name to search: ";
        getline(cin >> ws, searchName);

        Contact* current = head;
        while (current != nullptr) {
            if (current->name == searchName) {
                cout << "Contact found!\n";
                cout << "Name: " << current->name << "\tPhone Number: " << current->phoneNumber << "\n";
                return;
            }
            current = current->next;
        }

        cout << "Contact not found.\n";
    }

    // Function to delete a contact by name
    void deleteContact() {
        if (head == nullptr) {
            cout << "Phone book is empty. Cannot delete.\n";
            return;
        }

        string deleteName;
        cout << "Enter the name to delete: ";
        getline(cin >> ws, deleteName);

        if (head->name == deleteName) {
            Contact* temp = head;
            head = head->next;
            delete temp;
            cout << "Contact deleted successfully!\n";
            return;
        }

        Contact* current = head;
        while (current->next != nullptr && current->next->name != deleteName) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Contact* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Contact deleted successfully!\n";
        } else {
            cout << "Contact not found.\n";
        }
    }

    // Function to perform bubble sort on the linked list based on contact names
    void sortContacts() {
        if (head == nullptr) {
            cout << "Phone book is empty. Cannot sort.\n";
            return;
        }

        for (Contact* i = head; i->next != nullptr; i = i->next) {
            for (Contact* j = head; j->next != nullptr; j = j->next) {
                if (j->name > j->next->name) {
                    // Swap data of j and j+1
                    swap(j->name, j->next->name);
                    swap(j->phoneNumber, j->next->phoneNumber);
                }
            }
        }

        cout << "Phone book sorted successfully!\n";
    }

    // Function to clear the entire phone book and free memory
    void clearPhoneBook() {
        Contact* current = head;
        while (current != nullptr) {
            Contact* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
};

int main() {
    PhoneBook phoneBook;

    int choice;
    do {
        cout << "\nPhone Book Operations:\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Sort Contacts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(); // Consume the newline character from the previous input

        switch (choice) {
            case 1:
                phoneBook.addContact();
                break;
            case 2:
                phoneBook.displayContacts();
                break;
            case 3:
                phoneBook.searchContact();
                break;
            case 4:
                phoneBook.deleteContact();
                break;
            case 5:
                phoneBook.sortContacts();
                break;
            case 6:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
