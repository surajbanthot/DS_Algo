#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

class doublylist
{
public:
    void push(Node **head_ref, int new_data)
    {
        Node *new_node = new Node();

        new_node->data = new_data;

        new_node->next = (*head_ref);

        new_node->prev = NULL;

        if ((*head_ref) != NULL)
            (*head_ref)->prev = new_node;

        (*head_ref) = new_node;
    }

    void insertBefore(Node **head_ref, Node *next_node, int new_data)
    {

        /*1. check if the given next_node is NULL */
        if (next_node == NULL)
        {
            printf("the given next node cannot be NULL");
            return;
        }

        /* 2. allocate new node */
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

        /* 3. put in the data */
        new_node->data = new_data;

        /* 4. Make prev of new node as prev of next_node */
        new_node->prev = next_node->prev;

        /* 5. Make the prev of next_node as new_node */
        next_node->prev = new_node;

        /* 6. Make next_node as next of new_node */
        new_node->next = next_node;

        /* 7. Change next of new_node's previous node */
        if (new_node->prev != NULL)
            new_node->prev->next = new_node;
        /* 8. If the prev of new_node is NULL, it will be 
       the new head node */
        else
            (*head_ref) = new_node;
    }

    void printlist(Node *node)
    {
        Node *last;

        cout << "\n Traversal in forward Direction \n";
        while (node != NULL)
        {
            cout << node->data << " ";
            last = node;
            node = node->next;
        }
        cout << "\n";

        cout << "\n Traversal in reverse Direction \n";
        while (last != NULL)
        {
            cout << last->data << " ";
            last = last->prev;
        }
        cout << "\n";
    }

    /* Given a reference (pointer to pointer) to the head  
of a DLL and an int, appends a new node at the end */
    void append(Node **head_ref, int new_data)
    {
        /* 1. allocate node */
        Node *new_node = new Node();

        Node *last = *head_ref; /* used in step 5*/

        /* 2. put in the data */
        new_node->data = new_data;

        /* 3. This new node is going to be the last node, so  
        make next of it as NULL*/
        new_node->next = NULL;

        /* 4. If the Linked List is empty, then make the new  
        node as head */
        if (*head_ref == NULL)
        {
            new_node->prev = NULL;
            *head_ref = new_node;
            return;
        }

        /* 5. Else traverse till the last node */
        while (last->next != NULL)
            last = last->next;

        /* 6. Change the next of last node */
        last->next = new_node;

        /* 7. Make last node as previous of new node */
        new_node->prev = last;

        return;
    }

    /* Function to delete a node in a Doubly Linked List.  
head_ref --> pointer to head node pointer.  
del --> pointer to node to be deleted. */
    void deleteNode(Node **head_ref, Node *del)
    {
        /* base case */
        if (*head_ref == NULL || del == NULL)
            return;

        /* If node to be deleted is head node */
        if (*head_ref == del)
            *head_ref = del->next;

        /* Change next only if node to be  
    deleted is NOT the last node */
        if (del->next != NULL)
            del->next->prev = del->prev;

        /* Change prev only if node to be  
    deleted is NOT the first node */
        if (del->prev != NULL)
            del->prev->next = del->next;

        /* Finally, free the memory occupied by del*/
        free(del);
        return;
    }
};

int main()
{
    Node *head = NULL;
    doublylist d;
    d.push(&head, 10);
    d.push(&head, 20);
    d.push(&head, 30);
    // d.insertBefore(&head, head->next->next, 49);
    // d.deleteNode(&head, head);
    d.deleteNode(&head, head->next);
    d.deleteNode(&head, head->next);
    d.printlist(head);

    return 0;
}