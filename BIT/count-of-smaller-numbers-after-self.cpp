class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());
        for (int i = 0; i < n; i++) {
            nums[i] = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) - sorted_nums.begin() + 1;
        }
        // cout<<endl;
        vector<int> BIT(n+1);
        for (int i = n-1; i >= 0; i--) {
            ans[i] = query(BIT, nums[i]-1);
            update(BIT, nums[i]);
        }
        return ans;
    }
private:
    void update(vector<int>& BIT, int i) {
        while (i < BIT.size()) {
            BIT[i]++;
            i += i & -i;
        }
    }
    int query(vector<int>& BIT, int i) {
        int res = 0;
        while (i > 0) {
            res += BIT[i];
            i -= i & -i;
        }
        return res;
    }
};
// https://leetcode.com/problems/count-of-smaller-numbers-after-self/
