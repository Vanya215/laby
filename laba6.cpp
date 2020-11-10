#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main(void)
{
	setlocale(LC_ALL, "Russian");
	int** a = nullptr;
	int n, b[3] = { 0, 0, 0 };

	do {
		system("cls");
		printf("Введите размер матрицыn n: ");
		scanf_s("%d", &n);
		if (n < 1) {
			fflush(stdin);
			continue;
		}
		if (!(a = (int**)malloc(sizeof(int*) * n)))
			printf("\nНедостаточно свободной памяти\nУменьшите размер матрицы");
		for (int i = 0; i < n; i++) {
			if (!(*(a + i) = (int*)malloc(sizeof(int) * n))) {
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
	bool f = true;
	for (int i = 0; i < n; i++) {
		f = true;
		for (int j = 0; j < n && f; j++) {
			if (j == 0)
				if (a[i][j] < 0) {
					if (j < i)
						b[0] += a[i][j];
					else if (j == i)
						b[1] += a[i][j];
					else
						b[2] += a[i][j];
					f = true;
				}
				else
					f = false;
			else if (f)
				if (j < i)
					b[0] += a[i][j];
				else if (j == i)
					b[1] += a[i][j];
				else
					b[2] += a[i][j];

		}
	}

	for (int i = 0; i < 3; i++) {
		printf("b[%d]: %d\n", i, b[i]);
	}
}