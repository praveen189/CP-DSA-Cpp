#include <iostream>
#include <vector>

// notes:
// TC - O(2^n)
// SC - O(1)

using namespace std;
int ks(vector<int> &wt, vector<int> &val, int n, int w)
{
    // recursion
    // bc
    if (n == 0 || w == 0)
    {
        return 0;
        // no profit
    }

    // code
    if (wt[n - 1] <= w)
    {
        // 2 case lo, na lo
        return max((val[n - 1] + ks(wt, val, n - 1, w - wt[n - 1])), ks(wt, val, n - 1, w));
    }
    else if (wt[n - 1] > w)
    {
        // one case na lo
        return ks(wt, val, n - 1, w);
    }
}

int main()
{
    //1. 0 - 1 knapsack
    vector<int> wt = {10,20,30};
    vector<int> val = {60,100,120};
    int w = 50; // 7kg

    int n = wt.size();
    int ans = ks(wt, val, n, w);
    cout << " Max profit: " << ans;

    return 0;
}