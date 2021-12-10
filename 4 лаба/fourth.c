#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include "utils.h"

typedef struct net_device {
    char IPv4[16];
    char isOnline[6];
    char *name;
} net_device;

void insertItemByIndex(int length, struct net_device *net_devicies) {
    char *s = NULL;
    int index = 0;
    int temp = 0;
    printf("������� ����� ������ �������� ����������: ���, IPv4, isOnline\n");
    s = get_str();
    net_devicies = realloc(net_devicies, (length + 1) * sizeof *net_devicies);
    if (s) {
        char **res = NULL;
        char *p = strtok(s, " ");
        int n_spaces = 0, i;

        while (p) {
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

        printf("������� ������: "); scanf("%d", &index);
        

        for (i = temp - 1; i >= index; i--)
            net_devicies[i] = net_devicies[i - 1];

        net_devicies[index] = net_devicies[temp];

        for (int i = 0; i < temp; i++) {
            printf("name = %s; ", net_devicies[i].name);
            printf("IPv4 = %s; ", net_devicies[i].IPv4);
            printf("isOnline = %s; ", net_devicies[i].isOnline);
            printf("\n");
        } 
        
        free(res);
        free(s);
    }
}

void insertItemWithoutJokes(int length, struct net_device *net_devicies) {
    char *s = NULL;
    int temp = 0;
    printf("������� ����� ������ �������� ����������: ���, IPv4, isOnline\n");
    s = get_str();
    net_devicies = realloc(net_devicies, (length + 1) * sizeof *net_devicies);
    if (s) {
        char **res = NULL;
        char *p = strtok(s, " ");
        int n_spaces = 0, i;

        while (p) {
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

        for (int i = 0; i < temp; i++) {
            printf("name = %s; ", net_devicies[i].name);
            printf("IPv4 = %s; ", net_devicies[i].IPv4);
            printf("isOnline = %s; ", net_devicies[i].isOnline);
            printf("\n");
        }
        
        free(res);
        free(s);
    }
}

void deleteItemWithLength(int length, struct net_device *net_devicies) {
    int k , n;
    printf("������� ����� ��������, � �������� ������ ������ ��������: ");
    scanf("%d", &k);
    printf("������� ���������� ���������, ������� ������ �������: ");
    scanf("%d", &n);

    for (int i = k; i < length - n; i++){  
        net_devicies[i] = net_devicies[i + n];
        
    }
    for (int i = 0; i < length - n; i++) {
            printf("name = %s; ", net_devicies[i].name);
            printf("IPv4 = %s; ", net_devicies[i].IPv4);
            printf("isOnline = %s; ", net_devicies[i].isOnline);
            printf("\n");
    }    
        
}

void mainMenu();

void sortModule(int length, struct net_device *net_devicies) {
    printf(
        "\n"
        "------------------------------\n"
        "         Sorting Menu\n"
        "------------------------------\n");
    printf("1. ��������� ����������\n");
    printf("2. ������ ���������� ���������\n");
    printf("3. ������������� ����������\n");
    printf("0. ������� � ������� ����\n");
    char choiceSort;
    printf("\n");
    printf("������ ���-������ �� �����. \n");  
    choiceSort = getch(); 
    printf("���� �����: %c", choiceSort);
    printf("\n"); 
    clock_t t; double time_taken;  
    switch (choiceSort) {
    case '1':
        printf("\n");
        printf("��������� ����������\n");
        printf("\n");
        t = clock();
        cocktailSortQsortFormat(net_devicies, length, sizeof(net_devicies), compare);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        for (int i = 0; i < length; i++) {
            printf("name = %s; ", net_devicies[i].name);
            printf("IPv4 = %s; ", net_devicies[i].IPv4);
            printf("isOnline = %s; ", net_devicies[i].isOnline);
            printf("\n");     
        }
        printf("Execution time = %.6f\n",  time_taken);
        break;
    case '2':
        printf("\n");
        printf("������ ���������� ���������\n");
        printf("\n");
        t = clock();
        insertionSortQsortFormat(net_devicies, length, sizeof(net_devicies), compare);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        for (int i = 0; i < length; i++) {
            printf("name = %s; ", net_devicies[i].name);
            printf("IPv4 = %s; ", net_devicies[i].IPv4);
            printf("isOnline = %s; ", net_devicies[i].isOnline);
            printf("\n");     
        }
        printf("Execution time = %.6f\n",  time_taken);
        break;
    case '3':
        printf("\n");
        printf("������������� ����������\n");
        printf("\n");
        t = clock();
        heapSortQsortFormat(net_devicies, length, sizeof(net_devicies), compare);
        t = clock() - t;
        time_taken = ((double)t)/CLOCKS_PER_SEC;
        for (int i = 0; i < length; i++) {
            printf("name = %s; ", net_devicies[i].name);
            printf("IPv4 = %s; ", net_devicies[i].IPv4);
            printf("isOnline = %s; ", net_devicies[i].isOnline);
            printf("\n");     
        }
        printf("Execution time = %.6f\n",  time_taken);
        break;
    case '0':
        printf("\n");
        printf("����������� ���!\n");
        printf("\n");
        mainMenu();
        free(net_devicies);
        break;     
    default:
        printf("�� ��� �����, ������ ��������� ��� �������");
        break;
    }
}

void codeRefactoring(int length, struct net_device *net_devicies) {
    printf(
        "\n"
        "------------------------------\n"
        "         Refactoring Menu\n"
        "------------------------------\n");
    printf("1. ������� ������ �������� � ������ �� �������\n");
    printf("2. ������� ������ �������� � ������������� ������ ��� ��������� ��� ���������������\n");
    printf("3. �������� ��������� ���������� ���������, ������� � ���������� �������\n");
    printf("4. ���������� �������\n");
    printf("0. ������� � ������� ����\n");
    char choiceRefactor; 
    printf("\n");
    printf("������ ���-������ �� �����. \n"); 
    choiceRefactor = getch(); 
    printf("���� �����: %c", choiceRefactor);
    printf("\n");
    switch (choiceRefactor) {
    case '1':
        printf("\n");
        printf("������� ������ �������� � ������ �� �������\n");
        printf("\n");
        insertItemByIndex(length, net_devicies);
        break;
    case '2':
        printf("\n");
        printf("������� ������ �������� � ������������� ������ ��� ��������� ��� ���������������\n");
        printf("\n");
        insertItemWithoutJokes(length, net_devicies);
        break;
    case '3':
        printf("\n");
        printf("�������� ��������� ���������� ���������, ������� � ���������� �������\n");
        printf("\n");
        deleteItemWithLength(length, net_devicies);
        break;
    case '4':
        printf("\n");
        printf("���������� �������\n");
        printf("\n");
        sortModule(length, net_devicies);
        break;
    case '0':
        printf("\n");
        printf("����������� ���!\n");
        printf("\n");
        mainMenu();
        free(net_devicies);
        break;    
    default:
        printf("�� ��� �����, ������ ��������� ��� �������");
        break;
    }
}

void output(int length, struct net_device *net_devicies){
    printf(
        "\n"
        "------------------------------\n"
        "         Outputting Menu\n"
        "------------------------------\n");
    printf("1. ������ � ����������� ����� ������ (��� �����)\n");
    printf("2. ������ � ��������� ����\n");
    printf("0. ������� � ������� ����\n");
    char choiceOutput;
    printf("\n");
    printf("������ ���-������ �� �����. \n"); 
    choiceOutput = getch(); 
    printf("���� �����: %c", choiceOutput);
    printf("\n");
    FILE *f;
    switch (choiceOutput) {
    case '1':
        printf("\n");
        printf("������ � ����������� ����� ������ (��� �����)\n");
        printf("\n");
        for (int i = 0; i < length; i++) {
            printf("name = %s; ", net_devicies[i].name);
            printf("IPv4 = %s; ", net_devicies[i].IPv4);
            printf("isOnline = %s; ", net_devicies[i].isOnline);
            printf("\n");
        }
        printf("\n");
        break;
    case '2':
        f = fopen("output.txt", "w");
        if (f == NULL) {
            printf("Error opening file!\n");
            exit(1);
        }
        printf("\n");
        printf("������ � ��������� ����\n");
        printf("\n");
        for (int i = 0; i < length; i++) {
            fprintf(f,"name = %s; ", net_devicies[i].name);
            fprintf(f,"IPv4 = %s; ", net_devicies[i].IPv4);
            fprintf(f,"isOnline = %s; ", net_devicies[i].isOnline);
            fprintf(f,"\n");
        }
        printf("\n");
        fclose(f);
        break;
    case '0':
        printf("\n");
        printf("����������� ���!\n");
        printf("\n");
        mainMenu();
        free(net_devicies);
        break;    
    default:
        printf("�� ��� �����, ������ ��������� ��� �������\n");
        break;
    }
    codeRefactoring(length, net_devicies);
}

void textInput() {
    struct net_device *net_devicies = NULL;
    char *s = NULL;
    size_t length = 0;
    char line[128]; FILE *file; 
    file = fopen("super_input.txt", "r");
    net_devicies = malloc(sizeof *net_devicies * length);
    while (fgets(line, 128, file) != NULL) {
            net_devicies = realloc(net_devicies, (length + 1) * sizeof *net_devicies);
            char **res = NULL;
            char *p = strtok(line, " ");
            int n_spaces = 0, i;

            while (p) {
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

void consoleInput() {
    struct net_device *net_devicies = NULL;
    char *s = NULL;
    size_t length = 0;
    net_devicies = malloc(sizeof *net_devicies * length);
    do {
        printf("������� ����� ������ �������� ����������[%d]: ���, IPv4, isOnline\n", length);
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

void mainMenu() {
    printLogo();
    printf("1. ���� ������\n");
    printf("2. ����� ������\n");
    printf("3. ��������� ������\n");
    printf("4. ������������\n");
    char choice;
    printf("\n");
    printf("������ ���-������ �� �����. \n");
    choice = getch();
    printf("���� �����: %c", choice);
    printf("\n");
    switch (choice) {
    case '1':
        printf(
            "\n"
            "------------------------------\n"
            "         Inputting Menu\n"
            "------------------------------\n");
        printf("1. ������ �� ������������ ������ ����� (�� �����������)\n");
        printf("2. ������ �� ���������� �����\n");
        printf("3. ��������� ��������� ������\n");
        printf("0. ������� � ������� ����\n");
        char choice_1;
        printf("\n");
        printf("������ ���-������ �� �����. \n");
        choice_1 = getch();
        printf("���� �����: %c", choice_1);
        printf("\n"); 
        switch (choice_1) {
            case '1':
                printf("\n");
                printf("������ �� ������������ ������ ����� (�� �����������)\n");
                printf("\n");
                consoleInput();
                break;
            case '2':
                printf("\n");
                printf("������ �� ���������� �����\n");
                printf("\n");
                textInput();
                break;
            case '3':
                printf("\n");
                printf("�� ��� �����, � �� ����� ��� �������. ��� ����� API((\n");
                printf("���. ��������� ���� � ������� ����)");
                printf("\n");
                mainMenu();
                break;
             case '0':
                printf("\n");
                printf("����������� ���!\n");
                printf("\n");
                mainMenu();
                break;    
        }
            break;
    case '2':
        printf("\n");
        printf("� ������� ��� �������, �� ����� ���� �� ������ ������\n");
        printf("��� ��� ��-������� ������ ���\n");
        printf("��� ��� ���� ����.");
        printf("\n");
        
        mainMenu();
        break;
    case '3':
        printf("\n");
        printf("�������, ���� ���� ������ ������ ����, � �� ����� ������ ������\n");
        printf("��� � ������ ��������� ������, ���� �� ���� ������ �� ����\n");
        printf("��� ��� ���� ����.");
        printf("\n");
        mainMenu();
        break;
    case '4':
        printf("\n");
        printf("������������ - ��� ������� ���������, �� ������ ��� ��� ����� valgring � time ;)\n");
        printf("��� ��� ���� ����.");
        printf("\n");
        mainMenu();
        break;
    default:
        printf("\n");
        printf("�� ��� �����, ������ ��������� ��� �������");
        printf("��� ��� ������, ��� ��� ��� �����.");
        break;
    }
}

int main() {
    //system("chcp 1251");
    mainMenu();
    return 0;
}