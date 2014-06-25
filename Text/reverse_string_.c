#include <stdio.h>
#include <string.h>

void  reverse_string(char str[], int n)
{
  char *p, *r, temp;
  int i;

  p = str;

  for(r = str; *r != '\0'; r++);
  r--;

  for(i = 0; i <= n/2; i++ )
  {
    temp = *r;
    *r = *p;
    *p = temp;
    p++;
    r--;
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
