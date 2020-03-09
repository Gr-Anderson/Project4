// dijsktras.cpp

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Main Execution

int main(int argc, char *argv[]) 
{
	map <char, int> tilecosts;
	map <char, int>::const_iterator tileit;
	vector <vector<char>> matrix;
	unsigned int ntiles, tilenum, maprows, mapcols;
	unsigned int startrow, startcol, endrow, endcol;
	char tilename, inputtile;

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

	// Checking Input
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
	
	cout << startrow <<  " " << startcol << '\n' << endrow << " " << endcol << '\n';
	return 0;
}

