# Interview Question Patterns

## [Coding Pattern](https://emre.me/categories/#coding-patterns)

## Patterns
- [1D and 2D Array](#1D-and-2D-Array)
- [String](#String)
- [Sliding Window](#Sliding-Window)
- [Two Pointers](#Two-Pointers-or-Iterators)
- [Fast and Slow Pointers](#Fast-and-Slow-Pointers)
- [Intervals](#Intervals)
- [Cyclic Sort](#Cyclic-Sort)
- [Linked List](#Linked-List)
- [BFS](#BFS)
- [DFS](#DFS)
- [BFS or DFS](#BFS-or-DFS)
- [Heaps](#Heaps)
- [Subsets](#Subsets)
- [Binary Search](#Modified-Binary-Search)
- [Topological Sort](#Topological-Sort)
- [Binary and Bitwise Operations](#Binary-&-Bitwise-XOR)
- [Trie](#Trie)
- [Dynamic Programming](#Dynamic-Programming)
- [Backtracking](#Backtracking)

## About
This is a collection of common interview patterns and questions used to prepare for interviews. The point of this collection is to focus on **quality** rather than **quantity**.  If we just blindly shotgun hundred of problems, we may run into problems we've never seen before and are unsure on how to solve them from an abstract, theorectical standpoint.  

_For example, we may have a toolbox full of tools but are unsure of which problems those tools solve. We could run into a problem of trying to attach a board to another with a screw. Could we hammer the screw? Sure, O(n<sup>2</sup>). Could we hit it with a level? Sure, (Time limit exceded). A better solution is to use a screwdriver. O(nlogn). An even more optimal solution is to use a drill O(n)._  

This illustrates that if we just do a bunch of problems, we know we need to get the screw to attach both boards. But knowing the theory of the problems shows us which _tool_ to use.

### Question selection
Questions are gathered from a mix of currated lists and frequently asked questions on leetcode. The majority will be LC Medium difficulty (7-10), with 2-3 easy and 2-3 hard. Feel free to skip the easy or hard, the mediums will be where you get the most bang for your buck.

### References
**Patterns**  
[HackerNoon](https://hackernoon.com/14-patterns-to-ace-any-coding-interview-question-c5bb3357f6ed)  

**Other References:**  
[Grokking the Coding Interview](https://www.educative.io/courses/grokking-the-coding-interview) (Course)  
[Team Blind 75](https://www.teamblind.com/post/New-Year-Gift---Curated-List-of-Top-75-LeetCode-Questions-to-Save-Your-Time-OaM1orEU) (List)  
[Cracking The Coding Interview](https://www.amazon.com/Cracking-Coding-Interview-Programming-Questions/dp/0984782850/ref=sr_1_1?crid=FNKSJQH1QNFP&dchild=1&keywords=cracking+the+coding+interview&qid=1599937209&sprefix=cracking+the+co%2Caps%2C144&sr=8-1) (Book)  
[Elements of Programming Interviews](https://www.amazon.com/Elements-Programming-Interviews-Java-Insiders/dp/1517435803/) (Book, also comes in C++ and Python)  

## Problem Solving Strategies
- Pay attention to the problem description.
- Input -> Is it sorted? Duplicates allowed? Size/range? How to handle null? Invalid input?
- Output -> Return type?
- Do you need to keep track of unique characters? HashSet

## Patterns
### 1D and 2D Array
<!-- [x] means finish -->
#### Easy
- [ ] [Contains Duplicate](https://leetcode.com/problems/contains-duplicate/)
- [ ] [Two Sum](https://leetcode.com/problems/two-sum/)
#### Medium
- [x] [Find All Duplicates in an Array](https://leetcode.com/problems/find-all-duplicates-in-an-array/)
 - hash table
- [x] [Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self/)
 - use division
- [x] [Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)
 - dp
- [ ] [One Edit Distance](https://leetcode.com/problems/one-edit-distance/)
- [x] [String Compression](https://leetcode.com/problems/string-compression/)
- [ ] [Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
- [ ] [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)
- [ ] [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)
- [ ] [Rotate Image](https://leetcode.com/problems/rotate-image/)
- [ ] [ZigZag Conversion](https://leetcode.com/problems/zigzag-conversion/)
#### Hard

---
### String
#### Easy
- [ ] [Valid Anagram](https://leetcode.com/problems/valid-anagram/)
- [ ] [Valid Parentheses](https://leetcode.com/problems/valid-parentheses/)
- [ ] [Valid Palindrome](https://leetcode.com/problems/valid-palindrome/)
#### Medium
- [x] [Group Anagrams](https://leetcode.com/problems/group-anagrams/)
 - hash table
 - notice that anagram are with same num of alphabet
- [x] [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
 - palindromic has a center
 - Manacher's Algorithm
   - https://havincy.github.io/blog/post/ManacherAlgorithm/
   - https://www.zhihu.com/question/30226229
   - http://manacher-viz.s3-website-us-east-1.amazonaws.com/#/
- [x] [Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/)
 - palindromic has a center
 - Manacher's Algorithm
- [ ] [Encode and Decode Strings](https://leetcode.com/problems/encode-and-decode-strings/)
#### Hard

---
### Sliding Window
https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems   
https://medium.com/leetcode-patterns/leetcode-pattern-2-sliding-windows-for-strings-e19af105316b   
https://emre.me/coding-patterns/sliding-window/   

#### Easy
#### Medium
- [x] [Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/)
 - dp, but time complexity: O(mn), m=target, n=len
 - sliding window, complexity: O(n)
- [x] [Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/)
 - sliding window
- [x] [Permutation in String](https://leetcode.com/problems/permutation-in-string/)
 - sliding window
- [ ] [Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/)
- [ ] [Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)
- [ ] [Longest Continuous Subarray with Abs Diff <= Limit](https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/)
- [ ] [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/)
- [ ] [Max Points You Can Obtain From Cards](https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/)
- [ ] [Longest Substring with at Most Two Distinct Characters](https://leetcode.com/problems/longest-substring-with-at-most-two-distinct-characters/)
- [ ] [Number of Subsequences that Satisfy the Given Sum Condition](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/)
- [ ] [Grumpy Bookstore Owner](https://leetcode.com/problems/grumpy-bookstore-owner/)

#### Hard
- [ ] [Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
- [ ] [Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)
- [ ] [Minimum Number of K Consecutive Bit Flips](https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/)
- [ ] [Count Unique Characters of All Substrings of a Given String](https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/)
- [ ] [Substring with Concatenation of All Words](https://leetcode.com/problems/substring-with-concatenation-of-all-words/)

---
### Two Pointers or Iterators
https://emre.me/coding-patterns/two-pointers/
#### Easy
- [ ] [Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)
- [x] [Two Sum](https://leetcode.com/problems/two-sum/)
 - hash table
- [ ] [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)
- [ ] [Backspace String Compare](https://leetcode.com/problems/backspace-string-compare)
#### Medium
- [x] [Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)
 - hash table
- [x] [3 Sum](https://leetcode.com/problems/3sum/)
 - both hash table & two pointer
- [x] [3 Sum Closest](https://leetcode.com/problems/3sum-closest/)
 - two pointer
- [ ] [Subarrays with Product Less than K](https://leetcode.com/problems/subarray-product-less-than-k/)
- [ ] [Sort Colors](https://leetcode.com/problems/sort-colors/)
- [x] [Container With Most Water](https://leetcode.com/problems/container-with-most-water/)
 - two pointer
#### Hard
- [ ] [Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

---
### Fast and Slow Pointers
https://emre.me/coding-patterns/fast-slow-pointers/
#### Easy
- [ ] [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)
- [ ] [Middle of the Linked List](https://leetcode.com/problems/middle-of-the-linked-list/)
- [ ] [Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)
- [ ] [Remove Linked List Elements](https://leetcode.com/problems/remove-linked-list-elements/)
- [ ] [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)
#### Medium
- [x] [Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)
 - fast-slow pointers
- [x] [Remove Duplicated from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)
- [ ] [Add Two Numbers](https://leetcode.com/problems/add-two-numbers/)
- [ ] [Add Two Number II](https://leetcode.com/problems/add-two-numbers-ii/)
- [ ] [Remove Nth Node From End Of List](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)
- [ ] [Sort List](https://leetcode.com/problems/sort-list/)
 - merge sort
- [ ] [Reorder List](https://leetcode.com/problems/reorder-list/)
 - using fast-slow pointer to find middle
 - reverse the half after middle 1->2->3->6->5->4
 - reoder 1->6->2->5->3->4
#### Hard


---
### Intervals
https://emre.me/coding-patterns/merge-intervals/  
#### Easy
- [ ] [Meeting Rooms](https://leetcode.com/problems/meeting-rooms)
#### Medium
- [ ] [Meeting Rooms II](https://leetcode.com/problems/meeting-rooms-ii/)
- [x] [Merge Intervals](https://leetcode.com/problems/merge-intervals/)
- [x] [Interval List Intersections](https://leetcode.com/problems/interval-list-intersections/)
- [x] [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)
- [x] [Minimum Number of Arrows to Burst Balloons](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/)
#### Hard
- [ ] [Insert Interval](https://leetcode.com/problems/insert-interval/)

---
### Cyclic Sort
https://emre.me/coding-patterns/cyclic-sort/  
#### Easy
- [x] [Find all missing numbers](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
 - use negtive
#### Medium
#### Hard
- [x] [First Missing Positive](https://leetcode.com/problems/first-missing-positive/)
 - use swap
---
### Linked List
https://emre.me/coding-patterns/in-place-reversal-of-a-linked-list/  

#### Easy
- [ ] [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)
- [ ] [Intersection](https://leetcode.com/problems/intersection-of-two-linked-lists/)
#### Medium
- [x] [Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)
- [x] [Rotate List](https://leetcode.com/problems/rotate-list/)
- [ ] [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)
- [ ] [Odd Even Linked List](https://leetcode.com/problems/odd-even-linked-list/)
- [ ] [Partition Linked List](https://leetcode.com/problems/partition-list/)
#### Hard
- [ ] [Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)

---
### BFS
https://emre.me/coding-patterns/breadth-first-search/
#### Easy
- [ ] [Binary Tree Level Order Traversal II](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)
- [ ] [Average of Levels in Binary Tree](https://leetcode.com/problems/average-of-levels-in-binary-tree/)
#### Medium
- [x] [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/)
 - use queue
- [ ] [Binary Tree Zigzag Level Order Traversal](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)
- [ ] [Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node/)
- [ ] [Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)
#### Hard

---
### DFS
https://emre.me/coding-patterns/depth-first-search/  
_make sure you can solve dfs both recursively **and** iteratively_
#### Easy
- [ ] [Invert Binary Tree](https://leetcode.com/problems/invert-binary-tree/)
- [ ] [Path Sum](https://leetcode.com/problems/path-sum/)
- [ ] [Same Tree](https://leetcode.com/problems/same-tree/)
- [ ] [Diameter of Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)
- [ ] [Merge Two Binary Trees](https://leetcode.com/problems/merge-two-binary-trees/)
- [ ] [Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/)
- [ ] [Lowest Common Ancestor of a Binary Search Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)
- [ ] [Subtree of Another Tree](https://leetcode.com/problems/subtree-of-another-tree/)
#### Medium
- [ ] [Path Sum II](https://leetcode.com/problems/path-sum-ii/)
- [ ] [Path Sum III](https://leetcode.com/problems/path-sum-iii/)
- [ ] [Kth Smallest Element in a BST](https://leetcode.com/problems/kth-smallest-element-in-a-bst/)
- [ ] [Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)
- [ ] [Maximum Binary Tree](https://leetcode.com/problems/maximum-binary-tree/)
- [ ] [Maximum Width of Binary Tree](https://leetcode.com/problems/maximum-width-of-binary-tree/)
- [ ] [Construct Binary Tree from Preorder and Inorder Traversal](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)
- [ ] [Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/)
- [ ] [Target Sum](https://leetcode.com/problems/target-sum/)
- [ ] [Split BST](https://leetcode.com/problems/split-bst/)
#### Hard
- [ ] [Word Search](https://leetcode.com/problems/word-search-ii/)
- [ ] [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)


---
### BFS or DFS
#### Easy
- [ ] [Minimum Depth of Binary Tree](https://leetcode.com/problems/minimum-depth-of-binary-tree/)
- [ ] [Convert Sorted Array to BST](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/)
#### Medium
- [ ] [Clone Graph](https://leetcode.com/problems/clone-graph/)
- [ ] [Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/)
- [ ] [Number of Islands](https://leetcode.com/problems/number-of-islands/)
- [ ] [Graph Valid Tree](https://leetcode.com/problems/graph-valid-tree/)
- [ ] [Number of Connected Components in an Undirected Graph](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)
- [ ] [Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)
- [ ] [All Nodes Distance K in Binary Tree](https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/)
- [x] [Max Area of Island](https://leetcode.com/problems/max-area-of-island/)
- [x] [Word Ladder](https://leetcode.com/problems/word-ladder/)
#### Hard
- [x] [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)
- [ ] [Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/)

---
### Heaps
https://emre.me/coding-patterns/k-way-merge/  
https://emre.me/coding-patterns/top-k-numbers/  
https://emre.me/coding-patterns/two-heaps/  
#### Easy
#### Medium
- [x] [Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/)
 - kth smallest element in 2d matrix
- [x] [Task Scheduler](https://leetcode.com/problems/task-scheduler/)
 - try examples and find the pattern
- [x] [Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/)
 - bucket sort
- [x] [Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/)
 - top k: using priority queue(heap)
    - time complexity: O(nlogk)
 - however, the range of the array we want to sort is bounded
 - we can use bucket sort
    - time complexity: O(n)
- [ ] [Kth Largest Element](https://leetcode.com/problems/kth-largest-element-in-an-array/)
- [ ] [K Closests Points to Origin](https://leetcode.com/problems/k-closest-points-to-origin/)
- [ ] [Reorganize String](https://leetcode.com/problems/reorganize-string/)
#### Hard
- [ ] [Employee Free Time](https://leetcode.com/problems/employee-free-time/)
- [ ] [Smallest Range Covering Elements from K Lists](https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/) 
- [ ] [Rearrange String k Distance Apart](https://leetcode.com/problems/rearrange-string-k-distance-apart)
- [ ] [Course Schedule III](https://leetcode.com/problems/course-schedule-iii/)
- [ ] [Maximum Frequency Stack](https://leetcode.com/problems/maximum-frequency-stack/)
- [ ] [Find Median from Data Stream](https://leetcode.com/problems/find-median-from-data-stream/)
- [ ] [Sliding Window Median](https://leetcode.com/problems/sliding-window-median/)
- [ ] [Merge K Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/)

---
### Subsets
https://emre.me/coding-patterns/subsets/  
https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)  

#### Easy
#### Medium
- [x] [Subsets](https://leetcode.com/problems/subsets/)
- [x] [Subsets II](https://leetcode.com/problems/subsets-ii/)
- [x] [Permutations](https://leetcode.com/problems/permutations/)
- [ ] [Permutations II](https://leetcode.com/problems/permutations-ii/)
- [ ] [Palindrome Permuations](https://leetcode.com/problems/palindrome-permutation-ii/)
- [ ] [Letter Case Permutation](https://leetcode.com/problems/letter-case-permutation/)
#### Hard

---
### Modified Binary Search
https://emre.me/coding-patterns/modified-binary-search/
#### Easy
- [x] [Binary Search](https://leetcode.com/problems/binary-search/)
- [ ] [Find Smallest Letter Greater Than Target](https://leetcode.com/problems/find-smallest-letter-greater-than-target/)
- [ ] [Peak Index in a Mountain Array](https://leetcode.com/problems/peak-index-in-a-mountain-array/)
#### Medium
- [x] [Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)
 - priority queue
- [x] [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)
 - analysis boundary with simple case
 - [0, 1, 2], [1, 2, 0], [2, 0, 1]
- [x] [Find Peak Element](https://leetcode.com/problems/find-peak-element/)
 - simulate the process, and find the pattern
- [x] [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/)
 - analysis boundary with simple case
 - [0, 1, 2], [1, 2, 0], [2, 0, 1]
- [ ] [Search in Rotated Sorted Array II](https://leetcode.com/problems/search-in-rotated-sorted-array-ii/)
- [ ] [Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)
- [ ] [Search a 2D Matrix II](https://leetcode.com/problems/search-a-2d-matrix-ii/)
- [ ] [Find K Closest Elements](https://leetcode.com/problems/find-k-closest-elements/)
- [ ] [Capacity to Ship Packages Within D Days](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)
#### Hard
- [ ] [Count of Range Sum](https://leetcode.com/problems/count-of-range-sum/)


---
### Topological Sort
https://emre.me/coding-patterns/topological-sort/
#### Easy
#### Medium
- [x] [Course Schedule](https://leetcode.com/problems/course-schedule/)
 - topological sort, push when indegree = 0
- [x] [Course Schedule II](https://leetcode.com/problems/course-schedule-ii/)
 - topological sort, push when indegree = 0
- [ ] [Minimum Height Trees](https://leetcode.com/problems/minimum-height-trees/)
- [ ] [Sequence Reconstruction](https://leetcode.com/problems/sequence-reconstruction)
#### Hard
- [ ] [Sort Items by Groups Respecting Dependencies](https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/)
- [ ] [Alien Dictionary](https://leetcode.com/problems/alien-dictionary)

---
### Binary & Bitwise XOR
https://emre.me/coding-patterns/bitwise-xor/
#### Easy
- [x] [Single Number](https://leetcode.com/problems/single-number/)
 - a xor a = 0
- [ ] [Missing Number](https://leetcode.com/problems/missing-number/)
- [ ] [Complement of Base 10](https://leetcode.com/problems/complement-of-base-10-integer/)
- [ ] [Number of 1 Bits](https://leetcode.com/problems/number-of-1-bits/)
- [ ] [Reverse Bits](https://leetcode.com/problems/reverse-bits/)
#### Medium
- [x] [Single Number II](https://leetcode.com/problems/single-number-ii/)
 - find the operation s.t. a @ a @ a = 0
 - start from the simplest case
- [x] [Single Number III](https://leetcode.com/problems/single-number-iii/)
 - retry the parttern of [single number]
 - try the simplest case, [1, 2, 3, 3]
 - use the clue of a ^ b
- [x] [Sum of Two Integers](https://leetcode.com/problems/sum-of-two-integers/)
 - start from the simplest case
- [x] [Counting Bits](https://leetcode.com/problems/counting-bits/)
 - observe the pattern
- [ ] [Pow(x,n)](https://leetcode.com/problems/powx-n/)
- [ ] [Kth Symbol in Grammar](https://leetcode.com/problems/k-th-symbol-in-grammar/)
#### Hard


---
### Trie
#### Easy
- [ ] [Longest Word in Dictionary](https://leetcode.com/problems/longest-word-in-dictionary/)
- [ ] [Index Pairs of a String](https://leetcode.com/problems/index-pairs-of-a-string/)
#### Medium
- [x] [Implement Trie (Prefix Tree)](https://leetcode.com/problems/implement-trie-prefix-tree/)
 - data structure
- [x] [Maximum XOR of Two Numbers in an Array](https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array)
 - dont try to find the best solution first
 - sometimes your solution is just the best
 - or you can improve it later
- [ ] [Add and Search Word](https://leetcode.com/problems/add-and-search-word-data-structure-design/)
#### Hard
- [ ] [Concatenated Words](https://leetcode.com/problems/concatenated-words/)
- [ ] [Prefix and Suffix Search](https://leetcode.com/problems/prefix-and-suffix-search/)
- [ ] [Palindrome Pairs](https://leetcode.com/problems/palindrome-pairs/)
- [ ] [Design Search Autocomplete System](https://leetcode.com/problems/design-search-autocomplete-system/)
- [ ] [Word Squares](https://leetcode.com/problems/word-squares/)

---
### Dynamic Programming
https://emre.me/coding-patterns/longest-common-substring-subsequence/  
https://emre.me/coding-patterns/palindromes/  
https://emre.me/coding-patterns/staircase/  
https://emre.me/coding-patterns/knapsack/  
#### Easy
- [ ] [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
- [ ] [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
- [ ] [House Robber](https://leetcode.com/problems/house-robber/)
- [x] [Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
#### Medium
- [x] [Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)
 - use the concept of FSM
- [ ] [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) 
- [x] [Coin Change](https://leetcode.com/problems/coin-change/)
- [x] [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
 - simulate the process, and find the pattern
- [x] [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)
- [x] [Word Break](https://leetcode.com/problems/word-break/)
- [x] [Combination Sum](https://leetcode.com/problems/combination-sum/)
 - can reuse
- [x] [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)
 - cant duplicate
- [x] [Combination Sum III](https://leetcode.com/problems/combination-sum-iii/)
 - can duplicate, but cant reuse
- [x] [Combination Sum IV](https://leetcode.com/problems/combination-sum-iv/)
 - can reuse
- [x] [House Robber II](https://leetcode.com/problems/house-robber-ii/)
- [x] [Decode Ways](https://leetcode.com/problems/decode-ways/)
- [x] [Unique Paths](https://leetcode.com/problems/unique-paths/)
- [x] [Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)
- [ ] [Jump Game](https://leetcode.com/problems/jump-game/)
- [ ] [Paint Fence](https://leetcode.com/problems/paint-fence/)
#### Hard


---
### Backtracking  
https://leetcode.com/problems/subsets/discuss/27281/A-general-approach-to-backtracking-questions-in-Java-(Subsets-Permutations-Combination-Sum-Palindrome-Partitioning)  

#### Easy
#### Medium
- [x] [Combinations](https://leetcode.com/problems/combinations/)
 - using recursive
- [x] [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)
 - count of '(' >= count of ')'
- [x] [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)
 - every Palindrome have a center
- [x] [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)
- [ ] [Generalized Abbreviation](https://leetcode.com/problems/generalized-abbreviation/)
- [x] [Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)
 - the sum for each partition is known
- [x] [Partition to K Equal Sum Subsets](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/)
 - recursive target can also be an array
#### Hard
- [x] [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/)
- [ ] [N-Queens](https://leetcode.com/problems/n-queens/)

## Reference
[Interview Question Patterns](https://gist.github.com/jelliott8020)