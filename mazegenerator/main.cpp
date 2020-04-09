//
//  main.cpp
//  mazegenerator
//
//  Created by Josiah Ebhomenye on 22/12/2016.
//  Copyright © 2016 Josiah Ebhomenye. All rights reserved.
//

#include <iostream>

#include "generator.h"

using namespace std;

int main(int argc, const char * argv[]) {
    Maze<5, 5> maze;
    maze.generate();
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            Cell& cell = maze[i][j];
            vector<Cell*> neighbours = cell.getNeighbours();
            cout << "cell[" << i << ", " << j << "]: " << endl;
            for(Cell* neighbour : neighbours){
                auto loc = maze.location(neighbour);
                int iLoc = get<0>(loc);
                int jLoc = get<1>(loc);
                cout << "\t\tneighbour[" << iLoc << ", " << jLoc << "]: ";
                if(cell.hasWallBetween(neighbour)){
                    cout << " wall";
                }else{
                    cout << " no wall";
                }
                cout << endl;
            }
            cout << endl;
            
        }
    }
    return 0;
}
