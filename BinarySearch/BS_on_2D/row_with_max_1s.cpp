/* - binary (0/1) matrix
- sorted rows 
- if multiple rows with max 1s-> return smallest row idx

ip: mat[] = 
1 1 1
0 0 1
0 0 0
op: 0 (row 0th idx) -> if all 0, no 1 , return -1
*/

/* brute:  n*m
-add every ele in a  row , maintain count
- update countrow with max */


#include<bits/stdc++.h>
using namespace std;

int brute(vector<vector<int>>&mat, int n, int m){
    int cnt_max=0; //max 1s
    int idx =-1;
    for(int i=0; i<n; i++){
        int cnt_1s=0;
        for(int j=0; j<m; j++){
            cnt_1s += mat[i][j]; 

        }
        if(cnt_1s > cnt_max){
            cnt_max=cnt_1s;
            idx=i;
        }
    }
    return idx;
}

/* optimal: n * logm
- BS on each row with m cols -> can change row traversal
- sorted row -> no. of 1s = m - 1st occ of 1 = m- lb(1) = m- ub(0)
 */

int lb(vector<int>&a, int n, int x){
    int low =0, high=n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        //maybe an ans
        if(a[mid]>=x) {
            ans = mid;
            high = mid -1;//look for even samller
        }
        else low = mid+1;
    }
    return ans;
}

int optimal(vector<vector<int>>&mat, int n, int m){
    int cnt_max = 0;
    int idx =-1;
    for(int i=0; i<n; i++){
        int cnt_1s = m - lb(mat[i], n, 1);//row arr
        if(cnt_1s > cnt_max){
            cnt_max = cnt_1s;
            idx =i;
        }
        
    }
    return idx;
 }




int main(){
    vector<vector<int>>mat = {{1,1,1},{0,0,1},{0,0,0}};
    int n= mat.size();
    int m = mat[0].size();
    cout<<optimal(mat,n,m);
    return 0;

}

/* optimal: BS(sorted) 


*/