#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left, *right;
    int h, key;
};

int height (struct Node *cur)
{
    if (cur == NULL)
        return 0;
    return cur -> h;
}

struct Node * getNode (int data)
{
    struct Node *nw;
    nw = malloc (sizeof (struct Node));
    nw -> key = data;
    nw -> left = nw -> right = NULL;
    nw -> h = 1;
    return nw;
}

int max (int a, int b)
{
    return (a > b) ? a : b;
}

struct Node *LeftLeftRotation (struct Node *x)
{
    struct Node *y;
    y = x -> right;
    x -> right = y -> left;
    y -> left = x;
    x ->  h = max(height(x -> left), height (x -> right)) + 1;
    y ->  h = max(height(y -> left), height (y -> right)) + 1;
    return y;
}

struct Node *RightRightRotation (struct Node *x)
{
    struct Node *y;
    y = x -> left;
    x -> left = y -> right;
    y -> right = x;
    x ->  h = max(height(x -> left), height (x -> right)) + 1;
    y ->  h = max(height(y -> left), height (y -> right)) + 1;
    return y;
}

struct Node * insert (struct Node *cur, int data)
{
    int bal = 0;
    if (cur == NULL)
        return getNode (data);
    if (data < cur -> key)
        cur -> left = insert (cur -> left, data);
    else if (data > cur -> key)
        cur -> right = insert (cur -> right, data);
    else
    {
        printf ("\nNode already exists\n");
        return cur;
    }
    cur -> h = max(height(cur -> left), height (cur -> right)) + 1;
    bal = height (cur -> left) - height (cur -> right);
    if (bal > 1 && cur -> left -> key)
        return RightRightRotation (cur);
    else if (bal < -1 && data > cur -> right -> key)
        return LeftLeftRotation(cur);
    else if (bal > 1 && data < cur -> left -> key)
    {
        cur -> left = LeftLeftRotation(cur -> left);
        return RightRightRotation(cur);
    }
    else if (bal < -1 && data < cur -> right -> key)
    {
        cur -> right = RightRightRotation (cur -> right);
        return LeftLeftRotation(cur);
    }
    return cur;
}

void preorder (struct Node *cur)
{
    if (cur == NULL)
        return;
    printf ("%d ", cur -> key);
    preorder (cur -> left);
    preorder (cur -> right);
}

void inorder (struct Node *cur)
{
    if (cur == NULL)
        return;
    inorder (cur -> left);
    printf ("%d ", cur -> key);
    inorder (cur -> right);
}

void postorder (struct Node *cur)
{
    if (cur == NULL)
        return;
    postorder (cur -> left);
    postorder (cur -> right);
    printf ("%d ", cur -> key);
}

int main()
{
    struct Node *root = NULL;
    int choice, key;
    do
    {
        printf ("\n1: Insert\n2: Preorder Display\n3:Inorder Display\n4:Postorder Display\n0: Exit\n\nEnter your choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1: printf ("\nEnter key: ");
                    scanf ("%d", &key);
                    root = insert (root, key);
                    break;

            case 2: printf ("\nPreorder Display: \n");
                    preorder (root);
                    break;

            case 3: printf ("\nInorder Display: \n");
                    inorder (root);
                    break;

            case 4: printf ("\nPostorder Display: \n");
                    postorder (root);
                    break;

            case 0: printf ("\nExit\n");
                    break;

            default : printf ("\nInvalid choice");
        }
    }while (choice);
    return 0;
}
