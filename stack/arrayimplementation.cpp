#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INT_MAX 10
struct Astack
{
    ll top;
    ll *arr;
    ll capacity;
};
void init(Astack &obj)
{
    obj.top=-1;
    obj.capacity=INT_MAX;
    obj.arr=new ll[INT_MAX];
    if(!obj.arr)
        cout<<"not possible";
}
bool isEmpty(Astack &obj)
{
    if(obj.top==-1)
        return true;
    return false;
}
bool isFull(Astack &obj)
{

    if(obj.top==obj.capacity)
        return true;
    return false;
}
void push(Astack &obj,ll  tmp)
{
    obj.arr[++(obj.top)]=tmp;

}
void pop(Astack &obj)
{
    if(isEmpty(obj))
    {
        cout<<"stack is empty";
    }
    else
    {
        cout<<"\nsuccessfully popped "<<obj.arr[obj.top];
        obj.arr[obj.top--];
    }

}
int main()
{
    Astack obj;
    init(obj);
    ll opt,d,i;
    system("color B0");
    while(1)
    {
        cout<<"\n1:push\n2:pop\n3:top\n4:display\n5:isEmpty\n0:Exit\nOpt:";
        cin>>opt;
        if(opt==0)
            break;
        switch(opt)
        {
        case 1:
            cout<<"\nEnter data to push";
            cin>>d;
            push(obj,d);
            break;
        case 2:
            pop(obj);
            break;
        case 3:
            if(isEmpty(obj))
                cout<<"\nEmpty Stack";
            else
                cout<<"TOP: "<<obj.arr[obj.top];
            break;
        case 4:
            for(i=obj.top;i>=0;i--)
            {
                cout<<obj.arr[i]<<" ";
            }
            break;
        case 5:
            if(isEmpty(obj))
                cout<<"\nEmpty";
            else
                cout<<"\nNot Empty";
            break;



        }
    }


}
