#ifndef FOO_H_   /* Include guard */
#define FOO_H_


unsigned int foo_strlen (const char* str);
void foo_memcpy(void *dest, void *src, int n);
char* foo_strtok(char* s, char* delm);

#endif // FOO_H_