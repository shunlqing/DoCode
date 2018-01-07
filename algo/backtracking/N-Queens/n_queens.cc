/**
 * N-Queens Problems
 */

#include <iostream>
#include <vector>
#include <bitset>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::bitset;

/**
* 
*/
bool isValid_8(int index, std::vector<unsigned char> queens)
{
	if(index == 1)
		return true;

	if(index > 1)
	{
		char cur = queens[0];
		for(int i = 1; i < index; i++) {
			if((cur | queens[i]) == cur)
				return false;
			else
				cur |= queens[i];
		}

		for(int i = 0; i < index; i++) {
			for(int j = i + 1; j < index; j++) {
				if((queens[i] * pow(2, (j-i)) == queens[j]) || (queens[j] * pow(2, (j-i)) == queens[i]))
					return false;
			}
		}
	}
	return true;
}

/**
* if has a solve
*/
bool solve1(int i, std::vector<unsigned char> queens, char n)
{
	if(i == n)
	{
		if(isValid_8(i, queens))
			return true;
		else
			return false;
	} else {
		for(int j = 0; j < n; j++)
		{
			queens[i] |= 1 << j;
			if(isValid_8(i + 1, queens)) {
				return solve1(i + 1, queens, n);
			} else {
				queens[i] = 0;
			}
		}
	}
}

void printResult(std::vector<unsigned char> result)
{
	for(int j = 0; j < result.size(); j++)
	{
		bitset<8> c = result[j];
		cout << c << endl;
	}
	cout << endl;
}

std::vector<std::vector<unsigned char> > result;
void solve2(int i, std::vector<unsigned char> queens, char n)
{
	if(i == n)
	{
		if(isValid_8(i, queens)) {
			result.push_back(queens);
			// printResult(queens);
		}
	} else {
		for(int j = 0; j < n; j++)
		{
			queens[i] = 1 << j;
			if(isValid_8(i + 1, queens)) {
				solve2(i + 1, queens, n);
			}
			queens[i] = 0;
		}
	}
}

void printResult(std::vector<std::vector<unsigned char> > result)
{
	for(int i = 0; i < result.size(); i++)
	{
		cout << i << ":" << endl;
		for(int j = 0; j < result[1].size(); j++)
		{
			bitset<8> c = result[i][j];
			cout << c << endl;
		}
		cout << endl;
	}
}



bool solve(void)
{
	std::vector<unsigned char> queens(8, 0);

	solve2(0, queens, 8);
}

int main()
{
	solve();
	cout << "result.size() = " << result.size() << endl;
	printResult(result);
}