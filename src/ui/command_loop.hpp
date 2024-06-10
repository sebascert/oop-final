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

const std::string options =
"1 Mostrar todo el catalogo con calificaciones.\n\
2 Calificar un video.\n\
3 Mostrar peliculas o capitulos con una calificacion minima determinada.\n\
4 Mostrar peliculas o capitulos de un cierto genero.\n\
9 Salir.";

void commandLoop(VideoRater& videoRater){
    bool loop = true;
    while(loop){
        try{
            std::cout << std::endl;
            int cmdBuff = getInput<int>(options, '\n');
            COMMAND option = static_cast<COMMAND>(cmdBuff);

            switch (option)
            {
            case COMMAND::CATALOG:{
                for (Video* vid : videoRater.getCatalog())
                    std::cout << *vid << std::endl;
            }
                break;
            case COMMAND::RATE_MOVIE:{
                
            }
                break;
            case COMMAND::FILTER_MIN_RATING:{
                
            }
                break;
            case COMMAND::FILTER_GENRE:{
                // for (Video* vid : videoRater.getByGenre())
                //     std::cout << vid->genreFormat() << std::endl;
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
