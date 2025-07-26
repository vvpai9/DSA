#include <stdio.h>
#define DQSIZE 5

typedef struct
{
    int DQ[DQSIZE], front, rear;
}DQueue;

int DQFull (DQueue dq)
{
    if ((dq.rear + 1) % DQSIZE == dq.front)
        return 1;
    return 0;
}

int DQEmpty (DQueue dq)
{
    if (dq.rear == dq.front)
        return 1;
    return 0;
}

void insertFrontDQ (DQueue *pdq, int data)
{
    pdq -> DQ[pdq -> front] = data;
    pdq -> front =  (pdq -> front + (DQSIZE - 1)) % DQSIZE;
}

void insertRearDQ (DQueue *pdq, int data)
{
    pdq -> rear = (pdq -> rear + 1) % DQSIZE;
    pdq -> DQ [pdq -> rear] = data;
}

int deleteRearDQ (DQueue *pdq)
{
    int data;
    data = pdq -> DQ[pdq -> rear];
    pdq -> rear = (pdq -> rear + (DQSIZE - 1)) % DQSIZE;
    return data;
}

int deleteFrontDQ (DQueue *pdq)
{
    pdq -> front = (pdq -> front + 1) % DQSIZE;
    return pdq -> DQ [pdq -> front];
}

void displayDQueue (DQueue dq)
{
    int i;
    printf ("\nEntered Queue:\n");
    for (i = (dq.front +1) % DQSIZE; i != (dq.rear + 1) % DQSIZE; i = (i + 1) % DQSIZE)
        printf ("%d ", dq.DQ[i]);
    printf ("\n");
}

int main()
{
    DQueue dq;
    int choice, mainch, data;
    dq.front = dq.rear = (DQSIZE - 1);
    do
    {
        printf ("\n1 -> Input restricted double ended queue\n2 -> Output restricted Double Ended Queue\n0 -> Exit\n\nEnter your choice: ");
        scanf ("%d", &mainch);
        if (mainch != 1 && mainch != 2 && mainch != 0)
            printf ("\nInvalid choice\n");
    }while (mainch != 1 && mainch != 2 && mainch != 0);
    do
    {
        if (mainch == 0)
            break;
        printf ("\n1 -> Insert an element at the rear of the queue\n2 -> Delete an element at the front of the queue");
        if (mainch == 1)
            printf ("\n3 -> Delete an element at the rear of the queue");
        else
            printf ("\n3 -> Insert an element at the front of the queue");
        printf ("\n4 -> Display entire queue\n0 -> Exit\n\nEnter your choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1 : if (DQFull (dq))
                        printf ("\nQueue is full\n");
                    else
                    {
                        printf ("\nEnter data to insert: ");
                        scanf ("%d", &data);
                        insertRearDQ (&dq, data);
                    }
                    break;

            case 2 : if (DQEmpty (dq))
                        printf ("\nQueue is empty\n");
                    else
                        printf ("\nThe deleted data is %d\n", deleteFrontDQ (&dq));
                    break;

            case 3 : if (mainch == 1)
                    {
                        if (DQEmpty (dq))
                            printf ("\nQueue is empty\n");
                        else
                            printf ("\nThe deleted data is %d\n", deleteRearDQ (&dq));
                    }
                    else
                    {
                        if (DQFull (dq))
                            printf ("\nQueue is full\n");
                        else
                        {
                            printf ("\nEnter data to insert: ");
                            scanf ("%d", &data);
                            insertFrontDQ (&dq, data);
                        }
                    }
                    break;

            case 4 :if (DQEmpty (dq))
                        printf ("\nQueue is empty\n");
                    else
                        displayDQueue (dq);
                    break;

            case 0 : break;

            default : printf ("\nInvalid choice\n");
        }
    }while (choice != 0);
    return 0;
}


