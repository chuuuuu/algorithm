#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string alphabetToNumber(string str)
{
  // ABA -> 26^2 * 1 + 26^1 * 2 + 26^0 * 1
  int ret = 0;
  int base = 1;
  for (int i = str.size() - 1; i >= 0; i--)
  {
    ret += base * (str[i] - 'A' + 1);
    base *= 26;
  }

  return to_string(ret);
}

string numberToAlphabet(string str)
{
  // 26^2 * 1 + 26^1 * 2 + 26^0 * 1 -> ABA
  int num = stoi(str);
  string ret;
  while (true)
  {
    if (num == 0)
    {
      break;
    }

    if (num % 26 == 0)
    {
      num -= 26;
      num /= 26;
      ret.push_back('Z');
      continue;
    }

    ret.push_back('A' + num % 26 - 1);
    num /= 26;
  }

  reverse(ret.begin(), ret.end());

  return ret;
}

void solve()
{
  string word;
  cin >> word;
  size_t first = word.find_first_of("0123456789");
  if (word.substr(first).find('C') == string::npos)
  {
    // BC23 -> R23C55
    string alphabetCol = word.substr(0, first);
    string numberCol = alphabetToNumber(alphabetCol);
    cout << "R" + word.substr(first) + "C" + numberCol << endl;
    return;
  }

  // R23C55 -> BC23
  size_t cPos = word.find("C");
  string numberRow = word.substr(1, cPos - 1);
  string numberCol = word.substr(cPos + 1);
  string alphabetCol = numberToAlphabet(numberCol);
  cout << alphabetCol + numberRow << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    solve();
  }
}