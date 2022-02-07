#include <bits/stdc++.h>
using namespace std;

string addOne(string str)
{
  reverse(str.begin(), str.end());
  for (int i = 0; i < int(str.size()); i++)
  {
    int num = (str[i] - '0') + 1;
    if (num < 10)
    {
      str[i] = '0' + num;
      break;
    }
    if (num == 10)
    {
      str[i] = '0';
    }
  }

  if (str.back() == '0')
  {
    str.push_back('1');
  }

  reverse(str.begin(), str.end());
  return str;
}

string padding(string str, int size)
{
  for (int i = str.size(); i < size; i++)
  {
    str.push_back('0');
  }

  return str;
}

bool isGreater(string str1, string str2)
{
  if (str1.size() > str2.size())
  {
    return true;
  }

  if (str1.size() < str2.size())
  {
    return false;
  }

  for (int i = 0; i < int(str1.size()); i++)
  {
    if (str1[i] == str2[i])
    {
      continue;
    }

    return str1[i] > str2[i];
  }

  // equal
  return false;
}

void solve()
{
  int N;
  cin >> N;

  vector<string> strs(N, "");
  for (int i = 0; i < N; i++)
  {
    cin >> strs[i];
  }

  string prev = strs[0];
  int ans = 0;
  for (int i = 1; i < N; i++)
  {
    if (isGreater(strs[i], prev))
    {
      prev = strs[i];
      continue;
    }

    string prevAddOne = addOne(prev);
    if (prevAddOne.substr(0, strs[i].size()) == strs[i])
    {
      prev = prevAddOne;
      ans += prevAddOne.size() - strs[i].size();
      continue;
    }

    string strPadding = padding(strs[i], prev.size());
    if (!isGreater(strPadding, prev))
    {
      strPadding.push_back('0');
    }

    prev = strPadding;
    ans += strPadding.size() - strs[i].size();
  }

  cout << ans << "\n";
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  auto t = 0;
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}