/*
https://www.youtube.com/watch?v=mg9yi6YuAVk&ab_channel=ApnaCollege 
Algo
if(operand)
    output operand
else if(right paranthesis)

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

string infixToPostFix(string in)
{
    string post;
    stack<char> st;
    for (int i = 0; i < in.size(); i++)
    {
        if (isalpha(in[i])) //if operand
        {
            post += in[i];
        }
        else if (in[i] == '(')
        {
            st.push(in[i]);
        }
        else if (in[i] == ')') //pop element from stack until we get '('
        {
            while (st.size() > 0 && st.top() != '(')
            {
                post += st.top();
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
                post += st.top();
                st.pop();
            }
            st.push(in[i]); //push current operator inside stack
        }
    }

    while (st.empty() == false)
    {
        post += st.top();
        st.pop();
    }

    return post;
}
int main()
{
    string in, post;
    cin >> in;

    post = infixToPostFix(in);
    cout << "Infix :  " << in << endl;
    cout << "Postfix : " << post << endl;
}