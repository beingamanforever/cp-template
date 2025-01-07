// iterative and faster, uses less memory
// for array pass in the size, due to decaying of array to a pointer
struct segtree
{
    // point update range query
    // TODO: id is identity element
    typedef long long T;
    T def = 0, t[2 * N];            // TODO: change here
    T f(T a, T b) { return a + b; } // TODO: change here
    void build(const std::vector<T> &v)
    {
        int n = v.size();
        for (int i = 0; i < n; ++i)
        {
            t[i + N] = v[i];
        }
        for (int i = N - 1; i > 0; --i)
        {
            t[i] = f(t[2 * i], t[2 * i + 1]);
        }
    }
    void modify(int p, T v)
    {
        // set value v at position p
        for (t[p += N] = v; p /= 2;)
        {
            // if you want to add v, t[p += N] += v
            t[p] = f(t[2 * p], t[2 * p + 1]);
        }
    }
    T query(int l, int r)
    {
        // query on interval [l, r)
        T resl = def, resr = def;
        for (l += N, r += N; l < r; l /= 2, r /= 2)
        {
            if (l & 1)
            {
                resl = f(resl, t[l++]);
            }
            if (r & 1)
            {
                resr = f(t[--r], resr);
            }
        }
        return f(resl, resr);
    }
};
