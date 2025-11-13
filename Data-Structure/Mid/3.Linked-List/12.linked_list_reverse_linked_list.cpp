// Reverse linked list

// amdr linked list jodi 1->2->3->4 thake taile amra etake 4->3->2->1 emne print krbo
// amra jni amdr linked list amra akta direction e traverse korte pari
// amra reverse order e traverse korte pari na


// akhn kivabe amra reverse order e print kote pari
// akhn eikhane amra reccursion er help nite pari


// karon recursion er modde ki hoy
// amdr akta stack create hoy.. mane recursion stack
// recursion stack e ki hoy...j element first e dhuke oi element ta shbr last e ber hoy
// akhn amra jdi 1,2,3,4 serial by dhukai taile 4 age ber hobe trpr 3 trpr 2 trpr 1



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
    if(head == NULL) {          // head null hoye gele taile amra return kore dibo
        return;
    }

    // recursive case
    reverseprint(head->next); 

    cout<<head->val<<" ";
    
}
// 1,2,3,4
// eikhane amdr head er porer element gula recursion amdr print kore disse... last e giye head ta print kore dissi
// akhn ami recursively call korbo head er next then print head value
// first e recursive function call hobe jeikhane head is pointing to 1...
// akhn amdr recursive stack create hbe... jeikhane reverse 1 er jnno er jnno call hosse..mne head akhn stack 1 joma hoise...mane reverse(1)
// function ta abr call hobe for head er next er jnno... head er next hoilo 2...tw stack e 2 joma hobe... mane reverse(2)
// akhn reverse function for 2 call korbe head er next k...head ta 2 k point korle head er next point korbe head er next 3..mane 3 joma hobe...mane reverse(3)
// akhn reverse function for 3 call korbe head er next k...head ta 3 k point korle head er next point korbe head er next 4..mane 4 joma hobe...mane reverse(4)
// akhn head 4 k point kortese..tai 4 er next hobe null...akhn reverse function null k call korbe
// jkhn e reverse funciton null k call korbe tkhn amdr base condition k hit korbe...akhn head hbe null...null hoile return kore felte hbe
// akhn 4 er j recursive call ta hobe oita complete hbe...mane akhn head e ase 4...taile 4 ta print korbe
// 4 print korar por 4 er j recursive call ta complete hoi jabe...tai 4 ta stack theke remove hoye jabe
// akhn amdr function call ta hoisilo jkhn amdr head 3 te chilo...akhn 3 er ta complte ta krbe
// erpr 2 er jnno korbe...erpr 1 er jnno korbo
// akhn amdr stack khali hoi gese
// mane amra amdr linked list ta reverse order e print kore disi


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
}




