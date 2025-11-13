// Delete the duplicate element


// akta sorted linked list e duplicate element gula k delete korte hbe
// 1,2,2,3,3,3...eirokom thakbe....1,2,3 korte hbe

// akhn amra linked list k head theke traverse korbo
// jodi current node r current node er next same hoiya jae 
// taile current node ta k thik rakhbo bt current node er next ta k delete kore dibo
// akhn j current ta k thik rakhsi oitar shthe curr er next er next ta compare krbo
// jodi same hoy taile current ta k thik rekhe oita dlt kore dibo....evabe cholte thakbe jodi same hoy
// jodi same na hoy taile current pos update korte thakbo


// akhn amra akta pointer banaitesi current node er
// current node ta jotokhon na null er shoman hobe totokhon loop cholbe
// akhn amdr current pos akta node e ase
// akhn amdr akta loop chalaite hbe jotokhon na current and current er next equal ase totkhon amdr current er next k shoraite hbe
// totkhon current er next k delete korbo jotokhon same hbe
// arekta condition add korte hbe 
// current er next null hoite parbe na



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

void updateatposition(Node* &head, int k, int value) {  
    Node* temp = head;         
    int curr_pos = 0;         

    while(curr_pos != k) {      
        temp = temp->next;
        curr_pos++;
    }
    
    temp->val = value;
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
        deleteathead(head);    
        return;
    }
   
    int curr_pos = 0;           
    Node* prev = head;          
    while(curr_pos != pos - 1) {
        prev = prev->next;
        curr_pos++;
    }

    
    Node* temp = prev->next;        
    prev->next = prev->next->next;    
    free(temp);

}

void reverseprint(Node* head) {
    // base conditon
    if(head == NULL) {          
        return;
    }

    // recursive case
    reverseprint(head->next); 

    cout<<head->val<<" ";
    
}

void deleteduplicatenode(Node* &head) {
    Node* curr_node = head;
    while(curr_node != NULL) {
        while(curr_node->next != NULL && curr_node->val == curr_node->next->val) { // jotokhon na current node er value r current node er next er value equal totokhon cholbe
            // totokhon current node er next k delete korte thakbo
            Node* temp = curr_node->next;    // node to be deleted
            curr_node->next  = curr_node->next->next;
            free(temp);
        }
        // 2nd while loop ta shesh hbe jkhn current node r next node value are different or linked list end hoile
        curr_node = curr_node->next;        // totokhon amdr current node k 1 step kore age baraite hbe
    }
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
    //deleteatposition(head, 1);     
    //display(head);

    reverseprint(head);
    //display(head);

    deleteduplicatenode(head);
    display(head);
}




// eikhane sorted way te code ta nai...
// r dupdicate node ta o nai



