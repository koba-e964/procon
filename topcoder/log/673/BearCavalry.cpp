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
using vi = vector<int>;
typedef pair<ll, ll> P;

static const double EPS = 1e-14;
static const long long INF = 1e18;
static const long long MOD = 1e9+7;
#define MAX_N 100005

class BearCavalry {
    public:
        int countAssignments(vector <int> w_, vector <int> h_) {
            ll n = h_.size();
            ll b = w_[0];
            vi w(n-1); rep(i, n-1) { w[i] = w_[i+1]; }
            sort(all(w));

            ll ret = 0;
            rep(i, n) {
                ll m = b * h_[i];
                vi h; rep(j, n) { if (i == j) continue; h.pb(h_[j]); }
                sort(all(h));
                vi num(n-1);
                rep(j, n-1) {
                    int k = 0;
                    for (k = 0; k < n-1; k++) {
                        if (w[j] * h[k] >= m) {
                            num[j] = k;
                            break;
                        } 
                    }
                    if (k == n-1) num[j] = n-1;
                }
                sort(all(num));
                ll tmp = 1;
                for (int j = num.size(); j >= 1; j--) {
                    (tmp *= count_if(all(num), [&](int x) { return x >= j; })) %= MOD;
                    num.pop_back();
                }
                (ret += tmp) %= MOD;
            }
            return ret % MOD;
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	BearCavalry *obj;
	int answer;
	obj = new BearCavalry();
	clock_t startTime = clock();
	answer = obj->countAssignments(p0, p1);
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {5,8,4,8};
	p1 = {19,40,25,20};
	p2 = 2;
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {1,1};
	p1 = {1,1};
	p2 = 0;
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {10,2,10};
	p1 = {100,150,200};
	p2 = 3;
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {10,20};
	p1 = {1,3};
	p2 = 1;
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {20,20,25,23,24,24,21};
	p1 = {20,25,25,20,25,23,20};
	p2 = 0;
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {970,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800};
	p1 = {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
	p2 = 318608048;
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
// Would you want to fight against bears who ride horses?
// Me neither.
// 
// Limak is a grizzly bear.
// He is a general of the dreadful army of Bearland.
// The most important part of the army is, of course, the cavalry.
// 
// The cavalry of Bearland consists of the same number of warriors and horses.
// Limak knows the strength of each warrior and also the strength of each horse.
// These are given in vector <int>s warriors and horses, respectively.
// 
// General Limak must assign exactly one horse to each warrior.
// Obviously, different warriors must be given different horses.
// 
// A warrior together with his assigned horse is called a unit.
// The strength of a unit is equal to the product of the strengths of the warrior and the horse that form the unit.
// 
// The warrior that corresponds to element 0 in warriors is called Bravebeart.
// He is always the first to charge the enemy.
// Limak decided that Bravebeart deserves some respect.
// Thus, his unit must be strictly stronger than any other unit.
// (Ties are not allowed.)
// 
// Given this constraint, let X be the number of valid ways in which Limak can create the units.
// A general must know everything about his army.
// Help Limak count the valid assignments.
// Compute and return the value (X modulo 1,000,000,007).
// 
// DEFINITION
// Class:BearCavalry
// Method:countAssignments
// Parameters:vector <int>, vector <int>
// Returns:int
// Method signature:int countAssignments(vector <int> warriors, vector <int> horses)
// 
// 
// CONSTRAINTS
// -warriors will contain between 2 and 50 elements, inclusive.
// -warriors and horses will contain the same number of elements.
// -Each element in warriors and in horses will be between 1 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {5,8,4,8}
// {19,40,25,20}
// 
// Returns: 2
// 
// There are four warriors and four horses for them.
// Bravebeart's strength is warriors[0] = 5.
// 
// There are two valid ways to pair the warriors and horses into units.
// Below, each unit is presented as an ordered pair (warrior's strength, horse's strength).
// The warriors are presented in the same order as in warriors.
// 
// Valid assignment #1: (5,40), (8,19), (4,25), (8,20).
// 
// Valid assignment #2: (5,40), (8,20), (4,25), (8,19).
// 
// In assignment #1, the strength of Bravebeart's unit is 5*40 = 200.
// The other three units have strengths 8*19 = 152, 4*25 = 100, and 8*20 = 160.
// This is a valid assignment because the number 200 is strictly greater than each of the numbers 152, 100, and 160.
// 
// 1)
// {1,1}
// {1,1}
// 
// Returns: 0
// 
// 
// 
// 2)
// {10,2,10}
// {100,150,200}
// 
// Returns: 3
// 
// There are three valid assignments.
// 
// (10,200), (2,150), (10,100)
// (10,200), (2,100), (10,150)
// (10,150), (2,200), (10,100)
// 
// (Again, the warriors are printed in the same order as in warriors. Hence, in each assignment Bravebeart's unit is the first one printed.)
// 
// 3)
// {10,20}
// {1,3}
// 
// Returns: 1
// 
// 
// 
// 4)
// {20,20,25,23,24,24,21}
// {20,25,25,20,25,23,20}
// 
// Returns: 0
// 
// 
// 
// 5)
// {970,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,
// 800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800,800}
// {1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
// 1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
// 1000,1000,1000,1000,1000,1000,1000,1000,1000,1000}
// 
// Returns: 318608048
// 
// In all 50! assignments Bravebeart's unit is the strongest one.
// Thus, you should return 50! modulo 1,000,000,007.
// Note that even if different warriors/horses have the same strength, they are still considered distinct.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
