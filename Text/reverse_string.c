#include <stdio.h>
int main()
{
  char string[10];
  char *p;

  printf("Please input your string(within 10 letters).\n");
  scanf("%s", string);

  /*string[sizeof(string)+1] = '\0';*/
  for(p = string; *p != '\0'; p++);

  printf("\nthe string after reversing is:\n");

  for(; *p != string[0]; p--)
  {
    printf("%c", *p);
  }
  printf("%c", *p);
  printf("\n");

  return 0;
}
