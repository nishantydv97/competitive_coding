/*


Monk has an array A having N distinct integers and a Binary Search Tree which is initially empty. He inserts all the elements of the array from index 1 to N in the BST in the order given in the array. But wait! The tree so formed turns out to be cursed. Monk is having some weird experiences since he made that tree.

So, now to stop all that, Monk has two options, to destroy the BST or to pray to God and ask for a solution. Now since Monk has to use this BST in a Code Monk Challenge, he cannot destroy it. So he prays to God.

God answer his prayers and sends an angel named Micro. Now, Micro asks Monk to find something. He tells him two values, X and Y, present in the BST and ask him to find the maximum value that lie in the path between node having value X and node having value Y. (including X and Y ).

Now since, Monk is very afraid of that tree he asks for your help.

Input:
First line consists of a single integer denoting N.
Second line consists of N space separated integers denoting the array A.
Third line consists of two space separated integers denoting X and Y.

Output:
Print the maximum value that lie in the path from node having value X and node having value Y in a new line.

Constraints:


It is ensured that values X and Y are present in the array.

SAMPLE INPUT 
5
4 7 8 6 3
3 7

SAMPLE OUTPUT 
7
Explanation
Binary Search Tree for the given array is given below

enter image description here

Path between node having value 3 and node having value 7 is 3 -> 4 -> 7. Maximum value that lies on this path is


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
#define MAX 1000000007
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<db, db> pdd;

class node{
    public:
    ll data;
    node * left;
    node * right;
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node * insert(node * root, ll data){
    if(root==NULL){
        node * tmp=new node(data);
        root=tmp;
        return root;
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }else{
        root->right=insert(root->right,data);
    }
    return root;
}
int maxx=0;
ll max(ll a, ll b){
    return a>b ? a : b;
}
void max_between(node * root, ll data){
    //cout<<"  max between maxx : "<<maxx<<" and root->data  :"<<root->data<<" ";
    maxx=max(root->data,maxx);
    //cout<<maxx<<endl;
    if(root->data==data){
        return;
    }
    if(data<root->data){
        max_between(root->left,data);
    }else{
        max_between(root->right,data);
    }
}

void search(node * root, ll data, vector<node *> & v){
    v.pb(root);
    if(root->data==data){
        return;
    }else{
        if(data<root->data){
            search(root->left,data,v);
        }else{
            search(root->right,data,v);
        }
    }
}
void inorder(node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    fast
    ll n;
    cin>>n;
    node * root=NULL;
    rep(i,n){
        ll tmp;
        cin>>tmp;
        root=insert(root,tmp);
    }
    //inorder(root);
    ll x,y;
    cin>>x>>y;
    vector<node *> v1;
    search(root,x,v1);
    vector<node *> v2;
    search(root,y,v2);
    
    
    
    //for(auto i : v1){cout<<i->data<<" ";}
    //cout<<"\n";
    //for(auto i : v2){cout<<i->data<<" ";}
    
    node * lca;
    ll j=0;
    
    while((j < sz(v1) && j < sz(v2)) && (v1[j]->data==v2[j]->data)){
        //lca=v1[i];
        //cout<<" j is "<<j<<endl;
        j++;
    }
    lca=v1[j-1];
    //cout<<"LCA is "<<lca->data<<endl;
    //cout<<endl;
    maxx=lca->data;
    max_between(lca,max(x,y));
    cout<<maxx<<endl;
}


