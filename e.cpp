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

int N, A;
fenwick_tree<int> ft(1000001);

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A;
        ft.add(A, 1);
    }

    ll ans = 0;
    for (int x = 1; x < 1000001; ++x) {
        int c = ft.sum(x, x + 1);
        if (!c) continue;
        for (int k = 1; (ll)x * k < 1000001; ++k) ans += (ll)k * c * ft.sum(x * k, min(x * (k + 1), 1000001));
        ans -= (ll)c * (c + 1) / 2;
    }

    cout << ans << '\n';
}
