#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }
};
// here we are writting the delete code of a BST

Node *deleteformBST(Node *root, int val)
{
    // base case

    if (root == NULL)
    {
        return root;
    }
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL'
        }

        // 1 child

        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        //  2 child

        if (root->left != NULL && root->right != NULL)
        {
            int mini = minval(root->right)->data;
            root->data = mini;
            root->right = deletefromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {

        root - left = deleteformBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteformBST(root->right, val);
        return root;
    }
}
Node *ismaxVal(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }
    ismaxVal(root->left, val);
    ismaxVal(root->right, val);

    // for samller values printing

    return root;
}

Node *insertintoBST(Node *root, int data)
{
    // base case

    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }
    if (data > root->data)
    {
        // right part insertion
        root->right = insertintoBST(root->right, data);
    }
    else
    {
        // left part insertion
        root->left = insertintoBST(root->left, data);
    }
}

void takeinput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        insertintoBST(root, data);
        cin >> data;
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ,";
    inorder(root->right);
}

void levelordertraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    Node *root = NULL;

    cout << "Enter data to create BST" << endl;
    takeinput(root);

    cout << "printing the BST" << endl;
    levelordertraversal(root);
    cout << "printing Inorder" << endl;
    inorder(root);

    return 0;
}