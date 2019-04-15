#include "./mul.hpp"

void fullAdder(digit a, digit b, digit c, digit& s, digit& carry){
    unsigned int sum = a + b + c;
    carry = sum / B;
    s = sum - carry * B;
}

void digitMult(digit a, digit b , digit& s, digit& carry){
    unsigned int prod = a * b;
    carry = prod / B;
    s = prod - carry * B;
}

digit getDigit(const integer& a, int i){
    return ( i < a.size() ? a[i] : 0 );
}

void mult(const integer& a, const digit& b, integer& atimesb){
    int n = a.size();
    assert(atimesb.size() == n + 1);
    digit carry = 0, c, d, cprev = 0;
    rep(i,n){
        digitMult(a[i], b, d, c);
        fullAdder(d, cprev, carry, atimesb[i], carry);
        cprev = c;
    }
    d = 0;
    fullAdder(d, cprev, carry, atimesb[n], carry);
    assert(carry == 0);
}

void addAt(integer& p, const integer& atimesbj, int j){
    // p は長さ n+m をもつ
    digit carry = 0;
    int L = p.size();
    FOR(i,j,L){
        fullAdder(p[i], getDigit(atimesbj, i-j), carry, p[i], carry);
    }
    assert(carry == 0);
}

integer mult(const integer& a, const integer& b){
    int n = a.size();
    int m = b.size();
    integer p(n + m, 0);
    integer atimesbj(n+1);
    rep(j,m){
        mult(a, b[j], atimesbj);
        addAt(p, atimesbj, j);
    }
    return p;
}
