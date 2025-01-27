#include <vector>

class Solution {
public:
  int coinChange(std::vector<int> &coins, int amount) {
    const int oo = 1e9;
    std::vector<int> dp(amount + 1, oo);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
      for (auto c : coins) {
        dp[i] = std::min(dp[i], (i < c ? oo : 1 + dp[i - c]));
      }
    }
    return (dp[amount] == oo ? -1 : dp[amount]);
  }
};
