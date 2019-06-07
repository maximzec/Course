#include <iostream>
#include "UserInterface/Menu.h"
#include "Models/Individual.h"
#include "FileManager/FileManager.h"
#include <vector>
#include <iterator>

int main() {
    Menu menu = Menu();
    for(;;)
    {
        menu.printMenu();
    }



    return 0;
}