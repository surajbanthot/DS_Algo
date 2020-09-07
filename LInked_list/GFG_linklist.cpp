#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

class LinkedList
{
    public:
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

    void printList(Node *node)
    {
        while(node!=NULL)
        {
            cout<<" "<<node->data;
            node=node->next;
        }
    }

    void deleteNode(Node **head_ref, int key)
    {
        Node* temp=*head_ref;
        Node* prev;
        if(temp !=NULL && temp->data==key)
        {
            *head_ref=temp->next;
            free(temp);
            return;
        }
        while(temp !=NULL && temp->data != key)
        {
            prev=temp;
            temp=temp->next;
        }

        if(temp==NULL)
        return;

        prev->next=temp->next;
        free(temp);
    }

    void DeleteNodeat(Node** head_ref, int pos)
    {
        if(*head_ref==NULL)
        return;

        Node* temp =*head_ref;
        if(pos==0)
        {
            *head_ref=temp->next;
            free(temp);
            return;
        }

        for(int i=0;temp!=NULL && i<pos-1;i++)
        temp=temp->next;

        if(temp==NULL || temp->next==NULL)
        return;

        Node* next=temp->next->next;
        free(temp->next);

        temp->next= next;

    }

};


int main()  
{  

    LinkedList l;
    /* Start with the empty list */
    Node* head = NULL;  
      
    // Insert 6. So linked list becomes 6->NULL  
    l.append(&head, 6);  
      
    // Insert 7 at the beginning.  
    // So linked list becomes 7->6->NULL  
    l.push(&head, 7);  
      
    // Insert 1 at the beginning.  
    // So linked list becomes 1->7->6->NULL  
    l.push(&head, 1);  
      
    // Insert 4 at the end. So  
    // linked list becomes 1->7->6->4->NULL  
    l.append(&head, 4);  
      
    // Insert 8, after 7. So linked  
    // list becomes 1->7->8->6->4->NULL  
    l.insertAfter(head->next, 8);  
      
    cout<<"Created Linked list is: ";  
    l.printList(head);  

    l.deleteNode(&head, 6);

    l.printList(head);
      
    return 0;  
}  