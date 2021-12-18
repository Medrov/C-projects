#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>

int count;

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

void insertRowByIndex(int **matrix, int length)
{
    char *s = NULL;
    int index = 0;
    int temp = 0;
    printf("Введите строку\n");
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

        temp = length + 1;
        for (size_t i = 0; i < n_spaces; i++)
        {
            matrix[temp][i] = atoi(res[i]);
        }

        printf("Введите индекс: ");
        scanf("%d", &index);

        for (i = temp - 1; i >= index; i--)
            matrix[i] = matrix[i - 1];

        matrix[index] = matrix[temp];

        for (size_t i = 0; i < temp; i++)
        {
            for (size_t j = 0; j < length; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        free(s);
        free(res);
        length++;
    }
}

void insertColumnByIndex(int **matrix, int length)
{
    char *s = NULL;
    int index = 0;
    int temp = 0;
    printf("Введите строку\n");
    s = get_str();
    printf("\n");
    temp = length + 1;
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

        matrix[length] = (int *)malloc(length * sizeof(int));

        for (size_t i = 0; i < n_spaces; i++)
        {
            matrix[length][i] = atoi(res[i]);
        }

        for (int j = 0; j < length; j++)
        {
            for (int k = 0; k < temp; k++)
            {
                if (length == k)
                {
                    matrix[j][k] = matrix[length][j];
                }
            }
        }

        printf("Введите индекс: ");
        scanf("%d", &index);

        for (size_t i = 0; i < length; i++)
        {
            for (size_t j = 0; j < temp; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        // Это короче не пашет, уже с этим три часа. Так что эта функции идет в столицу Шри-Ланки)
        for (int j = 0; j < length; j++)
        {
            for (int k = 0; k < temp; k++)
            {
                if (index == k)
                {
                    int matTemp = matrix[j][k];
                    matrix[j][k] = matrix[length][j];
                    matrix[length][j] = matTemp;
                }
            }
        }

        for (size_t i = 0; i < length; i++)
        {
            for (size_t j = 0; j < temp; j++)
            {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        free(s);
        free(res);
        length++;
    }
}

void deleteRowByIndex(int **matrix, int length)
{
    int index = 0, i, j, k;
    printf("Введите индекс: ");
    scanf("%d", &index);
    for (size_t i = index; i < length - 1; i++)
    {
        for (size_t j = 0; j < length; j++)
        {
            matrix[i][j] = matrix[i + 1][j];
            ;
        }
    }

    for (size_t i = 0; i < length - 1; i++)
    {
        for (size_t j = 0; j < length; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void deleteColumnByIndex(int **matrix, int length)
{
    int index = 0, i, j, k;
    printf("Введите индекс: ");
    scanf("%d", &index);
    for (size_t i = 0; i < length; ++i)
    {
        for (size_t j = index; j < length - 1; ++j)
        {
            matrix[i][j] = matrix[i][j + 1];
            ;
        }
    }

    for (size_t i = 0; i < length; i++)
    {
        for (size_t j = 0; j < length - 1; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void getCofactor(int **matrix, int **temp, int p, int q, int n)
{
    int i = 0, j = 0;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = matrix[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
    if (count == n)
    {
        printf("Минор номер: %d\n", q + 1);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                printf("%d ", temp[i][j]);
            }
            printf("\n");
        }
    }
}

int calculateMinors(int **matrix, int n)
{
    int D = 0;
    if (n == 1)
        return matrix[0][0];

    int **temp = (int **)malloc(count * sizeof(int *));
    for (int i = 0; i < n; i++)
        temp[i] = (int *)malloc(count * sizeof(int));

    int sign = 1;
    for (int f = 0; f < n; f++) {
        getCofactor(matrix, temp, 0, f, n);
        D += sign * matrix[0][f] * calculateMinors(temp, n - 1);
        sign = -sign;
    }

    if (n + 1 == count)
    {
        printf("Значение текущего минора: %d\n", D);
        printf("\n");
    }

    return D;
}
