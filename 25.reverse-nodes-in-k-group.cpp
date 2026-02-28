/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (65.31%)
 * Likes:    15518
 * Dislikes: 799
 * Total Accepted:    1.5M
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given the head of a linked list, reverse the nodes of the list k at a time,
 * and return the modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes, in the end, should remain as it is.
 * 
 * You may not alter the values in the list's nodes, only nodes themselves may
 * be changed.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is n.
 * 1 <= k <= n <= 5000
 * 0 <= Node.val <= 1000
 * 
 * 
 * 
 * Follow-up: Can you solve the problem in O(1) extra memory space?
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#define ZANKYO_DEBUG 0
#include <vector>
using namespace std;
#if ZANKYO_DEBUG
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif
// 100% time 38% mem
class Solution {
public:
    ListNode* step1(ListNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        ListNode *thisHead = step2(node, nullptr, 0);
        if (nextStart != nullptr) {
            ListNode *nextHead = step1(nextStart);
            node->next = nextHead;
        }
        else if (thisHead == nullptr) {
            thisHead = node;
        }
        return thisHead;
    }
    ListNode* step2(ListNode* node, ListNode* prev, int n) {
        if (node == nullptr) {
            nextStart = nullptr;
            return nullptr;
        }
        //ListNode* next = node->next;
        
        ListNode* result = node;
        if (n+1 == K) {
            //thisHead = node;
            if (!firstReverse) {
                finalHead = node;
                firstReverse = true;
            }
            nextStart = node->next;
            result = node;
        }
        else {
            result = step2(node->next, node, n+1);
        }
        if (result != nullptr) {
            node->next = prev;
        }
        return result;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }
        K = k;
        finalHead = head;
        step1(head);
        return finalHead;
    }
    int K = 0;
    ListNode *finalHead = nullptr;
    //ListNode *thisHead = nullptr;
    ListNode *nextStart = nullptr;
    bool firstReverse = false;
};
// @lc code=end

#if ZANKYO_DEBUG
#include <iostream>
ListNode *vectorToListNode(vector<int>& v) {
    ListNode *head = nullptr;
    ListNode *node = nullptr;
    for (int i = 0; i < v.size(); ++i) {
        ListNode *newNode = new ListNode(v[i]);
        if (node != nullptr) {
            node->next = newNode;
        }
        node = newNode;
        if (head == nullptr) {
            head = node;
        }
    }
    return head;
}
void releaseNodes(ListNode *node) {
    if (node == nullptr) {
        return;
    }
    releaseNodes(node->next);
    delete node;
}
void printNodes(ListNode *node, int n = 0) {
    if (node == nullptr) {
        return;
    }
    if (n > 0) {
        cout << ',';
    }
    cout << node->val;
    printNodes(node->next, n+1);
    if (n == 0) {
        cout << endl;
    }
}
void main() {
    Solution s;
    /*{
        vector<int> v({1,2,3,4,5});
        ListNode *n = vectorToListNode(v);
        n = s.reverseKGroup(n, 3);
        printNodes(n);
        releaseNodes(n);
    }*/
    {
        vector<int> v({1,2,3,4});
        ListNode *n = vectorToListNode(v);
        n = s.reverseKGroup(n, 2);
        printNodes(n);
        releaseNodes(n);
    }
}
#endif

