/**
 * Filnamn: maze.cpp
 * @author: ommo2200
 * Kurs: C++
 * Lärare Jimmy Åhlander
 * @version: 1.0
 * skapad: 2023-10-11
 * @details: Programmet genererar, löser och visualiserar en labyrint med hjälp av DSF
*/

#include <iostream>
#include <vector>
#include "Maze.h"

//using namespace std;

int main() {
    int width, height;
    char choice = ' ';




    while (choice != '0') {

    Maze dflLavyrint(6,6);
    dflLavyrint.generateMaze();
    dflLavyrint.setStartAndEnd();
    std::cout << "\n\nDefualt labyrint 6 x 6: " << std::endl; 
    std::cout << " " << std::endl; 
    dflLavyrint.visualizeGeneratedMaze();
    std::cout << " " << std::endl; 

        do {
            std::cout << "Ange labyrinten bredd (positivt heltal större än 2): ";
            std::cin >> width;
            if (std::cin.fail() || width <= 2) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ogigltig inmatning. Ange ett positiv heltal större än 2." << std::endl;
            }
        } while (width <= 2);


        do {
            std::cout << "Ange labyrinten höjd (positivt heltal större än 2): ";
            std::cin >> height;
            if (std::cin.fail() || height <= 2) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Ogigltig inmatning. Ange ett positiv heltal större än 2. " << std::endl;
            }
        } while (height <= 2);

        std::cout << "Genererar labyrinten..." << std::endl;
        std::cout << " " << std::endl; 
        Maze maze(width, height);

        
            maze.generateMaze();
            maze.setStartAndEnd();

        std::cout << "Visualiserar genererad labyrint:" << std::endl;
        std::cout << " " << std::endl; 
        maze.visualizeGeneratedMaze();  

        std::cout << "\n\nLöser labyrint..." << std::endl;
        std::vector <std::vector<char>> Maze;
        maze.convertMaze(Maze); 
        maze.solveMaze(Maze);   
        std::cout << "\nVisualiserar löst labyrint:" << std::endl;
        std::cout << " " << std::endl; 
        maze.visualizeSolvedMaze(Maze);  

        std::cout << "\nAnge '0' för att avsluta eller någon annan siffra för att starta om: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;

}
