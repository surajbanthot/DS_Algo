#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void sortedInsert(Node **, Node *);

void insertSort(Node **head_ref)
{
    Node *sorted=NULL;

    Node *current=*head_ref;

    while(current!=NULL)
    {
        Node *next =current->next;
        sortedInsert(&sorted, current);

        current=next;
    }

    *head_ref=sorted;
}

void sortedInsert(Node **head_ref, Node * new_node)
{
    Node *current;
    if(*head_ref ==NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next=*head_ref;
        *head_ref=new_node;
    }else 
    {
        current=*head_ref;
        while(current->next!=NULL && current->next->data <new_node->data)
        {
            current=current->next;
        }
        new_node->next=current->next;
        current->next=new_node;
    }
}

void printlist(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


void push(Node **head_ref, int new_data)
{
    Node *new_node =new Node();
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}


int main()
{
    Node *a=NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    cout<<"Linked List before sorting \n";
    printlist(a);

    insertSort(&a);

    cout<<"\nLinked list after sorting \n";
    printlist(a);



    return 0;
}