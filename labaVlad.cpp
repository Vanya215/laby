#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int **mat = nullptr;
    int i, j, n, m;
    do {
        system("cls");
        printf("Введите количество столбцов n: ");
        scanf_s("%d", &n);
        printf("Введите количество строк m: ");
        scanf_s("%d", &m);
        if (n < 1 || m < 1) {
            fflush(stdin);
            continue;
        }
        if (!(mat = (int**)malloc(sizeof(int*) * n)))
            printf("\nНедостаточно свободной памяти\nУменьшите размер матрицы");
        for (int i = 0; i < n; i++) {
            if (!(*(mat + i) = (int*)malloc(sizeof(int) * m))) {
                printf("\nНедостаточно свободной памяти\nУменьшите размер матрицы");
                for (int j = 0; j < n; j++)
                    free(*(mat + j));

                free(mat);
                mat = nullptr;
                break;
            }
        }
    } while (!mat);
    printf("Заполните матрицу: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            scanf_s("%d", &mat[i][j]);
    }
    printf("\n Матрица \n");
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%4d", mat[i][j]);
        printf("\n");
    }
    int max = -99999999999, min = 9999999999, tmp, k, l, x, y;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++) {
            if (mat[i][j] < 0) {
                if (mat[i][j] > max) {
                    max = mat[i][j];
                    x = i;
                    y = j;
                }
            }
            else if (mat[i][j] > 0) {
                if (mat[i][j] < min) {
                    min = mat[i][j];
                    k = i;
                    l = j;
                }
            }
        }
    }
    tmp = mat[k][l];
    mat[k][l] = mat[x][y];
    mat[x][y] = tmp;
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%4d", mat[i][j]);
        printf("\n");
    }
}
