// Centroid Decomposition
// int root = decomp(1, 1), change N as needed
vector<int> tree[N];
int sz[N], cpar[N], lvl[N];

int getsize(int i, int p)
{
    sz[i] = 1;
    for (int j : tree[i])
    {
        if (j != p && !lvl[j])
        {
            sz[i] += getsize(j, i);
        }
    }
    return sz[i];
}

int centroid(int i, int p, int n)
{
    for (int j : tree[i])
    {
        if (j != p && !lvl[j] && sz[j] > (n / 2))
        {
            return centroid(j, i, n);
        }
    }
    return i;
}

int decomp(int i, int l)
{
    int cent = centroid(i, -1, getsize(i, -1));
    lvl[cent] = l;
    for (int j : tree[cent])
    {
        if (!lvl[j])
        {
            cpar[decomp(j, l + 1)] = cent;
        }
    }
    return cent;
}
