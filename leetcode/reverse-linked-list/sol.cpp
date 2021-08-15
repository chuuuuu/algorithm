#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// explain:
// first we create a dummy node in front of head
// then we move the node one by one to the place after dummy
class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    if (!head)
    {
      return head;
    }

    auto dummy = new ListNode(0, head);
    auto current = head;

    // dummy -> ... -> current -> moved -> ... -> NULL
    while (true)
    {
      if (!current->next)
      {
        break;
      }

      auto moved = current->next;
      current->next = moved->next;
      moved->next = dummy->next;
      dummy->next = moved;
    }

    return dummy->next;
  }
};