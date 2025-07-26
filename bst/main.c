#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* insert(Node* root, int data)
{
    Node* nw, *cur, *parent;
    nw = (Node*) malloc(sizeof(Node));
    if (nw)
    {
        nw->data = data;
        nw->left=nw->right=NULL;
        if (root == NULL)
            return nw;
        for(cur = root, parent = NULL; cur != NULL;)
        {
            parent = cur;
            if (nw->data < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }
        if (nw->data < parent->data)
            parent->left = nw;
        else
            parent->right = nw;
    }
    else
    {
        printf("\nNode allocation failed\n");
    }
    return root;
}

Node* deleteNode (Node*root, int data)
{
    struct Node *par, *cur, *temp;
    if (root == NULL)
    {
        printf ("\nEmpty Tree\n");
        return root;
    }
    par = NULL;
    cur = root;
    while (cur != NULL && cur -> data != data)
    {
        par = cur;
        if (data < cur -> data)
            cur = cur -> left;
        else
            cur = cur -> right;
    }
    if (cur == NULL)
    {
        printf ("\nNode not found\n");
        return root;
    }
    if (cur -> left != NULL && cur -> right != NULL)
    {
        temp = par = cur;
        cur = cur -> left;
        while (cur -> right != NULL)
        {
            par = cur;
            cur = cur -> right;
        }
        temp -> data = cur -> data;
    }
    if (cur -> left != NULL && cur -> right == NULL)
    {
        if (cur == root)
            root = root -> left;
        else
        {
            if (cur == par -> left)
                par -> left = cur -> left;
            else
                par -> right = cur -> left;
        }
    }
    else if (cur -> left == NULL && cur -> right != NULL)
    {
        if (cur == root)
            root = root -> right;
        else
        {
            if (cur == par -> left)
                par -> left = cur -> right;
            else
                par -> right = cur -> right;
        }
    }
    else
    {
        if (cur == root)
            root = NULL;
        else
        {
            if (par -> left == cur)
                par -> left = NULL;
            else
                par -> right = NULL;
        }
    }
    free(cur);
    return root;
}

void inorder(Node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    int values[10] = {45, 23, 78, 12, 34, 56, 89, 67, 5, 99}, n=10, i;

    Node* root = NULL;
    for (i = 0; i < n; i++)
        root = insert(root, values[i]);

    printf("Inorder after inserting all elements:\n");
    inorder(root);

    root = deleteNode(root, 34);
    printf("\n\nInorder after deleting 34 (leaf node):\n");
    inorder(root);

    root = deleteNode(root, 78);
    printf("\n\nInorder after deleting 78:\n");
    inorder(root);

    root = insert(root, 40);
    printf("\n\nInorder after inserting 40:\n");
    inorder(root);
    printf("\n");
    return 0;
}
