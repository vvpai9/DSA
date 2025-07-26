#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left, *right;
    int roll_no, lthread, rthread;
    char name[25];
};

struct Node *getNode ()
{
    return malloc (sizeof (struct Node));
}

void readInfo (struct Node *cur)
{
    printf ("\nEnter student details: ");
    scanf ("%d%s", &cur -> roll_no, cur -> name);
}

void displayInfo (struct Node *cur)
{
    printf ("\nRoll No.: %d\nName: ", cur -> roll_no);
    puts (cur -> name);
}

void freeNode (struct Node *cur)
{
    free (cur);
}

struct Node *insertNode (struct Node *head)
{
    struct Node *par, *nw;
    nw = getNode ();
    readInfo (nw);
    nw -> lthread = nw -> rthread = 1;
    if (head == NULL)
    {
        head = getNode ();
        head -> right = head;
        head -> rthread = 1;
        head -> left = nw;
        head -> lthread = 0;
        nw -> left = nw -> right = head;
    }
    else
    {
        par = head -> left;
        while (1)
        {
            if (nw -> roll_no < par -> roll_no)
            {
                if (!(par -> lthread))
                    par = par -> left;
                else
                {
                    nw -> left = par -> left;
                    par -> left = nw;
                    par -> lthread = 0;
                    nw -> right = par;
                    break;
                }
            }
            else if (nw -> roll_no > par -> roll_no)
            {
                if (!(par -> rthread))
                    par = par -> right;
                else
                {
                    nw -> right = par -> right;
                    par -> right = nw;
                    par -> rthread = 0;
                    nw -> left = par;
                    break;
                }
            }
            else
            {
                printf ("\nNode already exists\n");
                freeNode (nw);
                break;
            }
        }
    }
    printf ("\nCreated\n");
    return head;
}

void inorder (struct Node *cur)
{
    struct Node * head = cur;
    cur = cur -> left;
    while (cur != head)
    {
        while (!(cur -> lthread))
            cur = cur -> left;
        displayInfo (cur);
        while (cur != head -> left || cur != head)
        {
            cur = cur -> right;
            displayInfo (cur);
        }
        cur = cur -> right;
    }
}

int main()
{
    struct Node *head = NULL;
    int choice;
    do
    {
        printf ("\n1: Insert a node\n2: Inorder Display\n0: Exit\n\nEnter your choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1 : head = insertNode (head);
                    break;

            case 2 : inorder (head);
                    break;

            case 0 : break;

            default : printf ("\nInvalid choice\n");
        }
    }while (choice != 0);
    return 0;
}
