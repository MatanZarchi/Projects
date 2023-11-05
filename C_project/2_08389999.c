#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 100

// Matan Zarchi 208389999
//הוגש ביחידות


//EX1

int lengthOfWord_colom(char* str, int index) // Ex1 - counting the lentgh of each word
{
	int count = 0, i = index;

	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			break;
		}
		else
		{
			count++;
			i++;
		}

	}
	return count + 1;
}
int countWordsWithLetter_rows(char* str, char letter) //Ex1 - count how many words start with letter
{
	int i = 0;
	int count = 0;
	while (str[i] != '\0')
	{
		if ((tolower(str[i]) == letter || toupper(str[i]) == letter) && i == 0)// for the first word
		{
			count++;
			while (str[i] != ' ' && str[i] != '\0')
			{
				i++;
			}
		}
		else if ((tolower(str[i]) == letter || toupper(str[i]) == letter) && str[i - 1] == ' ') // after space
		{
			count++;
			while (str[i] != ' ' && str[i] != '\0')
			{
				i++;
			}
		}
		else
		{
			i++;
		}
	}

	return count;
}
void freeMatrix(char** matrix, int row)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		free(matrix[i]);
	}
}
char** split(char* str, char letter, int* count, int* r) 
{
	int matrix_row = 0, matrix_colom = 0, colom = 0, row, i = 0;
	bool startOfWord = true;
	row = countWordsWithLetter_rows(str, letter);
	*r = row;
	char** matrix = (char**)malloc(row * sizeof(char*));

	while (str[i] != '\0')
	{
		if (str[i - 1] == ' ')
			startOfWord = true;
		if ((letter == tolower(str[i]) || letter == toupper(str[i])) && startOfWord == true)
		{
			colom = lengthOfWord_colom(str, i);
			if (colom > * count) // counter is the size of the array by reference
			{
				*count = colom;
			}
			matrix[matrix_row] = (char*)calloc(colom, sizeof(char));
			while (str[i] != ' ' && str[i] != '\0')
			{
				matrix[matrix_row][matrix_colom] = str[i];
				matrix_colom++;
				i++;
				if (str[i] == ' ')
				{
					matrix[matrix_row][matrix_colom] = '\0';

				}
			}
			startOfWord = true;
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
			startOfWord = false;
			i++;
		}
	}
	return matrix;
}
/******************END OF EX1************************/

//EX2

int strRealSize(char *str) //remove the the spaces and numbers and return the size without them.
{
	int i = 0, count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			i++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
		}
		else
		{
			count++;
			i++;
		}
	}
	return count + 1;

}
char *clearDigitsAndSpaces(char *str) //Ex2
{
	int size, i = 0, j = 0;
	size = strRealSize(str);
	char *newString = (char*)malloc(size * sizeof(char));
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			i++;
		}
		else if (str[i] != ' ')
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				i++;
			}
			else
			{
				newString[j] = str[i];
				j++;
				i++;
			}
		}
		newString[j] = '\0';
	}
	return newString;

}
/******************END OF EX2************************/

//EX3

void createFile(char* str) 
{
	char converting[SIZE] = { 0 };
	char line[SIZE];
	strcat(converting, str);
	strcat(converting, ".txt");
	FILE* file = fopen(converting, "w+t");
	rewind(stdin);
	printf("Enter your line to the %s file\n", converting);
	gets(line);
	fputs(line, file);
	fclose(file);
}
char commonestLetter(char* filename) 
{
	createFile(filename);
	int bigger, flag = 0;
	int check = 0, i = 0;
	int monim[26] = { 0 };
	char big = 0;

	FILE* fileptr = fopen("filename.txt", "rt");

	while (check != EOF)
	{
		check = fgetc(fileptr);
		monim[tolower(check) - 'a']++;
		flag++;
	}
	if (flag == 1)
	{
		return big;
	}
	else
	{
		bigger = monim[0];

		for (i = 1; i < 26; i++)
		{
			if (monim[i] > bigger)
			{
				bigger = monim[i];
				big = i;
			}
			else if (bigger == monim[i])
			{
				bigger = monim[i];
				big = i;

			}
			else
			{
				continue;
			}
		}

		return 	toupper(big + 'a');
	}
}
/******************END OF EX3************************/

//EX4

char* decode(char* str)//makes decode, for example: "bc8 d", will change with "aa5 c".
{
	int i = 0, j, size = 0;
	while (str[i] != '\0')
	{
		size++;
		i++;
	}
	char* strTemp = (char*)malloc(size * sizeof(char));
	i = j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			strTemp[j] = ' ';
		}
		else
		{
			if (str[i - 1] == ' ')
			{
				strTemp[j] = str[i] - 1;
			}
			else
			{
				strTemp[j] = str[i] - (i + 1);
			}
		}
		i++; j++;
	}
	strTemp[j] = '\0';
	return strTemp;
}
/******************END OF EX4************************/

//EX5

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
int countDeclarations(char* declaration) //Checks how many declarations are there
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
void printing_file(FILE* f, char* filename)
{
	f = fopen(filename, "r");
	int ch = 0;
	while (ch != EOF)
	{
		ch = fgetc(f);
		printf("%c", ch);
	}
}
char* casting_from_int_to_string(int sum) //Makes a string number(bytes) required for a variable
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
int checkType(char* declaration, int* index) // Checks what types of variables are entered
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
void memoryReport(char* declaration, char* filename) 
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
	for (matrix_row = 0; matrix_row < row; matrix_row++) // Declarations (int i , double j ...):
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
		if (matrix[i][0] == '*') // Pointers:
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
				if (matrix[i][j] == '[') // Arrays:
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
/******************END OF EX5************************/

/***************************MAIN************************************/

void Ex1()
{
	char str[50];
	char letter;
	int  i = 0, j = 0, count = 0;
	int row = 0, colom = 0;
	rewind(stdin);
	printf("Please enter a string \n");
	gets(str);
	printf("Please enter a letter\n");
	letter = getchar();
	char** ptr = split(str, letter, &count, &row);
	printf("The output is:\n");
	for (i = 0; i < row; i++)
	{
		printf("%s \n", ptr[i]);
	}
	printf("Size of array is: %d", count);
	freeMatrix(ptr, row);
}

void Ex2()
{
	char str[50];
	rewind(stdin);
	printf("Please enter a string \n");
	gets(str);
	char* newString = clearDigitsAndSpaces(str);//
	puts(newString);
	free(newString);
}

void Ex3()
{

	char* txt_name = (char*)malloc(sizeof(char));
	char ch;
	rewind(stdin);
	printf("Named the file\n");
	gets(txt_name);
	createFile(txt_name);
	//rewind(stdin);
	char filename[] = "filename";
	ch = commonestLetter(filename);
	if (ch)
	{
		printf("The commonest letter is %c\n", ch);
	}
	else
	{
		printf("No letters in the file");
	}
}

void Ex4()
{
	char str[SIZE];
	int i = 0;
	printf("Please put any string: \n");
	gets(str);
	char* strTemp = decode(str);
	puts(strTemp);
	//free(strTemp);
}

void Ex5()
{
	char declaration[SIZE], filename[SIZE];
	rewind(stdin);
	printf("Enter the name for the report:\n");
	gets(filename);
	rewind(stdin);
	printf("Enter the declarations:\n");
	gets(declaration);
	memoryReport(declaration, filename);
}

void Ex6()
{
	printf("En od milvado\n");
}

void Ex7()
{
	printf("En od milvado\n");
}

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 7; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-7 : ");
				scanf("%d", &select);
			} while ((select < 0) || (select > 7));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;
			case 6: Ex6(); break;
			case 7: Ex7(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}


