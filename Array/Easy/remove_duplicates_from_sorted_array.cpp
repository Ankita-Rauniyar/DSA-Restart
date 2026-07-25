#include<bits/stdc++.h>
using namespace std;

/*  
ip: a[]={1,1,2,2,2,3,3}
op: 3 (modify array, remove in place duplicates, return no. of unique elements)
*/

/* Brute: 
- unique only, use set STL 
- set allows 1 occurence of each ele, auto removes duplicates
 
TC: O(nlogn + n)
SC: O(n) -> additional space to store in set
*/

 int brute(vector<int>&a, int n){

    set<int> st;
    //1st pass -> O(nlogn)
    for (int i=0; i<n;i++){
        st.insert(a[i]); 
    }

    //2nd pass
    int index =0;
    //copy unique ele back to array
    for(auto it:st){ //-> O(n)
        a[index] = it;
        index++;
    }
    return index;
 }

 /* optimal: (two pointer approach)
 - since sorted array, duplicates are adjacent
 - keep i=0(1st unique ele), scan for j 1 to n
 - unique ele in i+1, i++
 - final index i+1

 TC: O(n)
 SC: O(1) */

 int optimal(vector<int>&a, int n){
    //edge case: empty array
    if(n==0)
    return 0;

    int i =0; //1st unique ele
    for(int j =1; j<n; j++){
        if(a[i]!=a[j]){
            a[j] = a[i+1]; //just after 1st unique
            i++;
        }
    }
    return i+1;
 }




int main(){

    vector<int> a = {1,1,2,2,2,3,3};

    int n = a.size();

    int k = brute(a,n);
    int m = optimal(a,n);

    cout << "Unique Elements = " << k << endl;
 
    cout << "Modified Array: ";

    for(int i = 0; i < k; i++){

        cout << a[i] << " ";
    }
    return 0;

}