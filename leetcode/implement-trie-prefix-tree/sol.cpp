#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
  bool isWord = false;
  TrieNode *nodes[26];
};

class Trie
{
public:
  /** Initialize your data structure here. */
  TrieNode *root;
  Trie()
  {
    this->root = new TrieNode();
  }

  /** Inserts a word into the trie. */
  void insert(string word)
  {
    auto current = this->root;
    for (auto c : word)
    {
      auto index = c - 'a';
      if (!(current->nodes[index]))
      {
        current->nodes[index] = new TrieNode();
      }

      current = current->nodes[index];
    }

    current->isWord = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word)
  {
    auto current = this->root;
    for (auto c : word)
    {
      auto index = c - 'a';
      if (!current->nodes[index])
      {
        return false;
      }

      current = current->nodes[index];
    }

    return current->isWord;
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix)
  {
    auto current = this->root;
    for (auto c : prefix)
    {
      auto index = c - 'a';
      if (!current->nodes[index])
      {
        return false;
      }

      current = current->nodes[index];
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */