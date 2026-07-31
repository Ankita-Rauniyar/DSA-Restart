/* everything on right must be smaller (in any order)
ip: [10,22,12,3,0,6]
op: [22,12,6] (leaders) */

/* brute: linear traverse
- for each ele, check on right if any greater or not
- at any point if greater found, break , chcek for other

n^2
1 (ans doesnt depend on ip size), n (WC)*/

vector<int> brute(vector<int>&a, int n){
    vector<int> ans;
    for(int i =0; i<n; i++){
        bool leader = true; //assume leader
        for(int i=j+1; i<n; i++){
            if(a[j]>=a[i]){
                leader = false;
                break;
            }
        }
        if(leader){
            ans.push_back(a[i]);
        }
    }
    return ans;
}

/* optimal: 
-find max on right, if a[i]>max -> leader (backward)
update max (leader value) 

reverse ans(in place order), as backward loop*/

vector<int> optimal(vector<int> &a, int n){
    vector<int> ans;
    int maxi =INT_MIN;
    for(int i=n-1; i>=0; i--){
        if(a[i]>maxi){
            ans.push_back(a[i]); //leader

        }
        maxi = max(maxi, a[i]);
    }
    reverse(ans.begin(), ans.end());

}

int main(){
    vector<int> a ={16,17,4,3,5,2};
    int n = a.size();
    vector<int> ans1 =brute(a,n);
    for(auto it: ans1)
    cout<<it<<" ";
}