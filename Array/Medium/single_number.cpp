//every number twice, only 1 once -> find that single no.

/* brute: linear search
for each no, traverse whole array maintain count, if count==1 return 

TC: n*n */

int brute(vector<int>&a, int n){
    for(int i=0; i<n; i++){
        int num = a[i];
        int count=0;
        for(int j=0; j<n; j++){
            if(a[i]==num){
                count++;
            }   
        }
        if(count==1) return num;

    }
    return -1; //if no single no.
}

/* better: hashing (not for large datatype)
- hash array size = maxele + 1 i.e. 0 to maxele
- store count

TC: n+n+n
SC: n(hash array)
*/

int better(vector<int>&a, int n){
    //find max ele of array
    int maxi=a[0];
    for(int i=0; i<n; i++){
        maxi = max(maxi, a[i]);
    }

    vector<int> hash(maxi+1, 0); //size maxi+1 initialize 0
    for(int i=0; i<n; i++){
        hash(a[i]++);
    }
    for(int i=0; i<n; i++){
        if(hash(a[i])==1)
        return a[i];
    }
    return -1;
}


/* optimal: xor
- xor all, same gives 0
TC: n
SC: 1
 */

 int optimal(vector<int>&a, int n){
    int xor =0;
    for(int i=0; i<n; i++){
        xor = xor^a[i];
        return xor;
    }
    return -1;
 }


int main(){

    vector<int> a = {4,1,2,1,2};

    cout << brute(a,a.size());

    return 0;
}