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
        // printf("calcpar dijalankan\n");
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
    // printf("P sekarang sedang menunjuk ke %c\n", *P );
    if (IsNumber(*P))
    {
        while (IsNumber(*P))
        {
            f = (f*10) + strtod(P,NULL);
            // printf("f = %f\n",f);
            P++;
            // printf("P menunjuk ke : %c\n",*P);
        }
        if (*P == '.')
        {
            P++;
            if (!IsNumber(*P))
            {
                return (Error);
            }
            else
            {
                while (IsNumber(*P))
                {
                    // printf("1. f = %f\n",f);
                    // f = f + strtod(P,NULL)*mul;
                    // mul /= 10;
                    P++;
                    // printf("2. f = %f\n",f);
                }
            }
        }
        // printf("nilai f adalah : %f\n",f);
        return (f);
    }
    else
    {
        return (Error);
    }
}

double OrderOne()
//Addition and Subtraction Operation
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
            OpExist = true;
            char Op;
            Op = *P;
            P++;

            double b;

            b = OrderTwo();
            // printf("nilai b adalah : %f\n",b);
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
            // printf("hasil a pada order a adlaah : %f\n",a);
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
        OpExist = true;
        char Op;

        Op = *P;

        P++;

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
                a = a / b;
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
        // printf("setelah calcpar, p sekarang menunjuk ke : %c\n", *P );
        // printf("fungsi clcpar mengemblikan a =  : %f\n", a );
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

    a = CheckNumber(P);


    if ((*P == '^') && (a != Error))
    {
        OpExist = true;
        P++;
        a = CalcExp(a);
    }
    return (a);
}

double CalcExp (double a)
{
    double b;

    b = CheckNumber(P);
    // printf("pada fungsi calcExp, b sekrang bernilai : %f\n",b);
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
