#include<iostream>
using namespace std;
class Node{
    public:
    
    int val;
    Node* next;
    
    Node(int data) {
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
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = new_node;
}

void insertatposition(Node* &head, int val, int pos) {
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
    new_node = temp->next;
    temp->next = new_node;
    
}



void deleteatfirst(Node* &head) {
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
}

void deleteatposition(Node* &head, int pos) {
    Node* prev = head;
    int curr_pos = 0;
    
    while(curr_pos != NULL) {
        prev = prev->next;
        curr_pos++;
    }
    
    Node* temp = prev->next;
    prev->next = prev->next->next;
    free(temp);
}

void searching(Node* head, int key) {
    Node* temp = head;
    int pos = 0;
    bool found = false;
    
    while(temp != NULL) {
        if(temp->val == key) {
            cout<<"The element is found at : "<<pos<<endl;
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if(!found) {
        cout<<"Not found"<<endl;
    }
}


void display(Node* head) {
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
    insertathead(head, 4);
    display(head);
    insertathead(head, 6);
    display(head);
    insertattail(head, 3);
    display(head);
    deleteatfirst(head);
    display(head);
    deleteattail(head);
    display(head);
    deleteatposition(head, 2);
    display(head);
    searching(head, 2);
    searching(head, 6);
}










