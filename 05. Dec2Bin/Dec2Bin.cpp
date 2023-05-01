#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

void Dec2Bin(int n) 
{
    Node* head = nullptr;
    while (n > 0) 
    {
        int digit = n % 2;
        Node* newNode = new Node;
        newNode->data = digit;
        newNode->next = head;
        head = newNode;
        n /= 2;
    }
    Node* current = head;
    while (current != nullptr) 
    {
        cout << current->data;
        current = current->next;
    }
}

int main() 
{
    int n;
    cin >> n;
    Dec2Bin(n);
    return 0;
}