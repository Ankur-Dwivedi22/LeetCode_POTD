class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        int a = -1, b = -1 , ct = 0;
        for(int i=0; i<n; i++){
                int c = intervals[i][0], d = intervals[i][1];
                if(a != -1 && ((a <= c && d <= b) || (c <= a && b <= d))){
                    ct++;
                    a = min(a, c);
                    b = max(b, d);
                }
                else{
                    a = c;
                    b = d;
                }
        }

        return n-ct;
    }
};