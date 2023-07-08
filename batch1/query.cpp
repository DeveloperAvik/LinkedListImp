#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        data = 0;
        prev = nullptr;
        next = nullptr;
    }
};

class Queries
{
public:
    Node *head;
    Node *tail;
    Queries()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int cunt, int val)
    {
        Node *newNode = new Node;
        newNode->data = val;

        if (head == nullptr)
        {
            newNode->prev = nullptr;
            newNode->next = nullptr;
            head = newNode;
            tail = newNode;
        }
        else if (cunt == 0)
        {

            newNode->prev = nullptr;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else if (cunt >= size())
        {
            newNode->prev = tail;
            newNode->next = nullptr;
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            Node *cur = head;
            for (int i = 0; i < cunt; i++)
            {
                cur = cur->next;
            }

            newNode->prev = cur->prev;
            newNode->next = cur;
            cur->prev->next = newNode;
            cur->prev = newNode;
        }
    }

    int size()
    {
        int count = 0;
        Node *cur = head;
        while (cur != nullptr)
        {
            count++;
            cur = cur->next;
        }
        return count;
    }

    void printList()
    {
        cout << "L -> ";
        Node *cur = head;
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";

        cout << "R -> ";
        cur = tail;
        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->prev;
        }
        cout << endl;
    }
};

int main()
{
    Queries List;
    int t;
    cin >> t;

    while (t--)
    {
        int cunt, val;
        cin >> cunt >> val;

        if (cunt < 0 || cunt > List.size())
        {
            cout << "Invalid" << endl;
        }
        else
        {
            List.insert(cunt, val);
            List.printList();
        }
    }

    return 0;
}
