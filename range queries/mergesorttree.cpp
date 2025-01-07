// O(log^2(N)), for each node we have a sorted list of vector elements
// before calling tree.build(), do set tree.t[i + N] = {arr[i]}; for [0,n)
struct mstree {
    vector<int> t[2 * N];
    int f(int i, int k) {
        // num elements < k in t[i]
        return (int)(lower_bound(all(t[i]), k) - t[i].begin());
    }
    void build() {
        // call after setting t[i + N] for i in [0, n)
        for (int i = N - 1; i >= 0; i--) {
            merge(all(t[2 * i]), all(t[2 * i + 1]), back_inserter(t[i]));
        }
    }
    int query(int l, int r, int k) {
        // num elements < k in interval [l, r)
        int res = 0;
        for (l += N, r += N; l < r; l /= 2, r /= 2) {
            if (l & 1) {
                res += f(l++, k);
            }
            if (r & 1) {
                res += f(--r, k);
            }
        }
        return res;
    }
};
