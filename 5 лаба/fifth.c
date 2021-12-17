#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include "utils.h"

/*
����� ��� ��� ������ ���, ����� ������, ��� ������ ������ � ��� ����� � ������� � ���������� ������ ��������� ���.
��� ���, ���� �� ������� �����-�� ����, � �� ������ ����� �������, �� �� ����������. � ��� ����� ������ �������� ��� ������)
� �� ��� �� �����, ������ ��� �� ���� ���������� ���������. ���� ��� ��� ��� ����� ������ ������ ����� valgrind �� ����������� ������.
�����, � � ����� ����� �� ���� �����������. � ���� � ���� ��� � VS Code)
���-�� ���, ������)
*/

int count;
void mainMenu();

void refactorModule(int **matrix, int length)
{
    printf(
        "\n"
        "------------------------------\n"
        "       Refactoring Menu\n"
        "------------------------------\n");
    printf("1. ������� ������ � ������� �� �������\n");
    printf("2. ������� ������� � ������� �� �������\n");
    printf("3. �������� ������ �� ������� �� �������\n");
    printf("4. �������� ������� �� ������� �� �������\n");
    printf("5. �������������� �������\n");
    printf("0. ������� � ������� ����\n");
    //int (*fin)[length] = (int (*)[length]) matrix;
    char choice_refactor;
    printf("\n");
    printf("������ ���-������ �� �����. \n");
    choice_refactor = getch();
    printf("���� �����: %c", choice_refactor);
    printf("\n");
    switch (choice_refactor)
    {
    case '1':
        printf("\n");
        printf("������� ������ � ������� �� �������\n");
        printf("\n");
        insertRowByIndex(matrix, length);
        break;
    case '2':
        printf("\n");
        printf("������� ������� � ������� �� �������\n");
        printf("\n");
        insertColumnByIndex(matrix, length);
        break;
    case '3':
        printf("\n");
        printf("�������� ������ �� ������� �� �������\n");
        printf("\n");
        deleteRowByIndex(matrix, length);
        break;
    case '4':
        printf("\n");
        printf("�������� ������� �� ������� �� �������\n");
        printf("\n");
        deleteColumnByIndex(matrix, length);
        break;
    case '5':
        printf("\n");
        printf("�������������� �������\n");
        printf("\n");
        count = length;
        calculateMinors(length, matrix);
        break;
    case '0':
        printf("\n");
        printf("����������� ���!\n");
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

void outputMenu(int **matrix, int length)
{
    printf(
        "\n"
        "------------------------------\n"
        "       Outputting Menu\n"
        "------------------------------\n");
    printf("1. ������ �������� ������ � ����������� ����� ������ (��� �����)\n");
    printf("2. ������ �������� ������ � �������� ����\n");
    printf("0. ������� � ������� ����\n");
    char choice_output;
    FILE *fileWB;
    printf("\n");
    printf("������ ���-������ �� �����. \n");
    choice_output = getch();
    printf("���� �����: %c", choice_output);
    printf("\n");
    switch (choice_output)
    {
    case '1':
        printf("\n");
        printf("������ �������� ������ � ����������� ����� ������ (��� �����)\n");
        printf("\n");
        for (size_t i = 0; i < length; i++)
        {
            for (size_t j = 0; j < length; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        refactorModule(matrix, length);
        break;
    case '2':
        printf("\n");
        printf("������ �������� ������ � �������� ����\n");
        printf("\n");

        fileWB = fopen("data_output.bin", "wb");
        for (int i = 0; i < length; ++i)
            fwrite(matrix[i], sizeof(long int), sizeof(matrix), fileWB);

        fclose(fileWB);
        refactorModule(matrix, length);
        break;
    case '0':
        printf("\n");
        printf("����������� ���!\n");
        printf("\n");
        mainMenu();
        break;
    }
}

void generateData()
{
    int r;
    srand(time(NULL));
    r = rand() % 10 + 1;
    int **matrix = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
        matrix[i] = (int *)malloc(r * sizeof(int));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < r; j++)
        {
            matrix[i][j] = rand() % 31 + 10;
        }
    }

    outputMenu(matrix, r);

    free(matrix);
}

void fileInput()
{
    FILE *f = fopen("data_output.bin", "rb");
    fseek(f, 0, SEEK_END);
    int length = ftell(f) / 16;
    fclose(f);

    FILE *fileRB = fopen("data_output.bin", "rb");
    int **data_read = (int **)malloc(length * sizeof(int *));
    for (int i = 0; i < length; i++)
        data_read[i] = (int *)malloc(length * sizeof(int));

    for (int i = 0; i < length; i++)
        fread(data_read[i], sizeof(data_read[i][length]), sizeof(data_read[i][length]), fileRB);

    fclose(fileRB);

    outputMenu(data_read, length);
    free(data_read);
}

void consoleInput()
{
    char *s = NULL;
    int **matrix = NULL;
    size_t length = 0;
    size_t size = 0;
    do
    {
        printf("������� �������� �������, %d ����\n", length + 1);
        s = get_str();
        matrix = realloc(matrix, (length + 1) * sizeof *matrix);

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

            if (length == 0)
                size = n_spaces;

            matrix[length] = (int *)malloc(n_spaces * sizeof(int));

            for (size_t i = 0; i < n_spaces; i++)
            {
                matrix[length][i] = atoi(res[i]);
            }

            free(s);
            free(res);
            length++;
        }
        if (length == size)
        {
            break;
        }

    } while (s);

    outputMenu(matrix, length);

    printf("\n");
}

void mainMenu()
{
    printLogo();
    printf("1. ������ �������� ������ �� ������������ ������ ����� (�� �����������)\n");
    printf("2. ������ �������� ������ �� ��������� �����\n");
    printf("3. ��������� ��������� �������� ������\n");
    char choice;
    printf("\n");
    printf("������ ���-������ �� �����. \n");
    choice = getch();
    printf("���� �����: %c", choice);
    printf("\n");
    switch (choice)
    {
    case '1':
        printf("\n");
        printf("������ �������� ������ �� ������������ ������ ����� (�� �����������)\n");
        printf("\n");
        consoleInput();
        break;
    case '2':
        printf("\n");
        printf("������ �������� ������ �� ��������� �����\n");
        printf("\n");
        fileInput();
        break;
    case '3':
        printf("\n");
        printf("��������� ��������� �������� ������\n");
        printf("\n");
        generateData();
        break;
    default:
        printf("\n");
        printf("�� ��� �����, ������ ��������� ��� �������");
        printf("��� ��� ������, ��� ��� ��� �����.");
        break;
    }
}

int main() {
    system("chcp 1251");
    mainMenu();
    return 0;
}
