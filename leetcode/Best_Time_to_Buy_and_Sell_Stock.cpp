/*
For each price, I only need to find the minimal price before it.
*/
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min=std::numeric_limits<int>::max(),ans=0,n=prices.size();
        for (int i=0;i<n;i++)
        {
            min=min<prices[i]?min:prices[i];
            ans=ans>prices[i]-min?ans:prices[i]-min;
        }
        return ans;
    }
};