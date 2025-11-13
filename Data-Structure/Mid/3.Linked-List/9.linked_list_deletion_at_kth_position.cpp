// Deletion at k th position
// Delete a node at the start
// ei jnno amdr head pointer k move korte hobe head er next e
// ei jnno first e amdr akta temp var nibo jetate current head k rakhbo...erpr head k next e shift krbo..
// erpr temp ta k delete kore dibo



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

void updateatposition(Node* &head, int k, int val) {  
    Node* temp = head;
    int curr_pos = 0;

    while(curr_pos != k) {
        temp = temp->next;
        curr_pos++;
    }
    
    temp->val = val;
}

void deleteathead(Node* &head) {
    Node* temp = head;          // node to be deleted
    head = head->next;
    free(temp);             // akhn temp er modde ager head ta ase...akhn ami free funciton diye temp ta memory te jototuk space khaitese ta delete kore dite pari

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
    deleteathead(head);
    display(head);
}

