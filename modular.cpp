ll madd(ll a, ll b) {
    return (a + b) % M;
}

ll msub(ll a, ll b) {
    return (((a - b) % M) + M) % M;
}

ll mmul(ll a, ll b) {
    return ((a % M) * (b % M)) % M;
}

ll mpow(ll base, ll exp) {
    ll res = 1;
    while (exp) {
        if (exp % 2 == 1){
            res = (res * base) % M;
        }
        exp >>= 1;
        base = (base * base) % M;
    }
    return res;
}

ll minv(ll base) {
    return mpow(base, M - 2);
}

ll mdiv(ll a, ll b) {
    return mmul(a, minv(b));
}
