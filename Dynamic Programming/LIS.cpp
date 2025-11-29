#include<iostream>
#include<vector>
using namespace std;
inline int max(int a, int b)
{
	if (a >= b)return a;
	return b;
}
int length_of_LIS(vector<int>& nums) {
    int n = nums.size();
	if (n == 0) return 0;
	vector<int> dp(n, 1);
	int max_len = 1;
	for (int j = 1; j < n; j++) {
		if (nums[j-1] < nums[j]) {
			dp[j] = dp[j-1] + 1;
		}
		max_len = max(max_len, dp[j]);
	}
	return max_len;
}