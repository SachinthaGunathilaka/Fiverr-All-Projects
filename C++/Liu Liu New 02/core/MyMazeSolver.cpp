#include <ics46/factory/DynamicFactory.hpp>
#include "MyMazeSolver.hpp"


ICS46_DYNAMIC_FACTORY_REGISTER(MazeSolver, MyMazeSolver, "MyMazeSolver");

MyMazeSolver::MyMazeSolver(){

}

void MyMazeSolver::solveMaze(const Maze& maze, MazeSolution& mazeSolution){
    int x = mazeSolution.getStartingCell().first;
    int y = mazeSolution.getStartingCell().second;

    visited = new int[maze.getHeight() * maze.getWidth()];
    for (int i = 0; i < (maze.getHeight() * maze.getWidth()); i++){
        visited[i] = 0;
    }    

    recurSolveMaze(maze, mazeSolution, x, y);
    
}



vector<int>  MyMazeSolver::getNextPositions(const Maze & maze, int x, int y){
    vector<int> next;
    if((x > 0) && (!maze.wallExists(x, y, Direction::left))){
        next.push_back(1);
    }

    if((x < maze.getWidth()-1) && (!maze.wallExists(x, y, Direction::right))){
        next.push_back(2);
    }

    if((y > 0) && (!maze.wallExists(x, y, Direction::up))){
        next.push_back(3);
    }

    if((y < maze.getHeight()-1) && (!maze.wallExists(x, y, Direction::down))){
        next.push_back(4);
    }

    return next;
}



bool MyMazeSolver::recurSolveMaze(const Maze& maze, MazeSolution& mazeSolution, int x, int y){
    visited[y*maze.getWidth() + x] = 1;
    vector<int> next = getNextPositions(maze, x, y);
    
    while (1){
        if(mazeSolution.isComplete())
            return true;

        if(next.size() == 0){
            return false;
        }
            

        if(next[0] == 1){
            if(visited[y*maze.getWidth() + x-1] == 0){
                mazeSolution.extend(Direction::left);
                bool isValid = recurSolveMaze(maze, mazeSolution, x-1, y);

                if (!isValid){
                    mazeSolution.backUp();
                }
                    
            }
           
        }

        if(next[0] == 2){
            if(visited[y*maze.getWidth() + x+1] == 0){

                mazeSolution.extend(Direction::right);
                bool isValid = recurSolveMaze(maze, mazeSolution, x+1, y);
                if (!isValid){
                    mazeSolution.backUp();

                }
            }

        }

        if(next[0] == 3){

            if(visited[(y-1)*maze.getWidth() + x] == 0){

                mazeSolution.extend(Direction::up);
                bool isValid = recurSolveMaze(maze, mazeSolution, x, y-1);
                if (!isValid){
                    mazeSolution.backUp();

                }
            }

            

        }

        if(next[0] == 4){
            if(visited[(y+1)*maze.getWidth() + x] == 0){
                mazeSolution.extend(Direction::down);
                bool isValid = recurSolveMaze(maze, mazeSolution, x, y+1);
                if (!isValid){
                    mazeSolution.backUp();

                }
            }

        }
        next.erase(next.begin());
    }


}
