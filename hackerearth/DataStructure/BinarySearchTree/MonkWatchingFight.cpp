/*
 Once Monk was watching a fight between an array and a tree, of being better. Tree got frustrated and converted that array into a Binary Search Tree by inserting the elements as nodes in BST, processing elements in the given order in the array. Now Monk wants to know the height of the created Binary Search Tree.

Help Monk for the same.

Note:

1) In Binary Search Tree, the left sub-tree contains only nodes with values less than or equal to the parent node; the right sub-tree contains only nodes with values greater than the parent node.

2) Binary Search Tree with one node, has height equal to 1.

Input Format :

The first line will consist of 1 integer N, denoting the number of elements in the array.
In next line, there will be N space separated integers , A[i], Where 1<=i<=N , denoting the elements of array.


Output Format

Print the height of the created Binary Search Tree.

SAMPLE INPUT
4
2 1 3 4
SAMPLE OUTPUT
3
Explanation
N=4.

Insert 2. It becomes root of the tree.
Insert 1. It becomes left child of 2.
Insert 3. It becomes right child of 2.
Insert 4. It becomes right child of 3.
Final height of tree = 3.



*/


/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
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



class node{
    public:
    int data;
    node * left;
    node * right;
    node(ll data){
        this->data=data;
        this->left=this->left=NULL;
    }
};



node * insert_node(node * root, int data){
    if(root==NULL){
        return new node(data);
    }else{
        if(data<=root->data){
            root->left=insert_node(root->left, data);
        }else{
            root->right=insert_node(root->right, data);
        }
        return root;
    }
}


int hight_of_bst(node * root){
    if(root==NULL){
        return 0;
    }
    return(1+max(hight_of_bst(root->left),hight_of_bst(root->right)));
}

int main(){
    ll n;
    cin>>n;
    node * root=NULL;
    for(ll i=0;i<n;i++){
        ll in;
        cin>>in;
        root=insert_node(root,in);
    }
    cout<<hight_of_bst(root);
    return 0;
}
