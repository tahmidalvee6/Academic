// Delete node at the last
// ei jnno amdr second last jeta ase shetake point koraite hobe null e
// tai amdr age second last node ta ber korte hbe
// akhn amdr second last node er next holo last node
// amdr second last node er next er next hobe NULL... mane amdr last node er next ta hobe NULL


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
    Node* temp = head;         
    head = head->next;
    free(temp);             

}

void deleteattail(Node* &head) {
    Node* second_last = head;
    while(second_last->next->next != NULL) {
        second_last = second_last->next;            // jotokhon na NULL hoy totokhon second last k age move korabo
    }
    // now second last poins to second last node
    Node* temp = second_last->next;             // node to be deleted
    second_last->next = NULL;                   // akhn second last er next e NULL diye disi tai amdr second last ta akhn amdr last node hoye jabe
    free(temp);
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
    deleteattail(head);
    display(head);
}


