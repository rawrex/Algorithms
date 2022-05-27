// 147. Insertion Sort List
// https://leetcode.com/problems/insertion-sort-list/
//
// Singly linked list, so we will go left to right due to the head being on the left
// We can make in-place or make a copy
struct ListNode {
int val;
ListNode *next;
ListNode() : val(0), next(nullptr) {}
ListNode(int x) : val(x), next(nullptr) {}
ListNode(int x, ListNode *next) : val(x), next(next) {}
};
