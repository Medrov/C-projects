#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<readline/readline.h>


void Palindrom( char *s )
{
    int i = 0;
    int h = strlen(s) - 1;

    while ( h > 1 )
    {
       if ( s[i++] != s[h--])
       {
        printf("%s is not a palindrom\n", s);
        return;
       }
    }
    printf("%s is a palindrom\n", s);
}


int main() {
   char *s = NULL;

  do
  {
    s = readline("Enter string: ");
      if (s)
      {
        Palindrom(s);
        free(s);
      }

  } while (s);

    return 0;
}