#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

// Array based queue implementation;

class Queue
{
    int Q[SIZE];
    int frontIndex = 0;
    int backIndex = 0;

public:

    void enqueue(int z){
        Q[backIndex] = z;
        backIndex++;
    }

    void dequeue(){
        frontIndex++;
    }

    int Front(){
        return Q[frontIndex];
    }

    bool isEmpty(){
        return frontIndex == backIndex;
    }
};

int main()
{
    Queue Q;

    for(int i=1; i<=10; i++){
        Q.enqueue(rand()%100);
    }

    if(Q.isEmpty())
        cout << "Empty" << endl;
    else
        cout << "Not Empty" << endl;

    while(!Q.isEmpty()){
        cout << Q.Front() << endl;
        Q.dequeue();
    }

    if(Q.isEmpty())
        cout << "Empty" << endl;
    else
        cout << "Not Empty" << endl;


    return 0;
}
