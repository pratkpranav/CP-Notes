void pushdown(ll cur, ll l, ll r)
{
    if (delta[cur] != -1)
    {
        ll mid = (l + r) >> 1;
        delta[lch[cur]] = delta[cur];
        delta[rch[cur]] = delta[cur];
        x[lch[cur]] = (mid - l + 1) * delta[cur];
        x[rch[cur]] = (r - mid) * delta[cur];
        delta[cur] = -1;
    }
}
void update(ll cur)
{
    x[cur] = x[lch[cur]] + x[rch[cur]];
}
void build(ll &cur, ll l, ll r)
{
    cur = ++tot;
    delta[cur] = -1;
    if (l == r)
    {
        x[cur] = a[l];
        return;
    }
    ll mid = (l + r) >> 1;
    build(lch[cur], l, mid);
    build(rch[cur], mid + 1, r);
    update(cur);
}
void modify(ll cur, ll l, ll r, ll L, ll R, ll a)
{
    if (L <= l && r <= R)
    {
        delta[cur] = a;
        x[cur] = a * (r - l + 1);
        return;
    }
    pushdown(cur, l, r);
    ll mid = (l + r) >> 1;
    if (L <= mid)
        modify(lch[cur], l, mid, L, R, a);
    if (R >= mid + 1)
        modify(rch[cur], mid + 1, r, L, R, a);
    update(cur);
}
ll qurry(ll cur, ll l, ll r, ll L, ll R)
{
    if (L <= l && r <= R)
    {
        return x[cur];
    }
    pushdown(cur, l, r);
    ll mid = (l + r) >> 1;
    ll ans = 0;
    if (L <= mid)
        ans += qurry(lch[cur], l, mid, L, R);
    if (R >= mid + 1)
        ans += qurry(rch[cur], mid + 1, r, L, R);
    return ans;
}

checkout: https://codeforces.com/contest/1478/submission/106090032 (implementation)
