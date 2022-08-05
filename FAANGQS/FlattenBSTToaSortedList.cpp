/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder(TreeNode<int> *root, vector<int> &n)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, n);
    n.push_back(root->data);
    inorder(root->right, n);
}

TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> inorderval;
    //     store inorder-> sorted values
    inorder(root, inorderval);
    int n = inorderval.size();

    TreeNode<int> *newroot = new TreeNode<int>(inorderval[0]);
    TreeNode<int> *curr = newroot;
    //     2nd step
    for (int i = 1; i < n; i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(inorderval[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    //     3rd step

    curr->left = NULL;
    curr->right = NULL;
    return newroot;
}