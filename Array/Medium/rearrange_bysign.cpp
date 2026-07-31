/* ip: (equal numbers of -ve, +ve ele)
op: maintain order , alternate sign (+ - +  -)

Input: arr[] = {1,2,-4,-5}, N = 4
Output: 1 -4 2 -5
*/

/* brute: 
- create +ve & -ve array (list)
- put each ele in respective array
- put +ves in even idx(0 2 4), -ves in odd idx ( 1 3 5) 

Tc: n + n/2
SC: n/2 +n/2*/

vector<int> brute (vector<int> &a, int n){
    vector<int> pos;
    vector<int> neg;
    for(int i=0; i<n; i++){
        if (a[i]>0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }

    for(int i=0; i<n/2; i++){ //equal halfs 
        a[2*i] = pos[i];
        a[2*i + 1] = neg[i];
    }
    return a;

}

/* optimal: Tc: n SC: n(return ans)
- 0 1 2 3 
  + - + - (next +ve no ahead by 2 from last +ve)
- create ans array, put no directly as per idx
 */

 vector<int> optimal(vector<int>&a, int n){
    int pos =0, neg =1;
    vector<int> ans(n, 0);
    for(int i=0; i<n; i++){
        if(a[i]>0){
            ans[pos]=a[i];
            pos += 2; //next pos idx
        }
        else {
            ans[neg] = a[i];
            neg += 2; //next -ve idx
        }
    }
    return ans;
 }


 /* variety: 
 
 ip: not equal number of +ve -ves (pos != neg) -> pos>neg or pos<neg
 if remain , add at end w/o changing order 

 - not optimal(as it alternate idx), go back to brute force

 TC: n + min(pos,neg) + extra = n
 SC: n/2, n/2
 */

 vector<int> alternate(vector<int> &a, int n){
    vector<int> pos, neg;
    for(int i=0; i<n; i++){
        if(a[i]>0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    if(pos.size()>neg.size()){
        for(int i=0; i<neg.size(); i++){ //fill smaller array frst
            a[2*i] = pos[i];
            a[2*i +1 ] = neg[i];
        }
        int index = neg.size() * 2 ; //array filled equal no of +ves -ves
        //fill remaining pos
        for(int i = neg.size(); i<pos.size(); i++){
            a[index] = pos[i];
            index++;
        }

    }
    else{
        for(int i=0; i<pos.size(); i++){ //fill smaller array frst
            a[2*i] = pos[i];
            a[2*i +1 ] = neg[i];
        }
        int index = pos.size() * 2 ; //array filled equal no of +ves -ves
        //fill remaining neg
        for(int i = pos.size(); i<neg.size(); i++){
            a[index] = neg[i];
            index++;
        }

        
    }
    return a;
 }