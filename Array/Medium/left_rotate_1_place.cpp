#include<bits/stdc++.h>
using namespace std;

/* ip: [1,2,3,4,5]
op: [2,3,4,5,1] */

/* 
brute: 
- take dummy temp[n] array
- store number in that array shifting left 
- print dummy array 
SC: O(n) 
*/


/* 
optimal:
- store 1st ele as temp
- left shift all
- store last ele as temp

TC: O(n)
SC: O(1) -> modify array itself (no extra space)
    O(n) -> space used in algo/code temp
 */

 //only modify array -> void
 void optimal(vector<int> &a, int n){
    int temp = a[0];
    for (int i=1; i<n; i++){ 
        a[i-1] = a[i]; 
    }
    a[n-1] = temp;
 }

 /* right rotate:
 temp = a[n-1] -> last ele
 i=n-1 to >0 (backward) -> a[i] =a[i-1]
 a[0] = temp -> copy at first */

 int main(){
    vector<int> a={1,2,3,4,5};
    int n = a.size();
    optimal(a,n);
    cout<< "Rotated array";

    for(int i =0; i<n; i++){
        cout<<a[i]<<" ";
    }

    return 0;
 }