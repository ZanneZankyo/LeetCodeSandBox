/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBSTNode(long min, long max, TreeNode* node){
        if((node->val <= min) || (node->val >= max)){
            return false;
        }
        bool childrenResult = true;
        if(node->left != nullptr){
            childrenResult &= isValidBSTNode(min, node->val, node->left);
        }
        if(node->right != nullptr){
            childrenResult &= isValidBSTNode(node->val, max, node->right);
        }
        return childrenResult;
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr)
            return true;
        return isValidBSTNode(0x8000000000000000, 0x7fffffffffffffff, root);
    }
};

