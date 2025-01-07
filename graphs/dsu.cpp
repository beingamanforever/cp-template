struct DSU
{
    vector<int> parent, size;
    DSU(int n) : parent(n), size(n, 1)
    {
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }
    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    bool unite(int x, int y)
    {
        int xr = find(x), yr = find(y);
        if (xr == yr)
        {
            return false;
        }
        if (size[xr] < size[yr])
        {
            swap(xr, yr);
        }
        parent[yr] = xr;
        size[xr] += size[yr];
        return true;
    }
    bool islink(int x, int y)
    {
        return find(x) == find(y);
    }
    int getsize(int x)
    {
        return size[find(x)];
    }
};
