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

    if (head == nullptr)
    {
        head = newNode;
        head->next = head;
        head->prev = head;
    }
    else
    {
        Node *last = head->prev;

        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
    }
    cout << "Node added: " << value << endl;
}

// Add node at specific position
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
        head->next = head;
        head->prev = head;
        cout << "Node added at position " << position << ": " << value << endl;
        return;
    }

    if (position == 1)
    {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev = newNode;
        head->prev->next = newNode;
        head = newNode;

        cout << "Node added at head: " << value << endl;
        return;
    }

    Node *temp = head;
    int count = 1;
    while (temp->next != head && count++ < position - 1)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
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

    // Case: only one node
    if (head->next == head && head->data == value)
    {
        delete head;
        head = nullptr;
        cout << "Node deleted: " << value << endl;
        return;
    }

    // Search for node
    do
    {
        if (temp->data == value)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            if (temp == head)
            {
                head = temp->next; // update head if needed
            }

            delete temp;
            cout << "Node deleted: " << value << endl;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value not found!" << endl;
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
    cout << "CDLL Forward: ";
    do
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    } while (temp != head);
    cout << "(back to head)" << endl;
}

// Display backward
void displayBackward()
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node *temp = head->prev;
    cout << "CDLL Backward: ";
    do
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    } while (temp != head->prev);
    cout << "(back to tail)" << endl;
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
