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



#if 1 //21%

struct ListListNode{
    ListNode* node;
    ListListNode* next;
    ListListNode(ListNode* n) : node(n), next(nullptr){}
};

class Solution {
public:

    ListListNode* insertSortedList(ListListNode* head, ListListNode* newList){

        if(newList == nullptr || newList->node == nullptr){
            return head;
        }

        if(head == nullptr){
            return newList;
        }

        ListListNode* prev = nullptr;
        ListListNode* current = head;
        while(current){
            if(current->node->val >= newList->node->val){
                if(prev == nullptr){
                    newList->next = head;
                    head = newList;
                }else{
                    prev->next = newList;
                    newList->next = current;
                }
                return head;
            }
            prev = current;
            current = current->next;
        }
        if(prev == nullptr){
            return newList;
        }
        else{
            prev->next = newList;
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListListNode* sortedLists = nullptr;
        for(ListNode* node : lists){
            sortedLists = insertSortedList(sortedLists, new ListListNode(node));
        }
        ListNode* result = nullptr;
        ListNode* current = result;
        while(sortedLists){
            ListListNode* top = sortedLists;
            ListListNode* others = sortedLists->next;
            ListNode* newNode = top->node;
            if(result == nullptr){
                result = newNode;
                current = result;
            }
            else{
                current->next = newNode;
                current = newNode;
            }
            top->node = top->node->next;
            top->next = nullptr;
            sortedLists = insertSortedList(others, top);
            //cout<<"<-"<<sortedLists->node->val;
        }
        return result;
    }
};

#endif

#if 0 //7%
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
#endif

