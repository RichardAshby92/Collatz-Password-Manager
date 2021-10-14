#include <iostream>
#include <string>

using namespace std;

int* Encrypt(string a)
{
	const int L = size(a);
	int count = 0;
	int offset = 0;
	int* P = new int[L];
	unsigned char n = a[0];


	for (int i = 0; i < L; i++)
	{
		unsigned char n = a[i];

		for (n = n + offset; n != 1; count++)
		{
			n = (n % 2 == 0) ? n / 2 : 3 * n + 1;
		}

		P[i] = count;
		offset = count;
		count = 0;

	}

	return P;
}