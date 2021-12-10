#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include "utils.h"

typedef struct net_device
{
    char IPv4[16];
    char isOnline[6];
    char *name;
} net_device;

void insertItemByIndex(int length, struct net_device *net_devicies)
{
    char *s = NULL;
    int index = 0;
    int temp = 0;
    printf("Введите новую запись сетевого устройства: Имя, IPv4, isOnline\n");
    s = get_str();
    net_devicies = realloc(net_devicies, (length + 1) * sizeof *net_devicies);
    if (s)
    {
        char **res = NULL;
        char *p = strtok(s, " ");
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

        temp = length + 1;
        net_devicies[temp].name = malloc(strlen(res[0]) + 1);
        strcpy(net_devicies[temp].name, res[0]);
        strcpy(net_devicies[temp].IPv4, res[1]);
        strcpy(net_devicies[temp].isOnline, res[2]);

        printf("Введите индекс: ");
        scanf("%d", &index);

        for (i = temp - 1; i >= index; i--)
            net_devicies[i] = net_devicies[i - 1];

        net_devicies[index] = net_devicies[temp];

        for (int i = 0; i < temp; i++)
        {
            printf("name = %s; ", net_devicies[i].name);
            printf("IPv4 = %s; ", net_devicies[i].IPv4);
            printf("isOnline = %s; ", net_devicies[i].isOnline);
            printf("\n");
        }

        free(res);
        free(s);
    }
}

void insertItemWithoutJokes(int length, struct net_device *net_devicies)
{
    char *s = NULL;
    int temp = 0;
    printf("Введите новую запись сетевого устройства: Имя, IPv4, isOnline\n");
    s = get_str();
    net_devicies = realloc(net_devicies, (length + 1) * sizeof *net_devicies);
    if (s)
    {
        char **res = NULL;
        char *p = strtok(s, " ");
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

        temp = length + 1;
        net_devicies[length].name = malloc(strlen(res[0]) + 1);
        strcpy(net_devicies[length].name, res[0]);
        strcpy(net_devicies[length].IPv4, res[1]);
        strcpy(net_devicies[length].isOnline, res[2]);

        for (int i = 0; i < temp; i++)
        {
            printf("name = %s; ", net_devicies[i].name);
            printf("IPv4 = %s; ", net_devicies[i].IPv4);
            printf("isOnline = %s; ", net_devicies[i].isOnline);
            printf("\n");
        }

        free(res);
        free(s);
    }
}

void deleteItemWithLength(int length, struct net_device *net_devicies)
{
    int k, n;
    printf("Введите номер элемента, с которого хотите начать удаление: ");
    scanf("%d", &k);
    printf("Введите количество элементов, которые хотите удалить: ");
    scanf("%d", &n);

    for (int i = k; i < length - n; i++)
    {
        net_devicies[i] = net_devicies[i + n];
    }
    for (int i = 0; i < length - n; i++)
    {
        printf("name = %s; ", net_devicies[i].name);
        printf("IPv4 = %s; ", net_devicies[i].IPv4);
        printf("isOnline = %s; ", net_devicies[i].isOnline);
        printf("\n");
    }
}

void mainMenu();

void sortModule(int length, struct net_device *net_devicies)
{
    printf(
        "\n"
        "------------------------------\n"
        " Sorting Menu\n"
        "------------------------------\n");
    printf("1. Шейкерная сортировка\n");
    printf("2. Парная сортировка вставками\n");
    printf("3. Пирамидальная сортировка\n");
    printf("0. Возврат в главное меню\n");
    char choiceSort;
    printf("\n");
    printf("Выбери что-нибудь из этого. \n");
    choiceSort = getch();
    printf("Твой ответ: %c", choiceSort);
    printf("\n");
    clock_t t;
    double time_taken;
    switch (choiceSort)
    {
    case '1':
        printf("\n");
        printf("Шейкерная сортировка\n");
        printf("\n");
        t = clock();
        cocktailSortQsortFormat(net_devicies, length, sizeof(net_devicies), compare);
        t = clock() - t;
        time_taken = ((double)t) / CLOCKS_PER_SEC;
        for (int i = 0; i < length; i++)
        {
            printf("name = %s; ", net_devicies[i].name);
            printf("IPv4 = %s; ", net_devicies[i].IPv4);
            printf("isOnline = %s; ", net_devicies[i].isOnline);
            printf("\n");
        }
        printf("Execution time = %.6f\n", time_taken);
        break;
    case '2':
        printf("\n");
        printf("Парная сортировка вставками\n");
        printf("\n");
        t = clock();
        insertionSortQsortFormat(net_devicies, length, sizeof(net_devicies), compare);
        t = clock() - t;
        time_taken = ((double)t) / CLOCKS_PER_SEC;
        for (int i = 0; i < length; i++)
        {
            printf("name = %s; ", net_devicies[i].name);
            printf("IPv4 = %s; ", net_devicies[i].IPv4);
            printf("isOnline = %s; ", net_devicies[i].isOnline);
            printf("\n");
        }
        printf("Execution time = %.6f\n", time_taken);
        break;
    case '3':
        printf("\n");
        printf("Пирамидальная сортировка\n");
        printf("\n");
        t = clock();
        heapSortQsortFormat(net_devicies, length, sizeof(net_devicies), compare);
        t = clock() - t;
        time_taken = ((double)t) / CLOCKS_PER_SEC;
        for (int i = 0; i < length; i++)
        {
            printf("name = %s; ", net_devicies[i].name);
            printf("IPv4 = %s; ", net_devicies[i].IPv4);
            printf("isOnline = %s; ", net_devicies[i].isOnline);
            printf("\n");
        }
        printf("Execution time = %.6f\n", time_taken);
        break;
    case '0':
        printf("\n");
        printf("Потрясающий ход!\n");
        printf("\n");
        mainMenu();
        free(net_devicies);
        break;
    default:
        printf("Ты что клоун, напиши нормально как человек");
        break;
    }
}

void codeRefactoring(int length, struct net_device *net_devicies)
{
    printf(
        "\n"
        "------------------------------\n"
        " Refactoring Menu\n"
        "------------------------------\n");
    printf("1. Вставка нового элемента в массив по индексу\n");
    printf("2. Вставка нового элемента в упорядоченный массив без нарушения его упорядоченности\n");
    printf("3. Удаление заданного количества элементов, начиная с некоторого индекса\n");
    printf("4. Сортировка массива\n");
    printf("0. Возврат в главное меню\n");
    char choiceRefactor;
    printf("\n");
    printf("Выбери что-нибудь из этого. \n");
    choiceRefactor = getch();
    printf("Твой ответ: %c", choiceRefactor);
    printf("\n");
    switch (choiceRefactor)
    {
    case '1':
        printf("\n");
        printf("Вставка нового элемента в массив по индексу\n");
        printf("\n");
        insertItemByIndex(length, net_devicies);
        break;
    case '2':
        printf("\n");
        printf("Вставка нового элемента в упорядоченный массив без нарушения его упорядоченности\n");
        printf("\n");
        insertItemWithoutJokes(length, net_devicies);
        break;
    case '3':
        printf("\n");
        printf("Удаление заданного количества элементов, начиная с некоторого индекса\n");
        printf("\n");
        deleteItemWithLength(length, net_devicies);
        break;
    case '4':
        printf("\n");
        printf("Сортировка массива\n");
        printf("\n");
        sortModule(length, net_devicies);
        break;
    case '0':
        printf("\n");
        printf("Потрясающий ход!\n");
        printf("\n");
        mainMenu();
        free(net_devicies);
        break;
    default:
        printf("Ты что клоун, напиши нормально как человек");
        break;
    }
}

void output(int length, struct net_device *net_devicies)
{
    printf(
        "\n"
        "------------------------------\n"
        " Outputting Menu\n"
        "------------------------------\n");
    printf("1. Запись в стандартный поток вывода («на экран»)\n");
    printf("2. Запись в текстовый файл\n");
    printf("0. Возврат в главное меню\n");
    char choiceOutput;
    printf("\n");
    printf("Выбери что-нибудь из этого. \n");
    choiceOutput = getch();
    printf("Твой ответ: %c", choiceOutput);
    printf("\n");
    FILE *f;
    switch (choiceOutput)
    {
    case '1':
        printf("\n");
        printf("Запись в стандартный поток вывода («на экран»)\n");
        printf("\n");
        for (int i = 0; i < length; i++)
        {
            printf("name = %s; ", net_devicies[i].name);
            printf("IPv4 = %s; ", net_devicies[i].IPv4);
            printf("isOnline = %s; ", net_devicies[i].isOnline);
            printf("\n");
        }
        printf("\n");
        break;
    case '2':
        f = fopen("output.txt", "w");
        if (f == NULL)
        {
            printf("Error opening file!\n");
            exit(1);
        }
        printf("\n");
        printf("Запись в текстовый файл\n");
        printf("\n");
        for (int i = 0; i < length; i++)
        {
            fprintf(f, "name = %s; ", net_devicies[i].name);
            fprintf(f, "IPv4 = %s; ", net_devicies[i].IPv4);
            fprintf(f, "isOnline = %s; ", net_devicies[i].isOnline);
            fprintf(f, "\n");
        }
        printf("\n");
        fclose(f);
        break;
    case '0':
        printf("\n");
        printf("Потрясающий ход!\n");
        printf("\n");
        mainMenu();
        free(net_devicies);
        break;
    default:
        printf("Ты что клоун, напиши нормально как человек\n");
        break;
    }
    codeRefactoring(length, net_devicies);
}

void textInput()
{
    struct net_device *net_devicies = NULL;
    char *s = NULL;
    size_t length = 0;
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
    output(length, net_devicies);

    free(net_devicies);
}

void consoleInput()
{
    struct net_device *net_devicies = NULL;
    char *s = NULL;
    size_t length = 0;
    net_devicies = malloc(sizeof *net_devicies * length);
    do
    {
        printf("Введите новую запись сетевого устройства[%d]: Имя, IPv4, isOnline\n", length);
        s = get_str();
        net_devicies = realloc(net_devicies, (length + 1) * sizeof *net_devicies);
        if (s)
        {
            char **res = NULL;
            char *p = strtok(s, " ");
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

    } while (s);

    printf("\n");
    output(length, net_devicies);
    free(net_devicies);
}

void mainMenu()
{
    printLogo();
    printf("1. Ввод данных\n");
    printf("2. Вывод данных\n");
    printf("3. Обработка данных\n");
    printf("4. Таймирование\n");
    char choice;
    printf("\n");
    printf("Выбери что-нибудь из этого. \n");
    choice = getch();
    printf("Твой ответ: %c", choice);
    printf("\n");
    switch (choice)
    {
    case '1':
        printf(
            "\n"
            "------------------------------\n"
            " Inputting Menu\n"
            "------------------------------\n");
        printf("1. Чтение из стандартного потока ввода («с клавиатуры»)\n");
        printf("2. Чтение из текстового файла\n");
        printf("3. Генерация случайных данных\n");
        printf("0. Возврат в главное меню\n");
        char choice_1;
        printf("\n");
        printf("Выбери что-нибудь из этого. \n");
        choice_1 = getch();
        printf("Твой ответ: %c", choice_1);
        printf("\n");
        switch (choice_1)
        {
        case '1':
            printf("\n");
            printf("Чтение из стандартного потока ввода («с клавиатуры»)\n");
            printf("\n");
            consoleInput();
            break;
        case '2':
            printf("\n");
            printf("Чтение из текстового файла\n");
            printf("\n");
            textInput();
            break;
        case '3':
            printf("\n");
            printf("Ты что клоун, я не смогу это сделать. Мне нужно API((\n");
            printf("Бан. Возвращаю тебя в главное меню)");
            printf("\n");
            mainMenu();
            break;
        case '0':
            printf("\n");
            printf("Потрясающий ход!\n");
            printf("\n");
            mainMenu();
            break;
        }
        break;
    case '2':
        printf("\n");
        printf("Я конечно все понимаю, но нужно хотя бы ввести данные\n");
        printf("Так что по-братски сделай это\n");
        printf("Даю еще один шанс.");
        printf("\n");

        mainMenu();
        break;
    case '3':
        printf("\n");
        printf("Дружище, тебе надо начать меньше пить, а то крыша быстро поедет\n");
        printf("Как я сделаю обработку данных, если ты даже ничего не ввел\n");
        printf("Даю еще один шанс.");
        printf("\n");
        mainMenu();
        break;
    case '4':
        printf("\n");
        printf("Таймирование - это конечно прикольно, но сделай это сам через valgring и time ;)\n");
        printf("Даю еще один шанс.");
        printf("\n");
        mainMenu();
        break;
    default:
        printf("\n");
        printf("Ты что клоун, напиши нормально как человек");
        printf("Это без шансов, так что иди домой.");
        break;
    }
}

int main()
{
    //system("chcp 1251");
    mainMenu();
    return 0;
}