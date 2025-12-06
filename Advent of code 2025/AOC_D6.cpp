#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <string>
using namespace std;

void part1()
{
	ifstream input("input.txt");
	int operationMembers[10][1000];

	char line[10000];
	int indexRow = 0;
	int indexCol;
	while (input.getline(line, sizeof(line)))
	{
		indexCol = 0;
		char* pointer = strtok(line, " ");

		while (pointer != NULL)
		{
			if (*pointer == '*' || *pointer == '+')
			{
				operationMembers[indexRow][indexCol] = *pointer;
			}
			else
			{
				int value = atoll(pointer);
				operationMembers[indexRow][indexCol] = value;
			}

			pointer = strtok(NULL, " ");
			indexCol++;
		}
		indexRow++;
	}

	long long int answer = 0;

	for(int iCol = 0; iCol<indexCol; iCol++)
	{ 
		long long int tempAnswer;
		if (operationMembers[indexRow - 1][iCol] == 42)
			tempAnswer = 1;
		else
			tempAnswer = 0;

		for (int iRow = 0; iRow < indexRow-1; iRow++)
		{
			if (operationMembers[indexRow - 1][iCol] == 42)
				tempAnswer = tempAnswer * operationMembers[iRow][iCol];
			else
				tempAnswer = tempAnswer + operationMembers[iRow][iCol];
		}

		answer += tempAnswer;
	}

	cout << "answer: " << answer;
}

int main()
{
	part1();
}