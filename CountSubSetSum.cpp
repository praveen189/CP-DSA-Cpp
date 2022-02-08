#include<iostream>
#include<vector>

using namespace std;

int countSubSet(vector<int> &wt, int n, int sum){
    // dp matrix
    // bc
    // code
    int t[n+1][sum+1];

    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<sum+1; j++){
            if(i == 0){
                t[i][j] = 0;
            }
            if(j == 0){
                t[i][j] = 1;
            }
        }
    }

    // code
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<sum+1; j++){
            if(wt[i-1] <= j){
                // 2 case, lo,  na lo
                t[i][j] =((t[i-1][j-wt[i-1]]) + t[i-1][j] );
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][sum];
}
int main(){
    // vector<int> wt = {1,2,3,7,8,10};
    vector<int> wt = {2,3,5,6,8,10};
    int sum = 10; /// sum
    
    int n = wt.size();
    cout<<"No of Subset possible are: "<<countSubSet(wt, n, sum);

    return 0;
}