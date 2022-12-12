#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stddef.h>
#include <stdlib.h>

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
		printf("Имя: %s\nФамилия: %s\nКатегория: %s\nДата рождения: %d/%d/%d\n\n",dr->name, dr->surname, dr->cathegory, dr->day, dr->month, dr->year);
		dr++;
		
	}
	return 0;

}


int search_output(DR* dr, int count)
{
	printf("Имя:%s\nФамилия:%s\nКатегория:%s\nДата: %d/%d/%d  \n", dr[count].name, dr[count].surname, dr[count].cathegory, dr[count].day, dr[count].month, dr[count].year);
}

int search(DR* dr, int count)
{
	int z;
	short name_f, surname_f, cathegory_f;
	

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
			if (name_f = dr[i].name)
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
			if (surname_f = dr[i].surname)
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
			if (cathegory_f = dr[i].cathegory)
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
		printf("\nВвод данных - 1\nВывод данных - 2\nПоиск по категориям - 3\nСортировка - 4\nВыход из программы - 5\n");
		scanf("%d", &z);
		switch (z)
		{
		case 1:
			printf("Введите количество записей\n");
			scanf("%d", &k);
			input(dr, k);
			break;
			break;
		case 2:
			output(dr, k);
			break;
		case 3:
			search(dr, k);
			break;
		case 4:
			break;
		case 5:
			flag = 0;
			break;

		}
	}
}