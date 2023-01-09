#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stddef.h>
#include <stdlib.h>
#define LEN 100

struct Denrozhd
{
	char name[20];
	char surname[20];
	char cathegory[20];
	int day;
	int month;
	int year;

}*dr;

typedef struct Denrozhd DR;

DR input(DR* dr, int count);//Добавление новых записей


void output(DR* dr, int count);//Вывод записей

int write(DR* dr, int count);//Добавление записей в файл 


int read();//Чтение записей из файла



int search_output(DR* dr, int count);//Вывод записей


int search(DR* dr, int count);//Поиск записей по выбранной категории


DR sort(DR* dr, int count);//Сортировка записей по убыванию




int main()
{
	system("chcp 1251");
	setlocale(0, "Rus");
	int flag = 1;
	int k = 0;
	dr = malloc(k * sizeof(int));
	int z;

	while (flag != 0)
	{
		printf("\nВвод данных - 1\nВывод данных - 2\nЗапись данных в файл - 3\nВывод данных из файла - 4\nПоиск по катерогрии - 5\nСортировка - 6\nВыход из программы - 7\n");
		scanf("%d", &z);
		switch (z)
		{
		case 1:
			printf("Введите количество записей\n");
			scanf("%d", &k);
			input(dr, k);
			break;
		case 2:
			output(dr, k);
			break;
		case 3:
			write(dr, k);
			break;
		case 4:
			read();
			break;
		case 5:
			search(dr, k);
			break;
		case 6:
			sort(dr, k);
			break;
		case 7:
			flag = 0;
			break;

		}
	}
}

DR input(DR* dr, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("Введите имя:");
		scanf("%s", dr->name);
		printf("Введите фамилию:");
		scanf("%s", dr->surname);
		printf("Введите Категорию:");
		scanf("%s", dr->cathegory);
		printf("Введите день:");
		scanf("%d", &dr->day);
		printf("Введите месяц:");
		scanf("%d", &dr->month);
		printf("Введите год:");
		scanf("%d", &dr->year);
		printf("\n");
		dr++;
	}
	return *dr;
}

void output(DR* dr, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("Имя: %s\nФамилия: %s\nКатегория: %s\nДата рождения: %d/%d/%d\n\n", dr->name, dr->surname, dr->cathegory, dr->day, dr->month, dr->year);
		dr++;

	}
	return 0;

}

int write(DR* dr, int count)
{

	FILE* ptr_file = fopen("kp.txt", "w");
	for (int i = 0; i < count; i++)
	{
		fprintf(ptr_file, "Имя:%s\nФамилия:%s\nКатегория:%s\nДата: %d/%d/%d\n", dr[i].name, dr[i].surname, dr[i].cathegory, dr[i].day, dr[i].month, dr[i].year);
	}
	fclose(ptr_file);
	printf("\nДанные успешно сохранены\n");
}

int read()
{
	char rfile[LEN];
	FILE* ptr_file = fopen("kp.txt", "r");
	while (fgets(rfile, LEN, ptr_file))
		fprintf(stdout, "%s\n", rfile);

}


int search_output(DR* dr, int count)
{
	printf("Имя:%s\nФамилия:%s\nКатегория:%s\nДата: %d/%d/%d  \n", dr[count].name, dr[count].surname, dr[count].cathegory, dr[count].day, dr[count].month, dr[count].year);
}

int search(DR* dr, int count)
{
	int z;
	short name_f[20], surname_f[20], cathegory_f[20];


	int day_f;
	int month_f;
	int year_f;

	printf("Выберите критерий поиска\n");
	printf("По имени - 1\n");
	printf("По фамилии - 2\n");
	printf("По категории - 3\n");
	printf("По дате рождения - 4\n");
	scanf("%d", &z);
	if (z == 1)
	{
		printf("Введите имя:\n");
		scanf("%s", &name_f);
		for (int i = 0; i < count; i++)
		{
			if (strcmp((dr + i)->name, name_f) == 0)
			{
				search_output(dr, i);
			}
		}
		dr++;
	}
	if (z == 2)
	{
		printf("Введите фамилию:\n");
		scanf("%s", &surname_f);
		for (int i = 0; i < count; i++)
		{
			if (strcmp((dr + i)->surname, surname_f) == 0)
			{
				search_output(dr, i);
			}
		}
		dr++;
	}
	if (z == 3)
	{
		printf("Введите категорию:\n");
		scanf("%s", &cathegory_f);
		for (int i = 0; i < count; i++)
		{
			if (strcmp((dr + i)->cathegory, cathegory_f) == 0)
			{
				search_output(dr, i);
			}
		}
		dr++;
	}
	if (z == 4)
	{
		printf("Введите день\n");
		scanf("%d", &day_f);
		printf("Введите месяц\n");
		scanf("%d", &month_f);
		printf("Введите год\n");
		scanf("%d", &year_f);

		for (int i = 0; i < count; i++)
		{
			if (day_f == dr[i].day && month_f == dr[i].month && year_f == dr[i].year)
			{
				search_output(dr, i);
			}
		}
		dr++;
	}

}

DR sort(DR* dr, int count)
{
	DR sort;
	printf("Введите текущий год\n");
	int nowyear;
	scanf("%d", &nowyear);
	for (int i = count - 1; i >= 0; i--)
	{
		for (int g = 0; g < i; g++)
		{
			if ((nowyear - dr[g].year) < (nowyear - dr[g + 1].year))
			{
				sort = dr[g];
				dr[g] = dr[g + 1];
				dr[g + 1] = sort;
			}
		}
	}
	printf("\nСортировка завершена\n");
	return *dr;
	
}

