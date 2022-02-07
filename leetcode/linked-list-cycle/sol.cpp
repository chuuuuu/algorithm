#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    if (!head || !(head->next))
    {
      return false;
    }

    ListNode *fast = head->next->next;
    ListNode *slow = head->next;
    while (true)
    {
      if (!fast || !(fast->next))
      {
        return false;
      }

      if (fast == slow)
      {
        return true;
      }

      fast = fast->next->next;
      slow = slow->next;
    }
  }
};