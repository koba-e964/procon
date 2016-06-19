#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
using P = pair<ll, ll>;

template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template<size_t...> struct seq{}; template<size_t N, size_t... Is> struct gen_seq : gen_seq<N-1, N-1, Is...>{}; template<size_t... Is> struct gen_seq<0, Is...> : seq<Is...>{};
template<class Ch, class Tr, class Tuple, size_t... Is>
void print_tuple(basic_ostream<Ch,Tr>& os, Tuple const& t, seq<Is...>){ using s = int[]; (void)s{0, (void(os << (Is == 0? "" : ", ") << get<Is>(t)), 0)...}; }
template<class Ch, class Tr, class... Args> 
auto operator<<(basic_ostream<Ch, Tr>& os, tuple<Args...> const& t) -> basic_ostream<Ch, Tr>& { os << "("; print_tuple(os, t, gen_seq<sizeof...(Args)>()); return os << ")"; }
ostream &operator<<(ostream &o, const vvll &v) { rep(i, v.size()) { rep(j, v[i].size()) o << v[i][j] << " "; cout << endl; } return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { o << '['; rep(i, v.size()) o << v[i] << (i != v.size()-1 ? ", " : ""); o << "]";  return o; }
template <typename T>  ostream &operator<<(ostream &o, const set<T> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it << (next(it) != m.end() ? ", " : ""); o << "]";  return o; }
template <typename T, typename U>  ostream &operator<<(ostream &o, const unordered_map<T, U> &m) { o << '['; for (auto it = m.begin(); it != m.end(); it++) o << *it; o << "]";  return o; }

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

class Mod {
    public:
        int num, mod;
        Mod() : Mod(0) {}
        Mod(long long int n) : Mod(n, 1000000007) {}
        Mod(long long int n, int m) { mod = m; num = (n % mod + mod) % mod;}
        Mod(const string &s){ long long int tmp = 0; for(auto &c:s) tmp = (c-'0'+tmp*10) % mod; num = tmp; }
        Mod(int n) : Mod(static_cast<long long int>(n)) {}
        operator int() { return num; }
        void setmod(const int mod) { this->mod = mod; }
};
istream &operator>>(istream &is, Mod &x) { long long int n; is >> n; x = n; return is; }
Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % a.mod, a.mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a, b.mod) + b; }
Mod operator+(const Mod a, const long long int b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1, a.mod); }
Mod operator-(const Mod a, const Mod b) { return Mod((a.mod + a.num - b.num) % a.mod, a.mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a, b.mod) - b; }
Mod operator--(Mod &a) { return a - Mod(1, a.mod); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % a.mod, a.mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a, b.mod)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b, a.mod)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b, a.mod)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod factorial(const long long n, const int m = 1000000007) {
    if (n < 0) return 0;
    Mod ret(1, m);
    for (int i = 1; i <= n; i++) {
        ret *= i;
    }
    return ret;
}
Mod operator^(const Mod a, const long long n) {
    if (n == 0) return Mod(1, a.mod);
    Mod res = (a * a) ^ (n / 2);
    if (n % 2) res = res * a;
    return res;
}
Mod operator^(const Mod a, const int n) { return a^(long long)n; }
Mod modpowsum(const Mod a, const long long b) {
    if (b == 0) return 0;
    if (b % 2 == 1) return modpowsum(a, b - 1) * a + Mod(1, a.mod);
    Mod result = modpowsum(a, b / 2);
    return result * (a ^ (b / 2)) + result;
}


class BearPlays {
    public:
        int pileSize(int a, int b, int k) {
            Mod tmp = (Mod(2, a+b)^k)*a;
            return min<ll>(tmp.num, a+b-tmp.num);
        }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit-pf 2.3.0
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cmath>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	BearPlays *obj;
	int answer;
	obj = new BearPlays();
	clock_t startTime = clock();
	answer = obj->pileSize(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	bool disabled;
	bool tests_disabled;
	all_right = true;
	tests_disabled = false;
	
	int p0;
	int p1;
	int p2;
	int p3;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 4;
	p1 = 7;
	p2 = 2;
	p3 = 5;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 5;
	p1 = 5;
	p2 = 3;
	p3 = 0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 2;
	p1 = 6;
	p2 = 1;
	p3 = 4;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 2;
	p1 = 8;
	p2 = 2000000000;
	p3 = 2;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 900000000;
	p1 = 350000000;
	p2 = 3;
	p3 = 300000000;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, true, p3) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	if (all_right) {
		if (tests_disabled) {
			cout << "You're a stud (but some test cases were disabled)!" << endl;
		} else {
			cout << "You're a stud (at least on given cases)!" << endl;
		}
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// Limak is a little bear who loves to play.
// Today he is playing by moving some stones between two piles of stones.
// Initially, one of the piles has A and the other has B stones in it.
// 
// Limak has decided to perform a sequence of K operations.
// In each operation he will double the size of the currently smaller pile.
// Formally, if the current pile sizes are labeled X and Y in such a way that X <= Y, he will move X stones from the second pile to the first one.
// After this move the new pile sizes will be X+X and Y-X.
// 
// You are given the ints A, B, and K.
// Determine the pile sizes after Limak finishes all his operations.
// Return the size of the smaller of those piles.
// 
// Formally, suppose that the final pile sizes are labeled P and Q in such a way that P <= Q.
// Return P.
// 
// DEFINITION
// Class:BearPlays
// Method:pileSize
// Parameters:int, int, int
// Returns:int
// Method signature:int pileSize(int A, int B, int K)
// 
// 
// NOTES
// -Pay attention to the unusual time limit.
// 
// 
// CONSTRAINTS
// -A and B will be between 1 and 1,000,000,000, inclusive. 
// -K will be between 1 and 2,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 4
// 7
// 2
// 
// Returns: 5
// 
// The process will look as follows:
// 
// Initially, the pile sizes are 4 and 7.
// First operation: Limak doubles the pile of size 4 by moving 4 stones from the other pile to this pile. The new pile sizes are 8 and 3.
// Second operation: Limak doubles the pile of size 3. The final pile sizes are 5 and 6.
// As 5 <= 6, the correct return value is 5.
// 
// 
// 1)
// 5
// 5
// 3
// 
// Returns: 0
// 
// The initial pile sizes are 5 and 5.
// In the first operation Limak will double one of them, so after the operation the new pile sizes will be 10 and 0.
// The second and third operation do nothing: in each of them Limak doubles the size of an empty pile.
// 
// As 0 ≤ 10, the correct return value is 0.
// 
// 2)
// 2
// 6
// 1
// 
// Returns: 4
// 
// After the only operation the pile sizes will be 4 and 4, hence the correct return value is 4.
// 
// 3)
// 2
// 8
// 2000000000
// 
// Returns: 2
// 
// 
// 
// 4)
// 900000000
// 350000000
// 3
// 
// Returns: 300000000
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!