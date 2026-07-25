//op: ele present in both

/* Brute: (visited array)
- for every ele in 1st array, check if correspoinding same ele present in anoother array
- for duplicates, corresponsing duplicates must be present
- use visited array so 1 ele of b used only once

algo:
- visited array of size 2nd array with all marked 0s
- for every ele in 1st array, traverse 2nd array, check if equal or already visited
- stop traversing if b[j]>a[i], as already sorted

TC: n1*n2
SC: n2 (size of visited array)*/

vector<int> brute(vector<int>&a, vector<int>&b){
    vector<int> ans;
    int n1 = a.size();
    int n2 = b.size();
    vector<int> vis(n2,0); //mark matched ele in 2nd array
     for(int i=0; i<n1; i++){
        for(int j=0; j<n2; j++){
            if(a[i]==b[j] && vis[j]==0){
                ans.push_back(a[i]);
                vis[j] =1; //mark every visited
                break;
            }
            if(b[j]> a[i]) break; //edge case
        }
     }
     return ans;
    
}

/* optimal: (2 pointer)
- pointer at 0
- compare each, put if matched ,increment
- if unmatched (large or small), increment

TC: O(n1+n2) worst case, traverse entire array no matched found
SC: O(1)
    O(n1+n2) -> worst case, store ans and return

 */

 vector<int> optimal(vector<int>&a, vector<int>&b){
    int n1 = a.size();
    int n2 = b.size();
    int i=0;
    int j=0;
    vector<int> ans;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            i++;
        }
        else if(b[j]<a[i]){
            j++;
        }
        else{
            ans.push_back(a[i]); //matched
            i++;
            j++;
        }
    }
    return ans;
 }

 int main(){
    vector<int> a={1,2,2,3,3,4,5,6};
    vector<int>b={2,3,3,5,6,6,7};
    vector<int> ans=optimal(a,b);
    for(auto it:ans)
    cout<<it<<" ";
    return 0;
 }
