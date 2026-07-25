//given N, ip: n-1 nos from 0 to N or 1 to N, find missing
/* ip:[ 1,2,4,5]
op: 3 */


 /* brute: 
- check every no 1 to N
- for every no, search entire array
- if exist , mark, stop searching
- if not exist, return 
- if no missing found return -1

TC: O(n*n)->WC
SC: O(1)
 */

 int brute(vector<int>&a, int N){
    int n=a.size();
    for(int i=1; i<=N; i++){
        int exist=0;
        for(int j=0; j<n; j++){
            if(a[j]==i){
                exist =1;
                break;
            }
        }
        if(exist==0)
        return i;
    }
    return -1; //no missing
 }

 /* better: hashing (size = N+1 (0 to N))
 -create hash array idx=no. value=present or not

 TC: n+n (hash check +array traverse)
 SC: N (hash array)
  */
 int better(vector<int>&a, int N){
    int n= a.size();

    //hash size N+1 because range is 0 to N
    int hash[N+1] = {0}; 

    /* index a[i]:  0 1 2 3 4 5 (used as given ip) N=5
        hash i :   0 0 0 0 0 0 (present or not)*/

    for(int i =0; i<n; i++){ // given array
        hash[a[i]]=1; //mark if idx matches array ele
    }
    for(int i=1; i<N; i++){ // 1 to N, find missing
        if(hash[i]==0)
        return i;
    }

 return -1;
 }


 /* optimal: 1.sum (n(n+1)/2) or 2.XOR (a^a =0, 0^b=b)
 - sum2 = total a[i], sum = formula, ans=sum-sum2


 - XOR1 = given array,  XOR2= 1 to N (better for bigger datatype)
 - XOR1 ^ XOR2 = mising number (a^a =0, 0^b=b)

TC: O(n) SC: O(1)
  */

 int optimal1(vector<int>&a, int N){
    int n = a.size();
    int requiredsum = n*(n+1)/2; 
    int sum2 = 0;
    
    for(int i=0;i<n; i++){ //sum in given array
        sum2+=a[i];
    }
    return (requiredsum-sum2);
 }


  int optimal2(vector<int>&a, int N){
    int n=a.size();
    /* O(2n)
    
    int xor1 = 0, xor2 =0;
    for(int i=1; i<=N; i++){
        xor1 = xor1 ^ i;
    }
    for (int i=0; i<n; i++){
        xor2 =xor2^a[i];
    }
    return xor1^xor2; 
    */

    //optimised O(n)
    int xor1 = 0, xor2 =0;
    int n = N-1; //array size = N-1 (1 no. missing)

    //1 pass
    for(int i=0; i<n; i++){ 
        xor2 = xor2 ^ a[i]; //array xor
        xor1 = xor1 ^ (i+1); //xor of 1 to N-1
    }

    //last N
    xor1 = xor1 ^ N;
    return xor1^xor2;
 }



 int main(){
    vector<int>a={1,2,4,5};
    int N =5;
    cout<<optimal(a,N);
    return 0;
 }