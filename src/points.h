#include <iostream>
#include <vector>
#ifndef MATRIX
	#define MATRIX
	#include "matrix.h"
#endif
using namespace std;

class points
{
private:
	int n;
	vector<double> x, y;

public:
	points()
	{
		cin >> n;
		x.resize(n);
		y.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i];
		}
	}

	int getN() { return n; }

	matrix matX(int d)
	{
		matrix c(n, d + 1);
		for (int i = 0; i < n; i++)
		{
			c.set(i, 0, 1.0);
			double cur = x[i];
			for (int j = 1; j <= d; j++)
			{
				c.set(i, j, cur);
				cur = cur * x[i];
			}
		}
		return c;
	}

	matrix matY()
	{
		matrix c(n, 1);
		for (int i = 0; i < n; i++)
			c.set(i, 0, y[i]);
		return c;
	}
};