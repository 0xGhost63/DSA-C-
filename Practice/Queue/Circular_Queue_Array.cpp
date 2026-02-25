#include <iostream>
using namespace std;
#define SIZE 6

class Circular_Queue
{
    public:
    int front,rear;
    int arr [SIZE]={0};

    Circular_Queue()
    {
        front=-1;
        rear=-1;
    }

    bool isEmpty()
    {
        return (front==-1 && rear==-1);
    }

    //Enqueuing 

    void enqueue(int value)
    {
        //Full State
        if (front==(rear+1)%SIZE)
        {
            cout<<"Queue Overflow\n";
        }
        //Empty State
        else if (isEmpty())
        {
            rear++;
            front++;
            arr[rear]=value;
        }

        //Normal State
        else
        {
            rear=(rear+1)%SIZE;
            arr[rear]=value;
        }

    }

    void dequeue()
    {
        //Empty State
        if (isEmpty())
        {
            cout<<"Queue is already empty ! Can't delete the element !\n";
        }
        //Full State
        else if (rear==front)
        {
            arr[front]=0;
            rear=-1;
            front=-1;
        }
        //Normal State
        else
        {
            arr[front]=0;
            front=(front+1)%SIZE;
        }
    }
    void currentState()
    {
        cout << "The current elements in the queue are:\n";
        cout << "-------------------------------------------\n";

        for (int i = 0; i < SIZE; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < SIZE; i++)
        {
            cout << (i == front ? "F " : (i == rear ? "R " : "  "));
        }
        cout << endl;

        cout << "-------------------------------------------\n";
    }

};

void menu()
{
    cout << "\n======QUEUE MENU======\n";
    cout << "1-Enqueue \n";
    cout << "2-Dequeue \n";
    cout << "0-Exit\n";
    cout << "Enter your choice : ";
}
int main()
{
    Circular_Queue q;
    int choice, value;

    do
    {
        menu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                q.enqueue(value);
                q.currentState();
                break;

            case 2:
                q.dequeue();
                q.currentState();
                break;


            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}