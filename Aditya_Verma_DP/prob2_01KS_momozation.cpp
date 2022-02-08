#include<iostream>
#include<vector>

using namespace std;
int t[10][10];

int ks(vector<int> wt, vector<int> val, int n, int w){
    // bc
    if(n == 0 || w == 0){
        return 0;
    }

    // memozation

    // if(t[n][w] != 0)
    if(wt[n-1] <= w){
        // 2 cond.
        return t[n][w] = max( (val[n-1] + ks(wt, val, n-1, w-wt[n-1])), ks(wt, val, n-1, w));
    }

    else{
        return t[n][w] = ks(wt, val, n-1,w);
    }
    //return t[n][w];


}
int main(){
    // using memozation 
    vector<int> wt = {10, 20,30};
    vector<int> val = {60,100,120};
    int w = 50;

    int n = wt.size();

    cout<<ks(wt, val,n, w);
    return 0;
}