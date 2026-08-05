/* 
 unique ele
ip: {4,5,6,7,0,1,2} target=0 (unique ele)
op: 4

ip: {4,5,6,7,0,1,2} target=3
op: -1
*/


/* brute: always linear search -> n */

/* optimal: (unique ele -> return idx)

Find sorted half (as whole rotaed arr not sorted, atleast one half is sorted )
        |
Check target range
        |
Keep one half, discard other 
*/


#include<bits/stdc++.h>
using namespace std;


//unique ele ip
int search(vector<int>& nums,int n, int target) {
        int low=0, high=n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return mid;
            // if left half sorted
            if(nums[low]<=nums[mid]){
                //target lies on left
                if(nums[low]<=target && nums[mid]>=target){
                    high = mid-1; //look on left
                }
                else{
                    low = mid+1; //look on right
                }
            }

            //right half sorted
            else{
                if(nums[mid]<=target && nums[high]>=target){
                    low = mid+1;

                }
                else high = mid-1;
            }
            
        }
        return -1;
        
    }



int main(){
    vector<int> a = {4,5,6,7,0,1,2};
    int n = a.size();
    int x = 0;
    cout<<search(a,n,x);
    return 0;
}



