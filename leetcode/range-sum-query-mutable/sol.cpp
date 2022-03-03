#include <bits/stdc++.h>

using namespace std;

class Node
{
  // range
  int _head, _mid, _tail, _val;

  // childs
  Node *_leftNode, *_rightNode;

public:
  Node(int head, int tail, vector<int> &nums)
  {
    _head = head;
    _tail = tail;
    if (_head == _tail)
    {
      _val = nums[_head];
      return;
    }

    _mid = (_head + _tail) / 2;

    _leftNode = new Node(_head, _mid, nums);
    _rightNode = new Node(_mid + 1, _tail, nums);
    _val = _leftNode->_val + _rightNode->_val;
  }

  int getSum(int head, int tail)
  {
    if (_head == head && _tail == tail)
    {
      return _val;
    }

    int ret = 0;
    if (head <= _mid)
    {
      ret += _leftNode->getSum(head, min(tail, _mid));
    }
    if (tail >= _mid + 1)
    {
      ret += _rightNode->getSum(max(head, _mid + 1), tail);
    }

    return ret;
  }

  void update(int pos, int num)
  {
    if (_head == _tail)
    {
      _val = num;
      return;
    }

    if (pos <= _mid)
    {
      _leftNode->update(pos, num);
    }
    else
    {
      _rightNode->update(pos, num);
    }

    _val = _leftNode->_val + _rightNode->_val;
  }
};

class NumArray
{
  Node *root;

public:
  NumArray(vector<int> &nums)
  {
    root = new Node(0, nums.size() - 1, nums);
  }

  void update(int index, int val)
  {
    root->update(index, val);
  }

  int sumRange(int left, int right)
  {
    return root->getSum(left, right);
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */