/* a =[ 2,6,5,8,11] target =14
op: yes
op: [1,3] -> 6+8=14

1. check if pair (2 nos ) exists whose sum = target -> yes/no
2. return idxes of both ele
 */

 /* brute:  n^2
 -for every ele, check sum with other ele , check if match ans or not  */

 vector<int>brute(vector<int> &a, int n, int target){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){ //start from next ele, no need to repeat same sum
            if(a[i]+a[j]== target){
                return {i,j};  //"yes" -> string
            }
        }
    }
    return {-1,-1};
 }

 /* better: hashing (ele->idx) TC, SC: O(n), (nlogn if map(ordered))

 - store in hashmap, find (ele - target) -> if required no. present in map, return both idx
 - 1st check required ele, then store current ele
  */

  vector<int>better(vector<int>&a, int n, int target){
    unordered_map<int, int> mpp;
    for(int i=0; i<n; i++){
        int num = a[i];
        int required = target - num;
        if(mpp.find(required) != mpp.end()){ // present
            return {mpp[required], i};
        }
        mpp[num] = i; //if not found
    }
    return {-1,-1};
  }


  /* optimal: (w/o map) 2 pointer +greedy (only yes/no -> as idx change after sorting)
  - sort +traverse
   
  TC: O(nlogn + n)
  SC: O(1)
  */

  string optimal(vector<int>&a, int n, int target){
    sort(a.begin(), a.end());
    int left =0, right = n-1;
    while(left<right){
        int sum = a[left] + a[right];
        if(sum == target) return "yes";
        else if(sum < target) left++;
        else right--;
    }
    return "no";
  }

