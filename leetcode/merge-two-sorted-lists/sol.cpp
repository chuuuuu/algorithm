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

class Solution
{
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    ListNode *head = new ListNode();
    ListNode *prev = head;
    while (true)
    {
      if (!list1)
      {
        prev->next = list2;
        break;
      }

      if (!list2)
      {
        prev->next = list1;
        break;
      }

      if (list1->val < list2->val)
      {
        prev->next = list1;
        prev = prev->next;
        list1 = list1->next;
        continue;
      }

      prev->next = list2;
      prev = prev->next;
      list2 = list2->next;
    }

    return head->next;
  }
};