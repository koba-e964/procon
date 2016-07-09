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

class TrySail {
    public:
        int get(vector <int> a) {
            /*
            rep(i, strength.size()) {
                printbits(strength[i], 8);
            }
            */
            static ll dp[55][256][256]; rep(i, 55) rep(j, 256) rep(k, 256) dp[i][j][k] = -1;
            dp[0][0][0] = 0;
            ll allxor = 0;
            rep(i, a.size()) {
                allxor ^= a[i];
            }
            rep(i, a.size()) rep(x, 256) rep(y, 256) if (dp[i][x][y] >= 0) {
                chmax(dp[i+1][x^a[i]][y], 1);
                chmax(dp[i+1][x][y^a[i]], 1);
                chmax(dp[i+1][x][y], 1);
            }
            
            ll ret = 0;
            ll i = a.size(); rep(x, 256) rep(y, 256) if (dp[i][x][y] >= 0) {
                chmax(ret, x + y + ((allxor ^ x) ^ y));
            }
            return ret ;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	TrySail *obj;
	int answer;
	obj = new TrySail();
	clock_t startTime = clock();
	answer = obj->get(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
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
	int p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {2,3,3};
	p1 = 8;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {7,3,5,2};
	p1 = 17;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {13,13,13,13,13,13,13,13};
	p1 = 26;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {114,51,4,191,9,81,0,89,3};
	p1 = 470;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {108,66,45,82,163,30,83,244,200,216,241,249,89,128,36,28,250,190,70,95,117,196,19,160,255,129,10,109,189,24,22,25,134,144,110,15,235,205,186,103,116,191,119,183,45,217,156,44,97,197};
	p1 = 567;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
		// ----- test 4 -----
	disabled = false;
	p0 = {108,66,45,82,10,109,189,24,22,25,134,144,110,15,235,205,186,103,116,191,119,183,45,217,156,44,97,197};
	p1 = -1;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, true, p1) ) && all_right;
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
// There are N students in your class.
// The strength of each student is a small nonnegative integer.
// You are given these strengths in the vector <int> strength with N elements.
// 
// You are going to divide all students into three teams for the boat race "TrySail".
// Each student must be assigned to exactly one of the three teams.
// Teams cannot be empty.
// 
// Strangely enough, in this race the strength of a team is the bitwise xor of the strengths of its members.
// You want to maximize the sum of strengths of the three teams.
// Compute and return the largest possible sum of the teams' strengths.
// 
// DEFINITION
// Class:TrySail
// Method:get
// Parameters:vector <int>
// Returns:int
// Method signature:int get(vector <int> strength)
// 
// 
// CONSTRAINTS
// -N will be between 3 and 50, inclusive.
// -strength will contain exactly N elements.
// -Each element of strength will be between 0 and 255, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {2,3,3}
// 
// Returns: 8
// 
// There are only three students.
// The only way to create three nonempty teams is to put each student into a different team.
// In that case the sum of teams' strengths will be 2+3+3 = 8.
// 
// 1)
// {7,3,5,2}
// 
// Returns: 17
// 
// There are 6 ways to make 3 teams:
// · {0},{1},{2,3}: sum of strengths is 7+3+(5 xor 2) = 17
// · {0},{2},{1,3}: sum of strengths is 7+5+(3 xor 2) = 13
// · {0},{3},{1,2}: sum of strengths is 7+2+(3 xor 5) = 15
// · {1},{2},{0,3}: sum of strengths is 3+5+(7 xor 2) = 13
// · {1},{3},{0,2}: sum of strengths is 3+2+(7 xor 5) = 7
// · {2},{3},{0,1}: sum of strengths is 5+2+(7 xor 3) = 11
// Therefore, the answer is 17.
// 
// 2)
// {13,13,13,13,13,13,13,13}
// 
// Returns: 26
// 
// 
// 
// 3)
// {114,51,4,191,9,81,0,89,3}
// 
// Returns: 470
// 
// 
// 
// 4)
// {108,66,45,82,163,30,83,244,200,216,241,249,89,128,36,28,250,190,70,95,117,196,19,160,255,129,10,109,189,24,22,25,134,144,110,15,235,205,186,103,116,191,119,183,45,217,156,44,97,197}
// 
// Returns: 567
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
