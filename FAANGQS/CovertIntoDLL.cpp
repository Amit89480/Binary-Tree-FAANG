void convertintoDLL(TreeNode<int> *root, TreeNode<int> *&head)
{
    if (root == NULL)
    {
        return;
    }
    convertintoDLL(root->right, head);
    root->right = head;
    if (head != NULL)
    {
        head->left = root;
    }
    head = root;
    convertintoDLL(root->left, head);
}