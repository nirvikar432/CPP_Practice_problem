#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Contact
{
    string phoneNumber;
    string email;
};

unordered_map<string, Contact> phonebook;

void addContact()
{
    string name;
    Contact newContact;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter phone number: ";
    cin >> newContact.phoneNumber;
    cout << "Enter email: ";
    cin >> newContact.email;

    phonebook[name] = newContact;
    cout << "Contact added!\n";
}

void searchContact()
{
    string name;
    cout << "Enter name to search: ";
    cin >> name;

    if (phonebook.find(name) != phonebook.end())
    {
        Contact contact = phonebook[name];
        cout << "Name: " << name << "\n";
        cout << "Phone number: " << contact.phoneNumber << "\n";
        cout << "Email: " << contact.email << "\n";
    }
    else
    {
        cout << "Contact not found.\n";
    }
}

int main()
{
    int choice;
    while (true)
    {
        cout << "Phonebook Management System\n";
        cout << "1. Add Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addContact();
            break;
        case 2:
            searchContact();
            break;
        case 3:
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}

/*

In this example, the unordered_map container is used to store contacts where the keys are the names
of the contacts. The addContact function adds a new contact to the hash map, and the searchContact
function searches for a contact by name and displays its information if found.
You can further expand and refine this example to include more features and error handling as needed.

*/