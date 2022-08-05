TreeNode<int> *sortedLinkedListtoBST(TreeNode<int> *&head, int n)
{
    //     base case

    if (n <= 0 && root == NULL)
    {
        return;
    }
    TreeNode *left = sortedLinkedListtoBST(head, n / 2);
    TreeNode<int> *root = head;
    root->left = left;
    head = head->next;

    root->right = sortedLinkedListtoBST(head, n - n / 2 - 1);
    return root;
}






