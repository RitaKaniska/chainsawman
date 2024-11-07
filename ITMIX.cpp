#include <bits/stdc++.h>
#define int intmax_t

struct Node {
    int value;
    int inc = 0;
    int mul = 1;
};

constexpr int N = 1e5 + 5;
constexpr int MOD = 1e9 + 7;

int array[N];
Node tree[4 * N];
void build(int id, int l, int r) {
    if (l > r) return;
    if (l == r) {
        tree[id].value = array[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(2 * id + 1, l, m);
    build(2 * id + 2, m + 1, r);
    tree[id].value = (tree[2 * id + 1].value + tree[2 * id + 2].value) % MOD;
}

int32_t main() {
    int n, m;
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    build(0, 0, n - 1);
    std::cout << tree[0].value;
};