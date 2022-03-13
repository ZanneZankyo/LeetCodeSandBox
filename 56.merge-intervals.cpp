/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (34.96%)
 * Total Accepted:    313.3K
 * Total Submissions: 896.3K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * 
 * Constraints:
 * 
 * 1 <= intervals.length <= 104
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 104
 * 
 */
#if 1
class Solution {
public:
    static bool sortIntervals(vector<int> const &intervalA, vector<int> const &intervalB){
        return intervalA[0] < intervalB[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), sortIntervals);

        vector<vector<int>> result;
        result.reserve(intervals.size());

        int intervalStart = intervals[0][0], intervalEnd = intervals[0][1];
        for(int i = 1; i < intervals.size(); ++i){
            if(intervalEnd < intervals[i][0]){
                vector<int> newInterval;
                newInterval.resize(2);
                newInterval[0] = intervalStart;
                newInterval[1] = intervalEnd;
                result.push_back(newInterval);
                intervalStart = intervals[i][0];
                intervalEnd = intervals[i][1];
            }
            else{
                intervalEnd = intervalEnd > intervals[i][1] ? intervalEnd : intervals[i][1];
            }
        }
        vector<int> newInterval;
        newInterval.resize(2);
        newInterval[0] = intervalStart;
        newInterval[1] = intervalEnd;
        result.push_back(newInterval);
        return result;
    }
};
#endif
#if 0
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        for(int i = 0 ; i < intervals.size(); i++){
            bool didMerge = false;
            for(int j = i + 1; j < intervals.size(); j++){
                if( (intervals[i][1] >= intervals[j][0] && intervals[i][0] < intervals[j][1])
                   || (intervals[j][1] >= intervals[i][0] && intervals[j][0] < intervals[i][1])
                   || (intervals[i][0] <= intervals[j][0] && intervals[j][1] <= intervals[i][1])
                   || (intervals[j][0] <= intervals[i][0] && intervals[i][1] <= intervals[j][1])
                  ){
                    int min = intervals[i][0] < intervals[j][0] ? intervals[i][0] : intervals[j][0];
                    int max = intervals[i][1] > intervals[j][1] ? intervals[i][1] : intervals[j][1];
                    intervals.erase(intervals.begin() + j);
                    intervals.erase(intervals.begin() + i);
                    vector<int> newInterval;
                    newInterval.push_back(min);
                    newInterval.push_back(max);
                    intervals.insert(intervals.begin() + i, newInterval);
                    j-=2;
                    if(j <= i)
                        j = i+1;
                    didMerge = true;
                }
            }
            if(didMerge){
                i-=2;
                if(i<-1)
                    i = -1;
            }
        }
        return intervals;
    }
};
#endif

