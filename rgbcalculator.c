#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "boolean.h"
#include "rgbcalculator.h"

boolean IsNumber(char p)
{
    return(p >= '0' && p <= '9');
}

double CheckNumber(char *p)
{
    float check;
    char *prev;

    if (*P == '-')
    {
        prev = p-1;
        // Mengecek apakah sebelum bilangan negatif ada  tanda kurung atau tidak
        if (*prev != '(')
        {
            return(Error);
        }
        else
        {
            P++;
            check = GetNumber();
            if (check != Error)
            {
                return ((-1) * check);
            }
            else
            {
                return (Error);
            }
        }
    }
    else if (*P == '(')
    {
        P++;
        return (CalcPar());
    }
    else
    {
        return (GetNumber());
    }
}

double GetNumber()
{
    double f = 0;

    if (IsNumber(*P))
    {
        while (IsNumber(*P))
        {
            f = (f*10) + strtod(P,NULL);
            P++;
        }
        if (*P == '.')
        {
            P++;
            double mul = 0.1;
            if (!IsNumber(*P))
            {
                return (Error);
            }
            else
            {
                while (IsNumber(*P))
                {
                    f = f + strtod(P,NULL)*mul;
                    mul /= 10;
                    P++;
                }
            }
        }
        return (f);
    }
    else
    {
        return (Error);
    }
}

double OrderOne()
//Order of Addition and Subtraction Operation
{
    double a;
    a = OrderTwo();

    if (a == Error)
    {
        return (Error);
    }
    else
    {
        while ((*P == '+')||(*P == '-'))
        {
            char Op;
            Op = *P;
            P++;

            double b;

            b = OrderTwo();

            if (b == Error)
            {
                return (Error);
            }

            if (Op == '+')
            {
                a = a + b;
            }
            else if (Op == '-')
            {
                a = a - b;
            }
        }
    return a;
    }
}

double OrderTwo()
//Order of Multiplication and Division Operation
{
    double a;

    a = Expn();

    if (a == Error)
    {
        return (Error);
    }

    while ((*P == '*') || (*P == '/'))
    {
        char Op;

        Op = *P;

        double b;

        b = Expn();

        if (b == Error)
        {
            return (Error);
        }

        if (Op == '*')
        {
            a = b * a;
        }
        else if (Op == '/')
        {
            if(a == 0) // if divided by zero
            {
                return MathError;
            }
            else
            {
                a = b / a;
            }
        }
    }
    return a;
}

double CalcPar()
//Parentheses calculation
{
    double a;

    a = OrderOne();
    if (*P == ')')
    {
        P++;
        return a;
    }
    else
    {
        return (Error);
    }
}


double Expn()
{
    double a;

    a = GetNumber();

    if ((*P == '^') && (a != Error))
    {
        P++;
        a = CalcExp(a);
    }
    return (a);
}

double CalcExp (double a)
{
    double b;

    b = GetNumber();

    if (b == Error)
    {
        return (Error);
    }
    else if (*P != '^')
    {
        return (pow(a,b));
    }
    else //Recurrence
    {
        P++;
        double c;

        c = CalcExp(b);
        if (c == Error)
        {
            return (Error);
        }
        else
        {
            return (pow(a,c));
        }
    }
}
