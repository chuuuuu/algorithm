#include <bits/stdc++.h>

using namespace std;

struct Data
{
  int key;
  int value;
};

class LRUCache
{
  unordered_map<int, list<Data>::iterator> _map;
  list<Data> _list;
  int _capacity;

public:
  LRUCache(int capacity) : _capacity(capacity)
  {
  }

  int get(int key)
  {
    if (!_map.count(key))
    {
      return -1;
    }

    _list.splice(_list.begin(), _list, _map[key]);
    return _map[key]->value;
  }

  void put(int key, int value)
  {
    if (_map.count(key))
    {
      _list.splice(_list.begin(), _list, _map[key]);
      _map[key]->value = value;
      return;
    }

    if (_map.size() == _capacity)
    {
      _map.erase(_list.back().key);
      _list.pop_back();
    }

    _list.push_front({key, value});
    _map[key] = _list.begin();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */