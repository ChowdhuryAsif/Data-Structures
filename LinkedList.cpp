/**
*   author: Asif Ahmed Chowdhury
*   Southeast University
*   Dept. of CSE
**/

#include <bits/stdc++.h>
using namespace std;


class Node
{
    /// this is the Node field of list
public:
    int data;       //data field
    Node* next;     //next field which points to next node
};
Node* head; // initial head node

class List
{
    /// this is the field of which Operations can do this ADT
public:

    // Insertion in the List
    void Insert(int value){
        Node* temp = new Node();
        temp->data = value;
        temp->next = NULL;

        if(head == NULL)
            head = temp;        //Insertion at 1st position in the List
        else{
            Node* t = head;
            while(t->next != NULL)
                t = t->next;

            t->next = temp;      //Insertion at last in the List
        }
    }

    //Deletion from the List
    void Delete(int position){
        if(position == 1){
            Node* temp = head;
            head = head->next;  // deletion from 1st position

            free(temp); // memory will be free for this position
        }
        else{
            Node* temp1 = head;

            for(int i=1; i<=position-2; i++)
                temp1 = temp1->next;

            Node* temp2 = temp1->next;
            temp1->next = temp2->next;

            free(temp2);
        }
    }

    //Printing the List
    void Print(){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    head = NULL;    // Initially head points to NULL as there is no node or element in the List
    List myList;

    myList.Insert(2);
    myList.Insert(5);
    myList.Insert(9);
    myList.Insert(3);
    myList.Insert(8);
    myList.Insert(0);

    myList.Print();     //Printing after Insertion of some element

    myList.Delete(3);   // Deletion of a particular position

    myList.Print();     //Printing after Deletion

    return 0;
}
