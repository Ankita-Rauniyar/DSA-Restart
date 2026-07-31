/* best time to buy & sell stock
- maximize profit (sell - buy)
- buy before sell 

Har din ko selling day maan lo.
Profit = current price − minimum price seen so far.
Maximum profit update karo.
Current price agar aur chhota hai to minimum buy price update kar do.

Input: arr = [10, 7, 5, 8, 11, 9]
Output: 6
Buy on day 3 (price = 5) and sell on day 5 (price = 11), 
profit = 11 - 5 = 6.

- if no transaction op: 0
*/

int profit(vector<int> &a, int n){
    int mini = a[0]; // min buy price till now
    int maxprofit = 0; 
    for(int i=1; i<n; i++){ //sell every day
        int profit = a[i] - mini; //profit on ith day
        maxprofit = max(maxprofit, profit);
        mini = min(mini, a[i]); //update for future
    }
    return maxprofit;
}