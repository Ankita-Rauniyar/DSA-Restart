/* ip: [2 2 3 3 1 2 2]
 op: 2 (appears > n/2 = 7/2 = 3)   */


 /* brute: linear seach (n^2)
 - for every ele, traverse, maintain count, count>n/2 return  */

 /* better: hashing 
 (n+(n or nlogn )->(depends on map type) SC: n (to store in map wc(unique ele)))
 
 - ele -> count

*/

int better(vector<int> &a, int n){
    map<int,int>mpp;
    for(int i=0; i<n; i++){
        mpp[a[i]]++; //store key value
    }
    for(auto it: mpp){
        if(it.second > n/2){
            return it.first;
        }
    }
    return -1;
}
  
 /* optimal: moore's voting algo TC: n SC: 1

- "cancellation" - diff ele cancel each other
- majority ele has more votes(extra copies) -> remain after cancellation

initially count = 0, candidate ele
same ele -> count++

different ele -> count--

if count == 0 (till now all ele cancel)
   new candidate = current -> count=1

- verify candidate is majority (>n/2) (2nd pass)

[1,2,3,4] -> after cancellation 4 left(not majority)

*/

int optimal(vectro<int>&a, int n){
    int count =0;
    int ele;
    for(int i=0; i<n; i++){
        if(count == 0){
            count =1;
            ele = a[i]; //current candidate
        }
        else if(a[i]==el){
            count++;
        }
        else count--;
    }

    //check ele majority or not
    int count_ele =0;
    for(int i=0; i<n; i++){
        if(a[i]==ele) {
            count_ele++;
        }
    }
        if(count_ele > n/2){
            return ele;
        }
    
    return -1;
}