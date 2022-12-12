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
		printf("������� ���:");
		scanf("%s", dr->name);
		printf("������� �������:");
		scanf("%s", dr->surname);
		printf("������� ���������:");
		scanf("%s", dr->cathegory);
		printf("������� ����:");
		scanf("%d", &dr->day);
		printf("������� �����:");
		scanf("%d", &dr->month);
		printf("������� ���:");
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
		printf("���: %s\n�������: %s\n���������: %s\n���� ��������: %d/%d/%d\n\n",dr->name, dr->surname, dr->cathegory, dr->day, dr->month, dr->year);
		dr++;
		
	}
	return 0;

}


int search_output(DR* dr, int count)
{
	printf("���:%s\n�������:%s\n���������:%s\n����: %d/%d/%d  \n", dr[count].name, dr[count].surname, dr[count].cathegory, dr[count].day, dr[count].month, dr[count].year);
}

int search(DR* dr, int count)
{
	int z;
	short name_f, surname_f, cathegory_f;
	

	int day_f;
	int month_f;
	int year_f;

	printf("�������� �������� ������\n");
	printf("�� ����� - 1\n");
	printf("�� ������� - 2\n");
	printf("�� ��������� - 3\n");
	printf("�� ���� �������� - 4\n");
	scanf("%d", &z);
	if (z == 1)
	{
		printf("������� ���:\n");
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
		printf("������� �������:\n");
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
		printf("������� ���������:\n");
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
		printf("������� ����\n");
		scanf("%d", &day_f);
		printf("������� �����\n");
		scanf("%d", &month_f);
		printf("������� ���\n");
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
		printf("\n���� ������ - 1\n����� ������ - 2\n����� �� ���������� - 3\n���������� - 4\n����� �� ��������� - 5\n");
		scanf("%d", &z);
		switch (z)
		{
		case 1:
			printf("������� ���������� �������\n");
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