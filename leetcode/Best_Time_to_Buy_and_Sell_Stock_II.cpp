/*
If you buy the stock in day i and you will get the profit in day i+1, you should by it.Each decreasing is the chance of getting profit.
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans=0,n=prices.size();
        for (int i=1;i<n;i++)
        if (prices[i]>prices[i-1]) ans+=prices[i]-prices[i-1];
        return ans;
    }
};