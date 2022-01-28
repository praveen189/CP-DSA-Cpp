#include<iostream>
#include<vector>

using namespace std;
void generateParenthesis(vector<string> &s, int o, int c, string op){

    if(o == 0 && c == 0){
        // leaf node 
        s.push_back(op);
        return;
    }
    if(o != 0){
        string op1 = op;
        op1.push_back('(');
        generateParenthesis(s,o-1, c, op1);
    }

    if(c > o){
        string op2 = op;
        op2.push_back(')');
        generateParenthesis(s,o,c-1,op2);
    }
    return;
}
int main(){

    //Generate All Parentheses II
    int n = 3;
    int o = n;
    int c = n;

    string op = " ";

    vector<string> s;
    generateParenthesis(s, o, c, op);

    for(int i = 0; i<s.size(); i++){
        cout<<s[i]<<" ";
    }

    return 0;
}