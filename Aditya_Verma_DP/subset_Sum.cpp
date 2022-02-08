#include<iostream>
#include<vector>

using namespace std;

bool SubSet(vector<int> &wt, int n, int w){
    // DP matrix 
    // initialization 
    // code

    if (w == 0)
        return true;
    if (n == 0)
        return false;

    bool t[n+1][w+1];

    // initialization 
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<w+1; j++){
            if(i == 0){
                t[i][j] = false;
            }
            if(j == 0){
                t[i][j] == true;
            }
        }
    }

    // code
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<w+1; j++){
            if(wt[i-1] <= j){
                // 2 case lo, na lo
                t[i][j] = ( (t[i-1][j-wt[i-1]]) || t[i-1][j] );
            }
            else if(wt[i-1] > j){
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];

}
int main(){
    // subset problem 
    // if exist any subset return -- True
    // else -- False
    // vector<int> wt = {21,31,71,8,10};
    // vector<int> wt = {3, 34, 4, 12, 5, 2};
    vector<int> wt = {3, 34, 4, 12, 5, 2};
    int sum = 30;

    int n = wt.size();
    cout<<SubSet(wt, n,sum)<<endl;

    return 0;
}