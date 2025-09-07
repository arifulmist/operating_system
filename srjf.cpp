#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n;
    cin >> n;
    vector<ll> at(n), bt(n), ct(n), tat(n), wt(n), exc(n),rm(n);
    for (ll i = 0; i < n; i++)
    {
        cout<<"enter your arrival time and burst time" << i + 1 << ": ";
        cin >> at[i] >> bt[i];
        rm[i] = bt[i];
    }
    ll tmp = n;
    ll cur = 0;
    while (tmp != 0)
    {
        ll mn = 1e9, ind = -1;
        for (ll i = 0; i < n; i++)
        {
            if (cur >= at[i] && rm[i] < mn && rm[i]>0&& exc[i] != 1)
            {
                mn = rm[i];
                ind = i;
            }
        }
        rm[ind]--;
        cur++;
        if(rm[ind]==0)
        {
            ct[ind] = cur;
            tat[ind] = ct[ind] - at[ind];
            wt[ind] = tat[ind] - bt[ind];
            exc[ind] = 1;
            tmp--;
        }
        
    }
    double avgtat = 0, avgwt = 0;
    for (ll i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i]
             << "\t" << tat[i] << "\t" << wt[i] << endl;
        avgtat += tat[i];
        avgwt += wt[i];
    }
    avgtat /= n;
    avgwt /= n;
    cout << "Average Turn Around Time: " << avgtat << "s\n";
    cout << "Average Waiting Time: " << avgwt << "s\n";
}