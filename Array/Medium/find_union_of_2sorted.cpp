/* Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8] -> may have duplicates

Output: [1, 3, 4, 5, 6, 7, 8, 9] -> only unique */

/* brute: use 'set' -> unioque ele
- each array, store in set 
- store all ele in single array 
TC: O((n1+n2) log(n1+n2)) ; every insertion in set O(log n), total insertions (n1+n2)
SC: (n1+n2)-> set + (n1+n2)-> to return ans */

vector<int> brute(vector<int> &a, vector<int>&b){
    int n1 = a.size();
    int n2 = b.size();
    set<int> st;
    for(int i=0; i<n1; i++){
        st.insert(a[i]);
    }

    for(int i=0;i<n2; i++){
        st.insert(b[i]);
    }
    vector<int> temp;
    for(auto it:st){
        temp.push_back(it);
    }
    return temp;
}

/* optimal: 2 pointer union (only for sorted arrays)
- if not sorted, sort 1st -> increase TC: (n1logn1+n2logn2)
- iterate individual array
- Compare current elements and insert the smaller one.
- Skip duplicates while inserting.

TC: n1+n2
SC: n1+n2 (worst case)-> to return ele
 */

 vector<int> optimal(vector<int> a, vector<int>b){
    int n1 = a.size();
    int n2 = b.size();
    int i=0;
    int j=0;
    vector<int> ans;

    /* sort(a.begin(), a.end());
     sort(b.begin(), b.end()); */

     while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            if(ans.size()==0 || ans.back()!= a[i]){ //insert if empty or  not duplicate from last inserted ele
                ans.push_back(a[i]);
            }
            i++;
        }
        else{
            if(ans.size()==0 || ans.back()!= b[j]){ // ans.empty() 
                ans.push_back(b[j]);
            }
            j++;
        }

     }

     //remaining ele
    while(i<n1){
        if(ans.size()==0 || ans.back()!= a[i]){ 
                ans.push_back(a[i]);
            }
            i++;
     }

     while(j<n2){
        if(ans.size()==0 || ans.back()!= b[j]){ 
                ans.push_back(b[j]);
            }
            j++;
     }

     return ans;
    
 }
