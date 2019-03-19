/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 *
 * https://leetcode.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (42.32%)
 * Total Accepted:    189K
 * Total Submissions: 446.2K
 * Testcase Example:  '3'
 *
 * Given a non-negative index k where k ≤ 33, return the k^th index row of the
 * Pascal's triangle.
 * 
 * Note that the row index starts from 0.
 * 
 * 
 * In Pascal's triangle, each number is the sum of the two numbers directly
 * above it.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: [1,3,3,1]
 * 
 * 
 * Follow up:
 * 
 * Could you optimize your algorithm to use only O(k) extra space?
 * 
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec[2];
        int vecIndex = 0;
        vec[0].push_back(1);
        vec[1].push_back(1);
        vector<int>* prev = &vec[0];
        for(int i = 1; i <= rowIndex; ++i)
        {
            vecIndex ^= 1;
            vector<int>* cur = &vec[vecIndex];
            cur->clear();
            cur->reserve(i + 1);
            cur->push_back(1);
            for(int j = 0; j < prev->size() - 1; ++j){
                cur->push_back(prev->at(j) + prev->at(j + 1));
            }
            cur->push_back(1);
            
            //cout<<vecIndex<<"|";
            prev = cur;
        }
        /*for(int n : vec[0]){
            cout << n << "|";
        }
        cout<<endl;
        for(int n : vec[1]){
            cout << n << "|";
        }*/
        return vec[vecIndex];
    }
};

