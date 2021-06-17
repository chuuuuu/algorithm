#include <bits/stdc++.h>
using namespace std;

//112358
//s[0:1] + s[1:2] = s[2:3]
//s[1:2] + s[2:3] = s[3:4]
//s[2:3] + s[3:4] = s[4:5]
//s[3:4] + s[4:5] = s[5:6]

using ll = long long;

class Solution
{
	string s;
	int L;

public:
	bool isAdditiveNumber(string s)
	{
		this->s = s;
		this->L = s.size();

		// at least need to check s[0:2]+s[2:4]=s[4:6]
		for (int i = 1; i < L / 2 + 1; i++)
		{
			for (int j = i + 1; j < L - i + 1; j++)
			{
				// check if s additive with starting substring s[0:i], s[i:j]
				if (this->isAdditiveNumber(0, i, j))
				{
					return true;
				}
			}
		}

		return false;
	}

	int isAdditiveNumber(int i0, int i1, int i2)
	{
		ll n0, n1, n2;
		int i3;
		string s2_expect;

		n0 = this->get_num(i0, i1);
		n1 = this->get_num(i1, i2);
		if (n0 == -1 or n1 == -1)
		{
			return false;
		}

		s2_expect = to_string(n0 + n1);
		i3 = i2 + s2_expect.size();
		if (i3 > this->L)
		{
			return false;
		}

		n2 = this->get_num(i2, i3);
		if (n0 + n1 != n2)
		{
			return false;
		}

		if (i3 == this->L)
		{
			return true;
		}

		if (this->isAdditiveNumber(i1, i2, i3))
		{
			return true;
		}

		return false;
	}

	ll get_num(int i0, int i1)
	{
		if (this->s[i0] == '0' and i1 != i0 + 1)
		{
			return -1;
		}

		ll ret = 0;
		for (int i = i0; i < i1; i++)
		{
			ret *= 10;
			ret += int(this->s[i]) - int('0');
		}

		return ret;
	}
};

int main() {
	ios::sync_with_stdio(0);
  cin.tie(0);
  
	Solution sol = Solution();
	string s;

	s = "112358";
	cout << s << ": " << sol.isAdditiveNumber(s) << endl;

	s = "112359";
	cout << s << ": " << sol.isAdditiveNumber(s) << endl;
}