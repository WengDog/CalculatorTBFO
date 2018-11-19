#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "rgbcalculator.h"
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

  // OpExist = false;
  char InputString[100];
  printf("Welcome to RGB Calculator, please input a string (use 'exit' to close): ");
  scanf("%s",InputString);
  while(strcmp(InputString,"exit")){
    P = InputString;
    double result = OrderOne();
    if (result == MathError || *P != '\0')
      {
        printf("Syntax Error\n");
        printf("Please try again : ");
      }

    else {
      printf("Result : %.2f\n", result);
      printf("Way to go! Write another one : ");
    }

    scanf("%s",InputString);
  }
}
