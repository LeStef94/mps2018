#include<iostream>
#include<fstream>
#define leng 100001
using namespace std;

ifstream f("dfs.in");
ofstream g("dfs.out");

struct nod {
	int info;
	nod* next;
};

void add_node(nod *&p, nod *&u, int i) {
	if (p == NULL) {
		p = new nod;
		p->info = i;
		u = p;
		u->next = NULL;
	}
	else {
		nod *c = new nod;
		c->info = i;
		u->next = c;
		u = c;
		u->next = NULL;
	}
}

void dfs_graph(int start, int *vis, nod **L) {
	nod *current = L[start];
	vis[start] = 1;
	for (current = L[start]; current != NULL; current = current->next) {
		if (vis[current->info] == 0) {
			dfs_graph(current->info,vis,L);
		}
	}
}

int main()
{
	int N, M;
	int i, j;
	f >> N >> M;

	nod* L[leng], *LF[leng];
	nod *p, *u;
	p = u = NULL;

	for (int i = 0; i < leng; i++) {
		L[i] = LF[i] = NULL;
	}

	while (M--) {
		f >> i >> j;
		add_node(L[i], LF[i], j);
		add_node(L[j], LF[j], i);
	}

	int * vis = new int[leng];
	for (int i = 0; i < leng; i++)
		vis[i] = 0;
	
	int counter = 0;
	for (int i = 1; i <= N; i++) {
		if (vis[i]==0) {
			counter++;
			dfs_graph(i, vis, L);
		}
	}

	g << counter;
	f.close();
	g.close();
	return 0;
}