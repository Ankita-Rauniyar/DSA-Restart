/* n*m(odd*odd) = odd no of ele 
- median: middle value in sorted set of nos 

ip: row wise sorted matrix
*/

/* brute:  n*m(traverse) + (n*m)log(n*m) (sort) SC: n*m(list)
-convert 2D in 1D -> sort 1D -> return med

*/
#include<bits/stdc++.h>
using namespace std;

int brute(vector<vector<int>>&mat, int n, int m){
    vector<int>eles; //list of 1D 
    for(int i =0; i<n; i++ ){
        for(int j=0; j<m; j++){
            eles.push_back(mat[i][j]);
        }
    }
    sort(eles.begin(),eles.end());
    int k = eles.size();
    return eles[k/2];

}

/* optimal: BS on ans

- Median is the smallest value such that more than half of the elements are less than or equal to it.

Smallest valid value for which:
 count(elements <= mid value) > (n*m)/2

- Hum mid value(possible median) guess kar rahe hain:
      count elements <= mid (upperbound idx= count on each row)


If  count (elements <= mid) > total/2 (exceeds half of totla ele)
- mid k andar median position aagyi
- mid possible ans h
- search smallest valid value(on left)

else, mid is small, search median on right


TC: nlogm(ub) * log(max-min) (outer BS med check in value range)
*/

int countLessEqual(vector<int>&row, int n, int m, int x){
    int low =0, high = m-1;
    int ans = m;
    while(low<=high){
        int mid = low + (high -low)/2;
        //may be an ans
        if(row[mid]>x){
            ans = mid;
            high = mid-1;

        }
        else{
            low = mid+1;
        }
    }
    return ans;
}



int optimal(vector<vector<int>>&mat, int n, int m){
    int low = INT_MAX; //mat not globally sorted, only row wise
    int high = INT_MIN;
    //value range (smallest ele, largest ele)
    for(int i=0;i<n; i++){
        low = min(low, mat[i][0]); //as row sorted , ele on 1st col
        high = max(high, mat[i][m-1]);//on last col
    }

    int req = (n*m)/2;
    while(low<=high){
        int mid = low +(high-mid)/2;
        int count =0;
        //count ele<=mid across rows
        for(int i=0; i<n; i++){
            //STL: upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            count += countLessEqual(mat[i],n, m, mid);
        }
        if(count<=req){
            low =mid+1; //on right
        }
        else{
            high = mid-1; //on left
        }
    }
    return low; //median
}


int main(){
    vector<vector<int>>mat = {{1,4,9},{2,5,6},{3,8,10}};
    int n = mat.size();
    int m = mat[0].size();
    cout<<brute(mat,n,m)<<endl;
    cout<<optimal(mat,n,m)<<endl;
    return 0;

}