//find the subarray with the largest sum, and return its sum.

/* brute: n^3 to n2

-find all subarray , sum, find max sum (maxi= max(sum, maxi))
maxi = INT_MIN 
*/

/* optimal: kadane's algo (donot carry -ve runnig sum in future)

- move , keep adding (in subarray), if sum<0 (-ve) -> drop (set sum =0), as it decrease total sum
- start new subarray

sum += current
maxi = max(maxi,sum)
if(sum<0)
    sum=0

TC = O(n)
SC = O(1)

 */

// -ve maxi allowed as empty subarray not allowed, so maxi = INT_MIN
 int optimal(vector<int>&a, int n){
    int sum =0;
    int maxi = INT_MIN;  // if empty subarray allowed -> maxi=0 (i.e. max sum =0, all ele -ves)
    for(int i=0; i<n; i++){
        sum += a[i];
        maxi = max(maxi, sum);
        if(sum<0){
            sum =0;
        }     
    }
    return maxi;
 }

 //print any subarray with max sum
 /* - start -> current subarray idx
  ansStart, ansEnd -> required subarray idx
sum += a[i]

if(sum > maxi)
    save start & end

if(sum < 0) -> start fresh
{
    sum = 0;
    start = i+1; 
}
  */


  int print(vector<int>&a, int n){
    int sum =0;
    int maxi = INT_MIN;
    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;
    for(int i=0; i<n; i++){
        sum += a[i];
        if(sum>maxi){
            maxi =sum;
            ansStart = start;
            ansEnd = i; //subarray till current idx
        }
        if(sum<0){ //start fresh
            sum =0;
            start = i+1; //new subarray
        }
    }
    
    for(int i=ansStart ; i<=ansEnd; i++){
        cout<<a[i]<<" " << endl;
        return maxi;
    }
  }