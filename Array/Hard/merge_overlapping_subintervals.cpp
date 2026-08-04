/*Input : intervals=[[1,3],[2,6],[8,10],[15,18]]
Output : [[1,6],[8,10],[15,18]]

Two intervals overlap if: 
next interval ka start <= current interval ka end 
[1,3] & [2,6] overlap  as 2<=3
merged interval: min(start) max(end) -> [1,6]

next interval ka end bas merge k tym expand karta h, overlap k liye start bas check krna h

*/

#include<bits/stdc++.h>
using namespace std;

/* brute: (no sorting) n^2(or worse depends on implementation), n(visited)

- for each interval, compare with other
- if overlap -> update start,end(i.e. merge) -> mark visited -> store ans
((not handle edge case) may skip some overlapping one , so Merge hone ke baad fir se scan karna padskta h jb tk koi merge na ho)
- high TC: repeated comparisons 
*/



/* better: sorting + nested loop (nlogn +n(merge))

- sort(bring overlapping intervals together)
- for ith interval, merge all next overlapping 
- jump to next nonoverlapping interval
*/


vector<vector<int>>better(vector<vector<int>>&a){
    int n = a.size();
    sort(a.begin(), a.end());
    vector<vector<int>>ans;
    for(int i=0; i<n;){ //manual increment
        int start  = a[i][0]; //current ith
        int end = a[i][1];

        int j = i+1;
        while(j<n && a[j][0]<=end){
            end = max(end, a[j][1]); //start min hota h as sorted
            j++;
        }
        ans.push_back({start, end}); 
        i=j; //skip all overlap intervals, jump to nonoverlapping
    }
    return ans;
}


/* optimal: sorting + single paas (nlogn +n(merge))

- Har interval ko last merged interval se compare karo
if(current.start > lastMerged.end)
    new interval
else
    merge by updating end 
*/

vector<vector<int>> optimal(vector<vector<int>>&a){
    int n = a.size();
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for(auto it: a){ //each inetrval
        //no overlap
        if(ans.empty() || ans.back()[1]<it[0]){ //lastmerged.end < current.start
            ans.push_back(it);

        }
        //overlap
        else{
            ans.back()[1]= max(ans.back()[1], it[1]); //update end
        }
    }
    return ans;
}




int main(){
    vector<vector<int>>intervals ={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>>ans = optimal(intervals);

    for(auto interval: ans){
        cout<<"["<<interval[0]<<" "<<interval[1]<<"] ";
    }
    return 0;
}
