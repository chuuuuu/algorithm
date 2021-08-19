// ref: https://www.youtube.com/watch?v=MCTN3MM8vHA&ab_channel=HuaHua
#include <bits/stdc++.h>

using namespace std;

struct Data
{
  int freq;
  int value;
  int key;
};

class LFUCache
{
  unordered_map<int, list<Data>::iterator> _keyMap;
  unordered_map<int, list<Data>> _freqMap;
  int _minFreq;
  int _capacity;

public:
  LFUCache(int capacity) : _capacity(capacity), _minFreq(0)
  {
  }

  int get(int key)
  {
    // if key not found
    if (!_keyMap.count(key))
    {
      return -1;
    }

    auto &iter = _keyMap[key];
    updateFreq(iter);

    return iter->value;
  }

  void put(int key, int value)
  {
    if(!_capacity){
      return;
    }

    // if key exist
    if (_keyMap.count(key))
    {
      auto &iter = _keyMap[key];
      iter->value = value;
      updateFreq(iter);
      return;
    }

    // remove
    if (_keyMap.size() == _capacity)
    {
      auto &list = _freqMap[_minFreq];
      auto &iter = list.back();
      _keyMap.erase(iter.key);
      _freqMap[_minFreq].pop_back();
      if (_freqMap[_minFreq].empty())
      {
        _freqMap.erase(_minFreq);
      }
    }

    // insert key, value
    _minFreq = 1;
    if (!_freqMap.count(_minFreq))
    {
      _freqMap[_minFreq] = {};
    }

    _freqMap[_minFreq].push_front({_minFreq, value, key});
    _keyMap[key] = _freqMap[_minFreq].begin();
  }

  void updateFreq(list<Data>::iterator &iter)
  {
    auto oldFreq = iter->freq;
    auto newFreq = oldFreq + 1;
    iter->freq = newFreq;

    if (!_freqMap.count(newFreq))
    {
      _freqMap[newFreq] = {};
    }

    _freqMap[newFreq].splice(_freqMap[newFreq].begin(), _freqMap[oldFreq], iter);
    if (_freqMap[oldFreq].empty())
    {
      _freqMap.erase(oldFreq);
      if (oldFreq == _minFreq)
      {
        _minFreq += 1;
      }
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */