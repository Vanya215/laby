// laba8.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include<locale>

int main()
{
	setlocale(LC_ALL, "Rus");
	char *s;
	int n, l = 0, gr1 = 0, gr2 = 0, gr3 = 0;
	printf("������� ������ ������: ");
	scanf("%d", &n);
	s = (char*)malloc(n * sizeof(char));
	rewind(stdin);
	printf("������� �����: ");
	gets_s(s, n + 1);
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') l++;
		else if(l != 0){
			if (l > 1) 	gr1++;
			l = 0;
		}
		if (i + 1 == n && l > 1) gr1++;
	}
	l = 0;
	for (int i = 0; i < n; i++) {
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) l++;
		else if (l != 0) {
			if (l > 1) 	gr2++;
			l = 0;
		}
		if (i + 1 == n && l > 1) gr2++;
	}
	l = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '+' || s[i] == '*' || s[i] == '-') l++;
		else if (l != 0) {			
			if (l > 1) 	gr3++;
			l = 0;
		}
		if (i + 1 == n && l > 1) gr3++;
		
		
	}
	printf("���������� ����� ����: %d\n", gr1);
	printf("���������� ����� ����: %d\n", gr2);
	printf("���������� ����� ������: %d\n", gr3);
	if (gr2 > gr3) {
		printf("���������� ����� ���� ������ ��� ���������� ����� ������\n");
		system("pause");
		return 0;
	}
	printf("���������� ����� ���� ������ ��� ���������� ����� ������\n");
	system("pause");
	return 0;
}

