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

// 対応する括弧列を出力する。対応する閉括弧が異常なら-1, 開括弧が異常なら-2
// O(n^2)
// もう少しどうにかなると思うけど…しかも、できれば深さも知りたい
//  ) ) ( ) (
// -1-1 3 2-2
vector<ll> correspondingParentheses(string s) {
    vector<ll> ret(s.length(), -1);
    rep(i, s.length()) {
        if (ret[i] >= 0) continue;
        ll j;
        ll sum = 0;
        for (j = i; j < s.length(); j++) {
            sum += (s[j] == '(' ? 1 : -1);
            if (sum < 0) { ret[i] = -1; break; }
            if (sum == 0) { ret[i] = j, ret[j] = i; break; }
        }
        if (j == s.length()) 
            ret[i] = -2;
    }
    return ret;
}
// sが正しい括弧列かを判別する
// O(n)
bool isValidParentheses(string s) {
    ll counter = 0; 
    rep(i, s.length()) 
        if ((counter += (s[i] == '(' ? 1 : -1)) < 0)
            return false;
    return counter == 0;
}
// sの括弧数を求める
// O(n)
ll countOpenParentheses(string& s) { ll sum = 0; rep(i, s.length()) sum += s[i] == ')'; return sum; }
ll countClosingParentheses(string& s) { ll sum = 0; rep(i, s.length()) sum += s[i] == '('; return sum; }

class ParenthesesDiv1Easy {
    public:
        vector<int> correct(string s) {
            if (s.length() % 2) return vector<int>(1, -1);
            if (isValidParentheses(s)) return vector<int>();

            // 行き過ぎることはない…と思うが
            vector<ll> ret;
            rep(i, 9) {
                vector<ll> corr = correspondingParentheses(s);
                bool faf = 1;
                for (int j = 0; j < corr.size(); j++) {
                    if (corr[j] == -1) {
                        faf = 0;
                        break;
                    }
                }
                if (faf) break;

                ll j, h; // [j, h)
                for (j = 0; j < corr.size(); j++) 
                    if (corr[j] == -1)
                        break;
                for (h = j; h < corr.size(); h++) 
                    if (corr[h] == -2)
                        break;
                ret.pb(j); ret.pb(h-1);

                reverse(s.begin()+j, s.begin()+h);
                for (ll k = j; k < h; k++) 
                    s[k] = (s[k] == ')' ? '(' : ')');

            }

            vector<ll> corr = correspondingParentheses(s);
            ll sum = 0; 
            rep(i, corr.size()) 
                sum += (corr[i] == -2);
            sum /= 2;
            ll j;
            for (j = corr.size()-1; j >= 0; j--) {
                if (corr[j] == -2) 
                    sum--;
                if (!sum)
                    break;
            }
            ret.pb(j); ret.pb(corr.size()-1);

            vector<int> ret_; rep(i, ret.size()) ret_.pb(ret[i]);
            return ret_;
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
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, vector <int> p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	ParenthesesDiv1Easy *obj;
	vector <int> answer;
	obj = new ParenthesesDiv1Easy();
	clock_t startTime = clock();
	answer = obj->correct(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p1.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << p1[i];
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << answer[i];
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p1.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p1[i]) {
					res = false;
				}
			}
		}
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
	vector <int> p1;
	
	// ----- test 0 -----
	disabled = false;
	p0 = ")(";
	p1 = {0,0,1,1};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = "))))))((((((";
	p1 = {0,5,6,11};
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = "))()())()";
	p1 = {-1};
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = ")()(((";
	p1 = {0,0,3,3,5,5};
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = "()";
	p1 = {};
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
// Correct parentheses sequences can be defined recursively as follows:
// 
// The empty string "" is a correct sequence.
// If "X" and "Y" are correct sequences, then "XY" (the concatenation of X and Y) is a correct sequence.
// If "X" is a correct sequence, then "(X)" is a correct sequence.
// Each correct parentheses sequence can be derived using the above rules.
// 
// Examples of correct parentheses sequences include "", "()", "()()()", "(()())", and "(((())))".
// 
// 
// You have a string s.
// You want to change it into a correct parentheses sequence.
// 
// 
// 
// You can only change the string using magic flips.
// In order to do a magic flip, you specify two 0-based indices L and R such that L <= R.
// The operation modifies the characters on indices from L to R, inclusive.
// First, the order of these characters is reversed.
// Then, each character is toggled to the opposite one.
// That is, each '(' in the specified range changes to a ')' and vice versa.
// 
// 
// 
// For example, suppose you have the string "((()".
// If you do a magic flip on the entire string (i.e., choosing L=0 and R=3), it first gets reversed to ")(((" and then all parentheses are toggled. Thus, flipping the string "((()" produces the string "()))".
// 
// 
// 
// Given s, find and report any sequence of at most 10 magic flips that changes s into a correct parentheses sequence.
// If there is no such sequence of magic flips, return the vector <int> {-1}.
// If there are multiple such sequences, you may return any of them.
// In particular, you are not required to find the shortest possible sequence of flips.
// The returned vector <int> should contain 2*F elements, where F is the number of flips you want to perform: 
// for each flip, in order, first its L and then its R.
// 
// DEFINITION
// Class:ParenthesesDiv1Easy
// Method:correct
// Parameters:string
// Returns:vector <int>
// Method signature:vector <int> correct(string s)
// 
// 
// CONSTRAINTS
// -s will contain between 1 and 1,000 characters, inclusive.
// -Each character in s will be '(' or ')'.
// 
// 
// EXAMPLES
// 
// 0)
// ")("
// 
// Returns: {0, 0, 1, 1 }
// 
// The first flip has L=R=0.
// It changes the string to "((".
// The second flip has L=R=1.
// It changes that string to "()", which is a correct parentheses sequence.
// 
// 1)
// "))))))(((((("
// 
// Returns: {0, 5, 6, 11 }
// 
// Here, the first flip changes the string to "((((((((((((" and then the second flip changes it to "(((((())))))".
// 
// Note that {0,0,1,1,2,2,...,11,11} is not a valid solution.
// This sequence of flips produces a correct parentheses sequence (by flipping each character separately).
// However, this sequence consists of 12 flips and we are only allowed to perform at most 10 flips.
// 
// 2)
// "))()())()"
// 
// Returns: {-1 }
// 
// This s has length 9.
// There is no correct parentheses sequence of length 9, so there can be no good sequence of flips.
// 
// 3)
// ")()((("
// 
// Returns: {0, 0, 3, 3, 5, 5 }
// 
// 
// 
// 4)
// "()"
// 
// Returns: { }
// 
// This time we don't need to do anything.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!