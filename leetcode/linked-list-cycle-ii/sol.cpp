#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// a1 -> a2 -> ... -> an -> an+1 -> ... -> am
//                    ^                     |
//                    |                     |
//                    +---------------------+

class Solution
{
public:
  ListNode *detectCycle(ListNode *head)
  {
    if (head == NULL)
    {
      return NULL;
    }

    auto slow = head;
    auto fast = head;
    while (true)
    {
      slow = slow->next;
      if (slow == NULL)
      {
        return NULL;
      }

      fast = fast->next;
      if (fast == NULL)
      {
        return NULL;
      }

      fast = fast->next;
      if (fast == NULL)
      {
        return NULL;
      }

      if (slow == fast)
      {
        break;
      }
    }

    slow = head;

    while (true)
    {
      if (slow == fast)
      {
        break;
      }

      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};