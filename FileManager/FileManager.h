//
// Created by User on 24.05.2019.
//

#ifndef COURSE_FILEMANAGER_H
#define COURSE_FILEMANAGER_H

#include <ios>
#include <iostream>
#include <fstream>
#include "../Models/Individual.h"

void writeData(std::vector<Individual> i1, std::vector<Organization> o1)
{
    std::ofstream f("../UserData/Individual.txt");
    for(std::vector<Individual>::const_iterator i = i1.begin(); i != i1.end(); ++i) {
        f<<i->getName()<<'\n' << i->getSurname() <<'\n' <<  i ->getMidname() <<'\n' << i->getTIN() << '\n' << i->getCitizenship() << '\n' << i->getM_status()<<'\n' << i->getSex() <<'\n' <<i->getAge() <<'\n' << i->getUniq_key()
          <<'\n' ;
    }
    f.close();

    std::ofstream f1("../UserData/Organization.txt");
    for(std::vector<Organization>::const_iterator i = o1.begin(); i != o1.end(); ++i) {
        f <<'\n'<<i->getID() <<'\n' << i->getName()<< '\n'<< i->getAdrress() << '\n' << i->getPhone_number() << '\n' << i->getHolder() <<'\n' << i->getTIN() <<'\n';
    }
    f1.close();
}


void readData(std::vector<Individual> *i1 , std::vector<Organization> *o1)
{
    std::string stroke , name , surname , midname , TIN , citizenship , m_status;
    int age ;
    char sex;
    unsigned int uniq_key;
    std::ifstream f("../UserData/Individual.txt");
    if (!(f.is_open())) {
        std::cout << "File openning error!" << std::endl;
    }

    while(!f.eof())
    {
        std::getline(f , name);
        std::getline(f , surname);
        std::getline(f , midname);
        std::getline(f , TIN);
        std::getline(f , citizenship);
        std::getline(f , m_status);
        f >> sex;
        f >> age ;
        f >> uniq_key ;

       i1->push_back(*(new Individual(name  , surname , midname , TIN , citizenship , m_status , age , sex , uniq_key)));


    }
    f.close();
    std::string name1 , address, phone_number, TIN1 , holder , id;
    int ID;
    std::ifstream f1("../UserData/Organization.txt");

    while(!(f1.eof()))
    {
        f1 >> ID ;
        std::getline(f1 , name1  );
        std::getline(f1, address );
        std::getline(f1 , phone_number );
        std::getline(f1, holder );
        std::getline(f1, TIN1 );
        o1->push_back(*(new Organization(ID , name1 , address , phone_number , holder , TIN1 )));
    }
    f1.close();
}
#endif //COURSE_FILEMANAGER_H
