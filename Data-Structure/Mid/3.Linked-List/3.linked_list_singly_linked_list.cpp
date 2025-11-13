// Singly Linked List 

// amndr jodi code linked list banaite hoy...taile amdr mathae rakhte hobe linked list gula built in na... mne int , double eirkom na
// amdr eigula define korte hbe... define korte hbe with the help of object oriented programming
// define korte hbe class er help e

// Syntax
/*
class Node {
    int value;      // eta holo data 
    Node *next;     // eta holo pointer to the next node
}
*/


#include<iostream>
using namespace std;
class Node {
    public :
    int val;
    Node *next;

    Node(int data){ // akta constructor banailam...
        val = data;     // jodi kono data pass kori ta node er  value field e store hoye jabe
        next = NULL;    // r next pointer e null store kore disi
    }
};

int main() {
    // jdi node er kono object create korte hoy
    Node *n = new Node(1);  // eikhane akta node create hobe jekhane value field e 1 store hoye jabe...r next e store hoye jabe NULL
    cout<<n->val<<" "<<n->next<<endl;
}

// Output : 1 0
