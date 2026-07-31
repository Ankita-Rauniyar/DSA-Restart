/* Total = n! 

TC: n! * n(ele for every permutation)
SC: recursion stack: O(n)
    visited array: O(n)
    current ds: O(n)
    answer storage: O(n × n!)

Total auxiliary space (excluding answer): O(n) */

/* Approach 1:

- ds(for current permutation), mark array(n,0) (for visited ele)
- loop(0 to n) -> if(not in map), ds.add[i], map[i]=1 (visited)
- recursively build permutations
- backtrack: unmark remove ele
- ds.size == n -> one possible permutation
- store in ans 

choose ele -> mark -> recursive call -> unchoose(unmark) (backtrack)*/

void generatePermute(vector<int>&a, vector<int>&current, vector<vector<int>>&ans, vector<int>&visited){

    //if current permute size equals array size, store in ans
    if(current.size()==a.size()){
        ans.push_back(current);
        return;
    }

    for(int i=0; i<n; i++){
        //if ele not used
        if(visited[i] == 0){
            //pick ele, mark
            current.push_back(a[i]);
            visited[i] =1;
       

        //go to next position
        generatePermute(a, current, ans, visited);

        //backtrack(remove choice)
        visited[i] = 0;
        current.pop_back();
        }
    }
}

//main permute function
vector<vector<int>> getPermute(vector<int>&a){
    vector<vector<int>> ans; //stores all permute
    vector<int> current; //store 1 permute
    vector<int> visited(v.size(), 0); //mark used ele

    generatePermute(a, current, ans, visted);
    return ans;

}


/* Apprach 2: using swap(no vesited array) , in place modification 

element ko current position pe lao -> recursive -> wapas original state me lao

TC: n! * n
SC: n (recursion stack)
*/


/* void generatePermute(int index, vector<int>&a, vector<vector<int>>&ans){

    if(index == a.size()){ //one permutation formed
        ans.push_back(a);
        return;
    }

    for(int i = index; i<a.size(); i++){
        swap(a[index], a[i]); //choose: ele at curr idx (fix)
        generatePermute(index+1, a, ans); //fill next pos
        swap(a[index], a[i]); //undo choice ->backtrack
    }
}

vector<vector<int>>getPermute(vector<int>&a){
    vector<vector<int>> ans ;
    generatePermute(0, a, ans);
    return ans;

} */



int main(){
    vector<int> a ={1,2,3};
    vector<vector<int>> ans = getPermute(a);

    //print
    for(auto it: ans){
        for(auto x: it){ //each permutation
            cout<<x<<" ";
        }
        cout<<endl;
    }
return 0; 
}


