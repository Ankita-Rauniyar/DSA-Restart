/* - individual row & col wise sorted (in asc order)

Matrix=
1   4   7   11
2   5   8   12
3   6   9   16
10 13  14  17
Target: 9
Output: Found at (2,2) (0-indexed)
*/

/* better: BS on each 1D row n*logm */

#include<bits/stdc++.h>
using namespace std;

pair<int,int> BS(vector<int>&row,int n, int x, int i){
    int low =0, high = n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(row[mid]==x) return {i,mid}; //rowidx,colidx
        else if(row[mid]>x) high = mid-1;
        else low=mid+1;
    }
    return {-1,-1};
}
pair<int,int> better(vector<vector<int>>&mat, int n, int m, int x){
    //BS on each row
    for(int i=0; i<n; i++){
        pair<int,int> ans = BS(mat[i],n,x,i);
        if(ans.first!=-1) return ans; //target found -> if not Bs on next row
    }
    return {-1,-1};
}

/* optimal: (n+m) -> staircase(top right)
*/

bool search2(vector<vector<int>>&mat, int n, int m, int x){
    int i = 0, j=m-1; //top right
    while(i<n && j>=0){
        if(mat[i][j]==x) return true;
        else if(mat[i][j]> x) j--; //on left
        else i++; //down
    }
    return false;
}


int main(){
    vector<vector<int>>mat = {{1,4,7,11},{2,5,8,12},{3,6,9,16},{10,13,14,17}};
    int n= mat.size();
    int m= mat[0].size();
    int x = 9;
    pair<int,int>ans= better(mat,n,m,x);
    cout<<ans.first<<" "<<ans.second<<endl;
    cout<<search2(mat,n,m,x);
    return 0;
}

