/*  Coder : Ankit Kumar 
 Task 3 - Build a c++ user driven program of simple contact management system . 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    string email;
};
//Function declare for contact management system
void displayMenu();
void addContact(vector<Contact>& contacts);
void viewContacts(const vector<Contact>& contacts);
void editContact(vector<Contact>& contacts);
void deleteContact(vector<Contact>& contacts);
void loadContacts(vector<Contact>& contacts, const string& filename);
void saveContacts(const vector<Contact>& contacts, const string& filename);

int main() {
    vector<Contact> contacts;
    const string filename = "contacts.txt";

    // Load contacts from file
    loadContacts(contacts, filename);

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Clear the newline character from input buffer

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                viewContacts(contacts);
                break;
            case 3:
                editContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                saveContacts(contacts, filename);
                cout << "Contacts saved. Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
//Fuction definition
void displayMenu() {
    cout << "\nContact Management System\n";
    cout << "1. Add Contact\n";
    cout << "2. View Contacts\n";
    cout << "3. Edit Contact\n";
    cout << "4. Delete Contact\n";
    cout << "5. Exit\n";
}

void addContact(vector<Contact>& contacts) {
    Contact newContact;

    cout << "Enter name: ";
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phoneNumber);
    cout << "Enter email address: ";
    getline(cin, newContact.email);

    contacts.push_back(newContact);
    cout << "Contact added successfully.\n";
}

void viewContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to display.\n";
        return;
    }

    cout << "\n----------------Contact List----------------\n";
    cout << "\nSn.\tName\tPhone No.\tEmails\n \n";
    for (size_t i = 0; i < contacts.size(); ++i) {
        cout << i + 1 << ".    " << contacts[i].name << "\t"
             << contacts[i].phoneNumber << "\t"
             << contacts[i].email << endl;
    }
}

void editContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to edit.\n";
        return;
    }

    int index;
    cout << "Enter the contact number to edit: ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > static_cast<int>(contacts.size())) {
        cout << "Invalid contact number!\n";
        return;
    }

    Contact& contact = contacts[index - 1];
    cout << "Editing contact: " << contact.name << endl;
    cout << "Enter new name (leave blank to keep current): ";
    string newName;
    getline(cin, newName);
    if (!newName.empty()) contact.name = newName;

    cout << "Enter new phone number (leave blank to keep current): ";
    string newPhoneNumber;
    getline(cin, newPhoneNumber);
    if (!newPhoneNumber.empty()) contact.phoneNumber = newPhoneNumber;

    cout << "Enter new email (leave blank to keep current): ";
    string newEmail;
    getline(cin, newEmail);
    if (!newEmail.empty()) contact.email = newEmail;

    cout << "Contact updated successfully.\n";
}

void deleteContact(vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "No contacts to delete.\n";
        return;
    }

    int index;
    cout << "Enter the contact number to delete: ";
    cin >> index;
    cin.ignore();

    if (index < 1 || index > static_cast<int>(contacts.size())) {
        cout << "Invalid contact number!\n";
        return;
    }

    contacts.erase(contacts.begin() + index - 1);
    cout << "Contact deleted successfully.\n";
}

void loadContacts(vector<Contact>& contacts, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "No existing contacts found.\n";
        return;
    }

    Contact contact;
    while (getline(file, contact.name)) {
        getline(file, contact.phoneNumber);
        getline(file, contact.email);
        contacts.push_back(contact);
    }

    file.close();
    cout << "Contacts loaded successfully.\n";
}

void saveContacts(const vector<Contact>& contacts, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cout << "Error saving contacts!\n";
        return;
    }

    for (const auto& contact : contacts) {
        file << contact.name << endl;
        file << contact.phoneNumber << endl;
        file << contact.email << endl;
    }

    file.close();
}
