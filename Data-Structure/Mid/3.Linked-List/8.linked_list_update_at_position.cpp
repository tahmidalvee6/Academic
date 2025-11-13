// Kono akta pos e value update korar jnno

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

void insertathead(Node* &head, int val) {   
    Node* new_node = new Node(val);         
    new_node->next = head;                  
    head = new_node;                        
}

void insertattail(Node* &head, int val) {   
    Node* new_node = new Node(val);         
    
     Node* temp = head;
     while(temp->next != NULL)  {       
        temp = temp->next;
     }  
     
     temp->next = new_node;           
}

void insertatposition(Node* &head, int val, int pos){
    if(pos == 0) {
        insertathead(head, val);
        return;
    }

    Node* new_node = new Node(val);         
    Node* temp = head;
    int current_pos = 0;
    while(current_pos != pos - 1) {
        temp = temp->next;
        current_pos++;
    }
    
    new_node->next = temp->next;     
    temp->next = new_node;
}

void updateatposition(Node* &head, int k, int value) {  // eikhane first amdr linked list thakbe, erpr position deya thakbe, erpr updated value ta thakbe
    Node* temp = head;         // akta pointer banaisi jeta shuru hbe head theke
    int curr_pos = 0;          // position track korar jnno

    while(curr_pos != k) {      // jotokhon na amr curr pos k pojjonto na pouchai totokhon temp k age baraite hbe
        temp = temp->next;
        curr_pos++;
    }
    // akhn loop theke ber hoi temp will be pointed to the k th node
    temp->val = value;
}

void display(Node* head) {            
    // Travarsal
    Node* temp = head;                  
    while(temp != NULL) {
        cout<<temp->val<<"->";   
        temp = temp->next;       
    }
    cout<<"NULL"<<endl;         
}

int main() {  
    
    Node* head = NULL;              
    insertathead(head, 2);          
    display(head);                  
    insertathead(head, 1);
    display(head);
    insertattail(head, 3);
    display(head);
    insertatposition(head, 4, 1);
    display(head);
    updateatposition(head, 2, 5);
    display(head);
}

