class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mx {};
        int l {}, r = l + 1;
        while(r < prices.size()) {
            if (prices[r] - prices[l] > mx) {
                mx = prices[r] - prices[l];
                r++;
            } else if (prices[r] < prices[l]) {
                l = r;
                r++;
            } else {
                r++;
            }
        }
        return mx;
    }
};
