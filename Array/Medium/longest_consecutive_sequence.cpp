//op: length of longest consecutive seq of integers(like 1 2 3 4) in any order

/* brute:
For every element:
    search x+1, x+2...
    count length

TC = O(n²)  */

bool linearsearch(vector<int>&a, int num){
    for(int i=0; i<n; i++){
        if(a[i]==num){
            return true;
        }
    }
    return false;
}

int brute(vector<int>&a, int n){
    if(n==0) return0;
    int longest =1;
    for(int i=0; i<n; i++){
        int x = a[i];
        int cnt =1;

        while (linearsearch(a, x+1)){ //check if next greater present or not
            x++;
            cnt++;
        }

        longest = max(longest, cnt);
    }
    return longest;
}


/* better: sorting (nlogn)
lastSmaller → previous number jo sequence me tha
cnt         → current sequence length
longest     → maximum length

 */

 int optimal(vector<int>&a , int n){
    if( n==0) return 0;

    sort(a.begin(), a.end());

    int longest = 1;
    int cnt = 1;
    int last = a[0];

    for(int i =0; i<n; i++){
        if(a[i]==last){ //duplicate skip
            continue;
        }
        else if(a[i]==last+1){
            cnt++;
            last = a[i];
        }
        else{
            cnt =1;
            last = a[i]; //start new sequence
        }

        longest = max(longest, cnt);
    }
    return longest;
 }

 /* optimal:  hashing n+n(set+traverse), n (set to store)
- every ele in unordered set (only unique)
seq starting point: jiska previous number(x-1) exist nahi karta -> seq descending hoga


x-1 absent?
    ↓
x is starting point

cnt=1
while(x+1 exists)
    x++
    cnt++

 */

 int optimal(vector<int>&a, int n){
    if(n==0) return 0;
    unordered_set<int> st;
    for(int x: a){
        st.insert(x);
    }
    int longest = 0;
    for(int x : st){
        if(st.find(x-1)==st.end()){ //x absent, starting point
            int cnt =1;
            int num =x; //start seq

            while(st.find(num+1) != st.end()){
                num++;
                cnt++;
            }
            longest = max(cnt, longest);
        }
    }
    return longest;
 }

