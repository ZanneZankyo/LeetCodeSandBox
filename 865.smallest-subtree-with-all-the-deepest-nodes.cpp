/*
 * @lc app=leetcode id=865 lang=cpp
 *
 * [865] Smallest Subtree with all the Deepest Nodes
 *
 * https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/description/
 *
 * algorithms
 * Medium (54.51%)
 * Total Accepted:    14.9K
 * Total Submissions: 27.3K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]'
 *
 * Given a binary tree rooted at root, the depth of each node is the shortest
 * distance to the root.
 * 
 * A node is deepest if it has the largest depth possible among any node in the
 * entire tree.
 * 
 * The subtree of a node is that node, plus the set of all descendants of that
 * node.
 * 
 * Return the node with the largest depth such that it contains all the deepest
 * nodes in its subtree.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,5,1,6,2,0,8,null,null,7,4]
 * Output: [2,7,4]
 * Explanation:
 * 
 * 
 * 
 * We return the node with value 2, colored in yellow in the diagram.
 * The nodes colored in blue are the deepest nodes of the tree.
 * The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of
 * the given tree.
 * The output "[2, 7, 4]" is a serialization of the subtree rooted at the node
 * with value 2.
 * Both the input and output have TreeNode type.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the tree will be between 1 and 500.
 * The values of each node are unique.
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
    bool canAccessAllNode(const vector<TreeNode*>& deepNodes, TreeNode* node)
    {
        vector<bool> canVisit;
        canVisit.resize(deepNodes.size(), false);
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty())
        {
            TreeNode* n = q.front();
            q.pop();
            for(int i = 0 ; i < deepNodes.size(); i++)
                if(n == deepNodes[i])
                    canVisit[i] = true;
            if(n->left)
                q.push(n->left);
            if(n->right)
                q.push(n->right);
        }
        for(bool c : canVisit)
            if(!c)
                return false;
        return true;
    }
    TreeNode* recursiveFindSubTree(const vector<TreeNode*>& deepNodes, TreeNode* node)
    {
        if(!node)
            return nullptr;
        TreeNode* result = nullptr;
        if(canAccessAllNode(deepNodes, node))
            result = node;
        TreeNode* left = recursiveFindSubTree(deepNodes, node->left);
        if(left)
            return left;
        TreeNode* right = recursiveFindSubTree(deepNodes, node->right);
        if(right)
            return right;
        return result;
    }
    void recursiveFindDeepNodes(int& outMaxDepth, vector<TreeNode*>& outDeepNodes , TreeNode* node, int currentDepth)
    {
        if(!node->left && !node->right)
        {
            if(currentDepth > outMaxDepth)
            {
                outMaxDepth = currentDepth;
                outDeepNodes.clear();
                outDeepNodes.push_back(node);
            }
            else if(currentDepth == outMaxDepth)
            {
                outDeepNodes.push_back(node);
            }
        }
        if(node->left)
            recursiveFindDeepNodes(outMaxDepth,outDeepNodes,node->left,currentDepth+1);
        if(node->right)
            recursiveFindDeepNodes(outMaxDepth,outDeepNodes,node->right,currentDepth+1);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> deepNodes;
        int maxDepth = 0;
        recursiveFindDeepNodes(maxDepth,deepNodes,root,0);
        return recursiveFindSubTree(deepNodes,root);
    }
};

class Solution2 {
public:
    bool IsEnd(TreeNode* node){
        return (!node->left && !node->right);
    }
    void recursive(int& outMaxDepth, TreeNode* & outSubTree ,TreeNode* root, TreeNode* node, int currentDepth)
    {
        
        if(!node)
            return;
        
        if(node->left)
        {
            bool isLeftEnd = IsEnd(node->left);
            if(isLeftEnd && currentDepth > outMaxDepth)
            {
                outMaxDepth = currentDepth;
                outSubTree = node;
            }
            recursive(outMaxDepth, outSubTree, root, node->left, currentDepth+1);
        }
        if(node->right)
        {
            bool isRightEnd = IsEnd(node->right);
            if(isRightEnd && currentDepth > outMaxDepth)
            {
                outMaxDepth = currentDepth;
                outSubTree = node;
            }
            recursive(outMaxDepth, outSubTree, root, node->right, currentDepth+1);
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
            return nullptr;
        if(IsEnd(root))
            return root;
        int maxDepth = 0;
        TreeNode* subTree = nullptr;
        recursive(maxDepth, subTree, root, root, 0);
        return subTree;
    }
};

