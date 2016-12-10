// pekempeyさんのLCTree
// iwiwi先生のLCTree解説 http://www.slideshare.net/iwiwi/2-12188845
// Masaki HaraのSpaceship解説 http://www.slideshare.net/qnighy/2013-spaceships2
// もうちょっと厳密な資料 http://www.lab2.kuis.kyoto-u.ac.jp/fswikiout/wiki.cgi?action=ATTACH&page=2009%C7%AF%C5%D9%B7%D7%BB%BB%CE%CC%CD%FD%CF%C0&file=lecture4.pdf
//
// Splay木
// 平衡二分探索木（ランダムに入力されることを前提としてO(log n), 昇順でO(n)）
//
// 理解のポイント
//
// まず、「木をたくさんの列に分解することで表現している」
// 同じ列であることは、強連結であることで特徴付けている
// 列間の構造は、parentのみの単方向でつなげることで表している。

// 「列を平衡二分探索木で表現している」
// 平行二分探索木を使って、ハイローゲームをしていると思うとわかりやすい。
// 長さnの列の順番を確定させるには、n-1個の情報（=大きさnの木の辺の数）があれば十分である。
//
// 真の根に近いほうが「小さい」ノードであると定義すると、列は平衡二分探索木で表現できる
// この定義では、左が根に近く右が根から遠くなる。
// 
// 例えば、
//   5 - 3 - 2 - 1
// という列を二分探索木で表すとする。
// まず、どこを基準にするかを決める。
// ここでは3を基準とすると、この列を再現するには、「3より5が左側」「3より1が右側」「1より2が左側」という情報が必要
// これを表したSplay木は以下のようになる。
//     3
//   /   |
//  5    1
//      /
//     2
// どんな情報であっても、このようなSplay木が構成可能である。
//
// ところで、列は左右どちらから見ても実質同じであるという問題がある。
// おそらく、この性質をevertを使って吸収しているものと思う。


// 二分探索木が与えられた時、二分探索木が表す順序は一意に定まる！
// 具体的には、二分探索木の根から、「左が終わってないなら左に移動、左が終わってるなら自分を取る、自分も左も終わってるなら右に移動、全部終わってるなら親に戻る」を繰り返せば、列を復元できる
//
// splay(x)すると何が嬉しいか？
// splay(x)後は、
// xの右の子以降が絶対に自分より葉側であり、xの左の子以降が絶対に自分より根側である！
// だから、
// exposeでは右だけ張り替えればよいし、
// cutでは左だけ切ればよい。
//
// expose(x)すると何が嬉しいか？
// xの右側が全部ぶった切られるので、xがxの属するSplay木の中で最も葉側であることが保証される！
// 別の木ならば、Splay木をそのまま貼り付けることができるようになる
//
// Splay木の根は、親がいないという意味ではない！
// Splay木はあくまで左にあるやつが親。
//
#include <bits/stdc++.h>
using namespace std;
 
//**************************************************************
//	link-cut tree
//**************************************************************
struct node {
    // 重要なのは
    // 「Splay木内では、自分の親は自分を子だと思ってくれている」
    // 「Splay木間では、自分の親は知っているが、
    // 　親は自分を子だと認識してくれていない！」
    //
    // 上記の違いによって、いわゆる
    //      Solid edgeとDashed edge
    //      Preferred edgeとNormal edge
    // の区別ができている。
    //
    // 要するに、Splay木間では片方向のリンクしか張られない、ということ
    //
    // http://www.slideshare.net/iwiwi/2-12188845 (p.22参照)
	node *parent;

    // これらはparentとは異なり、平衡二分探索木内での左右のノード、という一意な意味
    // lchが根に近く、rchが根から遠い
	node *lch;
	node *rch;

	bool reversed;
	int id;
	node(int id) : id(id) {
		parent = lch = rch = nullptr;
	}
};
node *tr[1000100];
unordered_map<node*, int> tr_inv;

ostream &operator<<(ostream &o, const node* v) {
    o << (tr_inv[(node*)v]) << " ";
    o << (v->parent ? to_string(v->parent->id) : "-") << " ";
    o << (v->lch ? to_string(v->lch->id) : "-") << " ";
    o << (v->rch ? to_string(v->rch->id) : "-") << " ";
    return o;
}

// なんだこれ
// 何もやってない
// nodeに対する操作が必要になったら実装される？
void update(node *x) {
	if (x == nullptr) return;
}
 
// reversedは一回だけ左右の子をswapして、フラグを落としている
// reversedを除けば何もしていない
void push(node *x) {
	if (x == nullptr) return;
	if (x->reversed) swap(x->lch, x->rch);
 
	x->reversed = false;
 
	update(x);
}
 
//**************************************************************
//	link-cut tree basic operation
//**************************************************************
enum { LEFT, RIGHT };
 
// xが「根」か判定
//
// 「根」とは、「真の根」と「splay木の根」の両方にヒットすることに注意
// 真の根だけを抽出したいなら、x->parent == nullptrで行うこと。
// 更に注意点としては、Link-cut treeは実はTreeというよりForestなので、
// x->parent == nullptrとなるノードは複数存在しうる。
//
// splay木の根を抽出するには、親が自分のことを子だと認知していなければいい
bool is_root(node *x) {
	return x->parent == nullptr ||
        (x->parent->lch != x && x->parent->rch != x);
}
 
// xに取って、親がどっち方向にいるかを判定
// 親が子をどちらにもつか、ではないので注意!
// 親がいなければ-1
int parent_direction(node *x) {
	if (is_root(x)) return -1;
	return x->parent->rch == x ? LEFT : RIGHT;
}
 
// childにとって、parentがdir方向にいるように、parentにつける
void connect(node *child, node *parent, int dir) {
	if (parent != nullptr && dir != -1)
        (dir == RIGHT ? parent->lch : parent->rch) = child;
	if (child != nullptr)
        child->parent = parent;
}
 
// zig-step = xを1つ上に上げるような回転を行う
//     z   
//    /   |
//   y    4 
//  /  |
//  x  3 
// / |
// 1 2 
//
// を、以下のようにする
//
//    z   
//  /    |
//  x    4 
// /  |
// 1  y
//   / |
//   2 3
void raise(node *x) {
	node *y = x->parent; // xの親
	node *z = y->parent; // xの親の親
	int xdir = parent_direction(x);
	int ydir = parent_direction(y);
	connect(xdir == LEFT ? x->lch : x->rch, y, xdir);
	connect(y, x, !xdir);
	connect(x, z, ydir);
	update(y);
	update(x);
	update(z);
}
 
// 頂点xをsplay木の根まで持っていく
void splay(node *x) {
	while (!is_root(x)) {
		push(x->parent->parent);
		push(x->parent);
		push(x);
        // zig-step すぐ上が根の場合は普通に回転
		if (is_root(x->parent)) { 
			raise(x);
        // zig-zig-step 
		} else if (parent_direction(x) == parent_direction(x->parent)) {
			raise(x->parent);
			raise(x);
        // zig-zag-step 
		} else {
			raise(x);
			raise(x);
		}
	}
	push(x);
}
 
// xを、真の根が属するSplay木に属させる。ついでにxをsplay木の根にする。
// 英語の意味は「むきだしにする」「掘り出す」
//
// やっていることは、
// 「splayして、前のを右にくっつけて、親に上がる」を真の親になるまで繰り返している
//
// 重要なこととして、exposeの結果は「見た目」一意でない（もちろんsplayの実装見れば一意だが…）。
// デバッグの時は、exposeの結果が同じ木を表現していることを確認するくらいが関の山。
void expose(node *x) {
	for (node *y = x, *rch = nullptr; y != nullptr; 
            y = y->parent) { // splay(y)しているので、このparentは必ず次のsplay木に移動する
		splay(y);
		y->rch = rch; // y == xの時、右を切っている！
		rch = y;
		update(y);
	}
	splay(x);
}
 
// xとxの親を切断する
void cut(node *x) {
	expose(x);
	x->lch->parent = nullptr;
	x->lch = nullptr;
	update(x);
}
 
// pの右にxをつける
// xとpは、別の木であることを前提としている
// xもpも、exposeで最も葉側となってくれているので、ただくっつけるだけで問題なく列となってくれる
void link(node *x, node *p) {
	expose(x);
	expose(p);
	x->parent = p;
	p->rch = x;
	update(x);
	update(p);
}
 
void evert(node *x) {
	expose(x);
	x->rch = x->lch;
	x->lch = nullptr;
	if (x->rch != nullptr) x->rch->reversed ^= 1;
	update(x);
}
 
//**************************************************************
//	main
//**************************************************************
 
node *lca(node *x, node *y) {
	expose(y);
	expose(x);
 
	bool same = false;
 
	node *l = y;
	while (y != nullptr) {
		if (is_root(y) && y->parent != nullptr) {
			l = y->parent;
		}
		if (y == x->rch) return x;
		if (x == y) same = true;
		y = y->parent;
	}
	if (!same) return nullptr;
	return l;
}
 
/*

6
link 1 2
link 2 3
link 3 5
link 4 5
expose 1
splay 2

// expose, splayは、同じ列を表していることを確認するくらいで良い
*/

int main() {
	int n;
	cin >> n;
 
	for (int i = 0; i < n; i++) {
        tr[i] = new node(i);
        tr_inv[tr[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cout << tr[i] << endl; 
    }
	while (1) {
        cout << "--------" << endl;
        string c; 
        cin >> c;
 
		if (c == "link") {
			int u, v;
			scanf("%d %d", &u, &v);
 
			link(tr[u], tr[v]);
		} else if (c == "cut") {
			int u;
			scanf("%d", &u);
 
			cut(tr[u]);
		} else if (c == "splay") {
			int u;
			scanf("%d", &u);
 
			splay(tr[u]);
		} else if (c == "expose") {
			int u;
			scanf("%d", &u);
 
			expose(tr[u]);
		} else if (c == "lca") {
			int u, v;
			scanf("%d %d", &u, &v);
 
			node *l = lca(tr[u], tr[v]);
			int ans = l == nullptr ? -2 : l->id;
//			printf("%d\n", ans + 1);
		} else {
            cout << "INVALID" << endl;
            exit(1);
        }
        for (int i = 0; i < n; i++) 
            cout << tr[i] << endl;  // parent, lch, rch
	}
}
