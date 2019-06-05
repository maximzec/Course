//
// Created by User on 24.05.2019.
//

#ifndef COURSE_FILEMANAGER_H
#define COURSE_FILEMANAGER_H

#include <ios>
#include <iostream>
#include <fstream>
#include "../Models/Individual.h"

class FileManager {
private:
    std::ifstream fileIN;
    std::ofstream fileOUT;

public:
    FileManager() {
        fileIN.open(R"(C:\Users\User\CLionProjects\Course\data.txt)");
        fileOUT.open(R"(C:\Users\User\CLionProjects\Course\data.txt)", std::ios::app);
        if (!fileIN.is_open()) {
            std::cout << "Problems with file opening";
        } else {
            std::cout << "Ready to write data";
        }
        if (fileOUT.is_open()) {
            std::cout << "Ready to get data";
        }
    }

    void uploadData(Individual individual)
    {
        fileIN.open(R"(C:\Users\User\CLionProjects\Course\data.txt)", std::ios::in);
        fileIN.close();
    }

    void downloadData(Individual individual)
    {
        fileOUT.open(R"(..\data.txt)", std::ios::app);
        fileOUT << individual.getName()  << "/" << individual.getMidname() <<  individual.getSurname()  << "/"  << individual.getAge()  << "/" << individual.getSex()  << "/" << individual.getTIN()  << "/"
        << individual.getCitizenship()  << "/" << individual.getM_status()  << "/";
        fileOUT.close();
    }


};
#endif //COURSE_FILEMANAGER_H
