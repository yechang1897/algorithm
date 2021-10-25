#include<iostream>

using namespace std;

typedef struct ListNode{
    int data;
    struct ListNode * next;
}Node;

void addToTail(Node** head, int value){
    
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    // cout << "init1" << endl;
    if(*head == NULL) {
        // cout << "init" << endl;
        *head = newNode;
    } else {
        // cout << "init1" << endl;
        Node* temp = *head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void removeNode(Node** head, int value) {
    if(head == NULL || *head == NULL) return;
    Node* dnode = NULL;
    if((*head)->data == value) {
        dnode = *head;
        *head = (*head)->next;
    } else {
        Node* temp = *head;
        while(temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }
        if(temp->next != NULL && temp->next->data == value) {
            dnode = temp->next;
            temp->next = temp->next->next;
        }
    }
    if(dnode != NULL) {
        delete dnode;
        dnode = NULL;
    }
}

void printList(Node** head) {
    Node* temp = *head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    // cout << "test" << endl;
    for(int i = 0; i < 5; i++) {
        addToTail(&head, i);
    }
    // cout << "test" << endl;
    printList(&head);
    removeNode(&head, 2);
    printList(&head);
    removeNode(&head, 4);
    printList(&head);
    // cout << "test" << endl;
    return 0;
}