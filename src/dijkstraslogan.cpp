// dijsktras.cpp

#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <ctype.h>
using namespace std;

struct Node
{
	Node(int ind, char t);

	Node *backedge;
	bool visited;
	char tile;
	int distance;
	int index;
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
};

// Main Execution

int main(int argc, char *argv[]) 
{
	unsigned int numtiles;

	cin >> numtiles;

	Matrix landscape(numtiles);
//	landscape.FindEdges();
//	landscape.CreatePath();

	return 0;
}

Node::Node(int ind, char t)
{
	backedge = NULL;
	visited = 0;
	tile = t;
	distance = -1;
	index = ind;
	adjacent.resize(0);
}

Matrix::Matrix(unsigned int numtiles)
{
	char tilename, inputtile;
	map <char, int>::const_iterator tileiterator;
	unsigned int startrow, startcol, endrow, endcol;
	int tilecost;

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
		inputnode = new Node(i, inputtile);
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

	/* -- Testing input -- */
	cout << numtiles << '\n';

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
	
	/* -- Checking the adjacent matrix -- */
	for (unsigned int i = 0; i < graph.size(); i++)
	{
		cout << "graph[" << i << "] : ";
		for (unsigned int j = 0; j < graph[i]->adjacent.size(); j++)
			cout << graph[i]->adjacent[j]->tile << " ";

		cout << '\n';
	}

}

Matrix::~Matrix()
{
	for (unsigned int i = 0; i < graph.size(); i++)
		delete graph[i];
}
