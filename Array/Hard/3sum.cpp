//Find triplets(unique idxes i != j != k, number can be same in diff idx) that add up to 0 or k (sum)

/* brute: try all triplet sum(3 loops); set insertion (O(k))

TC: N3 * log(no. of unique triplets) -> sort(3 ele)= O(1)
SC: O(2* number of unique triplets) (set + ans list)

- order of triplet doesn't matter: [-1,0,1] == [1,-1,0]
 set<vector<int>> checks full vector value , may add both order

- so sort triplet before storing in set -> avoid duplicate 
  */

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>brute(vector<int>&a, int n){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j = i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                if(a[i]+a[j]+a[k]==0){
                    vector<int> temp = {a[i], a[j],a[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                
                }
                
            }
        }
    }
    //set->vector (return type)
    vector<vector<int>> ans;
    for(auto it: st){
        ans.push_back(it);
    }
    return ans;

}


/* better:  hashing (2 pointer)
TC:  n^2log(no. of unique triplets=k) -> loop+hashset(lookup)
SC:  O(2k + N) -> set(triplet)+ ans vector+hashset(lookup)

a[i]+ a[j]+a[k]=0 // change acc to target
a[k]= -(a[i]+a[j]) -> required (lookup in table), not be the same no, diff one(use sort before store in set)

- before moving j, put the curr ele in map, after ith traverse -> new hash( new j,k for new i, new search space)

*/

vector<vector<int>> better(vector<int>&a, int n){
    set<vector<int>> st; //avoid duplicates
    for(int i=0; i<n; i++){
        set<int>hashset; //fast lookup, new for every i(only ele after i considered), prevents mixing of previous data
        for (int j=i+1; j<n; j++){
            int third = -(a[i]+a[j]);
            if(hashset.find(third)!= hashset.end()){
                vector<int> temp ={a[i], a[j], third};
                sort(temp.begin(),temp.end());
                st.insert  (temp);          
        }

            hashset.insert(a[j]); //store curr for future lookup
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}


/* optimal: sorting + 2 pointers(w/o map)

- Sort array
- Fix first element i, find remaining 2
- left=i+1, right=n-1
- sum<0 -> left++
- sum>0 -> right--
- sum==0 -> store answer, move both
- Skip duplicate values -> i, left and right

TC: O(n²) + nlogn
SC: O(1) (exclusing ans)
 */

 vector<vector<int>>optimal(vector<int>&a, int n){
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        //skip 1st duplicate ele
        if(i>0 && a[i]==a[i-1])continue;
        int left = i+1;
        int right = n-1;
        while(left<right){
            int sum = a[i]+a[left]+a[right];
            if(sum<0) left++;
            else if(sum>0)right--;
            else{
                vector<int>temp ={ a[i], a[left], a[right]};
                ans.push_back(temp);
                left++;
                right--;
                //skip dulicate left and right
                while(left<right && a[left]==a[left-1]) left++;
                while(left<right && a[right]==a[right+1]) right--;
                
            }
        }
    }
    return ans;

 }



int main(){
    vector<int> a = {-1, 0, 1,2,-1,-4};
    int n = a.size();
    vector<vector<int>>ans = optimal(a,n);
    for(auto it: ans){
        for(auto val: it){
            cout<< val<<" ";
        }
        cout<<endl;
    }
    return 0;
    

}

