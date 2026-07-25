/* Input:{1, 1, 0, 1, 1, 1} (0/1)
Output: 3 */

/*  Aprroach:
- count = current streak of 1s -> if break back to 0
- maxi = maximum streak found so far*/

int ans(vector<int>&a, int n){
    int count =0;
    int maxi=0;
    for(int i=0; i<n; i++){
        if(a[i]==1){
            count++;
            maxi = max(maxi, count);
        }
        else{
            count =0;
        }
    }
    return maxi;
}