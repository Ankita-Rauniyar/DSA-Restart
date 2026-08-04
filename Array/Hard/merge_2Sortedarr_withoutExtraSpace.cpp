
/* brute: extra space allowed (ans arr) (2(n+m) traverse)
- compare ele of both arr, store in correct pos in third arr 
- put every ele back in arr1 */



/* optimal1: swap +sort(w/o extra space) (no extra space given in any arr)
a = [-5,-2,4,5]
b = [-3,1,8]
TC: O(min(m,n) + mlogm + nlogn)

- compare largest of a(last ele) with smallest b(1st ele)
- swap if a>b,  segregate arr into smaller larger
- then sort both 
 */

 #include<bits/stdc++.h>
 using namespace std;

 void merge1(vector<int>&a,vector<int>&b){
    int m = a.size();
    int n = b.size();
    int left = m-1; //last
    int right = 0; //1st of b
    while(left>=0 && right<n){
        if(a[left]> b[right]){ //means ele galat arr mei h
            swap(a[left], b[right]);
            left--;
            right++;
        }
        else{
            break; //both arr already sorted(smaller/larger)
        }
    }
    sort(a.begin(), a.end()); //after swap(as misplaced) 
    sort(b.begin(), b.end()); 
 }

 /* optimal2: gap method(no extra space) (optimised sol, TC same)
 TC: O((m+n) log(m+n)) = number of gaps(n/2, n/4,n/6...) × comparisons per gap(N(array traverse))
 
 - dono arrays ko ek combined virtual array maan lo(a+b)
 - compare using gap like shell sort (improved insertion sort)
 - avoid sorting whole array
 */

 int nextgap(int gap){
    if(gap<=1) return 0;
    return (gap/2)+(gap%2); //ceil(gap/2)
 }

void merge2(vector<int>&a, vector<int>&b){
    int m= a.size();
    int n = b.size();
    int len = m+n; //virtual combined arr
    int gap = nextgap(len); 
    while(gap>0){
        int left=0;
        int right = left + gap;
        while(right<len){
            if(left<m && right<m){ //both pointers in a
                if(a[left]>a[right])
                swap(a[left], a[right]);

            }
            //left in a, right in b
            else if(left<m && right>=m){
                if(a[left]> b[right-m]) //(virtual idx - a size = b idx)
                swap(a[left], b[right-m]);
            }
            //both pointers in b
            else{
                if(b[left-m]>b[right-m])
                swap(b[left-m],b[right-m]);
            }
            left++;
            right++;
        }
        gap = nextgap(gap); //reduced gap
    }
}


/*  Extra empty space in arr1 (3 pointers) -> O(m+n)

Input : nums1 = [-5, -2, 4, 5, 0, 0, 0], nums2 = [-3, 1, 8]
Output : [-5, -3, -2, 1, 4, 5, 8] 

-start se merge karne pe, existing ele overwrite hoskta h(may lose)
so end se fill karenge(largest at end)

*/

void merge3(vector<int>&a, int m, vector<int>&b, int n){
    int i = m-1; //a valid end
    int j = n-1; //b end
    int k = m+n-1; //a final end
    while(i>=0 && j>=0){
        if(a[i]>b[j]){
            a[k]= a[i];
            i--;
        }
        else{
            a[k]=b[j];
            j--;
        }
        k--;
    }

    while(j>=0){ //if ele left, copy
        a[k]=b[j];
        j--;
        k--;
    }
    //no need for a remaing ele, as already in place
}


 int main(){
    vector<int>a= {-5, -2, 4, 5,0,0,0};
    vector<int>b ={-3, 1, 8};
   merge3(a,4,b,3);
   for(auto it: a) cout<<it<<" ";
  
   return 0;
 }