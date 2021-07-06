#include <bits/stdc++.h>
using namespace std;
#define ll long long
//main class
class node
{
public:
    ll data;
    node *l;
    node *r;
};

//to create node
node *createNode(int d)
{
    node *tmp = new node();
    tmp->l = NULL;
    tmp->r = NULL;
    tmp->data = d;
    return tmp;
}

//to insert
// We insert element where we find left or right child null
void insert(node **rt, int d)
{
    node *tp = *rt;
    if (*rt == NULL)
    {
        //  cout<<endl<<"root"<<d;
        *rt = createNode(d);
        return;
    }
    queue<node *> q;
    q.push(tp);
    while (!q.empty())
    {
        tp = q.front();
        q.pop();
        if (tp->l == NULL)
        {
            //  cout<<endl<<"left of: "<<tp->data<<" "<<d;
            tp->l = createNode(d);
            break;
        }
        else
            q.push(tp->l);
        if (tp->r == NULL)
        {
            //  cout<<endl<<"right of: "<<tp->data<<" "<<d;
            tp->r = createNode(d);
            break;
        }
        else
            q.push(tp->r);
    }
}
//________________________________________All inorder_____________________________________________
//recursion
void normalInorder(node *rt)
{
    if (rt)
    {
        normalInorder(rt->l);
        cout << rt->data << " ";
        normalInorder(rt->r);
    }
}
void stack_Inorder(node *rt)
{
    if (!rt)
        return;
    node *tp = rt;
    stack<node *> s;

    while (tp != NULL || s.empty() == false)
    {
        //if left exist then go to left
        while (tp != NULL)
        {
            s.push(tp);
            tp = tp->l;
        }

        tp = s.top();
        s.pop();
        cout << tp->data << " ";
        //go to right and repeat same process
        tp = tp->r;
    }
}
void morrisInorder(node *rt)
{
    if (!rt)
        return;
    node *curr = rt;
    node *pre;
    while (curr != NULL)
    {
        if (curr->l == NULL)
        {
            cout << curr->data << " ";
            curr = curr->r;
        }
        else //left not null
        {
            pre = curr->l;
            //to go to left   and avoid more traversal
            while (pre->r != NULL && pre->r != curr)
            {
                pre = pre->r;
            }
            if (pre->r == NULL)
            {
                pre->r = curr;
                curr = curr->l;
            }
            else
            {
                pre->r = NULL;
                cout << curr->data << " ";
                curr = curr->r;
            }
        }
    }
}

//_______________________________preorde traversal__________________
void normal_Preorder(node *rt) //recursive preorder
{
    if (rt)
    {
        cout << rt->data << " ";
        normal_Preorder(rt->l);
        normal_Preorder(rt->r);
    }
}
void stack_Preorder(node *rt) //using stack
{
    if (!rt)
        return;
    node *curr = rt;
    stack<node *> s;
    while (curr != NULL || s.empty() == false)
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";
            s.push(curr);
            curr = curr->l;
        }
        curr = s.top();
        s.pop();
        curr = curr->r;
    }
}

//_______________________postOrder_______________________
//Left - Right - Root
void stack_PostOrder(node *root) //using 2 stack
{
    if (!root)
        return;
    stack<node *> tmp, ans;
    node *curr = root;
    tmp.push(curr);
    while (tmp.empty() == false)
    {
        curr = tmp.top();
        tmp.pop();
        ans.push(curr);
        if (curr->l)
            tmp.push(curr->l);
        if (curr->r)
            tmp.push(curr->r);
    }
    while (ans.empty() == false)
    {
        curr = ans.top();
        cout << curr->data << " ";
        ans.pop();
    }
}
void normal_PostOrder(node *rt) //recursive postorder
{
    if (rt)
    {
        normal_PostOrder(rt->l);
        normal_PostOrder(rt->r);
        cout << rt->data << " ";
    }
}
//find max element
int max_Element(node *rt)
{
    int Max = INT_MIN;
    if (!rt)
        return Max;
    if (!rt->l && !rt->r)
        return rt->data;
    int ldata = max_Element(rt->l);
    int rdata = max_Element(rt->r);
    //finding max from left and right
    if (ldata > rdata)
        Max = ldata;
    else
        Max = rdata;

    //checking max with current node
    if (Max < rt->data)
        Max = rt->data;
    return Max;
}
//30)_________________________Zig and Zag traversal___________________
//use 2 stacks for storing alternate levels
//for 1st stack store right child 1st then left child
//for 2nd stack store left child 1st then right child
void zig_Zag(node *rt)
{
    if (!rt)
        return;
    stack<node *> s1, s2;
    s1.push(rt);
    node *curr;
    cout << "Zig Zag Traversal\n";
    while (!s1.empty() || !s2.empty())
    {
        while (!s1.empty())
        {
            curr = s1.top();
            cout << curr->data << " ";
            s1.pop();
            if (curr->l)
                s2.push(curr->l);
            if (curr->r)
                s2.push(curr->r);
        }
        while (!s2.empty())
        {
            curr = s2.top();
            cout << curr->data << " ";
            s2.pop();
            if (curr->r)
                s1.push(curr->r);
            if (curr->l)
                s1.push(curr->l);
        }
    }
}
//find max without Recursion
int max_Element_No_Recursion(node *rt)
{
    int Max = INT_MIN;
    if (!rt)
        return Max;
    int ldata, rdata;
    queue<node *> q;
    node *curr = rt;
    q.push(rt);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr->l)
        {
            ldata = curr->l->data;
            q.push(curr->l);
        }
        if (curr->r)
        {
            rdata = curr->l->data;
            q.push(curr->r);
        }
        //find max from left and right
        if (ldata > rdata)
            Max = ldata;
        else
            Max = rdata;
        //compare with root
        if (curr->data > Max)
            Max = curr->data;
    }
    return Max;
}

// Search Element With recursion
bool searchElementWithRecursion(node *rt, ll d)
{
    // Base case
    if (!rt)
        return false;

    // if found
    if (rt->data == d)
        return true;

    // check to left
    if (rt->l)
        if (searchElementWithRecursion(rt->l, d) == true)
            return true;

    // if not found on left go to right
    return searchElementWithRecursion(rt->r, d);
}
//search Element Without Recursion
bool searchElement(node *rt, ll d)
{
    if (!rt)
        return false;
    bool ans = false;
    queue<node *> q;
    node *curr = rt;
    q.push(rt);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr->data == d)
        {
            ans = true;
            break;
        }
        if (curr->l)
            q.push(curr->l);
        if (curr->r)
            q.push(curr->r);
    }
    return ans;
}
//_______________________Size of binary tree(total no of nodes present inside binary tree)_________________________________
//Size with recursion
int tree_Size(node *rt)
{
    //if null return 0
    if (!rt)
        return 0;
    //if exist
    return 1 + tree_Size(rt->l) + tree_Size(rt->r);
}
//size of  tree without recursion
int tree_Size_No_Resursion(node *rt)
{
    int cnt = 0;
    if (!rt)
        return cnt;
    queue<node *> q;
    node *curr = rt;
    q.push(rt);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        cnt++;
        if (curr->l)
            q.push(curr->l);
        if (curr->r)
            q.push(curr->r);
    }
    return cnt;
}
//reverse level Order traversal
//use stack
//push root then right  & then left
void level_Order_Reverse(node *rt)
{
    if (!rt)
        return;
    queue<node *> q;
    node *curr = rt;
    q.push(rt);
    stack<node *> s;
    s.push(curr); //pushing root
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr->r)
        {
            s.push(curr->r);
            q.push(curr->r);
        }
        if (curr->l)
        {
            s.push(curr->l);
            q.push(curr->l);
        }
    }
    cout << "\nReverse Level Order Traversal: ";
    while (s.empty() == false)
    {
        cout << s.top()->data << " ";
        s.pop();
    }
}
//______________________________delete tree___________________________________
void delete_all(node *rt)
{
    if (rt)
    {
        delete_all(rt->l);
        delete_all(rt->r);
        delete rt; //delete node
    }
}
void delete_Tree(node **rt)
{
    delete_all(*rt);
    *rt = NULL; //assign null to root
}
//Height of Binary Tree
ll height_Of_Tree(node *rt)
{
    if (rt == NULL)
        return 0;

    ll lheight = height_Of_Tree(rt->l); //left height
    ll rheight = height_Of_Tree(rt->r); //right height

    //take max out of left and right
    if (lheight > rheight)
        return 1 + lheight;
    return 1 + rheight;
}
//height with no recursion
ll height_No_Recursion(node *rt)
{
    ll height = 0;
    if (!rt)
        return height;
    queue<node *> q;
    q.push(rt);
    node *tmp;
    ll sizeof_queue;
    while (!q.empty())
    {
        //store size of queue(no of nodes at level particular level)
        sizeof_queue = q.size();
        while (sizeof_queue > 0)
        {
            tmp = q.front();
            q.pop();
            if (tmp->l)
                q.push(tmp->l);
            if (tmp->r)
                q.push(tmp->r);
            sizeof_queue--;
        }
        height++;
    }
    return height;
}
//find deepest node in tree(last node in level order traversal)
void deep_Node(node *rt)
{
    if (!rt)
        return;
    queue<node *> q;
    q.push(rt);
    node *tmp;
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        if (tmp->l)
            q.push(tmp->l);
        if (tmp->r)
            q.push(tmp->r);
    }
    //deepest node is last node in level Order traversal
    cout << endl
         << "Deep node: " << tmp->data;
}
//Delete node in binary tree
//find deppest node  and replace data of node to be deleted with deepest ndoe
//delete deepest node
void delete_Node(node **rt, ll key)
{
    node *curr = *rt;
    if (!curr)
        return;
    queue<node *> q;
    node *to_del, *deepest, *parent = NULL;
    q.push(curr);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr->data == key)
            to_del = curr;
        if (curr->l)
            q.push(curr->l);
        if (curr->r)
            q.push(curr->r);
    }
    //now last node inside tree is deepest node
    deepest = curr;
    //swap data of deepest and node to be deleted
    std::swap(deepest->data, to_del->data);

    //to delete deepst node
    curr = *rt;
    //clear queue
    while (!q.empty())
        q.pop();

    q.push(curr);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr->l)
        {
            if (curr->l == deepest)
            {
                delete deepest;
                curr->l = NULL;
                break;
            }
            else
                q.push(curr->l);
        }
        if (curr->r)
        {
            if (curr->r == deepest)
            {
                delete deepest;
                curr->r = NULL;
                break;
            }
            else
                q.push(curr->r);
        }
    }
}
//Count of full nodes without recursion
//The set of all nodes with both left and right children are called full nodes.
ll count_Of_Full_Nodes(node *rt)
{
    ll cnt = 0;
    if (!rt)
        return cnt;
    queue<node *> q;
    node *curr = rt;
    q.push(rt);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr->l)
            q.push(curr->l);
        if (curr->r)
        {
            q.push(curr->r);
            //as right satisfy we have to check only left again
            if (curr->l)
                cnt++;
        }
    }
    return cnt++;
}
//Count of number of leaf without recursion
int count_Of_Leaf_Nodes(node *rt)
{
    ll cnt = 0;
    if (!rt)
        return cnt;
    queue<node *> q;
    node *curr = rt;
    q.push(rt);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr->r == NULL && curr->l == NULL)
            cnt++;
        else
        {
            if (curr->l)
            {
                q.push(curr->l);
            }
            if (curr->r)
            {
                q.push(curr->r);
            }
        }
    }
    return cnt;
}

//Count of Half nodes without recursion
//The set of all nodes with either left or right children but not both are called Half nodes
ll count_Of_Half_Nodes(node *rt)
{
    ll cnt = 0;
    if (!rt)
        return cnt;
    queue<node *> q;
    node *curr = rt;
    q.push(rt);
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr->l)
        {
            q.push(curr->l);
            if (!curr->r) //if not right
                cnt++;
        }
        if (curr->r)
        {
            q.push(curr->r);
            if (!curr->l) //if no left child
                cnt++;
        }
    }
    return cnt;
}
//Check whether 2 trees have identical structure
bool check_2_Identical(node *f, node *s)
{
    if (!f && !s) // both are empty
        return true;
    if (!f || !s) //if one is not empty
        return false;
    //check data + left subtree + right subtree
    return ((f->data == s->data) && check_2_Identical(f->l, s->l) && check_2_Identical(f->r, s->r));
}

/*

Diameter of Binary Tree - Number of nodes in longest path inside Binary Tree

To find height - O(n)
and  here we find height for all nodes i.e O(n) -> so total is O(n)*O(n) ===> O(n^2)
_____________________Diameter of Binary tree__________________
*/
ll Max_data(ll a, ll b)
{
    return a > b ? a : b;
}

ll diameter_Of_Tree(node *rt)
{
    if (!rt)
        return 0;
    ll l_height = height_Of_Tree(rt->l);
    ll r_height = height_Of_Tree(rt->r);
    //Some time diameter of  binary tree does not pass through root
    return Max_data(
        l_height + r_height + 1 /*diameter through root*/,
        Max_data(diameter_Of_Tree(rt->l), diameter_Of_Tree(rt->r)) //max from diameter of left and right
    );
}

/*
Find Level that has max sum in binary tree
Time Complexity: O(n). 
Space Complexity: O(n).

*/
ll level_That_Has_Max_Sum(node *rt)
{
    if (!rt) //if no tree exist
        return -1;
    ll sum_that_level = 0; //to calculate sum at particular level
    ll level = 1;          //to keep track of levels
    ll ans = 0;            //ans
    ll max_sum = INT_MIN;
    ll no_node_at_level = 0; //to calculate nodes at that level
    node *curr = NULL;
    queue<node *> q;
    q.push(rt);
    while (!q.empty())
    {
        no_node_at_level = q.size(); //q.size() gives no of nodes at that level
        sum_that_level = 0;          //initial sum at each level is 0
        while (no_node_at_level--)
        {
            curr = q.front();
            sum_that_level += curr->data;
            q.pop();
            if (curr->l)
                q.push(curr->l);
            if (curr->r)
                q.push(curr->r);
        }
        if (sum_that_level > max_sum)
        {
            max_sum = sum_that_level;
            ans = level;
        }
        level++;
    }
    //cout<<"max sum level: "<<ans;
    return ans;
}

//print all root-leaf paths
void printVector(vector<ll> &v)
{
    cout << endl;
    ll len = v.size();
    for (ll i = 0; i < len; i++)
        cout << "[ " << v[i] << " ]=>";
    cout << "[ NULL ]";

    //removing that leaf node
    v.pop_back();
}
void print_Path(node *rt, vector<ll> &v)
{
    if (rt == NULL)
        return;
    //while visiting 1st push node in vector
    v.push_back(rt->data);
    //if leaf node then print path upto this
    if (!rt->l && !rt->r)
        printVector(v);
    else
    {
        print_Path(rt->l, v);
        print_Path(rt->r, v);
    }
}
//21)___________________path with given sum_________________________refer- https://www.youtube.com/watch?v=aYwiLCCdb-k
//preorder traversal used
void printStack(stack<int> s)
{
    cout << "\n";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
void path_With_Given_Sum(node *rt, ll key)
{
    static stack<int> st;
    static int sum = 0;
    if (rt)
    {
        sum += rt->data;
        st.push(rt->data);
        if (sum == key)
            printStack(st);
        path_With_Given_Sum(rt->l, key);
        path_With_Given_Sum(rt->r, key);
        //removing added data
        sum -= rt->data;
        st.pop();
    }
}
//22)Sum of all elements in tree
ll sum_Of_All(node *rt)
{
    if (!rt)
        return 0;
    if (!rt->l && !rt->r) //if leaf return data
        return rt->data;
    return rt->data + sum_Of_All(rt->l) + sum_Of_All(rt->r);
}
//sum with no recursion
ll sum_Of_All_No_Recursion(node *rt)
{
    ll sum = 0;
    if (!rt)
        return sum;
    queue<node *> q;
    q.push(rt);
    node *curr = NULL;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        sum += curr->data;
        if (curr->l)
            q.push(curr->l);
        if (curr->r)
            q.push(curr->r);
    }
    return sum;
}
//24)Convert given tree into its mirror
//Mirror of a tree is another tree with left and right children of all non-leaf nodes interchanged.
node *make_Mirror(node *rt)
{

    if (rt)
    {
        make_Mirror(rt->l);
        make_Mirror(rt->r);

        // swap the pointers of this node
        node *tp = rt->l;
        rt->l = rt->r;
        rt->r = tp;
    }
    return rt;
}

/*
25)Check 2 tree mirror of each other or not
Time Complexity: O(n). Space Complexity: O(n).

*/
bool check_2_Tree_Mirror_or_not(node *rt1, node *rt2)
{
    if (!rt1 && !rt2) //if both are null return true
        return true;
    if (!rt1 || !rt2) //if one exist and another is null return false
        return false;
    if (rt1->data != rt2->data) //if data of 2 nodes is not equal return false
        return false;

    return check_2_Tree_Mirror_or_not(rt1->l, rt2->r) && check_2_Tree_Mirror_or_not(rt1->r, rt2->l);
}

//________________________________construct Binary tree from inorder and preorder traversal
// helper function
node *build_Tree_from_Inorder_Preorder(ll preIndex, ll inorder[], ll preorder[], ll instart, ll inend, map<int, int> &m)
{
    if (instart > inend)
        return NULL;
    node *rt;
    //select node from preorder taraversal
    ll data = preorder[preIndex];
    preIndex++;
    rt = createNode(data);
    if (instart == inend)
        return rt;
    //find inorder index of this node in inorder traversal
    ll inorder_index = m[data];

    //fill right and left sub tree by inorder traversal
    rt->l = build_Tree_from_Inorder_Preorder(preIndex, inorder, preorder, instart, inorder_index - 1, m);
    rt->r = build_Tree_from_Inorder_Preorder(preIndex, inorder, preorder, inorder_index + 1, inend, m);

    return rt;
}

node *construct_from_inorder_and_preorder(ll in[], ll pre[], ll sz)
{
    //use map to store inorder element value and its index
    map<int, int> m;
    for (int i = 0; i < sz; i++)
        m[in[i]] = i; //map element with its index in inorder array

    ll preIndex = 0;

    return build_Tree_from_Inorder_Preorder(preIndex, in, pre, 0, sz - 1, m);
}
//29)print Ancenstor of given node
bool print_Ancenstor(node *rt, ll key)
{
    if (rt == NULL)
        return false;
    if (rt->data == key)
    {
        cout << rt->data << " ";
        return true;
    }
    if (print_Ancenstor(rt->l, key) || print_Ancenstor(rt->r, key))
    {
        cout << rt->data << " ";
        return true;
    }
    return false;
}
/*
Check 2 trees are isomorphic or not
Two binary trees root1 and root2 are isomorphic if they have the same structure. 
Time Complexity: O(n). Space Complexity: O(n).
*/
bool isIsomorphic(node *r1, node *r2)
{
    if (!r1 && !r2) //if both not exist
        return true;

    if ((!r1 && r2) || (r1 && !r2)) //if one of them exist
        return false;

    return isIsomorphic(r1->l, r2->l) && isIsomorphic(r1->r, r2->r);
}

//top view of tree
/*
step 1 :
    calculate horizontal distance for each node and create map of it
    map=> [ node | horizontal_distance ]
step 2:
    do level order traversal and go level by level
    create map =>[horizontal_distance | value_of_node ]
    if data all ready present inside map do not update
    if not present then insert
*/
//function to calculate horizontal distance
void calHorizontalDistance(node *rt, int hd, map<node *, int> &m)
{
    if (rt == NULL)
        return;
    m[rt] = hd;
    calHorizontalDistance(rt->l, hd - 1, m);
    calHorizontalDistance(rt->r, hd + 1, m);
}
void topView(node *rt)
{
    if (!rt)
        return;
    map<node *, int> node__to_hod;
    calHorizontalDistance(rt, 0, node__to_hod);

    map<int, int> hod_to_val;
    queue<node *> q;
    node *curr;
    int horizontal_distance;
    int no_nodes_at_level = 0;
    q.push(rt);
    while (q.empty() == false)
    {
        no_nodes_at_level = q.size();
        for (int i = 0; i < no_nodes_at_level; i++)
        {
            curr = q.front();
            q.pop();
            horizontal_distance = node__to_hod[curr];
            if (hod_to_val[horizontal_distance] == 0)
            {
                hod_to_val[horizontal_distance] = curr->data;
            }
            if (curr->l)
                q.push(curr->l);
            if (curr->r)
                q.push(curr->r);
        }
    }

    //printing top view
    map<int, int>::iterator it = hod_to_val.begin();
    for (; it != hod_to_val.end(); ++it)
    {
        cout << it->second << " ";
    }
}

//______________________________Bottom view________________________
/*
step 1 :
    calculate horizontal distance for each node and create map of it
    map=> [ node | horizontal_distance ]
step 2:
    do level order traversal and go level by level
    create map =>[horizontal_distance | value_of_node ]
    if data all ready present inside map  update
    if not present then insert
*/
//function to calculate horizontal distance

void bottomView(node *rt)
{
    if (!rt)
        return;
    map<node *, int> node__to_hod;

    //to calculate horizontal distance use function at top view
    calHorizontalDistance(rt, 0, node__to_hod);

    map<int, int> hod_to_val;
    queue<node *> q;
    node *curr;
    int horizontal_distance;
    int no_nodes_at_level = 0;
    q.push(rt);
    map<int, int>::iterator it;
    while (q.empty() == false)
    {
        no_nodes_at_level = q.size();
        for (int i = 0; i < no_nodes_at_level; i++)
        {
            curr = q.front();
            q.pop();
            horizontal_distance = node__to_hod[curr];

            //if not present then insert if present then update
            hod_to_val[horizontal_distance] = curr->data;

            if (curr->l)
                q.push(curr->l);
            if (curr->r)
                q.push(curr->r);
        }
    }

    //printing top view
    it = hod_to_val.begin();
    for (; it != hod_to_val.end(); ++it)
    {
        cout << it->second << " ";
    }
}
//Vertical traversal of tree
/*
step 1 :
    calculate horizontal distance for each node and create map of it
    map=> [ node | horizontal_distance ]
step 2:
    do level order traversal and go level by level
    create map =>[horizontal_distance | list of nodes with horizontal distance ]
*/
void verticalTraversal(node *rt)
{
    if (!rt)
        return;
    map<node *, int> node__to_hod;

    //to calculate horizontal distance use function at top view
    calHorizontalDistance(rt, 0, node__to_hod);

    //declare horizontal distance and list of nodes
    map<int, list<int>> hod_to_list;
    queue<node *> q;
    node *curr;
    int horizontal_distance;
    int no_nodes_at_level = 0;
    q.push(rt);

    while (q.empty() == false)
    {
        no_nodes_at_level = q.size();
        for (int i = 0; i < no_nodes_at_level; i++)
        {
            curr = q.front();
            q.pop();
            horizontal_distance = node__to_hod[curr];

            //insert node inside map
            hod_to_list[horizontal_distance].push_back(curr->data);

            if (curr->l)
                q.push(curr->l);
            if (curr->r)
                q.push(curr->r);
        }
    }

    map<int, list<int>>::iterator it;
    cout << "\nVertical Traversal\n";
    for (it = hod_to_list.begin(); it != hod_to_list.end(); ++it)
    {
        for (list<int>::iterator lit = hod_to_list[it->first].begin(); lit != hod_to_list[it->first].end(); ++lit)
        {
            cout << *lit << " ";
        }
        cout << endl;
    }
}
//Check if binary tree is BST or notis
//pass min as INT_MIN and max as INT_MAX
bool checkBST(node *rt, ll min, ll max)
{
    if (rt == NULL)
        return true;

    //for each node check if more than min and less than max
    if (rt->data < min || rt->data > max)
        return false;

    return checkBST(rt->l, min, rt->data - 1) && checkBST(rt->r, rt->data + 1, max);
}
//______________remove all half nodes from tree_____________
node *reomve_Half_Node(node *rt)
{
    if (!rt)
        return NULL;
    rt->l = reomve_Half_Node(rt->l);
    rt->r = reomve_Half_Node(rt->r);

    if (rt->l == NULL && rt->l == NULL) //if root node
        return rt;
    if (rt->l == NULL) //if only  so half node so retrun roots right child
        return rt->r;
    if (rt->r == NULL) //if only so half node so retrun roots left child
        return rt->l;
    return rt;
}
//________________remove leaves_______________
//Time Complexity: O(n).
node *remove_Leaves(node *rt)
{
    if (rt == NULL)
        return NULL;
    if (rt->l == NULL && rt->r == NULL) //delete leaf and return null
    {
        delete rt;
        return NULL;
    }
    rt->l = remove_Leaves(rt->l);
    rt->r = remove_Leaves(rt->r);

    return rt;
}
//_____________________Max_Path_Sum_________________
ll max_Path_Sum(node *rt) //?????????????
{
    return 0;
}

//_______________________LCA________________________
//26)find lowest common ancenstor  of 2 nodes
node *LCA(node *rt, node *first, node *second)
{
    if (rt == NULL)
        return rt;
    if (rt == first || rt == second) //if any node match then return that node
        return rt;

    node *tmpleft = LCA(rt->l, first, second);
    node *tmpright = LCA(rt->r, first, second);

    //if we get nodes both from left and right side so this is LCA
    if (tmpleft && tmpright)
        return rt;
    else
        return tmpleft ? tmpleft : tmpright;
}
//_____________________check binary tree is complete or not____________________
//so last node that we visit should be null and after that we get any other node then it is false
/*
When we get NULL node 1st time set complete to 0 and if after that we not get
any  node then again we set complete to 1 and break if not found after that null node 
means that is last node so return true
*/
bool isComplete(node *rt)
{
    //empty or if contain only single
    if (!rt || (!rt->l && !rt->r))
        return true;
    queue<node *> q;
    node *curr;
    q.push(rt);
    int complete = 1;
    while (!q.empty())
    {
        curr = q.front();
        q.pop();
        if (curr->l)
        {
            if (complete)
                q.push(curr->l);
            else
            {
                complete = 1;
                break;
            }
        }
        else
            complete = 0;
        if (curr->r)
        {
            if (complete)
                q.push(curr->r);
            else
            {
                complete = 1;
                break;
            }
        }
        else
            complete = 0;
    }
    if (!complete)
        return true;
    return false;
}

int main()
{
    // system("color B0");
    ll t, n;
    cin >> t;
    node *rt = NULL;
    while (t--)
    {
        cin >> n;
        insert(&rt, n);
    }
    cout << endl;
    normalInorder(rt);
    cout << "\n";
    cout << "Complete:" << isComplete(rt);
}
