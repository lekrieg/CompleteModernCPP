#include "DynamicMemoryAlocationPart1.h"

namespace DynamicMemoryAlocation
{
	void MallocExample()
	{
		std::cout << "Malloc example called" << '\n';
		int* p = (int*)malloc(sizeof(int));
		*p = 5;
		std::cout << *p << '\n';

		delete p;
	}

	void CallocExample()
	{
		std::cout << "Calloc example called" << '\n';

		size_t size = 3;
		int* p = (int*)calloc(size, sizeof(int));
		*p = 5;
		*(p + 1) = 3;
		*(p + 2) = 9;

		for (size_t i = 0; i < size; i++)
		{
			std::cout << *(p + i) << ' ';
		}

		std::cout << '\n';

		delete[] p;
	}

	void DynamicMemoryAlocation::NewExample()
	{
		std::cout << "New example called" << '\n';

		int* p = new int{ 5 };
		/*int *p = new int;
		*p = 5;*/

		std::cout << "Valor: " << *p << '\n' << "Endereco: " << p << '\n';

		delete p;
		//p = nullptr;
	}

	void DynamicMemoryAlocation::NewArrayExample()
	{
		std::cout << "New[] and new[][] example called" << '\n';

		size_t size = 3;
		int* p = new int[size] { 5, 3, 9 };
		/**p = 5;
		*(p + 1) = 3;
		*(p + 2) = 9;*/

		for (size_t i = 0; i < size; i++)
		{
			std::cout << *(p + i) << ' ';
		}

		std::cout << "\n\n";

		delete[] p;

		//int (*p)[3] = new int[3][3];
		int** p2 = new int* [3]
		{
			new int[3] { 1, 3, 5 },
				new int[3] { 9, 7, 15 },
				new int[3] { 99, 2, 4 }
		};

		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				std::cout << p2[i][j] << ' ';
			}
			std::cout << '\n';
		}

		std::cout << '\n';

		for (size_t i = 0; i < size; i++)
		{
			delete[] p2[i];
		}
		delete[] p2;
	}
}