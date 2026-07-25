#include<bits/stdc++.h>
using namespace std;

/* ip: [ 1,2,0,0,3]
op: [1,2,3,0,0] */

/* Brute: 
- iterate, store all non zeros in temp
- put them in front in array (size = temp)
- then zeroes at remaining places 

TC: n+x(temp)+n-x(remaining)= 2n
SC: x(temp nonzero ele)
SC: n (if no non zero, whole array size)-> worst case
 */

 vector<int> brute(vector<int> &a, int n){
    vector<int> temp;
    for(int i=0; i<n; i++){
        if(a[i]!= 0){
            temp.push_back(a[i]);
        }
    }

    int nz = temp.size(); 
    for(int i =0; i<nz; i++){
        a[i] = temp[i];
    }

    for(int i = nz; i<n; i++){
        a[i] = 0;
    }

    return a;
 }


/*  
optimal: (2 pointer)
 -swap nz with 0 over one iterartion in array itself
 - j always at 1st 0, i(next ele to 0) iterate over , swap(a[i], a[j])
 
 TC: x(for j pass) + n-x (for i) = n
 SC: O(1), no extra space 
 */


vector<int> optimal(vector<int> &a, int n){
    int j = -1; //min index
   

    for(int i=0; i<n; i++){
        if(a[i] == 0){
            j=i; //always at 1st 0
            break;
        }
    } 
     //no non zero numbers
    if(j==-1) return 0;
    
    for(int i=j+1; i<n; i++ ){
        if(a[i]!=0){
            swap(a[i],a[j]);
            j++;
        }
    }

    return a;  
}


 int main(){
    vector<int>v={1,2,0,0,3};
    int n= v.size();
    
    vector<int>v1 = brute(v,n);
    for(auto it:v1)
    cout<<it<<" ";


    return 0;

 }