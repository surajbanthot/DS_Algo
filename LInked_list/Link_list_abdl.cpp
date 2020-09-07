#include <bits/stdc++.h>
using namespace std;
#define MIN_INT -32768

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
public:
    void createfrmArray(int A[], int n)
    {
        int i;
        Node *last;
        Node *first = new Node();
        first->data = A[0];
        last = first;
        Node *t = new Node();
        for (i = 1; i < n; i++)
        {
            t->data = A[i];
            t->next = NULL;
            last->next = t;
            last = t;
        }
    }

    void push(Node **head_ref, int new_data)
    {

        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = (*head_ref);
        (*head_ref) = new_node;
    }

    void printlist(Node *node)
    {
        while (node != NULL)
        {
            cout << " " << node->data;
            node = node->next;
        }
    }

    void insertAfter(Node *prev_node, int new_data)
    {
        if (prev_node == NULL)
        {
            cout << "The given previous Node cannot be NULL\n";
            return;
        }

        Node *new_node = new Node();

        new_node->data = new_data;
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
    void append(Node **head_ref, int new_data)
    {
        Node *new_node = new Node();
        new_node->data = new_data;
        new_node->next = NULL;

        Node *last = *head_ref;

        if (*head_ref == NULL)
        {
            *head_ref = new_node;
            return;
        }

        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = new_node;
        return;
    }

    void deleteNode(Node **head_ref, int key)
    {
        Node *temp = *head_ref;
        Node *prev;
        if (temp != NULL && temp->data == key)
        {
            *head_ref = temp->next;
            free(temp);
            return;
        }
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        prev->next = temp->next;
        free(temp);
    }

    void DeleteNodeat(Node **head_ref, int pos)
    {
        if (*head_ref == NULL)
            return;

        Node *temp = *head_ref;
        if (pos == 0)
        {
            *head_ref = temp->next;
            free(temp);
            return;
        }

        for (int i = 0; temp != NULL && i < pos - 1; i++)
            temp = temp->next;

        if (temp == NULL || temp->next == NULL)
            return;

        Node *next = temp->next->next;
        free(temp->next);

        temp->next = next;
    }

    void RevDisplay(Node *p)
    {
        if (p != NULL)
        {
            RevDisplay(p->next);
            cout << p->data << " ";
        }
    }

    int max(Node *p)
    {
        //Iterative method
        // int m=-32768;
        // while(p)
        // {
        //     if(p->data>m)
        //     m=p->data;
        //     p=p->next;
        // }
        // return (m);

        //recursive method

        int x = 0;
        if (p == 0)
        {
            return MIN_INT;
        }
        else
        {
            x = max(p->next);
            if (x > p->data)
                return x;
            else
                return p->data;
        }
    }

    Node *Search(Node **head, int key)
    {
        // // Iterative Method
        // while (p != NULL)
        // {
        //     if (key == p->data)
        //         return (p);
        //     p = p->next;
        // }
        // return NULL;

        //Recursive Method
        // if (p == NULL)
        //     return NULL;
        // if (key == p->data)
        //     return (p);
        // return Search(p->next, key);

        struct Node *q;
        Node *p = *head;
        while (p != NULL)
        {
            if (key == p->data)
            {
                q->next = p->next;
                p->next = *head;
                *head = p;
                return *head;
            }
            q = p;
            p = p->next;
        }

        return NULL;
    }

    Node *insertAtlast(Node **head, int data)
    {
        Node *t = new Node();
        t->data = data;
        t->next = NULL;

        Node *last;

        if(*head==NULL)
        {
            t=*head;
            return t;
        }else
        {
            last=*head;
            while(last->next!=NULL)
            {
                last=last->next;
            }
            last->next=t;
            t->next=NULL;
            last=t;
            return *head;
        }
    }
};

int main()
{
    Node *head = NULL;
    Node *temp;
    LinkedList l;
    // int A[] = {2, 3, 4, 5, 343, 54};
    // l.createfrmArray(A, 6);

    //simillar to pushing an element into a stack
    l.push(&head, 63);
    l.push(&head, 53);
    l.push(&head, 43);
    l.push(&head, 32);

    //add's an element to the tail of the linkedList
    l.append(&head, 58);
    //Inserts an element after the head's next ->next as the pointer is at head->next
    l.insertAfter(head->next, 8);

    cout << "Created Linked list is:\n";
    l.printlist(head);
    //Deleting an first instance of the element in by passing the key as parameter
    l.deleteNode(&head, 6);

    //Reverse Display
    cout << "\nRecursive  Reverse display\n";
    l.RevDisplay(head);

    cout << "\nprint list\n";
    l.printlist(head);

    //Max of linked list
    cout << "\nMaximum element within the present linked list is "
         << l.max(head) << "\n";

    //Searching within a Liked list
    cout << "To find the element in List: " << endl;
    temp = l.Search(&head, 43);

    if (temp)
    {
        cout << "Element present in list element:" << temp->data<<"\n";
    }
    else
    {
        cout << "Key cannot be found in list\n";
    }

    l.insertAtlast(&head, 87);

    l.insertAtlast(&head, 56);

    l.printlist(head);

    return 0;
}