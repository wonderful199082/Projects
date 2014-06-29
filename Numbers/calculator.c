#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define STACK_NUM 100

int priority(char a, char b)
{
  if(a == '#') return 0;

  if(a == '*' || a == '/')  return 1;
  if((a == '+'|| a == '-') && (b == '+' || b == '-')) return 1;
  if((a =='+' || a == '-') && (b == '*' || b == '/')) return 0;
}

double exec(double n1, double n2, char op)
{
  switch(op)
  {
    case '+' : return n1 + n2;
    case '-' : return n1 - n2;
    case '*' : return n1 * n2;
    case '/' : return n1 / n2;
  }
}
double calculate(char str[])
{
  char stk_op[STACK_NUM];
  double stk_num[STACK_NUM];
  int top_num = 0, top_op = 0;
  size_t i;

  stk_op[top_op++] = '#';

  for( i = 0; i < strlen(str); i++)
  {
    if(isdigit(str[i]))
    {
      stk_num[top_num++] = str[i] - 48;
    }
    else
    {
      if(priority (stk_op[top_op-1], str[i]) )
      {
        double n2 = stk_num[--top_num];
        double n1 = stk_num[--top_num];
        char op = stk_op[--top_op];
        stk_num[top_num++] = exec(n1, n2, op);
      }
      stk_op[top_op++] = str[i];
    }
  }

  while(stk_op[top_op-1] != '#')
  {
    double n2 = stk_num[--top_num];
    double n1 = stk_num[--top_num];
    char op = stk_op[--top_op];
    stk_num[top_num++] = exec(n1, n2, op);
  }
  return stk_num[0];
}

int main(int argc, char*  argv[])
{
  double  res = calculate(argv[1]);
  printf("%f\n", res);

  return 0;
}
