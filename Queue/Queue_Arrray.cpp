#include <bits/stdc++.h>

using namespace std;

class Queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    Queue()
    {
        front = rear - 1;
        size = 10;
        Q = new int[this->size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new int[this->size];
    }
    void enqueue(int x)
    {
        if (rear == size - 1)
            cout << "Queue Full\n";
        else
        {
            rear++;
            Q[rear] = x;
        }
    }

    int dequeue()
    {
        int x = -1;
        if (front == rear)
            cout << "Queue is Empty\n";
        else
        {
            x = Q[front + 1];
            front++;
        }
        return x;
    }

    void Display()
    {
        for (int i = front + 1; i <= rear; i++)
            cout <<Q[i]<<" ";
        cout<<"\n";
    }
};

int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.Display();
    return 0;
}