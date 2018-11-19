#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "boolean.h"
#include "rgbcalculator.h"

double charToDouble(char c)
// Char to double
{
  return (c - '0');
}

boolean IsNumber(char p)
{
    return(p >= '0' && p <= '9');
}

double CheckSymbol(char *p)
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
            f = (f*10) + charToDouble(*P);
            // printf("f = %f\n",f);
            P++;
            // printf("P menunjuk ke : %c\n",*P);
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
                    f = f + charToDouble(*P)*mul;
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

double OperationA()
//Addition and Subtraction Operation
{
    double a;
    a = OperationB();

    if (a == Error)
    {
        return (Error);
    }
    else if (a == MathError)
    {
        return (MathError);
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

            b = OperationB();
            // printf("nilai b adalah : %f\n",b);
            if (b == Error)
            {
                return (Error);
            }
            else if (b == MathError)
            {
                return (MathError);
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

double OperationB()
//Order of Multiplication and Division Operation
{
    double a;

    a = Expn();

    if (a == Error)
    {
        return (Error);
    }
    else if (a == MathError)
    {
        return (MathError);
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
        else if (b == MathError)
        {
            return (MathError);
        }

        if (Op == '*')
        {
            a = b * a;
        }
        else if (Op == '/')
        {
            if(b == 0) // if divided by zero
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

    a = OperationA();
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

    a = CheckSymbol(P);


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

    b = CheckSymbol(P);
    // printf("pada fungsi calcExp, b sekrang bernilai : %f\n",b);
    if (b == Error)
    {
        return (Error);
    }
    else if (*P != '^')
    {
        if (((0<b && b<1) || (-1<b && b<0)) && (a <0))
        {
            return MathError;
        }
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
        else if (c == MathError)
        {
            return (MathError);
        }
        else
        {
            return (pow(a,c));
        }
    }
}
