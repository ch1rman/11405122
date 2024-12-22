class Solution {
public:
 int maxProfit(vector<int>& prices) {
       if(!prices.size()) return 0;
       int maximum = 0;
       for(int i=1; i<prices.size(); i++)
            maximum = (prices[i]>prices[i-1]) ? (maximum+prices[i]-prices[i-1]) : maximum;
       return maximum;
    }
};


