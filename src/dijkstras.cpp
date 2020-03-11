// dijsktras.cpp

#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <ctype.h>
using namespace std;

// Main Execution

int main(int argc, char *argv[]) 
{
	map <char, int> tilecosts;
	map <char, int>::const_iterator tileit;
	vector <vector<char> > matrix;
	unsigned int ntiles, tilenum, maprows, mapcols;
	unsigned int startrow, startcol, endrow, endcol;
	char tilename, inputtile;
	multimap<int, int> Nodes;
	multimap<int, int>::iterator Nodesit;
	vector<int> edges;

	cin >> ntiles;

	for (unsigned int i = 0; i < ntiles; i++)
	{
		cin >> tilename >> tilenum;
		tilecosts[tilename] = tilenum;
	}

	cin >> maprows >> mapcols;

	matrix.resize(maprows);

	for (unsigned int i = 0; i < maprows; i++)
	{
		for (unsigned int j = 0; j < mapcols; j++)
		{
			cin >> inputtile;
			matrix[i].push_back(inputtile);
		}
	}

	cin >> startrow >> startcol >> endrow >> endcol;

/*	// Checking Input
	cout << ntiles << '\n';

	for (tileit = tilecosts.begin(); tileit != tilecosts.end(); tileit++)
	{
		cout << tileit->first << " " << tileit->second << '\n';
	}

	cout << maprows << " " << mapcols << '\n';
	for (unsigned int i = 0; i < maprows; i++)
	{
		for (unsigned int j = 0; j < mapcols; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << '\n';
	}
	
	cout << startrow <<  " " << startcol << '\n' << endrow << " " << endcol << '\n';*/

	Nodes.insert(pair<int, int>(0, 0));

	for(int i = startrow; i < maprows; i++){
		for(int j = startcol; j < mapcols; j++){

			if(i+1 < mapcols){
				tileit = tilecosts.find(matrix[i+1][j]);
				if(tileit->second > 0)
					Nodes.insert(pair<int, int>(tileit->second, (i*mapcols)+j));
			}

			if(j+1 < maprows){
				tileit = tilecosts.find(matrix[i][j+1]);
				if(tileit->second > 0)
					Nodes.insert(pair<int, int>(tileit->second, (i*mapcols)+j));
						}
					}
/*			if(i-1 >= 0){
				tileit = tilecosts.find(matrix[i-1][j]);
				if(tileit->second > 0)
					Nodes.insert(pair<int, int>(tileit->second, (i*mapcols)+j));
			}

			if(j-1 >= 0){
				tileit = tilecosts.find(matrix[i][j-1]);
				if(tileit->second > 0)
					Nodes.insert(pair<int, int>(tileit->second, (i*mapcols)+j));
						}*/
		}

	i = (mapcols*endrow)+endcol;
	edges.push_back(i);
	int total = 0;
			
	while(i != 0){
		
		for(Nodesit = Nodes.begin(); Nodesit != Nodes.end(); Nodesit++){
			if(Nodesit->second == i-10){
				edges.push_back(Nodesit->second);
				i = Nodesit->second;
				total += Nodesit->first;
				Nodes.erase(Nodesit);
				Nodesit = Nodes.begin();
				if(i == 0)
					break;
			}
			if(Nodesit->second == i-1){
				edges.push_back(Nodesit->second);
				i = Nodesit->second;
				total += Nodesit->first;
				Nodes.erase(Nodesit);
				Nodesit = Nodes.begin();
				if(i == 0)
					break;
			}
		/*	if(Nodesit->second == i+1){
				edges.push_back(Nodesit->second);
				i = Nodesit->second;
				Nodes.erase(Nodesit);
				Nodesit = Nodes.begin();
				if(i == 0)
					break;
			}
			if(Nodesit->second == i+10){
				edges.push_back(Nodesit->second);
				i = Nodesit->second;
				Nodes.erase(Nodesit);
				Nodesit = Nodes.begin();
				if(i == 0)
					break;
			}*/
		}
				
	}

	cout << total << '\n';

	for(int i = edges.size()-1; i >= 0; i--)
		cout << edges[i]/mapcols << ' ' << edges[i]%mapcols << '\n';


	return 0;
}

