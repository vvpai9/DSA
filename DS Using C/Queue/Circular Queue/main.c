#include <stdio.h>
#include <time.h>
#define MAX_SIZE 100

typedef struct
{
    int rear, front, CQ[MAX_SIZE];
}CQueue;

void Random()
{
    FILE *file = fopen("input.txt", "w");
    if (file)
    {
        srand(time(NULL));
        for (int i = 0; i < 10; i++)
        {
            int num = rand() % 100;
            fprintf(file, "%d\n", num);
        }
        fclose(file);
        printf("10 random numbers written to input.txt\n");
    }
    else
    {
        printf("Error opening file\n");
    }  
}

int CQFull (CQueue cq)
{
    if (((cq.rear + 1) % MAX_SIZE) == cq.front)
        return 1;
    return 0;
}

int readNum(CQueue *cq)
{
    FILE *file = fopen("input.txt", "r");
    int count = 0, data;
    if (file) 
    {
        while (fscanf(file, "%d", &data) != EOF && count < MAX_SIZE)
        {
            count++;
            if (CQFull(*cq))
            {
                printf("Circular Queue is full\n");
                break;
            }
            else
                insertElement(cq, data);
        }
        fclose(file);
    }
    else
        printf("Error opening file\n");
    return count;
}

void writeFile(CQueue cq) 
{
    FILE *file = fopen("output.txt", "w");
    int count = 0, i = cq.front;
    if (file) 
    {
        if (CQEmpty(cq))
            fprintf(file, "Circular Queue is empty\n");
        else
        {
            while (i != cq.rear)
            {
                i = (i + 1) % MAX_SIZE;
                fprintf(file, "%d\n", cq.CQ[i]);
            }
        }    
    }
    else
        printf("Error opening file\n");
}

int CQEmpty (CQueue cq)
{
    if (cq.front == cq.rear)
        return 1;
    return 0;
}

void insertElement (CQueue *pcq, int data)
{
    pcq -> rear = ((pcq -> rear) + 1) % MAX_SIZE;
    pcq -> CQ[pcq -> rear] = data;
}

int deleteElement (CQueue *pcq)
{
    pcq -> front = (pcq -> front + 1) % MAX_SIZE;
    return pcq -> CQ[pcq -> front];
}

void displayCQueue (CQueue cq)
{
    int i = cq.front;
    while (i != cq.rear)
    {
        i = (i + 1) % MAX_SIZE;
        printf ("\n%d", cq.CQ[i]);
    }
    printf("\n");
}

int main()
{
    CQueue cq;
    int choice, data;
    cq.rear = cq.front= -1;
    do
    {
        printf("\n1 -> Insert an element to the circular queue\n2 -> Delete an element at the front of the circular queue\n3 -> Display entire circular queue\n0 -> Exit\n\nEnter your choice: ");
        scanf ("%d", &choice);
        switch (choice)
        {
            case 1 : if (CQFull (cq))
                        printf ("\nCircular Queue is full\n");
                    else
                    {
                        printf ("\nEnter integer element to insert: ");
                        scanf ("%d", &data);
                        insertElement (&cq, data);
                    }
                    break;

            case 2 : if (CQEmpty (cq))
                        printf ("\nCircular Queue is empty\n");
                    else
                    {
                        data = deleteElement (&cq);
                        printf ("\nThe deleted element is: %d\n", data);
                    }
                    break;

            case 3 : if (CQEmpty (cq))
                        printf ("\nCircular Queue is empty\n");
                    else
                        displayCQueue (cq);
                    break;

            case 0 : break;

            default : printf ("\nInvalid choice\n");
        }
    }while (choice != 0);
    return 0;
}
