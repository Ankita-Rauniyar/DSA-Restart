/* - no adjacent cells same
- ele > left,right,top,bottom
- always greater than boundary -1
- may be multiple peaks -> return any idxes
*/


/* brute: WC: n*m*4 (check for each ele in  all 4 direction) */

/* optimal: BS (skip some search space) -> (nlogm) -> max in col* BS across col

- BS across cols -> eliminate going through all ele
- find mid col, the max ele  on that col
- check only left right, as its aleready greater than up down

3 cases: left<max>right ->peak found
          right>max -> look on right 
          left>max -> on left

- BS can be done across rows too

*/

#include<bits/stdc++.h>
using namespace std;

//row idx having max ele on mid col
int maxRow(vector<vector<int>>&mat, int n, int m, int col){
    int idx =0;
    for(int i=0; i<n; i++){
        if(mat[i][col]>mat[idx][col]){
            idx = i;
        }
    }
    return idx;
}


vector<int>findPeak(vector<vector<int>>&mat, int n, int m){
    int low =0, high = m-1; //BS across col
    while(low<=high){
        int mid = (low+high)/2;
        //row having max ele on mid col
        int row = maxRow(mat,n,m,mid); 
        //find left - right & boundary handle
        int left = (mid-1>=0) ? mat[row][mid-1]: -1; 
        int right = (mid+1<m) ? mat[row][mid+1]: -1;

        //peak found
        if(mat[row][mid]>left && mat[row][mid]>right){
            return {row,mid};
        }
        //peak on left
        else if(left > mat[row][mid]){
            high = mid-1;
        }
        //peak on right
        else low = mid+1;
    }
    return {-1,-1};
}


int main(){
    vector<vector<int>>mat = {{5,10,8},{4,25,7},{3,9,6}};
    int n = mat.size();
    int m = mat[0].size();
    vector<int>ans = findPeak(mat,n,m);
    cout<<ans[0]<<" "<<ans[1]; //idxes
    return 0;
}