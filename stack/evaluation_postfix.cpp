#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
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
    void push(int x);
    int pop();
    void Display();
    int pre(char x);
    int isOperand(char x);
    char *InToPost(const char *infix);
    int Eval(const char *postfix);
    ;
};

void Stack::push(int x)
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

int Stack::pop()
{
    int x = -1;
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
    postfix[j] = '\0';//ascii value from which postfix value has to be substracted. starting 0=48
    return postfix;
}

int Stack::Eval(const char *postfix)
{
    int i=0;
    int x1=0,x2=0,r=0;
    for(i=0;postfix[i]!='\0';i++)
    {
        if(isOperand(postfix[i]))
        {
            push(postfix[i]-'0');
        }
        else
        {
            
                x2=pop();x1=pop();
                switch(postfix[i])
                {
                    case '+':r=x1+x2;break;
                    case '-':r=x1-x2;break;
                    case '*':r=x1*x2;break;
                    case '/':r=x1/x2;break;
                }
                push(r);
            
        }
        
        
    }
    return top->data;
}

int main()
{
    Stack stk;
    const char *postfix = "234*+82/-";
    
    cout << stk.Eval(postfix);

    return 0;
}