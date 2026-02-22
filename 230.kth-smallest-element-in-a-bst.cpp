/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 *
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
 *
 * algorithms
 * Medium (76.47%)
 * Likes:    12618
 * Dislikes: 260
 * Total Accepted:    2.2M
 * Total Submissions: 2.8M
 * Testcase Example:  '[3,1,4,null,2]\n1'
 *
 * Given the root of a binary search tree, and an integer k, return the k^th
 * smallest value (1-indexed) of all the values of the nodes in the tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,1,4,null,2], k = 1
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,3,6,2,4,null,null,1], k = 3
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is n.
 * 1 <= k <= n <= 10^4
 * 0 <= Node.val <= 10^4
 * 
 * 
 * 
 * Follow up: If the BST is modified often (i.e., we can do insert and delete
 * operations) and you need to find the kth smallest frequently, how would you
 * optimize?
 * 
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
    void step(TreeNode* node) {
        if (node->left != nullptr) {
            step(node->left);
        }
        if (current == target) {
            return;
        }
        else {
            ++current;
            if (current == target) {
                result = node->val;
                return;
            }
        }
        if (node->right != nullptr) {
            step(node->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        current = 0;
        target = k;
        if (root != nullptr){
            step(root);
        }
        return result;
    }
    int result = 0;
    int target = 0;
    int current = 0;
};
// @lc code=end

// [3,1,4,null,2]\n4

