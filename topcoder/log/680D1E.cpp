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

class BearFair {
    public:
        string isFair(int n, int b, vector <int> upTo, vector <int> quantity) {
           vector<P> q; 
            rep(i, upTo.size()) 
                q.pb(P(upTo[i], quantity[i])); 
            sort(all(q));
            if (q[q.size()-1].first != b)
                q.push_back(P(b, n));

            rep(i, q.size()-1) 
                if (q[i].first == q[i+1].first && q[i].second != q[i+1].second)
                    return "unfair";

            bool dp[1010][55][55] = {};
            dp[0][0][0] = true;
            rep(i, b) rep(e, n+1) rep(o, n+1) {
                if (!dp[i][e][o]) continue;
                bool tmp;
                tmp = 1; for (auto x : q) { if (x.first == i+1 && x.second != o+e+1) { tmp = 0; break; } }
                ((i+1)%2?dp[i+1][e][o+1]:dp[i+1][e+1][o]) = (e+o+1<=n && tmp);

                tmp = 1; for (auto x : q) { if (x.first == i+1 && x.second != o+e+0) { tmp = 0; break; } }
                dp[i+1][e][o] = (e+o<=n && tmp);
            }

            return dp[b][n/2][n/2]?"fair":"unfair";
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
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, vector <int> p3, bool hasAnswer, string p4) {
    cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
    for (int i = 0; int(p2.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p2[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p3.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p3[i];
    }
    cout << "}";
    cout << "]" << endl;
    BearFair *obj;
    string answer;
    obj = new BearFair();
    clock_t startTime = clock();
    answer = obj->isFair(p0, p1, p2, p3);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "\"" << p4 << "\"" << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << "\"" << answer << "\"" << endl;
    if (hasAnswer) {
        res = answer == p4;
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
    vector <int> p2;
    vector <int> p3;
    string p4;

    // ----- test 0 -----
    disabled = false;
    p0 = 4;
    p1 = 6;
    p2 = {3,6};
    p3 = {2,4};
    p4 = "fair";
    all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) ) && all_right;
    tests_disabled = tests_disabled || disabled;
    // ------------------

    // ----- test 1 -----
	disabled = false;
	p0 = 4;
	p1 = 6;
	p2 = {3,6};
	p3 = {2,3};
	p4 = "unfair";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = 2;
	p1 = 6;
	p2 = {1,2,3};
	p3 = {1,1,2};
	p4 = "unfair";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = 50;
	p1 = 1000;
	p2 = {736,205,264,235,273,40,901,37,900,424,122,517,820,402,669,279,455,921,774,923,107,936,484,171,248,186,970,231,321,902,606,24,451,585,823,270,361,292,128,521,689,683,270,726,980,652,996,909,196,357};
	p3 = {35,9,9,9,9,3,46,3,46,18,7,25,39,18,32,9,20,49,37,49,7,49,24,8,9,8,49,9,12,46,29,2,20,29,39,9,16,11,7,27,33,32,9,34,49,32,50,47,8,16};
	p4 = "fair";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = 4;
	p1 = 1000;
	p2 = {400,600};
	p3 = {4,0};
	p4 = "unfair";
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) ) && all_right;
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
// Limak is a grizzly bear.
// He is big and dreadful.
// You were chilling in the forest when you suddenly met him.
// It's very unfortunate for you.
// He will eat all your cookies unless you can demonstrate your mathematical skills.
// To test you, Limak is going to give you a puzzle to solve.
// 
// 
// 
// It's a well-known fact that Limak, as every bear, owns a set of numbers.
// You know some information about the set:
// 
// The elements of the set are distinct positive integers.
// The number of elements in the set is n. The number n is even.
// All elements are between 1 and b, inclusive: bears don't know numbers greater than b.
// The set contains exactly n/2 even elements and exactly n/2 odd elements, because grizzly bears only like sets with this property.
// 
// 
// 
// 
// Limak smiles mysteriously and gives you q hints about his set.
// The hints are numbered 0 through q-1.
// For each valid i, the hint number i is the following sentence:
// "If you only look at elements that are between 1 and upTo[i], inclusive, you will find exactly quantity[i] such elements in my set."
// 
// 
// 
// In a moment Limak will tell you the actual puzzle, but something doesn't seem right...
// That smile was very strange.
// You start to think about a possible reason.
// Maybe Limak cheated you?
// Or is he a fair grizzly bear?
// 
// 
// 
// You are given the ints n and b.
// You are also given the vector <int>s upTo and quantity.
// Return "fair" (quotes for clarity) if there exists at least one set that has all the required properties and matches all the given hints.
// Otherwise, return "unfair".
// 
// 
// DEFINITION
// Class:BearFair
// Method:isFair
// Parameters:int, int, vector <int>, vector <int>
// Returns:string
// Method signature:string isFair(int n, int b, vector <int> upTo, vector <int> quantity)
// 
// 
// CONSTRAINTS
// -n will be between 2 and 50, inclusive.
// -n will be even.
// -b will be between n and 1000, inclusive.
// -q will be between 1 and 50, inclusive.
// -upTo will have exactly q elements.
// -quantity will have exactly q elements.
// -Each element in upTo will be between 1 and b, inclusive.
// -Each element in quantity will be between 0 and n, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 4
// 6
// {3,6}
// {2,4}
// 
// Returns: "fair"
// 
// Limak is a fair bear. Some sets that match his hints are {1,3,4,6} and {1,2,4,5}.
// 
// 1)
// 4
// 6
// {3,6}
// {2,3}
// 
// Returns: "unfair"
// 
// The second hint is that exactly 3 elements are between 1 and 6 (inclusive).
// But there should be 4 elements in total, all between 1 and 6 (inclusive).
// In this situation Limak is clearly being unfair, there is no set that matches these hints.
// 
// 2)
// 2
// 6
// {1,2,3}
// {1,1,2}
// 
// Returns: "unfair"
// 
// The only set that matches the hints is the set {1,3}. However, this set violates the constraint that the number of odd elements must be n/2.
// 
// 3)
// 50
// 1000
// {736,205,264,235,273,40,901,37,900,424,122,517,820,402,669,279,455,921,774,923,107,936,484,171,248,
// 186,970,231,321,902,606,24,451,585,823,270,361,292,128,521,689,683,270,726,980,652,996,909,196,357}
// {35,9,9,9,9,3,46,3,46,18,7,25,39,18,32,9,20,49,37,49,7,49,24,8,9,8,49,9,12,46,29,2,20,29,39,9,16,11,7,27,33,32,9,34,49,32,50,47,8,16}
// 
// Returns: "fair"
// 
// 
// 
// 4)
// 4
// 1000
// {400,600}
// {4,0}
// 
// Returns: "unfair"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!