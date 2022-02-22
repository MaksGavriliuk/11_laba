#include<stdio.h>
#include<string.h>
#include "sort.h"
extern struct worker  
{
	char familia[30];
	char name[30];
	char dolgnost[30];
	int year;
};

extern worker mas[10]; 
extern worker tmp, t, buffer;
extern int kol_vo;       
extern int er;          


extern void sort() 
{
	if (kol_vo == 0) {
		printf("\n��� �������\n\n");
	}
	else {
		do
		{
			int num;               //���������� ��� ������, �� ������ ���� ����� ������������� ����������
			while (1) {
			printf("\n�������, �� ������ �������� �� ������ �������������� ������:\n");
			printf("1-�� ������� ���������\n");
			printf("2-�� ����� ���������\n");
			printf("3-�� ���������� ���������\n");
			printf("4-�� ���� �������� �� ������\n");
			printf("5-��� �����������\n");

				scanf_s("%d", &num);
				getchar();
				if (num > 0 && num <= 5) {       //��������
					break;
				}
				else printf("\n�������� �����\n");
			}


			switch (num)
			{
			case 1:                            // �� ������� ���������
			{
				for (int i = 0; i < kol_vo; i++) {
					for (int j = i + 1; j < kol_vo; j++) {
						if (strcmp(mas[i].familia, mas[j].familia) > 0)
						{
							t = mas[i];
							mas[i] = mas[j];
							mas[j] = t;
						}
					}
				}
				printf("\n������ ������� ������������� �� ���� '������� ���������'\n");
			}
			break;

			case 2:                            // �� ����� ���������
			{
				for (int i = 0; i < kol_vo; i++) {
					for (int j = i + 1; j < kol_vo; j++) {
						if (strcmp(mas[i].name, mas[j].name) > 0)
						{
							t = mas[i];
							mas[i] = mas[j];
							mas[j] = t;
						}
					}
				}
				printf("\n������ ������� ������������� �� ���� '��� ���������'\n");
			}
			break;

			case 3:                            // �� ���������� ���������
				for (int i = 0; i < kol_vo; i++)
					for (int j = i; j < kol_vo; j++)
						if (strcmp(mas[i].dolgnost, mas[j].dolgnost) > 0)
						{
							t = mas[i];
							mas[i] = mas[j];
							mas[j] = t;
						}
				printf("\n������ ������� ������������� �� ���� '���������� ���������'\n");
				break;

			case 4:                            // �� ���� �������� �� ������
				for (int i = 0; i < kol_vo; i++)
					for (int j = i; j < kol_vo; j++)
						if (mas[i].year > mas[j].year)
						{
							buffer = mas[i];
							mas[i] = mas[j];
							mas[j] = buffer;
						}
				printf("\n������ ������� ������������� �� ���� '��� �������� �� ������'\n");
				break;

			case 5: return;                   //�����
			}

		} while (1);
	}
}
