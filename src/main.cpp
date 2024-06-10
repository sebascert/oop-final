#include <iostream>
#include <fstream>

#include "classes/video_rater.hpp"
#include "ui/command_loop.hpp"

/*
Execute cmd
g++ classes/*.cpp -o main main.cpp && ./main
*/

int main(){
    std::cout << "Ingresar la direccion del archivo con las peliculas: ";
    std::string videosPath = getInput<std::string>(std::cin, "Error en string", '\n');

    std::ifstream videosFile(videosPath);
    if (!videosFile.is_open()){
        std::cout << std::endl << "No se pudo abrir el archivo" << std::endl;
        exit(EXIT_FAILURE);
    }

    VideoRater videoRater(videosFile);
    commandLoop(videoRater);

    exit(EXIT_SUCCESS);
}
