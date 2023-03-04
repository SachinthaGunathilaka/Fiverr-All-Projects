#include "MazeSolver.hpp"
#include <iostream>

using namespace std;

#include "Maze.hpp"
#include "MazeSolution.hpp"

class MyMazeSolver : public MazeSolver{

public:
    MyMazeSolver();
    void solveMaze(const Maze& maze, MazeSolution& mazeSolution) override;
    vector<int> getNextPositions(const Maze & maze, int x, int y);
    bool recurSolveMaze(const Maze& maze, MazeSolution& mazeSolution, int x, int y);
   
private:
    int * visited;


};