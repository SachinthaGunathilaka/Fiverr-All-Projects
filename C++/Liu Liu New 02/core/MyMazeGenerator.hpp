#include "MazeGenerator.hpp"
#include <iostream>

using namespace std;

#include "Maze.hpp"

class MyMazeGenerator : public MazeGenerator{

public:
    MyMazeGenerator();
    void generateMaze(Maze & maze) override;
    void recurGenerateMaze(Maze & maze, int x, int y);
    vector<int>   getNextPositions(Maze & maze, int x, int y);

private:
    int * visited;

};