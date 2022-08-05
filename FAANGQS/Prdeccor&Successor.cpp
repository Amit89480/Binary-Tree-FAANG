
    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pred=-1;
    int suc=-1;
     BinaryTreeNode<int>* temp = root;
    while(temp->data!=key){
        if(temp->data>key){
             suc=temp->data;
            temp=temp->left;
           
            
            
            
        }
        
        if(temp->data<key){
               pred=temp->data;
            temp=temp->right;
         
        }
    }
//     pred and succ
//     first pred
    BinaryTreeNode<int>* lefttree=temp->left;
    
    while(lefttree!=NULL){
        pred=lefttree->data;
        lefttree=lefttree->right;
    }
//     ṣuccess
    
   BinaryTreeNode<int>* righttree=temp->right; 
    while(righttree!=NULL){
        suc=righttree->data;
        righttree=righttree->left;
    }
    pair<int,int> ans=make_pair(pred,suc);
    return ans;
    
    
    
    
    
}