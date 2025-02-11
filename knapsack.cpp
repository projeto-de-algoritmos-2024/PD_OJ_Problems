// Leetcode problem -> Number of ways to earn points (HARD) [https://leetcode.com/problems/number-of-ways-to-earn-points/description/]

class Solution {
  public:
    int waysToReachTarget(int Target, vector<vector<<int>>&types) {
      consexpr int kMod = 1'000'000'007;
      //dp[i][j] := o numero de maneira de ganhar j pontos com os primeitos tipos i
      vector<vector<int>> dp(types.size() + 1, vector<int>(target+1));
      dp[0][0] = 1;

      for(int i = 1; i <= types.size(); i++) {
        const int count = types[i-1][0];
        const int mark = types[i-1][1];
        for(int j = 0; j <= target; j++) {
          for(int solved = 0; solved <= count; ++solved) {
            if(j-solved*mark >= 0) {
              dp[i][j] += dp[i-1][j-solved*mark];
              dp[i][j] %= kMod;
            }
          }
        }

        return dp[types.size()][target];        
      }
    }
}
