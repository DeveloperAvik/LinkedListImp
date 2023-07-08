
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next1;
    Node *next2;

    Node()
    {
        data = 0;
        next1 = NULL;
        next2 = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next1 = NULL;
        this->next2 = NULL;
    }
};
class Linkedlist
{

public:
    Node *head;
    Linkedlist()
    {
        head = NULL;
    }
    void printList_L();
    void printList_R();
    void insertNode_end(int, int);
    void insertNode_begin(int);
};
void Linkedlist::printList_L()
{
    cout << "L -> ";
    Node *temp = head;
    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next2;
    }
}
void Linkedlist::printList_R()
{
    cout << "R -> ";
    Node *temp = head;
    if (head == NULL)
    {
        cout << "List empty" << endl;
        return;
    }
    while (temp != NULL)
    {
        // cout << temp->data << " ";
        temp = temp->next2;
    }
    while (temp != head)
    {
        cout << temp->data << " ";
        temp = temp->next1;
    }
}

void Linkedlist::insertNode_end(int data, int n)
{

    Node *newNode = new Node(data);
    int i = 0;
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *cnode = head;
    Node *pnode;
    while (cnode->next2 != NULL)
    {

        pnode = cnode;
        cnode = cnode->next2;

        if (i == n)
        {
            newNode->next2 = cnode;
            cnode->next1 = newNode;

            newNode->next1 = pnode;
            pnode->next2 = newNode;
        }
        else if (i == 0)
            insertNode_begin(data);
    }
}
void Linkedlist::insertNode_begin(int data)
{
    Node *cnode = new Node(data);
    cnode->next2 = head;
    head->next1 = cnode;
    head = cnode;
}
int main()
{
    Linkedlist list;
    int a, s, n = -1, i = 0;
    cin >> s;
    // vector<int> arr(s * 2);
    int arr[s];
    for (i = 0; i < s * 2; i++)
    {
        cin >> a;
        // arr.push_back(a);
    }
    i = 0;
    while (i < s * 2)
    {
        if (n + 1 < arr[i])
        {
            cout << "Invalid";
        }
        else
        {
            list.insertNode_end(arr[i + 1], arr[i]);
            n++;
        }
        list.printList_L();
        list.printList_R();
        i += 2;
    }
    //    list1.printList();
    //    cout<<endl;
    //    list2.printList();
    return 0;
}