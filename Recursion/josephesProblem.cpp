#include<iostream>
#include<vector>
using namespace std;

void solveJosephes(vector<int> v, int index, int k, int &ans){
    if(v.size() == 1){
        ans = v[0];
        return;
    }

    index = (index + k)%v.size();

    v.erase(v.begin()+index);

    solveJosephes(v, index, k, ans);

    return;

}
int main(){

    // josephes problem
    int n = 40;
    int k = 7;

    vector<int> v;
    for(int i =1; i<=n; i++){
        v.push_back(i);
    }

    k--;
    int index = 0;
    int ans = -1;

    solveJosephes(v,index, k, ans);

    cout<<"ans: "<<ans<<endl;
    return 0;
}