//4 quads(unique idxes) that add up to target value
#include<bits/stdc++.h>
using namespace std;

/* brute: generate all quads(4 loop) , check sum
 - sort before store in set

 Tc: n^4 + logn(set) / 1(if unordered set)
 */

 vector<vector<int>> brute(vector<int> &a, int n, int target){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k = j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    if(a[i]+a[j]+a[k]+ a[l]== target){ //add sepearately to avoid int overflow
                        vector<int>temp ={a[i],a[j],a[k], a[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>>ans(st.begin(), st.end());
    
    return ans;
    
 }


 /* better: hashing (n^3 + logn)
 -kSum → fix k-1 elements, search last element 
 int fourth = target - (a[i]+a[j]+a[k]); (3 fixed, 4th find)
 new hash after (i,j), insert curre ele before moving k
 sort before store in set

  */

 vector<vector<int>>better(vector<int>&a, int n, int target){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<int>hashset;
            for(int k=j+1; k<n; k++){
                int fourth = target - (a[i]+a[j]+a[k]);
                if(hashset.find(fourth)!= hashset.end()){
                    vector<int> temp = {a[i],a[j],a[k],fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);

                }
                hashset.insert(a[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;

 }

 /* optimal: sort + 2 pointer
 - fix i,j -> use left right for remaining 2, avoid duplicates 
 
(nlogn +n^3)-> sort + 2 inner loop & pointer traversal
O(1)-> no extra space, exclude ans*/

 vector<vector<int>>optimal(vector<int>&a, int n, int target){
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for(int i=0;i<n; i++){
        //skip duplicate i
        if(i>0 && a[i]==a[i-1])continue;
        for(int j=i+1; j<n; j++){
            //skip duplicate j
            if(j>i+1 && a[j]==a[j-1])continue;
            int left = j+1;
            int right = n-1;
            while(left<right){
                long long sum = (long long) a[i]+ a[j]+ a[left]+a[right];
                if(sum<target) left++;
                else if (sum>target)right--;
                else{
                    ans.push_back({a[i], a[j], a[left], a[right]});
                   //skip duplicate left/right
                left++;
                right--;
                while(left<right && a[left]==a[left+1]) left++;
                while(left<right && a[right]==a[right-1]) right--;
            }
        }

        }
    }
    return ans;
 }

int main(){
    vector<int> a = {1,0,-1,0,-2,2};
    int n = a.size();
    vector<vector<int>> ans = optimal(a,n, 0);
    for(auto row: ans){
        for(auto x: row){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}

