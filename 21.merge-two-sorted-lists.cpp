/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (46.07%)
 * Total Accepted:    524.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newHead = nullptr;
        ListNode* cur = nullptr;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while(cur1 || cur2){
            bool use1 = (cur1 && cur2 && cur1->val < cur2->val) || (cur1 && !cur2);
            int newValue = 0;
            if(use1){
                newValue = cur1->val;
                cur1 = cur1->next;
            }
            else{
                newValue = cur2->val;
                cur2 = cur2->next;
            }
            if(!newHead){
                newHead = new ListNode(newValue);
                cur = newHead;
            }
            else{
                cur->next = new ListNode(newValue);
                cur = cur->next;
            }
        }
        return newHead;
    }
};

