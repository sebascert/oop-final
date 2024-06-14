#include <iostream>
#include <fstream>

#include "classes/video_rater.hpp"
#include "ui/command_loop.hpp"

/*
Execute cmd
g++ classes/*.cpp -o main main.cpp && ./main
*/

int main(){
    std::string videosPath = "videos.txt";
    std::cout << "Se asume que el archivo de videos se llama: " + videosPath << std::endl;

    std::ifstream videosFile(videosPath);
    if (!videosFile.is_open()){
        std::cout << std::endl << "No se pudo abrir el archivo" << std::endl;
        exit(EXIT_FAILURE);
    }

    VideoRater videoRater(videosFile);
    commandLoop(videoRater);

    exit(EXIT_SUCCESS);
}
