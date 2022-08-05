/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
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
TreeNode<int> *inordertoBST(int s, int e, vector<int> &n)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    TreeNode<int> *root = new TreeNode<int>(n[mid]);
    root->left = inordertoBST(s, mid - 1, n);
    root->right = inordertoBST(mid + 1, e, n);
    return root;
}

TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    vector<int> inorderval;
    //     srore inorder->sorted values
    inorder(root, inorderval);

    return inordertoBST(0, inorderval.size() - 1, inorderval);
}