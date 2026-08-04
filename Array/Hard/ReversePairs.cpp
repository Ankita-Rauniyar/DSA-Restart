//i<j && a[i]>2*a[j]

/* ip: {1,3,2,3,1}
op:2 -> (3,1)(3,1)-> 3>2*1 */

/* brute: 
generate all pairs (n^2)
chcek condition, maintain cnt */

/* optimal:  mergesort (nlogn)

- merge do sorting not counting (simple compare a>b, not a>2*b)
 so, before merge, check pairs using count condition, then merge (to keep array sorted)

-Counting Intuition: 
For every element in the left half, move the right pointer until:
      a[left] > 2*a[right]

Since both halves are sorted, if a[left] satisfies the condition for a[right],
then every next left element (larger or eaual element) will also satisfy it. 
so right++ only (never reset), making the counting step O(N) instead of O(N²).
    
So, cnt += right - (mid+1) -> for each left ele
because all elements from (mid+1) to (right-1) form valid reverse pairs.


*/

#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>&a, int low, int mid, int high){
    int left = low; //left half
    int right = mid+1;//right half
    vector<int>temp;
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
     while(left<=mid){
             temp.push_back(a[left]);
            left++;
     }
    while(right<=high){
            temp.push_back(a[right]);
            right++;

     }
    for(int i=low; i<=high; i++){
        a[i]= temp[i-low];
    }
}

int CountPairs(vector<int>&a, int low, int mid, int high){
    int right = mid+1;
    int cnt =0;
    for(int i=low; i<=mid; i++){
        while(right<=high && (long long)a[i]>2*(long long)a[right]){
            right++;  
        }
        cnt += (right - (mid+1));
    }
    return cnt;
}

int mergeSort(vector<int>&a, int low, int high){
    int cnt =0;
    if(low>=high) return 0;
    int mid = low +(high-low)/2;
    //return cnt from every single mergesort + current cnt
    cnt += mergeSort(a, low, mid); 
    cnt += mergeSort(a, mid+1, high);
    //before merge cnt pairs
    cnt += CountPairs(a, low, mid, high); 
    merge(a, low,mid, high);
    return cnt;
}

int ans(vector<int>&a, int n){
    return mergeSort(a, 0, n-1);
}


int main(){
    vector<int>a ={1,3,2,3,1};
    int n = a.size();
    cout<<ans(a,n);
    return 0;
}
