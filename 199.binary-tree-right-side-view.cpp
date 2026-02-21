/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#define MAX_NODE_COUNT 100
class Solution {
public:
    void step(TreeNode* node, int layer) {
        if (node != nullptr) {
            if (!layers[layer]) {
                layers[layer] = true;
                result.emplace_back(node->val);
            }
            
            step(node->right, layer + 1);
            step(node->left, layer + 1);
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        memset(layers, false, MAX_NODE_COUNT * sizeof(bool));
        result.clear();

        step(root, 0);
        return result;
    }
    vector<int> result;
    bool layers[MAX_NODE_COUNT];
};
// @lc code=end

