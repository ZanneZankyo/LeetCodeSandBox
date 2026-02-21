/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
class Solution {
public:
    void step(TreeNode* node, vector<int>& nums, int sum) {
        nums.emplace_back(node->val);
        sum += node->val;
        if (node->left == nullptr && node->right == nullptr) {
            if (sum == target) {
                results.emplace_back(nums);
            }
        }
        else {
            if (node->left != nullptr) {
                step(node->left, nums, sum);
            }
            if (node->right != nullptr) {
                step(node->right, nums, sum);
            }
        }
        nums.pop_back();
        sum -= node->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        results.clear();
        nums.clear();
        target = targetSum;
        if (root != nullptr) {
            step(root, nums, 0);
        }
        return results;
    }
    vector<vector<int>> results;
    vector<int> nums;
    int target;
};
// @lc code=end

