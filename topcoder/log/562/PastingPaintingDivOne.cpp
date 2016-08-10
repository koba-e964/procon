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

class PastingPaintingDivOne {
    public:
        vector<long long> countColors(vector <string> b, int t_) {
            ll t = t_;
            vll ret(500);

            map<ll, vector<char>> memo;
            ll maxrange = 200;
            for (ll s = -maxrange; s <= maxrange; s++) {
                vll tmp;
                for (ll i = 0; i <= maxrange; i++) {
                    ll j = i - s;
                    if (i >= 0 && i < b.size() && j >= 0 && j < b[0].size()) {
//                        cout << i << " " << j  << " " << s << endl;
                        memo[s].pb(b[i][j]);
                    }
                }
            }
            /*
            for (auto x : memo) {
                cout << x.fi << " ";
                rep(i, x.se.size()) {
                    cout << x.se[i] << " ";
                }
                cout << endl;
            }
            */

            for (auto x : memo) {
                vector<char>& tmp = x.se;
                bool flag = 1;
                ll blank = 0;
                rep(i, tmp.size()) {
                    if (tmp[i] == '.') {
                        blank++;
                    } else {
                        ll tosum = t;
                        if (!flag) {
                            chmin(tosum, blank + 1);
                        }

                        ret[tmp[i]] += tosum;
                        flag = 0;
                        blank = 0;
                    }
                }
            }

            vll trueret = {ret['R'], ret['G'], ret['B']};
            return trueret;
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
bool KawigiEdit_RunTest(int testNum, vector <string> p0, int p1, bool hasAnswer, vector<long long> p2) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << "\"" << p0[i] << "\"";
    }
    cout << "}" << "," << p1;
    cout << "]" << endl;
    PastingPaintingDivOne *obj;
    vector<long long> answer;
    obj = new PastingPaintingDivOne();
    clock_t startTime = clock();
    answer = obj->countColors(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << "{";
        for (int i = 0; int(p2.size()) > i; ++i) {
            if (i > 0) {
                cout << ",";
            }
            cout << p2[i];
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
        if (answer.size() != p2.size()) {
            res = false;
        } else {
            for (int i = 0; int(answer.size()) > i; ++i) {
                if (answer[i] != p2[i]) {
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

    vector <string> p0;
    int p1;
	vector<long long> p2;
	
	// ----- test 0 -----
	disabled = false;
	p0 = {"..G","R..","BG."};
	p1 = 3;
	p2 = {3ll,4ll,3ll};
	all_right = (disabled || KawigiEdit_RunTest(0, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 1 -----
	disabled = false;
	p0 = {"R...","....","....","...R"};
	p1 = 2;
	p2 = {4ll,0ll,0ll};
	all_right = (disabled || KawigiEdit_RunTest(1, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 2 -----
	disabled = false;
	p0 = {"RGB"};
	p1 = 100000;
	p2 = {100000ll,100000ll,100000ll};
	all_right = (disabled || KawigiEdit_RunTest(2, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 3 -----
	disabled = false;
	p0 = {"."};
	p1 = 1000000000;
	p2 = {0ll,0ll,0ll};
	all_right = (disabled || KawigiEdit_RunTest(3, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 4 -----
	disabled = false;
	p0 = {"RB.",".G."};
	p1 = 100;
	p2 = {100ll,1ll,100ll};
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
   
    // ----- test 4 -----
	disabled = false;
	p0 = {"R..","...", "..G"};
	p1 = 100;
	p2 = {100ll,2ll,0ll};
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    // ----- test 4 -----
	disabled = false;
	p0 = {"R...","....","....", "...R"};
	p1 = 2;
	p2 = {4ll,0ll,0ll};
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
    // ----- test 4 -----
	disabled = false;
	p0 = {"R...",".R..","..R.", "...R"};
	p1 = 2;
	p2 = {5ll,0ll,0ll};
	all_right = (disabled || KawigiEdit_RunTest(4, p0, p1, true, p2) ) && all_right;
	tests_disabled = tests_disabled || disabled;
	// ------------------
	
	// ----- test 5 -----
	disabled = false;
	p0 = {"..........G..........",".........G.G.........","........G...G........",".......G.....G.......","......G..B.B..G......",".....G...B.B...G.....","....G...........G....","...G...R.....R...G...","..G.....RRRRRR....G..",".G..........RR.....G.","GGGGGGGGGGGGGGGGGGGGG"};
	p1 = 1000000000;
	p2 = {2000000018ll,17000000048ll,2000000005ll};
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
// Cucumber Boy likes drawing pictures.  Today, he plans to draw a picture using a very simple graphics editor.
// 
// The editor has the following functions:
// 
// The canvas is an infinite two-dimensional grid of pixels.
// There are only four colors: red, green, blue, and transparent. These are denoted 'R', 'G', 'B', and '.' (a period), respectively.
// The editor has a clipboard that contains a rectangular picture.
// The editor can take the picture in the clipboard and paste it onto any corresponding rectangle of the canvas. The user just has to select the pixel of the canvas where the upper left corner of the clipboard will be pasted.
// When pasting the picture, the red, green, and blue pixels of the picture in the clipboard will overwrite their corresponding pixels on the canvas. The pixels that are transparent in the clipboard picture do not change the canvas.
// 
// 
// At this moment, all pixels on the infinite canvas are transparent.  Cucumber Boy has already stored a picture in the clipboard.  You are given this picture as a vector <string> clipboard.
// 
// Cucumber Boy now wants to paste the clipboard picture onto the canvas exactly T times in a row.  For each i, when pasting the clipboard for the i-th time, he will choose the pixel (i,i) as the upper left corner of the pasted picture.
// 
// You are given the vector <string> clipboard and the int T.  Return a vector<long long> containing exactly three elements: the number of red, green, and blue pixels on the canvas after all the pasting is finished.
// 
// DEFINITION
// Class:PastingPaintingDivOne
// Method:countColors
// Parameters:vector <string>, int
// Returns:vector<long long>
// Method signature:vector<long long> countColors(vector <string> clipboard, int T)
// 
// 
// CONSTRAINTS
// -clipboard will contain between 1 and 50 elements, inclusive.
// -Each element of clipboard will contain between 1 and 50 characters, inclusive.
// -Each element of clipboard will contain the same number of characters.
// -Each character of each element of clipboard will be one of 'R', 'G', 'B', and '.'.
// -T will be between 1 and 1,000,000,000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {
// "..G",
// "R..",
// "BG."
// }
// 3
// 
// Returns: {3, 4, 3 }
// 
// 
// 
// 1)
// {
// "R...",
// "....",
// "....",
// "...R"
// }
// 2
// 
// Returns: {4, 0, 0 }
// 
// 
// 
// 2)
// {"RGB"}
// 100000
// 
// Returns: {100000, 100000, 100000 }
// 
// 
// 
// 3)
// {"."}
// 1000000000
// 
// Returns: {0, 0, 0 }
// 
// 
// 
// 4)
// {
// "RB.",
// ".G."
// }
// 
// 100
// 
// Returns: {100, 1, 100 }
// 
// 
// 
// 5)
// {
// "..........G..........",
// ".........G.G.........",
// "........G...G........",
// ".......G.....G.......",
// "......G..B.B..G......",
// ".....G...B.B...G.....",
// "....G...........G....",
// "...G...R.....R...G...",
// "..G.....RRRRRR....G..",
// ".G..........RR.....G.",
// "GGGGGGGGGGGGGGGGGGGGG"
// }
// 1000000000
// 
// Returns: {2000000018, 17000000048, 2000000005 }
// 
// Note that the answers may overflow a 32-bit integer variable.
// 
// 
// This is the image of clipboard in this example.
// 
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit-pf 2.3.0!