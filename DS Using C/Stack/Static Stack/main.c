#include <stdio.h>
#define STACKSIZE 5

struct stack
{
    int top, s[STACKSIZE];
};

int full (struct stack stk)
{
    if (stk.top == STACKSIZE - 1)
        return 1;
    else
        return 0;
}

int empty (struct stack stk)
{
    if (stk.top == 1)
        return 1;
    else
        return 0;
}

void display (struct stack stk)
{
    if (empty (stk))
        printf ("\nStack Underflow\n");
    else
    {
        for (; stk.top != 1; stk.top = stk. top - 1)
            printf ("\n%d", stk.s[stk.top]);
    }
}

void push (struct stack *ps, int data)
{
    ps -> top = ps -> top + 1;
    ps -> s[ps -> top] = data;
}

int pop (struct stack *ps)
{
    int data;
    data = ps -> s [ps -> top];
    ps -> top = ps -> top - 1;
    return data;
}

int peek (struct stack stk)
{
    return (stk.s[stk.top]);
}

int main()
{
    struct stack stk;
    int ch, data;
    stk.top = -1;
    do
    {
        printf ("\n1 -> Push an element to the stack\n2 -> Pop the topmost element from the stack\n3 -> Peek (View the topmost element of the stack)\n4 -> Display entire stack\n0 -> Exit\n\nEnter your choice: ");
        scanf ("%d", &ch);
        switch (ch)
        {
            case 1 : if (full (stk))
                        printf ("\nStack Overflow\n");
                    else
                    {
                        printf ("\nEnter the element to push: ");
                        scanf ("%d", &data);
                        push (&stk, data);
                    }
                    break;

            case 2 : if (empty (stk))
                        printf ("\nStack Underflow\n");
                    else
                    {
                        data = pop (&stk);
                        printf ("\nThe popped element is: %d\n", data);
                    }
                    break;

            case 3 : if (empty (stk))
                        printf ("\nStack Underflow\n");
                    else
                        printf ("\nThe topmost element of the stack is: %d\n", data);
                    break;

            case 4 : display (stk);
                        break;

            case 0 : break;

            default : printf ("\nInvalid  choice\n");
        }
    }while (ch != 0);
    return 0;
}
