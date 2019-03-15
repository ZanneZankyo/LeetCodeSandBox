/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (30.69%)
 * Total Accepted:    788.4K
 * Total Submissions: 2.6M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* currentNode = result;
        int carry = 0;

        while(l1 != NULL || l2 != NULL)
        {
            int val;
            if(l1 && l2)
                val = l1->val + l2->val + carry;
            else if(l1 && !l2)
                val = l1->val + carry;
            else if(!l1 && l2)
                val = l2->val + carry;
            carry = val / 10;
            val %= 10;
            ListNode* newNode = new ListNode(val);
            if(!result)
            {
                result = newNode;
                currentNode = newNode;
            }
            else
            {
                currentNode->next = newNode;
                currentNode = currentNode->next;
            }
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry)
            currentNode->next = new ListNode(carry);
        return result;

    }
};

