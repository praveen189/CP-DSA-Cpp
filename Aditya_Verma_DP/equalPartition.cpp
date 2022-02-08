#include<iostream>
#include<vector>

using namespace std;

bool FindSubsetSum(vector<int> &wt, int n, int sum){
    // dp matrix.
    // initialization
    // code
    int t[n+1][sum+1];

    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(i == 0){
                t[i][j] = false;
            }
            if(j == 0){
                t[i][j] = true;
            }
        }
    }

    // code
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<sum+1; j++){
            if(wt[i-1] <= j){
                // 2 case. lo, na lo
                t[i][j] = ( (t[i-1][j-wt[i-1]]) || (t[i-1][j]) );
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

bool EqualSumPartition(vector<int> &wt, int n){
    // if sum[i] == odd then we can't deevide the sum into to equal subet sum 
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum +=wt[i];
    }

    if(sum %2 != 0){
        return false;
    }

    // else
    // s1 = s2 = sum/2
    return FindSubsetSum(wt, n, sum/2);

}

int main(){
    // equal sum partition 
    vector<int> wt = {2,5,11,5};

    int n = wt.size();
    cout<<"ANS:  "<<EqualSumPartition(wt, n);
    return 0;



}