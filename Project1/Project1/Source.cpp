#include <stdio.h>                      
#include <string.h>
#include<locale.h>
#include<stdlib.h>
#include "sort.h"

 struct worker                                                                   //��������� ������ ���������
{
	char familia[30];
	char name[30];
	char dolgnost[30];
	int year;
} inf;

        
struct worker *mas = (struct worker*)malloc(10 * sizeof(struct worker));          //����������� �������� ������ ��� ������ ��������
 worker  t, buffer;                                                               //��������� �������� ���������� ������������ ���� t � buffer ��� ����������
 static worker tmp;                                                               //����������� ���������� ��� ������� ��������
 int kol_vo = 0;                                                                  //������� ������ �������
int er;                                                                           //�������������

int menu();                                                                     
void enter_new();        // ������� ����� ����� ������
void change();           //������� ��� ��������� ������
void out();              //�������� ������ �������
void find();             //�������� ������ �������
void sort();             //������� ����������
void del();              //�������� �������� ������
void stag();             //������� ������ ������� �� ������ ������/������/����� ��������� �����
void read(FILE* f);      //������� ������ ������� �� �����
void _new(FILE* f);      //������� ����������� � ����


int main()
{
	setlocale(LC_ALL, "rus");
	while (1)
	{
		switch (menu())
		{
		case 1: enter_new(); break;
		case 2:change(); break;
		case 3:out(); break;
		case 4:find(); break;
		case 5: sort(); break;
		case 6:del(); break;
		case 7: stag(); break;
		case 8: {
			FILE* f;
			if (fopen_s(&f, "f.txt", "r") == 0) //��������� ���� p ��� ������
			{
				read(f);
				fclose(f);
			}
			else {
				printf("���������� ������� ���� f");
			}

			break;
		}
		case 9: return 0;
		default: printf("\n�������� �����\n");
		}
	}
	
	free(mas);
	
}

 int menu()
{
	int er;
	printf("\n�������:\n");
	printf("1. ��� ����� ����� ������\n");
	printf("2. ��� ��������� ������\n");
	printf("3. ��� ������ ������(��)\n");
	printf("4. ��� ������ \n");
	printf("5. ��� ���������� �� ���������� ��������\n");
	printf("6. ��� �������� ������\n");
	printf("7. ��� ������ ������� ����������, ��� ���� ������/������ ��������� � ��������� �����\n");
	printf("8. ��� ������ ������� �� �����\n");
	printf("9. ��� ������\n");
	scanf_s("%d", &er);
	getchar();
	return er;
}

// ������� ����� ����� ������
void enter_new()
{
	if (kol_vo < 10)              //������ ����� ������ ������, ���� ������� ������ ������� ������ ������������� ���������� �������
	{
		printf("������ ����� %d\n", kol_vo + 1);
		printf("\n������� ������� ���������\n");
		fgets(mas[kol_vo].familia, 30, stdin);
		fflush(stdin);

		printf("������� ��� ��������� \n");
		fgets(mas[kol_vo].name, 30, stdin);
		fflush(stdin);

		printf("������� ���������� ���������\n");
		fgets(mas[kol_vo].dolgnost, 30, stdin);

		int prov;
		while (1) {
			printf("������� ��� ����������� �� ������\n");
			scanf_s("%d", &prov);
			getchar();
			if (prov < 1970 || prov>2022) {
				printf("�������� ���\n");

			}
			else {
				mas[kol_vo].year = prov;
				break;
			}
		}
		kol_vo++;
	}
	else printf("������� ������������ ���-�� �������\n");
}

//������� ��� ��������� ������
void change()
{
	if (kol_vo == 0) {
		printf("\n��� �������\n\n");
	}
	else {
		register int c;                   //����� ������, ������� ����� ��������
		int per;                          //���������� ��� ������, �� ������ ���� ����� �������� ������
		while (1) {
			printf("\n������� ����� ������\n");                          //������ ����� ������, ������� ����� ��������, � ������ �������� �� ������������� ������ � ����� �����
			scanf_s("%d", &c);
			getchar();
			if (c > 0 && c <= kol_vo) {
				break;
			}
			else printf("\n�������� �����\n");
		}
		do
		{
			
				printf("\n�������: \n");                                       //���� ��� ������, �� ������ ���� ����� �������� ������
				printf("1. ��� ��������� ������� ���������\n");
				printf("2. ��� ��������� ����� ���������\n");
				printf("3. ��� ��������� ���������� ���������\n");
				printf("4. ��� ��������� ���� ����� �� ������\n");
				printf("5. ��� �����������\n");
				scanf_s("%d", &per);
				getchar();
			
				switch (per)
				{
				case 1: {                                                              //��������� ������� ���������
					printf("\n������� ����� ������� ���������\n");
					fgets(mas[c - 1].familia, 30, stdin);
					printf("������ ������� ��������\n");
					break;
				}
				case 2: {                                                              //��������� ����� ���������
					printf("\n������� ����� ��� ���������\n");
					fgets(mas[c - 1].name, 30, stdin);
					printf("������ ������� ��������\n");
					break;
				}
				case 3: {                                                              //��������� ��������� ���������
					printf("\n������� ����� ���������� ���������\n");
					fgets(mas[c - 1].dolgnost, 30, stdin);
					printf("������ ������� ��������\n");
					break;
				}
				case 4: {                                                              //��������� ���� �������� �� ������
					int prov;
					while (1) {
						printf("������� ��� ����������� �� ������\n");
						scanf_s("%d", &prov);
						getchar();
						if (prov < 1970 || prov>2022) {
							printf("�������� ���\n");

						}
						else {
							mas[c - 1].year = prov;
							break;
						}
					}
					printf("������ ������� ��������\n");
					break;
				}
				case 5: return;                                                              //�����

				default: printf("\n�������� �����\n");
				}
		} while (1);
	}
}

//�������� ������ �������
void out()
{

	int sw;                               // ������������� ��� ������ �������� ��� ������ ��� ����
	int k;                                //����� ���������, ������� ���� �������
	if (kol_vo == 0)                       //���� ������� ���������� �������� ����� 0, �� �������, ��� ��� �������
		printf("\n��� �������\n\n");
	else
	{

		                                                         //���� ��� ������, 1 ������ ��� ��� ����� ��������
			printf("\n�������: \n");
			printf("1. ��� ������ �����-���� ������\n");
			printf("2. ��� ������ ���� �������\n");
			printf("3. ��� ������\n");
			scanf_s("%d", &sw);
			getchar();
			
		switch (sw) {
		case 1: {
			while (1) {
				printf("������� ����� ������, ������� ����� �������\n");              //������ ����� ������, ������� ����� �������, � ��������� �� �������������
				scanf_s("%d", &k);
				getchar();
				if (k > 0 && k <= kol_vo) {
					break;
				}
				else printf("\n�������� �����\n");
			}

			printf("\n������ ����� %d\n", k);
			printf("-------------------\n");
			printf("������� ���������: %s\n", mas[k - 1].familia);
			printf("��� ���������: %s\n", mas[k - 1].name);
			printf("���������� ���������: %s\n", mas[k - 1].dolgnost);
			printf("��� �������� �� ������: %d\n", mas[k - 1].year);
		}
			  break;

		case 2: {
			for (register int i = 0; i < kol_vo; i++)                                    //������� � ����� ��� ������
			{
				printf("\n\n������ ����� %d\n", i + 1);
				printf("-------------------\n");
				printf("������� ���������: %s\n", mas[i].familia);
				printf("��� ���������: %s\n", mas[i].name);
				printf("���������� ���������: %s\n", mas[i].dolgnost);
				printf("��� �������� �� ������: %d\n", mas[i].year);

			}
		}
			  break;
		case 3: return;
		default: printf("\n�������� �����\n");
		}
	}
}

//�������� ������ �������
void find()
{
	if (kol_vo == 0) {
		printf("\n��� �������\n\n");
	}
	else {
		do
		{
			int num;                             //���������� ��� ������, �� ������ ���� ����� ����������� �����
			
				printf("\n�������, �� ������ �������� �� ������ ���������� �����:\n");
				printf("1. �� ������� ���������\n");
				printf("2. �� ����� ���������\n");
				printf("3. �� ���������� ���������\n");
				printf("4. �� ���� ����� �� ������\n");
				printf("5. ��� �����������\n");
				scanf_s("%d", &num);                      //��������
				getchar();

			switch (num)
			{

			case 1:                                       // �� ������� ���������
			{
				if (kol_vo == 0)
					printf("\n��� ������� \n");
				else
				{
					char familia[30];
					printf("������� ������� ���������:\n");
					fgets(familia, 30, stdin);
					fflush(stdin);

					int count = 0;
					for (register int i = 0; i < kol_vo; i++) {
						if (strcmp(mas[i].familia, familia) == 0) {
							count++;
							printf("\n������ ����� %d\n", i + 1);
							printf("-------------------\n");
							printf("������� ���������: %s\n", mas[i].familia);
							printf("��� ���������: %s\n", mas[i].name);
							printf("���������� ���������: %s\n", mas[i].dolgnost);
							printf("��� �������� �� ������: %d\n", mas[i].year);
							printf("____________\n");
						}
					}
					if (count == 0) printf("\n���������� � ����� �������� ���\n");
				}
			}
			break;

			case 2:                          //�� ����� ���������
			{
				if (kol_vo == 0)
					printf("\n��� ������� \n");
				else
				{
					printf("������� ��� ���������:\n");
					char name[30];
					fgets(name, 30, stdin);
					fflush(stdin);

					int count = 0;
					for (register int i = 0; i < kol_vo; i++) {
						if (strcmp(mas[i].name, name) == 0) {
							count++;
							printf("\n������ ����� %d\n", i + 1);
							printf("-------------------\n");
							printf("������� ���������: %s\n", mas[i].familia);
							printf("��� ���������: %s\n", mas[i].name);
							printf("���������� ���������: %s\n", mas[i].dolgnost);
							printf("��� �������� �� ������: %d\n", mas[i].year);
							printf("____________\n");
						}
					}
					if (count == 0) printf("\n���������� � ����� ������ ���\n");
				}
			}
			break;

			case 3:                      //�� ���������� ���������
			{
				if (kol_vo == 0)
					printf("\n��� ������� \n");
				else
				{
					printf("������� ���������� ���������:\n");
					char dolgnost[30];
					fgets(dolgnost, 30, stdin);
					fflush(stdin);

					int count = 0;
					for (register int i = 0; i < kol_vo; i++) {
						if (strcmp(mas[i].dolgnost, dolgnost) == 0) {
							count++;
							printf("\n������ ����� %d\n", i + 1);
							printf("-------------------\n");
							printf("������� ���������: %s\n", mas[i].familia);
							printf("��� ���������: %s\n", mas[i].name);
							printf("���������� ���������: %s\n", mas[i].dolgnost);
							printf("��� �������� �� ������: %d\n", mas[i].year);
							printf("____________\n");
						}
					}
					if (count == 0) printf("\n���������� � ����� ���������� ���\n");
				}
			}
			break;

			case 4: {                          //�� ���� ������� �� ������
				int year;
				if (kol_vo == 0)
					printf("\n��� ������� \n");
				else
				{
					while (1) {                       //������ ��� �������� � ��������� �� �������������� ���������� [1970; 2022]
						printf("\n������� ��� �������� �� ������: \n");
						scanf_s("%d", &year);
						getchar();
						if (year >= 1970 && year <= 2022) {
							break;
						}
						else {
							printf("\n�������� ���\n");
							printf("\n������� ��� �� ���������� [1970; 2022]\n");
						}
					}

					int count = 0;
					for (register int i = 0; i < kol_vo; i++)               //� ����� ������������� ��� ��������� �� ������� ��������
					{
						if (mas[i].year == year) {
							count++;
							printf("\n������ ����� %d\n", i + 1);
							printf("-------------------\n");
							printf("������� ���������: %s\n", mas[i].familia);
							printf("��� ���������: %s\n", mas[i].name);
							printf("���������� ���������: %s\n", mas[i].dolgnost);
							printf("��� �������� �� ������: %d\n", mas[i].year);
							printf("____________\n");
						}
					}
					if (count == 0) printf("\n���������� � ����� ����� �������� �� ������ ���\n");
				}
			}
				  break;

			case 5:  return;            //�����
			default: printf("\n�������� �����\n");
			}
		} while (1);
	}
}

//�������� �������� ������
void del()
{
	if (kol_vo == 0) {
		printf("\n��� �������\n\n");
	}
	else {
		int d;                                              //����� ������, ������� ����� �������
		while (1) {
			printf("\n������� ����� ������, ������� ���������� �������\n");
			printf("���� ���������� ������� ��� ������, ������� 11\n");
			scanf_s("%d", &d);
			getchar();
			if ((d > 0 && d <= kol_vo) || d == 11) {                 //��������� ����� ������ �� �������������
				break;
			}
			else printf("\n�������� �����\n");
		}

		if (d == 11)
		{
			for (register int i = 0; i < 30; i++) {
				mas[i] = tmp;                                        //�������� ������ ��������� � ������� ������ ����������
				kol_vo = 0;
			}
			printf("\n��� ������ ������� �������\n");
		}
		else
		{
			for (register int i = (d - 1); i < kol_vo; i++)         //���� ��� �������� �������� ������, �������� ���� � ��������� ������
				mas[i] = mas[i + 1];                                //�������� ������� ������ ��������� �� ���
			kol_vo--;
			printf("\n������ ������� �������\n");
		}
	}
}

//������� ������ ������� �� ������ ������/������/����� ��������� �����
void stag()
{
	if (kol_vo == 0) {
		printf("\n��� �������\n");
	}
	else {
		int zapis1;                            //���������� ��� ������, ����� ���� ����� ��������
		
			printf("\n�������, ������ ����� ���������� �� ������ �������\n");
			printf("1. ��� ���� ������ ��������� �����\n");
			printf("2. ��� ���� ������ ��������� �����\n");
			printf("3. ��� ���� ����� ��������� �����\n");
			printf("4. �����\n");
			scanf_s("%d", &zapis1);
			getchar();

		switch (zapis1) {
		case 1: {                                          //���� ������ ��������� �����
			int stag1;
			while (1) {
				printf("\n������� �����\n");              //������ ����� � ���������, �� ������ 70 �� ���
				scanf_s("%d", &stag1);
				getchar();
				if (stag1 < 0 || stag1>70) {
					printf("\n�������� �����\n");

				}
				else {
					int count = 0;
					for (int i = 0; i < kol_vo; i++) {
						if (stag1 < (2022 - mas[i].year)) {

							printf("\n������ ����� %d\n", i + 1);
							printf("-------------------\n");
							printf("������� ���������: %s\n", mas[i].familia);
							printf("��� ���������: %s\n", mas[i].name);
							printf("���������� ���������: %s\n", mas[i].dolgnost);
							printf("��� �������� �� ������: %d\n", mas[i].year);
							count++;
						}
					}
					if (count == 0) {
						printf("\n���������� � ����� ������ ���\n");
					}
					break;
				}
			}
			break;
		}
		case 2: {                                                          //���� ������ ��������� �����
			int stag1;
			while (1) {       
				printf("\n������� �����\n");                                //������ ����� � ���������, �� ������ 70 �� ���
				scanf_s("%d", &stag1);
				getchar();
				if (stag1 < 0 || stag1>70) {
					printf("\n�������� �����\n");

				}
				else {
					int count = 0;
					for (int i = 0; i < kol_vo; i++) {
						if (stag1 > (2022 - mas[i].year)) {

							printf("\n������ ����� %d\n", i + 1);
							printf("-------------------\n");
							printf("������� ���������: %s\n", mas[i].familia);
							printf("��� ���������: %s\n", mas[i].name);
							printf("���������� ���������: %s\n", mas[i].dolgnost);
							printf("��� �������� �� ������: %d\n", mas[i].year);
							count++;
						}
					}
					if (count == 0) {
						printf("\n���������� � ����� ������ ���\n");
					}
					break;
				}
			}
			break;
		} 
		case 3:                                                             //���� ����� ��������� �����
		{
			int stag1;
			while (1) {
				printf("\n������� �����\n");                                //������ ����� � ���������, �� ������ 70 �� ���
				scanf_s("%d", &stag1);
				getchar();
				if (stag1 < 0 || stag1>70) {
					printf("\n�������� �����\n");

				}
				else {
					int count = 0;
					for (int i = 0; i < kol_vo; i++) {
						if (stag1 == (2022 - mas[i].year)) {

							printf("\n������ ����� %d\n", i + 1);
							printf("-------------------\n");
							printf("������� ���������: %s\n", mas[i].familia);
							printf("��� ���������: %s\n", mas[i].name);
							printf("���������� ���������: %s\n", mas[i].dolgnost);
							printf("��� �������� �� ������: %d\n", mas[i].year);
							count++;
						}
					}
					if (count == 0) {
						printf("\n���������� � ����� ������ ���\n");
					}
					break;
				}
			}
			break;
		}
		case 4: break;                                                     //�����
		default: printf("\n�������� �����\n");
		}
	}
}          

//������� ������ ������� �� �����
void read(FILE* f)
{
		for (register int i = 0; i < 10; i++)
		{
			fread(&mas[i], sizeof(mas[i]), 1, f);
		}
		printf("\n������ �� ����� ������� ���������\n");
		kol_vo = 10;
}  

//������� ����������� � ����
void _new(FILE* f)
{

	for (int i = 0; i < 10; i++) {
		printf("\n������� ������� ���������\n");
		fflush(stdin);
		fgets(inf.familia, 30, stdin);

		printf("������� ��� ���������\n");
		fflush(stdin);
		fgets(inf.name, 30, stdin);

		printf("������� ���������� ���������\n");
		fflush(stdin);
		fgets(inf.dolgnost, 30, stdin);

		int prov;
		while (1) {
			printf("������� ��� ����������� �� ������\n");
			scanf_s("%d", &prov);
			getchar();
			if (prov < 1970 || prov>2022) {
				printf("�������� ���\n");

			}
			else {
				inf.year = prov;
				break;
			}
		}

		fwrite(&inf, sizeof(inf), 1, f);
	}
	kol_vo = 10;
}

