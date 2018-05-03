#include<iostream>

using namespace std;

void graphTraverse (const Graph *G){
	for (int v = 0; v < G -> n(); v++)
		G->setMark(v, UNVISITED);
	for (int v = 0; v < G -> n(); v++)
		if (G -> getMark(v) == UNVISITED)
			DFS(G,v);
}

void DFS (Graph *G, int v){
	G -> setMark(v, VISITED);
	for (int w=G->first(v); w < G->n(); w=G->next(v,w))
		if (G->getMark(w) == UNVISITED)
			DFS(G,w);
}

int main()
{
	Graphm g(6);
	Graph *gp;
	gp = g;
	g.setEdge(0,2,1);
	g.setEdge(0,4,1);
	g.setEdge(1,2,1);
	g.setEdge(1,5,1);
	g.setEdge(2,0,1);
	g.setEdge(2,1,1);
	g.setEdge(2,3,1);
	g.setEdge(2,5,2);
	g.setEdge(3,2,1);
	g.setEdge(3,5,1);
	g.setEdge(4,0,1);
	g.setEdge(4,5,1);
	g.setEdge(5,1,1);
	
	graphTraverse(gp);

	for (int i = 0; i < 6; i++)
	{
		cout << g.mark[i] << " ";
	}	

	cout << endl;

	return 0;
	

}
