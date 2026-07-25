#include<bits/stdc++.h>
using namespace std;

/* A sorted(ascending) rotated array can have only ONE decreasing point.

nums[i] > nums[(i+1)%n] 
if %n missing, then a[n], out of bound as last a[n-1]

Example:
[3,4,5,1,2]

Break:
5 > 1  (only one)
a[4] > a[(4+1)%5] i.e. a[0] 

If breaks > 1:
Not possible  eg: [2,1,3,4] -> 2>1, 4>2 


Sorted array → 0 breaks
Sorted rotated array → 1 break
More than 1 break → false
*/

bool isSortedRotated(vector<int>&a, int n){
    int count =0;
    
    for (int i=0; i<n; i++){
        //compare curr with next
        //(i+1)%n makes array circular
        //last compared with first

        if(a[i] > a[(i+1)%n]){ //check decreasing point
            count++;
        }
    }

    //sorted rotated array atmost 1 break
    //return count<=1; //condition auto return true/false
    if(count <= 1)
    {
    return true;
    }
    else
{
    return false;
}
}

/* (check sorted or not)
 for (int i =1; i<nums.size(); i++){ //no need to check for 1st ele
                if ( nums[i]>=nums[i-1]){ //ascending order
                }
                else {
                    return false;
                }
            }
            return true; //if already sorted 
*/

int main(){
    vector<int> a ={3,4,5,1,2};
    if(isSortedRotated(a, n))
        cout << "true";
    else
        cout << "false";


    return 0;
}

