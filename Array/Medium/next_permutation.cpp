/* ip: 1,3,2
   permutations: (rearrange all in ascending(lexicographic order) 
   [1,2,3] , [1,3,2], [2,1,3], [3,1,2], [3,2,1]
   op: [2,1,3] (next after ip) 
   
   if 3,2,1 given as ip -> op: 1,2,3 (lowest posiible i.e. 1st one)*/

   /* brute: recursion + linear search 
   TC:(n! * n) (very high order)
   SC: n! (store all permutation)

   - generate all possible (use recursion, then sort)
   - linear search of ip, return next idx  permutation
   - if no next exist, return 1st */


   /* better: C++ STl

   next_permutation(a.begin(), a.end());
   return a;  
   */

   /* optimal: implement STL
   
   - next permutation = same longest prefix ; slightly larger number
   - break point: from right 1st idx where a[i]<a[i+1]
   - from right, find 1st just greater ele than a[idx] ->swap
   - reverse remaining right part (ascending order)
   - no break point(i.e. already in dedecnding order) -> reverse whole array(last permutation -> 1st permutation)

   Find Break → Find Just Greater → Swap → Reverse Right Part

   !! reverse bcoz right part after break point is already in descending order

1 2 5 4 3

Break = 2
Swap 2 ↔ 3

1 3 5 4 2

Reverse after 3
1 3 2 4 5


TC: n ( break point + linear reverse) SC: 1
*/

void nextPermute(vector<int>&a, int n){
   int idx = -1; //break point
   for (int i = n-2; i>=0; i-- ){//backward
      if(a[i]<a[i+1]){
         idx =i;
         break;
      }
   }

      if(idx == -1){ //edge case (last permute)
         reverse(a.begin(), a.end());
         return;
      }

      for(int i = n-1; i>idx; i--){
         if(a[i]>a[idx]){ //just greater
            swap(a[i], a[idx]);
            break;
         }
      }

      //remaining right part
      reverse(a.begin()+idx+1, a.end());  
   }





    