#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularList
{
public:
    Node *addToEmpty(Node *last, int data)
    {

        if (last != NULL)
            return last;
        Node *temp = new Node();
        temp->data = data;
        last = temp;
        last->next = last;
        return last;
    }

    void traverse(Node *last)
    {
        Node *p;
        if (last == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        p = last->next;

        do
        {
            cout << p->data << " ";
            p = p->next;
        } while (p != last->next);
    }

    Node *addBegin(Node *last, int data)
    {
        if (last == NULL)
            return addToEmpty(last, data);

        Node *temp = new Node();

        temp->data = data;
        temp->next = last->next;
        last->next = temp;

        return last;
    }

    Node *addEnd(Node *last, int data)
    {

        if (last == NULL)
            return addToEmpty(last, data);

        Node *temp = new Node();

        temp->data = data;
        temp->next = last->next;
        last->next = temp;
        last = temp;

        return last;
    }

    Node *addAfter(Node *last, int data, int item)
    {
        if (last == NULL)
            return NULL;

        Node *temp = new Node();
        Node *p;
        p = last->next;
        do
        {
            if (p->data == item)
            {
                temp->data = data;
                temp->next = p->next;
                p->next = temp;

                if (p == last)
                    last = temp;
                return last;
            }
            p = p->next;
        } while (p != last->next);

        cout<<item<<" not present in the list. "<<endl;
        return last;
    }
};

int main()
{
    Node *last = NULL;
    CircularList c;
    last = c.addToEmpty(last, 10);
    last = c.addBegin(last, 20);
    //last=c.addToEmpty(last,20); this will return the last node
    //in the list as the result of trying to insert in a non empty list
    last = c.addEnd(last, 30);
    last=c.addAfter(last, 40,30);
    c.traverse(last);
}