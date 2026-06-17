#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode* fast = head;

    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    ListNode* slow = head;

    if (fast == NULL) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
    }

    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;

    return head;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    int n = 2;

    head = removeNthFromEnd(head, n);

    cout << "After Deletion: ";
    printList(head);

    return 0;
}