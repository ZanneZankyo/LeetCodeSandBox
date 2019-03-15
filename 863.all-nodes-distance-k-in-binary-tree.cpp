/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 *
 * https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/description/
 *
 * algorithms
 * Medium (45.73%)
 * Total Accepted:    17.9K
 * Total Submissions: 39K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n2'
 *
 * We are given a binary tree (with root node root), a target node, and an
 * integer value K.
 * 
 * Return a list of the values of all nodes that have a distance K from the
 * target node.  The answer can be returned in any order.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
 * 
 * Output: [7,4,1]
 * 
 * Explanation: 
 * The nodes that are a distance 2 from the target node (with value 5)
 * have values 7, 4, and 1.
 * 
 * 
 * 
 * Note that the inputs "root" and "target" are actually TreeNodes.
 * The descriptions of the inputs above are just serializations of these
 * objects.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The given tree is non-empty.
 * Each node in the tree has unique values 0 <= node.val <= 500.
 * The target node is a node in the tree.
 * 0 <= K <= 1000.
 * 
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int DistanceToTarget(TreeNode* node, TreeNode* target, int currentDistance){
        if(node == target)
            return currentDistance;
        if(!node)
            return -1;
        int leftDis = DistanceToTarget(node->left, target, currentDistance+1);
        int rightDis = DistanceToTarget(node->right, target, currentDistance+1);
        if(leftDis != -1)
            return leftDis;
        if(rightDis != -1)
            return rightDis;
        return -1;
        
    }
    void RecursiveDistanceToTarget(TreeNode* node, TreeNode* target, int K, int rootValue, vector<int>& result){
        if(!node)
            return;
        int distance = DistanceToTarget(node,target,0);
        if(distance != -1)
            rootValue = distance;
        if(distance == K)
            result.push_back(node->val);
        if(distance == -1 && rootValue == K)
            result.push_back(node->val);
        RecursiveDistanceToTarget(node->left, target, K, rootValue+1, result);
        RecursiveDistanceToTarget(node->right, target, K, rootValue+1, result);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        map<TreeNode*,int> distanceMap;
        vector<int> result;
        if(K == 0){
            result.push_back(target->val);
            return result;
        }
        RecursiveDistanceToTarget(root, target, K, -1, result);
        return result;
    }
};

