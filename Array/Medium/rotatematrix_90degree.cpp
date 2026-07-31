/* clockwise rotation 90 degree (N*N )
 */
#include<bits/stdc++.h>
using namespace std;

 /* brute: create ans n*n mat, place ele in correct place 
 (i,j) -> (j, (n-1)-i)

 TC: n*m (traverse)
 SC: n*m (ans)
 */

 vector<vector<int>> brute(vector<vector<int>>&mat){
    int n= mat.size();
    vector<vector<int>> ans(n, vector<int>(n)); // n rows, each row has n col
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            //place ele
            ans[j][(n-1)-i] = mat[i][j];

        }
    }
    return ans;
    
 }

 /* optimal: in place
 - while rotation: 1st col -> 1st row (in reverse order), same for all row
  Transpose(i,j)->(j,i) diagonal in place, then reverse each row

Clockwise 90° → transpose + reverse rows
Anti-clockwise 90° → transpose + reverse columns

 */

  void optimal(vector<vector<int>>&mat){
    int n =mat.size();
    //transpose 
    //i= 0 to n-2 ( if i=n-1, j=i+1=n (out of bound))
    //j = i+1 to n-1 (only upper triangle swap, no diagonal swap so j=i+1, no duplicate swap)
    for(int i=0;i<n-1; i++){
        for(int j=i+1; j<n; j++){ 
            swap(mat[i][j], mat[j][i]);
        }
    }
    //reverse row
    for(int i=0; i<n; i++){
        reverse(mat[i].begin(), mat[i].end);    
    }

  }


 int main(){
    vector<vector<int>> mat ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<vector<int>> ans = brute(mat);
    for(auto row: ans){
        for(auto x: row){
            cout<<x<<" ";  
        }
         cout<<endl;
    }
    return 0;
 }

