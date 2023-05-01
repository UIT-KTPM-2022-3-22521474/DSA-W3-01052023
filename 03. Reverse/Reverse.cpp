#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode 
{
public:
    int data;
    SinglyLinkedListNode* next;
    SinglyLinkedListNode(int node_data) 
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList 
{
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
    SinglyLinkedList() 
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
};

void reverseLinkedList(SinglyLinkedList* llist) 
{
    SinglyLinkedListNode* prevNode = nullptr;
    SinglyLinkedListNode* currNode = llist->head;
    SinglyLinkedListNode* nextNode;
    while (currNode != nullptr) 
    {
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    llist->head = prevNode;
}

void printLinkedList(SinglyLinkedList* llist) 
{
    SinglyLinkedListNode* currNode = llist->head;
    while (currNode != nullptr) 
    {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
}

void insert_node(SinglyLinkedList* llist, int node_data) 
{
    SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);
    if (!llist->head) 
    {
        llist->head = node;
    }
    else 
    {
        SinglyLinkedListNode* current = llist->head;
        while (current->next) 
        {
            current = current->next;
        }
        current->next = node;
    }
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    cin >> llist_count;
    for (int i = 0; i < llist_count; i++) 
    {
        int llist_item;
        cin >> llist_item;

        insert_node(llist, llist_item);
    }
    reverseLinkedList(llist);
    printLinkedList(llist);
    return 0;
}