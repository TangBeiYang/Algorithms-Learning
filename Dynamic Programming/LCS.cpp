#include<iostream>
#include<vector>
using namespace std;
inline int max(int a, int b)
{
	if (a >= b)return a;
	return b;
}
int longest_Common_Subsequence(string text1, string text2)
{
	int m = text1.length(), n = text2.length();
	// dp[i][j] represents LCS of text1[0..i-1] and text2[0..j-1]
	vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			if (text1[i - 1] == text2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	return dp[m][n];
}
string lcs_string(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 构建DP表
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // 回溯构建LCS字符串
    string result;
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            result = s1[i - 1] + result;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    return result;
}
int main()
{
	string a = "QWERTYUIO";
	string b = "RTYNMNMYUINMNMQWER";
	cout << lcs_string(a, b);
}