#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace atcoder;
using ll = long long;
using bint = boost::multiprecision::cpp_int;
using mint = modint998244353;
using pr = pair<int, int>;
ostream &operator<<(ostream &os, const mint &x) {
    os << x.val();
    return os;
}
template <class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
struct fast {
    fast() {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;

ll N, M;
mint f(int x, ll N) {
    return (N + 1) / (1ll << x + 1) * (1ll << x) + max(0ll, (N + 1) % (1ll << x + 1) - (1ll << x));
}

int main() {
    cin >> N >> M;
    mint ans = 0;
    for (int i = 0; i < 60; ++i) {
        if ((1ll << i) & M) {
            ans += f(i, N);
            cerr << i << ':' << f(i, N) << '\n';
        }
    }
    cout << ans << '\n';
}
