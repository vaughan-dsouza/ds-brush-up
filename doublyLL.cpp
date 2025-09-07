#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

Node *head = nullptr;

// Add node at end
void addNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    cout << "Node added: " << value << endl;
}

// Add node at a specific position
void addNodeAt(int value, int position)
{
    if (position <= 0)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = value;

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        cout << "Node added at position " << 1 << ": " << value << endl;
        return;
    }

    if (position == 1)
    {
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
        cout << "Node added at head: " << value << endl;
        return;
    }

    Node *temp = head;
    int count = 1;
    while (temp->next != nullptr && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != nullptr)
        temp->next->prev = newNode;
    temp->next = newNode;

    cout << "Node added at position " << position << ": " << value << endl;
}

// Delete node by value
void deleteNode(int value)
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node *temp = head;

    // Deleting head
    if (head->data == value)
    {
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        delete temp;
        cout << "Node deleted: " << value << endl;
        return;
    }

    while (temp != nullptr && temp->data != value)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Value not found!" << endl;
        return;
    }

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;

    if (temp->prev != nullptr)
        temp->prev->next = temp->next;

    delete temp;
    cout << "Node deleted: " << value << endl;
}

// Display forward
void displayForward()
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node *temp = head;
    cout << "DLL Forward: ";
    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Display backward
void displayBackward()
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    cout << "DLL Backward: ";
    while (temp != nullptr)
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main()
{
    int choice, value, pos;
    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Node at End\n";
        cout << "2. Delete Node\n";
        cout << "3. Display Forward\n";
        cout << "4. Display Backward\n";
        cout << "5. Add Node at Position\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            addNode(value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteNode(value);
            break;
        case 3:
            displayForward();
            break;
        case 4:
            displayBackward();
            break;
        case 5:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> pos;
            addNodeAt(value, pos);
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
