/* ip:  N = 7, target = 13, array[] = {3, 4, 13, 13, 13, 20, 40} 
op: 2,4

if not found, return -1

total count of occurence = lastocc-firstocc+1*/

/* brute: linear traverse(n)

first =-1, last=-1;
for(i=0 ->n){
if(a[i]==x){
if(first==-1) first =i;
last =i //since sorted
}
}
 */

 /* optimal1: 2(logn)
 -find lb, ub-1
 - check if(lb==n or arr[lb]!=x) -> no x found case
 
 */

 #include<bits/stdc++.h>
 using namespace std;


 int lowerbound(vector<int>&a, int n, int x){
    int low=0, high=n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]>=x){
            ans=mid;
            high = mid-1; //look for even smaller
        }
        else low = mid+1;
    }
    return ans;
}

int upperbound(vector<int>&a, int n, int x){
    int low=0, high=n-1;
    int ans = n;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]>x){
            ans=mid;
            high = mid-1; //look for even smaller
        }
        else low = mid+1;
    }
    return ans;
}

    pair<int,int> searchRange(vector<int>& nums, int target) {
        int n =nums.size();
        int lb = lowerbound(nums,n,target);
        if(lb==n || nums[lb]!=target) return {-1,-1}; //target doesn't exist
        
        int ub= upperbound(nums,n,target);
        return {lb,ub-1};
        
    }


    /* optimal2: BS from scratch
    */

    int firstocc(vector<int>&a, int n, int x){
        int low=0, high=n-1;
        int first=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(a[mid]==x){ //may or may not be 1st occ
                first = mid;
                high = mid-1;//look on left for first occ
            }
            else if(a[mid]<x) low = mid+1; //on right
            else high=mid-1;
        }
        return first;

    }
    int lastocc(vector<int>&a, int n, int x){
        int low=0, high=n-1;
        int last=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(a[mid]==x){ //may or may not be last occ
                last = mid;
                low = mid+1;//look on right for last occ
            }
            else if(a[mid]<x) low = mid+1; //on right
            else high=mid-1;
        }
        return last;
    }
    vector<int>firstlastocc(vector<int>&a, int n, int x){
        int first = firstocc(a, n, x);
        if(first ==-1) return {-1,-1}; //no1st occ means no last occ too
        int last = lastocc(a,n,x);
        return {first,last};
    }

    int count(vector<int>&a, int n, int x){
        vector<int>ans = firstlastocc(a,n,x);
        if(ans[0] ==-1) return 0;
        return ans[1]-ans[0]+1; //total count of occurence  
    }




 int main(){
    vector<int>a={3, 4, 13, 13, 13, 20, 40};
    int n = a.size();
    int x = 13;
    pair<int,int>ans = searchRange(a,x);
    cout<<ans.first<<" "<<ans.second<<endl;;

    vector<int>ans1 = firstlastocc(a,n,x);
    cout<<ans1[0]<<" "<<ans1[1]<<endl;

    cout<< count(a,n,x);


    return 0;
 }