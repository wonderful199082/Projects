#include <stdio.h>

int Fibonacci(int n)
{
  if(n == 1) return 1;
  if(n == 2) return 1;

  if(n >= 3)
  {
    return Fibonacci(n-1) + Fibonacci(n-2);
  }
}

int main()
{
  int n;
  printf("please input n.\n");
  scanf("%d", &n);
  printf("Fibonacci(%d) = %d\n", n, Fibonacci(n));

  return 0;
}

