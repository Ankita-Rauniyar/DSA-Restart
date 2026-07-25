#include<bits/stdc++.h>
using namespace std;


//Brute: (sort, then find distinct ele)
//TC: O(nlogn + n)
pair<int,int> brute(vector<int> a, int n){
    if (n<2)
    return {-1,-1};

    sort(a.begin(), a.end()); 

    int sS = INT_MAX;
    int sL = INT_MIN;

    for(int i=1;i<n; i++){ //forward
        if(a[i]!= a[0]){
            sS = a[i]; //if duplicates
            break;
        }
    }

    for (int i = n-2; i>=0; i--){
        if (a[i]!= a[n-1]){
            sL = a[i];
            break;
        }
    }

    if( sS == INT_MAX )
    sS = -1;

    if(sL == INT_MIN )
    sL =
     -1;

    return {sS, sL};
}


//Better: 
//first find smallest and largest, then find secondorder values
//TC: O(n+n) (traverse 2 times)

/* optimal: (one traversal)
TC: O(n)
SC: O(1)

Edge cases: 
1. n<2 -> return -1
2. all elements same -> return -1 (no slarge or ssmall)
3. duplicate largest/smallest -> ignore duplicates
4. -ve numbers allowed -> INT_MIN (else -1) & INT_MAX  
*/

pair<int,int> optimal(vector<int> &a, int n){
    if (n<2)
    return {-1,-1};

    int largest = a[0]; //1st ele
    int slargest = INT_MIN;

    int smallest = a[0];
    int ssmallest = INT_MAX;

    //single traversal
    for (int i=1; i<n; i++){
        //new largest found
        if(a[i] > largest){
            //previous largest become slargest
            slargest = largest;
            largest = a[i];
        }
        
        //ignore duplicate largest , update if between largest & slargest
        else if (a[i] < largest && a[i] > slargest){
            slargest = a[i];
        }

        if(a[i]<smallest){
            ssmallest =smallest;
            smallest = a[i];
        }

        else if( a[i]>smallest && a[i]<ssmallest){
            ssmallest = a[i];
        }
    }

    //no second largest exists or all same 
    if (slargest == INT_MIN)
    slargest = -1;


    if (ssmallest == INT_MAX)
    ssmallest = -1;

    return {ssmallest, slargest};
    
}



int main (){
    int n;
    cin>>n;

    vector<int> a(n);
    for (int i=0; i<n; i++){
        cin>>a[i];
    }

    //pair<int,int> ans1 = brute(a,n);
    pair<int,int> ans = optimal(a,n);

    cout<< ans.first<<" "<<ans.second;

    return 0;
}



