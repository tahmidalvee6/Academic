// Linked list er last e add korte chaile


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
    // akhn amdr last pojjonto jaite hbe mane travarsal korte hbe     
     Node* temp = head;
     while(temp->next != NULL)  {       // mne jotokhon temp null hobe na totokhon temp k age baraite thako
        temp = temp->next;
     }  
     // jodi condition r true na hoy... mane temp null ba last node e aisha porse
     temp->next = new_node;           // taile next e new node rakhbo....r new node er next e already constructor diye by default bole disi j null
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
}
