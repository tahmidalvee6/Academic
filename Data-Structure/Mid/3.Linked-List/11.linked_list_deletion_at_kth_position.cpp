// Deletion at k th position
// amdr pos e jeta ase sheta delete korte hobe
// ei jnno pos - 1 ta k amdr k pos + 1 er shthe point koraite hbe
// akhn amdr pos - 1 pojjonto amdr traverse korte hbe..eta k amra prev nam dibo
// prev er next hbe prev er next er next... prev er next tw pos ta hbe



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
        second_last = second_last->next;            
    }
    
    Node* temp = second_last->next;            
    second_last->next = NULL;                   
    free(temp);
}

void deleteatposition(Node* &head, int pos) {
    if(pos == 0) {
        deleteathead(head);    // pos jodi 0 th pos e hoy taile amra deletionathead func k call dile e hoy
        return;
    }
    // jodi pos 0 na hoy taile amdr traverse korte hbe pos - 1 pojjonto
    int curr_pos = 0;           // jeta start hbe 0 theke
    Node* prev = head;          // jeta start hobe head theke
    while(curr_pos != pos - 1) {
        prev = prev->next;
        curr_pos++;
    }

    // akhn prev is pointing to node at pos - 1;
    // amdr delete korte hbe prev next k

    Node* temp = prev->next;        // tai jetake delete krbo ba prev er next k akta temp er modde rakhbo
    prev->next = prev->next->next;    // prev er next k point korai disi prev er next er next k
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
    // deleteathead(head);
    // display(head);
    // deleteattail(head);
    // display(head);
    deleteatposition(head, 1);     // mane pos 1 ta delete korbo
    display(head);
}


