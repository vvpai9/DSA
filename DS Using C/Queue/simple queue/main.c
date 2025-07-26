#include <stdio.h>
#define MAX_SIZE 100

typedef struct
{
    int pid, psize;
    char pname[MAX_SIZE];
}Process;

typedef struct
{
    Process Q[MAX_SIZE];
    int rear, front;
}Queue;

void readProcess (Process *p)
{
    printf ("\nEnter process details: (Process ID; Process Name; Process Size)\n");
    scanf ("%d%s%d", &p -> pid, p -> pname, &p -> psize);
}

void displayProcess (Process p)
{
    printf ("\nProcess ID: %d\nProcess Name: %s\nProcess Size: %d\n", p.pid, p.pname, p.psize);
}

int QFull (Queue q)
{
    if (q.rear == MAX_SIZE - 1)
        return 1;
    return 0;
}

int QEmpty (Queue q)
{
    if (q.front > q.rear)
        return 1;
    return 0;
}

void insertElement (Queue *q, Process data)
{
    q -> Q[++q -> rear] = data;
}

Process deleteElement (Queue *q)
{
    return q -> Q[q -> front++];
}

void displayQueue (Queue q)
{
    int i;
    for (i = q.front; i <= q.rear; i++)
        displayProcess (q.Q[i]);
}

int main()
{
    Queue q;
    Process data;
    int choice;
    q.rear = -1;
    q.front = 0;
    do
    {
        printf("\n1 -> Insert an element to the queue\n2 -> Delete an element at the front of the queue\n3 -> Display entire queue\n0 -> Exit\n\nEnter your choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1 : if (QFull (q))
                        printf ("\nQueue is full\n");
                    else
                    {
                        readProcess (&data);
                        insertElement (&q, data);
                    }
                    break;

            case 2 : if (QEmpty (q))
                        printf ("\nQueue is empty\n");
                    else
                    {
                        data = deleteElement (&q);
                        printf ("\nThe deleted element is: ");
                        displayProcess (data);
                    }
                    break;

            case 3 : if (QEmpty (q))
                        printf ("\nQueue is empty\n");
                    else
                        displayQueue (q);
                    break;

            case 0 : break;

            default : printf ("\nInvalid choice\n");
        }
    }while (choice != 0);
    return 0;
}
