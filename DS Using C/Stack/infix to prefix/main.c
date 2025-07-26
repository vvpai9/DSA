#include <stdio.h>
#include <string.h>
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

void convert (char infix [], char prefix [])
{
    stack stk;
    int i, p;
    char input;
    stk.top = -1;
    strrev (infix);
    for (i = 0, p = 0; (input = infix [i]) != '\0'; i++)
    {
        if (isalpha (input) || isdigit (input))
            prefix [p++] = input;
        else if (input == '(')
        {
            while (stacktop (stk) != ')')
                    prefix [p++] = pop (&stk);
            pop (&stk);
        }
        else
        {
            do
            {
                if (empty (stk) || input == ')' || stacktop (stk) == ')' || (associativeLtoR (input) && precedence (input) >= precedence (stacktop (stk))) || (!associativeLtoR (input) && precedence (input) > precedence (stacktop (stk))))
                    break;
                prefix [p++] = pop (&stk);
            }while (1);
            push (&stk, input);
        }
    }
    while (!empty (stk))
        prefix [p++] = pop (&stk);
    prefix [p] = '\0';
    strrev (prefix);
}

double evalPrefix (char infix[], char prefix [])
{
    convert (infix, prefix);
    stack stk;
    int p;
    double op1, op2, res;
    char input;
    stk.top = -1;
    strrev (prefix);
    for (p = 0; (input = prefix[p]) != '\0'; p++)
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
            op1 = pop (&stk);
            op2 = pop (&stk);
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
    double res;
    char infix[100], prefix[100];
    printf ("(Spaces are not allowed. Use '$' or '^' for power function)\nEnter an infix expression: ");
    gets (infix);
    convert (infix, prefix);
    printf ("\nResultant prefix expression : ");
    puts (prefix);
    res = evalPrefix (infix, prefix);
    printf ("\nResult: %lf\n", res);
    return 0;
}
