/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 *
 * https://leetcode.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (35.46%)
 * Total Accepted:    238.5K
 * Total Submissions: 672.2K
 * Testcase Example:  '[1,2]'
 *
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2
 * Output: false
 * 
 * Example 2:
 * 
 * 
 * Input: 1->2->2->1
 * Output: true
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr){
            return true;
        }
        vector<int> list;
        ListNode* cur = head;
        while(cur != nullptr){
            list.push_back(cur->val);
            cur = cur->next;
        }
        bool palindrome = true;
        int end = list.size() / 2;
        for(int i = 0; i < end; ++i){
            if(list[i] != list[list.size() - 1 - i]){
                palindrome = false;
                break;
            }
        }
        
        return palindrome;
    }
};

