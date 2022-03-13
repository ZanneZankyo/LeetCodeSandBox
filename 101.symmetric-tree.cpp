/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (51.08%)
 * Likes:    8866
 * Dislikes: 220
 * Total Accepted:    1.2M
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given the root of a binary tree, check whether it is a mirror of itself
 * (i.e., symmetric around its center).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,2,3,4,4,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,2,null,3,null,3]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 1000].
 * -100 <= Node.val <= 100
 * 
 * 
 * 
 * Follow up: Could you solve it both recursively and iteratively?
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
    bool symmetricComp(TreeNode *a, TreeNode *b){
        if(a == nullptr && b == nullptr){
            return true;
        }
        if((a == nullptr && b != nullptr) || (a != nullptr && b == nullptr)){
            return false;
        }
        if(a->val != b->val){
            return false;
        }
        return symmetricComp(a->left, b->right) && symmetricComp(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return false;
        }
        return symmetricComp(root->left, root->right);
    }
};
// @lc code=end

