#include<iostream>
#include<vector>
#include<bits/stdc++.h>


using namespace std;
void subSetOfVector( vector<vector<int>> &ans, vector<int> ip,vector<int> op ){
    // bs 
    if(ip.size() == 0){
        ans.push_back(op);
        return;
    }

    vector<int> op1 = op;
    vector<int> op2 = op;

    op2.push_back(ip[0]);
    ip.erase(ip.begin()+0);

    subSetOfVector(ans,ip, op1);
    subSetOfVector(ans,ip, op2);

    return;
}
int main(){

    vector<int> v = {1,2,3};
    
    vector<int> op;

    vector<vector<int>> ans;
    subSetOfVector(ans,v, op);

    sort(ans.begin(), ans.end());

    for(int i = 0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }

    return 0;
}