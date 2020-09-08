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
        if(last==NULL)
        {
            cout<<"List is empty\n";
            return;
        }

        p=last->next;
        
        do
        {
            cout<<p->data<<" ";
            p=p->next;
        } while (p!=last->next);
        
    }
};

int main()
{
    Node *last = NULL;
    CircularList c;
    last=c.addToEmpty(last, 10);
    //last=c.addToEmpty(last,20); this will return the last node 
    //in the list as the result of trying to insert in a non empty list
    c.traverse(last);

}