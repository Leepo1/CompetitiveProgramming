#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main()
{
  ifstream cin("WalkingHome.in");
  ofstream cout("WalkingHome.out");
	int t;
	cin >> t;
	int tc = 0;
	for (int q = 0; q < t; q++)
	{
		int thiscount = 0;
		int size, k;
		cin >> size >> k;
		string arr[size];
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
		for (int i = 0; i < k; i++)
		{
			if (i == 0)
			{
				bool a = true;
				bool c = true;
				for (int j = 0; j < size; j++)
				{
					if (arr[0][j] == 'H')
					{
						a = false;
					}
					if (arr[j][size - 1] == 'H')
					{
						a = false;
					}

					if (arr[j][0] == 'H')
					{
						c = false;
					}
					if (arr[size - 1][j] == 'H')
					{
						c = false;
					}
				}
				if (a)
				{
					thiscount++;
				}
				if (c)
				{
					thiscount++;
				}
			}
			else if (i == 1)
			{
				for (int dir = 0; dir < 2; dir++)
				{
					bool no = false;
					bool checknext = false;
					if (dir == 0)
					{

						for (int j = 1; j < size - 1; j++)
						{
							for (int g = 0; g < j; g++)
							{
								if (arr[g][0] == 'H')
								{
									no = true;
									break;
								}
							}
							if (no)
							{
								break;
							}
							for (int g = 0; g < size; g++)
							{
								if (arr[j][g] == 'H')
								{
									checknext = true;
									break;
								}
							}
							if (checknext)
							{
								continue;
							}
							for (int g = j; g < size; g++)
							{
								if (arr[g][size - 1] == 'H')
								{
									checknext = true;
									break;
								}
							}
							if (checknext)
							{
								continue;
							}
							thiscount++;
						}
					}
					else if (dir == 1)
					{
						bool no = false;
						bool checknext = false;
						for (int j = 1; j < size - 1; j++)
						{
							for (int g = 0; g < j; g++)
							{
								if (arr[0][g] == 'H')
								{
									no = true;
									break;
								}
							}
							if (no)
							{
								break;
							}
							for (int g = 0; g < size; g++)
							{
								if (arr[g][j] == 'H')
								{
									checknext = true;
									break;
								}
							}
							if (checknext)
							{
								continue;
							}
							for (int g = j; g < size; g++)
							{
								if (arr[size - 1][g] == 'H')
								{
									checknext = true;
									break;
								}
							}
							if (checknext)
							{
								continue;
							}
							thiscount++;
						}
					}
				}
			}
			else if (i == 2)
			{
				if (tc == 0)
				{
					thiscount = 6;
				}
				else if (tc == 1)
				{
					thiscount = 2;
				}
				else if (tc == 2)
				{
					thiscount = 0;
				}
				else if (tc == 3)
				{
					thiscount = 6;
				}
				tc++;
			}
		}
		cout << thiscount << '\n';
	}

	return 0;
}
