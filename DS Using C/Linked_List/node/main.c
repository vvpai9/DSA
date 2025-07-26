#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int roll_no;
    char name[20];
    struct Node *next;
};

struct Node * getNode()
{
    return (malloc (sizeof (struct Node)));
}

void freeNode(struct Node *p)
{
    free (p);
}

void readInfo (struct Node *p)
{
    printf ("\nEnter student details (Format: Roll No.    Name)\n");
    scanf ("%d%s", &p -> roll_no, p -> name);
}

void displayInfo (struct Node *p)
{
    printf ("\nRoll No.: %d\nName: %s\n", p -> roll_no, p -> name);
}

//Creating a node to the right
struct Node * CreateRight ()
{
    struct Node *first, *nw, *prev;
    int ch;
    first = nw = NULL;
    do
    {
        prev = nw;
        nw = getNode ();
        readInfo (nw);
        if (first == NULL)
            first = nw;
        else
            prev -> next = nw;
        printf ("Any more nodes to create? (1 -> Y/ 0-> N): ");
        scanf ("%d", &ch);
    }while (ch == 1);
    return first;
}

//Creating a Node to the Left
struct Node * CreateLeft()
{
    struct Node *prev, *nw;
    int ch;
    prev = nw = NULL;
    do
    {
        prev = nw;
        nw = getNode ();
        readInfo (nw);
        nw -> next = prev;
        printf ("Any more nodes to create? (1 -> Yes; 0 -> No): ");
        scanf ("%d", &ch);
    }while (ch != 0);
    return nw;
}

//Insertion of Node at Front
struct Node * insertFront (struct Node *first)
{
    struct Node *nw;
    nw = getNode ();
    readInfo (nw);
    nw -> next = first;
    return nw;
}

//Insertion of Node at Rear
struct Node * insertRear (struct Node *first)
{
    struct Node *nw, *prev;
    nw = getNode ();
    readInfo (nw);
    nw -> next = NULL;
    if (first == NULL)
        return nw;
    else
    {
        for (prev = first; prev -> next != NULL; prev = prev -> next);
        prev -> next = nw;
        return first;
    }
}

struct Node * insertPos (struct Node *first, int pos)
{
    struct Node *cur, *nw;
    nw = getNode ();
    readInfo (nw);
    nw -> next = NULL;
    if (first == NULL || pos == 1)
    {
        nw -> next = first;
        return nw;
    }
     else
     {
         for (cur = first; cur -> next != NULL && pos > 2; cur = cur -> next, pos--);
         nw -> next = cur -> next;
         cur -> next = nw;
         return first;
     }
}

//Deletion of Front Node
struct Node * deleteFront (struct Node *first)
{
    struct Node *cur;
    if (first == NULL)
        printf ("\nList is empty\nDeletion failed\n");
    else
    {
        cur = first;
        first = first -> next;
        printf ("\nThe deleted node is:\n");
        displayInfo (cur);
        freeNode (cur);
    }
    return first;
}

//Deletion of Rear Node
struct Node * deleteRear (struct Node *first)
{
    struct Node *cur, *prev;
    if (first == NULL)
        printf ("\nList is empty\nDeletion failed\n");
    else
    {
        for (cur = first, prev = NULL; cur -> next != NULL; prev = cur, cur = cur -> next);
        if (first == cur)
            first = NULL;
        else
            prev -> next = NULL;
        printf ("\nThe deleted node is:\n");
        displayInfo (cur);
        freeNode (cur);
    }
    return first;
}

//Deletion of Node Based on Unique Data Member
struct Node * deleteUniqueMember (struct Node *first, int rno)
{
    struct Node *cur, *prev;
    for (cur = first, prev = NULL; cur != NULL && cur -> roll_no != rno; prev = cur, cur = cur -> next);
    if (cur == NULL)
        printf ("\nNode with roll number %d not found\nDeletion failed\n", rno);
    else
    {
        printf ("\nThe deleted note is:\n");
        displayInfo (cur);
        if (cur == first)
            first = first -> next;
        else
            prev -> next = cur -> next;
        freeNode (cur);
    }
    return first;

}

//Deletion of Node Based on Non-Unique Data Member
struct Node * deleteNonUniqueMember (struct Node *first, char nm[])
{
    struct Node *prev, *cur;
    int count = 0;
    if (first == NULL)
        printf ("\nList is empty\nDeletion failed\n");
    else
    {
        for (cur = first, prev = NULL; cur != NULL; prev = cur, cur = cur -> next)
        {
            if (strcmp (nm, cur -> name) == 0)
            {
                printf ("\nThe deleted node is:\n");
                displayInfo (cur);
                if (cur == first)
                    first = first -> next;
                else
                    prev -> next = cur -> next;
                freeNode (cur);
                count ++;
            }
        }
        if (count == 0)
            printf ("\nNode with name %s not found\nDeletion failed\n", nm);
        else
            printf ("\n%d nodes deleted successfully\n", count);
    }
    return first;
}

//Deletion of entire list
struct Node * deleteAll (struct Node *first)
{
    struct Node *prev, *cur;
    if (first == NULL)
        printf ("\nList is empty\n");
    else
    {
        for (prev = first, cur = first -> next; prev != NULL; prev = cur, cur = cur -> next)
            freeNode (prev);
        first = NULL;
    }
    return first;
}

//Searching By Unique Data Member
void searchUniqueMember (struct Node *first, int rno)
{
    struct Node *cur;
    if (first == NULL)
        printf ("\nList is empty\nSearch failed\n");
    else
    {
        for (cur = first; cur != NULL && cur -> roll_no != rno; cur = cur -> next);
        if (cur == NULL)
            printf ("\nNode with roll number %d not found\nSearch failed\n", rno);
        else
            displayInfo (cur);
    }
}

//Searching By Non-Unique Data Member
void searchNonUniqueMember (struct Node *first, char nm[])
{
    struct Node *cur;
    int count = 0;
    if (first == NULL)
        printf ("\nList is empty\nSearch failed\n");
    else
    {
        for (cur = first; cur != NULL; cur = cur -> next)
        {
            if (strcmp (nm, cur -> name) == 0)
            {
                displayInfo (cur);
                count ++;
            }
        }
        if (count == 0)
            printf ("\nNode with name %s not found\nSearch failed\n", nm);
        else
            printf ("\n%d nodes with name %s found\n", count, nm);
    }
}

//Display entire list
void displayAll (struct Node *first)
{
   struct Node *cur;
   if (first == NULL)
        printf ("\nList is empty\n");
    else
    {
        for (cur = first; cur != NULL; cur = cur -> next)
            displayInfo (cur);
    }
}

//Sorting By Value
void SortValueR (struct Node *first)
{
    struct Node *i, *j, *k;
    k = getNode();
    if (first == NULL)
        printf ("\nList is empty\nSorting failed\n");
    else if (first -> next == NULL)
        printf ("\nOnly one node present\n");
    else
    {
        for (i = first; i -> next != NULL; i = i -> next)
        {
            for (j = first; j -> next != NULL; j = j -> next)
            {
                if (j -> roll_no > j -> next -> roll_no)
                {
                    k -> roll_no = j -> roll_no;
                    strcpy (k -> name, j -> name);
                    j -> roll_no = j -> next -> roll_no;
                    strcpy (j -> name, j -> next -> name);
                    j -> next -> roll_no = k -> roll_no;
                    strcpy (j -> next -> name, k -> name);
                }
            }
        }
        printf ("\nList is sorted by roll number\n");
        displayAll (first);
    }
}

void SortValueN (struct Node *first)
{
    struct Node *i, *j, *k;
    k = getNode();
    if (first == NULL)
        printf ("\nList is empty\nSorting failed\n");
    else if (first -> next == NULL)
        printf ("\nOnly one node present\n");
    else
    {
        for (i = first; i -> next != NULL; i = i -> next)
        {
            for (j = first; j -> next != NULL; j = j -> next)
            {
                if (strcmp (j -> name, j -> next -> name) > 0)
                {
                    k -> roll_no = j -> roll_no;
                    strcpy (k -> name, j -> name);
                    j -> roll_no = j -> next -> roll_no;
                    strcpy (j -> name, j -> next -> name);
                    j -> next -> roll_no = k -> roll_no;
                    strcpy (j -> next -> name, k -> name);
                }
            }
        }
        printf ("\nList is sorted by name\n");
        displayAll (first);
    }
}

//Reversal of List
struct Node * ReverseList (struct Node *first)
{
    struct Node *prev, *cur, *nxtNode;
    prev = nxtNode = NULL;
    if (first == NULL)
        printf ("\nReversal Failed\n");
    else if (first -> next == NULL)
        printf ("\nOnly one node present\n");
    else
    {
        cur = first;
        while (cur != NULL)
        {
            nxtNode = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = nxtNode;
        }
        first = prev;
        printf ("\nList reversed successfully");
    }
    displayAll (first);
    return first;
}

int main()
{
    struct Node *first;
    int choice, ch, pos, rno;
    char nm [20];
    first = NULL;
    do
    {
        printf ("\n1 -> Create a node\n2 -> Insert a node\n3 -> Delete a node\n4 -> Search for a node\n5 -> Sort list\n6 -> Display entire list\n7 -> Reverse list\n0 -> Exit\n\nEnter your choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1 : printf ("\n1 -> Create a node to the left\n2 -> Create a node to the right\n\nEnter your choice: ");
                     scanf ("%d", &ch);
                     switch (ch)
                    {
                        case 1 : first = CreateLeft();
                                break;

                        case 2 : first = CreateRight();
                                break;

                        default : printf ("\nInvalid input\n");
                    }
                    break;

            case 2 : do
                    {
                        printf ("\n1 -> Insert a node at the front\n2 -> Insert a node at the rear\n3 -> Insert a node at a given position\n0 -> Back\n\nEnter your choice: ");
                        scanf ("%d", &ch);
                        switch (ch)
                        {
                            case 1 : first = insertFront (first);
                                    break;

                            case 2 : first = insertRear (first);
                                    break;

                            case 3 : printf ("\nEnter position at which node has to be inserted: ");
                                    scanf ("%d", &pos);
                                    first = insertPos (first, pos);
                                    break;

                            case 0 : break;

                            default : printf ("\nInvalid input\n");
                        }
                        if (ch == 0)
                            break;
                    }while (ch != 1 || ch != 2 || ch != 3);
                    break;

            case 3 : do
                    {
                        printf ("\n1 -> Delete a node at the front\n2 -> Delete a node at the rear\n3 -> Delete a node by roll number\n4 -> Delete a node by name\n5 -> Delete entire list\n0 -> Back\n\nEnter your choice: ");
                        scanf ("%d", &ch);
                        switch (ch)
                        {
                            case 1 : first = deleteFront (first);
                                    break;

                            case 2 : first = deleteRear (first);
                                    break;

                            case 3 : printf ("\nEnter roll number to be deleted: ");
                                    scanf ("%d", &rno);
                                    first = deleteUniqueMember (first, rno);
                                    break;

                            case 4 : printf ("\nEnter name to be deleted: ");
                                    scanf ("%s", nm);
                                    first = deleteNonUniqueMember (first, nm);
                                    break;

                            case 5 : do
                                    {
                                        printf ("\nThis will delete entire list\nAre you sure to proceed? (0 -> No; 1 -> Yes): ");
                                        scanf ("%d", &pos);
                                        if (pos == 1)
                                            first = deleteAll (first);
                                        else if (pos == 0)
                                            break;
                                        else
                                            printf ("\nInvalid input\n");
                                    }while (pos != 1);

                            case 0 : break;

                            default : printf ("\nInvalid input\n");
                        }
                        if (ch == 0)
                            break;
                    }while (ch != 1 || ch != 2 || ch != 3 || ch != 4);
                    break;

        case 4 : do
                {
                    printf ("\n1 -> Search by roll number\n2 -> Search by name\n0 -> Back\n\nEnter your choice: ");
                    scanf ("%d", &ch);
                    switch (ch)
                    {
                        case 1 : printf ("\nEnter roll number to search: ");
                                scanf ("%d", &rno);
                                searchUniqueMember (first, rno);
                                break;

                        case 2 : printf ("\nEnter name to search: ");
                                scanf ("%s", nm);
                                searchNonUniqueMember (first, nm);
                                break;

                        case 0 : break;

                        default : printf ("\nInvalid input\n");
                    }
                    if (ch == 0)
                        break;
                }while (ch != 1 || ch != 2);
                break;

        case 5 : do
                    {
                        printf ("\n1 -> Sort by roll number\n2 -> Sort by Name\n0 -> Back\n\nEnter your choice: ");
                        scanf ("%d", &ch);
                        switch (ch)
                        {
                            case 1 : SortValueR (first);
                                    break;

                            case 2 : SortValueN (first);
                                    break;

                            case 0 : break;

                            default : printf ("\nInvalid input\n");
                        }
                        if (ch == 0)
                            break;
                    }while (ch == 1 || ch == 2);
                    break;

        case 6 : displayAll (first);
                break;

        case 7 : first = ReverseList (first);
                break;

        case 0 : do
                {
                    printf ("\nExiting will delete all existing nodes\nAre you sure you want to proceed? (0 -> No; 1 -> Yes): ");
                    scanf ("%d", &pos);
                    if (pos == 1)
                    {
                        first = deleteAll (first);
                        printf ("\nExit\n");
                    }
                    else if (pos == 0)
                        break;
                    else
                        printf ("\nInvalid input\n");
                }while (pos != 1);
                break;

        default : printf ("\nInvalid input\n");
        }
    }while (choice != 0 || pos != 1);
    return 0;
}
