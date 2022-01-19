#include<iostream>
#include<vector>
#include<stack>

using namespace std;\

vector<int> NSLFun(vector<int> a, int n){
    stack<int> s;
    vector<int> ans;

    for(int i = 0; i<n; i++){
        if(s.size() == 0){
            // it means stack is empty.
            ans.push_back(-1);
        }
        else if(s.size() >0 && s.top() < a[i]){
            ans.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() >= a[i]){
            // we have to pop the large ele.
            // till we get stack as empty means -1;
            // or we get ele smaller to it
            while (s.size() >0 && s.top() >= a[i])
            {
                s.pop();
            }
            // two case for breaking the loop
            if(s.size() == 0){
                ans.push_back(-1);
            }
            else if(s.top()<a[i]){
                ans.push_back(s.top());
            }
            
        }
        s.push(a[i]);
    }
    return ans;

}

int main(){

    vector<int> v = {4,5,2,10,8};
    
    int n = v.size();

    vector<int> ans = NSLFun(v, n);
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}