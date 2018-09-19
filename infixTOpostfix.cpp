#include<iostream>
#include<stack>
#include<string>
using namespace std;
string convert(string exp);

int Precedence(char op1, char op2);

bool Operator(char c);

bool Operand(char c);

int main()
{
    string exp;
    cout<<"Enter Expression \n";
    getline(cin,exp);
    string postfix = convert(exp);
    cout<<"Output = "<<postfix;
}

string convert(string exp)
{
    stack<char> S;
    string postfix = "";
    for(int i = 0;i< exp.length();i++)
        {
        if(Operator(exp[i]))
        {
            while(S.top() != '('  && Precedence(S.top(),exp[i])&&!S.empty())
            {
                postfix+= S.top();
                S.pop();
            }
            S.push(exp[i]);
        }
        else if(Operand(exp[i]))
        {
            postfix +=exp[i];
        }

        else if (exp[i] == '(')
        {
            S.push(exp[i]);
        }

        else if(exp[i] == ')')
        {
            while(  S.top() !=  '(' && !S.empty()) {
                postfix += S.top();
                S.pop();
            }
            S.pop();
        }
    }

    while(!S.empty()) {
        postfix += S.top();
        S.pop();
    }

    return postfix;
}

bool Operand(char c)
{
    if(c >= 'A' && c <= 'Z') return true;
    return false;
}

bool Operator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' )
        return true;

    return false;
}

int setprecedence(char op)
{
    int k = -1;
    switch(op)
    {
    case '+':
    case '-':
        k= 1;
    case '*':
    case '/':
        k = 2;
    }
    return k;
}
int Precedence(char op1, char op2)
{
    int x = setprecedence(op1);
    int y = setprecedence(op2);
    return x > y ?  true: false;
}
