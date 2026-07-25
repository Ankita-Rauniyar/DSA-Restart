/* ip: array of 0 1 2 */

//brute: sort 

/* better: 
- maintain count of 0 1 2 
- for counts, pace number in array 

n(counting loop) + n(filling loop)*/

void brute(vector<int>&a, int n){ //modifying array, no return
    int cnt0 =0, cnt1 =0, cnt2=0;
    for(int i=0; i<n; i++){
        if(a[i]==0) cnt0++;
        else if(a[i]==1)cnt1++;
        else cnt2++;
    }
    //fill
    for(int i=0; i<cnt0; i++) a[i]=0;
    for(int i=cnt0; i< cnt0 +cnt1; i++) a[i]=1;
    for(int i=cnt0+cnt1; i<n; i++) a[i]=2;
}


/* optimal: (dutch national flag algo)

[0 0 0 | 1 1 1 |unknown| 2 2 2]

 0 to low-1     = 0 (fixed)
 low to mid-1   = 1 (fixed)
 mid to high    = unknown (check karna hai)
 high+1 to n-1  = 2 (fixed)

initially:
(0s section)low = 0
(check current ele) mid = 0
(2s section) high = n-1

TC: n (once traverse using mid)
SC: 1
*/

void optimal(vector<int> &a, int n){
    int low =0;
    int mid =0;
    int high = n-1;
    
    while(mid<=high){
        if(a[mid]==0){
            swap(a[mid], a[low]);
            low++;
            mid++;
        }
        else if(a[mid]==1){
            mid++;
        }
        else { //if 2
            swap(a[mid], a[high]);
            high--;
        }
    }
}