/* ip: {1,1,2,2,3,3,4,5,5,6,6} -> all duplicates except one
op: 4

*/

/* brute: check pre and next ele for curr -> N
 */

 #include<bits/stdc++.h>
 using namespace std;

 int brute(vector<int> &a, int n){
    if(n==1) return a[0]; //single ele arr
    for(int i=0; i<n; i++){
        //edge cases: avoid runtime error (overflow of idxes)
        if(i==0){
            if(a[i]!=a[i+1]) return a[i]; //check on right
        }
        else if(i==n-1){
            if(a[i]!=a[i-1]) return a[i]; //check on left
        }
        else{
            if(a[i]!=a[i-1] && a[i]!=a[i+1]) return a[i]; //check both
        }
    }
    return -1; //dummy statement
 }

 /* better: binary serach
 same ele idx (even, odd) -> ans on right half (eliminate left)
 same ele idx (odd, even) -> ans on left half (eliminate right part)
 */
 int better(vector<int>&a, int n){

    if(n==1) return a[0];
    if(a[0]!=a[1]) return a[0];
    if(a[n-1]!=a[n-2]) return a[n-1];

    int low=1, high = n-2;
    while(low<=high){
        int mid = (low+high)/2;
        //check both -> single ele found
        if(a[mid]!=a[mid-1] && a[mid]!=a[mid+1]){
            return a[mid];
        }

        //left pair(odd, even) -> ans on right -> eliminate left
        if((mid%2==1 && a[mid] == a[mid-1]) || (mid%2==0 && a[mid]==a[mid+1])){
            low = mid+1;
        }
        //right pair(even,odd) -> ans on left-> eliminate right
        else{
            high = mid-1;
            
        }
    }
    return -1;
 }





 int main(){
    vector<int> a = {1,1,2,2,3,3,4,5,5,6,6};
    int n = a.size();
    cout<<brute(a,n)<<endl;
    cout<<better(a,n);
    return 0;
 }