#include <bits/stdc++.h>
using namespace std;

/* brute: generate all subarray, count those with sum k 
n^2*/

int brute(vector<int>&a, int k){
    int n = a.size();
    int count =0;
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum += a[j];
            if(sum == k){
                count++;
            }

        }
    }
    return count;
}

/* optimal: prefix+hashmap (presum->count). 
O(n) average->array traversal O(1) for unoredred map, O(n) space(wc: if all presum stored in map)

- presum (from idx 0 to current idx)

- (preSum - k) agar pehle mila hai, to us prefix ke baad se current index tak ka subarray ka sum 'k' hoga. -> new subarray found
[at i, (presum - k) + k(required subarray) =  presum till idx i]


cnt += mpp[presum - k] (purane valid prefix mile, utni subarray add karo)

- Store current prefix sum:
    mpp[preSum]++ (for future)

- mpp[0] =1(presum 0 exists once before starting array) -> counts subarrays starting from idx 0,
    kyunki ([3], k = 3
                 preSum = 3
                 presum - k=3-3=0, mpp[0]=1-> [3] single subarray h)
 */ 


 int optimal(vector<int>&a, int k){
    unordered_map<int, int>mpp;
    mpp[0] = 1; //before starting array
    int presum =0;
    int cnt =0;
    for(int i=0; i< a.size(); i++){
        presum += a[i];
        int remove = presum -k; //presum = remove +k i.e. agar remove pehle mila to, subarray k mila h
        cnt += mpp[remove];
        mpp[presum]++;
    }
    return cnt;

 }


int main(){
    vector<int> a={1,2,3,-3,1,1,1,4,2,-3};
    int k=3;
    int ans = brute(a,k);
    cout<<ans;
    return 0;
}