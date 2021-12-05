#ifndef UTILS_H_   /* Include guard */
#define UTILS_H_
#include <stddef.h>

typedef struct net_device net_device; 
void printLogo();
char *get_str();
void swap(struct net_device *A, struct net_device *B);
int compare(const void *s1, const void *s2);
void cocktailSortQsortFormat(void* base, size_t n, size_t size, int (*comparator)(const void*,const void*));
void insertionSortQsortFormat(void* base, size_t n, size_t size, int (*comparator)(const void*,const void*)) ;
void heapifyQsortFormat(void* base, size_t n, int i, int (*comparator)(const void*,const void*)) ;
void heapSortQsortFormat(void* base, size_t n, size_t size, int (*comparator)(const void*,const void*)) ;

#endif // UTILS_H_