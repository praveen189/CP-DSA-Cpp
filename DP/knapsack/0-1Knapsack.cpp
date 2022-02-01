int t[1002][1002];
//memset(t, -1, sizeOf(t));
// memset(t, -1, sizeof(t));


int knapscak(vector<int>&val, vector<int> &wt, int n, int w){
    // bc
    if(n == 0 || w == 0){
        return t[n][w] = 0;
    }

    // memoaization 
    if(t[n][w] != -1){
        return t[n][w];
    }

    // choice diagram 
    if(wt[n-1] <= w){
        // 2 choice 
        return t[n][w] = max( (val[n-1] + knapscak(val, wt, n-1, w-wt[n-1])), (knapscak(val, wt, n-1, w)) );
    }

    else if(wt[n-1] > w){
        return t[n][w] = knapscak(val, wt, n-1, w);
    }

    return t[n][w];
}

int Solution::solve(vector<int> &val, vector<int> &wt, int w) {
    // w- capacity 
    int n = val.size();
    memset(t, -1, sizeof(t));

    return knapscak(val, wt, n, w);

}
