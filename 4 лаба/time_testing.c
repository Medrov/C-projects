#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
typedef struct net_device
{
    char IPv4[16];
    char isOnline[6];
    char *name;
} net_device;

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

void textInput()
{
    struct net_device *net_devicies = NULL;
    char *s = NULL;
    size_t length = 0;
    printf("I can work");
    char line[128];
    FILE *file;
    file = fopen("super_input.txt", "r");
    net_devicies = malloc(sizeof *net_devicies * length);
    while (fgets(line, 128, file) != NULL)
    {
        net_devicies = realloc(net_devicies, (length + 1) * sizeof *net_devicies);
        char **res = NULL;
        char *p = strtok(line, " ");
        int n_spaces = 0, i;

        while (p)
        {
            res = realloc(res, sizeof(char *) * ++n_spaces);
            if (res == NULL)
                exit(-1);
            res[n_spaces - 1] = p;
            p = strtok(NULL, " ");
        }

        res = realloc(res, sizeof(char *) * (n_spaces + 1));
        res[n_spaces] = 0;

        net_devicies[length].name = malloc(strlen(res[0]) + 1);
        strcpy(net_devicies[length].name, res[0]);
        strcpy(net_devicies[length].IPv4, res[1]);
        strcpy(net_devicies[length].isOnline, res[2]);
        free(s);
        free(res);
        length++;
    }

    printf("\n");

   

    clock_t t; double time_taken;
    t = clock();
    //cocktailSortQsortFormat(net_devicies, length, sizeof(net_devicies), compare);
    //insertionSortQsortFormat(net_devicies, length, sizeof(net_devicies), compare);
    //heapSortQsortFormat(net_devicies, length, sizeof(net_devicies), compare);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;
    printf("Execution time = %.6f\n", time_taken);
    
    free(net_devicies);
}

int main()
{
   
    textInput();
    return 0;
}