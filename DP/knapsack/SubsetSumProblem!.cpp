// Subset Sum Problem!



int Solution::solve(vector<int> &val, int w) {
    // top down approach

    int n = val.size();

    bool t[n+1][w+1];
    

    // initialize
    // imp to take care w+1 row ............. this is w
    for(int i = 0; i<w+1; i++){
        t[0][i] = false;
    }

// imp to take care w+1 column  this is w
    for(int j = 0; j<n+1; j++){
        t[j][0] = true;
    }

// top down approach
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<w+1; j++){

            if(val[i-1] <= j){
                t[i][j] = (t[i-1][j- val[i-1]] || t[i-1][j]);
            }
            else {
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][w];

}
