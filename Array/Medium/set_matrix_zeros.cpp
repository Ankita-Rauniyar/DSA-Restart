/* binary (0/1) nXn matrix, find initial 0s pos
make each ele 0 in those row,col */

#include <bits/stdc++.h>
using namespace std;

/* brute: (traversal) 
- Find 0, mark entire col/row = -1
- convert -1 to 0
        
-1!=original 0  -> so only original 0s col/row are set 

TC: O((m × n)(0s check) × (m + n))
(Har zero ke liye poori row aur column traverse karte h.)
SC: 1 (only temp marker used)*/


void markRowCol(vector<vector<int>>& mat, int row, int col){

    int m = mat.size();
    int n = mat[0].size();

    // mark ele in row: mat[fixed_row][changing_column]
    for(int j = 0; j < n; j++){ 
        if(mat[row][j] != 0)
            mat[row][j] = -1;
    }

    // mark column 
    for(int i = 0; i < m; i++){
        if(mat[i][col] != 0)
            mat[i][col] = -1;
    }
}

void brute(vector<vector<int>>&mat){
    int m =mat.size();
    int n = mat[0]. size(); //col = row 0 size

    //mark -1
    for (int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 0){
                markRowCol(mat, i, j);
            }
        }
    }
    //convert -1 to 0
    for(int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if(mat[i][j]==-1){
                mat[i][j]=0;
            }
        }
    }
}


/* better: (marker arrays)
- mark row[m], col[n] no. with 0, then change ele in those marked directly in 0 
 
TC:(n*m)+(n*m)
SC: n+m */


void better(vector<vector<int>>&mat){
    int m = mat.size();
    int n = mat[0].size();
    vector<int>row(m,0); //marker
    vector<int>col(n,0);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(row[i]==1 || col[j]==1) {
                mat[i][j]=0;
            }
        }
    }
}

/* optimal: in place (O(1) SC)

- instead of separate row[]col[] marker array, reuse 1st row, col of matrix itself
- mat[i][0] -> (row marker, 1st col stores row info)
  mat[1][0] = 0 -> row 1 ko baad me poora zero karna h)
- mat[0][j]-> col marker
- mat[0][0] -> belongs to both 1st row/col -> can be confusing, if 0 -> which to handle row/col
- col0 =1 variable, If 1st col contains any 0 -> col0 = 0.

mark rows/col using marker -> zero remaining cells using markers -> handle 1st row using mmat[0][0] ->1st col using col0
*/

void optimal(vector<vector<int>>&mat){
    int m = mat.size();
    int n = mat[0].size();
   
    int col0 = 1;
    for(int i=0; i<m; i++){
        for(int j =0; j<n; j++){
            if(mat[i][j]==0){
                mat[i][0]=0; //mark ith row
                if(j!=0){
                    mat[0][j]=0; //mark jth col, except 1st col
                }
                    else
                    col0=0;
                
            }
        }
    }
    //fill remaining cells other than markers
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
                //check for col, row
                if(mat[i][0]==0 || mat[0][j]==0){
                    mat[i][j]=0; 
                }    
        }
    }
    //1st row
    if(mat[0][0]==0){
        for(int j=0; j<n; j++) mat[0][j]= 0;
    }
    //1st col
    if(col0==0){
        for(int i=0; i<m;i++) mat[i][0] =0;
    }

}

int main(){
    vector<vector<int>> mat = {{1,1,1}, {1,0,1}, {1,1,1}};
    better(mat);
    for(auto row:mat){
        for(auto x: row)
        cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}
