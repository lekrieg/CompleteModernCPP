#ifndef BASIC_LANGUAGE_FACILITIES_H
#define BASIC_LANGUAGE_FACILITIES_H

namespace BLF
{
	class BasicLanguageFacilities
	{
	private:
		const float PI{ 3.14f };

	public:
		void PrintBasicTypesInfo() const;
		void GetUserInput();
		void BasicPointerAndReferenceTest();
		void PrintCircleInfo(const int& radius) const;
		void ConstPractice();
		void ForLoopPratice() const;
		void FunctionPointerPratice() const;

		inline int Square(int x)
		{
			return x * x;
		}
	private:
		void Swap(int* x, int* y);
		void Swap(int& x, int& y);
		void NormalForLoop() const;
		void RangedBasedForLoop() const;
	};

	void PrintCharacter(int count, char c);
}

#endif // !BASIC_LANGUAGE_FACILITIES_H
