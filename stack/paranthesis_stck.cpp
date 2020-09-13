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


// // CPP program to check for balanced parenthesis. 
// #include <bits/stdc++.h> 
// using namespace std; 

// // function to check if paranthesis are balanced 
// bool areParanthesisBalanced(string expr) 
// { 
// 	stack<char> s; 
// 	char x; 

// 	// Traversing the Expression 
// 	for (int i = 0; i < expr.length(); i++) { 
// 		if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') { 
// 			// Push the element in the stack 
// 			s.push(expr[i]); 
// 			continue; 
// 		} 

// 		// IF current current character is not opening 
// 		// bracket, then it must be closing. So stack 
// 		// cannot be empty at this point. 
// 		if (s.empty()) 
// 			return false; 

// 		switch (expr[i]) { 
// 		case ')': 

// 			// Store the top element in a 
// 			x = s.top(); 
// 			s.pop(); 
// 			if (x == '{' || x == '[') 
// 				return false; 
// 			break; 

// 		case '}': 

// 			// Store the top element in b 
// 			x = s.top(); 
// 			s.pop(); 
// 			if (x == '(' || x == '[') 
// 				return false; 
// 			break; 

// 		case ']': 

// 			// Store the top element in c 
// 			x = s.top(); 
// 			s.pop(); 
// 			if (x == '(' || x == '{') 
// 				return false; 
// 			break; 
// 		} 
// 	} 

// 	// Check Empty Stack 
// 	return (s.empty()); 
// } 

// // Driver program to test above function 
// int main() 
// { 
// 	string expr = "{()}[]"; 

// 	if (areParanthesisBalanced(expr)) 
// 		cout << "Balanced"; 
// 	else
// 		cout << "Not Balanced"; 
// 	return 0; 
// } 
