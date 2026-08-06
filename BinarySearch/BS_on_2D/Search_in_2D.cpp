/*
Type I: ip: mat = [ [1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12] ], target = 8
        op: true
- each row  sorted 
- 1st ele of each row > last ele of pre row (globally sorted 1D)


Type II: (gfg) 

ip:{{10,20,30,40},{11,21,36,43},{25,29,39,50},{50,60,70,80}} target= 29
op: idxs {2,1}

- row & col wise sorted
- 1st ele of each row/col > last ele of pre row/col

*/

#include<bits/stdc++.h>
using namespace std;

/* Type I: 
brute: linear traverse(n*m)
optimal: BS on virtual 1D array-> log(n*m) Sc:O(1) 

1D Index → 2D
row = index / columns
col = index % columns

2D → 1D
index = row * columns + col

*/

bool search1(vector<vector<int>>&mat, int n, int m, int x){
     //mat{{}} -> 1 row, 0 col -> avoid zero division error in i
    if(matrix.empty() || matrix[0].empty()) 
     return false;  

     int low =0, high = n*m-1; //1st last idx
    while(low<=high){
        int mid = low + (high-low)/2;
        int i = mid/m;
        int j = mid%m;
        if(mat[i][j]== x) return true;
        else if(mat[i][j]<x) low = mid+1; //look on right
        else high = mid-1; //look on left
    }
    return false;   
}


/* TypeII: optimal(2 pointer) -> n+m (staircase search) -> BS (will be slow, cant treat as single sorted 1D)
- pointer at last ele(i.e. last col) of 1st row  (top right)
- move left down after compairing (each row, col sorted) -> a row/col eliminated in each step
*/

vector<int>search2(vector<vector<int>>&mat, int n, int m, int x){
    int i=0, j=m-1;
    while(i<n && j>=0){
        if(mat[i][j]==x){
            return {i,j};
        }
        else if (mat[i][j]>x) j--; //dec col (search on left)
        else i++; //inc row (search downward)
    }
    return{-1,-1};
}


int main(){
    vector<vector<int>>mat1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int n1 = mat1.size();
    int m1 = mat1[0].size();
    int x1 = 8;
    cout<<search1(mat1,n1, m1,x1)<<endl;

    vector<vector<int>>mat2 = {{10,20,30,40},{11,21,36,43},{25,29,39,50},{50,60,70,80}};
    int n2 = mat2.size();
    int m2 = mat2[0].size();
    int x2 = 29;
    vector<int> idx = search2(mat2,n2, m2,x2);
    cout<<idx[0]<<" "<<idx[1];
    return 0;
}
