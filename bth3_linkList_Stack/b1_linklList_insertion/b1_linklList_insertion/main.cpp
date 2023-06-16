#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

void printLinkedList(SinglyLinkedListNode* head) {
    while (head != NULL) {
        cout << head->data << ' ';
        head = head->next;
    }
}


// Chèn một nút vào một danh sách liên kết đơn đã có thứ tự tăng dần
SinglyLinkedListNode* insertSortedLinkedList(SinglyLinkedListNode* head, int x) {
    // Tạo node mới cần chèn
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(x);

    // Trường hợp danh sách rỗng
    if (head == NULL) {
        head = newNode;
        return head;
    }

    // Trường hợp chèn vào đầu danh sách
    if (x < head->data) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    // Duyệt qua các phần tử của danh sách
    SinglyLinkedListNode* temp = head;
    while (temp->next != NULL && temp->next->data < x) {
        temp = temp->next;
    }

    // Chèn node mới vào sau node tìm được
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

int main() {
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    int x;

    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist->insert_node(llist_item);
    }
    cin >> x;
    llist->head = insertSortedLinkedList(llist->head, x);
    printLinkedList(llist->head);

    return 0;
}