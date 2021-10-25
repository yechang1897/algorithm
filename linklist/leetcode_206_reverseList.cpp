#include<iostream>
#include<algorithm>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//为什么while循环里面第三行和第四行调换顺序就不行了。
ListNode* reverseList(ListNode* head) {
    ListNode* pre = head;
    ListNode* node = head;
    ListNode* prepre = nullptr;
    while(node) {
        pre = prepre;
        prepre = node;
        node = node->next;
        prepre->next = pre;
    }
    return prepre;
}
//递归的
ListNode* reverseList_2(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode* p = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return p;
}

int main() {
    ListNode* head = new ListNode(1);
    ListNode* iter;
    iter = head;
    for(int i = 1; i < 5; i++) {
        ListNode * temp = new ListNode(i+1);
        iter->next = temp;
        iter = iter->next;
    }
    ListNode* res = reverseList_2(head);
    while(res) {
        cout << res->val << " ";
        res = res->next;
    }
}