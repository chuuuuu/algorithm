#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, int> keyToIndex;
    vector<vector<string>> anagramsVec;
    for (auto str : strs)
    {
      auto key = this->getKey(str);
      if (!keyToIndex.count(key))
      {
        keyToIndex[key] = anagramsVec.size();
        anagramsVec.push_back({});
      }

      anagramsVec[keyToIndex[key]].push_back(str);
    }

    return anagramsVec;
  }

  string getKey(string value)
  {
    vector<int> keyVec(26, 0);
    for (auto c : value)
    {
      auto idx = c - 'a';
      keyVec[idx] += 1;
    }

    string ret = "";
    for (auto key : keyVec)
    {
      ret.push_back('#');
      ret += to_string(key);
    }

    return ret;
  }
};