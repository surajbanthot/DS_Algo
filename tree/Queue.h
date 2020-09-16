#ifndef Queue_h
#define Queue_h
#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue()
    {
        front = rear - 1;
        size = 10;
        Q = new Node *[this->size];
    }
    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[this->size];
    }
    void enqueue(Node *x)
    {
        if (rear == size - 1)
            cout << "Queue Full\n";
        else
        {
            rear++;
            Q[rear] = x;
        }
    }

    Node *dequeue()
    {
        Node *x = NULL;
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
            cout << Q[i] << " ";
        cout << "\n";
    }
    int isEmpty() { return front == rear; }
};
#endif