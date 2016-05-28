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

class SplitStoneGame {
    public:
        string winOrLose(vector <int> number) {
            if (number.size() <= 2 || accumulate(all(number), 0) == number.size())
                return "LOSE";
            return number.size() % 2 ? "WIN" : "LOSE";
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
	SplitStoneGame *obj;
	string answer;
	obj = new SplitStoneGame();
	clock_t startTime = clock();
	answer = obj->winOrLose(p0);
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
	p0 = {1,1,1};
	p1 = "LOSE";
	all_right = (disabled || KawigiEdit_RunTest(0, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {2,2};
	p1 = "LOSE";
	all_right = (disabled || KawigiEdit_RunTest(1, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {1,1,2};
	p1 = "WIN";
	all_right = (disabled || KawigiEdit_RunTest(2, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {1,2,3,4,3,2,2,4,3,1,4,4,1,2,4,4,1,4,3,1,4,2,1};
	p1 = "WIN";
	all_right = (disabled || KawigiEdit_RunTest(3, p0, true, p1) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {1,1,1,1,1,1,1,1,1,1,2,1,1,1,3,1,9,1,3,1,1,1,1,1};
	p1 = "LOSE";
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
// Shiny likes to play games.
// Her favorite games are games with pebbles (small stones).
// Today, she is playing such a game with her friend Lucy.
// 
// Initially, there are N piles of stones.
// You are given a vector <int> number with N elements.
// Each element of number is the number of stones in one of the piles.
// 
// The players take alternating turns.
// Shiny plays first.
// In each turn, the current player must:
// 
// Choose a pile X that has at least two stones.
// Split the chosen pile X into two non-empty parts A and B. (The parts can have arbitrary sizes, as long as both are non-empty.)
// Choose two piles Y and Z. (Y and Z must be different non-empty piles other than X.)
// Add all stones from A to the pile Y, and all stones from B to the pile Z.
// 
// 
// For example, if the current piles are {1, 2, 50}, the current player could:
// 
// Choose the pile with 50 stones as X.
// Split it into two parts with 25 stones each.
// Choose the other two piles (the ones with 1 and 2 stones) to be Y and Z.
// Add all stones from A to the pile Y, and all stones from B to the pile Z. At the end of the turn, there are two piles of stones: one with 26 and one with 27 stones.
// 
// 
// The player who cannot make a valid move loses the game.
// Assume that both players play the game optimally.
// Return the string "WIN" (quotes for clarity) if Shiny wins the game, and "LOSE" if she does not.
// 
// 
// DEFINITION
// Class:SplitStoneGame
// Method:winOrLose
// Parameters:vector <int>
// Returns:string
// Method signature:string winOrLose(vector <int> number)
// 
// 
// CONSTRAINTS
// -number will contain between 1 and 50 elements, inclusive.
// -Each element of number will be between 1 and 50, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1, 1, 1}
// 
// Returns: "LOSE"
// 
// Shiny can't choose a pile X that has at least two stones, so she loses.
// 
// 1)
// {2, 2}
// 
// Returns: "LOSE"
// 
// After Shiny chooses one of the piles as X and splits it into two piles with one stone each, she is
// unable to choose Y and Z, because there is only one pile left to choose from at the moment. Thus,
// she cannot make a valid move and therefore she loses the game.
// 
// 2)
// {1, 1, 2}
// 
// Returns: "WIN"
// 
// Shiny can choose the last pile as X, split it into 1+1 stone, and add those stones to the other two
// piles. This is a valid move that produces two piles with two stones each, and it is now Lucy's turn. 
// As we saw in Example 1, Lucy now has no valid move left, thus she loses the game and Shiny is the
// winner.
// 
// 3)
// {1, 2, 3, 4, 3, 2, 2, 4, 3, 1, 4, 4, 1, 2, 4, 4, 1, 4, 3, 1, 4, 2, 1}
// 
// Returns: "WIN"
// 
// 
// 
// 4)
// {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 3, 1, 9, 1, 3, 1, 1, 1, 1, 1}
// 
// Returns: "LOSE"
// 
// 
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!
