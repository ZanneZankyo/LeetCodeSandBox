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
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        for(int i = 0 ; i < intervals.size(); i++){
            bool didMerge = false;
            for(int j = i + 1; j < intervals.size(); j++){
                if( (intervals[i].end >= intervals[j].start && intervals[i].start < intervals[j].end)
                   || (intervals[j].end >= intervals[i].start && intervals[j].start < intervals[i].end)
                   || (intervals[i].start <= intervals[j].start && intervals[j].end <= intervals[i].end)
                   || (intervals[j].start <= intervals[i].start && intervals[i].end <= intervals[j].end)
                  ){
                    int min = intervals[i].start < intervals[j].start ? intervals[i].start : intervals[j].start;
                    int max = intervals[i].end > intervals[j].end ? intervals[i].end : intervals[j].end;
                    intervals.erase(intervals.begin() + j);
                    intervals.erase(intervals.begin() + i);
                    intervals.insert(intervals.begin() + i, Interval(min,max));
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

