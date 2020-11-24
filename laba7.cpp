#include "stdafx.h"

#include<locale.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{
	setlocale(LC_ALL, "Rus");
	char *s, *s1 = nullptr;
	int n;
	printf("Введите длинну строки: ");
	scanf("%d", &n);
	s = (char*)malloc(n * sizeof(char));
	
	rewind(stdin);
	printf("Введите строку: ");
	gets_s(s, n+1);
	int l = 0, len = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '*') {
			l++;
		}
	}
	len = (n - l) * 2;
	s1 = (char*)malloc(len * sizeof(char));
	l = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] != '*') {
			s1[l] = s[i];
			s1[l + 1] = s[i];
			l += 2;
		}
	}
	s1[l] = s[n];
	printf("Новая строка: %s\n", s1);
	system("pause");
    return 0;
}

