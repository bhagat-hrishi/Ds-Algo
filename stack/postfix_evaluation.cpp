/*
Algo 
    1)if operand push inside stack
    2)if operator pop last 2 operand and do operation and store result inside stack
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string post;
    cin >> post;

    stack<int> st;
    int op1, op2;
    for (int i = 0; i < post.size(); i++)
    {
        if (post[i] >= '0' && post[i] <= '9')
        {
            st.push(post[i] - '0'); //convert char to int then push
        }
        else //if operand
        {
            op2 = st.top();
            st.pop();
            op1 = st.top();
            st.pop();
            switch (post[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    cout << "Evaluation for " << post << " : " << st.top() << endl;
}