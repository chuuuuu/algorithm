# Interview Question Patterns

- [Interview Question Patterns](#interview-question-patterns)
  - [About](#about)
    - [Question selection](#question-selection)
  - [Patterns](#patterns)
    - [1D and 2D Array](#1d-and-2d-array)
    - [String](#string)
    - [Sliding Window](#sliding-window)
    - [Two Pointers or Iterators](#two-pointers-or-iterators)
    - [Fast and Slow Pointers](#fast-and-slow-pointers)
    - [Intervals](#intervals)
    - [Cyclic Sort](#cyclic-sort)
    - [Linked List](#linked-list)
    - [BFS](#bfs)
    - [DFS](#dfs)
    - [BFS or DFS](#bfs-or-dfs)
    - [Heaps](#heaps)
    - [Subsets](#subsets)
    - [Modified Binary Search](#modified-binary-search)
    - [Topological Sort](#topological-sort)
    - [Binary & Bitwise XOR](#binary--bitwise-xor)
    - [Trie](#trie)
    - [Dynamic Programming](#dynamic-programming)
    - [Backtracking](#backtracking)
    - [Design](#design)
  - [Reference](#reference)

## About

This is a collection of common interview patterns and questions used to prepare for interviews. The point of this collection is to focus on **quality** rather than **quantity**. If we just blindly shotgun hundred of problems, we may run into problems we've never seen before and are unsure on how to solve them from an abstract, theorectical standpoint.

_For example, we may have a toolbox full of tools but are unsure of which problems those tools solve. We could run into a problem of trying to attach a board to another with a screw. Could we hammer the screw? Sure, O(n<sup>2</sup>). Could we hit it with a level? Sure, (Time limit exceded). A better solution is to use a screwdriver. O(nlogn). An even more optimal solution is to use a drill O(n)._

This illustrates that if we just do a bunch of problems, we know we need to get the screw to attach both boards. But knowing the theory of the problems shows us which _tool_ to use.

### Question selection

Questions are gathered from a mix of currated lists and frequently asked questions on leetcode. The majority will be LC Medium difficulty (7-10), with 2-3 easy and 2-3 hard. Feel free to skip the easy or hard, the mediums will be where you get the most bang for your buck.

## Patterns

### 1D and 2D Array

| Title                                                                                             | Solution                                       | Difficulty |
| ------------------------------------------------------------------------------------------------- | ---------------------------------------------- | ---------- |
| [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)                           |                                                | Easy       |
| [Two Sum](https://leetcode.com/problems/two-sum/)                                                 |                                                | Easy       |
| [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/) | [C++](find-all-duplicates-in-an-array/sol.cpp) | Medium     |
| [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)       |                                                | Medium     |
| [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)               | [C++](maximum-product-subarray/sol.cpp)        | Medium     |
| [One Edit Distance](https://leetcode.com/problems/one-edit-distance/)                             |                                                | Medium     |
| [String Compression](https://leetcode.com/problems/string-compression/)                           | [C++](string-compression/sol.cpp)              | Medium     |
| [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)                     |                                                | Medium     |
| [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)                             | [C++](set-matrix-zeroes/sol.cpp)               | Medium     |
| [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)                                     |                                                | Medium     |
| [Rotate Image](https://leetcode.com/problems/rotate-image/)                                       |                                                | Medium     |
| [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/)                             |                                                | Medium     |

### String

| Title                                                                                         | Solution                                     | Difficulty |
| --------------------------------------------------------------------------------------------- | -------------------------------------------- | ---------- |
| [Valid Anagram](https://leetcode.com/problems/valid-anagram/)                                 |                                              | Easy       |
| [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)                         |                                              | Easy       |
| [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)                           |                                              | Easy       |
| [Group Anagrams](https://leetcode.com/problems/group-anagrams/)                               | [C++](group-anagrams/sol.cpp)                | Medium     |
| [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/) | [C++](longest-palindromic-substring/sol.cpp) | Medium     |
| [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)               | [C++](palindromic-substrings/sol.cpp)        | Medium     |
| [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/)         |                                              | Medium     |

### Sliding Window

https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems  
https://medium.com/leetcode-patterns/leetcode-pattern-2-sliding-windows-for-strings-e19af105316b  
https://emre.me/coding-patterns/sliding-window/

| Title                                                                                                                                                           | Solution                                 | Difficulty |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------- | ---------- |
| [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)                                                                           | [C++](minimum-size-subarray-sum/sol.cpp) | Medium     |
| [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)                                                                                         | [C++](fruit-into-baskets/sol.cpp)        | Medium     |
| [Permutation in String](https://leetcode.com/problems/permutation-in-string/)                                                                                   | [C++](permutation-in-string/sol.cpp)     | Medium     |
| [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)                                 |                                          | Medium     |
| [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)                                               |                                          | Medium     |
| [Longest Continuous Subarray with Abs Diff <= Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/) |                                          | Medium     |
| [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)                                                                             |                                          | Medium     |
| [Max Points You Can Obtain From Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)                                                 |                                          | Medium     |
| [Longest Substring with at Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)                 |                                          | Medium     |
| [Number of Subsequences that Satisfy the Given Sum Condition](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/)       |                                          | Medium     |
| [Grumpy Bookstore Owner](https://leetcode.com/problems/grumpy-bookstore-owner/)                                                                                 |                                          | Medium     |
| [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)                                                                                 |                                          | Hard       |
| [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)                                                                             |                                          | Hard       |
| [Minimum Number of K Consecutive Bit Flips](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/)                                           |                                          | Hard       |
| [Count Unique Characters of All Substrings of a Given String](https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/)       |                                          | Hard       |
| [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)                                           |                                          | Hard       |

---

### Two Pointers or Iterators

https://emre.me/coding-patterns/two-pointers/

| Title                                                                                             | Solution                    | Difficulty |
| ------------------------------------------------------------------------------------------------- | --------------------------- | ---------- |
| [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)                   |                             | Easy       |
| [Two Sum](https://leetcode.com/problems/two-sum/)                                                 | [C++](two-sum/sol.cpp)      | Easy       |
| [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)             |                             | Easy       |
| [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare)                |                             | Easy       |
| [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)             |                             | Medium     |
| [3 Sum](https://leetcode.com/problems/3sum/)                                                      |                             | Medium     |
| [3 Sum Closest](https://leetcode.com/problems/3sum-closest/)                                      | [C++](3sum-closest/sol.cpp) | Medium     |
| [Subarrays with Product Less than K](https://leetcode.com/problems/subarray-product-less-than-k/) |                             | Medium     |
| [Sort Colors](https://leetcode.com/problems/sort-colors/)                                         |                             | Medium     |
| [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)             |                             | Medium     |
| [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)                         |                             | Hard       |

### Fast and Slow Pointers

https://emre.me/coding-patterns/fast-slow-pointers/

| Title                                                                                                         | Solution                            | Difficulty |
| ------------------------------------------------------------------------------------------------------------- | ----------------------------------- | ---------- |
| [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)                                         |                                     | Easy       |
| [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)                         |                                     | Easy       |
| [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)                               |                                     | Easy       |
| [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)                     |                                     | Easy       |
| [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)       |                                     | Easy       |
| [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)                                   | [C++](linked-list-cycle-ii/sol.cpp) | Medium     |
| [Remove Duplicated from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) |                                     | Medium     |
| [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)                                             |                                     | Medium     |
| [Add Two Number II](https://leetcode.com/problems/add-two-numbers-ii/)                                        |                                     | Medium     |
| [Remove Nth Node From End Of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)           |                                     | Medium     |
| [Sort List](https://leetcode.com/problems/sort-list/)                                                         |                                     | Medium     |
| [Reorder List](https://leetcode.com/problems/reorder-list/)                                                   |                                     | Medium     |

### Intervals

https://emre.me/coding-patterns/merge-intervals/

| Title                                                                                                                   | Solution                                                  | Difficulty |
| ----------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------- | ---------- |
| [Meeting Rooms](https://leetcode.com/problems/meeting-rooms)                                                            |                                                           | Easy       |
| [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)                                                     |                                                           | Medium     |
| [Merge Intervals](https://leetcode.com/problems/merge-intervals/)                                                       | [C++](merge-intervals/sol.cpp)                            | Medium     |
| [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/)                               | [C++](interval-list-intersections/sol.cpp)                | Medium     |
| [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)                                   | [C++](non-overlapping-intervals/sol.cpp)                  | Medium     |
| [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) | [C++](minimum-number-of-arrows-to-burst-balloons/sol.cpp) | Medium     |
| [Insert Interval](https://leetcode.com/problems/insert-interval/)                                                       |                                                           | Medium     |

### Cyclic Sort

https://emre.me/coding-patterns/cyclic-sort/

| Title                                                                                               | Solution                                                | Difficulty |
| --------------------------------------------------------------------------------------------------- | ------------------------------------------------------- | ---------- |
| [Find all missing numbers](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/) | [C++](find-all-numbers-disappeared-in-an-array/sol.cpp) | Easy       |
| [First Missing Positive](https://leetcode.com/problems/first-missing-positive/)                     | [C++](first-missing-positive/sol.cpp)                   | Hard       |

### Linked List

https://emre.me/coding-patterns/in-place-reversal-of-a-linked-list/

| Title                                                                               | Solution                           | Difficulty |
| ----------------------------------------------------------------------------------- | ---------------------------------- | ---------- |
| [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)           | [C++](reverse-linked-list/sol.cpp) | Easy       |
| [Intersection](https://leetcode.com/problems/intersection-of-two-linked-lists/)     |                                    | Easy       |
| [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)     |                                    | Medium     |
| [Rotate List](https://leetcode.com/problems/rotate-list/)                           |                                    | Medium     |
| [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)           |                                    | Medium     |
| [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)         |                                    | Medium     |
| [Partition Linked List](https://leetcode.com/problems/partition-list/)              |                                    | Medium     |
| [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/) |                                    | Hard       |

### BFS

https://emre.me/coding-patterns/breadth-first-search/

| Title                                                                                                                           | Solution                                            | Difficulty |
| ------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------- | ---------- |
| [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)                     | [C++](binary-tree-level-order-traversal-ii/sol.cpp) | Easy       |
| [Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/)                             |                                                     | Easy       |
| [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)                           |                                                     | Medium     |
| [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)             |                                                     | Medium     |
| [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)       |                                                     | Medium     |
| [Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/) |                                                     | Medium     |

### DFS

https://emre.me/coding-patterns/depth-first-search/  
_make sure you can solve dfs both recursively **and** iteratively_

| Title                                                                                                                                                 | Solution                          | Difficulty |
| ----------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------- | ---------- |
| [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)                                                                               | [C++](invert-binary-tree/sol.cpp) | Easy       |
| [Path Sum](https://leetcode.com/problems/path-sum/)                                                                                                   |                                   | Easy       |
| [Same Tree](https://leetcode.com/problems/same-tree/)                                                                                                 |                                   | Easy       |
| [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)                                                                     |                                   | Easy       |
| [Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/)                                                                       |                                   | Easy       |
| [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)                                                           |                                   | Easy       |
| [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)                       |                                   | Easy       |
| [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)                                                                     |                                   | Easy       |
| [Path Sum II](https://leetcode.com/problems/path-sum-ii/)                                                                                             |                                   | Medium     |
| [Path Sum III](https://leetcode.com/problems/path-sum-iii/)                                                                                           |                                   | Medium     |
| [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)                                                         |                                   | Medium     |
| [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)                                     |                                   | Medium     |
| [Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/)                                                                             |                                   | Medium     |
| [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/)                                                           |                                   | Medium     |
| [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) |                                   | Medium     |
| [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)                                                             |                                   | Medium     |
| [Target Sum](https://leetcode.com/problems/target-sum/)                                                                                               |                                   | Medium     |
| [Split BST](https://leetcode.com/problems/split-bst/)                                                                                                 |                                   | Medium     |
| [Word Search](https://leetcode.com/problems/word-search-ii/)                                                                                          |                                   | Hard       |
| [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)                                                           |                                   | Hard       |

### BFS or DFS

| Title                                                                                                                                         | Solution                                   | Difficulty |
| --------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------ | ---------- |
| [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)                                                   |                                            | Easy       |
| [Convert Sorted Array to BST](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)                                      |                                            | Easy       |
| [Clone Graph](https://leetcode.com/problems/clone-graph/)                                                                                     |                                            | Medium     |
| [Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/)                                                     | [C++](pacific-atlantic-water-flow/sol.cpp) | Medium     |
| [Number of Islands](https://leetcode.com/problems/number-of-islands/)                                                                         |                                            | Medium     |
| [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)                                                                           |                                            | Medium     |
| [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/) |                                            | Medium     |
| [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)                                                     |                                            | Medium     |
| [All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)                                     |                                            | Medium     |
| [Max Area of Island](https://leetcode.com/problems/max-area-of-island/)                                                                       |                                            | Medium     |
| [Word Ladder](https://leetcode.com/problems/word-ladder/)                                                                                     |                                            | Medium     |
| [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)                                                   |                                            | Hard       |
| [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)                                 |                                            | Hard       |

### Heaps

https://emre.me/coding-patterns/k-way-merge/  
https://emre.me/coding-patterns/top-k-numbers/  
https://emre.me/coding-patterns/two-heaps/

| Title                                                                                                                         | Solution                                       | Difficulty |
| ----------------------------------------------------------------------------------------------------------------------------- | ---------------------------------------------- | ---------- |
| [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)                             | [C++](find-k-pairs-with-smallest-sums/sol.cpp) | Medium     |
| [Task Scheduler](https://leetcode.com/problems/task-scheduler/)                                                               |                                                | Medium     |
| [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)                                   |                                                | Medium     |
| [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)                                             |                                                | Medium     |
| [Kth Largest Element](https://leetcode.com/problems/kth-largest-element-in-an-array/)                                         |                                                | Medium     |
| [K Closests Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)                                      |                                                | Medium     |
| [Reorganize String](https://leetcode.com/problems/reorganize-string/)                                                         |                                                | Medium     |
| [Employee Free Time](https://leetcode.com/problems/employee-free-time/)                                                       |                                                | Hard       |
| [Smallest Range Covering Elements from K Lists](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/) |                                                | Hard       |
| [Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart)                          |                                                | Hard       |
| [Course Schedule III](https://leetcode.com/problems/course-schedule-iii/)                                                     |                                                | Hard       |
| [Maximum Frequency Stack](https://leetcode.com/problems/maximum-frequency-stack/)                                             |                                                | Hard       |
| [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)                                   |                                                | Hard       |
| [Sliding Window Median](https://leetcode.com/problems/sliding-window-median/)                                                 |                                                | Hard       |
| [Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)                                                   |                                                | Hard       |

### Subsets

https://emre.me/coding-patterns/subsets/  
https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)

| Title                                                                              | Solution               | Difficulty |
| ---------------------------------------------------------------------------------- | ---------------------- | ---------- |
| [Subsets](https://leetcode.com/problems/subsets/)                                  | [C++](subsets/sol.cpp) | Medium     |
| [Subsets II](https://leetcode.com/problems/subsets-ii/)                            |                        | Medium     |
| [Permutations](https://leetcode.com/problems/permutations/)                        |                        | Medium     |
| [Permutations II](https://leetcode.com/problems/permutations-ii/)                  |                        | Medium     |
| [Palindrome Permuations](https://leetcode.com/problems/palindrome-permutation-ii/) |                        | Medium     |
| [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/)  |                        | Medium     |

### Modified Binary Search

https://emre.me/coding-patterns/modified-binary-search/

| Title                                                                                                               | Solution                                               | Difficulty |
| ------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------ | ---------- |
| [Binary Search](https://leetcode.com/problems/binary-search/)                                                       | [C++](binary-search/sol.cpp)                           | Easy       |
| [Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/) |                                                        | Easy       |
| [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)                     |                                                        | Easy       |
| [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)   | [C++](kth-smallest-element-in-a-sorted-matrix/sol.cpp) | Medium     |
| [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)         | [C++](find-minimum-in-rotated-sorted-array/sol.cpp)    | Medium     |
| [Find Peak Element](https://leetcode.com/problems/find-peak-element/)                                               | [C++](find-peak-element/sol.cpp)                       | Medium     |
| [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)                     |                                                        | Medium     |
| [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)               |                                                        | Medium     |
| [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)                                             |                                                        | Medium     |
| [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/)                                       |                                                        | Medium     |
| [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/)                                   |                                                        | Medium     |
| [Capacity to Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)   |                                                        | Medium     |
| [Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/)                                             |                                                        | Easy       |

---

### Topological Sort

https://emre.me/coding-patterns/topological-sort/

| Title                                                                                                                       | Solution                       | Difficulty |
| --------------------------------------------------------------------------------------------------------------------------- | ------------------------------ | ---------- |
| [Course Schedule](https://leetcode.com/problems/course-schedule/)                                                           | [C++](course-schedule/sol.cpp) | Medium     |
| [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)                                                     |                                | Medium     |
| [Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/)                                                 |                                | Medium     |
| [Sequence Reconstruction](https://leetcode.com/problems/sequence-reconstruction)                                            |                                | Medium     |
| [Sort Items by Groups Respecting Dependencies](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/) |                                | Hard       |
| [Alien Dictionary](https://leetcode.com/problems/alien-dictionary)                                                          |                                | Hard       |

### Binary & Bitwise XOR

https://emre.me/coding-patterns/bitwise-xor/

| Title                                                                                 | Solution                        | Difficulty |
| ------------------------------------------------------------------------------------- | ------------------------------- | ---------- |
| [Single Number](https://leetcode.com/problems/single-number/)                         | [C++](single-number/sol.cpp)    | Easy       |
| [Missing Number](https://leetcode.com/problems/missing-number/)                       |                                 | Easy       |
| [Complement of Base 10](https://leetcode.com/problems/complement-of-base-10-integer/) |                                 | Easy       |
| [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)                   |                                 | Easy       |
| [Reverse Bits](https://leetcode.com/problems/reverse-bits/)                           |                                 | Easy       |
| [Single Number II](https://leetcode.com/problems/single-number-ii/)                   | [C++](single-number-ii/sol.cpp) | Medium     |
| [Single Number III](https://leetcode.com/problems/single-number-iii/)                 |                                 | Medium     |
| [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/)             |                                 | Medium     |
| [Counting Bits](https://leetcode.com/problems/counting-bits/)                         |                                 | Medium     |
| [Pow(x,n)](https://leetcode.com/problems/powx-n/)                                     |                                 | Medium     |
| [Kth Symbol in Grammar](https://leetcode.com/problems/k-th-symbol-in-grammar/)        |                                 | Medium     |

### Trie

| Title                                                                                                          | Solution                                  | Difficulty |
| -------------------------------------------------------------------------------------------------------------- | ----------------------------------------- | ---------- |
| [Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/)                        |                                           | Easy       |
| [Index Pairs of a String](https://leetcode.com/problems/index-pairs-of-a-string/)                              |                                           | Easy       |
| [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)                      | [C++](implement-trie-prefix-tree/sol.cpp) | Medium     |
| [Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array) |                                           | Medium     |
| [Add and Search Word](https://leetcode.com/problems/add-and-search-word-data-structure-design/)                |                                           | Medium     |
| [Concatenated Words](https://leetcode.com/problems/concatenated-words/)                                        |                                           | Hard       |
| [Prefix and Suffix Search](https://leetcode.com/problems/prefix-and-suffix-search/)                            |                                           | Hard       |
| [Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/)                                            |                                           | Hard       |
| [Design Search Autocomplete System](https://leetcode.com/problems/design-search-autocomplete-system/)          |                                           | Hard       |
| [Word Squares](https://leetcode.com/problems/word-squares/)                                                    |                                           | Hard       |

---

### Dynamic Programming

https://emre.me/coding-patterns/longest-common-substring-subsequence/  
https://emre.me/coding-patterns/palindromes/  
https://emre.me/coding-patterns/staircase/  
https://emre.me/coding-patterns/knapsack/

| Title                                                                                                                                       | Solution                                                            | Difficulty |
| ------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------- | ---------- |
| [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)                                           | [C++](best-time-to-buy-and-sell-stock/sol.cpp)                      | Easy       |
| [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)                                     | [C++](binary-tree-level-order-traversal-ii/sol.cpp)                 | Easy       |
| [House Robber](https://leetcode.com/problems/house-robber/)                                                                                 |                                                                     | Easy       |
| [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)                                                                         |                                                                     | Easy       |
| [Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) | [C++](best-time-to-buy-and-sell-stock-with-transaction-fee/sol.cpp) | Medium     |
| [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)               | [C++](best-time-to-buy-and-sell-stock-with-cooldown/sol.cpp)        | Medium     |
| [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)                                                                           |                                                                     | Medium     |
| [Coin Change](https://leetcode.com/problems/coin-change/)                                                                                   |                                                                     | Medium     |
| [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)                                             |                                                                     | Medium     |
| [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)                                                     | [C++](longest-common-subsequence/sol.cpp)                           | Medium     |
| [Word Break](https://leetcode.com/problems/word-break/)                                                                                     | [C++](word-break/sol.cpp)                                           | Medium     |
| [Combination Sum](https://leetcode.com/problems/combination-sum/)                                                                           | [C++](combination-sum/sol.cpp)                                      | Medium     |
| [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)                                                                     |                                                                     | Medium     |
| [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/)                                                                   |                                                                     | Medium     |
| [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/)                                                                     |                                                                     | Medium     |
| [House Robber II](https://leetcode.com/problems/house-robber-ii/)                                                                           |                                                                     | Medium     |
| [Decode Ways](https://leetcode.com/problems/decode-ways/)                                                                                   |                                                                     | Medium     |
| [Unique Paths](https://leetcode.com/problems/unique-paths/)                                                                                 |                                                                     | Medium     |
| [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)                                                                           |                                                                     | Medium     |
| [Jump Game](https://leetcode.com/problems/jump-game/)                                                                                       |                                                                     | Medium     |
| [Paint Fence](https://leetcode.com/problems/paint-fence/)                                                                                   |                                                                     | Medium     |
| [Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)                                   | [C++](best-time-to-buy-and-sell-stock-iii/sol.cpp)                  | Hard       |
| [Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/)                                     | [C++](best-time-to-buy-and-sell-stock-iv/sol.cpp)                   | Hard       |

### Backtracking

https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)

| Title                                                                                                         | Solution                                  | Difficulty |
| ------------------------------------------------------------------------------------------------------------- | ----------------------------------------- | ---------- |
| [Combinations](https://leetcode.com/problems/combinations/)                                                   |                                           | Medium     |
| [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)                                   | [C++](generate-parentheses/sol.cpp)       | Medium     |
| [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)                             |                                           | Medium     |
| [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) |                                           | Medium     |
| [Generalized Abbreviation](https://leetcode.com/problems/generalized-abbreviation/)                           |                                           | Medium     |
| [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)                       | [C++](partition-equal-subset-sum/sol.cpp) | Medium     |
| [Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)           |                                           | Medium     |
| [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)                                                 |                                           | Hard       |
| [N-Queens](https://leetcode.com/problems/n-queens/)                                                           |                                           | Hard       |

### Design

| Title                                                 | Solution                 | Difficulty |
| ----------------------------------------------------- | ------------------------ | ---------- |
| [LRU Cache](https://leetcode.com/problems/lru-cache/) | [C++](lru-cache/sol.cpp) | Medium     |
| [LFU Cache](https://leetcode.com/problems/lfu-cache/) | [C++](lfu-cache/sol.cpp) | Hard       |

## Reference

- [Interview Question Patterns](https://gist.github.com/jelliott8020)
- [Graph For Beginners](https://leetcode.com/discuss/general-discussion/655708/Graph-For-Beginners-Problems-or-Pattern-or-Sample-Solutions)
