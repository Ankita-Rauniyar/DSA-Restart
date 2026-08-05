/* lowerbound: smallest index such that a[idx]>=target
if no such idx found, return n(size of arr)

upperbound: smallest idx such that a[idx]>target


*/

/* brute: linear search (sorted arr)-> n  */

//optimal : logn or use STL -> lower_bound(a.begin(),a.end(),x) - a.begin() 
#include<bits/stdc++.h>
using namespace std;

int lb(vector<int>&a, int n, int target){
    int low =0, high = n-1;
    int ans = n; //highest idx possible
    while(low<=high){
        int mid = (low+high)/2;
        //maybe an ans
        if(a[mid]>=target) {
            ans =mid;
            high = mid-1; //look for more small idx on left
        }
        else{
            low=mid+1; //look on right
        }
    }
    return ans;
}


int ub(vector<int>&a, int n, int target){
    int low =0, high = n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]>target){ //condn change
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;
}


int main(){
    vector<int>a ={3,5,8,15,19};
    int n = a.size();
    int target = 9;
    cout<<ub(a, n, target);
    return 0;
}



