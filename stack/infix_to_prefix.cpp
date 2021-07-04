/*
https://youtu.be/snDDBjT8jYA

Algo 
1)reverse input string
2)now make opening bracket to closing and closing to opening
3)now apply logic of infix to postfix
*/

#include <bits/stdc++.h>
using namespace std;

int prec(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

string infixToPreFix(string in)
{
    string pre;
    stack<char> st;
    for (int i = 0; i < in.size(); i++)
    {
        if (isalpha(in[i])) //if operand
        {
            pre += in[i];
        }
        else if (in[i] == '(')
        {
            st.push(in[i]);
        }
        else if (in[i] == ')') //pop element from stack until we get '('
        {
            while (st.size() > 0 && st.top() != '(')
            {
                pre += st.top();
                st.pop();
            }
            if (st.size() > 0) //if not empty then pop '('
            {
                st.pop();
            }
        }
        else //if operator
        {
            //pop until we found operator which has low precedence than current operator

            while (st.empty() == false && prec(st.top()) >= prec(in[i]))
            {
                pre += st.top();
                st.pop();
            }
            st.push(in[i]); //push current operator inside stack
        }
    }

    while (st.empty() == false)
    {
        pre += st.top();
        st.pop();
    }

    reverse(pre.begin(),pre.end());//reverse string
    return pre;
}
int main()
{
    string in, pre;
    cin >> in;

    reverse(in.begin(), in.end());//reverse string

    // make opening to closing and closing to opening
    for(char &data:in)
    {
        if(data==')')
            data='(';
        else if(data=='(')
            data=')';
    }

    pre = infixToPreFix(in);
    cout << "Infix :  " << in << endl;
    cout << "Prefix : " << pre << endl;
}