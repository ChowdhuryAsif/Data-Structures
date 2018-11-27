#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

// Array based Implementation of Stack

class Stack
{
    int st[SIZE];
    int topPosition;
    int backPosition = 0;

public:

    void push(int val){
        st[backPosition] = val;
        backPosition++;
        topPosition = backPosition - 1;
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

    for(int i=1; i<=10; i++)
        st.push(i);

    if(!st.isEmpty())
        cout << "Not empty" << endl;
    else
        cout << "Empty" << endl;

    while(!st.isEmpty()){
        cout << st.top() << endl;
        st.pop();
    }

    if(!st.isEmpty())
        cout << "Not empty" << endl;
    else
        cout << "Empty" << endl;

    return 0;
}
