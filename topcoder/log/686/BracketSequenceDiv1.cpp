#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(long long i = 0; i < (long long)(n); i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
template<class T1, class T2> bool chmin(T1 &a, T2 b) { return b < a && (a = b, true); }
template<class T1, class T2> bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template <typename T, typename U> ostream &operator<<(ostream &o, const pair<T, U> &v) {  o << "(" << v.first << ", " << v.second << ")"; return o; }
template <typename T> ostream &operator<<(ostream &o, const vector<T> &v) { if (!v.empty()) { o << '['; copy(v.begin(), v.end(), ostream_iterator<T>(o, ", ")); o << "\b\b]"; } return o; }
using ll = long long; using ld = long double; using vll = vector<ll>; using vld = vector<ld>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
#define MAX_N 100005

class BracketSequenceDiv1 {
    public:
        long long count(string s) {
            ll dp[51][51] = {};
            function<ll(ll, ll)> f = [&](ll l, ll r) -> ll { // l: small, r: large
                if (r - l <= -2) return 0;
                if (r - l == -1) return 1;
                if (dp[l][r]) return dp[l][r];

                ll ret = f(l + 1, r);

                if (s[l] == ')' || s[l] == ']') goto skip;
                for (int i = l + 1; i <= r; i++) 
                    if (s[i] == (s[l] == '(' ? ')' : ']')) 
                        ret += f(l + 1, i - 1) * f(i + 1, r);

                skip: return dp[l][r] = ret;
            };

            return f(0, s.length()-1) - 1;
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, long long p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	BracketSequenceDiv1 *obj;
	long long answer;
	obj = new BracketSequenceDiv1();
	clock_t startTime = clock();
	answer = obj->count(p0);
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
	
	string p0;
	long long p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = "()[]";
	p1 = 3ll;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = "())";
	p1 = 2ll;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = "()()";
	p1 = 4ll;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = "([)]";
	p1 = 2ll;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = "())[]][]([]()]]()]]]";
	p1 = 3854ll;
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
// 
// Correct bracket sequences can be defined recursively as follows:
// 
// The empty string "" is a correct sequence.
// If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
// If "X" is a correct sequence, then "(X)" and "[X]" are also correct sequences.
// Each correct bracket sequence can be derived using the above rules.
// 
// 
// 
// Examples of correct bracket sequences include "", "()", "()[][]", "([]())", and "([[()]])".
// 
// 
// You are given a string s that only contains the characters '(', ')', '[', and ']'.
// We want to erase some subset of characters of s (possibly none of them, but not all of them).
// Moreover, we want to do it in such a way that the resulting string will be a correct non-empty bracket sequence.
// Compute and return the number of ways in which this can be done.
// 
// 
// DEFINITION
// Class:BracketSequenceDiv1
// Method:count
// Parameters:string
// Returns:long long
// Method signature:long long count(string s)
// 
// 
// CONSTRAINTS
// -s will contain between 1 and 40 characters, inclusive.
// -Each character in s will be one of '(', ')', '[', ']'.
// 
// 
// EXAMPLES
// 
// 0)
// "()[]"
// 
// Returns: 3
// 
// There are 3 valid ways to erase some characters and obtain a correct non-empty bracket sequence:
// 
// Erase nothing and obtain "()[]".
// Erase the first two characters and obtain "[]".
// Erase the last two characters and obtain "()".
// 
// 
// 1)
// "())"
// 
// Returns: 2
// 
// Here we have 2 solutions: we can either erase the middle character or the last character.
// Note that we count each of those ways separately, even though in both cases we get the same string "()".
// 
// 2)
// "()()"
// 
// Returns: 4
// 
// 
// 
// 3)
// "([)]"
// 
// Returns: 2
// 
// 
// 
// 4)
// "())[]][]([]()]]()]]]"
// 
// Returns: 3854
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
