/*
 
You are given a binary tree rooted at 1. You have to find the mirror image of any node qi about node 1. If it doesn't exist then print -1.
Input:
First line of input is N and Q.
Next N-1 line consists of two integers and one character first of whose is parent node , second is child node and character "L" representing Left child and "R" representing right child.
Next Q lines represents qi.
Output:
For each qi print it mirror node if it exists else print -1.
NOTE: 1 is mirror image of itself.
Constraints:
1 <= N <= 103
1<= Q <= 103

SAMPLE INPUT 
10 8
1 2 R
1 3 L
2 4 R
2 5 L
3 6 R
3 7 L
5 8 R
5 9 L
7 10 R
2
5
3
6
1
10
9
4
SAMPLE OUTPUT 
3
6
2
5
1
-1
-1
7 



 
 
*/



#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<db, db> pdd;
stack<char> s;
class node{
public:
    int data;
    node * left;
    node * right;
    node(int data){
        this->data=data;
        this->left=this->right=NULL;
    }
};

node * curr_node;

void find(node * root, int num){
    if(root==NULL){
        return;
    }
    if(root->data==num){
        curr_node=root;
    }
    find(root->left, num);
    find(root->right, num);
}

void insert_node(int r, int num, int pos, node * root){
    node * new_node = new node(num);
    find(root, r);
    if(pos=='R'){
        curr_node->right=new_node;
    }else{
        curr_node->left=new_node;
    }
}


void print_inorder(node * root){
    if(root==NULL){
        return;
    }
    print_inorder(root->left);
    cout<<root->data<<" ";
    print_inorder(root->right);
}




int findmirror(node* root1,node* root2,int val)
{
        if(root1==NULL||root2==NULL)
            return -1;
        if(root1->data==val)
            return root2->data;
        if(root2->data==val)
            return root1->data;
        int ans=findmirror(root1->left,root2->right,val);
        if(ans!=-1)
            return ans;
        findmirror(root1->right,root2->left,val);
}



int main() {
    ll n,k;
    cin>>n>>k;
    int r,num;
    char pos;
    node * root = new node(1);
    //cout<<root->data<<endl;
    //cout<<"inorder is   ";
    //print_inorder(root);
    //cout<<"\n";
    while(--n>0){
        cin>>r>>num>>pos;
        insert_node(r,num,pos,root);
        //cout<<"inorder is   ";
    //print_inorder(root);
    //cout<<"\n";
    }
    while(k--){
        int m;
        cin>>m;
        if(m==root->data){
            cout<<root->data<<endl;
        }else{
            cout<<findmirror(root->left, root->right, m)<<endl;
        }

    }
    //print_inorder(root);
    return 0;
}
