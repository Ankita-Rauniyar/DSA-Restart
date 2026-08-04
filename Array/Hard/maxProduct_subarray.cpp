/* ip: both -ve , +ve integers [1,2,-3,0,-4,-5]
op: max poduct subarray,  20 -> (-4)×(-5) */

/* brute: (n^2)
- generate ll possible subarray, i=0->n j=i->n
- maintain product(1 initially), update with max */


/* optimal1: Prefix + suffix(n) -> left right traversal

-  +ves -> prod increase, 0 -> prod reset to 1(breaks continuity, new subarray start)
- -ves -> even (make +ve-> good), odd (make -ve prod(not max) -> problem)
so,  remove either 1st or last -ve
use Prefix + suffix(both way check)

*/

#include<bits/stdc++.h>
using namespace std;

int maxprod1(vector<int>&a, int n){
    int prefix =1, suffix =1; //product 
    int ans =INT_MIN; //a might have only -ve number or use ans = a[0]
    // agar ans = 0  or 1 kardenge toh, single array like [-2] 0 return akrdega
    for(int i=0; i<n; i++){
        if(prefix ==0) prefix =1; //reset
        if(suffix ==0) suffix =1;
        prefix *= a[i];
        suffix *= a[n-1-i]; //backward
        ans = max(ans, max(prefix,suffix));
    }
    return ans;

}

/* optimal2: DP approach -> single traversal

- Sometimes,a very small negative product can become the maximum product when multiplied by another negative number.
  2*(-6)*-2 = 24
- so, track currMax(+ve largest) , currMin prod(-ve smallest) -> at curr idx
- when multiplied with next -ve ele, currmax prod -> -ve , currmin -> +ve 
 so swap(currmax, currmin) : old min becomes new currmax
- update currmax = max( start new subarray(x) or extend previous(currmax * x))
- update currmin = min(x, currmin*x)

*/

int maxprod2(vector<int>&a, int n){
    int currMax = a[0]; //prod at ith idx
    int currMin = a[0];
    int ans = a[0]; 
    for(int i=1; i<n; i++){
        if(a[i]<0){ //-ve number, swap role
            swap(currMax, currMin);

        }
        // update start new or expand
        currMax = max(a[i], currMax * a[i]);
        currMin = min(a[i], currMin*a[i]);
        //update ans
        ans = max(ans, currMax);

    }
    return ans;
}

int main(){
    vector<int>a ={ 1,2,3,0,-4,-5};
    int n= a.size();
    cout<< maxprod2(a, n);
    return 0;

}