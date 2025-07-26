#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int roll_no;
    char name[20];
    struct Node *previous, *next;
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
    printf ("\nEnter student details (Format: Roll No.; Name)\n");
    scanf ("%d%s", &p -> roll_no, p -> name);
}

void displayInfo (struct Node *p)
{
    printf ("\nRoll No.: %d\nName: %s\n", p -> roll_no, p -> name);
}

void displayList (struct Node *first)
{
    struct Node *cur;
    cur = first;
    do
    {
        displayInfo (cur);
        cur = cur -> next;
    }while (cur != first);
}

//Creating a node to the Right
struct Node * CreateRight ()
{
    struct Node *first, *nw, *prev;
    int ch;
    prev = first = nw = NULL;
    do
    {
        prev = nw;
        nw = getNode ();
        readInfo (nw);
        if (first == NULL)
            first = nw;
        else
            prev -> next = nw;
        nw -> previous = nw;
        printf ("Any more nodes to create? (1 -> Y; 0-> N): ");
        scanf ("%d", &ch);
    }while (ch == 1);
    nw -> next = first;
    first -> previous = nw;
    return first;
}

//Creating a Node to the Left
struct Node * CreateLeft()
{
    struct Node *prev, *nw, *last;
    int ch;
    prev = last = nw = NULL;
    do
    {
        prev = nw;
        nw = getNode ();
        readInfo (nw);
        if (last == NULL)
            last = nw;
        else
            nw -> next = prev;
        if (prev != NULL)
            prev -> previous = nw;
        printf ("Any more nodes to create? (1 -> Yes; 0 -> No): ");
        scanf ("%d", &ch);
    }while (ch != 0);
    nw -> previous = last;
    last -> next = nw;
    return nw;
}

//Insertion of Node at Front
struct Node * insertFront (struct Node *first)
{
    struct Node *nw, *last;
    nw = getNode ();
    readInfo (nw);
    if (first == NULL)
        first = nw -> previous = nw -> next = nw;
    else
    {
        nw -> next = first;
        last = first -> previous;
        last -> next = nw;
        nw -> previous = last;
        first -> previous = nw;
    }
    printf ("\nInsertion successful\n");
    return nw;
}

//Insertion of Node at Rear
struct Node * insertRear (struct Node *first)
{
    struct Node *nw, *prev;
    nw = getNode ();
    readInfo (nw);
    if (first == NULL)
        first = nw -> previous = nw -> next = nw;
    else
    {
        prev = first -> previous;
        nw -> previous = prev;
        nw -> next = first;
        first -> previous = nw;
    }
    printf ("\nInsertion successful\n");
    return first;
}

struct Node * insertBeforeRNo (struct Node * first, int rno)
{
    struct Node *prev, *cur, *nw;
    int found = 0;
    if (first == NULL)
        printf ("\nList is empty\nInsertion failed\n");
    else
    {
        cur = first;
        do
        {
            if (cur -> roll_no == rno)
            {
                found = 1;
                break;
            }
            cur = cur -> next;
        }while (cur != first);
        if (found == 0)
            printf ("\nNode with roll number %d not found\nInsertion failed\n", rno);
        else
        {
             nw = getNode ();
             readInfo (nw);
             prev = cur -> previous;
             nw -> next = cur;
             prev -> next = nw;
             nw -> previous = prev;
             cur -> previous = nw;
             if (cur == first)
                    first = nw;
            printf ("\nInsertion successful\n");
        }
    }
    return first;
}

struct Node * insertAfterRNo (struct Node * first, int rno)
{
    struct Node *nxt, *cur, *nw;
    int found = 0;
    if (first == NULL)
        printf ("\nList is empty\nInsertion failed\n");
    else
    {
        cur = first;
        do
        {
            if (cur -> roll_no == rno)
            {
                found = 1;
                break;
            }
            cur = cur -> next;
        }while (cur != first);
        if (found == 0)
            printf ("\nNode with roll number %d not found\nInsertion failed\n", rno);
        else
        {
             nw = getNode ();
             readInfo (nw);
             nxt = cur -> next;
             nw -> next = nxt;
             nxt -> previous = nw;
             cur -> next = nw;
             nw -> previous = cur;
            printf ("\nInsertion successful\n");
        }
    }
    return first;
}

//Deletion of Front Node
struct Node * deleteFront (struct Node *first)
{
    struct Node *cur, *last;
    if (first == NULL)
        printf ("\nList is empty\nDeletion failed\n");
    else
    {
        cur = first;
        last = first -> previous;
        printf ("\nThe deleted node is:\n");
        displayInfo (cur);
        if (first == last)
            first = NULL;
        else
        {
            first = first -> next;
            first -> previous = last;
            last -> next = first;
        }
        freeNode (cur);
        printf ("\nDeletion successful\n");
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
        cur = first -> previous;
        prev = cur -> previous;
        printf ("\nThe deleted node is: ");
        displayInfo (cur);
        if (first == cur)
            first = NULL;
        else
        {
            prev -> next = first;
            first -> previous = prev;
        }
        freeNode (cur);
        printf ("\nDeletion successful\n");
    }
    return first;
}

//Deletion of Node Based on Roll Number
struct Node * deleteRNo (struct Node *first, int rno)
{
    struct Node *cur, *prev, *nxt;
    int found = 0;
    if (first == NULL)
        printf ("\nList is empty\nDeletion failed\n");
    else
    {
        cur = first;
        do
        {
            if (cur -> roll_no == rno)
            {
                found = 1;
                break;
            }
            cur = cur -> next;
        }while (cur != first);
        if (found == 0)
            printf ("\nNode with roll number not found\nDeletion failed\n");
        else
        {
            printf ("\nThe deleted note is:\n");
            displayInfo (cur);
            prev = cur -> previous;
            nxt = cur -> next;
            prev -> next = nxt;
            nxt -> previous = prev;
            if (cur == first)
                first = nxt;
            freeNode (cur);
            printf ("\nDeletion successful\n");
        }
    }
    return first;
}

//Deletion of Node Based on Name
struct Node * deleteName (struct Node *first, char nm[])
{
    struct Node *prev, *cur, *nxt;
    int count = 0;
    if (first == NULL)
        printf ("\nList is empty\nDeletion failed\n");
    else
    {
        cur = first;
        do
        {
            if (strcmp (nm, cur -> name) == 0)
            {
                count ++;
                printf ("\nThe deleted node is:\n");
                displayInfo (cur);
                prev = cur -> previous;
                nxt = cur -> next;
                prev -> next = nxt;
                nxt -> previous = prev;
                if (cur == first)
                    first = nxt;
                freeNode (cur);
            }
            cur = cur -> next;
        }while (cur != first);
        if (count == 0)
            printf ("\nNode with name %s not found\nDeletion failed\n", nm);
        else
            printf ("\n%d nodes deleted successfully\n", count);
    }
    return first;
}

//Deletion of entire list
struct Node * deleteList (struct Node *first)
{
    //struct Node *cur, *prev;
    if (first == NULL)
        printf ("\nList is empty\n");
    else
    {
        do
        {
            first = deleteFront (first);
            /*cur = first -> previous;
            prev = cur -> previous;
            if (first == cur)
                first = NULL;
            else
            {
                prev -> next = first;
                first -> previous = prev;
            }
            freeNode (cur);*/
        }while (first != NULL);
        printf ("\nList deleted successfully\n");
    }
    return first;
}

//Searching By Roll Number
void searchRNo (struct Node *first, int rno)
{
    struct Node *cur;
    int found = 0;
    if (first == NULL)
        printf ("\nList is empty\nSearch failed\n");
    else
    {
        cur = first;
        do
        {
            if (cur -> roll_no == rno)
            {
                found = 1;
                break;
            }
            cur = cur -> next;
        }while (cur != first);
        if (found == 0)
            printf ("\nNode with roll number %d not found\n", rno);
        else
        {
            printf ("\nNode found:");
            displayInfo (cur);
        }
    }
}

//Searching By Name
void searchName (struct Node *first, char nm[])
{
    struct Node *cur;
    int count = 0;
    if (first == NULL)
        printf ("\nList is empty\nSearch failed\n");
    else
    {
        cur = first;
        do
        {
            if (strcmp (nm, cur -> name) == 0)
            {
                count ++;
                displayInfo (cur);
            }
            cur = cur -> next;
        }while (cur != first);
        if (count == 0)
            printf ("\nNode with name %s not found\nSearch failed\n", nm);
        else
            printf ("\n%d nodes with name %s found\n", count, nm);
    }
}

void SortValueR (struct Node *first)
{
    struct Node *i, *j, *k;
    k = getNode();
    if (first == NULL)
        printf ("\nList is empty\nSorting failed\n");
    else if (first -> next == first)
        printf ("\nOnly one node present\n");
    else
    {
        i = first;
        do
        {
            j = first;
            do
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
                j = j -> next;
            }while (j != first);
            i = i -> next;
        }while (i != first);
        printf ("\nList is sorted by roll number\n");
        displayList (first);
    }
}

void SortValueN (struct Node *first)
{
    struct Node *i, *j, *k;
    k = getNode();
    if (first == NULL)
        printf ("\nList is empty\nSorting failed\n");
    else if (first -> next == first)
        printf ("\nOnly one node present\n");
    else
    {
        i = first;
        do
        {
            j = first;
            do
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
                j = j -> next;
            }while (j != first);
            i = i -> next;
        }while (i != first);
        printf ("\nList is sorted by roll number\n");
        displayList (first);
    }
}

int main()
{
    struct Node *first;
    int ch, rno, conf;
    char nm [20];
    do
    {
        printf("\n1 -> Create a node to the right\n2 -> Create a node to the left\n3 -> Insert a node at the front\n4 -> Insert a node at the rear\n5 -> Insert a node before a given roll number\n6-> Insert a node after a given roll number\n7 -> Delete a node at the front\n8 -> Delete a node at the rear\n9 -> Delete a node with a given roll number\n10 -> Delete all nodes with a given name\n11 -> Delete entire list\n12 -> Search a node with a given name\n13 -> Search a node with a given roll number\n14 -> Sort list by roll number\n15 -> Sort list by name\n16 -> Display entire list\n0 -> Exit\n\nEnter your choice: ");
        scanf ("%d", &ch);
        switch (ch)
        {
            case 1 : first = CreateRight();
                        break;

            case 2 : first = CreateLeft();
                        break;

            case 3 : first = insertFront (first);
                        break;

            case 4 : first = insertRear (first);
                        break;

            case 5 : printf ("\nEnter roll number: ");
                        scanf ("%d", &rno);
                        first = insertBeforeRNo (first, rno);
                        break;

            case 6 : printf ("\nEnter roll number: ");
                        scanf ("%d", &rno);
                        first = insertAfterRNo (first, rno);
                        break;

            case 7 : first = deleteFront(first);
                        break;

            case 8 : first = deleteRear (first);
                        break;

            case 9 : printf ("\nEnter roll number to be deleted: ");
                        scanf ("%d", &rno);
                        first = deleteRNo (first, rno);
                        break;

            case 10 :  printf ("\nEnter name to be deleted: ");
                        gets (nm);
                        first = deleteName (first, nm);
                        break;

            case 11 : printf ("\nAre you sure to delete entire list? (1 -> Yes; 0 -> No): ");
                        scanf ("%d", &conf);
                        if (conf == 1)
                        {
                            printf ("\nPass\n");
                            first = deleteList(first);
                            printf ("\nDelete Pass\n");
                        }
                        break;

            case 12 : printf ("\nEnter name to search: ");
                        gets (nm);
                        searchName (first, nm);
                        break;

            case 13 : printf ("\nEnter roll number to search: ");
                        scanf ("%d", &rno);
                        searchRNo (first, rno);
                        break;

            case 14 : SortValueR (first);
                        break;

            case 15 : SortValueN (first);
                        break;

            case 16 : displayList (first);
                        break;

            case 0 : do
                    {
                        printf ("\nExiting will delete entire list\nAre you sure to proceed? (1 -> Yes; 0 -> No): ");
                        scanf ("%d", &conf);
                        printf ("\nPass 1\n");
                        if (conf == 1)
                        {
                            first = deleteList (first);
                            printf ("\nExit\n");
                        }
                        else if (conf == 0)
                            break;
                        else
                            printf ("\nInvalid choice\n");
                    }while (conf != 1);
                    break;

            default : printf ("\nInvalid choice\n");
        }
    }while (ch != 0 && conf != 1);
    return 0;
}
