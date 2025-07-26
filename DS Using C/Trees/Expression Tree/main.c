#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node
{
    struct Node *left, *right;
    char exp;
};

typedef struct
{
    struct Node * s[10];
    int top;
}stack;

void push (stack *ps, struct Node * add)
{
    ps -> top = ps -> top + 1;
    ps -> s[ps -> top] = add;
}

struct Node * pop (stack *ps)
{
    struct Node * add;
    add = ps -> s[ps -> top];
    ps -> top = ps -> top - 1;
    return add;
}

int op (char input)
{
    if (input == '+' || input == '-' || input == '*' || input == '/' || input == '$' || input == '^')
        return 1;
    else
        return 0;
}

struct Node * getNode ()
{
    return malloc (sizeof (struct Node));
}

struct Node * CreateTree (char postfix[])
{
    struct Node * input;
    stack stk;
    int i;
    stk.top = -1;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        input = getNode ();
        input -> left = input -> right = NULL;
        input -> exp = postfix[i];
        if (isalpha (input -> exp) || isdigit (input -> exp))
            push (&stk, input);
        else
        {
            input -> right = pop (&stk);
            input -> left = pop (&stk);
            push (&stk, input);
        }
    }
    printf ("\nCreation successful\n");
    return pop (&stk);
}

void preorder (struct Node *cur)
{
    if (cur == NULL)
        return;
    printf ("%c", cur -> exp);
    preorder (cur -> left);
    preorder (cur -> right);
}

int main()
{
    struct Node *root;
    char postfix[100];
    printf ("\nEnter postfix expression: ");
    gets (postfix);
    root = CreateTree (postfix);
    printf ("\nCreation successful\n");
    preorder (root);
    return 0;
}
