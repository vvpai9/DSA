#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node * getNode ()
{
    return malloc (sizeof (struct Node));
}

void readdata (struct Node *p)
{
    printf ("\nEnter data: ");
    scanf ("%d", &p -> data);
}

int QFull ()
{
    if (getNode () == NULL)
        return 1;
    return 0;
}

int QEmpty (struct Node *front)
{
    if (front == NULL)
        return 1;
    return 0;
}

void insertRearQ (struct Node **front)
{
    struct Node *nw;
    nw = getNode ();
    readdata (nw);
    if (QEmpty (*front))
        nw -> next = nw;
    else
    {
        nw -> next = (*front) -> next;
        (*front) -> next = nw;
    }
    *front = nw;
}

int deleteFrontQ (struct Node **front)
{
    int data;
    struct Node *cur;
    cur = (*front) -> next;
    data = cur -> data;
    if ((*front) == cur)
        *front = NULL;
    else
        (*front) -> next = cur -> next;
    free (cur);
    return data;
}

void displayQueue (struct Node *front)
{
    struct Node *cur;
    cur = front -> next;
    printf ("\nEntered Queue: ");
    do
    {
        printf ("\n%d", cur -> data);
        cur = cur -> next;
    }while (cur != front -> next);
    printf ("\n");
}

int main()
{
    struct Node *front;
    int choice;
    front = NULL;
    do
    {
        printf ("\n1: Insert an element to the queue\n2: Delete an element at the front of the queue\n3: Display entire  queue\n0: Exit\n\nEnter your choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1 : if (QFull ())
                        printf ("\nRAM is Full\n");
                    else
                        insertRearQ (&front);
                    break;

            case 2 :

            case 3 : if (QEmpty (front))
                        printf ("\nQueue is empty\n");
                    else if (choice == 2)
                        printf ("\nThe deleted data id %d\n", deleteFrontQ (&front));
                    else
                        displayQueue (front);
                    break;

            case 0 : while (!QEmpty (front))
                        deleteFrontQ (&front);
                    break;

            default : printf ("\nInvalid choice\n");
        }
    }while (choice != 0);
    return 0;
}
