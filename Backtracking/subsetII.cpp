
void subSetOfVector( set<vector<int>> &ans, vector<int> ip,vector<int> op ){
    // bs 
    if(ip.size() == 0){
        ans.insert(op);
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
vector<vector<int> > Solution::subsetsWithDup(vector<int> &ip){
    vector<int> op;
    set<vector<int> > ans;

    sort(ip.begin(), ip.end());

    subSetOfVector(ans, ip, op);

    // sort(ans.begin(), ans.end());
    vector<vector<int> > res;

    for(auto it:ans){
        res.push_back(it);
    }
    
    return res;

}
