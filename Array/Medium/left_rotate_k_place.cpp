#include<bits/stdc++.h>
using namespace std;

/* Left Rotation:
Input : [1,2,3,4,5,6,7], k = 2
Output: [3,4,5,6,7,1,2] */

/* k = k % n (effective rotation, if k>n) -> rotating n times gives the same array.
if n=8  -> 7+1 -> 1 place rotation only */

//Brute: -> Rotate left by 1, k times → O(n × k) SC: O(1)
void brute(vector<int>&a, int n, int k){
       //edge case
       if(n==0)
       return;

       k = k%n;
       while(k--){
        int temp = a[0]; //store 1st ele
        for (int i=1; i<n; i++){
            a[i-1]=a[i];
        }
        a[n-1] = temp;
       }
}


/* Better: Temporary array → O(n), SC: O(k)
- Store first k in temp
- Shift left
- Put temp at end (a[i] = temp[i-(n-k)])

Last k positions:
n-k  n-k+1 ... n-1

Temp positions:
0      1      ... k-1 

n = 7
k = 3

nums index : 4 5 6
temp index : 0 1 2 */

void better(vector<int>&a, int n, int k){
    //edge case
       if(n==0)
       return 0;

    k = k%n; 
    vector<int>temp(k); //int temp[k]
    for(int i=0; i<k; i++){ -> O(k)
        temp[i] = a[i];
    }

    //shift remaining k to n-1
    for(int i = k; i<n; i++){  -> O(n-k)
        a[i-k] = a[i];
    }

    //copy temp at end n-k to n-1
    for (int i=n-k; i<n; i++){// -> O(k)

        //temp index starts from 0
        a[i] = temp[i-(n-k)]; 
       
        /* 
        Example:
        n = 7, k = 3

        i = 4
        nums[4] = temp[4-(7-3)]
                = temp[4-4]
                = temp[0] */
    }   

}

/* optimal: Reversal Algorithm → O(n), O(1) (no extra space)
-reverse first k (a, a+k)
- reverse remaining (a+k, a+n)
- reverse whole */

//reverse start to end
void Reverse(vector<int>&a, int s,int e ){
    while(s<=e){
        int temp = a[s]; //swap(a[s], a[e])
        a[s] = a[e];
        a[e] = temp;
        s++;
        e--;
    }
}

void optimal(vector<int>&a, int n, int k){
    /* //STL  int: a...a+k....a+n

    reverse(a.begin(), a.begin()+k);
    reverse(a.begin()+k, a.end());
    reverse(a.begin(), a.end()); */

    k = k%n;
    Reverse(a, 0, k-1); //fist k ele
    Reverse(a, k, n-1); //remaining
    Reverse(a, 0, n-1); //whole
}

int main(){
int n;
cin>>n;
vector<int> a[n];
for(int i=0; i<n; i++){
    cin>> a[i];
}

int k;
cin>>k;
brute(a,n,k);
//rotated array
for(int i=0; i<n; i++){
    cout<< a[i]<<" ";
}


    return 0;
}
