#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std;

// //void subsetRecur(vector<int> v){
//     // bc
//     if(v.size() == 0){
//         cout<<
//     }

// }

void subsetRecur(vector<string> &ans, string ip, string op){
    // bc for subset 
    if(ip.size() == 0){
        ans.push_back(op);
        return;
    }
    // hypo
    string op1 = op;
    string op2 = op;

    op2.push_back(ip[0]);
    
    ip.erase(ip.begin()+0);

    subsetRecur(ans, ip, op1);
    subsetRecur(ans, ip, op2);

    return;
}
int main(){
    // generate a matrix of all sub set 

    string s = "123";

    string op = "";
    vector<string> ans;

    subsetRecur(ans, s, op);
    sort(ans.begin(), ans.end());


    for(int i= 0;i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }


    return 0;
}