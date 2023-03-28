class NumArray {
private:
    int n;
    vector<int> BIT;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->n = nums.size();
        this->nums = nums;
        BIT = vector<int>(n+1, 0);
        for (int i=0; i<n; i++){
            update1(i, nums[i]);
        }
    }
    void update1(int index, int val) {
        index++;
        while(index <= n){
            BIT[index] += val;
            index += index & (-index);
        }
    }
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        index++;
        while(index <= n){
            BIT[index] += diff;
            index += index & (-index);
        }
    }
    
    int getSum(int index){
        int sum = 0;
        index++;
        while(index > 0){
            sum += BIT[index];
            index -= index & (-index);
        }
        return sum;
    }
    
    int sumRange(int left, int right) {
        int sum1 = getSum(right);
        int sum2 = getSum(left-1);
        return sum1 - sum2;
    }
};
// https://leetcode.com/problems/range-sum-query-mutable/
