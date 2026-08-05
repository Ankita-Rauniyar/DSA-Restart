#include<bits/stdc++.h>
using namespace std;

/* - in rotated arr, one half always sorted
- min either 1st ele of sorted or on unsorted part
- discard sorted part after storing min */

 int findMin(vector<int>& nums) {
        int n= nums.size();
        int low=0, high=n-1;
        int mini = INT_MAX; 
        while(low<=high){

         // already sorted
        if(nums[low] <= nums[high]){
            mini = min(mini, nums[low]);
            break;
        }

            int mid =(low+high)/2;
            //left half sorted
            if(nums[low]<=nums[mid]){
                mini = min(nums[low], mini); //1st ele of sorted half always min
                low = mid+1; //discard left half

            }
            //right half sorted
            else{
                mini = min(nums[mid], mini);
                high = mid-1;  //discard right half

            }
        }
        return mini;
        
    }




int main(){
    vector<int>a={4,5,6,7,0,1,2} ; //unique ele
    cout<<findMin(a);
    return 0;
}