#include <iostream>
using namespace std;

#define SIZE 10

class Double_Sided_Queue
{
private:
    int front;
    int rear;
    int arr[SIZE];

public:
    Double_Sided_Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    bool isFull()
    {
        return ((rear + 1) % SIZE == front);
    }

    void pushRear(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;

        arr[rear] = value;
        cout << value << " inserted at rear.\n";
    }

    void pushFront(int value)
    {
        if (isFull())
        {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }

        if (isEmpty())
            front = rear = 0;
        else
            front = (front - 1 + SIZE) % SIZE;

        arr[front] = value;
        cout << value << " inserted at front.\n";
    }

    void popFront()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!\n";
            return;
        }

        cout << arr[front] << " removed from front.\n";

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    void popRear()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow!\n";
            return;
        }

        cout << arr[rear] << " removed from rear.\n";

        if (front == rear)
            front = rear = -1;
        else
            rear = (rear - 1 + SIZE) % SIZE;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";

        int i = front;
        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % SIZE;
        }
        cout << endl;
    }

    void showStatus()
    {
        cout << "\n----- CURRENT STATUS -----\n";
        cout << "Front Index: " << front << endl;
        cout << "Rear Index : " << rear << endl;

        if (isEmpty())
            cout << "Queue Condition: EMPTY\n";
        else if (isFull())
            cout << "Queue Condition: FULL\n";
        else
            cout << "Queue Condition: NORMAL\n";

        display();
        cout << "--------------------------\n";
    }
};

int main()
{
    Double_Sided_Queue dq;
    int choice, value;

    do
    {
        cout << "\n====== DOUBLE SIDED QUEUE MENU ======\n";
        cout << "1. Insert from Rear\n";
        cout << "2. Insert from Front\n";
        cout << "3. Delete from Front\n";
        cout << "4. Delete from Rear\n";
        cout << "5. Display Queue\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            dq.pushRear(value);
            dq.showStatus();
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            dq.pushFront(value);
            dq.showStatus();
            break;

        case 3:
            dq.popFront();
            dq.showStatus();
            break;

        case 4:
            dq.popRear();
            dq.showStatus();
            break;

        case 5:
            dq.showStatus();
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}