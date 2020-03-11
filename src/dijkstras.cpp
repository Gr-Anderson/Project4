// dijsktras.cpp

#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <ctype.h>
using namespace std;

struct Node
{
	Node(int ind, char t, int w);

	Node *backedge;
	bool visited;
	char tile;
	int distance;
	int index;
	int weight;
	vector <Node *> adjacent;
};

struct Matrix
{
	public:
		Matrix(unsigned int numtiles);
		~Matrix();
		void CreatePath();
		void FindEdges();
	private:
		unsigned int rows, cols;
		unsigned int start, end;
		vector <Node *> graph;
		map <char, int> tilecosts;
		map <char, int>::const_iterator tileiterator;
};

// Main Execution

int main(int argc, char *argv[]) 
{
	unsigned int numtiles;

	cin >> numtiles;

	Matrix landscape(numtiles);
	landscape.FindEdges();
	landscape.CreatePath();

	return 0;
}

void Matrix::CreatePath(){

	Node *n;
	n = graph[end];

	

	vector<int> flow;
	int a, totalWeight = 0;

	while(n->index != start){

	for(int i =0; i < 3; i++)
		cout << n->adjacent[i]->distance << ' ' << n->adjacent[i]->tile << '\n';

		cout << '\n';
		totalWeight += n->weight;
		flow.push_back(n->index);
		n = n->backedge;
	}

	cout << totalWeight << '\n';

	for(int i = flow.size(); i >= 0; i--)
		cout << flow[i]/cols << ' ' << flow[i]%cols << '\n';

}

void Matrix::FindEdges(){

	multimap<int, Node *> Nodes;
	multimap<int, Node *>::iterator nit;

	graph[0]->distance = 0;
	Node *n;
	n = graph[0];
	Nodes.insert(pair<int, Node *>(0, n));

	while(!Nodes.empty()){

//		for(nit = Nodes.begin(); nit != Nodes.end(); nit++)
//			cout << nit->first << ' ' << nit->second->index << '\n';

//		cout << '\n';

		nit = Nodes.begin();
		nit->second->visited = true;

		int dist = nit->second->distance;
		int id;

		for(int j = 0; j < nit->second->adjacent.size(); j++){

			if(nit->second->adjacent[j]->visited == false){
				if((dist + nit->second->adjacent[j]->weight) < (nit->second->adjacent[j]->distance || nit->second->adjacent[j]->distance == -1){

					id = nit->second->adjacent[j]->index;

					nit->second->adjacent[j]->distance = dist + nit->second->adjacent[j]->weight;
					dist += nit->second->adjacent[j]->weight;
					nit->second->adjacent[j]->backedge = nit->second;

					int a = nit->second->adjacent[j]->index;
					Nodes.insert(pair<int, Node *>(dist, graph[a]));

/*					nit = Nodes.begin();
					nit++;
					for(nit; nit != Nodes.end();)
						if(nit->second->index == id){
							Nodes.erase(nit);
							nit = Nodes.begin();
						}
						else
							nit++;

*/
				}
			}

		}

		nit = Nodes.begin();
		Nodes.erase(nit);
	}

	return;
}

Node::Node(int ind, char t, int w)
{
	backedge = NULL;
	visited = 0;
	tile = t;
	distance = -1;
	index = ind;
	adjacent.resize(0);
	weight = w;
}

Matrix::Matrix(unsigned int numtiles)
{
	char tilename, inputtile;
	unsigned int startrow, startcol, endrow, endcol;
	int tilecost;
	int weight;

	// Reading in tile costs
	for (unsigned int i = 0; i < numtiles; i++)
	{
		cin >> tilename >> tilecost;
		tilecosts[tilename] = tilecost;
	}

	cin >> rows >> cols;

	// Creating the graph of nodes
	for (unsigned int i = 0; i < (rows * cols); i++)
	{
		Node *inputnode;

		cin >> inputtile;
		tileiterator = tilecosts.find(inputtile);
		weight = tileiterator->second;
		inputnode = new Node(i, inputtile, weight);
		graph.push_back(inputnode);

	}

	// Setting the adjacent vectors of each node
	for (int i = 0; i < (int) graph.size(); i++)
	{
		// Adding above node to adj
		if ((i - cols) >= 0 && (i-cols) < (rows * cols))
			graph[i]->adjacent.push_back(graph[i-cols]);

		// Adding left node to adj
		if (((i%cols)-1 >= 0) && (i%cols)-1 < (rows*cols))
			graph[i]->adjacent.push_back(graph[i-1]);

		// Adding right node to adj
		if (((i%cols)+1 < cols) && (i%cols)+1 < (rows*cols))
			graph[i]->adjacent.push_back(graph[i+1]);

		// Adding below node to adj
		if ((i + cols) < (rows * cols))
			graph[i]->adjacent.push_back(graph[i+cols]);
	}

	cin >> startrow >> startcol >> endrow >> endcol;
	end = (endrow*rows)+endcol;
	start = (startcol*rows)+startcol;

	/* -- Testing input -- */
	/*	cout << numtiles << '\n';

		for (tileiterator = tilecosts.begin(); tileiterator != tilecosts.end(); tileiterator++)
		cout << tileiterator->first << " " << tileiterator->second << '\n';

		cout << rows << " " << cols << '\n';

		for (unsigned int i = 0; i < graph.size(); i++)
		{
		if ((i % cols == 0) && i != 0)
		cout << '\n';
		cout << graph[i]->tile << " ";
		}
		cout << '\n';
		cout << startrow << " " << startcol << '\n';
		cout << endrow << " " << endcol << '\n';

		-- Checking the adjacent matrix -- 
		for (unsigned int i = 0; i < graph.size(); i++)
		{
		cout << "graph[" << i << "] : ";
		for (unsigned int j = 0; j < graph[i]->adjacent.size(); j++)
		cout << graph[i]->adjacent[j]->tile << " ";

		cout << '\n';
		}
		*/
}

Matrix::~Matrix()
{
	for (unsigned int i = 0; i < graph.size(); i++)
		delete graph[i];
}
