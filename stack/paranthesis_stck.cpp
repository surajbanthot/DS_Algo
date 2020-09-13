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
    int isBalanced(const char *exp);
};

void Stack::push(char x)
{
    Node *t = new Node();
    if (t == NULL)
        cout << "Stack is full";
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

int Stack::isBalanced(const char *exp)
{
    int i;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

int main()
{
    const char *exp = "((a+b)*(c-d))";

    Stack stk;

    if (stk.isBalanced(exp))
    {
        cout << "Expresion is balanced\n";
    }
    else
    {
        cout << "Expresion is not balanced\n";
    }
    return 0;
}