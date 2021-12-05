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
#include <string.h>


// определяем макс. знач буфера
#define MAXC 80

// функция возвращает указатель на строку и принамает строку на вход
char* getAlphabetOrder(char myStr[100]) {
    //переменная где будем хранить временно символы 
	char temp; int i, j;
	//определяем размер строки
	int length = strlen(myStr);
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
    size_t nptrs = 0;       /* счетчик для количества выделенных указателей */
    char **list = NULL, buf[MAXC];    /* Массив и буффер фиксрованной длины*/ 
    /*Бесконечный цикл, который breakается при EOF*/
    while (1) { 
        int nchar, rtn;     /* Количество введенных символов, возвращаемое значаение scanf */
        printf ("Enter string with num %zu: ", nptrs + 1);  /* Ввод */
        rtn = scanf (" %80[^\n]%n", buf, &nchar);          /* получение значаения */
        if (rtn == EOF) {                                   /* проверка EOF */
            puts ("EOF\n\nOutput:\n");
            break;
        }
        /* делаем перераспределение блоков памяти, чтобы не было утечки */
        if (nchar == 80) { /* check line-too-long */
            fputs ("errro: line exceeds MAXC chars.\n", stderr);
            while (nchar == 80) {  /* loop discarding remainder of line */
                if (scanf ("%80[^\n]%n", buf, &nchar) != 1) {
                    goto getnextline;   /* skip over allocation/storage */
                }
            }
        }
        void *tmp = realloc (list, (nptrs + 1) * sizeof *list);
        /* делаем проверку на память */
        if (!tmp) {
            perror ("realloc-list");
            break;
        }
        list = tmp;         /* присваиваем reallocные блоки пямяти ptrs в наш массив */
        list[nptrs] = malloc (nchar + 1);           /* выделяем память для строки */
        memcpy(list[nptrs], buf, nchar + 1);       /* копирование памяти */
        nptrs += 1; 
        getnextline:;        /* инкременитруем число указателей */
    }
    /* делаем вывод */
    for (size_t j = 0; j < nptrs; j++) {
        //строка в кторой будет храниться слово
        char *token;
        //задаем сплит
	    token = strtok(list[j], " ");
	    printf ("Your strings by num %zu: ", j + 1);
	    //делаем сплит
	    while(token != NULL) {
            printf ("%s ", getAlphabetOrder(token));
            token = strtok (NULL, " ");
        }
        printf ("\n");
        free (list[j]);     /*освобождаем память строки*/
    }
    free (list);  /*освобождаем память указателей*/
}

char *get_str() {
    char buf[81] = {0};  // BUFSIZ - константа для длины буфера
    char *res = NULL;
    int len = 0;
    int n = 0;

    do {
        n = scanf("%80[^\n]", buf);  
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        }
        else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        }
        else {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    }
    else {
        res = calloc(1, sizeof(char));
    }

    return res;
}
int main () {
    char *s = get_str();
    while (s) {
        printf("\"%s\"\n", s);
        free(s);
        s = get_str("Enter string: ");
    }
    return 0;
}