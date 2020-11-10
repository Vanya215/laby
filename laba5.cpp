#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int **a = nullptr;
	int n, s;

	do {
		system("cls");
		printf("Введите размер матрицыn n: ");
		scanf_s("%d", &s);
		if (s < 1) {
			fflush(stdin);
			continue;
		}
		n = 2 * s;
		if (!(a = (int **)malloc(sizeof(int*)*n)))
			printf("\nНедостаточно свободной памяти\nУменьшите размер матрицы");
		for (int i = 0; i < n; i++) {
			if (!(*(a + i) = (int *)malloc(sizeof(int)*n))) {
				printf("\nНедостаточно свободной памяти\nУменьшите размер матрицы");
				for (int j = 0; j < n; j++) 
					free(*(a + j));					
				
				free(a);				
				a = nullptr;				
				break;				
			}
		}
	} while (!a);

	printf("\nВвод массива:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("A[%d][%d]: ", i, j);
			fflush(stdin);
			if (!(scanf_s("%d", *(a + i) + j)))
				j--;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	int p, t, r;
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			p = a[i][j+s];
			t = a[i + s][j + s];
			r = a[i + s][j];
			a[i][j + s] = a[i][j];
			a[i + s][j + s] = p;
			a[i + s][j] = t;
			a[i][j] = r;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
}