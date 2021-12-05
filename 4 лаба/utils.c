#include "utils.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct net_device {
    char IPv4[16];
    char isOnline[6];
    char *name;
} net_device;

void printLogo()
{
    printf(
        "\n"
        "##   ## ##### ###   ##### ####   ###  #       # \n"
        "# # # # #     #  #  #     #   # #   #  #     #  \n"
        "#  #  # ##### #   # ##### ####  #   #   #   #   \n"
        "#     # #     #  #  #     #  #  #   #    # #    \n"
        "#     # ##### ###   ##### #   #  ###      #     \n"
        "                                    __          \n"
        "                                    /_  _  /_   \n"
        "                                   //_'/_ / / . \n"
        "\n");
}

char *get_str() {

    char buf[81] = {0}; // BUFSIZ - константа для длины буфера
    char *res = NULL;
    int len = 0;
    int n = 0;

    do
    {
        n = scanf("%80[^\n]", buf);
        if (n < 0)
        {
            if (!res)
            {
                return NULL;
            }
        }
        else if (n > 0)
        {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        }
        else
        {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0)
    {
        res[len] = '\0';
    }
    else
    {
        res = calloc(1, sizeof(char));
    }

    return res;
}

void swap(struct net_device *A, struct net_device *B) {
    struct net_device temp = *A;
    *A = *B;
    *B = temp;
}

int compare(const void *s1, const void *s2) {
  struct net_device *e1 = (struct net_device *)s1;
  struct net_device *e2 = (struct net_device *)s2;
  int nameCompare = strcmp(e1->name, e2->name);
  if (nameCompare == 0)  
    return e1->IPv4 - e2->IPv4;
  else
    return -nameCompare;  
}

void cocktailSortQsortFormat(void* base, size_t n, size_t size, int (*comparator)(const void*,const void*)) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    struct net_device *arr = (struct net_device *)base;
    while (swapped) {
        swapped = false;
        for (int i = start; i < end; ++i)
        {
            if (comparator(&arr[i], &arr[i + 1]) > 0) {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;
        for (int i = end - 1; i >= start; --i)
        {
            if (comparator(&arr[i], &arr[i + 1]) > 0) {
                swap(&arr[i], &arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

void insertionSortQsortFormat(void* base, size_t n, size_t size, int (*comparator)(const void*,const void*)) {
    struct net_device *arr = (struct net_device *)base;
    struct net_device key;
    int i, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && comparator(&arr[j], &key) > 0)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void heapifyQsortFormat(void* base, size_t n, int i, int (*comparator)(const void*,const void*)) {
    struct net_device *arr = (struct net_device *)base;
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    
    if(l < n){
        if(comparator(&arr[l], &arr[largest]) > 0)
            largest = l;
    }
    if(r < n){
        if(comparator(&arr[r], &arr[largest]) > 0)
            largest = r;
    }
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        heapifyQsortFormat(arr, n, largest, compare);
    }
}

void heapSortQsortFormat(void* base, size_t n, size_t size, int (*comparator)(const void*,const void*)) {
  struct net_device *arr = (struct net_device *)base;
  for(int i = n / 2 - 1; i >= 0; i--){
    heapifyQsortFormat(arr, n, i, compare);
  }
  for(int i = n - 1; i > 0; i--){
    swap(&arr[0], &arr[i]);
    heapifyQsortFormat(arr, i, 0, compare);
  }
  
}
