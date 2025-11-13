// Insertion at k th positin in a singly linked list :
// jodi notun akta node amdr linked list er staring e insert korte hobe
// etar jnno amdr j notun node oita akhn head node...erpor hoya dorkar amdr ager head node
// erpor amra head pointer k amra new node point korbo


#include<iostream>
using namespace std;
class Node {
    public :
    int val;
    Node *next;

    Node(int data){ 
        val = data;     
        next = NULL;    
    }
};

void insertathead(Node* &head, int val) {   // eikhane head pointer ta dilam karon eikhan thke linked list shuru hobe...
                                            //eta pass by ref nisi karon amdr linked list chng korte hbe
                                            // trpr akta value dibo jeta insert korte chai
    Node* new_node = new Node(val);         // erpr amra new node create krbo jetate amra value pass korbo...etr next kisu likhi nai mane er porer ta null indicate krbe
    new_node->next = head;                  // new node er next e amdr current linked list er head ta rakhte hobe
    head = new_node;                        // erpr head pointer point korbe akhn new node k
}

// akhn linked list ta print korbo
// akhn print korar jnnno amdr travarsal korte hobe
void display(Node* head) {              // akta func e linked list k pass korbo tar head pass kore...eikhne pass by val hbe karon kono chng kortesi  na
    // Travarsal
    Node* temp = head;                  
    while(temp != NULL) {
        cout<<temp->val<<endl;   // jdi temp is not equla null hoy taile amra current j node ase oitar value print krbo
        temp = temp->next;       // erpr temp ta k porer node e niye abr condtion chck kore print krbo
    }
    cout<<"NULL"<<endl;         // last node ta point korbe null
}

int main() {  
    // akhn amra empty linked list theke try krbo...mane kono node thakbe na... mne head pointer ta point korbe null k
    Node* head = NULL;              // mane head pointer ta point kortese null k
    insertathead(head, 2);          // eikhne head pointer e first 2 insert korbo
    display(head);                  
    insertathead(head, 1);
    display(head);


}
