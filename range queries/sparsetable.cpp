int st[N][L];
int f(int a, int b) { return min(a, b); } // must be idempotent

int query(int l, int r)
{
    // half open interval [l, r) for 0 based, for 1 based do (r- l + 1)
    int k = 63 - __builtin_clzll(r - l); // 0 based indexing
    return f(st[l][k], st[r - (1 << k)][k]);
}

// input in: st[i][0]
for (int j = 1; j < L; j++)
{
    for (int i = 0; i < n; i++)
    {
        st[i][j] = st[i][j - 1];
        int i2 = i + (1LL << (j - 1));
        if (i2 < n)
        {
            st[i][j] = f(st[i][j], st[i2][j - 1]);
        }
    }
}
