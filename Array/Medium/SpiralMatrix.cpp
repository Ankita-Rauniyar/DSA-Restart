//spiral manner: go right->bottom->left->top
//TC: O(m*n)
//SC: O(1) (excluding output array)

#include <bits/stdc++.h>
using namespace std;

vector<int> optimal(vector<vector<int>>&mat){
int m = mat.size();
int n = mat[0].size();
vector<int>ans; //print
int left=0, right = n-1;
int top=0, bottom = m-1;

while(top<=bottom && left<=right){
    //go right
    for(int i=left; i<=right; i++){
        ans.push_back(mat[top][i]);//row fixed
    }
    top++; //next row
    //go bottom
    for(int i=top; i<=bottom; i++){
        ans.push_back(mat[i][right]); //col fixed

    }
    right--; //col changed

    //edge case: single row/col, avoid duplicate print
    
    if(top<=bottom){ 
    //go left
    for(int i=right; i>=left; i--){
        ans.push_back(mat[bottom][i]); //row fixed

    }
    bottom--; //row change
}
    //go top
    if(left<=right){
    for(int i=bottom; i>=top; i--){
        ans.push_back(mat[i][left]);//col fixed
    }
    left++; //next col
    }
}
return ans;
}


int main(){
    vector<vector<int>>mat={{ 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }};
    vector<int>ans=optimal(mat);
    for(auto x: ans){
        cout<<x<<" ";
    }
    return 0;
}