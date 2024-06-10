#pragma once

#include <string>
#include <iostream>

#include "../classes/video_rater.hpp"
#include "get_input.hpp"

enum class COMMAND{
    CATALOG=1,
    RATE_MOVIE,
    FILTER_MIN_RATING,
    FILTER_GENRE,
    EXIT=9,
};

const std::string commands =
"1 Mostrar todo el catalogo con calificaciones.\n\
2 Calificar un video.\n\
3 Mostrar peliculas o capitulos con una calificacion minima determinada.\n\
4 Mostrar peliculas o capitulos de un cierto genero.\n\
9 Salir.";

void commandLoop(VideoRater& videoRater){
    bool loop = true;
    while(loop){
        try{
            std::cout << std::endl << commands << std::endl << "Ingresar opcion: ";
            int cmdBuff = getInput<int>('\n');
            COMMAND option = static_cast<COMMAND>(cmdBuff);
            std::cout << std::endl;

            switch (option)
            {
            case COMMAND::CATALOG:{
                for (Video* vid : videoRater.getCatalog())
                    std::cout << *vid << std::endl;
            }
                break;
            case COMMAND::RATE_MOVIE:{
                std::cout << "Ingresar id: ";
                Id id = getInput<Id>('\n');
                std::cout << "Ingresar calificacion: ";
                int rating = getInput<int>('\n');
                videoRater[id].getRating().rate(rating);
            }
                break;
            case COMMAND::FILTER_MIN_RATING:{
                std::cout << "Ingresar calificacion minima: ";
                float rating = getInput<float>('\n');
                std::cout << "Ingresar tipo de video a filtrar:"
                          << "\nPelicula (1)\nEpisodio (2)\nAmbos (3)\n";
                float videoTypes = getInput<int>('\n');
                for (Video* vid : videoRater.getByRate(rating, videoTypes))
                    std::cout << vid->ratingFormat() << std::endl;
            }
                break;
            case COMMAND::FILTER_GENRE:{
                std::cout << "Ingresar genero: ";
                Genre genre = getInput<Genre>('\n');
                std::cout << "Ingresar tipo de video a filtrar:"
                          << "\nPelicula (1)\nEpisodio (2)\nAmbos (3)\n";
                float videoTypes = getInput<int>('\n');
                for (Video* vid : videoRater.getByGenre(genre, videoTypes))
                    std::cout << vid->ratingFormat() << std::endl;
            }
                break;
            case COMMAND::EXIT:
                loop = false;
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
                break;
            }
        }catch (const std::invalid_argument& e) {
            std::cout << e.what() << std::endl;
        }
    }
}
