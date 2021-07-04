// For searching pattern inside string

#include <bits/stdc++.h>
using namespace std;

string txt, pt;
int lt, lp;

bool match(int l, int r)
{
    for (int i = 0; i < lp; i++)
    {
        if (txt[l + i] != pt[i])
            return false;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;

    cin.ignore();
    while (t--)
    {
        getline(cin, txt);
        getline(cin, pt);

        lt = txt.size();
        lp = pt.size();

        for (int l = 0, r = lp - 1; r < lt; l++, r++)
        {
            if (match(l, r))
                cout << " Start index for [ " << pt << " ] Inside [ " << txt << " ] " << l << endl;
        }
    }
}