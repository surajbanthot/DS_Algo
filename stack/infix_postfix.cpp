#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    };
    void push(char x);
    char pop();
    void Display();
    int pre(char x);
    int isOperand(char x);
 char *InToPost(const char *infix);
    ;
};

void Stack::push(char x)
{
    Node *t = new Node();
    if (t == NULL)
    {
        cout << "Stack is Full\n";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

char Stack::pop()
{
    char x = -1;
    if (top == NULL)
        cout << "Stack is Empty\n";
    else
    {
        x = top->data;
        Node *t = top;
        top = top->next;
        delete (t);
    }
    return x;
}

void Stack::Display()
{
    Node *p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Stack::pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int Stack::isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
    {
        return 1;
    }
}

 char *Stack::InToPost(const char *infix)
{
    char *postfix;
    int i = 0, j = 0, len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            
                if (pre(infix[i]) > pre(top->data))
                    push(infix[i++]);
                else
                {
                    postfix[j++] = pop();
                }
            
        }
        }
        while (top != NULL)
            postfix[j++] = pop();
        postfix[j] = '\0';
        return postfix;
    
}

int main()
{
    Stack stk;
     const char *infix="a+b*c-d/e";
    stk.push('#');

    const char *postfix=stk.InToPost(infix);
    cout<<postfix;
    return 0;

}