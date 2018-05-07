#define UNVISITED 0
#define VISITED 1


class Graph{
	public:
	//Return the number of vertices
	virtual int n() =0;
	//Return the current number of edges
	virtual int e() =0;
	//Return the index of the first neigbor of given vertex
	virtual int first(int) =0;
	//Return the index of the next neigbor of given vertex
	virtual int next(int, int) =0;
	//Store an edge defined by two vertices and weight
	virtual void setEdge(int, int, int) =0;
	//Delete edge defined by two vertices
	virtual void delEdge(int, int) =0;
	//Return weight of edge connecting two vertices
	//Return 0 if no such edge exits
	virtual int weight(int, int) =0;
	//Get mark value for a vertex
	virtual int getMark(int) =0;
	//Set mark value for a vertex
	virtual void setMark(int, int) =0;
};

class Edge {
public:
	int vertex, weight;
	Edge() {vertex = -1; weight = -1;}
	Edge(int v, int w) {vertex = v; weight = w;}
};

class Graphl : public Graph{
private:
	int numVertex, numEdge;		//Store number of vertices, edges
	List<Edge>** vertex;		//List headers
	int *mark;			//Pointer to mark array
public:
	Graphl(int numVert) {
		int i, j;
		numVertex = numVert;
		numEdge = 0;
		mark = new int[numVert];	//Initialize mark array
		for (i=0; i<numVertex; i++)
			mark[i] = UNVISITED;
		
		//Create and initialize adjacency lists
		vertex = (List<Edge> **) new List<Edge>*[numVertex];
		for (i = 0; i<numVertex; i++)
			vertex[i] = new LList<Edge>();
	}

	~Graphm() {
		delete [] mark;
		for (int i = 0; i<numVertex; i++)
			delete [] vertex[i];
		delete [] vertex;
	}

	int n() {return numVertex;}
	int e() {return numEdge;}

	int first (int v) {
		Edge it;
		vertex[v]-> setStart();
		if (vertex[v]->getValue(it))
			return it.vertex;
		else
			return numVertex;	//Return n if none ,be use to terminate loop
	}

	int next (int v1, int v2){		//Get v1's neighbor after v2
		Edge it;
		vertex[v1]->getValue(it);
		if (it.vertex == v2)
			vertex[v1]->next();
		else {
			vertex[v1]->setStart();
			while (vertex[v1]->getValue(it) && (it.vertex <= v2))
				vertex[v1]->next();
		}
		if (vertex[v1]->getValue(it))
			return it.vertex;
		else
			return numVertex;
	}
	
	//Set edge (v1, v2) to wgt
	void setEdge(int v1, int v2, int wgt) {
	//	Assert(wgt>0, "Illegal weight value");
		if (matrix[v1][v2] == 0)
			numEdge++;
		matrix[v1][v2] = wgt;
	}

	void delEdge(int v1, int v2) {
		if (matrix[v1][v2] != 0)
			numEdge--;
		matrix[v1][v2] = 0;
	}

	int weight (int v1, int v2) {
		return matrix[v1][v2];
	}
	int getMark(int v){
		return mark[v];
	}
	void setMark(int v, int val){
		mark[v] = val;
	}	

};
