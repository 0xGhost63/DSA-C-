#include <iostream>
using namespace std;
#define SIZE 5


class Queue
{
    public:

    int front,rear;
    int arr[5]={0};

    Queue()
    {
        front=-1;
        rear=-1;
    }

    bool isEmpty()
    {
        return (front==-1 && rear==-1);
    }


    void enqueue(int value)
    {
        //Empty State
        if (isEmpty())
        {
            front++;
            rear++;
            arr[rear]=value;
        }
        //Full State
        else  if (rear==SIZE-1)
        {
            cout<<"Queue overflow ! \n";
        }
        //Normal State
        else 
        {
            rear++;
            arr[rear]=value;
        }

    }

    void dequeue()
    {
        //Empty State
        if (isEmpty())
        {
            cout<<"Queue is empty,can't delete the element !\n";
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
            front++;
        }
    }

    void currentState()
    {
        cout<<"The current elements in the queue are : ";
        for (int i : arr)
        {
            cout<<i<<" ";
        }
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
    Queue q;
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