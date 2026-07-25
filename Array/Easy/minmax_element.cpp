#include<bits/stdc++.h>
using namespace std;

/* //brute (sorting)
   //TC: O(nlogn)
   //SC: O(1) -> ignoring sorting implementation space

vector<int> getMinMax(vector<int> &v){

    sort(v.begin(), v.end());
    return{v.front(), v.back()}; 

} */



//optimal (linear traverse)
//TC: O(n)
//SC: O(1)



//return type_functionname(i/p type)
// &v -> original vector (1 vector in main) -> SC: O(1) (improve performance)
// v -> copy vector (extra mem) -> SC: O(n)

/* (int return 1 value )

 int ans = function(v); (return same as type)
 
 cout<<ans; */


/* exactly 2 value -> pair<int,int> function(vector<int>&v); 

pair<int,int> ans = function(v);
cout<<ans.first<<endl<<ans.second<<endl;

 */



vector<int> getMinMax(vector<int>&v){ 
                                      
    int min_ele = v[0];
    int max_ele = v[0];

    // min_ele = min(min_ele, v[i]); (STL)
    // max_ele = max(max_ele, v[i]);

    for (int i=1; i<v.size();i++){

        if(v[i]>max_ele){
            max_ele = v[i];
        }

        if(v[i]<min_ele){
            min_ele = v[i];
        }

    }

    return {min_ele, max_ele};
}

int main() {

int n;
cin >> n;

vector<int> v(n);

for(int i=0;i<n;i++){
    cin >> v[i];
}

//vector<int> v={1, 1, 2, 1, 3, 5, 1};
    
    vector<int> ans = getMinMax(v); //ans vector
     
    cout << "Minimum: " << ans[0] << endl; 
    cout << "Maximum: " << ans[1] << endl; 

    /* if( smallest== num[i]){
			index= i;
		} 
            cout<<index; */

    return 0;
    
}