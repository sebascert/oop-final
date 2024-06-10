#include <iostream>
#include <sstream>
#include <unordered_map>
#include <typeindex>
#include <type_traits>

#include "classes/id.hpp"
#include "classes/genre.hpp"
#include "classes/rating.hpp"
#include "classes/movie.hpp"

/*
Execute cmd
g++ classes/*.cpp -o main main.cpp && ./main
*/

std::unordered_map<std::type_index, std::string> typeNames = {
    {typeid(int), "Entero"},
    {typeid(float), "Flotante"},
    {typeid(double), "Flotante Doble"},
    {typeid(Id), "Video id"},
};
template<typename T>
T getInput(char delim);

int main(){
    return 0;
}

template<typename T>
T getInput(char delim){
    std::string buff;
    std::getline(std::cin, buff, delim);
    if constexpr (std::is_default_constructible<T>::value){
        std::istringstream buffss(buff);
        T value;
        if (!(buffss >> value) || buffss.peek() != EOF)
            throw std::invalid_argument(typeNames[typeid(T)] + " Invalido");
        return value;
    }else
        return T(buff);
}

// void commandLoop(Hotel* hotel);


// enum OPTION{
//     CATALOG=1,
//     RATE_MOVIE,
//     CARGOS,
//     TARIFAS,
//     REPORTE_OCUPACION,
//     EXIT,
// };

// const std::string options =
// "1) Hacer check-in\n\
// 2) Hacer check-out\n\
// 3) Realizar cargos a habitacion.\n\
// 4) Ingresos por tarifas\n\
// 5) Generar reporte de habitacion.\n\
// 6) Salir.";

// /*
// Execute cmd
// g++ -o main *.cpp && ./main
// */
// int main() {
//     Hotel* hotel = getHotel();

//     commandLoop(hotel);
//     std::cout << *hotel << std::endl;
//     delete hotel;
// }

// Hotel* getHotel(){
//     while (true){
//         try {
//             std::cout << "Nombre del hotel: ";
//             std::string hotelName;
//             std::getline(std::cin, hotelName);
//             std::cout << "Numero de Habitaciones Junior: ";
//             int juniorCount = getInput<int>();
//             std::cout << "Numero de Habitaciones Suite: ";
//             int suiteCount = getInput<int>();
//             std::cout << "Numero de Habitaciones Deluxe: ";
//             int deluxeCount = getInput<int>();

//             return new Hotel(hotelName, juniorCount, suiteCount, deluxeCount);
//         }
//         catch (const std::invalid_argument& e) {
//             std::cout << e.what() << std::endl;
//         }
//     }
// }

// void commandLoop(Hotel* hotel){
//     bool loop = true;
//     while(loop){
//         try{
//             std::cout << std::endl << options << std::endl;
//             int optBuff = getInput<int>();
//             OPTION option = static_cast<OPTION>(optBuff);

//             switch (option)
//             {
//             case OPTION::CHECKIN:{
//                 std::cout << "Nombre: ";
//                 std::string nombre;
//                 std::getline(std::cin, nombre);
//                 std::cout << "Numero de adultos: ";
//                 int adultos = getInput<int>();
//                 std::cout << "Numero de infantes: ";
//                 int infantes = getInput<int>();
//                 std::cout << "Cantidad de credito: ";
//                 double credito = getInput<double>();
//                 std::cout << "junior (1)\nsuite (2)\ndeluxe (3)\nTipo de Habitacion: ";
//                 int tipoHab = getInput<int>();
//                 std::cout << std::endl;

//                 MsgWrapper<int> result = hotel->checkin(nombre, adultos, infantes, credito, tipoHab);
//                 std::cout << result.message << std::endl;
//                 break;
//             }
//             case OPTION ::CHEKOUT:{
//                 std::cout << "Numero Habitacion: ";
//                 int numeroHab = getInput<int>();
//                 if (!hotel->checkout(numeroHab))
//                     std::cout << "No se pudo realizar chekout" << std::endl;
//                 else
//                     std::cout << "Chekout exitoso" << std::endl;
//                 break;
//             }
//             case OPTION::CARGOS:{
//                 std::cout << "Numero Habitacion: ";
//                 int numeroHab = getInput<int>();
//                 std::cout << "Cargos: ";
//                 double cargos = getInput<double>();
//                 MsgWrapper<bool> result = hotel->realizarCargosHabitacion(numeroHab, cargos);
//                 std::cout << result.message << std::endl;
//                 break;
//             }
//             case OPTION::TARIFAS:
//                 std::cout << "Total de Tarifas Base: " << hotel->getTotalXTarifaBase() << std::endl;
//                 break;
//             case OPTION::REPORTE_OCUPACION:
//                 hotel->imprimeOcupacion();
//                 break;
//             case OPTION::SALIR:
//                 loop = false;
//                 break;
//             default:
//                 std::cout << "Opcion invalida" << std::endl;
//                 break;
//             }
//         }catch (const std::invalid_argument& e) {
//             std::cout << e.what() << std::endl;
//         }
//     }
// }

