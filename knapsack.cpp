#include <bits/stdc++.h>
using namespace std;

int rec_knapsack(int n, int capacity, vector<int> values, vector<int> weights)
{
    if (n <= 0)
        return 0;

    int take = 0, notake = 0;
    if (capacity >= weights[n - 1])
        take = values[n - 1] + rec_knapsack(n - 1, capacity - weights[n - 1], values, weights);

    notake = rec_knapsack(n - 1, capacity, values, weights);
    return max(take, notake);
}

int memo_knapsack(int n, int capacity, vector<int> values, vector<int> weights, vector<vector<int>> &dp)
{
    if (n <= 0)
        return 0;

    if (dp[n][capacity] != -1)
        return dp[n][capacity];

    int take = 0, notake = 0;
    if (capacity >= weights[n - 1])
        take = values[n - 1] + memo_knapsack(n - 1, capacity - weights[n - 1], values, weights, dp);

    notake = memo_knapsack(n - 1, capacity, values, weights, dp);

    return dp[n][capacity] = max(take, notake);
}

int tab_knapsack(int n, int capacity, vector<int> values, vector<int> weights)
{
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the DP table bottom-up
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][capacity];
}

int main()
{
    vector<int> values = {1, 2, 3};
    vector<int> weights = {4, 5, 1};
    int n = weights.size();
    int capacity = 4;

    cout << "Using recursion: " << rec_knapsack(n, capacity, values, weights) << endl;

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    cout << "Using memoization: " << memo_knapsack(n, capacity, values, weights, dp) << endl;

    cout << "Using tabulation: " << tab_knapsack(n, capacity, values, weights) << endl;

    return 0;
}
