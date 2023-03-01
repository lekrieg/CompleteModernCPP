#include "BasicLanguageFacilities.h"

#include <iostream>
#include <climits>
#include <cfloat>
#include <cstdint>
#include <string>

namespace BLF
{
	void BasicLanguageFacilities::PrintBasicTypesInfo() const
	{
		// Value initialization => type obj{};
		// Direct initialization => type obj{v};
		// Copy initialization => type obj = v;
		// Copy initialization should be avoided with user defined objects
		// 
		// Uniform initialization have some advantages
		// 1 - It forces initialization
		// 2 - You can use direct initialization for array types
		// 3 - It prevents narrowing conversions
		// 4 - Uniform syntax for all types

		char maxCharValue{ CHAR_MAX };
		unsigned char maxUnsignedCharValue{ UCHAR_MAX };
		int maxIntValue{ INT_MAX };
		unsigned maxUnsignedIntValue{ UINT_MAX };
		signed maxSignedIntValue{ INT_MAX };
		short maxShortIntValue{ SHRT_MAX };
		unsigned short maxUnsignedShortIntValue{ USHRT_MAX };
		signed short maxSignedShortIntValue{ SHRT_MAX };
		long maxLongIntValue{ LONG_MAX };
		unsigned long maxUnsignedLongIntValue{ ULONG_MAX };
		long long maxLongLongIntValue{ LLONG_MAX };
		unsigned long long maxUnsignedLongLongIntValue{ ULLONG_MAX };
		float maxFloatValue{ FLT_MAX };
		double maxDoubleValue{ DBL_MAX };
		long double maxLongDoubleValue{ LDBL_MAX };
		wchar_t maxWchar_tValue{ WCHAR_MAX };

		std::cout << "Max char value: " << static_cast<int>(maxCharValue) << "\tSize: " << sizeof(maxCharValue) << '\n';
		std::cout << "Max unsigned char value: " << static_cast<int>(maxUnsignedCharValue) << "\tSize: " << sizeof(maxUnsignedCharValue) << '\n';
		std::cout << "Max int value: " << maxIntValue << "\tSize: " << sizeof(maxIntValue) << '\n';
		std::cout << "Max unsigned int value: " << maxUnsignedIntValue << "\tSize: " << sizeof(maxUnsignedIntValue) << '\n';
		std::cout << "Max signed int value: " << maxSignedIntValue << "\tSize: " << sizeof(maxSignedIntValue) << '\n';
		std::cout << "Max short int value: " << maxShortIntValue << "\tSize: " << sizeof(maxShortIntValue) << '\n';
		std::cout << "Max unsigned short int value: " << maxUnsignedShortIntValue << "\tSize: " << sizeof(maxUnsignedShortIntValue) << '\n';
		std::cout << "Max signed short int value: " << maxSignedShortIntValue << "\tSize: " << sizeof(maxSignedShortIntValue) << '\n';
		std::cout << "Max long int value: " << maxLongIntValue << "\tSize: " << sizeof(maxLongIntValue) << '\n';
		std::cout << "Max unsigned long int value: " << maxUnsignedLongIntValue << "\tSize: " << sizeof(maxUnsignedLongIntValue) << '\n';
		std::cout << "Max long long int value: " << maxLongLongIntValue << "\tSize: " << sizeof(maxLongLongIntValue) << '\n';
		std::cout << "Max unsigned long long int value: " << maxUnsignedLongLongIntValue << "\tSize: " << sizeof(maxUnsignedLongLongIntValue) << '\n';
		std::cout << "Max float value: " << maxFloatValue << "\tSize: " << sizeof(maxFloatValue) << '\n';
		std::cout << "Max double value: " << maxDoubleValue << "\tSize: " << sizeof(maxDoubleValue) << '\n';
		std::cout << "Max long double value: " << maxLongDoubleValue << "\tSize: " << sizeof(maxLongDoubleValue) << '\n';
		std::cout << "Max wchar_t value: " << maxWchar_tValue << "\tSize: " << sizeof(maxWchar_tValue) << '\n';
	}

	void BasicLanguageFacilities::GetUserInput()
	{
		int age;
		std::cout << "Your age: ";
		std::cin >> age;
		std::cin.get();
		std::string name;
		std::cout << "Your name: ";
		std::getline(std::cin, name);

		std::cout << "-- Entered info --" << '\n';
		std::cout << "Name: " << name << "\nAge: " << age << '\n';
	}

	void BasicLanguageFacilities::BasicPointerAndReferenceTest()
	{
		int x{ 55 }, y{ 6 };
		int* pX{ &x }, * pY{ &y };

		std::cout << "-- BEFORE SWAP --" << '\n';
		std::cout << "pX value: " << *pX << " Address: " << pX << '\n';
		std::cout << "pY value: " << *pY << " Address: " << pY << '\n';
		Swap(&x, &y);
		std::cout << "-- AFTER SWAP --" << '\n';
		std::cout << "pX value: " << *pX << " Address: " << pX << '\n';
		std::cout << "pY value: " << *pY << " Address: " << pY << '\n';

		Swap(x, y);
	}

	void BasicLanguageFacilities::PrintCircleInfo(const int& radius) const
	{
		std::cout << "Area of the circle: " << PI * radius * radius << '\n';
		std::cout << "Circunference of the circle: " << PI * 2 * radius << '\n';
	}

	void BasicLanguageFacilities::ConstPractice()
	{
		int x = 10;
		const int* pValue = &x;
		// This gives error because it's a pointer to a const integer, you can't modify the value wich the pointer points, just the address
		// *pValue = 5;

		const int CHUNK_SIZE = 512;
		const int* const pSize = &CHUNK_SIZE;
		// This gives error too because it's a const pointer to a const integer, you can't modify the pointer location and neither the value wich it points
		// pSize = &x;
		// *pSize = x;

		char testChar1 = 'a';
		char* const pChar = &testChar1;
		char testChar2 = 'y';
		*pChar = testChar2;
		// pChar = testChar2;
	}

	void BasicLanguageFacilities::Swap(int* x, int* y)
	{
		std::cout << "Swap method *" << '\n';

		int tmp = *x;
		*x = *y;
		*y = tmp;
	}

	void BasicLanguageFacilities::Swap(int& x, int& y)
	{
		std::cout << "Swap method &" << '\n';

		int tmp = x;
		x = y;
		y = tmp;
	}

	void BasicLanguageFacilities::ForLoopPratice() const
	{
		NormalForLoop();
		RangedBasedForLoop();
	}

	void BasicLanguageFacilities::NormalForLoop() const
	{
		std::cout << "-- Normal for loop --" << '\n';

		rsize_t range = 5;
		for (int i = 0; i < range; i++)
		{
			for (int j = 0; j < range; j++)
			{
				if ((i == j) || (i + j == range - 1))
				{
					std::cout << "*";
					continue;
				}
				std::cout << ' ';
			}
			std::cout << '\n';
		}
	}

	void BasicLanguageFacilities::RangedBasedForLoop() const
	{
		std::cout << "-- Ranged based for loop --" << '\n';

		int arr[] = { 1, 2, 3, 4, 5 };
		// & is used here to avoid copy of the element and const is used to avoid modification on the variable if necessary
		for (const auto& x : arr)
		{
			if (x % 2 == 0)
			{
				std::cout << x << ' ';
			}
		}

		std::cout << '\n';
	}

	void BasicLanguageFacilities::FunctionPointerPratice() const
	{
		void(*pFunc) (int, char) = PrintCharacter;
		(*pFunc)(5, 't');
		pFunc(5, 't');
	}
}

void BLF::PrintCharacter(int count, char c)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << c << ' ';
	}

	std::cout << '\n';
}