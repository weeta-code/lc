class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i {}; i < nums.size(); i++) {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1] ) continue;

            int l = i + 1;
            int r = nums.size() -1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }
        return ans;
    }
    // [-1, -0, 1, 2, -1, -4]
    /*
        [-4, -1, -1, 0, 1 2]
        sum = -2, target = 4
        sum = 1, target = 4
        sum = 1, target = 4
        sum = 2, target = 4
        sum = 3, target = 4
        break

        sum = -2, target = 1
        sum = 1, target = 1  l == i
        sum = 1, target = 1, triple (l, r, i) = (-1, 2, -1)
        target = 1 continue
        sum = -2, target = 0
        sum = 1, target = 0
        sum = 0, target = 0, triple 
    */   
};
