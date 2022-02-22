#include <stdio.h>                      
#include <string.h>
#include<locale.h>
#include<stdlib.h>
#include "sort.h"

 struct worker                                                                   //объявляем шаблон структуры
{
	char familia[30];
	char name[30];
	char dolgnost[30];
	int year;
} inf;

        
struct worker *mas = (struct worker*)malloc(10 * sizeof(struct worker));          //динамически выделяем память под массив структур
 worker  t, buffer;                                                               //объявляем временую переменную структурного типа t и buffer для сортировки
 static worker tmp;                                                               //статическая переменная для функции удаления
 int kol_vo = 0;                                                                  //Счетчик полных записей
int er;                                                                           //Переключатель

int menu();                                                                     
void enter_new();        // функция ввода новой записи
void change();           //функция для изменения записи
void out();              //функцция вывода записей
void find();             //функцция поиска записей
void sort();             //функция сортировки
void del();              //функцция удаления записи
void stag();             //функция вывода записей со стажем больше/меньше/равен введённого числа
void read(FILE* f);      //функция чтения записей из файла
void _new(FILE* f);      //функция записывания в файл


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
			if (fopen_s(&f, "f.txt", "r") == 0) //открываем файл p для чтения
			{
				read(f);
				fclose(f);
			}
			else {
				printf("Невозможно открыть файл f");
			}

			break;
		}
		case 9: return 0;
		default: printf("\nНеверный выбор\n");
		}
	}
	
	free(mas);
	
}

 int menu()
{
	int er;
	printf("\nВведите:\n");
	printf("1. Для ввода новой записи\n");
	printf("2. Для изменения записи\n");
	printf("3. Для вывода записи(ей)\n");
	printf("4. Для поиска \n");
	printf("5. Для сортировки по указанному признаку\n");
	printf("6. Для удаления записи\n");
	printf("7. Для вывода записей работников, чем стаж больше/меньше введённого с клавитуры числа\n");
	printf("8. Для чтения записей из файла\n");
	printf("9. Для выхода\n");
	scanf_s("%d", &er);
	getchar();
	return er;
}

// функция ввода новой записи
void enter_new()
{
	if (kol_vo < 10)              //вводим новую запись только, если счетчик полных записей меньше максимального количества записей
	{
		printf("Запись номер %d\n", kol_vo + 1);
		printf("\nВведите фамилию работника\n");
		fgets(mas[kol_vo].familia, 30, stdin);
		fflush(stdin);

		printf("Введите имя работника \n");
		fgets(mas[kol_vo].name, 30, stdin);
		fflush(stdin);

		printf("Введите занимаемую должность\n");
		fgets(mas[kol_vo].dolgnost, 30, stdin);

		int prov;
		while (1) {
			printf("Введите год поступления на работу\n");
			scanf_s("%d", &prov);
			getchar();
			if (prov < 1970 || prov>2022) {
				printf("Неверный год\n");

			}
			else {
				mas[kol_vo].year = prov;
				break;
			}
		}
		kol_vo++;
	}
	else printf("Введено максимальное кол-во записей\n");
}

//функция для изменения записи
void change()
{
	if (kol_vo == 0) {
		printf("\nНет записей\n\n");
	}
	else {
		register int c;                   //номер записи, которую нужно изменить
		int per;                          //переменная для выбора, по какому полю будет изменена запись
		while (1) {
			printf("\nВведите номер записи\n");                          //вводим номер записи, который нужно изменить, и делаем проверку на существование записи с таким номер
			scanf_s("%d", &c);
			getchar();
			if (c > 0 && c <= kol_vo) {
				break;
			}
			else printf("\nНеверный выбор\n");
		}
		do
		{
			
				printf("\nВведите: \n");                                       //меню для выюора, по какому полю будет изменена запись
				printf("1. Для изменения фамилии работника\n");
				printf("2. Для изменения имени работника\n");
				printf("3. Для изменения занимаемой должности\n");
				printf("4. Для изменения года приёма на работу\n");
				printf("5. Для прекращения\n");
				scanf_s("%d", &per);
				getchar();
			
				switch (per)
				{
				case 1: {                                                              //изменение фамилии работника
					printf("\nВведите новую фамилию работника\n");
					fgets(mas[c - 1].familia, 30, stdin);
					printf("Запись успешно изменена\n");
					break;
				}
				case 2: {                                                              //изменение имени работника
					printf("\nВведите новое имя работника\n");
					fgets(mas[c - 1].name, 30, stdin);
					printf("Запись успешно изменена\n");
					break;
				}
				case 3: {                                                              //изменение должности работника
					printf("\nВведите новую занимаемую должность\n");
					fgets(mas[c - 1].dolgnost, 30, stdin);
					printf("Запись успешно изменена\n");
					break;
				}
				case 4: {                                                              //изменение года принятия на работу
					int prov;
					while (1) {
						printf("Введите год поступления на работу\n");
						scanf_s("%d", &prov);
						getchar();
						if (prov < 1970 || prov>2022) {
							printf("Неверный год\n");

						}
						else {
							mas[c - 1].year = prov;
							break;
						}
					}
					printf("Запись успешно изменена\n");
					break;
				}
				case 5: return;                                                              //выход

				default: printf("\nНеверный выбор\n");
				}
		} while (1);
	}
}

//функцция вывода записей
void out()
{

	int sw;                               // переключатель для выбора выводить все записи или одну
	int k;                                //номер структуры, которую надо вывести
	if (kol_vo == 0)                       //если счетчик количества структур равен 0, то выводим, что нет записей
		printf("\nНет записей\n\n");
	else
	{

		                                                         //меню для выбора, 1 запись или все нужно выводить
			printf("\nВведите: \n");
			printf("1. Для вывода какой-либо записи\n");
			printf("2. Для вывода всех записей\n");
			printf("3. Для выхода\n");
			scanf_s("%d", &sw);
			getchar();
			
		switch (sw) {
		case 1: {
			while (1) {
				printf("Введите номер записи, которую нужно вывести\n");              //вводим номер запись, которую нужно вывести, и проверяем на существование
				scanf_s("%d", &k);
				getchar();
				if (k > 0 && k <= kol_vo) {
					break;
				}
				else printf("\nНеверный выбор\n");
			}

			printf("\nЗапись номер %d\n", k);
			printf("-------------------\n");
			printf("Фамилия работника: %s\n", mas[k - 1].familia);
			printf("Имя работника: %s\n", mas[k - 1].name);
			printf("Занимаемая должность: %s\n", mas[k - 1].dolgnost);
			printf("Год принятия на работу: %d\n", mas[k - 1].year);
		}
			  break;

		case 2: {
			for (register int i = 0; i < kol_vo; i++)                                    //выводим в цикле все записи
			{
				printf("\n\nЗапись номер %d\n", i + 1);
				printf("-------------------\n");
				printf("Фамилия работника: %s\n", mas[i].familia);
				printf("Имя работника: %s\n", mas[i].name);
				printf("Занимаемая должность: %s\n", mas[i].dolgnost);
				printf("Год принятия на работу: %d\n", mas[i].year);

			}
		}
			  break;
		case 3: return;
		default: printf("\nНеверный выбор\n");
		}
	}
}

//функцция поиска записей
void find()
{
	if (kol_vo == 0) {
		printf("\nНет записей\n\n");
	}
	else {
		do
		{
			int num;                             //переменная для выбора, по какому полю будет происходить поиск
			
				printf("\nВведите, по какому признаку Вы хотите произвести поиск:\n");
				printf("1. По фамилии работника\n");
				printf("2. По имени работника\n");
				printf("3. По занимаемой должности\n");
				printf("4. По году приёма на работу\n");
				printf("5. Для прекращения\n");
				scanf_s("%d", &num);                      //проверка
				getchar();

			switch (num)
			{

			case 1:                                       // по фамилии работника
			{
				if (kol_vo == 0)
					printf("\nНет записей \n");
				else
				{
					char familia[30];
					printf("Введите фамилию работника:\n");
					fgets(familia, 30, stdin);
					fflush(stdin);

					int count = 0;
					for (register int i = 0; i < kol_vo; i++) {
						if (strcmp(mas[i].familia, familia) == 0) {
							count++;
							printf("\nЗапись номер %d\n", i + 1);
							printf("-------------------\n");
							printf("Фамилия работника: %s\n", mas[i].familia);
							printf("Имя работника: %s\n", mas[i].name);
							printf("Занимаемая должность: %s\n", mas[i].dolgnost);
							printf("Год принятия на работу: %d\n", mas[i].year);
							printf("____________\n");
						}
					}
					if (count == 0) printf("\nРаботников с такой фамилией нет\n");
				}
			}
			break;

			case 2:                          //по имени работника
			{
				if (kol_vo == 0)
					printf("\nНет записей \n");
				else
				{
					printf("Введите имя работника:\n");
					char name[30];
					fgets(name, 30, stdin);
					fflush(stdin);

					int count = 0;
					for (register int i = 0; i < kol_vo; i++) {
						if (strcmp(mas[i].name, name) == 0) {
							count++;
							printf("\nЗапись номер %d\n", i + 1);
							printf("-------------------\n");
							printf("Фамилия работника: %s\n", mas[i].familia);
							printf("Имя работника: %s\n", mas[i].name);
							printf("Занимаемая должность: %s\n", mas[i].dolgnost);
							printf("Год принятия на работу: %d\n", mas[i].year);
							printf("____________\n");
						}
					}
					if (count == 0) printf("\nРаботников с таким именем нет\n");
				}
			}
			break;

			case 3:                      //по занимаемой должности
			{
				if (kol_vo == 0)
					printf("\nНет записей \n");
				else
				{
					printf("Введите занимаемую должность:\n");
					char dolgnost[30];
					fgets(dolgnost, 30, stdin);
					fflush(stdin);

					int count = 0;
					for (register int i = 0; i < kol_vo; i++) {
						if (strcmp(mas[i].dolgnost, dolgnost) == 0) {
							count++;
							printf("\nЗапись номер %d\n", i + 1);
							printf("-------------------\n");
							printf("Фамилия работника: %s\n", mas[i].familia);
							printf("Имя работника: %s\n", mas[i].name);
							printf("Занимаемая должность: %s\n", mas[i].dolgnost);
							printf("Год принятия на работу: %d\n", mas[i].year);
							printf("____________\n");
						}
					}
					if (count == 0) printf("\nРаботников с такой должностью нет\n");
				}
			}
			break;

			case 4: {                          //по году приняти на работу
				int year;
				if (kol_vo == 0)
					printf("\nНет записей \n");
				else
				{
					while (1) {                       //вводим год принятия и проверяем на принадлежность промежутку [1970; 2022]
						printf("\nВведите год принятия на работу: \n");
						scanf_s("%d", &year);
						getchar();
						if (year >= 1970 && year <= 2022) {
							break;
						}
						else {
							printf("\nНеверный год\n");
							printf("\nВведите год на промежутке [1970; 2022]\n");
						}
					}

					int count = 0;
					for (register int i = 0; i < kol_vo; i++)               //в цикле просматриваем все структуры из массива структур
					{
						if (mas[i].year == year) {
							count++;
							printf("\nЗапись номер %d\n", i + 1);
							printf("-------------------\n");
							printf("Фамилия работника: %s\n", mas[i].familia);
							printf("Имя работника: %s\n", mas[i].name);
							printf("Занимаемая должность: %s\n", mas[i].dolgnost);
							printf("Год принятия на работу: %d\n", mas[i].year);
							printf("____________\n");
						}
					}
					if (count == 0) printf("\nРаботников с таким годом принятия на работу нет\n");
				}
			}
				  break;

			case 5:  return;            //выход
			default: printf("\nНеверный выбор\n");
			}
		} while (1);
	}
}

//функцция удаления записи
void del()
{
	if (kol_vo == 0) {
		printf("\nНет записей\n\n");
	}
	else {
		int d;                                              //номер записи, которую нужно удалить
		while (1) {
			printf("\nВведите номер записи, которую необходимо удалить\n");
			printf("Если необходимо удалить все записи, введите 11\n");
			scanf_s("%d", &d);
			getchar();
			if ((d > 0 && d <= kol_vo) || d == 11) {                 //проверяем номер записи на существование
				break;
			}
			else printf("\nНеверный выбор\n");
		}

		if (d == 11)
		{
			for (register int i = 0; i < 30; i++) {
				mas[i] = tmp;                                        //замещаем каждую структуру в массиве пустой структурой
				kol_vo = 0;
			}
			printf("\nВсе записи успешно удалены\n");
		}
		else
		{
			for (register int i = (d - 1); i < kol_vo; i++)         //цикл для удаления заданной записи, начинаем цикл с удаляемой записи
				mas[i] = mas[i + 1];                                //замещаем текущую запись следующей за ней
			kol_vo--;
			printf("\nЗапись успешно удалена\n");
		}
	}
}

//функция вывода записей со стажем больше/меньше/равен введённого числа
void stag()
{
	if (kol_vo == 0) {
		printf("\nНет записей\n");
	}
	else {
		int zapis1;                            //переменная для выбора, какой стаж будем выводить
		
			printf("\nВведите, записи каких работников Вы хотите вывести\n");
			printf("1. Чей стаж больше введённого числа\n");
			printf("2. Чей стаж меньше введённого числа\n");
			printf("3. Чей стаж равен введённому числу\n");
			printf("4. Выход\n");
			scanf_s("%d", &zapis1);
			getchar();

		switch (zapis1) {
		case 1: {                                          //стаж больше введённого числа
			int stag1;
			while (1) {
				printf("\nВведите число\n");              //вводим число и проверяем, не больше 70 ли оно
				scanf_s("%d", &stag1);
				getchar();
				if (stag1 < 0 || stag1>70) {
					printf("\nНеверное число\n");

				}
				else {
					int count = 0;
					for (int i = 0; i < kol_vo; i++) {
						if (stag1 < (2022 - mas[i].year)) {

							printf("\nЗапись номер %d\n", i + 1);
							printf("-------------------\n");
							printf("Фамилия работника: %s\n", mas[i].familia);
							printf("Имя работника: %s\n", mas[i].name);
							printf("Занимаемая должность: %s\n", mas[i].dolgnost);
							printf("Год принятия на работу: %d\n", mas[i].year);
							count++;
						}
					}
					if (count == 0) {
						printf("\nРаботников с таким стажем нет\n");
					}
					break;
				}
			}
			break;
		}
		case 2: {                                                          //стаж меньше введённого числа
			int stag1;
			while (1) {       
				printf("\nВведите число\n");                                //вводим число и проверяем, не больше 70 ли оно
				scanf_s("%d", &stag1);
				getchar();
				if (stag1 < 0 || stag1>70) {
					printf("\nНеверное число\n");

				}
				else {
					int count = 0;
					for (int i = 0; i < kol_vo; i++) {
						if (stag1 > (2022 - mas[i].year)) {

							printf("\nЗапись номер %d\n", i + 1);
							printf("-------------------\n");
							printf("Фамилия работника: %s\n", mas[i].familia);
							printf("Имя работника: %s\n", mas[i].name);
							printf("Занимаемая должность: %s\n", mas[i].dolgnost);
							printf("Год принятия на работу: %d\n", mas[i].year);
							count++;
						}
					}
					if (count == 0) {
						printf("\nРаботников с таким стажем нет\n");
					}
					break;
				}
			}
			break;
		} 
		case 3:                                                             //стаж равен введённому числу
		{
			int stag1;
			while (1) {
				printf("\nВведите число\n");                                //вводим число и проверяем, не больше 70 ли оно
				scanf_s("%d", &stag1);
				getchar();
				if (stag1 < 0 || stag1>70) {
					printf("\nНеверное число\n");

				}
				else {
					int count = 0;
					for (int i = 0; i < kol_vo; i++) {
						if (stag1 == (2022 - mas[i].year)) {

							printf("\nЗапись номер %d\n", i + 1);
							printf("-------------------\n");
							printf("Фамилия работника: %s\n", mas[i].familia);
							printf("Имя работника: %s\n", mas[i].name);
							printf("Занимаемая должность: %s\n", mas[i].dolgnost);
							printf("Год принятия на работу: %d\n", mas[i].year);
							count++;
						}
					}
					if (count == 0) {
						printf("\nРаботников с таким стажем нет\n");
					}
					break;
				}
			}
			break;
		}
		case 4: break;                                                     //выход
		default: printf("\nНеверный выбор\n");
		}
	}
}          

//функция чтения записей из файла
void read(FILE* f)
{
		for (register int i = 0; i < 10; i++)
		{
			fread(&mas[i], sizeof(mas[i]), 1, f);
		}
		printf("\nДанные из файла успешно прочитаны\n");
		kol_vo = 10;
}  

//функция записывания в файл
void _new(FILE* f)
{

	for (int i = 0; i < 10; i++) {
		printf("\nВведите фамилию работника\n");
		fflush(stdin);
		fgets(inf.familia, 30, stdin);

		printf("Введите имя работника\n");
		fflush(stdin);
		fgets(inf.name, 30, stdin);

		printf("Введите занимаемую должность\n");
		fflush(stdin);
		fgets(inf.dolgnost, 30, stdin);

		int prov;
		while (1) {
			printf("Введите год поступления на работу\n");
			scanf_s("%d", &prov);
			getchar();
			if (prov < 1970 || prov>2022) {
				printf("Неверный год\n");

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

