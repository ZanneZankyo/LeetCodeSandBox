/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (46.30%)
 * Likes:    11869
 * Dislikes: 572
 * Total Accepted:    774.9K
 * Total Submissions: 1.7M
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * Given the root of a binary tree and an integer targetSum, return the number
 * of paths where the sum of the values along the path equals targetSum.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards (i.e., traveling only from parent nodes to child nodes).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * Output: 3
 * Explanation: The paths that sum to 8 are shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 1000].
 * -10^9 <= Node.val <= 10^9
 * -1000 <= targetSum <= 1000
 * 
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
#include <unordered_map>
class Solution { // 50% time 27% mem
public:
    void step(TreeNode *node, long prevSum) {
        if (node != nullptr) {
            long sum = prevSum + node->val;
            auto found = sums.find(sum - target);
            if (found != sums.end()) {
                result += found->second;
            }
            found = sums.find(sum);
            if (found != sums.end()) {
                ++(found->second);
            }
            else {
                sums.insert({sum, 1});
            }
            step(node->left, sum);
            step(node->right, sum);
            found = sums.find(sum);
            if (found != sums.end()) {
                --(found->second);
                if (found->second <= 0) {
                    sums.erase(found);
                }
            }
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        result = 0;
        target = targetSum;
        r = root;
        sums.clear();
        sums.insert({0,1});
        step(root, 0);
        return result;
    }
private:
    int result;
    int target;
    unordered_map<long, int> sums;
    TreeNode* r;
};
// @lc code=end

// [5,4,8,11,null,13,4,7,2,null,null,5,1]\n22\n[1]\n0\n[0,1,1]\n1\n[1,0,1,1,2,0,-1,0,1,-1,0,-1,0,1,0]\n2