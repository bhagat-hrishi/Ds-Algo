/*
BST property
-> The left subtree of a node contains only nodes with keys less than the nodes key.
-> The right subtree of a node contains only nodes with keys greater than the nodes key.
-> Both the left and right subtrees must also be binary search trees.

->The basic operations on a binary search tree take time proportional to the height of
the tree. For a complete binary tree with node n, such operations runs in O(lgn)
worst-case time. If the tree is a linear chain of n nodes (skew-tree), however, the
same operations takes O(n) worst-case time.


*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

//main class
class bstnode
{
public:
    ll data;
    bstnode *l;
    bstnode *r;
};
//to create node
bstnode *createNode(int d)
{
    bstnode *tmp = new bstnode();
    tmp->l = NULL;
    tmp->r = NULL;
    tmp->data = d;
    return tmp;
}
//insertion
bstnode *b_search_tree_insertion(bstnode *rt, ll key)
{
    if (rt == NULL)
    {
        rt = createNode(key);
        return rt;
    }
    if (rt->data > key)
    {

        rt->l = b_search_tree_insertion(rt->l, key);
        // cout<<endl<<rt->data<<" left-child: "<<rt->l->data<<endl;
    }
    else if (rt->data < key)
    {
        rt->r = b_search_tree_insertion(rt->r, key);
        // cout<<endl<<rt->data<<" right-child: "<<rt->r->data<<endl;
    }
    return rt;
}
//_______________________________________Deletion__________________________________

bstnode *b_search_tree_deletion(bstnode *rt, ll key)
{
    if (rt == NULL)
    {
        cout << "\nNo elements present inside tree";
    }
    else if (key < rt->data)
    {
        rt->l = b_search_tree_deletion(rt->l, key);
    }
    else if (key > rt->data)
    {
        rt->r = b_search_tree_deletion(rt->r, key);
    }
    else
    { //found

        if (rt->l && rt->r) //if node to deleted has both childs
        {
            bstnode *left_rightmost = rt->l;
            //finding rightmost child on left subtree( largest in left sub tree)
            while (left_rightmost->r != NULL)
                left_rightmost = left_rightmost->r;
            //assign value to current node
            rt->data = left_rightmost->data;

            //delete largest left subtree
            rt->l = b_search_tree_deletion(rt->l, rt->data);
        }
        else if (!rt->l && !rt->r) //if leaf node
        {
            bstnode *tp = rt;
            delete rt;
            return NULL;
        }
        else //if only one child
        {
            bstnode *tp = rt;
            if (rt->l == NULL) //if only right child
                rt = rt->r;
            if (rt->r == NULL) //if only left child
                rt = rt->l;
            delete tp;
        }
    }
    return rt;
}
//___________________________________________Inorder_____________________________
void b_search_tree_inorder(bstnode *rt)
{
    if (rt)
    {
        b_search_tree_inorder(rt->l);
        cout << rt->data << " ";
        b_search_tree_inorder(rt->r);
    }
}
// __________________bst max__________________
bstnode *b_search_tree_Max(bstnode *rt)
{
    if (rt == NULL)
        return NULL;
    if (rt->r == NULL) //find rightmost node which does not have right child
        return rt;
    return b_search_tree_Max(rt->r); //go right
    /*
Time Complexity: O(n), in worst case (when BST is a right skew tree).
Space Complexity: O(n), for recursive stack.
*/
}
bstnode *b_search_tree_Max_non_recursive(bstnode *rt)
{
    if (rt == NULL)
        return NULL;
    bstnode *curr = rt;
    while (curr->r != NULL)
    {
        curr = curr->r;
    }
    //return rightmost node in binary search tree
    return curr;

    /*
Time Complexity: O(n). //if skew worst case
Space Complexity: O(1).
*/
}

// ____________________bst min _________________
/*
Time Complexity: O(n). //if skew worst case
Space Complexity: O(1).
*/
bstnode *b_search_tree_Min(bstnode *rt)
{
    if (rt == NULL)
        return NULL;
    if (rt->l == NULL) //find leftmost node which does not have left child
        return rt;

    return b_search_tree_Min(rt->l); //go left
}
bstnode *b_search_tree_Min_non_recursive(bstnode *rt)
{
    if (rt == NULL)
        return NULL;
    bstnode *curr = rt;
    while (curr->r != NULL)
    {
        curr = curr->r;
    }
    //return rightmost node in binary search tree
    return curr;
}

//create BST from sorted array
bstnode *sorted_Array_To_Bst(ll a[], ll left, ll right)
{
    if (left > right)
        return NULL;
    bstnode *tmp;
    if (left == right) //this form leaf node
    {
        tmp = createNode(a[left]);
    }
    else
    {
        ll mid = left + (right - left) / 2;
        tmp = createNode(a[mid]);
        tmp->l = sorted_Array_To_Bst(a, left, mid - 1);
        tmp->r = sorted_Array_To_Bst(a, mid + 1, right);
    }
    return tmp;
}
//Check if AVL or not
//return -1 if not an AVL tree
ll max(ll x, ll y)
{
    return x > y ? x : y;
}
int isAVL(bstnode *rt)
{
    if (rt == NULL)
        return 0;
    ll left, right;
    left = isAVL(rt->l);
    if (left == -1) //if not left part not avl
        return -1;
    right = isAVL(rt->r);
    if (right == -1) //if right part is not AVL
        return -1;
    if (abs(left - right) > 1)
        return -1;
    return max(left, right);
}
//Element closest to given key
//https://stackoverflow.com/questions/6209325/how-to-find-the-closest-element-to-a-given-key-value-in-a-binary-search-tree
//pass root, key, closest (as ans) and min=INT_MAX;
void closestToGivenKey(bstnode *rt, ll key, ll &closest, ll &min)
{
    if (rt == NULL)
        return;
    if (rt->data == key)
    {
        closest = rt->data;
        return;
    }
    if (abs(key - rt->data) < min)
    {
        min = abs(key - rt->data); //changing min
        closest = rt->data;        //changing ans
    }
    if (key < rt->data)
        closestToGivenKey(rt->l, key, closest, min);
    else
        closestToGivenKey(rt->r, key, closest, min);
}

//find kth smallest element inside bst ???????????????????  wrong
//pass root, k  and count variable with 1 assigned value
void Kth_Smallest_Element(bstnode *rt, ll k, ll &cnt)
{
    if (rt)
    {
        if (k == cnt)
        {
            cout << rt->data << " ";
            return;
        }
        if (rt->l)
            Kth_Smallest_Element(rt->l, k, cnt);
        cnt++; //came from left so increase count
        if (k == cnt)
        {
            cout << rt->data << " ";
            return;
        }
        Kth_Smallest_Element(rt->r, k, cnt);
    }
}
//find kth largest element
//do Right-Root-Left traversal and while traversing decrease count and give ans
//if not possible return 0 or INT_MIN
ll kthLargest(bstnode *root, int k)
{
    if (!root)
        return 0;

    int ans = INT_MIN;
    stack<bstnode *> s;
    bstnode *curr = root;

    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->r;
        }
        curr = s.top();
        k--;
        if (k == 0)
        {
            ans = curr->data;
            break;
        }
        s.pop();
        curr = curr->l;
    }
    if (ans == INT_MIN)
        return -1;
    return ans;
    //Your code here
}
//print common nodes between 2 binary search tree ???????
void printCommonNodesInTwoBinaryTree(bstnode *r1, bstnode *r2)
{
    //if one of tree is empty
    if (!r1 || !r2)
    {
        cout << "Not possible";
        return;
    }
    stack<bstnode> s1, s2;
}
int main()
{
    // system("color B0");
    ll t, n;
    cin >> t;
    bstnode *rt = NULL;
    while (t--)
    {
        cin >> n;
        rt = b_search_tree_insertion(rt, n);
    }
    ll ans, min = 1;
    cout << endl;
    b_search_tree_inorder(rt);
    cout << "\nEnter value:\n";
    cin >> t;
    Kth_Smallest_Element(rt, t, min);

    // cout<<endl<<endl<<"Root data: "<<rt->data;
}
