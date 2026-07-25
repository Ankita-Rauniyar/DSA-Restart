/* N = 6, array[] = {9, -3, 3, -1, 6, -5}  
op: 5 
The following subarrays sum to zero:
- {-3, 3}
- {-1, 6, -5}
- {-3, 3, -1, 6, -5}
The length of the longest subarray with sum zero is 5. */

/* Brute:
Har possible subarray banao aur sum check karo. 

TC: n^2 SC: 1 */

/*  Longest Sum 0:
    find same prefix sum

    Longest Sum K:
    find prefix sum = current sum - K 
    
*/

/* optimal: (prefix sum+ hashmap) (=ve, -ve, 0 mixed array)

- prefix sum -> first index

- same prefix sum mila:
current index - old index = zero sum length (middle subarray)

TC: O(n)
SC: O(n) ( map size depends on ip, WC : every idx has diff sum)

- [5, 2, -7, 5]
Index    Sum

0        5
1        7
2        0
3        5 
prefix till index 0 = 5
prefix till index 3 = 5 -> index 1 to 3:    2 + (-7) + 5 = 0
length = curr idx - old idx(mpp[sum]) = 3-0 = 3 */


int optimal(vector<int>&a, int n){
    unordered_map<int,int>mpp;
    int maxlen=0; //maxlength of 0 subarray
    int sum=0; //prefix sum or sum=k

    for(int i=0; i<n; i++){
        sum+=a[i];
    
    //if sum is zero, subarray [0..i] has zero sum
    if(sum==0){ //or sum == k 
        maxlen=max(maxlen, i+1); //best length (0 to curr idx)
    }

    /* if k sum
    - rem = sum-k 
    if(mpp.find(rem)!= mpp.end()){
    maxi = max(maxi, i-mpp[rem])} */

    //if sum value seen before in array
    if(mpp.find(sum)!= mpp.end()){
        maxlen = max(maxlen, i-mpp[sum]); //curr idx - already stored pre index 
    }

    //if sum found 1st time, store (1st idx only -> longest needed)
    else{ 
        if(mpp.find(sum) == mpp.end())
    {
        mpp[sum]=i;
    }
}

}
return maxi;
}

int main(){

    vector<int> a = {9, -3, 3, -1, 6, -5};

    int ans = optimal(a, a.size());

    cout << ans;

    return 0;
}