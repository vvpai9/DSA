#include <stdio.h>
#include <ctype.h>
#include <math.h>

typedef struct
{
    int top;
    char s[100];
}stack;

int empty (stack stk)
{
    if (stk.top == -1)
        return 1;
    else
        return 0;
}

void push (stack *ps, char data)
{
    ps -> top = ps -> top + 1;
    ps -> s[ps -> top] = data;
}

char pop (stack *ps)
{
    char data;
    data = ps -> s [ps -> top];
    ps -> top = ps -> top - 1;
    return data;
}

int associativeLtoR (char op)
{
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
        return 1;
    else if (op == '$' || op == '^')
        return 0;
}

int precedence (char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '$' || op == '^')
        return 3;
}

char stacktop (stack stk)
{
    return stk.s[stk.top];
}

void convert (char infix [], char postfix [])
{
    stack stk;
    int i, p;
    char input;
    stk.top = -1;
    for (i = 0, p = 0; (input = infix [i]) != '\0'; i++)
    {
        if (isalpha (input) || isdigit (input))
            postfix [p++] = input;
        else if (input == ')')
        {
            while (stacktop (stk) != '(')
                    postfix [p++] = pop (&stk);
            pop (&stk);
        }
        else
        {
            do
            {
                if (empty (stk) || input == '(' || stacktop (stk) == '(' || (associativeLtoR (input) && precedence (input) > precedence (stacktop (stk))) || (!associativeLtoR (input) && precedence (input) >= precedence (stacktop (stk))))
                        break;
                postfix [p++] = pop (&stk);
            }while (1);
            push (&stk, input);
        }
    }
    while (!empty (stk))
        postfix [p++] = pop (&stk);
    postfix [p] = '\0';
}

double evalPostfix (char infix[], char postfix [])
{
    convert (infix, postfix);
    stack stk;
    int p;
    double op1, op2, res;
    char input;
    stk.top = -1;
    for (p = 0; (input = postfix[p]) != '\0'; p++)
    {
        if (isalpha (input))
        {
            printf ("\nEnter the value of %c: ", input);
            scanf ("%lf", &res);
            push (&stk,res);
        }
        else if (isdigit (input))
        {
            res = input - '0';
            push (&stk, res);
        }
        else
        {
            op2 = pop (&stk);
            op1 = pop (&stk);
            switch (input)
            {
                case '+' : res = op1 + op2;
                            break;

                case '-' : res = op1 - op2;
                            break;

                case '*' : res = op1 * op2;
                            break;

                case '/' : res = op1 / op2;
                            break;

                case '%' : res = (int) op1 % (int) op2;
                            break;

                case '$' :

                case '^' : res = pow (op1, op2);
                            break;
            }
            push (&stk, res);
        }
    }
    res = pop (&stk);
    return res;
}

int main()
{
    char infix[100], postfix[100];
    //double res;
    printf ("(Spaces are not allowed. Use '$' or '^' for power function. Modulus operator can be used only for integral values)\nEnter an infix expression: ");
    gets (infix);
    convert (infix, postfix);
    printf ("\nResultant postfix expression : ");
    puts (postfix);
    //res = evalPostfix (infix, postfix);
    //printf ("\nResult: %lf\n", res);
    return 0;
}
