//finding nCr in minimal time ->nCr = r!/n!(n-r)!

#include<bits/stdc++.h>
using namespace std;  

/* 1. given R, C(1- based) find ele at that place.  eg. r=5,c=3 -> op: 6 

ele = (r-1)C(c-1) -> C(5-1, 3-1) = C(4,2)= 6 
bcoz, Pascal indexing start from 0(pos count from 0)

nCr without factorial:  direct multiplication/division. (c times)
(nCr = n*(n-1)*(n-2)... / 1*2*3...) -> avoid factorial overflow 
result *= (n-i)
result /= (i+1)

(iterations decreased) optimized: k=min(k,n-k) as nCr=nC(n-r) ->10C9=10C1 TC: min(c,r-c)

TC: O(c), as k iteratons =c-1
SC: O(1)

*/

long long findele(int r, int c){ //long long for big N
    int n = r-1;
    int k = c-1;
    long long res=1; //initial val for multiply/divide
        for(int i=0; i<k; i++){ //cols
            res *= (n-i);
            res /= (i+1);
        }
return res;
}


 /* 2. print nth row

 - nth row = n ele
 - agar har ele k liye position factorial(nCr) use karenge toh -> overflow + extra calculation
  so previous ele use krk next ele nikalna

- next ele = preele * (row-col)/col
 1st ele =1

TC: O(N)
SC: O(N) (answer store karne ke liye)

  */

vector<int> printrow(int N){
    vector<int> row;
    int val =1; //1st ele
    row.push_back(val);

    for(int i=1; i<N; i++){ //nth row = n ele

        val = val*(N-i); //ith col
        val = val/i;

        row.push_back(val);
    }
    return row;
  }

/* 3. print triangle
 - generate every row 
 (n*n)
*/

/* vector<int>generaterow(int row){
 //printrow code
} */

vector<vector<int>> print(int N){
    vector<vector<int>>ans;
    for(int i=1; i<=N; i++){
        vector<int> temp = printrow(i); //print each row
        ans.push_back(temp);
    }
    return ans;
}



  int main(){
    int r=5, c=3;
    cout<< findele(r,c)<<endl;

    int n=5; //5th row
    vector<int>ans=printrow(n);
    for(auto it: ans){
        cout<<it<<" ";
        
    }
    cout<<endl;

    vector<vector<int>>ans1 = print(n);
    for(auto row: ans1){
        for(auto val:row){
            cout<<val<<" ";
            
        }
        cout<<endl;
    }

    return 0;
 }   