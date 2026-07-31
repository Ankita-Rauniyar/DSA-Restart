//greater than n/3 times (floor value, i.e 8/3=2), at max 2 ele as op

/* brute:  n^2 Sc: 1 (atmost 2 ele)
- count each ele, if >n/3 add to ans, skip duplicate, max 2 ele in ans

>(n/3)*3 ele = >n(not possible)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>brute(vector<int>&a, int n){
    vector<int>ans; 
    for(int i=0; i<n; i++){
        if(ans.size()==0 || ans[0]!=a[i]){ //check if ans array empty or has same ele
            int cnt =0;
            for(int j =0; j<n; j++){
                if(a[j]==a[i]){
                    cnt++;
                }   
            }
            if(cnt>n/3) ans.push_back(a[i]);  
        }
         if(ans.size()==2) break; //at max 2 ele
        
    }
    return ans;
    
}

/* better: hashing(store count) ele->cnt
TC: O(n)
SC: O(n)

- whenever mpp[a[i]] > n/3 add in ans

*/

vector<int>better(vector<int>&a, int n){
    vector<int>ans;
    unordered_map<int, int>mpp;
    int min = int (n/3)+1;  
    for(int i=0; i<n; i++){
        mpp[a[i]]++;
        if(mpp[a[i]] == min){ 
            //1st time(min) majority confirm hote hi add hoga, >n/3 pe duplicate add hone ka chance h
            ans.push_back(a[i]);
        }
        if(ans.size()==2) break;

    }
    return ans;
}


/* optimal: moore algo

*/

vector<int> optimal(vector<int>& nums, int n) { 
        int cnt1 =0, cnt2=0;
        int ele1= INT_MIN, ele2= INT_MIN;
        for(int i=0; i<n; i++){
            if(cnt1==0 && ele2!=nums[i]){
                cnt1 =1;
                ele1 = nums[i];
            }
            else if (cnt2==0 && ele1!=nums[i]){
                cnt2=1;
                ele2 = nums[i];
            }
            else if(nums[i]==ele1) cnt1++;
            else if(nums[i]==ele2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        } 
        //chcek majority
        cnt1 =0, cnt2 =0; //count again
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i]==ele1) cnt1++;
            if(nums[i]==ele2) cnt2++;

        } 
        int min = int(n/3)+1;  
        if(cnt1 >= min) ans.push_back(ele1);
        if(cnt2>=min) ans.push_back(ele2);  
        return ans; 
    }



int main(){
    vector<int>a ={11, 33, 33, 11, 33, 11};
    int n = a.size();
    vector<int>ans=brute(a, n);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}