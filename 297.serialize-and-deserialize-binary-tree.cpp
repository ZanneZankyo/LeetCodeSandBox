/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (39.68%)
 * Total Accepted:    165K
 * Total Submissions: 415.9K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "[";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(s.size() > 1){
                s += ",";
            }
            if(node != nullptr){
                s += to_string(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            else{
                s += "null";
            }
        }
        s += "]";
        //cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        int nodeCount = 0;
        TreeNode* head = nullptr;
        queue<TreeNode*> q;
        while(i < data.size()){
            if(data[i] == ']'){
                return head;
            }
            while(data[i] == ',' || data[i] == '[') ++i;
            int j = i;
            while(data[j] != ',' && data[j] != ']') ++j;
            string sub = data.substr(i, j-i);
            TreeNode* newNode = nullptr;
            //cout << sub << "|";
            if(sub != "null"){
                newNode = new TreeNode(stoi(sub));
            }
            if(head == nullptr){
                head = newNode;
            }
            if(!q.empty()){
                TreeNode* node = q.front();
                if((nodeCount & 1) == 0)
                    q.pop();
                if(nodeCount == 0 || node == nullptr) {}
                else if( (nodeCount & 1) != 0 ){
                    node->left = newNode;
                    //cout << node->val << "->" << newNode->val << "|" << endl;
                }
                else{
                    node->right = newNode;
                    //cout << node->val << "->" << newNode->val << "|" << endl;
                }
            }
            if(newNode != nullptr){
                q.push(newNode);
            }
            ++nodeCount;
            i = j;
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

