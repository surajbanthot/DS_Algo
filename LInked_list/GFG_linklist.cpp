#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    void push(Node** head_ref, int new_data)
    {
        Node* new_node=new Node();
        new_node->data=new_data;
        new_node->next=(*head_ref);
        (*head_ref)=new_node;
    }
    void insertAfter(Node *prev_node,int new_data)
    {
        if(prev_node==NULL)
        {
            cout<<"The given grevious node cannot be NULL\n";
            return;
        }

        Node* new_node=new Node();

        new_node->data=new_data;
        new_node->next=prev_node->next;
        prev_node->next=new_node;
    }

    void append(Node** head_ref, int new_data)
    {
        Node* new_node= new Node();
        new_node->data=new_data;
        new_node->next=NULL;

        Node* last=*head_ref;

        if(*head_ref==NULL)
        {
            *head_ref=new_node;
            return;
        }

        while(last->next!=NULL)
        {
            last=last->next;
        }

        last->next=new_node;
        return;
    }
};



int main()
{

return 0;
}