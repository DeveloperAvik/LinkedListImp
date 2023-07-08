#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> webAddresses;
    string address;

    while (cin >> address && address != "end")
    {
        webAddresses.push_back(address);
    }

    int Q;
    cin >> Q;

    string command;
    list<string>::iterator currentAddress = webAddresses.begin();

    while (Q--)
    {
        cin >> command;

        if (command == "visit")
        {
            cin >> address;

            auto it = find(webAddresses.begin(), webAddresses.end(), address);

            if (it != webAddresses.end())
            {
                currentAddress = it;
                cout << *currentAddress << "\n";
            }
            else
            {
                cout << "Not Available\n";
            }
        }
        else if (command == "next")
        {
            ++currentAddress;

            if (currentAddress != webAddresses.end())
            {
                cout << *currentAddress << "\n";
            }
            else
            {
                cout << "Not Available\n";
                --currentAddress;
            }
        }
        else if (command == "prev")
        {
            if (currentAddress != webAddresses.begin())
            {
                --currentAddress;
                cout << cpp * currentAddress << "\n";
            }
            else
            {
                cout << "Not Available\n";
            }
        }
    }

    return 0;
}
