#include <ics46/factory/DynamicFactory.hpp>
#include "MyMazeGenerator.hpp"


ICS46_DYNAMIC_FACTORY_REGISTER(MazeGenerator, MyMazeGenerator, "MyMazeGenerator");

MyMazeGenerator::MyMazeGenerator(){

}

void MyMazeGenerator::generateMaze(Maze & maze){
    maze.addAllWalls();
    visited = new int[maze.getHeight() * maze.getWidth()];
    for (int i = 0; i < (maze.getHeight() * maze.getWidth()); i++){
        visited[i] = 0;
    }    
    recurGenerateMaze(maze, 0, 0);
    
 
}

void MyMazeGenerator::recurGenerateMaze(Maze & maze, int x, int y){

    visited[y * maze.getWidth() + x] = 1;
    vector<int> next = getNextPositions(maze, x, y);

    while (1){
        if(next.size() == 0)
            return;

        int choice =  rand() % next.size();

        if(next[choice] == 1){
            if(visited[y*maze.getWidth() + x-1] == 0){
                maze.removeWall(x, y, Direction::left);
                recurGenerateMaze(maze, x-1, y);
            }
           
        }

        if(next[choice] == 2){
            if(visited[y*maze.getWidth() + x+1] == 0){
                maze.removeWall(x, y, Direction::right);
                recurGenerateMaze(maze, x+1, y);
            }

        }

        if(next[choice] == 3){

            if(visited[(y-1)*maze.getWidth() + x] == 0){
                maze.removeWall(x, y, Direction::up);
                recurGenerateMaze(maze, x, y-1);
            }


        }

        if(next[choice] == 4){
            if(visited[(y+1)*maze.getWidth() + x] == 0){
                 maze.removeWall(x, y, Direction::down);
                recurGenerateMaze(maze, x, y+1);
            }

           

        }
        next.erase(next.begin() + choice);
    }

    


}

vector<int>  MyMazeGenerator::getNextPositions(Maze & maze, int x, int y){
    vector<int> next;
     if(x > 0){
        next.push_back(1);
    }


    if(x < maze.getWidth()-1){
        next.push_back(2);
    }

    if(y > 0){
        next.push_back(3);
    }

    if(y < maze.getHeight()-1){
        next.push_back(4);
    }

    return next;
}
