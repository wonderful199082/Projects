#include <stdio.h>
#include <string.h>

void  Reverse_String(char str[], int n)
{
  char *p, *r, temp;
  int i;
  p = str;

  for(r = str; *r != '\0'; r++);
  r--;

  for(i = 0; i <= n/2; i++ )
  {
    /**p = *p + *r;*/
    /**r = *p - *r;*/
    /**p = *p - *r;*/
    temp = *r;
    *r = *p;
    *p = temp;
    p++;
    r--;
  }
}

int main()
{
  char str[10];
  char *p;
  int n;

  printf("Please input your string(within 10 letters).\n");
  scanf("%s", str);

  n = strlen(str);

  Reverse_String (str, n);

  /*string[sizeof(string)+1] = '\0';*/

  printf("\nthe string after reversing is:\n");

  for(p = str; *p != '\0'; p++)
  {
    printf("%c", *p);
  }
  printf("\n");

  return 0;
}
