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

class DivisibleSetDiv1 {
    public:
        string isPossible(vector <int> b) {
            int n = b.size();
            vll a(n);

            sort(b.begin(), b.end(), greater<int>());

            int sum = 0;
            rep(i, n) a[i] = i + 2, sum += a[i];
//            cout << a << endl;

            rep(loop, 100) {
                bool ok = true;
                rep(i, n) { // for all i 条件が満たされていればOK
                    if (a[i] * (b[i] + 1) < sum) { // ダメだったよ
                        repi(j, i, n) a[j]++, sum++;
                        cout << a << endl;
                        ok = false;
                        break;
                    }
                }
                if (ok) return "Possible";
            }

            return "Impossible";
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, string p1) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}";
    cout << "]" << endl;
    DivisibleSetDiv1 *obj;
    string answer;
    obj = new DivisibleSetDiv1();
    clock_t startTime = clock();
    answer = obj->isPossible(p0);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "\"" << p1 << "\"" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "\"" << answer << "\"" << endl;
    if (hasAnswer) {
        res = answer == p1;
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

    vector <int> p0;
    string p1;

    // ----- test 0 -----
    disabled = false;
    p0 = {2,1};
    p1 = "Possible";
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;

    disabled = false;
    p0 = {2, 2, 3};
    p1 = "Possible";
    all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // -		// ----- test 0 -----
    disabled = false;
    p0 = {1, 2, 4};
    p1 = "Impossible";
    all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------
    // ----- test 0 -----
	disabled = false;
	p0 = {1, 3, 3};
	p1 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    //	// ----- test 0 -----
	disabled = false;
	p0 = {2,2,2};
	p1 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
		// ----- test 0 -----
	disabled = false;
	p0 = {2, 2, 3};
	p1 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {1,1};
	p1 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {7,7,7};
	p1 = "Possible";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {5,3,5,4,6,1,3,7,9,6,2,5,4,1,1,9,6,10,10,6,10,7,7,8};
	p1 = "Impossible";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
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
// You are given a vector <int> b containing a sequence of n positive integers: b[0], ..., b[n-1].
// We are now looking for another sequence a = {a[0], ..., a[n-1]}.
// This sequence should have the following properties:
// 
// The elements of the sequence a should be distinct.
// Each a[i] should be an integer greater than 1.
// For each i, the value a[i]^b[i] (that is, a[i] to the power b[i]) should be divisible by p[i], where p[i] is the product of all other elements of a. (I.e. p[i] = a[0]*a[1]*...*a[i-1]*a[i+1]*...*a[n-1].)
// 
// 
// Determine whether there is at least one sequence with the desired properties.
// Return "Possible" (quotes for clarity) if such a sequence exists and "Impossible" otherwise.
// 
// DEFINITION
// Class:DivisibleSetDiv1
// Method:isPossible
// Parameters:vector <int>
// Returns:string
// Method signature:string isPossible(vector <int> b)
// 
// 
// CONSTRAINTS
// -b will contain between 2 and 50 elements, inclusive.  
// -Each element in b will be between 1 and 10, inclusive.  
// 
// 
// EXAMPLES
// 
// 0)
// {2,1}
// 
// Returns: "Possible"
// 
// Here, we have the following requirements:
// 
// The values a[0] and a[1] should be distinct positive integers, both greater than 1.
// The value a[0]^2 should be divisible by a[1].
// The value a[1]^1 should be divisible by a[0].
// 
// One sequence with the above properties is the sequence a = {2, 4}.
// 
// 1)
// {1,1}
// 
// Returns: "Impossible"
// 
// In this test case the requirements imply that a[0] must be divisible by a[1] and vice versa.
// This is possible only if a[0] = a[1].
// However, the elements of a must be distinct, so there is no valid sequence.
// 
// 2)
// {7, 7, 7}
// 
// Returns: "Possible"
// 
// For example, a = {12, 54, 18}.
// 
// 3)
// {5,3,5,4,6,1,3,7,9,6,2,5,4,1,1,9,6,10,10,6,10,7,7,8}
// 
// Returns: "Impossible"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!