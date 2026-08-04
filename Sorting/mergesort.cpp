//divide and conquer 

/* 
- recursively divide array into 2 halves until each subarray has 1 ele
- 1 ele already sorted
- backtracking, merge sorted halves in 1 arr using 2 pointers
- store merged result in temp(as may need more comparisons), copy back to original
 */
//nlogn (merge(work done) in all levels (total calls)) 

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&a, int low,int mid , int high){
    vector<int>temp;
    int left = low; //left half
    int right = mid+1; //right half
    while(left<=mid && right<=high){
        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            temp.push_back(a[right]);
            right++;
        }
        
    }
    //remaining
        while(left<=mid){
            temp.push_back(a[left]);
            left++;
        }
        while(right<=high){
            temp.push_back(a[right]);
            right++;
        }
    //copy back to original (as some ele still need for comparisons)
    for(int i=low; i<=high; i++){
        a[i]= temp[i-low]; 
        //a[0]=temp[low-low]=temp[0]
        //a[1] = temp[low+1-low]=temp[1]
    }


}


void mergeSort(vector<int>&a, int low, int high){
    if(low>=high) return;
    int mid = low + (high-low)/2; //avoid overflow (int large)
    //recursive divide
    mergeSort(a,low, mid);
    mergeSort(a,mid+1, high);
    //merge
    merge(a, low,mid,high);
}


int main(){
    vector<int>a={5,2,8,4,1};
    int n = a.size();
    mergeSort(a, 0, n-1);
    for (auto x: a){
        cout<<x<<" ";
    }
    return 0;
}