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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    ListNode* result;

    if (list1->val <= list2->val) {
        result = list1;
        result->next = mergeTwoLists(list1->next, list2);
    }
    else {
        result = list2;
        result->next = mergeTwoLists(list1, list2->next);
    }

    return result;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    // List1: 1 -> 3 -> 5
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    // List2: 2 -> 4 -> 6
    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    ListNode* merged = mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}