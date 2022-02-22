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
		printf("\nНет записей\n\n");
	}
	else {
		do
		{
			int num;               //переменная для выбора, по какому полю будет производиться сортировка
			while (1) {
			printf("\nВведите, по какому признаку Вы хотите рассортировать записи:\n");
			printf("1-по фамилии работника\n");
			printf("2-по имени работника\n");
			printf("3-по занимаемой должности\n");
			printf("4-по году принятия на работу\n");
			printf("5-для прекращения\n");

				scanf_s("%d", &num);
				getchar();
				if (num > 0 && num <= 5) {       //проверка
					break;
				}
				else printf("\nНеверный выбор\n");
			}


			switch (num)
			{
			case 1:                            // по фамилии работника
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
				printf("\nЗаписи успешно отсортированы по полю 'Фамилия работника'\n");
			}
			break;

			case 2:                            // по имени работника
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
				printf("\nЗаписи успешно отсортированы по полю 'Имя работника'\n");
			}
			break;

			case 3:                            // по занимаемой должности
				for (int i = 0; i < kol_vo; i++)
					for (int j = i; j < kol_vo; j++)
						if (strcmp(mas[i].dolgnost, mas[j].dolgnost) > 0)
						{
							t = mas[i];
							mas[i] = mas[j];
							mas[j] = t;
						}
				printf("\nЗаписи успешно отсортированы по полю 'Занимаемая должность'\n");
				break;

			case 4:                            // по году принятия на работу
				for (int i = 0; i < kol_vo; i++)
					for (int j = i; j < kol_vo; j++)
						if (mas[i].year > mas[j].year)
						{
							buffer = mas[i];
							mas[i] = mas[j];
							mas[j] = buffer;
						}
				printf("\nЗаписи успешно отсортированы по полю 'Год принятия на работу'\n");
				break;

			case 5: return;                   //выход
			}

		} while (1);
	}
}
