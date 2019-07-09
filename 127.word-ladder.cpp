/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 *
 * https://leetcode.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (24.21%)
 * Likes:    1460
 * Dislikes: 812
 * Total Accepted:    263.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * Given two words (beginWord and endWord), and a dictionary's word list, find
 * the length of shortest transformation sequence from beginWord to endWord,
 * such that:
 * 
 * 
 * Only one letter can be changed at a time.
 * Each transformed word must exist in the word list. Note that beginWord is
 * not a transformed word.
 * 
 * 
 * Note:
 * 
 * 
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 * You may assume no duplicates in the word list.
 * You may assume beginWord and endWord are non-empty and are not the same.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * Output: 5
 * 
 * Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" ->
 * "dog" -> "cog",
 * return its length 5.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * Output: 0
 * 
 * Explanation: The endWord "cog" is not in wordList, therefore no possible
 * transformation.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {

    struct StringNode{
        string* str;
        vector<string*> next;
        int dist = -1;
        StringNode(string* s = nullptr, string* n = nullptr) : str(s) {
            if(n){
                next.push_back(n);
            }
        }
    };

public:
    bool canTrans(string const &a, string const &b){
        if(a.size() != b.size())
            return false;
        int diffCount = 0;
        for(int i = 0; i < a.size(); ++i){
            if(a[i]!=b[i]){
                ++diffCount;
                if(diffCount > 1){
                    return false;
                }
            }
        }
        return diffCount == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        StringNode head(&beginWord);
        string* end = nullptr;
        for(string& s : wordList){
            if(canTrans(beginWord, s)){
                head.next.push_back(&s);
            }
        }
        map<string*, StringNode*> strMap;
        strMap[&beginWord] = &head;
        for(int i = 0; i < wordList.size(); ++i){
            StringNode* strNode = new StringNode(&wordList[i]);
            for(int j = 0; j < wordList.size(); ++j){
                if(i == j) continue;
                if(canTrans(wordList[i], wordList[j])){
                    strNode->next.push_back(&wordList[j]);
                }
            }
            if(canTrans(wordList[i], beginWord)){
                strNode->next.push_back(&beginWord);
            }
            strMap[&wordList[i]] = strNode;
            if(wordList[i] == endWord){
                end = &wordList[i];
            }
        }

        if(!end) return 0;

        queue<StringNode*> q;
        //unordered_set<StringNode*> visited;
        head.dist = 1;
        q.push(&head);
        //visited.insert(&head);
        while(!q.empty()){
            StringNode* front = q.front();
            q.pop();
            //cout<<*front->str<<":"<<front->dist<<"|";
            if(front->str == end){
                return front->dist;
            }
            for(string* s : front->next){
                auto found = strMap.find(s);
                if(found == strMap.end()) continue;
                if(found->second->dist >= 0) continue;
                found->second->dist = front->dist + 1;
                q.push(found->second);
            }
        }
        return 0;
    }
};

