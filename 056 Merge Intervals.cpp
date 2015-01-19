/**
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
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
	static bool cmp(Interval e1, Interval e2) {
		if((e1.start < e2.start) || (e1.start == e2.start && e1.end > e2.end))
			return true;
		else
			return false;
	}
    vector<Interval> merge(vector<Interval> &intervals) {
    	vector<Interval> ans;
    	Interval interval;
    	sort(intervals.begin(), intervals.end(), cmp);
    	for(int i = 0;i < (int)intervals.size();i ++) {
    		if(ans.size() == 0)
    			ans.push_back(intervals[i]);
    		else {
    			interval = ans.back();
    			if(intervals[i].start > interval.end)
    				ans.push_back(intervals[i]);
    			else if(intervals[i].end > interval.end){
    				interval.end = intervals[i].end;
    				ans.pop_back();
    				ans.push_back(interval);
    			}
    		}
    	}
    	return ans;
    }
};