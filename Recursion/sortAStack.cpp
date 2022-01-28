#include<iostream>
#include<vector>
#include<stack>


using namespace std;

void insertIntoStack(stack<int> &s, int temp){
    if(s.size() == 0 || s.top() <= temp){
        s.push(temp);
        return;
    }

    int temp1 = s.top();
    s.pop();

    insertIntoStack(s, temp);

    s.push(temp1);
}
void sortStack(stack<int> &s){
    if(s.size() == 1){
        return;
    }

    int temp = s.top();
    s.pop();

    sortStack(s);

    insertIntoStack(s,temp);

    return;
    
}
int main(){

    stack<int> s;

    s.push(0);
    s.push(1);
    s.push(5);
    s.push(2);


    sortStack(s);

    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
        
    }
    
    return 0;
}