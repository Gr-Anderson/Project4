Project 04: Path Finding
========================

N | Elapsed Time (total) | Memory Usage (Megabytes)
--- | :---: | :---:
10 | .0042s | 0.01 
20 | .0048s | 0.038
50 | .007s | 0.236
100 | .018s | 0.933
200 | .054s | 3.729
500 | .3274s | 21.982
1000 | 1.3088s | 87.928

##### How did you represent the map as a graph?

##### Explain which graph representation you used and how you determined the relationship between vertices include the edges and their weights.

##### What is complexity of your implementation of Dijkstra's Algorithm?

##### Explain this by describing which data structures you used and how you used them to implement path finding.

##### How well does your implementation scale?

##### Explain what effect did N (ie. the size of the map) have on the performance of your dijkstras path finding component in terms of execution time and memory usage?

This project implements a [Dijkstra's Algorithm] to perform rudimentary path
finding on a 2D tile-based map.

[Dijkstra's Algorithm]: https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm


Input
-----

    TILES_N
    TILE_NAME_0	TILE_COST_0
    ...
    TILE_NAME_N-1	TILE_COST_N-1

    MAP_ROWS MAP_COLUMNS
    TILE_0_0    ...
    ...

    TRAVELER_START_ROW TRAVELER_START_COL
    TRAVELER_END_ROW   TRAVELER_END_COL

Output
------

    Cost
    [(ROW_0, COL_0), ...]

