#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    struct Node * left, *right;
    int roll_no;
    char name[25];
};

struct Node * getNode ()
{
    return malloc (sizeof (struct Node));
}

void freeNode (struct Node * cur)
{
    free (cur);
}

void readInfo (struct Node * cur)
{
    printf ("\nEnter student details: ");
    scanf ("%d%s", &cur -> roll_no, cur -> name);
}

void displayInfo (struct Node *cur)
{
    printf ("\nRoll No.: %d\nName: %s\n", cur -> roll_no, cur -> name);
}

struct Node * insertNode (struct Node * cur, struct Node * nw)
{
    if (cur == NULL)
    {
        nw -> left = nw -> right = NULL;
        return nw;
    }
    else if (nw -> roll_no < cur -> roll_no)
        cur -> left = insertNode (cur -> left, nw);
    else if (nw -> roll_no > cur -> roll_no)
        cur -> right = insertNode (cur -> right, nw);
    else
    {
        printf ("\nNode already exists\n");
        freeNode (nw);
    }
    return cur;
}

void inorder (struct Node *cur)
{
    if (cur == NULL)
        return;
    inorder (cur -> left);
    displayInfo (cur);
    inorder (cur -> right);
}

void preorder (struct Node *cur)
{
    if (cur == NULL)
        return;
    displayInfo (cur);
    preorder (cur -> left);
    preorder (cur -> right);
}

void postorder (struct Node *cur)
{
    if (cur == NULL)
        return;
    postorder (cur -> left);
    postorder (cur -> right);
    displayInfo (cur);
}

struct Node * deleteNode (struct Node *root, int rno)
{
    struct Node *par, *cur, *temp;
    if (root == NULL)
    {
        printf ("\nEmpty Tree\n");
        return root;
    }
    par = NULL;
    cur = root;
    while (cur != NULL && cur -> roll_no != rno)
    {
        par = cur;
        if (rno < cur -> roll_no)
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
        temp -> roll_no = cur -> roll_no;
        strcpy (temp -> name, cur -> name);
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
    printf ("\nThe deleted node is: ");
    displayInfo (cur);
    freeNode (cur);
    return root;
}

int NodeCount (struct Node *cur)
{
    int count;
    if (cur == NULL)
        return 0;
    count = 1 + NodeCount (cur -> left) + NodeCount (cur -> right);
    return count;
}

int LeafNodeCount (struct Node *cur)
{
    int count;
    if (cur == NULL)
        return 0;
    if (cur -> left == NULL && cur -> right == NULL)
        return 1;
    count = LeafNodeCount (cur -> left) + LeafNodeCount (cur -> right);
    return count;
}

int IntNodeCount (struct Node *cur)
{
    int count;
    if (cur == NULL)
        return 0;
    if (cur -> left == NULL && cur -> right == NULL)
        return 0;
    count = 1 + NodeCount (cur -> left) + NodeCount (cur -> right);
    return count;
}

void swap (struct Node *cur)
{
    struct Node * temp;
    if (cur == NULL)
        return;
    temp = cur -> left;
    cur -> left = cur -> right;
    swap (cur -> left);
    swap (cur -> right);
}

struct Node * copyTree (struct Node * cur)
{
    struct Node *nw;
    if (cur == NULL)
        return NULL;
    nw = getNode();
    nw -> roll_no = cur -> roll_no;
    strcpy (nw -> name, cur -> name);
    nw -> left = copyTree (cur -> left);
    nw -> right = copyTree (cur -> right);
    return nw;
}

struct Node * mirrorTree (struct Node * cur)
{
    struct Node *nw;
    if (cur == NULL)
        return NULL;
    nw = getNode();
    nw -> roll_no = cur -> roll_no;
    strcpy (nw -> name, cur -> name);
    nw -> left = mirrorTree (cur -> right);
    nw -> right = mirrorTree (cur -> left);
    return nw;
}

int main()
{
    struct Node *root = NULL, *nw, *root2;
    int choice, rno;
    do
    {
        printf ("\n1: Insert a node to the tree\n2: Inorder Display\n3: Preorder Display\n4: Postorder Display\n5: Delete a node\n6: Count number of nodes\n7: Count number of leaf nodes\n8: Count number of internal nodes\n9: Swap Tree\n10: Copy Tree\n11: Mirror Tree\n0: Exit\n\nEnter your choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1 : nw = getNode();
                    readInfo (nw);
                    root = insertNode (root, nw);
                    printf ("\nNode inserted successfully\n");
                    break;

            case 2 :

            case 3 :

            case 4 : if (root == NULL)
                        printf ("\nEmpty Tree\n");
                    else if (choice == 2)
                        inorder (root);
                    else if (choice == 3)
                        preorder (root);
                    else
                        postorder (root);
                    break;

            case 5 : printf ("\nEnter roll number of the node to be deleted: ");
                    scanf ("%d", &rno);
                    root = deleteNode (root, rno);
                    break;

            case 6 : rno = NodeCount (root);
                    printf ("\nNumber of nodes: %d\n", rno);
                    break;

            case 7 : rno = LeafNodeCount (root);
                    printf ("\nNumber of leaf nodes: %d\n", rno);
                    break;

            case 8 : rno = IntNodeCount (root);
                    printf ("\nNumber of internal nodes: %d\n", rno);
                    break;

            case 9 : if (root == NULL)
                        printf ("\nEmpty Tree\n");
                    else
                    {
                        swap (root);
                        printf ("\nTree Swapped successfully\n");
                    }
                    break;

            case 10 : if (root == NULL)
                        printf ("\nEmpty Tree\n");
                    else
                    {
                        root2 = copyTree (root);
                        printf ("\nTree copied Successfully\n");
                    }
                    break;   

            case 11 : if (root == NULL)
                        printf ("\nEmpty Tree\n");
                    else
                    {
                        root2 = mirrorTree (root);
                        printf ("\nTree Mirrored Successfully\n");
                    }
                    break;    

            case 0 : break;

            default : printf ("\nInvalid choice\n");
        }
    }while (choice != 0);
    return 0;
}
