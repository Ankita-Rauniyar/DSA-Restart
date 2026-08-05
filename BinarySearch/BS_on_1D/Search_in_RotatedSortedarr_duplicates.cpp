/* (duplicates)
ip: arr = [7, 8, 1, 2, 3, 3, 3, 4, 5, 6], k = 3
op: yes */


/* cant decide clearly which half sorted
if a[low]=a[mid]=a[high] -> shrink search space low++, high--

*/
#include<bits/stdc++.h>
using namespace std;

bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low =0, high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target) return true;
            //duplicate case -> shrink search space
            if(nums[low]==nums[mid]  && nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
            //if left half sorted
            if(nums[low]<=nums[mid]){
                //target on left
                if(nums[low]<=target && nums[mid]>=target){
                    high = mid-1;
                }
                else low =mid+1;
            }
            //right half sorted
            else{
                //target on right
                if(nums[mid]<=target && nums[high]>=target){
                    low = mid+1;
                }
                else high = mid-1;

            }
        }
        return false;
        
    }

    int main(){
        vector<int>a ={7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
        int x = 3;
        cout<<search(a,x);
        return 0;

    }