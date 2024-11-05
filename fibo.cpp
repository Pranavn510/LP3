#include <bits/stdc++.h>
using namespace std;

vector<int> fibo_iterative(int n)
{
    vector<int> res;
    int fib1 = 0, fib2 = 1;
    while (n > 0)
    {
        res.push_back(fib1);
        int temp = fib1 + fib2;
        fib1 = fib2;
        fib2 = temp;
        n--;
    }
    return res;
}

int fibo_recursive(vector<int> &dp, int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    cout << n << " " << dp[n] << endl;
    if (dp[n])
        return dp[n];

    return dp[n] = (fibo_recursive(dp, n - 1) + fibo_recursive(dp, n - 2));
}

int main()
{
    cout << "Enter the n: ";
    int n;
    cin >> n;

    cout << "Using Iterative approach: ";
    vector<int> ans1;

    ans1 = fibo_iterative(n);
    for (auto x : ans1)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << "Using Recurssive approach: ";
    vector<int> dp(n + 1, 0);
    fibo_recursive(dp, n);
    for (auto it : dp)
    {
        cout << it << " ";
    }
    cout << endl;
}