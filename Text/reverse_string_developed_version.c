#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *p, char *q)
{
  *p ^= *q;
  *q ^= *p;
  *p ^= *q;
}

void reverse_string(char str[], int n)
{
  char *p = str, *q = str + strlen(str) - 1;

while(p < q)
  {
    swap(p, q);
    p++;
    q--;
  }

}

int main(int argc, char* argv[])
{
  char *p;

  reverse_string(argv[1], strlen(argv[1]));

  printf("\nThe reverse string is:\n");

  for(p = argv[1]; *p != '\0'; p++)
  {
    printf("%c", *p);
  }
  printf("\n");

  return 0;
}
