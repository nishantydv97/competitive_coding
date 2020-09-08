void bstToDll(Node *root, Node **head){
    
    if(root==NULL){
        return;
    }
    static Node *prev=NULL;
    
    bstToDll(root->left,head);
    if(prev==NULL){
        *head=root;
    }else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    bstToDll(root->right,head);
}

Node * bToDLL(Node *root)
{
    Node * head=NULL;
    bstToDll(root,&head);
    return head;
}

