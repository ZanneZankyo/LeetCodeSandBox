/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (63.84%)
 * Likes:    12935
 * Dislikes: 413
 * Total Accepted:    1.2M
 * Total Submissions: 1.9M
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a linked list, return the list after sorting it in
 * ascending order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range [0, 5 * 10^4].
 * -10^5 <= Node.val <= 10^5
 * 
 * 
 * 
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
 * (i.e. constant space)?
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
#if ZANKYO_DEBUG
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif
class Solution { // 67% time 98% mem
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        int len = 0;
        ListNode *node = head;
        while (node != nullptr) {
            ++len;
            node = node->next;
        }
        int interval = 1;
        while (interval <= len) {
            ListNode *nextStart = head;
            ListNode *prevTail = nullptr;
            while (nextStart != nullptr) {
                ListNode *left = nextStart;
                ListNode *right = left;
                for (int i = 0; i < interval && right != nullptr; ++i){
                    if (i == interval - 1) {
                        ListNode *next = right->next;
                        right->next = nullptr;
                        right = next;
                    }
                    else {
                        right = right->next;
                    }
                }
                ListNode *tail = right;
                for (int i = 0; i < interval && tail != nullptr; ++i){
                    if (i == interval - 1) {
                        ListNode *next = tail->next;
                        tail->next = nullptr;
                        tail = next;
                    }
                    else {
                        tail = tail->next;
                    }
                }
                nextStart = tail;
                tail = nullptr;
                ListNode *top = nullptr;
                while (left != nullptr || right != nullptr) {
                    ListNode *in;
                    if (left == nullptr) {
                        in = right;
                    } 
                    else if (right == nullptr) {
                        in = left;
                    } 
                    else {
                        in = left->val < right->val ? left : right;
                    }
                    if (in == left) {
                        left = left->next;
                    }
                    else {
                        right = right->next;
                    }
                    if (top == nullptr) {
                        top = in;
                        tail = top;
                        if (left == head) {
                            head = top;
                        }
                    }
                    else {
                        tail->next = in;
                        tail = in;
                    }
                }
                if (prevTail != nullptr) {
                    prevTail->next = top;
                }
                prevTail = tail;
            }
            interval *= 2;
        }
        return head;
    }
#if 0 //TLE
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        minNode = nullptr;
        ListNode *node = head;
        while (head != nullptr) {
            ListNode *next = head->next;
            ListNode *pos = minNode;
            while(pos != nullptr && pos->val < head->val){
                if (pos->next == nullptr) {
                    break;
                }
                if (pos->next->val > head->val) {
                    break;
                }
                pos = pos->next;
            }
            if(pos == nullptr) {
                minNode = head;
                head->next = nullptr;
            }
            else {
                if (pos == minNode && head->val < pos->val){
                    minNode = head;
                    head->next = pos;
                }
                else {
                    head->next = pos->next;
                    pos->next = head;
                }
            }
            head = next;
        }

        return minNode;
    }
    ListNode* minNode = nullptr;
    #endif
};
// @lc code=end

#if ZANKYO_DEBUG
#include <iostream>
#include <vector>
using namespace std;
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
        vector<int> v({4,2,1,3});
        ListNode *n = vectorToListNode(v);
        n = s.sortList(n);
        printNodes(n);
        releaseNodes(n);
    }
}
#endif
