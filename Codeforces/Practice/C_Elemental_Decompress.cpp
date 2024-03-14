/*
 ▄▀▀▄ ▄▄   ▄▀▀█▄   ▄▀▀▄ ▄▀▄  ▄▀▀▀▀▄   ▄▀▀▀▀▄   ▄▀▀█▄▄
█  █   ▄▀ ▐ ▄▀ ▀▄ █  █ ▀  █ █      █ █      █ █ ▄▀   █
▐  █▄▄▄█    █▄▄▄█ ▐  █    █ █      █ █      █ ▐ █    █
   █   █   ▄▀   █   █    █  ▀▄    ▄▀ ▀▄    ▄▀   █    █
  ▄▀  ▄▀  █   ▄▀  ▄▀   ▄▀     ▀▀▀▀     ▀▀▀▀    ▄▀▄▄▄▄▀
 █   █    ▐   ▐   █    █                      █     ▐
 ▐   ▐            ▐    ▐                      ▐
*/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define F first
#define double long double
#define S second
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
using namespace std;

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

void solve()
{
    int n;cin>>n;
        set<int>st1,st2;
        for(int i=1;i<=n;i++)
        {
            st1.insert(i);
            st2.insert(i);
        }
        int perm1[n]={},perm2[n]={},frq[200005]={};bool flag=1;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            if(frq[x]>=2)
            {
                flag=0;
                continue;
            }
            if(frq[x]==0)
            {
                perm1[i]=x;
                st1.erase(st1.find(x));
            }
            else
            {
                perm2[i]=x;
                st2.erase(st2.find(x));
            }
            frq[x]++;
        }
        if(flag==0)
        {
            cout<<"NO"<<endl;
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(perm2[i]==0)
            {
                auto it=st2.upper_bound(perm1[i]);
                if(it==st2.begin())
                {
                    cout<<"NO"<<endl;
                    return;
                }
                --it;
                perm2[i]=*it;
                st2.erase(it);
            }
            else
            {
                auto it=st1.upper_bound(perm2[i]);
                if(it==st1.begin())
                {
                    cout<<"NO\n";
                    return;
                }
                --it;
                perm1[i]=*it;
                st1.erase(it);
            }
        }
        cout<<"YES\n";
        for(int i=0;i<n;i++)
        {
            cout<<perm1[i]<<' ';
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<perm2[i]<<' ';
        }
        cout<<endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}