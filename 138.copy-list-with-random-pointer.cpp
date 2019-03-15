/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 *
 * https://leetcode.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (25.94%)
 * Total Accepted:    227K
 * Total Submissions: 875K
 * Testcase Example:  '{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}'
 *
 * A linked list is given such that each node contains an additional random
 * pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input:
 * 
 * {"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}
 * 
 * Explanation:
 * Node 1's value is 1, both of its next and random pointer points to Node 2.
 * Node 2's value is 2, its next pointer points to null and its random pointer
 * points to itself.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You must return the copy of the given head as a reference to the cloned
 * list.
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *RecursiveCopy(RandomListNode *node){
        if(!node)
            return nullptr;
        RandomListNode * newNode = new RandomListNode(node->label);
        newNode->next = RecursiveCopy(node->next);
        return newNode;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return nullptr;
        RandomListNode *newHead = RecursiveCopy(head);
        RandomListNode *cur = head;
        RandomListNode *newCur = newHead;
        while(cur && newCur){
            if(cur->random){
                RandomListNode *i = newHead;
                RandomListNode *j = head;
                while(j && i && j!=cur->random){
                    j = j->next;
                    i = i->next;
                }
                if(i && j){
                    newCur->random = i;
                }
            }
            cur = cur->next;
            newCur = newCur->next;
        }
        return newHead;
    }
};

