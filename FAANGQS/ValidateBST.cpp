bool isval(BinaryTreeNode<int> *root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data>=min&&root->data<=max){
        bool left=isval(root->left,min,root->data);
        bool right=isval(root->right,root->data,max);
        return left&&right;
    }
    else{
        return false;
    }
    
}
bool validateBST(BinaryTreeNode<int> *root) {
   return isval(root,INT_MIN,INT_MAX);
}