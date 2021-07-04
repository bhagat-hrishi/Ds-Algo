#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct NODE{
    int data;
    NODE *nxt;
};
NODE *createNODE(ll d)
{
    NODE tmp=new NODE;
    tmp->data=d;
    tmp->nxt=NULL;
    return tmp;
}
bool isEmpty(NODE *h)
{
    if(h==NULL)
        return true;
    return false;
}
void push(NODE **head,ll d)
{
    tmp=createNODE(d);
    tmp->nxt=*head;
    *head=tmp;
}
void pop(NODE **head)
{
    if(isEmpty(*head))
        cout<<"Empty";
    else
    {
        NODE *tmp=*head;
        *head=(*head)->nxt;
        delete tmp;
    }
}
void display(NODE **head)
{
    if(isEmpty(*head))
        cout<<"Empty";
    else
    {
        NODE *tmp=*head;
        for(tmp!=NULL)
        {
            cout<<tmp->data;
            tmp=tmp->nxt;
        }
    }
}
ll getTop(NODE *head)
{
    if(h!=NULL)
        return head->data;
}
int main()
{
    ll d,opt;
    NODE *h=NULL;
    while(1)
    {
        cout<<"\n1:push\n2:pop\n3:top\n4:Display\n0:Exit";
        cin>>opt;
        if(opt==0)
            break;
        switch(opt)
        {
        case 1:
                co
        }
    }

}
