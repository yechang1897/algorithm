#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int val;
    Node *next;

    Node(int value) {
        val = value;
        next = nullptr;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    Node* head = new Node(-1);
    Node *p = head;

    for (int i = 0; i < nums.size(); i++) {
        Node *t = new Node(nums[i]);
        p->next = t;
        p = p->next;
    }

    head = head->next;
    Node *q = head;

    while(q) {
        cout << q->val << " ";
        q = q->next;
    }
    return 0;
}