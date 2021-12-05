#include "foo.h" 
#include <malloc.h>
#include <stddef.h>

unsigned int foo_strlen (const char* str) {
    for (const char* s1 = str; ; s1++) if (!(*s1)) return s1 - str; 
}

void foo_memcpy(void *dest, void *src, int n) {
   char *csrc = (char *)src;
   char *cdest = (char *)dest;
  
   for (int i=0; i<n; i++)
       cdest[i] = csrc[i];
}

char* foo_strtok(char* s, char* delm) {
    static int currIndex = 0;
    if(!s || !delm || s[currIndex] == '\0')
    return NULL;
    char *W = (char *)malloc(sizeof(char)*100);
    int i = currIndex, k = 0, j = 0;

    while (s[i] != '\0'){
        j = 0;
        while (delm[j] != '\0'){
            if (s[i] != delm[j])
                W[k] = s[i];
            else goto It;
            j++;
        }

        i++;
        k++;
    }
It:
    W[i] = 0;
    currIndex = i+1;
    //Iterator = ++ptr;
    return W;
}
