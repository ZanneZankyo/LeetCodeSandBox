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

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newHead = nullptr;
        ListNode* cur = nullptr;
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        while(cur1 || cur2){
            bool use1 = (cur1 && cur2 && cur1->val < cur2->val) || (cur1 && !cur2);
            ListNode* newNode = nullptr;
            if(use1){
                newNode = cur1;
                cur1 = cur1->next;
            }
            else{
                newNode = cur2;
                cur2 = cur2->next;
            }
            if(!newHead){
                newHead = newNode;
                cur = newHead;
            }
            else{
                cur->next = newNode;
                cur = cur->next;
            }
        }
        return newHead;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.empty())
            return nullptr;

        int pair = 2;
        int skip = 1;
        while(skip < lists.size()){
            for(int i = 0; i+skip < lists.size(); i+=pair){
                //cout<<i << " x "<<i+skip<<" | ";
                lists[i] = mergeTwoLists(lists[i], lists[i+skip]);
            }
            pair *= 2;
            skip *= 2;
        }
        return lists[0];
    }
};

#if 0 //14%

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode headNoInclude(0x80000000);
        ListNode *min = &headNoInclude;
        //ListNode *current = min;
        while(!lists.empty()){
            ListNode* newMin = nullptr;
            for(int i = 0 ; i < lists.size(); ++i){
                if(!lists[i]){
                    lists.erase(lists.begin() + i);
                    --i;
                    continue;
                }

                if(!newMin){
                    newMin = lists[i];
                }
                else if(lists[i]->val < newMin->val){
                    newMin = lists[i];
                }

                ListNode *current = min;
                bool hasInserted = false;
                while(current->next){
                    if(current->val <= lists[i]->val && current->next->val >= lists[i]->val){
                        ListNode* currentNext = current->next;
                        ListNode* newList = lists[i];
                        lists[i] = lists[i]->next;
                        current->next = newList;
                        newList->next = currentNext;
                        hasInserted = true;
                        break;
                    }
                    current = current->next;
                }
                if(!hasInserted){
                    ListNode* currentNext = current->next;
                    ListNode* newList = lists[i];
                    lists[i] = lists[i]->next;
                    current->next = newList;
                    newList->next = currentNext;
                }

            }
            min = newMin;
            //if(newMin)
            //    cout<<newMin->val<<'|';
        }
        return headNoInclude.next;
    }
};

#endif

#if 0 //runtime 21% O(n * length)

class Solution {
public:

    struct ListListNode{
        ListNode* node;
        ListListNode* next;
        ListListNode(ListNode* n) : node(n), next(nullptr){}
    };

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
            //cout<<"<-"<<top->node->val;
            top->node = top->node->next;
            top->next = nullptr;
            sortedLists = insertSortedList(others, top);
        }
        return result;
    }
};

#endif

#if 0 //runtime 7% O(n*listLength)
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

