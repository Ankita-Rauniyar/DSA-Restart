//i < j  AND  arr[i] > arr[j]

/* ip: 5,3,2,1,4
op: 7
 7 pairs (5,1), (5,3), (5,2), (5,4),(3,2), (3,1), (2,1)
 */

/* brute: n^2
for each ele, check with all other

cnt=0;
for(i = 0 to n){
for(j=i+1 to n)
if(a[i]>a[j]) cnt++
}
return cnt;
*/

/* optimal: merge sort (nlogn) SC: n (temp arr)

- during merge, if a left>right (in two already sorted halves), all remaining ele in left > right
so cnt = mid-left+1; (multiple inversions)

*/

#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>&a, int low, int mid, int high){
    vector<int>temp;
    int left= low;
    int right = mid+1;
    int cnt =0;
    while(left<=mid && right <= high){
        if(a[left]<=a[right]){
            temp.push_back(a[left]);
            left++;
        }
        else{
            cnt += (mid-left+1); //all remaining left are inversions
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
    //copy back to original arr 
    for(int i=low; i<=high; i++){
        a[i]= temp[i-low]; //a[1] = temp[low+1-low]=temp[1]
    }
return cnt;
}


int mergeSort(vector<int>&a, int low, int high){
    int cnt=0;
    if(low>=high) return 0; //single ele or no ele
    int mid = (low+high)/2;
    cnt += mergeSort(a, low, mid);//combine all halves cnt
    cnt += mergeSort(a, mid+1, high);
    cnt += merge(a, low, mid, high);
    return cnt;
}

int ans(vector<int>&a, int n){ 
    return mergeSort(a, 0, n-1);
}

int main(){
    vector<int>a ={5,3,2,1,4};
    int n = a.size();
    cout<< ans(a,n);
    return 0;
}
