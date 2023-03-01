#include "DynamicMemoryAlocationPart1.h"

#include <stdio.h>
#include <stdlib.h>

void MallocExample()
{
	// doesn't initialize the memory
	int *pTmp = (int*)malloc(sizeof(int));
	// int *pTmp = (int*)malloc(5 * sizeof(int));
	if (pTmp == NULL)
	{
		printf("Failed to allocate memory!\n");
		return;
	}

	*pTmp = 5;
	printf("%d\n", *pTmp);
	free(pTmp);
	pTmp = NULL;
}

void CallocExample()
{
	// It initialize the memory to a default value
	int* pTmp = (int*)calloc(1, sizeof(int));
	if (pTmp == NULL)
	{
		printf("Failed to allocate memory!\n");
		return;
	}

	*pTmp = 99;
	printf("%d\n", *pTmp);
	free(pTmp);
	pTmp = NULL;
}

void ReallocExample()
{
	int* pTmp = (int*)calloc(1, 5 * sizeof(int));
	if (pTmp == NULL)
	{
		printf("Failed to allocate memory!\n");
		return;
	}

	printf("%I64u\n", sizeof(pTmp));

	pTmp = (int*)realloc(pTmp, 10 * sizeof(int));
	if (pTmp == NULL)
	{
		printf("Failed to allocate memory!\n");
		return;
	}

	printf("%I64u\n", sizeof(pTmp));

	free(pTmp);
	pTmp = NULL;
}