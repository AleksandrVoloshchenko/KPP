#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <time.h>



struct Denrozhd
{
	char name[20];
	char surname[20];
	char cathegory[20];
	int day;
	int month;
	int year;

};

typedef struct Denrozhd DR;


DR* input(DR* gon, int* count, int size);
void output(DR* gon, int* count);
int* search_data(DR* dr, int* count, struct tm t);
int search_name(DR* gon, int* count, char* name_f);
DR* sort(DR* gon, int* count);
int write(char* namefile, DR* dr, int* count);
int read(char* namefile, DR* dr, int size_mas);
int prov(char* namefile);
int main()
{
	system("chcp 1251");
	
	DR* dr;
	int kol = 0, flag1 = 1, choice1, choicemenu, ind_name, size_mas = 0, size_mas1 = 0, mas_in_file, tm_day, month_f, k = 0, nowyear;
	dr = (DR*)malloc(kol * sizeof(DR));
	char name_f[10], namefile[10];
	int* ind_data;
	
	printf("Выберите действие>\n1.Ввод новой записи\n2.Вывод существующей записи из файла\n");
	scanf("%d", &choicemenu);
	switch (choicemenu)
	{
	case 1:
		printf("Введите кол-во записей ");
		scanf("%d", &kol);
		printf("------------------------\n");
		size_mas1 = kol;
		kol += size_mas;
		dr = (DR*)realloc(dr, kol * sizeof(DR));
		input(dr, &kol, size_mas);
		size_mas += size_mas1;
	

		break;
	case 2:
		printf("Введите название файла\n");
		scanf("%s", &namefile);
		mas_in_file = prov(namefile);
		kol += mas_in_file;
		dr = (DR*)realloc(dr, kol * sizeof(DR));
		kol = read(namefile, dr, size_mas);
		kol += size_mas;
		size_mas += mas_in_file;
		output(dr, &kol);
		break;

	}
	while (flag1)
	{


		printf("1.Ввод значений\n2.Вывод значений\n3.Поиск по имени\n4.Поиск по дате\n5.Сортировка данных\n6.Запись данных в файл\n7.Чтение данных из файла\n0.Выход из программы\n");
		scanf("%d", &choice1);
		switch (choice1)
		{
		case 1:
			printf("Введите кол-во записей ");
			scanf("%d", &kol);
			printf("------------------------\n");
			size_mas1 = kol;
			kol += size_mas;
			dr = (DR*)realloc(dr, kol * sizeof(DR));
			input(dr, &kol, size_mas);
			size_mas += size_mas1;
			break;


		case 2:

			output(dr, &kol);
			break;


		case 3:
			printf("Введите имя\n");
			scanf("%s", name_f);
			ind_name = searchname(dr, &kol, name_f);
			printf("---------------------------------------------------------------------\n");
			printf("|| Номер || Имя || Фамилия || Категория || Дата ||\n");
			printf("---------------------------------------------------------------------\n");
			printf("||%8d||%13s||%13s||%13s||%2d/%2d/%2d||\n", ind_name + 1, dr[ind_name].name, dr[ind_name].surname, dr[ind_name].cathegory, dr[ind_name].day, dr[ind_name].month, dr[ind_name].year);
			printf("---------------------------------------------------------------------\n");
			break;
		case 4:
		{struct tm t;
		int d, m, y;
		printf("Введите дату\n");
		scanf("%d/%d/%d", &t.tm_mday, &t.tm_mon, &t.tm_year);
		ind_data = search_data(dr, &kol, t);
		printf("---------------------------------------------------------------------\n");
		printf("|| Номер || Имя || Фамилия || Категория || Дата ||\n");
		printf("---------------------------------------------------------------------\n");
		for (int i = 0; i < kol; i++)
		{
			if (ind_data[i] >= 0 && ind_data[i] < kol)
			{
				k = ind_data[i];

				printf("||%8d||%13s||%13s||%13s||%2d/%2d/%2d||\n", k, dr[k].name, dr[k].surname, dr[k].cathegory, dr[k].day, dr[k].month, dr[k].year);
				printf("---------------------------------------------------------------------\n");
			}
		}
		break; }
		case 5:
			printf("Введите текущий год:\n");
			scanf("%d", &nowyear);
			sort(dr, &kol, nowyear);
			output(dr, &kol);
			break;
		case 6:
			printf("Введите название файла\n");
			scanf("%s", &namefile);
			write(namefile, dr, &kol);
			break;
		case 7:
			printf("Введите название файла\n");
			scanf("%s", &namefile);
			mas_in_file = prov(namefile);
			kol += mas_in_file;
			dr = (DR*)realloc(dr, kol * sizeof(DR));
			kol = read(namefile, dr, size_mas);
			kol += size_mas;
			size_mas += mas_in_file;
			break;

		case 0:

			flag1 = 0;
			printf("Программа заверешна\n");
			break;
		default:
			puts("Данный выбор невозможен");

		}

	}
	free(dr);
}

DR* input(DR* dr, int* count, int size_mas)
{
	for (int i = size_mas; i < *count; i++)
	{
		printf("Введите имя:");
		scanf("%s", dr[i].name);
		printf("Введите фамилию:");
		scanf("%s", dr[i].surname);
		printf("Введите Категорию:");
		scanf("%s", dr[i].cathegory);
		printf("Введите день, месяц, год:");
		scanf("%d", &dr[i].day);
		if (dr[i].day < 0 || dr[i].day>31) printf("Недопустимое значение (максимальное кол-во дней в месяце - 31)\n");
		scanf("%d", &dr[i].month);
		if (dr[i].month < 0 || dr[i].month>12) printf("Недопустимое значение ( кол-во месяцев в году - 12)\n");
		scanf("%d", &dr[i].year);
		printf("\n");
	}
	return dr;
}
void output(DR* dr, int* count)
{
	printf("---------------------------------------------------------------------\n");
	printf("|| Номер || Имя || Фамилия || Категория || Дата ||\n");
	printf("---------------------------------------------------------------------\n");
	for (int i = 0; i < *count; i++)
	{
		printf("||%8d||%13s||%13s||%13s||%2d/%2d/%2d||\n", i + 1, dr[i].name, dr[i].surname, dr[i].cathegory, dr[i].day, dr[i].month, dr[i].year);

	}

}
int searchname(DR* gon, int* count, char* name_f)
{

	int num = -1;
	for (int i = 0; i < *count; i++)
	{
		if (strcmp(gon[i].name, name_f) == 0)
		{
			num = i;
		}



	}
	return num;


}
int* search_data(DR* dr, int* count, struct tm t)
{

	int* num = (int*)malloc(*count * sizeof(int));

	int n = 0;
	for (int i = 0; i < *count; i++)
	{
		if (t.tm_mday == dr[i].day && t.tm_mon == dr[i].month && t.tm_year == dr[i].year)
		{
			num[n++] = i;
		}

	}
	return num;
}
DR* sort(DR* dr, int* count, int nowyear)
{

	DR sort;

	int left = 0, right = *count - 1; // левая и правая границы сортируемой области массива
	int flag = 1; // флаг наличия перемещений
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++) //двигаемся слева направо
		{
			if (nowyear - dr[i].year < nowyear - dr[i + 1].year) // если следующий элемент меньше текущего,
			{ // меняем их местами
				double t = dr[i].year;
				dr[i].year = dr[i + 1].year;
				dr[i + 1].year = t;
				flag = 1; // перемещения в этом цикле были
			}
		}
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--) //двигаемся справа налево
		{
			if (nowyear - dr[i - 1].year < nowyear - dr[i].year) // если предыдущий элемент больше текущего,
			{ // меняем их местами
				double t = dr[i].year;
				dr[i].year = dr[i - 1].year;
				dr[i - 1].year = t;
				flag = 1; // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
	}

	printf("Сортировка по возрасту в порядке убывния завершена\n");

	return dr;
}
int write(char* namefile, DR* dr, int* count)
{
	FILE* file;
	if ((file = fopen(namefile, "wt")) == NULL)
	{
		fprintf(stderr, "Файл нельзя открыть для записи\n");
		system("pause");
		return -1;

	}
	else
	{
		for (int i = 0; i < *count; i++)
		{
			fprintf(file, "%s\n", dr[i].name);
			fprintf(file, "%s\n", dr[i].surname);
			fprintf(file, "%s\n", dr[i].cathegory);
			fprintf(file, "%d\n", dr[i].day);
			fprintf(file, "%d\n", dr[i].month);
			fprintf(file, "%d\n", dr[i].year);


		}
		fclose(file);
		printf("Данные записаны\n");
	}
}
int read(char* namefile, DR* dr, int size_mas)
{
	FILE* open;
	int z;
	int i = size_mas;
	int o = 0;
	open = fopen(namefile, "rb");
	while (!feof(open))
	{
		fscanf(open, "\r\n%d\r\n", &z);
		fscanf(open, "%s\r\n", dr[i].name);
		fscanf(open, "%s\r\n", &dr[i].surname);
		fscanf(open, "%s\r\n", &dr[i].cathegory);
		fscanf(open, "%d\r\n", &dr[i].day);
		fscanf(open, "%d\r\n", &dr[i].month);
		fscanf(open, "%d\r\n", &dr[i].year);
		i += 1;
		o += 1;
	}
	fclose(open);
	printf("Файл прочитан\n");
	return o;
}
int prov(char* namefile)
{
	FILE* open;
	int n = 0;
	open = fopen(namefile, "rb");
	while (!feof(open))
	{
		if (fgetc(open) == '\n')
			n += 1;
	}
	fclose(open);
	return n / 6;
}

