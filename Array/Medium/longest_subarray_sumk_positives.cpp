/* ip: nums = [10, 5, 2, 7, 1, 9], k = 15 (only +vs)  
op: 4 (5,4,7,1) ->contiguos part of array

return 0 ; if no such subarray */

/* brute: (linear search)

-generate all subarrays( i at start ele, j keeps moving making array), find sum
- if sum=k return max length (j-i+1)

n^3 (find start + end idx, sum subarray separately (i to j)) -> n^2 (best case (finding endidx and summing simultaneously)) */

int brute(vector<int>&a, int n int k){
    int maxlen=0;
    for(int i=0;i<n; i++){ //starting idx
        int sum =0;
        for(int j=i; j<n; j++){ //ending idx
            sum += a[j];
            if(sum ==k){
                maxlen = max(maxlen, j-i+1); //store every length
            }

        }
    }
    return maxlen;
}

/* optimal: (sliding window) (only +ve nos. as sum increase only; pointer move reliably)
2 pointer+greedy

- make window(subarray)
- increase sum from right (if sum<k, add ele), if sum>k decrease from left (remove ele on left)
- if sum =k, length = right-left+1,  update ans

TC: O(n) 
SC: O(1)
*/

int optimal (vector<int> &a, int n){
 int left=0;
 int sum=0;
 int maxlen=0;

 for(int right=0; right<n; right++){
    sum += a[right];

    while(sum>k){
        sum -= a[left];
        left++;
    }
    if(sum == k ){
        maxlen = max(maxlen, right - left + 1);
    }
 }
 return maxlen;

}