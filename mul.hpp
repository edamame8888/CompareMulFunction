#ifndef MUL_HEADER_FILE
#define MUL_HEADER_FILE

#include <bits/stdc++.h>

using namespace std;
extern unsigned int B;
extern unsigned int X;
typedef unsigned int digit;
typedef vector<digit> integer;

//repetition
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

/*
    変数名がクソなのは、参考書の引数名と同じものを採用したからです。
    多分、変数名を綺麗にするとコードの可読性をあげることができます。
    （綺麗に直した方がいらっしゃったらプルリクしてください)
*/
/*-----------------------
 Using school mul method
------------------------*/

/// 多数桁の各桁数に対して呼ばれる関数
/// 任意の桁数同士を足し合わせ桁上がりする数、その桁に残る数をpointerが指し示す場所に格納
/// - parameter a: 足し合わせたい一方の任意桁
/// - parameter b: 足し合わせたいもう一方の任意桁
/// - parameter s: aとbを足し合わせて、繰り上がりを除いた数のアドレス(*s < B)
/// - parameter carry: a+bを足し合わせて繰り上がる数のアドレス
/// - returns: なし
void fullAdder(digit a, digit b, digit c, digit& s, digit& carry);

/// 多数桁の各桁数に対して呼ばれる関数
/// 任意の桁数同士を掛け合わせ桁上がりする数、その桁に残る数をpointerが指し示す場所に格納
/// - parameter a: 掛け合わせたい一方の任意桁
/// - parameter b: 掛け合わせたいもう一方の任意桁
/// - parameter s: aとbを掛け合わせて、繰り上がりを除いた数のアドレス(*s < B)
/// - parameter carry: a+bを掛け合わせて繰り上がる数のアドレス
/// - returns: なし
void digitMult(digit a, digit b , digit& s, digit& carry);

/// 多数桁の任意の桁にアクセスする際に呼ばれる関数
/// - parameter a: 参照したい多数桁の配列
/// - parameter i: aのi桁目を指し示す正整数
/// - returns: 任意の桁数 存在しない桁数にアクセスしたら0を返す
digit getDigit(const integer& a, int i);


/*-----------------------
 Using school mul method
------------------------*/
/// 多数桁と一桁の数との乗算
/// - parameter a: 掛け合わせたい多数桁の配列のアドレス
/// - parameter b: 掛け合わせたい任意の整数
/// - parameter atimesb: 乗算した結果を格納する多数桁の配列のアドレス
/// - returns: なし
void mult(const integer& a, const digit& b, integer& atimesb);

/// 多数桁と一桁の数との乗算の結果を任意の桁数ずらして足し合わせる関数
/// - parameter p: 足し合わせる元の多数桁配列
/// - parameter atimesbj: j桁ずらす前の多数桁の配列
/// - parameter j: atimesbjをj桁ずらすため正整数 j
/// - returns: なし
void addAt(integer& p, const integer& atimesbj, int j);

/// 多数桁の同士の乗算(学校法と呼ばれる筆算と同じ計算方法)
/// - parameter a: 掛け合わせたい一方の多数桁の配列のアドレス
/// - parameter b: 掛け合わせたいもう一方の多数桁の配列のアドレス
/// - returns: 乗算した結果を格納する多数桁の配列のアドレス
integer mult(const integer& a, const integer& b);


/*-----------------------
 Using Karatsuba method
------------------------*/

/// a+bをを行いその結果を返り値とする関数
/// - parameter a: 足し合わせたい一方の多数桁の配列のアドレス
/// - parameter b: 足し合わせたいもう一方の多数桁の配列のアドレス
/// - returns: a+bを行った結果の多数桁の配列
integer add(const integer& a, const integer& b);

/// 多数桁の同士の減算を行い、結果を第一引数に格納する関数(a > b)
/// - parameter a: 結果の格納先かつ、減算を行いたい多数桁の配列のアドレス(a > b)
/// - parameter b: 減算を行いたい多数桁の配列のアドレス
/// - returns:　なし
void sub(integer& a, const integer& b);

/// 多数桁の配列aをa0,a1の2つに分割( a0は[ 0,a.size/2 ), a1は[a.size/2,a.size)の各桁)
/// - parameter a: 分割元の多数桁の配列のアドレス
/// - parameter a1:　aの上位[ a.size/2, a.size )の多数桁の配列を格納するアドレス
/// - parameter a0:　aの下位[ 0,a.size/2 )の多数桁の配列を格納するアドレス
/// - returns: なし
void split(const integer& a, integer& a1, integer& a0);

/// カラツバ法を用いて乗算を行う関数(入力の桁数がn0未満なら学校法を適用)
/// - parameter a: 掛け合わせたい一方の多数桁の配列のアドレス
/// - parameter b: 掛け合わせたいもう一方の多数桁の配列のアドレス
/// - parameter n0: 入力の桁数がn0未満なら学校法を適用するための条件切り替えの値
/// - returns: 乗算した結果を格納する多数桁の配列のアドレス
integer Karatsuba(const integer& a, const integer& b, int n0);

#endif // MUL_HEADER_FILE
