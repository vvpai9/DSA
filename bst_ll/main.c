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

void preorder (struct Node *cur)
{
    if (cur == NULL)
        return;
    printf ("%d ", cur -> data);
    preorder (cur -> left);
    preorder (cur -> right);
}

void inorder (struct Node *cur)
{
    if (cur == NULL)
        return;
    inorder (cur -> left);
    printf ("%d ", cur -> data);
    inorder (cur -> right);
}

void postorder (struct Node *cur)
{
    if (cur == NULL)
        return;
    postorder (cur -> left);
    postorder (cur -> right);
    printf ("%d ", cur -> data);
}

int main()
{
    int values[7] = {50, 30, 20, 40, 70, 60, 80}, i;

    Node* root = NULL;
    for (i = 0; i < 7; i++)
        root = insert(root, values[i]);

    printf("Inorder Display:\n");
    inorder(root);
    printf("\n\nPreorder Display:\n");
    preorder(root);
    printf("\n\nPostorder Display:\n");
    postorder(root);
    printf("\n");
    return 0;
}
