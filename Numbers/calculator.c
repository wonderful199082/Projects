#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define STACK_NUM 1000

double exec(double n1, double n2, char op)
{
  switch(op)
  {
    case '+': return n1 + n2;
    case '-': return n1 - n2;
    case '*': return n1 * n2;
    case '/': return n1 / n2;
  }
}

int op_priority(char op1, char op2)
{
  if(op1 == '*' || op1 == '/') return 1;

  if((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) return 0;

  if((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-')) return 1;

  if(op2 == '#') return 1;
}

float calculate(char str[])
{
  int i;

  char stk_operator[STACK_NUM];
  double stk_number[STACK_NUM];
  int top1 = 0, top2 = 0;

  stk_operator[top2++] = '#';

  for(i = 0; i < strlen(str); i++)
  {
    if(isdigit(str[i]))
    {
      stk_number[top1++] = str[i] - 48;
    }
    else
    {
      if(!op_priority(str[i], stk_operator[top2-1]))
      {
        double n2 = stk_number[--top1];
        double n1 = stk_number[--top1];
        char op = stk_operator[--top2];
        double tmp = exec(n1, n2, op);

        stk_number[top1++] = tmp;
      }

      stk_operator[top2++] = str[i];
    }
  }

  while(stk_operator[top2-1] != '#')
  {
    double n2 = stk_number[--top1];
    double n1 = stk_number[--top1];
    char op = stk_operator[--top2];
    double tmp = exec(n1, n2, op);

    stk_number[top1++] = tmp;
  }

  return stk_number[0];
}


int main(int argc, char* argv[])
{
  double res = calculate(argv[1]);

  printf("%s = %f\n", argv[1], res);

  return 0.0;
}
