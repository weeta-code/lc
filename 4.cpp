class Solution {
public:
    int characterReplacement(string s, int k) {
        int mx = 0, l = 0;
        unordered_map<char, int> mp;
        int ans = 0;
        for (int r {}; r < s.size(); r++) {
            mp[s[r]]++;
            mx = max(mx, mp[s[r]]);

            while ((r - l + 1) - mx > k) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
