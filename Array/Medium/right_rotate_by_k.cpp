/* Input:
[1,2,3,4,5,6,7]
k = 2

Output:
[6,7,1,2,3,4,5] */

/* better:
-store last k in temp 
-shift remaining by k to right  a[i+k]= a[i]
- copy temp at beginning 

[1 2 3 4 5 6 7], k=2

temp = [6 7]

shift:
_ _ 1 2 3 4 5

copy temp:

6 7 1 2 3 4 5 

Notes:
handle n==0
k=k%n
backward loop-> shift back to front*/

void better(vector<int> &a, int n, int k){
    if(n==0)
    return;

    k=k%n;
    vector<int> temp(k);
    // 0...n-k-1...n-k...n-1 
    for(int i=n-k; i<n; i++){ //last k ele index
        temp[i-(n-k)] = a[i]; //temp[curr-(n-k)] -> temp(index) -> 0 1 2..
    }

    for(int i = n-k-1; i>=0; i--){ 
        a[i+k] = a[i]; 
    }

    for(int i = 0; i<k; i++){
        a[i]=temp[i]; 
    }
}


/* optimal: 
- reverse whole
-reverse 1st k
reverse remaining */

void optimal(int a[], int n, int k){
    k = k%n;
    reverse(a, a+n); // 0 to n-1
    reverse(a, a+k); //0 to k-1
    reverse(a+k, a+n); //k to n-1

}


int main(){
    int n;
    cin>>n;
     vector<int> a(n);  
     for(int i=0; i<n; i++){
        cin>>a[i];
     }

     int k;
     cin>>k;
     better(a,n,k);
     for(int i =0; i<n; i++){ //for(auto it: a){cout<<it<<" ";}
        cout<< a[i]<<" ";
     }

     return 0;
}