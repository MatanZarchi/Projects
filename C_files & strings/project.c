


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define SIZE 100

void createFile(char* a) //����� 3 ���� � 
{
	char converting[SIZE] = { 0 };
	char line[SIZE];
	strcat(converting, a);
	strcat(converting, ".txt");

	FILE* file = fopen(converting, "w+t");

	printf("Enter your line to the %s file\n", converting);
	gets(line);
	fputs(line, file);
	fclose(file);


}

char commonestLetter(char* filename) //����� 3 ���� � 
{
	createFile(filename);
	int winner, flag = 0;;
	int check = 0, i = 0;
	int monim[26] = { 0 };
	char winwin = 0;

	FILE* fileptr = fopen("filename.txt", "rt");

	while (check != EOF)
	{
		check = fgetc(fileptr);
		monim[tolower(check) - 'a']++;
		flag++;
	}
	if (flag == 1)
	{
		return winwin;
	}
	else
	{
		winner = monim[0];

		for (i = 1; i < 26; i++)
		{
			if (monim[i] > winner)
			{
				winner = monim[i];
				winwin = i;
			}
			else if (winner == monim[i])
			{
				winner = monim[i];
				winwin = i;

			}
			else
			{
				continue;
			}
		}

		return 	toupper(winwin + 'a');
	}


}

int string_with_no_spaces_size(char* a) //����� 2- ���� ������ ������� 
{
	int i = 0, counter = 0;
	while (a[i] != '\0')
	{
		if (a[i] == ' ')
		{
			i++;
		}
		else if (a[i] >= '0' && a[i] <= '9')
		{
			i++;
		}
		else
		{
			counter++;
			i++;
		}
	}
	return counter + 1;

}

char* clearDigitsAndSpaces(char* a) //����� 2 ������� 
{
	int size = string_with_no_spaces_size(a), i = 0, j = 0;
	char* new_string = (char*)malloc(size * sizeof(char));
	while (a[i] != '\0')
	{
		if (a[i] == ' ')
		{
			i++;
		}
		else if (a[i] != ' ')
		{
			if (a[i] >= '0' && a[i] <= '9')
			{
				i++;
			}
			else
			{
				new_string[j] = a[i];
				j++;
				i++;
				if (a[i] != '\0')
				{
					new_string[j] = '\0';
				}
			}
		}

	}
	return new_string;

}

int colom_for_string(char* a, int index) //����� 1- ���� ���� ��� ����
{
	int counter = 0, i = index;

	while (a[i] != '\0')
	{
		if (a[i] == ' ' || a[i] == '\0')
		{
			break;
		}
		else
		{
			counter++;
			i++;
		}

	}
	return counter + 1;
}

int row_for_string(char* a, char letter) //����� 1- ������� ������ �����
{
	int i = 0;
	int counter = 0;
	while (a[i] != '\0')
	{
		if (tolower(a[i]) == letter || toupper(a[i]) == letter && i == 0)
		{
			counter++;
			while (a[i] != ' ')
			{
				i++;
			}
		}
		else if (tolower(a[i]) == letter || toupper(a[i]) == letter && a[i - 1] == ' ')
		{
			counter++;
			while (a[i] != ' ')
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}

	return counter;
}


void release_matrix(char** matrix, int row)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		free(matrix[i]);
	}
}

char** split(char* a, char letter, int* counter, int* r) //����� 1
{
	int row = 0, matrix_row = 0, matrix_colom = 0, colom = 0, i = 0, count = 0;
	row = row_for_string(a, letter);
	*r = row;
	*counter = colom;
	char** matrix = (char**)malloc(row * sizeof(char*));
	bool openingOfWord = true;
	while (a[i] != '\0')
	{
		if (a[i - 1] == ' ')
			openingOfWord = true;
		if ((letter == tolower(a[i]) || letter == toupper(a[i])) && openingOfWord == true)
		{
			colom = colom_for_string(a, i);
			if (colom > * counter) // ����� �� ���� ����� 
			{
				*counter = colom;
			}
			matrix[matrix_row] = (char*)calloc(colom, sizeof(char));
			while (a[i] != ' ' && a[i] != '\0')
			{
				matrix[matrix_row][matrix_colom] = a[i];
				matrix_colom++;
				i++;
				if (a[i] == ' ')
				{
					matrix[matrix_row][matrix_colom] = '\0';

				}

			}
			openingOfWord = true;
			matrix_row++;
			if (matrix_row == row)
			{
				break;
			}
			else
			{
				matrix_colom = 0;
			}

		}
		else
		{
			openingOfWord = false;
			i++;
		}
	}
	return matrix;
}

void decode(char* a) //����� 4
{
	int i = 0, decoder = 1;
	int size = strlen(a);

	while (size > 0)
	{
		if (a[i] == ' ')
		{
			decoder = 1;
			i++;
			size--;
			continue;

		}
		else
		{
			a[i] = a[i] - decoder;
			i++;
			size--;
			decoder++;
		}
	}
}

int countDeclarations(char* declaration) // ����� 5-��� ������ ��
{
	int count = 0, i = 0;
	while (declaration[i] != ';')
	{
		if (declaration[i] == ',')
		{
			count++;
			i++;
		}
		else
		{
			i++;
		}
	}

	return count + 1;
}


void printing_file(FILE* f, char* filename) // ����� 5
{
	f = fopen(filename, "r");
	int ch = 0;
	while (ch != EOF)
	{
		ch = fgetc(f);
		printf("%c", ch);
	}
}

int caculate_array(char* a, int index)
{
	int i = 0, count = 1, sum = 0, size = 0;
	while (a[index] != '\0')
	{
		index++;
		size++;
	}
	while (size > 0)
	{
		sum = sum + (a[index - 1] - 48) * count;
		count = count * 10;
		size--;
		index--;
	}
	return sum;
}

char* casting_from_int_to_string(int sum) // ����� 5 ���� �� ����� �� ���� ������� 
{
	int i = 0, j = 0;
	char cast = 0;
	char* castting = (char*)calloc(10, sizeof(char));
	char* reverse = (char*)calloc(10, sizeof(char));
	while (sum > 0)
	{
		cast = (sum % 10) + 48;
		castting[i] = cast;
		sum = sum / 10;
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		reverse[j] = castting[i];
		i--;
		j++;
	}
	return reverse;
}

int checkType(char* declaration, int* index) // ����� 5-���� ����� �� ������(������
{
	int type = 0, i = 0, j = 5, size = 4;
	if (declaration[0] == 'c') // char = 1
	{
		type = 1;
		*index = 5;
	}
	else if (declaration[0] == 'i') // int = 2
	{
		type = 2;
		*index = 4;

	}
	else if (declaration[0] == 'd') // double = 3
	{
		type = 3;
		*index = 7;

	}
	else if (declaration[0] == 'f') // float = 4
	{
		type = 4;
		*index = 6;

	}
	else if (declaration[0] == 's') // short = 5
	{
		type = 5;
		*index = 6;

	}
	else if (declaration[0] == 'l') // long = 6
	{
		while (size > 0)
		{
			if (declaration[i] != declaration[j])
			{
				break;
			}
			else
			{
				size--;
				j++;
				i++;
			}
		}
		if (size == 0)
		{
			type = 7;
			*index = 9;
		}
		else
		{
			type = 6;
			*index = 4;
		}
	}
	return type;
}

void memoryReport(char* declaration, char* filename) // ����� 5
{
	int i, j = 0, row, collom = 0, type, size, arr_num = 0, matrix_row = 0, bytesSum = 0;
	char* lineToFile = (char*)malloc(SIZE * sizeof(char));
	char converting[40] = { 0 };
	size = strlen(declaration);
	row = countDeclarations(declaration);
	type = checkType(declaration, &i);
	char** matrix = (char**)malloc(row * sizeof(char*));
	strcat(converting, filename);
	strcat(converting, ".txt");
	FILE* f = fopen(converting, "w");
	for (matrix_row = 0; matrix_row < row; matrix_row++) // ������
		matrix[matrix_row] = (char*)malloc(20 * sizeof(char));
	while (declaration[i] != ';')
	{
		if (j == row)
			break;
		else if (declaration[i] == ' ')
			i++;
		else if (declaration[i] != ',')
		{
			matrix[j][collom] = declaration[i];
			i++;
			collom++;
			if (declaration[i] == ';')
			{
				matrix[j][collom] = '\0';
				collom = 0;
				j++;
			}
		}
		else
		{
			i++;
			matrix[j][collom] = '\0';
			collom = 0;
			j++;
		}
	}
	j = 0;
	for (i = 0; i < row; i++)
	{
		if (matrix[i][0] == '*') // ��������
		{
			if (type == 1)
			{
				bytesSum = sizeof(char*);
			}
			else if (type == 2)
			{
				bytesSum = sizeof(int*);
			}
			else if (type == 3)
			{
				bytesSum = sizeof(double*);
			}
			else if (type == 4)
			{
				bytesSum = sizeof(float*);
			}
			else if (type == 5)
			{
				bytesSum = sizeof(short*);
			}
			else if (type == 6)
			{
				bytesSum = sizeof(long*);
			}
			else
			{
				bytesSum = sizeof(long long*);
			}
			lineToFile = casting_from_int_to_string(bytesSum);
			strcat(matrix[i], " requires ");
			strcat(matrix[i], lineToFile);
			strcat(matrix[i], " bytes\n");
			fputs(matrix[i], f);
		}
		else
		{
			for (j = 0; matrix[i][j] != '\0'; j++)
			{
				if (matrix[i][j] == '[') // ������
				{
					j++;
					while (matrix[i][j] != ']')
					{
						lineToFile[arr_num] = matrix[i][j];
						j++;
						arr_num++;
					}
					bytesSum = caculate_array(lineToFile, 0);
					if (type == 1)
					{
						bytesSum = bytesSum * sizeof(char);
					}
					else if (type == 2)
					{
						bytesSum = bytesSum * sizeof(int);
					}
					else if (type == 3)
					{
						bytesSum = bytesSum * sizeof(double);
					}
					else if (type == 4)
					{
						bytesSum = bytesSum * sizeof(float);
					}
					else if (type == 5)
					{
						bytesSum = bytesSum * sizeof(short);
					}
					else if (type == 6)
					{
						bytesSum = bytesSum * sizeof(long);
					}
					else
					{
						bytesSum = bytesSum * sizeof(long long);
					}
					lineToFile = casting_from_int_to_string(bytesSum);
					strcat(matrix[i], " requires ");
					strcat(matrix[i], lineToFile);
					strcat(matrix[i], " bytes\n");
					fputs(matrix[i], f);
					break;
				}
				else // Other declarations:
				{
					if (matrix[i][j + 1] == '\0')
					{
						if (type == 1)
						{
							bytesSum = sizeof(char);
						}
						else if (type == 2)
						{
							bytesSum = sizeof(int);
						}
						else if (type == 3)
						{
							bytesSum = sizeof(double);
						}
						else if (type == 4)
						{
							bytesSum = sizeof(float);
						}
						else if (type == 5)
						{
							bytesSum = sizeof(short);
						}
						else if (type == 6)
						{
							bytesSum = sizeof(long);
						}
						else
						{
							bytesSum = sizeof(long long);
						}
						lineToFile = casting_from_int_to_string(bytesSum);
						strcat(matrix[i], " requires ");
						strcat(matrix[i], lineToFile);
						strcat(matrix[i], " bytes\n");
						fputs(matrix[i], f);
						break;
					}
					else
					{
						continue;
					}
				}
			}
		}
	}
	fclose(f);
	printing_file(f, converting);
}

/***************************MAIN************************************/
void Ex1() {
	char a[SIZE] = "Rony Goodman got a good mark";
	char letter = 'g';
	int counter = 0, i = 0, j = 0;
	int row = 0, colom = 0;
	char** ptr = split(a, letter, &counter, &row);

	for (i = 0; i < row; i++)
		printf("%s \n", ptr[i]);

	release_matrix(ptr, row);
}
void Ex2() {
	int i;
	char a[] = " 123 Students & 5 Lectures ";
	char* res = clearDigitsAndSpaces(a);
	puts(res);
	free(res);
}
void Ex3() {
	char* txt_name = (char*)malloc(sizeof(char));
	char ch;
	printf("Named the file\n");
	gets(txt_name);

	createFile(txt_name);
	char filename[] = "filename";
	ch = commonestLetter(filename);
	if (ch)
	{
		printf("The commonest letter is %c", ch);
	}
	else
	{
		printf("No letters in the file");
	}
	free(txt_name);
}

void Ex4() {

	char* a = (char*)malloc(sizeof(char));
	printf("enter line for decode\n");
	gets(a);
	decode(a);
	puts(a);
	free(a);
}

void Ex5() {
	char declaration[SIZE], filename[SIZE];
	rewind(stdin);
	printf("Enter the name for the report:\n");
	gets(filename);
	rewind(stdin);
	printf("Enter the declarations:\n");
	gets(declaration);
	memoryReport(declaration, filename);
}
int main()

{
	int select = 0, i, all_Ex_in_loop = 0;
	printf_s("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 5; i++)
				printf_s("Ex%d--->%d\n", i, i);
			printf_s("EXIT-->0\n");
			do {
				select = 0;
				printf_s("please select 0-5 : ");
				scanf_s("%d", &select);
			} while ((select < 0) || (select > 5));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}
