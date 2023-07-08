#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> wa;
    string add;

    while (cin >> add && add != "end")
    {
        wa.push_back(add);
    }

    int t;
    cin >> t;

    string inst;
    list<string>::iterator ca = wa.begin();
    while (t--)
    {
        cin >> inst;

        if (inst == "visit")
        {
            cin >> add;

            auto it = find(wa.begin(), wa.end(), add);

            if (it != wa.end())
            {
                ca = it;
                cout << *ca << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (inst == "next")
        {
            ++ca;

            if (ca != wa.end())
            {
                cout << *ca << endl;
            }
            else
            {
                cout << "Not Available" << endl;
                --ca;
            }
        }
        else if (inst == "prev")
        {
            if (ca != wa.begin())
            {
                // cout << *ca << endl;
                --ca;
                cout << *ca << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
