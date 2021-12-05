/******************************************************************************


                ##   ## ##### ###   ##### ####   ###  #       # 
                # # # # #     #  #  #     #   # #   #  #     #
                #  #  # ##### #   # ##### ####  #   #   #   #
                #     # #     #  #  #     #  #  #   #    # #
                #     # ##### ###   ##### #   #  ###      #


*******************************************************************************/

/*
    Третья лаба - 9 вариант.
    Условие: Упорядочить символы внутри каждого слова строки по алфавиту.
*/

#include <stdio.h>
#include <stdlib.h>
#include "foo.h"


// определяем макс. знач буфера
#define MAXC 1000

// функция возвращает указатель на строку и принамает строку на вход
char* getAlphabetOrder(char myStr[100]) {
    //переменная где будем хранить временно символы 
	char temp; int i, j;
	//определяем размер строки
	int length = foo_strlen(myStr);
	// делаем сортировку выбором
	for (i = 0; i < length - 1; i++) {
		for (j = i + 1; j < length; j++) {
			if (myStr[i] > myStr[j]) {
					temp = myStr[i];
					myStr[i] = myStr[j];
					myStr[j] = temp;
			}
		}
	}
    //возвращаем значаение
	return myStr;
}

void tvoriBardaq(){
    int nptrs = 0;       /* счетчик для количества выделенных указателей */
    char **list = NULL, buf[MAXC];    /* Массив и буффер фиксрованной длины*/ 
    /*Бесконечный цикл, который breakается при EOF*/
    while (1) { 
        int nchar, rtn;     /* Количество введенных символов, возвращаемое значаение scanf */
        printf ("Enter string with num %zu: ", nptrs + 1);  /* Ввод */
        rtn = scanf (" %999[^\n]%n", buf, &nchar);          /* получение значаения */
        if (rtn == EOF) {                                   /* проверка EOF */
            puts ("EOF\n\nOutput:\n");
            break;
        }
        /* делаем перераспределение блоков памяти, чтобы не было утечки */
        void *tmp = realloc (list, (nptrs + 1) * sizeof *list);
        /* делаем проверку на память */
        if (!tmp) {
            perror ("realloc-list");
            break;
        }
        list = tmp;         /* присваиваем reallocные блоки пямяти ptrs в наш массив */
        list[nptrs] = malloc (nchar + 1);           /* выделяем память для строки */
        foo_memcpy(list[nptrs], buf, nchar + 1);       /* копирование памяти */
        nptrs += 1;         /* инкременитруем число указателей */
    }
    /* делаем вывод */
    for (int j = 0; j < nptrs; j++) {
        //строка в кторой будет храниться слово
        char *token;
        //задаем сплит
	    token = foo_strtok(list[j], " ");
	    printf ("Your strings by num %zu: ", j + 1);
	    //делаем сплит
	    while(token != NULL) {
            printf ("%s ", getAlphabetOrder(token));
            token = foo_strtok(NULL, " ");
        }
        printf ("\n");
        free (list[j]);     /*освобождаем память строки*/
    }
    free (list);  /*освобождаем память указателей*/
}

int main () {
    tvoriBardaq();
    int i;
    scanf("%d", i);
    return 0;
}