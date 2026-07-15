#include <iostream>

#include "Data.hpp"
#include "Serializer.hpp"

#define SAGE_GREEN   "\033[38;2;163;177;138m"
#define DUSTY_BLUE   "\033[38;2;109;130;153m"
#define SOFT_PURPLE  "\033[38;2;150;120;170m"
#define RESET        "\033[0m"


int main()
{
    std::cout << SOFT_PURPLE;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "        CPP06 EX01 - SERIALIZER        " << std::endl;
    std::cout << "---------------------------------------" << RESET << std::endl;


    std::cout << DUSTY_BLUE;
    std::cout << "\n[ Creating Data object ]" << RESET << std::endl;

    Data data;

    data.name = "Alice";
    data.value = 42;


    std::cout << SAGE_GREEN;
    std::cout << "Original data:" << std::endl;
    std::cout << "Name  : " << data.name << std::endl;
    std::cout << "Value : " << data.value << RESET << std::endl;


    std::cout << DUSTY_BLUE;
    std::cout << "\n[ Original pointer ]" << RESET << std::endl;

    Data* original = &data;

    std::cout << SAGE_GREEN;
    std::cout << "Original address: "
              << original << RESET << std::endl;



    std::cout << SOFT_PURPLE;
    std::cout << "\n[ Serialization ]" << RESET << std::endl;

    uintptr_t raw = Serializer::serialize(original);

    std::cout << SAGE_GREEN;
    std::cout << "Serialized integer value: "
              << raw << RESET << std::endl;



    std::cout << SOFT_PURPLE;
    std::cout << "\n[ Deserialization ]" << RESET << std::endl;

    Data* restored = Serializer::deserialize(raw);

    std::cout << SAGE_GREEN;
    std::cout << "Restored address: "
              << restored << std::endl;

    std::cout << "Restored name  : "
              << restored->name << std::endl;

    std::cout << "Restored value : "
              << restored->value << RESET << std::endl;



    std::cout << DUSTY_BLUE;
    std::cout << "\n[ Address comparison ]" << RESET << std::endl;


    if (original == restored) {
        std::cout << SOFT_PURPLE;
        std::cout << "SUCCESS: Same address restored!" 
                  << RESET << std::endl;
    }
    else {
        std::cout << "\033[38;2;220;50;50m";
        std::cout << "ERROR: Different address!"
                  << RESET << std::endl;
    }



    std::cout << SOFT_PURPLE;
    std::cout << "\n---------------------------------------" << std::endl;
    std::cout << "        TEST FINISHED SUCCESSFULLY     " << std::endl;
    std::cout << "---------------------------------------" << RESET << std::endl;


    return 0;
}