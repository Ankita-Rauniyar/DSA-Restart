/* ip: [3,5,4,1,1] -> [1,n] ele
op: [1,2] 
*/


#include<bits/stdc++.h>
using namespace std;

/* brute: n^2 
- for each no 1 to n, traverse whole array
if cnt==2 repeat, if cnt==0 missing 
- if both found break loop (repeating!=-1 && missing !=-1)*/

/* better: hashing (ele->cnt) Tc: n SC: n
- hash arr(n+1) i.e. 0 to n
 */

vector<int>better(vector<int>&a, int n){
    int hash[n+1] = {0}; //store 0 to n numbers, cnt as 0
    for(int i=0; i<n; i++){ //array traverse
        hash[a[i]]++;
    }
    int repeating =-1, missing =-1;
    for(int i=1; i<=n; i++){
        if(hash[i]==2) repeating =i; //hash ele check
        else if(hash[i]==0) missing = i;

        if(repeating!=-1 && missing !=-1) break;

    }
    return {repeating, missing};
 }

/* optimal: sum+square sum SC:1 

- diff= actual sum(given arr) - expected sum(1 to n) = repeating(y)- missing(x)
- squaresumdiff = actualsqsum-expectedsqsum = y^2-x^2 

(y-x)(y+x)=sqDiff
y+x = sqDiff / diff , y-x = diff. (eqns)
on adding both, 2y = diff + sqDiff/diff -> y = (diff + sqDiff/diff)/2
then  x = y - diff

*/

vector<int>optimal(vector<int>&a, long long n){ //n^2 can overflow 
    long long totalsum = (n*(n+1))/2; //expected
    long long totalsqsum = (n*(n+1)*(2*n+1))/6;
    long long sum =0, sqsum=0; //actual
    for(long long i=0; i<n; i++){
        sum += a[i];
        sqsum += (long long)a[i]*(long long)a[i];
    }

    long long sumdiff = sum - totalsum;
    long long sqsumdiff = sqsum - totalsqsum;
    long long sumxy = sqsumdiff/sumdiff;
    long long repeating = (sumdiff + sumxy)/2;
    long long missing = repeating - sumdiff;

    return {(int)repeating, (int)missing};

}


/* optimal: XOR
Array XOR 1..N
        ↓
Repeating ^ Missing
        ↓
Find different bit (as xor mixed both)
        ↓
Make 2 groups
        ↓
XOR groups
        ↓
Get both numbers

 */

int main(){
    vector<int> a ={3,5,4,1,1};
    int n = a.size();
    vector<int> ans = optimal(a,n);
    cout<<ans[0]<<" "<<ans[1];

    return 0;

}
