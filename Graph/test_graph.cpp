#include<iostream>
#include"graph.h"
using namespace std;

void DFS (Graphm *G, int v); 

void graphTraverse (Graphm *G){
	for (int v = 0; v < G -> n(); v++)
		G->setMark(v, UNVISITED);
	for (int v = 0; v < G -> n(); v++)
		if (G -> getMark(v) == UNVISITED)
			DFS(G,v);
}

void DFS (Graphm *G, int v){
	G -> setMark(v, VISITED);
	for (int w=G->first(v); w < G->n(); w=G->next(v,w))
		if (G->getMark(w) == UNVISITED)
			DFS(G,w);
}

int main()
{
	Graphm g(6);
	//Graphm *gp;
	//gp = g;
	g.setEdge(0,2,1);
	g.setEdge(0,4,1);
	g.setEdge(1,2,1);
	g.setEdge(1,5,1);
	//g.setEdge(2,0,1);
	//g.setEdge(2,1,1);
	g.setEdge(2,3,1);
	g.setEdge(2,5,2);
	//g.setEdge(3,2,1);
	g.setEdge(3,5,1);
	//g.setEdge(4,0,1);
	//g.setEdge(4,5,1);
	
	graphTraverse(&g);

//	for (int i = 0; i < 6; i++)
//	{
//		cout << g.mark[i] << " ";
//	}	

//	cout << endl;

	return 0;
	

}
