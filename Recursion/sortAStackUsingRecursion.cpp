#include<iostream>
#include<stack>

using namespace std;

void insertRecr(stack<int> &s, int temp){
    // BC: if stack is empty and  s.top ele is smaller then the temp val then we have to just inser t at bottom of stacka or top of stack.
    if(s.size() == 0 || s.top() <= temp){
        s.push(temp);
        return;
    }

    // hypo
    int temp1 = s.top();
    s.pop(); 
    // size of stack get reduced to n-1;
    insertRecr(s,temp);
    // now we will be having temp at its right position
    s.push(temp1);

    return;
}
void sortStack(stack<int> &s){
    // if stack have one ele then it is sorted
    // bc
    if(s.size() == 1){
        return;
    }

    int temp = s.top(); // top ele get stored 
    s.pop();

    // hypo
    sortStack(s); // this will give us a sorted stack of size n-1;

    // induction
    // we have to insert at right postion to temp.
    insertRecr(s, temp);

    return;
}
int main(){
    // sort an stack.
    stack<int> s;
    s.push(0);
    s.push(1);
    s.push(5);
    s.push(2);


    sortStack(s);

    cout<<"I am back!!!";
    
    while (s.size() >= 1)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    

    return 0;
}