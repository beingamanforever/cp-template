struct segtree {
    int n;
    vector<int> st;
    segtree(int _n) {
        n = _n;
        st.resize(4 * n, default_value());
    }
    int default_value() {
        // default values list
        // AND - maximum value of bitwise AND = (1LL << 30) - 1
        // SUM - 0
        // MIN - INT_MAX
        // MAX - INT_MIN
        // GCD - 0
        // OR - 0
        // XOR - 0
        return (1LL << 30) - 1;
    }
    int comb(int a, int b) {
        return (a & b);
    }
    void build(int start, int end, int node, vector<int> &v) {
        if (start == end) {
            st[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * node + 1, v);
        build(mid + 1, end, 2 * node + 2, v);
        st[node] = comb(st[2 * node + 1], st[2 * node + 2]);
    }
    int query(int start, int end, int l, int r, int node) {
        if (start > r || end < l) {
            return default_value();
        }
        if (start >= l && end <= r) {
            return st[node];
        }
        int mid = (start + end) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2);
        return comb(q1, q2);
    }
    void update(int start, int end, int node, int idx, int value) {
        if (start == end) {
            st[node] = value;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(start, mid, 2 * node + 1, idx, value);
        } else {
            update(mid + 1, end, 2 * node + 2, idx, value);
        }
        st[node] = comb(st[2 * node + 1], st[2 * node + 2]);
    }
    void build(vector<int> &v) {
        build(0, n - 1, 0, v);
    }
    int query(int l, int r) {
        return query(0, n - 1, l, r, 0);
    }
    void update(int idx, int value) {
        update(0, n - 1, 0, idx, value);
    }
};
