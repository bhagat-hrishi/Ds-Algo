/*
1)Trie is effecient information retrival data Structure
2) A trie is a tree and each node in it contains the number of pointers equal to the number of
characters of the alphabet. we consider only a to z
3)INSERT  AND SEARCH => O(key_length)
4)MEMORY REQUIRENMENT =>O(ALPHABET_SIZE  * key_length  * N)
    N = number of keys inside Trie
*/
#include<iostream>
#define ll long long
#define ALPHABET_SIZE 26 
using namespace std;

struct TrieNode{
    struct TrieNode *child[26]; //pointer another 26 trie
    
    //is_End it true if node represent end of word
    bool is_End;


    
};

//Function to create Node
TrieNode* createNode(){
    TrieNode* tmp = new TrieNode();
    tmp->is_End = false;    

    for(int i=0;i<26;i++)
        tmp->child[i]=NULL;
    
    return tmp;
}

void insert(TrieNode **root,string s){
    TrieNode *curr = *root;

    for(int i=0;i<s.length();i++){

        int index = s[i]-97 ;
        if(curr->child[index] == NULL){
            curr->child[index]=createNode();
        }

        curr = curr->child[index];
    }

    //making last node as leaf
    curr->is_End = true;

}

bool search(TrieNode *root, string s){
    TrieNode *curr = root;
    
    for(int i=0;i<s.length();i++){
        int index = s[i]-97;
        if(curr->child[index]==NULL)
            return false;
        
        curr = curr->child[index];
    }

    if(curr!=NULL && curr->is_End==true)
        return true;
    return false;
}

int main()
{
    int n,opt;
    string s;
    TrieNode *root = new TrieNode();
    while (1)
    {
        cout<<"\n1:Insert\n2:Find\n3:Exit\nOpt:";
        cin>>opt;
        if(opt<1 || opt >2)
            break;
        switch (opt)
        {
            case 1:
                cout<<"\nEnter string :";
                cin>>s;
                insert(&root,s);
                break;
            case 2:
                cout << "\nEnter string to find :";
                cin >> s;
                if(search(root,s))
                    cout<<"\nFound";
                else
                    cout<<"\nNot Found";
                break;
        }   
    }
    

}
