#include <bits/stdc++.h>
#include <time.h>
#include <sys/time.h>
using namespace std;
using ll = long long; using ld = long double; using vll = vector<ll>; using vi = vector<int>;
#define rep(i,n) for(int i = 0; i < n; i++)

ll randr(ll i, ll j) { if (i > j) return i; else return (ll)rand() % (j - i + 1) + i; }
ld randrf(ld i, ld j) { return ((ld)rand() / RAND_MAX) * (j - i) + i; }

int main(int argc, char** argv)
{
    struct timeval myTime; struct tm *time_st; gettimeofday(&myTime, NULL); time_st = localtime(&myTime.tv_sec); srand(myTime.tv_usec);

    ll x = 0;
    if (argc >= 2) 
        x = atoi(argv[1]);

    ll n = x;
    cout << n << endl;
    rep(i, n) {
        cout << i+1 << " ";
    }
    cout << endl;
    ll q = 10;
    cout << q << endl;
    rep(i, q) {
        ll l = randr(1, n);
        ll r = randr(l, n);
        cout << l << " " << r << endl;
    }

    return 0;
}

