
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#define M 5
#define N 5

int main()
{
    setlocale(LC_ALL, "Russian");
    int mat[M][N];
    int i, j, n, m;
    printf("Введите кол-во столбцов в матрице: ");
    scanf_s("%d", &m);
    while (m > 5 || m <= 0)
    {
        printf("Недопустимый размер, кол-во столбцов не должно превышать 5 \n");
        printf("Введите размер повторно: ");
        scanf_s("%d", &m);
    }
    printf("Введите кол-во строк в матрице: ");
    scanf_s("%d", &n);
    while (n > 5 || n <= 0)
    {
        printf("Недопустимый размер, кол-во строк не должно превышать 5 \n");
        printf("Введите размер повторно: ");
        scanf_s("%d", &n);
    }
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
