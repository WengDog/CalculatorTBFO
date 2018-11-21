#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "rgbcalculator.c"
#include "boolean.h"

char *P;
boolean OpExist;
int main ()
{
  system("clear");
  printf("██████╗  ██████╗ ██████╗      ██████╗ █████╗ ██╗      ██████╗██╗   ██╗██╗      █████╗ ████████╗ ██████╗ ██████╗ \n");
  printf("██╔══██╗██╔════╝ ██╔══██╗    ██╔════╝██╔══██╗██║     ██╔════╝██║   ██║██║     ██╔══██╗╚══██╔══╝██╔═══██╗██╔══██╗\n");
  printf("██████╔╝██║  ███╗██████╔╝    ██║     ███████║██║     ██║     ██║   ██║██║     ███████║   ██║   ██║   ██║██████╔╝\n");
  printf("██╔══██╗██║   ██║██╔══██╗    ██║     ██╔══██║██║     ██║     ██║   ██║██║     ██╔══██║   ██║   ██║   ██║██╔══██\n");
  printf("██║  ██║╚██████╔╝██████╔╝    ╚██████╗██║  ██║███████╗╚██████╗╚██████╔╝███████╗██║  ██║   ██║   ╚██████╔╝██║  ██║\n");
  printf("╚═╝  ╚═╝ ╚═════╝ ╚═════╝      ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝   ╚═╝    ╚═════╝ ╚═╝  ╚═\n");
  printf("================================== [A simple arithmetic expression parser and calculator ] ====================\n");
  printf("\n");

  OpExist = false;
  char InputString[100];
  printf("Welcome to RGB Calculator, please input a string (use 'exit' to close): ");
  scanf("%s",InputString);
  while(strcmp(InputString,"exit")){
    P = InputString;
    double result = OperationA();
    if(OpExist){

      if (result == MathError)
      {
        printf("MATH ERROR\n");
        printf("Please try again : ");
      }
      else if (result == Error)
      {
        printf("SYNTAX ERROR\n");
        printf("Please try again : ");
      }

      else {
        printf("Result : %.2f\n", result);
        printf("Way to go! Write another one : ");
      }
    }

    else {
      printf("Result : %s\n",InputString);
      printf("Way to go! Write another one (This time use an operator!) : ");
    }


    scanf("%s",InputString);
  }
}
