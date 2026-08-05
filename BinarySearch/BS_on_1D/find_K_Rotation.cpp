/* no. of times array rotated 
ip: [3,4,5,1,2]
op: 3 

original array should be [1,2,3,4,5], so 3 times rotated (right rotation)


Number of right rotations = index of minimum element

left rotations = ( n - right rotations) %n -> (5-3)%5 =2

logn(w/o duplicates)
n(wc: with duplicates)
 */


 #include<bits/stdc++.h>
 using namespace std;

 int RightRotationCount(vector<int>&a, int n){
    int low =0, high = n-1;
    int idx = -1; //min ele idx = ans
    int mini = INT_MAX;
    while(low<=high){
        //already sorted
        if(a[low]<=a[high]){
            if(a[low]<mini){
                mini = a[low];
                idx = low;
            }
            break;
        }
        int mid = (low+high)/2;
        //duplicate case -> check , shrink search space
        if(a[low]==a[mid]&& a[mid]==a[high]){
            if(a[low]<mini){
                mini = a[low];
                idx = low;
            }
            low++;
            high--;
            continue;
        }

        //left half sorted
        if(a[low]<=a[mid]){
            if(a[low]<mini){
                mini = a[low];
                idx = low;
            }
            low = low+1; //discard left half
        }
        //right half sorted
        else{
            if(a[mid]<mini){
                mini = a[mid];
                idx = mid;
            }
            high = mid-1; //discard right half
        }
    }
    return idx;
 }

 //No. of left rotation
 int LeftRotationCount(vector<int>&a, int n){
    int idx = RightRotationCount(a, n); //min ele idx
    return (n-idx) %n ; //rotation cyclic -> n rotation=0 rotations
 }

 int main(){
    vector<int>a= {3,4,5,1,2};
    int n = a.size();
    cout<<RightRotationCount(a,n)<<" "<<LeftRotationCount(a,n);
    return 0;
 }