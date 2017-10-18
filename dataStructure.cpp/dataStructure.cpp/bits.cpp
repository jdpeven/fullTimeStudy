#include "Header.h"

void printBitTable(int k)
{
	for (int i = 0; i < k; i++)
	{
		cout << "Base: " << i << "   Binary: ";
		for (int j = 0; j < 32; j++)
		{
			if ((i >> (31-j)) & 1 != 0)
			{
				cout << "1";
			}
			else
				cout << "0";
		}
		cout << endl;
	}
}


void testBits()
{
	printBitTable(50);
}