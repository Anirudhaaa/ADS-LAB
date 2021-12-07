#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* link;
    Node(int val){
        data = val;
        link = NULL;
    }
};

Node* XOR(Node* a, Node* b)
{
    return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}

Node* insert(Node* head, int val)
{
    Node* node = new Node(val);
    node->link = XOR(head, NULL);
    if(head != NULL)
        head->link = XOR(node, XOR(head->link, NULL));
    head = node;
    return head;
}

void printList(Node* head)
{
    Node *cur = head, *prev = NULL, *next;
    while(cur)
    {
        cout << cur->data << " ";
        next = XOR(prev, cur->link);
        prev = cur;
        cur = next;
    }
}

int main()
{
    int val;
    Node* head = NULL;
    cout << "Enter values to insert or enter -1 to quit\n";
    while(1)
    {
        cin >> val;
        if(val == -1)
            break;
        head = insert(head, val);
    }
    printList(head);
    return 0;
}
