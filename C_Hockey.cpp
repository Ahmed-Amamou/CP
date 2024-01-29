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

//...............................................................................................................
//.HHHHH.....HHHHH......AAAAAAA.......MMMMMMM....MMMMMMM.....OOOOOOOOOO.........OOOOOOOOOO.....DDDDDDDDDDDDD.....
//.HHHHH.....HHHHH......AAAAAAA.......MMMMMMM....MMMMMMM....OOOOOOOOOOOOO.....OOOOOOOOOOOOO....DDDDDDDDDDDDDD....
//.HHHHH.....HHHHH......AAAAAAAA......MMMMMMM....MMMMMMM...OOOOOOOOOOOOOOO...OOOOOOOOOOOOOOO...DDDDDDDDDDDDDDD...
//.HHHHH.....HHHHH.....AAAAAAAAA......MMMMMMM...MMMMMMMM..OOOOOOOO.OOOOOOO...OOOOOOO.OOOOOOOO..DDDDD..DDDDDDDD...
//.HHHHH.....HHHHH.....AAAAAAAAA......MMMMMMMM..MMMMMMMM..OOOOOO.....OOOOOO.OOOOOO.....OOOOOO..DDDDD.....DDDDDD..
//.HHHHH.....HHHHH.....AAAAAAAAAA.....MMMMMMMM..MMMMMMMM.MOOOOO......OOOOOO.OOOOO.......OOOOO..DDDDD.....DDDDDD..
//.HHHHH.....HHHHH....AAAAA.AAAAA.....MMMMMMMM.MMMMMMMMM.MOOOOO.......OOOOO.OOOOO.......OOOOOO.DDDDD......DDDDD..
//.HHHHHHHHHHHHHHH....AAAAA.AAAAAA....MMMMMMMMMMMMMMMMMM.MOOOO........OOOOO.OOOOO........OOOOO.DDDDD......DDDDD..
//.HHHHHHHHHHHHHHH...AAAAAA..AAAAA....MMMMMMMMMMMMMMMMMM.MOOOO........OOOOO.OOOOO........OOOOO.DDDDD......DDDDD..
//.HHHHHHHHHHHHHHH...AAAAA...AAAAA....MMMMMMMMMMMMMMMMMM.MOOOO........OOOOO.OOOOO........OOOOO.DDDDD......DDDDD..
//.HHHHH.....HHHHH...AAAAAAAAAAAAAA...MMMMMMMMMMMMMMMMMM.MOOOOO.......OOOOO.OOOOO.......OOOOOO.DDDDD......DDDDD..
//.HHHHH.....HHHHH..HAAAAAAAAAAAAAA...MMMMMMMMMMMMMMMMMM.MOOOOO......OOOOOO.OOOOOO......OOOOO..DDDDD.....DDDDDD..
//.HHHHH.....HHHHH..HAAAAAAAAAAAAAA...MMMMMMMMMMMM.MMMMM..OOOOOO.....OOOOOO.OOOOOO.....OOOOOO..DDDDD.....DDDDDD..
//.HHHHH.....HHHHH..HAAAA.....AAAAAA..MMMMM.MMMMMM.MMMMM..OOOOOOOOOOOOOOOO...OOOOOOO.OOOOOOOO..DDDDD...DDDDDDD...
//.HHHHH.....HHHHH.HHAAAA......AAAAA..MMMMM.MMMMMM.MMMMM...OOOOOOOOOOOOOOO...OOOOOOOOOOOOOOO...DDDDDDDDDDDDDDD...
//.HHHHH.....HHHHH.HHAAA.......AAAAAA.MMMMM.MMMMMM.MMMMM....OOOOOOOOOOOOO.....OOOOOOOOOOOOO....DDDDDDDDDDDDDD....
//.HHHHH.....HHHHH.HHAAA.......AAAAAA.MMMM..MMMMM..MMMMM.....OOOOOOOOOO.........OOOOOOOOOO.....DDDDDDDDDDDD......
//...............................................................................................................
const double EPS = 0.00000001;
const ll MOD = 1e9 + 7;
int gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
// PetrLoveLuckyNumbers
// PetrLovtTttttNumtttt
// Enter the forbidden strings in forbidden vector
// we check their occurences in the string
// if they exist then add coordinate to set
// then go through the set and change the each letter of string
// to the "desired letter" only when it's different if its the same else replace with a
// only case is is when desired letter is a then change to b;
// abababBabaBBaBBBBAaaaAAAAA
// bababaAbabAAbAAAABbbbBBBBB
// baababBabaBBaBBBBAaaaAAAAA
void solve()
{
    int n;
    cin >> n;
    vector<string> forbidden_words;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        forbidden_words.push_back(s);
    }
    string s;
    char letter;
    set<int> positions;
    cin >> s;
    string s_lower = s;
    transform(s_lower.begin(), s_lower.end(), s_lower.begin(),
              [](unsigned char c)
              { return tolower(c); });

    cin >> letter;
    for (const auto &word : forbidden_words)
    {
        string word_lower = word;
        transform(word_lower.begin(), word_lower.end(), word_lower.begin(),
                  [](unsigned char c)
                  { return tolower(c); });
        int pos = s_lower.find(word_lower);
        while (pos != string::npos)
        {
            // substr found at position pos
            for (int i = pos; i - pos < word.length(); i++)
            {
                positions.insert(i);
            }
            pos = s_lower.find(word_lower, pos + word_lower.size());
        }
        
    }
    // for (int i : positions)
    // {
    //     cout << i << " ";
    // }

    for (int pos : positions)
    {
        if (tolower(s[pos]) != tolower(letter))
        {
            if (isupper(s[pos]))
                s[pos] = toupper(letter);
            else
                s[pos] = tolower(letter);
        }
        else if (tolower(s[pos]) == tolower(letter) && tolower(s[pos]) == 'a')
        {
            if (isupper(s[pos]))
                s[pos] = 'B';
            else
                s[pos] = 'b';
        }
        else
        {
            if (isupper(s[pos]))
                s[pos] = 'A';
            else
                s[pos] = 'a';
        }
    }
    cout << s << endl;
}

signed main()
{
    FAST;
    ll tt = 1;
    // freopen("input.in", "r", stdin);
    //   cin >> tt;
    //   while (tt--)
    solve();
    return 0;
}