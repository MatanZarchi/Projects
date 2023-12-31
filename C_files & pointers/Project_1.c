#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define _CRT_SECURE_NO_WARNINGS


typedef struct ArrayData { //OF EX3
	int value, i, j;
}ArrayData;

typedef struct Node { //OF EX3
	struct Node* next;
	ArrayData key;
}node;

typedef struct intNode { //OF EX4
	struct intNode* next;
	int key;
}intnode;

typedef struct charNode { //OF EX6 && EX7
	struct charNode* next;
	char key;
}charnode;

//Functions:
void printArr(int*, int);//Of Arrays
int* powerArray(int);//Of EX1
void printMat(int*, int);
void freeMat(int**, int);
void neighborMaxMin(int**, int, int, int, int, int*, int*);//Of EX2
ArrayData* createThreeArr(int**, int, int, int*);//Of EX3
ArrayData createThree(int, int, int);//Of EX3
node* createThreeList(int**, int, int);//Of EX3
node* Insert(node*, int);
intnode* getnewnode1(int data);
node* getnewnode(ArrayData);
charnode* getnewnode2(char);
void freeList(node*);
void printlist(node*);
intnode* createList(intnode**);
intnode* createList2(intnode**);
void removeDupArrayLists(charnode**, int);
charnode* disassemblyList(charnode*);
void printArr(int* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}
void printArrayData(ArrayData* head)
{
	printf("data: %d, i: %d,j: %d\n", head->value, head->i, head->j);
}
void printArrayDataArr(ArrayData* arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printArrayData(&arr[i]);
	printf("\n");
}
void printMat(int* mat, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%8d", mat[i]);
	}
	printf("\n");
}
void freeMat(int** mat, int rows)
{
	int i;
	for (i = 0; i < rows; i++)
	{
		free(mat[i]);
	}
	free(mat);
}
node* Insert(node* head, ArrayData data)//����� ���� ������
{
	node* newnode = getnewnode(data);//creat a new node-> getting a new node with the data
	node* temp = head;
	if (head == NULL)
	{
		head = newnode;//now head points to new node
	}
	else// we would want to find a node that his next is null-> so that's the end of list and there we want to put the new node
	{
		while (temp->next != NULL)
		{
			temp = temp->next;//traversion
		}
		//end of loop means we reached a node which next=null => end of list!
		temp->next = newnode;
		newnode->next = NULL;
	}
	return head;
}
intnode* Insert1(intnode* head, int data)//����� ���� ������
{
	intnode* newnode = getnewnode1(data);//creat a new node-> getting a new node with the data
	intnode* temp = head;
	if (head == NULL)
	{
		head = newnode;//now head points to new node
	}
	else// we would want to find a node that his next is null-> so that's the end of list and there we want to put the new node
	{
		while (temp->next != NULL)
		{
			temp = temp->next;//traversion
		}
		//end of loop means we reached a node which next=null => end of list!
		temp->next = newnode;
		newnode->next = NULL;
	}
	return head;
}
charnode* Insert2(charnode* head, char data)//����� ���� ������
{
	charnode* newnode = getnewnode2(data);//creat a new node-> getting a new node with the data
	charnode* temp = head;
	if (head == NULL)
	{
		head = newnode;//now head points to new node
	}
	else// we would want to find a node that his next is null-> so that's the end of list and there we want to put the new node
	{
		while (temp->next != NULL)
		{
			temp = temp->next;//traversion
		}
		//end of loop means we reached a node which next=null => end of list!
		temp->next = newnode;
		newnode->next = NULL;
	}
	return head;
}
intnode* getnewnode1(int data)//creating a new node
{
	intnode* temp = (intnode*)malloc(sizeof(intnode));//dynamic array of size 1 of node
	temp->key = data;
	temp->next = NULL;//we dont not yet where to points
	return temp;
}
charnode* getnewnode2(char data)//creating a new node
{
	charnode* temp = (charnode*)malloc(sizeof(charnode));//dynamic array of size 1 of node
	temp->key = data;
	temp->next = NULL;//we dont not yet where to points
	return temp;
}
node* getnewnode(ArrayData data)//creating a new node
{
	node* temp = (node*)malloc(sizeof(node));//dynamic array of size 1 of node
	temp->key = data;
	temp->next = NULL;//we dont not yet where to points
	return temp;
}
void freeList(node* list)
{
	node* deletenode;
	while (list != NULL)
	{
		deletenode = list;
		list = list->next;
		free(deletenode);
	}
}
void printlist(node* head)
{
	node* temp = head;
	if (head == NULL)//list is empty.
	{
		printf("list is Empty\n");
	}
	else
	{
		while (temp != NULL)//cause when temp==NULL that's the end of list
		{
			printArrayData(&temp->key);
			temp = temp->next;
		}
		printf("\n");
	}
}
intnode* Delete(intnode* head, intnode* previous, intnode* deleteNode)
{
	intnode* next = deleteNode->next;
	free(deleteNode);
	if (previous == NULL)
	{
		return next;
	}
	previous->next = next;

	return head;
}
void printlist1(intnode* head)
{
	intnode* temp = head;
	if (head == NULL)//list is empty.
	{
		printf("list is Empty\n");
	}
	else
	{
		while (temp != NULL)//cause when temp==NULL that's the end of list
		{
			printf("%d ", temp->key);
			temp = temp->next;
		}
		printf("\n");
	}
}
void printlist2(charnode* head)
{
	charnode* temp = head;
	if (head == NULL)//list is empty.
	{
		printf("list is Empty\n");
	}
	else
	{
		while (temp != NULL)//cause when temp==NULL that's the end of list
		{
			printf("%c ", temp->key);
			temp = temp->next;
		}
		printf("\n");
	}
}

//EX1

int* powerArray(int num)//return a 2 power x while x is  worth i
{
	int i, x = 1;
	int* arr = (int*)calloc(num, sizeof(int));
	assert(arr);
	arr[0] = 1;
	if (num == 0)
	{
		return 0;
	}

	for (i = 1; i < num; i++)
	{
		x = x << 1;
		arr[i] = x;
	}
	return arr;
}
///***************END OF EX1******************///

//EX2

int* matrixMaxNeighbor(int** matA, int rows, int cols)//return matB of max neighbors in matA
{
	int** matB;
	int i, j;
	matB = (int**)calloc(rows, sizeof(int*));
	for (i = 0; i < rows; i++)
	{
		matB[i] = (int*)calloc(cols, sizeof(int));
	}
	int max = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (0 <= i - 1 && i - 1 <= rows - 1)
			{
				max = matA[i - 1][j];
			}
			if (0 <= i + 1 && i + 1 <= rows - 1)
			{
				max <= matA[i + 1][j] ? max = matA[i + 1][j] : max;
			}
			if (0 <= j - 1 && j - 1 <= cols - 1)
			{
				max <= matA[i][j - 1] ? max = matA[i][j - 1] : max;
			}
			if (0 <= j + 1 && j + 1 <= cols - 1)
			{
				max <= matA[i][j + 1] ? max = matA[i][j + 1] : max;
			}
			matB[i][j] = max;
			max = 0;
		}
	}
	return matB;

}
void neighborMaxMin(int** matA, int rows, int cols, int I, int J, int* min, int* max)//return max neighbor of a[i][j]
{

	if (0 <= I - 1 && I - 1 <= rows - 1)
	{
		*max = matA[I - 1][J];
		*min = *max;
	}
	if (0 <= I + 1 && I + 1 <= rows - 1)
	{
		if (*max < matA[I + 1][J]) {
			*max = matA[I + 1][J];
		}
		if (*min > matA[I + 1][J]) {
			*min = matA[I + 1][J];
		}
	}
	if (0 <= J - 1 && J - 1 <= cols - 1)
	{
		if (*max <= matA[I][J - 1]) {
			*max = matA[I][J - 1];
		}
		if (*min > matA[I][J - 1])
		{
			*min = matA[I][J - 1];
		}
	}
	if (0 <= J + 1 && J + 1 <= cols - 1)
	{
		if (*max < matA[I][J + 1]) {
			*max = matA[I][J + 1];
		}
		if (*min > matA[I][J + 1]) {
			*min = matA[I][J + 1];
		}
	}
}
///***************END OF EX2******************///


//EX3

/*
Builds a one-dimensional dynamic array of threes according
each of the matrix members whose value is less than or equal
to all its neighbors
*/

int createArrayAndList(int** mat, int rows, int cols, ArrayData** arr, node** list)
{
	int count;
	*arr = createThreeArr(mat, rows, cols, &count);
	return count;
}
ArrayData createThree(int value, int i, int j)
{
	ArrayData arrayData = { value,i,j };
	return arrayData;
}
node* createThreeList(int** mat, int rows, int cols)
{
	node* list = NULL;
	int i, j, min, max;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			neighborMaxMin(mat, rows, cols, i, j, &min, &max);
			if (mat[i][j] <= min) {
				list = Insert(list, createThree(mat[i][j], i, j));
			}
		}
		return list;
	}
}
ArrayData* createThreeArr(int** mat, int rows, int cols, int* count)
{
	ArrayData* arr;
	int i, j, min, max, index = 0;
	*count = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			neighborMaxMin(mat, rows, cols, i, j, &min, &max);
			if (mat[i][j] <= min) {
				(*count)++;
			}
		}
	}
	arr = (ArrayData*)malloc((*count) * sizeof(ArrayData));
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			neighborMaxMin(mat, rows, cols, i, j, &min, &max);
			if (mat[i][j] <= min) {
				arr[index++] = createThree(mat[i][j], i, j);
			}
		}
	}
	return arr;
}
///***************END OF EX3******************///

//EX4

intnode* createList(intnode** list)// search numbers which bigger than following and next and put them into newlist
{
	intnode* newlist = NULL, * temp = *list;
	intnode* previous = NULL;
	int prev_number = -1;

	intnode* next = NULL;
	if ((*list)->next == NULL)
	{
		newlist = Insert1(newlist, temp->key);
		*list = Delete(*list, NULL, *list);
		return newlist;
	}
	while (temp->next != NULL)
	{
		if (temp->key > temp->next->key)
		{
			if (previous == NULL)
			{
				newlist = Insert1(newlist, temp->key);
			}
			else
			{
				if (previous->key < temp->key)
					newlist = Insert1(newlist, temp->key);

			}
		}
		previous = temp;
		temp = temp->next;
	}
	if (previous->key < temp->key)
		newlist = Insert1(newlist, temp->key);

	temp = *list;
	previous = NULL;
	while (temp->next != NULL)
	{
		next = temp->next;

		if (temp->key > temp->next->key)
		{
			if (prev_number == -1)
			{
				prev_number = temp->key;
				*list = Delete(*list, previous, temp);
				temp = NULL;
			}
			else
			{
				if (prev_number < temp->key)
				{
					prev_number = temp->key;
					*list = Delete(*list, previous, temp);
					temp = NULL;
				}
				else
				{
					prev_number = temp->key;
					previous = temp;
				}
			}
		}
		else
		{
			previous = temp;
		}
		temp = next;
	}
	if (prev_number > temp->key)
		*list = Delete(*list, previous, temp);

	return newlist;
}
///***************END OF EX4******************///

//EX5
intnode* createList2(intnode** list)//Same as EX4 but without allocation or free
{
	intnode* newlist = NULL, * temp = *list;
	intnode* previous = NULL;
	intnode* newListTemp = NULL;
	if ((*list)->next == NULL)
	{
		newlist = *list;
		*list = NULL;
		return newlist;
	}
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->key > temp->next->key)
		{
			if (previous == NULL)
			{
				newlist = *list;
				*list = (*list)->next;
				newlist->next = NULL;
				newListTemp = newlist;
				newListTemp->next = NULL;
			}
			else
			{
				if (previous->key < temp->key)
				{
					previous->next = temp->next;
				}
			}
		}
		previous = temp;
		temp = temp->next;
	}
	if (temp != NULL && previous->key < temp->key)
	{
		newListTemp = temp;
		newlist = temp;
		previous->next = NULL;
		newListTemp = newListTemp->next;
		newListTemp = NULL;
	}
	else if (temp != NULL && previous->key > temp->key)
	{
		newlist = previous;
		previous = NULL;
		temp->next = NULL;
		newlist->next = NULL;
	}

	return newlist;
}

///***************END OF EX5******************///

//EX6

void removeDupArrayLists(charnode** arr, int size)//Remove duplicates from arraylist
{
	charnode* temp = NULL, * first = NULL, * previous = NULL, * next;
	int i;

	for (i = 0; i < size; i++) {
		first = arr[i];
		while (first != NULL)
		{
			temp = first->next;
			previous = first;
			while (temp != NULL)
			{
				if (first->key == temp->key)
				{
					next = temp->next;
					arr[i] = (charnode*)Delete((charnode*)arr[i], (charnode*)previous, (charnode*)temp);
					temp = next;
				}
				else
				{
					previous = temp;
					temp = temp->next;
				}
			}
			first = first->next;
		}
	}
}

///***************END OF EX6******************///

//EX7

charnode* disassemblyList(charnode* list, charnode** UppercaseList, charnode** SmallCapsList, charnode** NumberList, charnode* OtherList)//Divide mix char list to a new 4 lists by their types
{
	*UppercaseList = NULL, * SmallCapsList = NULL, * NumberList = NULL, OtherList = NULL;
	charnode* temp = list;
	charnode* tempnext;
	if (list->next == NULL)
	{
		if ('a' <= list->key && list->key <= 'z')
		{
			*SmallCapsList = list;
		}
		if ('A' <= list->key && list->key <= 'Z')
		{
			*UppercaseList = list;
		}
		if ('0' <= list->key && list->key <= '9')
		{
			*NumberList = list;
		}
		else OtherList = list;
	}
	while (temp != NULL && temp->next != NULL)
	{
		if (temp->key >= 'a' && temp->key <= 'z')
		{

			if (*SmallCapsList == NULL)
			{
				tempnext = temp->next;

				temp->next = NULL;
				*SmallCapsList = temp;
				temp = tempnext;
			}
			else
			{
				tempnext = temp->next;

				temp->next = *SmallCapsList;
				*SmallCapsList = temp;
				temp = tempnext;
			}
		}
		if (temp->key >= 'A' && temp->key <= 'Z')
		{

			if (*UppercaseList == NULL)
			{
				tempnext = temp->next;

				temp->next = NULL;
				*UppercaseList = temp;
				temp = tempnext;
			}
			else
			{
				tempnext = temp->next;

				temp->next = *UppercaseList;
				*UppercaseList = temp;
				temp = tempnext;
			}
		}
		if (temp->key >= '0' && temp->key <= '9')
		{

			if (*NumberList == NULL)
			{
				tempnext = temp->next;

				temp->next = NULL;
				*NumberList = temp;
				temp = tempnext;
			}
			else
			{
				tempnext = temp->next;

				temp->next = *NumberList;
				*NumberList = temp;
				temp = tempnext;
			}
		}
		if (temp->key >= 33 && temp->key <= 47 || temp->key >= 91 && temp->key <= 96 || temp->key >= 123 && temp->key <= 126 || temp->key >= 192 && temp->key <= 201)
		{

			if (OtherList == NULL)
			{
				tempnext = temp->next;
				temp->next = NULL;
				OtherList = temp;
				temp = tempnext;
			}
			else
			{
				tempnext = temp->next;

				temp->next = OtherList;
				OtherList = temp;
				temp = tempnext;
			}
		}
		else
		{
			temp = temp->next;
		}
	}
	return OtherList;
}
///***************END OF EX7******************///


// Function declarations 

void Ex1()
{
	int n;
	printf("Please enter array length: \n");
	scanf_s("%d", &n);
	unsigned int* arr = powerArray(n);
	printArr(arr, n);
	free(arr);
}

void Ex2()
{
	int** matA, ** matB;
	int max = 0, min = 0;
	int i, j, rows, cols, I = 0, J = 0;
	printf("enter number of rows\n");
	scanf_s("%d", &rows);
	printf("enter number of cols\n");
	scanf_s("%d", &cols);
	matA = (int**)calloc(rows, sizeof(int*));
	for (i = 0; i < rows; i++)
	{
		matA[i] = (int*)calloc(cols, sizeof(int));
	}
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			matA[i][j] = rand() % 5;
		}

	}
	printf("A matrix is:\n");
	for (i = 0; i < rows; i++)
	{
		printMat(matA[i], cols);
	}
	matB = matrixMaxNeighbor(matA, rows, cols);
	printf("B matrix is:\n");
	for (i = 0; i < rows; i++)
	{
		printMat(matB[i], cols);
	}
	printf("enter I less than %d\n", rows);
	scanf_s("%d", &I);
	printf("enter J less than %d\n", cols);
	scanf_s("%d", &J);
	neighborMaxMin(matA, rows, cols, I, J, &min, &max);
	printf("The min neighbor at matA[%d][%d] is: %d\n", I, J, min);
	printf("The max neighbor at matA[%d][%d] is: %d\n", I, J, max);
	freeMat(matA, rows);
	freeMat(matB, rows);
}

void Ex3()
{
	ArrayData* arr;
	node* list = NULL;
	int** mat;
	int max = 0, min = 0, count = 0;
	int i, j, rows, cols, I = 0, J = 0;
	printf("enter number of rows\n");
	scanf_s("%d", &rows);
	printf("enter number of cols\n");
	scanf_s("%d", &cols);
	mat = (int**)calloc(rows, sizeof(int*));
	for (i = 0; i < rows; i++)
	{
		mat[i] = (int*)calloc(cols, sizeof(int));
	}
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			mat[i][j] = rand() % 5;
		}

	}
	printf("A matrix is:\n");
	for (i = 0; i < rows; i++)
	{
		printMat(mat[i], cols);
	}

	count = createArrayAndList(mat, rows, cols, &arr, &list);
	printf("array:\n");
	printArrayDataArr(arr, count);
	//freeMat(mat, rows);
}

void Ex4()
{
	intnode* list, * newlist;
	int input;
	list = NULL;
	printf("please enter elements, to stop enter -1:\n");
	scanf_s("%d", &input);
	while (input != -1)
	{
		list = Insert1(list, input);
		printf("please enter elements, to stop enter -1:\n");
		scanf_s("%d", &input);
	}
	if (list == NULL) { printf("\nlist is empty! try again!"); }
	else {
		newlist = createList(&list);
		printf("The list after removed items:\n");
		printlist1(list);
		printf("The list of removed items:\n");
		printlist1(newlist);
		freeList(list);
		freeList(newlist);
	}
}

void Ex5()
{
	intnode* list, * newlist;
	int input;
	list = NULL;
	printf("please enter elements, to stop enter -1:\n");
	scanf_s("%d", &input);
	while (input != -1)
	{
		list = Insert1(list, input);
		printf("please enter elements, to stop enter -1:\n");
		scanf_s("%d", &input);
	}
	if (list == NULL) { printf("\nlist is empty! try again!"); }
	else {
		newlist = createList2(&list);
		printf("The list after removed items:\n");
		printlist1(list);
		printf("The list of removed items:\n");
		printlist1(newlist);
		freeList(list);
		freeList(newlist);
	}
}

void Ex6()
{
	charnode** arr;
	int size;
	int i;
	char c;
	printf("Enter a size of arrayList:\n");
	scanf_s("%d", &size);
	getchar();
	arr = (charnode**)malloc(size * sizeof(charnode*));
	for (i = 0; i < size; i++)
	{
		arr[i] = NULL;
	}
	printf("Enter elements of arrayList:\n");
	for (i = 0; i < size; i++)
	{
		printf("enter characters of %d\n", i + 1);
		c = getchar();
		while (c != '\n') {
			if (c != ' ')
				arr[i] = Insert2(arr[i], c);
			c = getchar();
		}
	}
	printf("\nThe ArrayList you inserted is:\n");
	for (i = 0; i < size; i++)
	{
		printf("list number %d:\n", i + 1);
		printlist2(arr[i]);
	}
	removeDupArrayLists(arr, size);
	printf("\nAfter function ArrayList is:\n");
	for (i = 0; i < size; i++)
	{
		printf("list number %d:\n", i + 1);
		printlist2(arr[i]);
	}
	free(arr);
}

void Ex7()
{
	charnode** UppercaseList = NULL, ** SmallCapsList = NULL, ** NumberList = NULL, * OtherList = NULL, * list = NULL;
	char input;
	printf("Enter any elements to stop press ENTER:\n");
	input = getchar();
	while (input != '\n')
	{
		list = Insert2(list, input);
		input = getchar();
	}
	if (list == NULL)
	{
		printf("list is empty!");
	}
	else {
		OtherList = disassemblyList(list, &UppercaseList, &SmallCapsList, &NumberList, OtherList);
		printf("Small letter list:\n");
		printlist2(SmallCapsList);
		printf("Big letter list:\n");
		printlist2(UppercaseList);
		printf("numbers list:\n");
		printlist2(NumberList);
		printf("Other list:\n");
		printlist2(OtherList);
	}

}

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf_s("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= 7; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-7 : ");
				scanf_s("%d", &select);
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











