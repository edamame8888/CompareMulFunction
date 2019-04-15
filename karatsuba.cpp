#include "./mul.hpp"

integer add(const integer& a, const integer& b){
    int n = max(a.size(), b.size());
    integer s(n+1);
    digit carry = 0;
    rep(i,n){
        fullAdder(getDigit(a,i), getDigit(b,i), carry, s[i], carry);
    }
    s[n] = carry;
    return s;
}

void sub(integer& a, const integer& b){
    digit carry = 0;
    rep(i,a.size()){
        if( a[i] >= (getDigit(b,i) + carry) ){
            a[i] = a[i] - getDigit(b,i) - carry;
            carry = 0;
        }else{
            a[i] = a[i] + B - getDigit(b,i) - carry;
            carry = 1;
        }
    }
    assert(carry == 0);
}

void split(const integer& a, integer& a1, integer& a0){
    int n = a.size();
    int k = n / 2;
    rep(i,k) a0[i] = a[i];
    rep(i,n-k) a1[i] = a[k+i];
}

integer Karatsuba(const integer& a, const integer& b, int n0){
    int n = a.size();
    int m = b.size();
    assert(n == m);
    assert(n0 >= 4);
    integer p(2*n);

    if(n < n0) return mult(a,b);

    int k = n / 2;
    integer a0(k), a1(n - k), b0(k), b1(n - k);

    split(a, a1, a0);
    split(b, b1, b0);

    integer p2 = Karatsuba(a1, b1, n0),
            p1 = Karatsuba(add(a1,a0), add(b1,b0), n0),
            p0 = Karatsuba(a0, b0, n0);

    rep(i, 2*k) p[i] = p0[i];
    FOR(i, 2*k, n+m) p[i] = p2[i - 2*k];

    sub(p1, p0);
    sub(p1, p2);
    addAt(p, p1, k);

    return p;
}
