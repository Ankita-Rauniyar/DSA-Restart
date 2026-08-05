/* floor: largest no<=x. (just samller or equak)
ceil : smallest no>=x (just greater or equal) -> lowerbound 

if no such no., return -1
*/

#include<bits/stdc++.h>
using namespace std;

int floor(vector<int>&a, int n, int target){
    int low=0, high=n-1;
    int ans =-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]<=target){
            ans = a[mid];
            low=mid+1;//search on right for more larger
        }
        else high=mid-1;
    }
    return ans;

}




int main(){
    vector<int>a={10,20,30,40,50};
    int n = a.size();
    int target =25;
    cout<<floor(a,n,target);
    return 0;
}