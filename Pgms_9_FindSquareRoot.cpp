#include <iostream>
#include <cmath>

using namespace std;

// Coded on Oct 23, 2021
// For a given number n, find the square root of N upto P decimal places
// Divide on a number line 1 to N such that, i square <= N,
// Find "i"  that is closest and <=N. Run binary search here with mid of 1 to N, and so on
// Once found then run bin search from 0 to 9 from first decimal place
// Similarly run bin search for second decimal place.
// Eq. N=10 and P=3
// (3)^2 <= 10
// (3.5)^2 <=10
// (3.12)^2 <=10
// and so on.

void FindSquareRoot(int N, int P, float &ans)
{
	int i, j, k;
	float temp_ans, temp_max, temp_final;
	bool found = true;
	int s, e, mid;
	s = 0;
	e = N - 1;
	int max;
	float sq;
	float floatingN = (float)N;
	while (s <= e)
	{
		mid = (s + e) / 2;
		sq = (mid + 1) * (mid + 1);

		if (sq > N)
		{
			e = mid - 1;
		}
		else
		{
			max = mid + 1;
			s = mid + 1;
		}
	}
	//cout << "sqrt in FindSquareRoot()=" << max << endl;
	ans = max;
	temp_final = ans;
	// Find the decimal digits now
	for (i = 0; i < P; i++)
	{
		s = 0, e = 9;
		while (s <= e)
		{
			mid = (s + e) / 2;

			temp_ans = temp_final + (1 / pow(10, i + 1)) * mid;
			sq = temp_ans * temp_ans;
			//cout << "temp_ans=" << temp_ans << "floatingN=" <<	floatingN << endl;
			if (sq > floatingN)
			{
				//cout << "temp_ans>floatingN" << endl;
				e = mid - 1;
			}
			else
			{
				//cout << "temp_ans <= floatingN" << endl;
				//cout << "temp_ans=" << temp_ans << endl;
				temp_max = temp_ans;
				s = mid + 1;
			}
		}
		temp_final = temp_max;
		//cout << "i=" << i << " temp_max=" << temp_max << endl;
	}

	ans = temp_final;
}
int main(int argc, char *argv[])
{
	int N;
	int P;

	cout << "Enter an interger to find Square Root:" << endl;
	cin >> N;
	cout << "Enter the number of decimal places to find square root :" << endl;
	cin >> P;

	float ans;

	FindSquareRoot(N, P, ans);

	cout << "Result=" << ans << endl;

	return 0;
}
