#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int *data;
	int maxSize;
	int length;
} SeqList;

void Init(SeqList *L)
{
	L->data = (int *)malloc(sizeof(int));
	L->maxSize = 1;
	L->length = 0;
}

int IsEmpty(SeqList *L)
{
	return L->length == 0;
}

void Resize(SeqList *L, int newSize)
{
	int *temp = L->data;

	L->data = (int *)malloc(newSize*sizeof(int));
	for (int i = 0; i < L->length; i++)
		L->data[i] = temp[i];
	L->maxSize = newSize;
	free(temp);
}

int Insert(SeqList *L, int index, int value)
{
	if (index < 1 || index > L->length+1)
		return -1;
	
	if (L->length == L->maxSize)
		Resize(L, 2*L->maxSize);

	for (int i = L->length; i >= index; i--)
		 L->data[i] = L->data[i-1];
	L->data[index-1] = value;
	L->length++;

	return 0;
}

int Delete(SeqList *L, int index, int *value)
{
	if (index < 1 || index > L->length)
		return -1;
	
	if (L->length == L->maxSize/4)
		Resize(L, L->maxSize/2);
	
	for (int i = index; i < L->length; i++)
		L->data[i-1] = L->data[i];
	*value = L->data[index-1];
	L->length--;

	return 0;
}

int LenOfList(SeqList *L)
{
	return L->length;
}

void Show(SeqList *L)
{
	printf("List:");
	for (int i = 0 ; i < L->length; i++)
		printf(" %d", L->data[i]);
}

int QueryWithIndex(SeqList *L, int index)
{
	if (index < 1 || index > L->length)
		return -1;
	return L->data[index-1];
}

int QueryWithValue(SeqList *L, int value)
{
	for (int i = 0; i < L->length; i++)
		if (L->data[i] == value)
			return i+1;
	return -1;
}

void Destory(SeqList *L)
{
	free(L->data);
	L->maxSize = 0;
	L->length = 0;
}

int main()
{
	SeqList L;
	int value;
	int index;
	int ret;
	
	Init(&L);
	ret = IsEmpty(&L);
	if (ret)
		printf("Init succeed, list is empty\n");
	else
		printf("Init failed, list is not empty\n");

	for (int i = 0; i < 10; i++)
		Insert(&L, i, 10 - i);
	Show(&L);
	printf(", Length = %d\n", LenOfList(&L));
	

	index = 2;
	value = 2;
	ret = Insert(&L, index, value);
	if (ret)
		printf("Insert failed, error code = %d\n", ret);
	else
		printf("Insert succeed, insert value = %d\n", value);
	Show(&L);
	printf(", Length = %d\n", LenOfList(&L));

	index = 2;
	value = 0;
	ret = Delete(&L, index, &value);
	if (ret)
		printf("Delete failed, error code = %d\n", ret);
	else
		printf("Delete succeed, delete value = %d\n", value);
	Show(&L);
	printf(", Length = %d\n", LenOfList(&L));

	index = 7;
	value = QueryWithIndex(&L, index);
	if (value == -1)
		printf("QueryWithIndex failed, illegal index\n");
	else
		printf("QueryWithIndex %d succeed, value = %d\n", index, value);
	
	value = 8;
	index = QueryWithValue(&L, value);
	if (index == -1)
		printf("QueryWithValue failed, not found\n");
	else
		printf("QueryWithValue %d succeed, index = %d\n", value, index);

	Destory(&L);
	if(L.length == 0)
		printf("Destory succeed\n");

	return 0;
}








