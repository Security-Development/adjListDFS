#include <stdio.h>
#include <stdlib.h>
#define MAX 16

struct Node {
	int vertex;
	Node *link;
};

struct Graph {
	int n;
	int cost[MAX];
	Node *list[MAX];
};

void init(Graph *g, bool visit[]) {
	g->n = 0;
	for(int i = 0; i < MAX; i++) {
		g->list[i] = NULL;
		visit[i] = false;
	}
}

void push(Graph *g, int u, int v, int cost) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->vertex = v;
	node->link = g->list[u];
	g->cost[u] = cost;
	g->list[u] = node;
	
}

void dfs(Graph *g, bool visit[], int start) {	
	visit[start] = true;
	Node *node = g->list[start];
	
	printf("값 %d\n", start + g->cost[start]);
	
	while(node != NULL) {
		if( !visit[node->vertex] )
			dfs(g, visit, node->vertex);
		node = node->link;
	}
}
		int node, link, cost;

void input(Graph *g, int n) {
	for(int i = 0; i < n; i++) {
		scanf("%d %d %d", &node, &cost, &link);
		for(int j = 0; j < link; j++) {
			int result;
			scanf("%d", &result);
			if( node == result ) {
				printf("같은 vertex는 연결 할수 없습니다.");
				return;
			}
			push(g, node, result, cost);
		}
		
	}
}

int main() {
	int n, start;
	
	Graph *g = (Graph *)malloc(sizeof(Graph));	
	
	scanf("%d", &n);
	
	bool visit[n];
	
	init(g, visit);
		
	// 노드 개수 설정 
	if( (g->n + 1) > MAX ) 
		return 0;
	g->n = n;
	
	input(g, n);
	
	//aprint(g,);
	printf("탐색을 시작할 vertex를 적어주세요: ");
	scanf("%d", &start);
	
	if( (g->n - 1) < start) {
		printf("\n%d라는 vertex는 없어 탐색 vertex으로 정할 수 없습니다.", start);
		return 0;
	}
	
	dfs(g, visit, start);
	
	free(g);
	
	
	return 0;
}




