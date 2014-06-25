#include <stdio.h>
#include <string.h>

void swap(char *p, char *q)
{
  char temp;
  char *r, *s;

  r = p;
  s = q;

  temp = *r;
  *r = *s;
  *s = temp;
}

void  reverse_string(char str[], int n)
{
  char *p = str, *q, temp;
  int i;

  for(q = str; *q != '\0'; q++);
  q--;

  for(i = 0; i < n/2; i++ )
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
