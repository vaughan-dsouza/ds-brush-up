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

    if (head == nullptr)
    {
        head = newNode;
        newNode->next = head; // point to itself
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    cout << "Node added: " << value << endl;
}

// Function to add node at a specific position
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
        newNode->next = head;
        cout << "Node added at position " << 1 << ": " << value << endl;
        return;
    }

    if (position == 1)
    {
        Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }
        newNode->next = head;
        last->next = newNode;
        head = newNode;
        cout << "Node added at head: " << value << endl;
        return;
    }

    Node *temp = head;
    int count = 1;
    while (temp->next != head && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Node added at position " << position << ": " << value << endl;
}

// Function to delete a node by value
void deleteNode(int value)
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node *curr = head;
    Node *prev = nullptr;

    // Special case: head node
    if (head->data == value)
    {
        Node *last = head;
        while (last->next != head)
        {
            last = last->next;
        }

        if (head == head->next)
        { // only 1 node
            delete head;
            head = nullptr;
        }
        else
        {
            last->next = head->next;
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Node deleted: " << value << endl;
        return;
    }

    // Search in rest of list
    do
    {
        prev = curr;
        curr = curr->next;
    } while (curr != head && curr->data != value);

    if (curr == head)
    {
        cout << "Value not found!" << endl;
        return;
    }

    prev->next = curr->next;
    delete curr;
    cout << "Node deleted: " << value << endl;
}

// Function to display circular linked list
void displayList()
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node *temp = head;
    cout << "Circular Linked List: ";
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)" << endl;
}

int main()
{
    int choice, value, pos;
    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Add Node at End\n";
        cout << "2. Delete Node\n";
        cout << "3. Display Circular Linked List\n";
        cout << "4. Add Node at Position\n";
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
            cin >> pos;
            addNodeAt(value, pos);
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
