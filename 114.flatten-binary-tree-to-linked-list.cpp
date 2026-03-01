/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
 *
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (70.18%)
 * Likes:    13613
 * Dislikes: 599
 * Total Accepted:    1.4M
 * Total Submissions: 1.9M
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * Given the root of a binary tree, flatten the tree into a "linked
 * list":
 * 
 * 
 * The "linked list" should use the same TreeNode class where the right child
 * pointer points to the next node in the list and the left child pointer is
 * always null.
 * The "linked list" should be in the same order as a pre-order traversal of
 * the binary tree.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,5,3,4,null,6]
 * Output: [1,null,2,null,3,null,4,null,5,null,6]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [0]
 * Output: [0]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 2000].
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * Follow up: Can you flatten the tree in-place (with O(1) extra space)?
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
class Solution { // 100% time 51% mem
public:
    TreeNode* step(TreeNode* node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return node;
        }
        TreeNode* left = step(node->left);
        TreeNode* right = step(node->right);
        TreeNode* leftTail;
        if (left != nullptr) {
            node->right = left;
            leftTail = left;
            while(leftTail->right != nullptr) leftTail = leftTail->right;
        }
        else {
            leftTail = node;
        }
        leftTail->right = right;
        node->left = nullptr;
        return node;
    }
    void flatten(TreeNode* root) {
        root = step(root);
    }
};
// @lc code=end

