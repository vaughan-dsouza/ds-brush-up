#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;

// Function to add node at end
void addNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

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
    }
    cout << "Node added: " << value << endl;
}

void addNodeAt(int value, int position)
{
    if (position <= 0)
    {
        cout << "invalid position, <= 0 given" << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    int count = 1;

    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head, *prev = head;

        while (count++ < position && temp != nullptr)
        {
            prev = temp;
            temp = temp->next;
        }

        newNode->next = temp;

        if (position == 1)
            head = newNode;
        else
            prev->next = newNode;
    }
    cout << "Node added: " << value << endl;
}

// rewrite of add node at
void addNodeAt2(int value, int position)
{
    if (position <= 0)
    {
        cout << "invalid position, <= 0 given" << endl;
        return;
    }

    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    int count = 1;

    if (head == nullptr || position == 1)
    {
        newNode->next = head;
        head = newNode;
        cout << "Node added: " << value << endl;
        return;
    }

    Node *temp = head;

    while (count++ < position - 1 && temp->next != nullptr)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node added: " << value << endl;
}

// Function to delete first occurrence of a value
void deleteNode(int value)
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted: " << value << endl;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != value)
    {
        temp = temp->next;
    }

    if (temp->next == nullptr)
    {
        cout << "Value not found!" << endl;
    }
    else
    {
        Node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Node deleted: " << value << endl;
    }
}

// Function to display linked list
void displayList()
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    Node *temp = head;
    cout << "Linked List: ";
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    int choice, value, position;
    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Display Linked List\n";
        cout << "4. Add Nod at\n";
        cout << "5. Exit\n";
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
            displayList();
            break;
        case 4:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter position: ";
            cin >> position;
            addNodeAt2(value, position);
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
