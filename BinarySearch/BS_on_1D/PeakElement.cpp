/* a[i-1]<a[i]>a[i+1] : ele greater than both left & right 

- may multiple peaks -> return any

ip:{1,2,3,4,5}
op: 5 -> assume -infinity on both end
so always a peack found

*/


#include<bits/stdc++.h>
using namespace std;

/* brute: linear search -> N
- check condn at every idx
 */
int brute(vector<int>&a, int n){
    for(int i=0; i<n; i++){
        //for 1st ele, left side always satisfy as -infinity on end, same for last ele
        //boundary check : avoid invalid idx i.e. a[-1], a[n]
        if((i==0 || a[i-1]<a[i]) && (i==n-1 || a[i]>a[i+1])){
            return i; //idx
        }
    }
    return -1;
}


/* optimal: BS 
- increasing left-> peak-> decreasing right

- if multiple peaks, return any i.e. the first one to get encountered on either slope
*/

   int optimal(vector<int>&a, int n){
    if(n==1) return 0;
    if(a[0]>a[1]) return 0; //1st peak
    if(a[n-1]>a[n-2]) return n-1; //last peak
    int low =1, high = n-2; 
    while(low<=high){
        int mid = (low+high)/2;
        //peak found
        if(a[mid]>a[mid+1] && a[mid]> a[mid-1]) return mid;
        else if(a[mid]>a[mid-1]){ //increasing slope, peak on right
            low = mid+1;

        }
        else high = mid-1; //decreasing slope, peak on left
    }
     return -1;

   }





int main(){
    vector<int> a ={1,2,3,4,5};
    int n = a.size();
    cout<<optimal(a,n);
    return 0;


}