#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

// Array based Implementation of Stack

class Stack
{
    int st[SIZE];
    int topPosition = -1;

public:

    void push(int val){
        topPosition++;
        st[topPosition] = val;
    }

    void pop(){
        topPosition--;
    }

    int top(){
        return st[topPosition];
    }

    bool isEmpty(){
        return topPosition < 0;
    }

};

int main()
{
    Stack st;

    for(int i=1; i<=5; i++)
        st.push(i);


    while(!st.isEmpty()){
        cout << st.top() << endl;
        st.pop();
    }

    for(int i=100; i<=105; i++)
        st.push(i);


    while(!st.isEmpty()){
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}
