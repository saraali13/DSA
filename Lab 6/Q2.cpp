/*
Name: S. Sara Ali
ID: 23K-0070
*/

#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack
{
private:
    int top;
    int max_size;
    T *arr;

public:
    Stack(int size)
    {
        top = -1;
        max_size = size;
        arr = new T[max_size];
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push(T value)
    {
        if (top < max_size - 1)
        {
            arr[++top] = value;
        }
        else
        {
            cout << "Stack overflow!" << endl;
        }
    }

    T pop()
    {
        if (top != -1)
        {
            return arr[top--];
        }
        else
        {
            cout << "Stack underflow!" << endl;
            return '\0';  
        }
    }

    T peek()
    {
        return (top != -1) ? arr[top] : '\0';
    }

    bool isEmpty()
    {
        return top == -1;
    }
};


int getPrecedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}


bool isOperand(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

string manualReverse(string str)
{
    string reversed = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        reversed += str[i];
    }
    return reversed;
}

string convertToPostfix(string infix)
{
    Stack<char> operatorStack(infix.length());
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char currentChar = infix[i];

    
        if (isOperand(currentChar))
        {
            postfix += currentChar;
        }
        
        else if (currentChar == '(')
        {
            operatorStack.push(currentChar);
        }
       
        else if (currentChar == ')')
        {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(')
            {
                postfix += operatorStack.pop();
            }
            operatorStack.pop();  
        }
        
        else
        {
            while (!operatorStack.isEmpty() && getPrecedence(currentChar) <= getPrecedence(operatorStack.peek()))
            {
                postfix += operatorStack.pop();
            }
            operatorStack.push(currentChar);
        }
    }

    
    while (!operatorStack.isEmpty())
    {
        postfix += operatorStack.pop();
    }

    return postfix;
}

string manualReversePostfix(string postfix)
{
    string reversed = "";
    for (int i = postfix.length() - 1; i >= 0; i--)
    {
        reversed += postfix[i];
    }
    return reversed;
}

string convertToPrefix(string infix)
{
    string reversedInfix = manualReverse(infix);

    for (int i = 0; i < reversedInfix.length(); i++)
    {
        if (reversedInfix[i] == '(')
        {
            reversedInfix[i] = ')';
        }
        else if (reversedInfix[i] == ')')
        {
            reversedInfix[i] = '(';
        }
    }

    string postFix = convertToPostfix(reversedInfix);

    string prefix = manualReversePostfix(postFix);

    return prefix;
}

int main()
{
    string infixExpression;

    cout << "Enter an infix expression: ";
    cin >> infixExpression;

    string postfixExpression = convertToPostfix(infixExpression);

    string prefixExpression = convertToPrefix(infixExpression);

    cout << "The postfix expression is: " << postfixExpression << endl;
    cout << "The prefix expression is: " << prefixExpression << endl;

    return 0;
}
