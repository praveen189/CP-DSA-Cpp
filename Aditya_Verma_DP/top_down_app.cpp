// topdown approach

#include <iostream>
#include <vector>

using namespace std;
int TopDown(vector<int> wt, vector<int> & val, int n, int w){
    // matrix 
    // initialization
    // code 
    int t[n+1][w+1];

    // initialization 
    for(int i = 0; i<n+1; i++){
        for(int j = 0; j<w+1; j++){
            if(j == 0 || i== 0 ){
                t[i][j] = 0;
            }
        }
    }

    // code
    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<w+1; j++){
            if(wt[i-1] <= w){
                // 2 case
                t[i][j] = max( (val[i-1] + t[i-1][j-wt[i-1]]), (t[i-1][j]));
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }

    return t[n][w];

}
int main()
{
    // top down
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int w = 50;

    int n = wt.size();

    cout <<"Max profit: "<<TopDown(wt, val, n, w);
    return 0;
}