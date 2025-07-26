#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct
{
    int data;
    struct Node* next;
} Node;

Node* hashTableChain[SIZE] = {NULL};
int Linear[SIZE], Quadratic[SIZE];

int hash(int key)
{
    return key % SIZE;
}

void insertChaining(int key)
{
    int index = hash(key);
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = hashTableChain[index];
    hashTableChain[index] = newNode;
}

void displayChaining()
{
    Node *temp;
    int i;
    printf("\nChaining Hash Table:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("[%d]:", i);
        temp = hashTableChain[i];
        while (temp)
        {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

void insertLinearProbing(int key)
{
    int index = hash(key), org = index;
    while (Linear[index] != -1)
    {
        index = (index + 1) % SIZE;
        if (index == org)
        {
            printf("Hash table full! Could not insert %d in Linear Probing.\n", key);
            return;
        }
    }
    Linear[index] = key;
}

void displayLinearProbing()
{
    printf("\nLinear Probing Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("[%d]: %d\n", i, Linear[i]);
}

void insertQuadraticProbing(int key)
{
    int index = hash(key), i = 0, newIndex;
    while (i < SIZE)
    {
        newIndex = (index + i*i) % SIZE;
        if (Quadratic[newIndex] == -1)
        {
            Quadratic[newIndex] = key;
            return;
        }
        i++;
    }
    printf("Hash table full! Could not insert %d in Quadratic Probing.\n", key);
}

void displayQuadraticProbing()
{
    printf("\nQuadratic Probing Hash Table:\n");
    for (int i = 0; i < SIZE; i++)
        printf("[%d]: %d\n", i, Quadratic[i]);
}

int main() {
    int keys[9] = {43, 22, 1, 31, 77, 99, 11, 55, 60};

    for (int i = 0; i < SIZE; i++)
    {
        Linear[i] = -1;
        Quadratic[i] = -1;
    }
    for (int i = 0; i < 9; i++)
    {
        insertChaining(keys[i]);
        insertLinearProbing(keys[i]);
        insertQuadraticProbing(keys[i]);
    }
    displayChaining();
    displayLinearProbing();
    displayQuadraticProbing();
    return 0;
}
