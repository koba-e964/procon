#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define repi(i,a,b) for(long long i = (long long)(a); i < (long long)(b); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define mt make_tuple
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

using ll = long long; using ld = long double; using vll = vector<ll>; using vvll = vector<vll>; using vld = vector<ld>; 
using vi = vector<int>; using vvi = vector<vi>;
vll conv(vi& v) { vll r(v.size()); rep(i, v.size()) r[i] = v[i]; return r; }
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
void printbits(ll mask, ll n) { rep(i, n) { cout << !!(mask & (1ll << i)); } cout << endl; }

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long mo = 1e9+7;

class PeriodicJumping {
    public:
        int minimalTime(int x_, vector <int> a_) {
            ll x = x_;
            vll a = conv(a_);
            if (x == 0) return 0;
            x = abs(x);
            ll s = accumulate(all(a), 0ll);
            if (x >= s) {
                ll tmp = 0;
                ll len = x / s * s;
                rep(i, a.size()) {
                    if (len >= x)
                        break;
                    len += a[i];
                    tmp++;
                }
                return x / s * a.size() + tmp;
            } else {
                ll m = x;
                ll total = x;
                ll i = 0;
                while (1) {
                    if (total >= 2 * m)
                        return i;
                    total += a[i%a.size()];
                    chmax(m, a[i%a.size()]);
                    i++;
                }
            }
            return -1;
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
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	PeriodicJumping *obj;
	int answer;
	obj = new PeriodicJumping();
	clock_t startTime = clock();
	answer = obj->minimalTime(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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
	vector <int> p1;
	int p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = 15;
	p1 = {1,2,3,4,5,6,7,8,9,10};
	p2 = 5;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = 5;
	p1 = {5};
	p2 = 1;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 1;
	p1 = {10};
	p2 = 2;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = -10;
	p1 = {2,3,4,500,6,7,8};
	p2 = 11;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = -1000000000;
	p1 = {1};
	p2 = 1000000000;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = 0;
	p1 = {19911120};
	p2 = 0;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 5 -----
	disabled = false;
	p0 = 9;
	p1 = {772315883, 948801907, 98119050, 332167024, 90543450, 984872854, 38742565, 925804740, 773648065, 747538803, 418344074, 82024644, 908911712, 900413060, 567506548, 328888170, 679620977, 134381153, 917548834, 579233405, 989349349, 706906090, 52516266, 293093511, 11048303, 745411998, 531770467, 720217823, 140798884, 207817129, 33522981, 971002846, 890522096, 990265718, 358225050, 766726420, 355198127, 424365730, 331750579, 96129537, 64599184, 238258575, 455658049, 443945039, 21293907, 591926314, 803118293, 715681892, 979576220, 382647791};
	p2 = 4;
	all_right = (disabled || KawigiEdit_RunTest(5, p0, p1, true, p2) ) && all_right;
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
// Frog Suwako lives on a two-dimensional plane.
// Currently, she is located in the point (0, 0).
// She would like to reach the point (x, 0).
// 
// 
// 
// Suwako jumps in a peculiar way: her jump lengths repeat in a periodic fashion.
// The vector <int> jumpLengths contains one period of her jump lengths, starting with the length of the first jump she will make.
// For example, if jumpLengths = { 2, 5 }, Suwako's jump lengths will be 2, 5, 2, 5, 2, 5, ...
// Note that Suwako can jump onto arbitrary points in the plane, they are not required to have integer coordinates.
// 
// 
// 
// You are given the int x and the vector <int> jumpLengths.
// Return the smallest non-negative integer j such that Suwako can reach the desired destination after j jumps.
// If there is no such j, return -1 instead.
// 
// DEFINITION
// Class:PeriodicJumping
// Method:minimalTime
// Parameters:int, vector <int>
// Returns:int
// Method signature:int minimalTime(int x, vector <int> jumpLengths)
// 
// 
// CONSTRAINTS
// -x will be between -1,000,000,000 and 1,000,000,000, inclusive.
// -jumpLengths will contain between 1 and 50 elements, inclusive.
// -Each element in len will be between 1 and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 15
// {1,2,3,4,5,6,7,8,9,10}
// 
// Returns: 5
// 
// In 4 jumps Suwako cannot get far enough. In 5 jumps she can reach the destination as follows: (0,0) -> (1,0) -> (3,0) -> (6,0) -> (10,0) -> (15,0).
// 
// 
// 1)
// 5
// {5}
// 
// Returns: 1
// 
// One jump is enough, since the distance between (0,0) and (5,0) is exactly 5.
// 
// 2)
// 1
// {10}
// 
// Returns: 2
// 
// Here Suwako needs two jumps. One possible solution is to land at (0.5, sqrt(10*10-0.5*0.5)) after the first jump.
// 
// 
// 3)
// -10
// {2,3,4,500,6,7,8}
// 
// Returns: 11
// 
// 
// 
// 4)
// -1000000000
// {1}
// 
// Returns: 1000000000
// 
// 
// 
// 5)
// 0
// {19911120}
// 
// Returns: 0
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
