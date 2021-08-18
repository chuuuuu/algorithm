#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int totalFruit(vector<int> &fruits)
  {
    unordered_map<int, int> count;
    int bestScore = INT_MIN;
    int head = 0;
    for (auto fruit : fruits)
    {
      if (count.count(fruit))
      {
        count[fruit] += 1;
        continue;
      }

      if (count.size() == 0 || count.size() == 1)
      {
        count[fruit] = 1;
        continue;
      }

      int score = 0;
      for (auto [key, value] : count)
      {
        score += value;
      }

      if (score > bestScore)
      {
        bestScore = score;
      }

      while (true)
      {
        auto key = fruits[head];
        count[key] -= 1;
        head += 1;
        if (count[key] == 0)
        {
          count.erase(key);
          break;
        }
      }

      count[fruit] = 1;
    }

    int score = 0;
    for (auto [key, value] : count)
    {
      score += value;
    }

    if (score > bestScore)
    {
      bestScore = score;
    }

    return bestScore;
  }
};