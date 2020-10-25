#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <istream>
#include <stdlib.h>
#include <vector> 
#include <algorithm>

namespace cs {
	class SetOfChar {

	public:
		const int getMaxPower() const { return MAX_SET_POWER; };
		unsigned int getCurrentPower() const { return currentPower; };
		char getSymbolByIndex(int index) const { return set[index]; };

		// пустой конструктор : задание 1
		SetOfChar(void) {
			currentPower = 0;
		};

		// задание 2
		SetOfChar(int power);

		// задание 3
		SetOfChar(const char* symbolString);

		// задание 4
		friend std::istream& input(std::istream& p, SetOfChar& s);
		friend std::ostream& output(std::ostream& p, const SetOfChar& s);

		// задание 5
		SetOfChar setUnion(const SetOfChar& set1, const SetOfChar& set2);

		// задание 6
		SetOfChar add(const char item);

		// задание 7
		SetOfChar intersection(const SetOfChar& set1, const SetOfChar& set2);

		// задание 8
		SetOfChar differ(const SetOfChar& set1, const SetOfChar& set2);

		// задание 9
		bool contains(char item) const;

		// вспомогательная функция для извлечения уникальных элементов
		void makeSet(char* str);

	private:
		unsigned int currentPower;
		static const int MAX_SET_POWER = 100;
		char set[MAX_SET_POWER];
		void addWithoutCheckingContaining(const char item);
	};

	std::istream& input(std::istream& p, cs::SetOfChar& s);
	std::ostream& output(std::ostream& p, const cs::SetOfChar& s);
}


template <class T>
int getn(T& a) {
	using std::cin;
	cin >> a;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin.clear();
		cin >> a;
	}
	return 1;
}