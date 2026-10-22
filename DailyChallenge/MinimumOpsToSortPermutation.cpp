class Solution {
public:
int minOperations(vector<int>& nums) {
int n = nums.size();
int zero = find(nums.begin(), nums.end(), 0) - nums.begin();

    bool forward = true;
    bool backward = true;

    for (int i = 1; i < n; i++) {
        int a = (zero + i - 1) % n;
        int b = (zero + i) % n;

        if (nums[a] > nums[b])
            forward = false;

        a = (zero - i + 1 + n) % n;
        b = (zero - i + n) % n;

        if (nums[a] > nums[b])
            backward = false;
    }

    int ans = INT_MAX;

    if (forward) {
        ans = min(ans, zero);
        ans = min(ans, n - zero + 2);
    }

    if (backward) {
        ans = min(ans, zero + 2);
        ans = min(ans, n - zero);
    }

    return ans == INT_MAX ? -1 : ans;
}

};