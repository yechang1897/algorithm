#include<iostream>
#include<vector>
#include<malloc.h>
using namespace std;

typedef struct node{
    int data;
    struct node * next;
}*pnode;

pnode init(vector<int> nums) {
    pnode head = new node;
    pnode p,q;
    p = head;
    
    int sz = nums.size();
    
    for(int i = 0; i < sz; i++) {
        q = new node;
        q->data = nums[i];
        // cout << q->data << endl;
        p->next = q;
        p = p->next;
    }
    // cout << "head" << endl;
    // p->next = nullptr;
    p->next = nullptr;
    return head->next; 
}

void printList(pnode head) {
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

int main() {
    // int n;
    // cin >> n;
    // int len = n;
    vector<int> nums;
    int ret;
    while(1) {
        int n;
        scanf("%d",&n);        
        nums.push_back(n);
        if(getchar() == '\n') break;
    }
    // for(int i = 0;i < len;i++) {
    //     cout << nums[i] << " ";
    // }
    pnode head = init(nums);
    // cout << head->data << endl;
    // printList(head);
    int target;
    cin >> target;
    if(head->data == target) {
        head = head->next;
        printList(head);
        return 0;
    }
    pnode temp = head;
    while(temp->next->data != target) {
        temp = temp->next;
    }
    if(!temp->next->next) {
        temp->next = nullptr;
    } else {
        temp->next = temp->next->next;
    }
    printList(head);
    return 0;
}