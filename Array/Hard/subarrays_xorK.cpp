/* Given an array of integers A and an integer K. 
Find the total number of subarrays having bitwise XOR of all elements equal to k. 
 
a^a = 0, a^0 = a 

ip: A = [4, 2, 2, 6, 4] , k = 6
op: 4 -> [4, 2], [4, 2, 2, 6, 4], [2, 2, 6], [6]*/

/* brute: generate all subarray, xor all (n^2)
*/
#include<bits/stdc++.h>
using namespace std;

int brute(vector<int>&a, int n, int K){
    int cnt=0;
    for(int i=0; i<n; i++){
        int xorval=0;
        for(int j=i; j<n; j++){
            xorval = xorval^a[j]; //may extra loop: k->i to j for xor subarray
            if(xorval==K)cnt++;
        }
    }
    return cnt;
}

/* optimal: hashmap (prefixxor->freq) TC: n, SC: n (hashmap)

At every index i, assume the subarray ends at i. (currprexor = xor(0...i))
Need: subarray XOR = K.

So, search for a previous prefix XOR such that:
oldPreXor ^ currPreXor = K( subarray xor(oldpreidx+1 to i)) (common prefix cancels)
=> (required) oldPreXor = currPreXor ^ K 

-If required prefix XOR appeared multiple times, each occurrence gives a different starting index,
so: cnt += mpp[required];

mpp[0] = 1(edge case , for single subarray)
 */

int optimal(vector<int>&a, int n, int K){
    unordered_map<int, int> mpp;
    
    int currXor=0;
    int cnt =0; 
    mpp[0]=1; //{0:1} prexor=0, before starting array
    
    for(int i=0; i<n; i++){
        currXor ^= a[i];
        int required = currXor ^ K;
        if(mpp.find(required)!=mpp.end()){
        //jitni baar oldprexor mila, utni baar new valid subarray banenge(oldpreidx+1 to i)
        //Har ek previous occurrence ek alag starting point deta hai.
            cnt += mpp[required]; 

        //agar cnt++ hota toh, bas 1 new subarray count hota
        //mpp[4]=2 matlab prexor 4, 2 times mila h(alag idxes pr), i.e. 2 valid subarray h

        }
        mpp[currXor]++; //for future store   
    }
    return cnt;

}





int main(){
    vector<int>a = {4,2,2,6,4};
    int n = a.size();
    int K=6;
    cout<<optimal(a,n,K);
    return 0;

}