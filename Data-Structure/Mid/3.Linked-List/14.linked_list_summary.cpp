// Insert at head, insert at tail, insert at k th position, delete at head, delete at tail, delete at k th position, update at k th position, reverse the linked list by varsity teacher


#include <iostream>
using namespace std;
class node
{
public:
    int val;
    node *next;
    node(int value)
    {
        this->val = value;
        this->next = nullptr;
    }
};
class linked_list
{
public:
    node *head;
    node *tail;
    linked_list()
    {
        head = nullptr;
        tail = nullptr;
    }
    void insertinFront(int value)
    {
        node *newNode = new node(value);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void insertinBack(int value)
    {
        node *newNode = new node(value);
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insertinPos(int value, int pos)
    {
        node *newNode = new node(value);
        int cnt = 1;
        while (cnt!= pos-1)
        {
            head= head->next;
            cnt++;
        }
        newNode->next = head->next;
        head->next = newNode;
    }
    
    void deleteathead(linked_list lst) {
        node* temp = lst.head;
        head = head->next;
        delete(temp);
    }
    
    void deleteattail(linked_list lst) {
        node* second_last = lst.head;
        while(second_last->next != lst.tail) {
            second_last = second_last->next;
        }
        
        second_last->next = NULL;
        node* temp = tail;
        delete(temp);
        tail = second_last;
    }
    
    void deleteatposition(linked_list &lst, int pos) {
        if (pos == 0) {
            lst.deleteathead(lst);
        
        }

        int current_pos = 0;
        node* prev = lst.head;

        while (current_pos != pos - 1) { 
            prev = prev->next;
            current_pos++;
        }

        node* temp = prev->next;
        prev->next = prev->next->next;
        delete temp;
    }
    
    void updateatposition(linked_list &lst, int k, int value) {
        node* temp = lst.head;
        int curr_pos = 0;
        
        while(curr_pos != k) {
            temp = temp->next;
            curr_pos++;
        }
        temp->val = value;
    }
    
    void reverseprint(node* head) {
    // Base condition
    if (head == NULL) {
        return;
    }

    // Recursive case
    reverseprint(head->next);

    cout << head->val << " ";
}

};

void printList(linked_list lst){
    node* temp = lst.head;
    while (temp!= nullptr)
    {
        cout<<temp->val<<' ';
        temp = temp->next;
    }
    
}

int main() {
        linked_list list;
        list.insertinFront(5);
        list.insertinFront(10);
        list.insertinBack(8);
        list.insertinBack(9);
        list.insertinPos(51, 2);
        //list.deleteathead(list);
        //list.deleteattail(list);
        //list.deleteatposition(list, 2);
        list.updateatposition(list, 1, 6);
        list.reverseprint(list.head);
        


        //printList(list);
}


