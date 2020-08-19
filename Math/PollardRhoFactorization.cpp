// O(n^1/4) Pollard's rho factorization method
long long factorization(long long n) {
    auto g = [&n](long long x) { return (x * x + 1) % n; };
    long long x = 2, y = 2, d = 1;
    int cnt = 0;
    while (d == 1) {
        cnt++;
        x = g(x);
        y = g(g(y));
        d = gcd(abs(x - y), n);
    }
    if (d == n) {
        return -1;  // failure
    } else {
        return d;
    }
}
