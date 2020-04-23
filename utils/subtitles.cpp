#include <bits/stdc++.h>

#define MOD 1000000007
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;

struct info{
    ll id, s, e;
    vector<string> data;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char a;
    string b;
    ll h, m, s, ms, num;
    vector<info> data;
    while(true) {
        data.push_back(info{});
        cin >> data.back().id;
        cin >> h >> a >> m >> a >> s >> a >> ms;
        data.back().s = h * 3600000 + m * 60000 + s * 1000 + ms;
        cin >> b >> h >> a >> m >> a >> s >> a >> ms;
        data.back().e = h * 3600000 + m * 60000 + s * 1000 + ms;
        a = cin.peek();
        while((cin.peek() != '#') && (cin.peek() < '0' || cin.peek() > '9')){
            getline(cin, b);
            data.back().data.push_back(b);
        }
        if(cin.peek() == '#'){
            cin >> a;
            break;
        }
    }
    cin >> num;
    for(auto &x:data){
        cout << x.id << "\n";
        x.s += num;
        x.e += num;
        ms = x.s % 1000;
        x.s = (x.s - ms) / 1000;
        s = x.s % 60;
        x.s = (x.s - s) / 60;
        m = x.s % 60;
        x.s = (x.s - m) / 60;
        h = x.s;
        cout << setw(2) << setfill('0') << h << ':' << setw(2) << m << ':' << setw(2) << s << ',' << setw(3) << ms;
        cout << " --> ";
        ms = x.e % 1000;
        x.e = (x.e - ms) / 1000;
        s = x.e % 60;
        x.e = (x.e - s) / 60;
        m = x.e % 60;
        x.e = (x.e - m) / 60;
        h = x.e;
        cout << setw(2) << setfill('0') << h << ':' << setw(2) << m << ':' << setw(2) << s << ',' << setw(3) << ms;
        for(auto &d:x.data)
            cout << d << '\n';
    }
    cout << "\n";

    return 0;
}//RUL0