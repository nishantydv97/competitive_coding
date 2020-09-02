/*

Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.

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
 
 bool compare(Interval i, Interval j){
     return(i.start<j.start);
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    vector<Interval> ans;
    sort(A.begin(),A.end(),compare);
    if(A.size()<=1){
        return A;
    }
    Interval interval=A[0];
    for(int i=1;i<A.size();i++){
        if(interval.end>=A[i].start){
            interval.end=max(A[i].end,interval.end);
        }else{
            ans.push_back(interval);
            interval.start=A[i].start;
            interval.end=A[i].end;
        }
    }
    ans.push_back(interval);
    return ans;
}
