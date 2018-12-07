/**
*   author: Asif Ahmed Chowdhury
*   Southeast University
*   Dept. of CSE
**/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
public:
    Node *back = NULL;

    void push(int value){
        Node *n = new Node;

        n->data = value;
        n->next = back;
        back = n;
    }

    void pop(){
        Node *temp = back;
        back = temp->next;
        free(temp);
    }

    int top(){
        return back->data;
    }

    bool isEmpty(){
        return back == NULL;
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

    Stack mt;

    for(int i=10; i<=15; i++)
        mt.push(i);

    while(!mt.isEmpty()){
        cout << mt.top() << endl;
        mt.pop();
    }

    for(int i=110; i<=115; i++)
        mt.push(i);

    while(!mt.isEmpty()){
        cout << mt.top() << endl;
        mt.pop();
    }


    return 0;
}
