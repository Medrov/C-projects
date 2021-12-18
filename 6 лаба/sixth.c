#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>

struct Node {
    char *data;
    struct Node* next;
};

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

char *get_str()
{

    char buf[81] = {0}; // BUFSIZ - РєРѕРЅСЃС‚Р°РЅС‚Р° РґР»СЏ РґР»РёРЅС‹ Р±СѓС„РµСЂР°
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

bool isVowel(char ch)
{
    ch = toupper(ch);
    return (ch == 'A' || ch == 'E'
            || ch == 'I' || ch == 'O'
            || ch == 'U');
}

void appendChar(char* s, char c) {
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

char* duplicateVowels(char* str)
{
    char* res = (char*) malloc((strlen(str) * 2)*sizeof(char)); 

    for (int i = 0; i < strlen(str); i++) {
        if (isVowel(str[i])) {
            appendChar(res, str[i]);
        }
        appendChar(res, str[i]);
    }
    return res;
}


//В начало списка). Θ(1)
void push(struct Node** head_ref, char *new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    //ложим инфу
    new_node->data  = malloc(strlen(new_data) + 1);
    strcpy(new_node->data, new_data);
    //делаем нод башкой
    new_node->next = (*head_ref);
    //пихаем башку в новый нод
    (*head_ref)    = new_node;
}
 
//Вставка после чего-то. Θ(1) + search time
void insertAfter(struct Node* prev_node, char *new_data) {
    if (prev_node == NULL) {
      printf("the given previous node cannot be NULL");
      return;
    }
 
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
    //ложим инфу
    new_node->data  = malloc(strlen(new_data) + 1);
    strcpy(new_node->data, new_data);
    //делаем своего рода рокировку
    new_node->next = prev_node->next;
    //пихаем старый в новый нод
    prev_node->next = new_node;
}
 
// В конец. Θ(1)
void append(struct Node** head_ref, char *new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;  
    new_node->data  = malloc(strlen(new_data) + 1);
    strcpy(new_node->data, new_data);
    //делаем кго последним
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
    //фигачим до последнего
    while (last->next != NULL)
        last = last->next;
    //меняем последний    
    last->next = new_node;
    return;
}

void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf("%s\n", node->data);
     node = node->next;
  }
}

void freeList(struct Node** head_ref)
{
   
   struct Node* current = *head_ref;
   struct Node* next;
 
   while (current != NULL)
   {
       next = current->next;
       free(current->data);
       free(current);
       current = next;
   }
   
   *head_ref = NULL;
}

int main() {
    system("chcp 1251");
    char *s = NULL;
    char *dupS = NULL;
    struct Node* head = NULL;
    do {
        s = get_str();
        if (s) {
            dupS = duplicateVowels(s);
            printf("\"%s\"\n", duplicateVowels(dupS));
            append(&head, duplicateVowels(s));
            free(dupS);
            free(s);
        }
    } while (s);

    printf("My Linked list is: \n");
    printList(head);
    freeList(&head);

    return 0;
}
