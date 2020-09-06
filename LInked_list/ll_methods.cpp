#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#define MIN_INT -32768
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *first;
    Node *last;

public:
    LinkedList()
    {
        first = NULL;
        last = NULL;
    }
    LinkedList(int A[], int n);
    int max();
    void Display();
    int search(int key);
    void Insert(int pos, int x);
    void insertLast(int x);
    void insertSortedList(int x);
    int Delete(int pos);
    bool isSorted();
    // ~LinkedList();
};

bool LinkedList::isSorted()
{
    Node *p=first;
    int x=-32768;
    while(p!=NULL)
    {
        if(p->data<x)
        return false;
        x=p->data;
        p=p->next;
    }
return true;
}

int LinkedList::Delete(int pos)
{
    Node *p, *q;
    int x = -1, i;
    if (pos == 1)
    {
        x = first->data;
        p = first;
        first = first->next;
        delete p;
    }
    else
    {
        p = first;
        q = NULL;
        for (i = 0; i < (pos - 1) && (p); i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
}

void LinkedList::insertSortedList(int x)
{
    Node *t;
    t = new Node;
    t->data = x;
    t->next = NULL;
    Node *p, *q;
    p = first;
    q = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

void LinkedList::insertLast(int x)
{
    Node *t;
    t = new Node;
    t->data = x;
    t->next = NULL;
    Node *p;
    p = first;
    if (first == NULL)
        first = last = t;
    else
    {
        last->next = t;
        last = t;
    }
}

void LinkedList::Insert(int pos, int x)
{
    Node *t, *p;

    if (pos == 0)
    {
        t = new Node;
        t->data = x;
        t->next = first;
        first = t;
    }
    else if (p > 0)
    {
        p = first;
        for (int i = 0; i < (pos - 1) && (p); i++)
            p = p->next;
        if (p)
        {
            t = new Node;
            t->data = x;
            t->next = p->next;
            p->next = t;
        }
    }
}

//linear search
// int LinkedList::search(int key)
// {
//     Node *p = first;
//     int i = 1;
//     while (p != NULL)
//     {
//         if (key == p->data)
//             return i;
//         p = p->next;
//         i = i + 1;
//     }
//     return i;
// }

//Transposition method in linear search

int LinkedList::search(int key)
{
    Node *p = first;
    Node *q = NULL;
    int i = 1;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q = p->next;
            p->next = first;
            first->next = q;
            first = p;
            return i;
        }
        q = p;
        p = p->next;
        i = i + 1;
    }
    return i;
}

int LinkedList::max()
{
    Node *p = first;
    int max = p->data;
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        else
        {
            p = p->next;
        }
    }
    return max;
}
void LinkedList::Display()
{
    Node *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
LinkedList::LinkedList(int A[], int n)
{
    Node *t;
    int i = 0;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int main()
{
    int A[] = {3, 10, 6, 57};
    LinkedList l(A, 4);

    //Max element in list
    // int max_ele = l.max();
    // cout << "Max element within the given list " << max_ele << "\n";

    //Search element in list
    // cout << "Enter the element to be serached \n";
    // int key;
    // cin >> key;
    // int search_res = l.search(key);
    // cout << "element found at " << search_res << endl;

    //Insert element in list at a position
    // int pos = 0;
    // cout << "Enter the Index at which element has to be inserted \n";
    // cin >> pos;
    // cout<<"Enter the element to insert at the pos "<<pos<<" ";
    // int ele;
    // cin>>ele;
    // l.Insertat(pos, ele);
    // l.Insert(0, 1);
    // l.Insert(1, 20);
    // l.Insert(0, 34);
  
    // l.insertLast(20);

    // l.insertSortedList(60);

    // l.Delete(3);

    // if(l.isSorted())
    // cout<<"Linked List is Sorted\n";
    // else 
    // cout<<"List is not sorted\n";

    

    l.Display();
    return 0;
} 