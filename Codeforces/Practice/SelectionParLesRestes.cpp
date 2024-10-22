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
#define debug(x) cout << #x << ": " << x << endl;

const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

signed main()
{
    FAST;
    int n;
    printf("Donner le nombre des individus: \n");
    cin >> n;
    printf("Donner les fitness de 1 à %d :\n", n);
    int a[n];
    double probabilites[n];
    double Ei[n];
    int EntiereEi[n];
    double Ri[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        sum += x;
    }
    for (int i = 0; i < n; i++)
    {
        probabilites[i] = a[i] * 1.0 / sum;
        Ei[i] = n * probabilites[i];
        EntiereEi[i] = (int)floor(Ei[i]);
        Ri[i] = Ei[i] - EntiereEi[i];
        cout << "Probabilite[" << i << "] = " << probabilites[i] << endl;
        cout << "Ei[" << i << "] = " << Ei[i] << endl;
        cout << "EntiereEi[" << i << "] = " << EntiereEi[i] << endl;
        cout << "Ri[" << i << "] = " << Ri[i] << endl; 
    }
    vector<int> SelectedIndividus;
    int nbre = 0;
    for (int i = 0; i < n; i++)
    {
        if (EntiereEi[i] > 0)
            for (int j = 0; j < EntiereEi[i]; j++)
            {
                SelectedIndividus.push_back(i + 1);
            }
    }
    //
    int caseRestantes = n - SelectedIndividus.size();
    for (int i = 0; i < INT16_MAX; i++)
    {
        float rnd = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        cout << rnd << " | ";
        if (caseRestantes <= 0)
            break;
        if (rnd < Ri[i % n])
        {
            SelectedIndividus.push_back(i % n + 1);
            caseRestantes--;
            cout << "< " << Ri[i%n] << "=> I" << i % n + 1 << " prise!!" << endl;
        }
        else
        {
            cout << "> " << Ri[i%n] << "=> I" << i % n + 1 << " pas prise :(" << endl;
        }
    }

    for (auto e : SelectedIndividus)
    {
        cout << "I" << e << " ";
    }
    cout << endl;
    return 0;
}