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

int N, M, A[100], X;

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) {
            cin >> X;
            A[j] -= X;
        }

    for (int i = 0; i < M; ++i)
        if (A[i] > 0) {
            cout << "No" << '\n';
            return 0;
        }
    cout << "Yes\n";
}
