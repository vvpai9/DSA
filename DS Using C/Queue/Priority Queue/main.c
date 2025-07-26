#include <stdio.h>

int pval, pqsize;

typedef struct
{
    int PQ[100][100], front[100], rear[100];
}PQueue;

int PQFull (PQueue pq, int pno)
{
    if ((pq.rear[pno] + 1) % pqsize == pq.front [pno])
        return 1;
    return 0;
}

int PQEmpty (PQueue pq)
{
    int i;
    for (i = 0; i < pval; i++)
    {

        if ((pq.rear[i] + 1) % pqsize == pq.front [i])
            return 0;
    }
    return 1;
}

void insertData (PQueue *ppq, int pno, int data)
{
    ppq -> rear [pno] = (ppq -> rear[pno] + 1) % pqsize;
    ppq -> PQ[pno][ppq -> rear[pno]] = data;
}

int deleteData (PQueue *ppq)
{
    int i;
    for (i = 0; i < pval; i++)
    {
        if (ppq -> front[i] != ppq -> rear[i])
        {
            ppq -> front [i] = (ppq -> front[i] + 1) % pqsize;
            return ppq -> PQ[i][ppq -> front[i]];
        }
    }
}

void displayPQueue (PQueue pq)
{
    int i, j;
    printf ("\nPriority No.\tTasks");
    for (i = 0; i < pval; i++)
    {
        printf ("\n%d\t", i + 1);
        if (pq.front[i] != pq.rear[i])
        {
            for (j = (pq.front[i] + 1) % pqsize; j <= pq.rear[i]; j++)
                printf ("%d ", pq.PQ[i][j]);
        }
    }
}

int main()
{
    do
    {
        printf("Enter maximum number of priorities: ");
        scanf ("%d", &pval);
        printf ("Enter maximum number of tasks for each priority: ");
        scanf ("%d", &pqsize);
        if (pqsize >= 100)
            printf ("\nMaximum number of tasks for each priority is 99\n");
        if (pval > 100)
            printf ("\nMaximum number of priorities is 100\n");
    }while (pval > 100 || pqsize >= 100);
    pqsize++;
    PQueue pq;
    int choice, data, pno, i;
    for (i = 0; i < pval; i++)
        pq.front[i] = pq.rear[i] = pqsize - 1;
    do
    {
        printf ("\n\n1 -> Insert an element to the priority queue\n2 -> Delete an element at the front of the priority queue\n3 -> Display entire priority queue\n0-> Exit\n\nEnter your choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1 : printf ("\nEnter priority number: ");
                        scanf ("%d", &pno);
                        if (PQFull(pq, pno))
                            printf ("\nQueue for priority %d is full\n", pno);
                        else
                        {
                            printf ("\nEnter data to be inserted: ");
                            scanf ("%d", &data);
                            insertData (&pq, pno, data);
                        }
                        break;

            case 2 : if (PQEmpty (pq))
                        printf ("\nPriority queue is empty\n");
                    else
                        printf ("\nThe deleted data is: %d\n", deleteData (&pq));
                    break;

            case 3 : if (PQEmpty (pq))
                        printf ("\nPriority Queue is empty\n");
                    else
                        displayPQueue (pq);
                    break;

            case 0 : break;

            default : printf ("\nInvalid choice\n");
        }
    }while (choice != 0);
    return 0;
}
