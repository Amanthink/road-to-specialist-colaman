#include <bits/stdc++.h>
using namespace std;

int sumCheckPoints(int N, int S, string pos[], int val[])
{
    int n = N - 1; // number of non-root checkpoints
    int ans = 0;

    // Check the root (path "")
    // For checkpoint i with path p_i, look at ALL other checkpoints
    // (root included) whose path has p_i as a strict prefix; the
    // character right after that prefix tells the immediate branch
    // direction (L/R) from i.
    for (int i = -1; i < n; i++)
    {
        string pi = (i == -1) ? "" : pos[i];
        int vi = (i == -1) ? S : val[i];

        bool left = false, right = false;

        for (int j = -1; j < n; j++)
        {
            if (j == i) continue;
            string pj = (j == -1) ? "" : pos[j];

            if (pj.size() > pi.size() && pj.substr(0, pi.size()) == pi)
            {
                char next = pj[pi.size()];
                if (next == 'L') left = true;
                if (next == 'R') right = true;
            }
        }

        if (left && right)
            ans += vi;
    }
    return ans;
}