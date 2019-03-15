/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (33.23%)
 * Total Accepted:    350K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* newHead = nullptr;
        ListNode* newCur = nullptr;
        bool areAllEnd = lists.empty();
        while(!areAllEnd){
            int min;
            int minIndex;
            bool isMinSet = false;
            for(int i = 0; i < lists.size(); i++)
            {
                
                ListNode* cur = lists[i];
                if(!isMinSet && cur){
                    min = cur->val;
                    minIndex = i;
                    isMinSet = true;
                }
                if(cur && (cur->val < min)){
                    min = cur->val;
                    minIndex = i;
                }
                
            }
            if(!isMinSet){
                break;
            }
                
            if(!newHead){
                newHead = new ListNode(min);
                newCur = newHead;
            }
            else{
                newCur->next = new ListNode(min);
                newCur = newCur->next;
            }
            lists[minIndex] = lists[minIndex]->next;
            areAllEnd = true;
            for(ListNode* cur : lists){
                if(cur){
                    areAllEnd = false;
                    break;
                }
            }
        }
        return newHead;
    }
};

