//
// Created by User on 30.05.2019.
//

#ifndef COURSE_MENU_H
#define COURSE_MENU_H

#include <vector>
#include "../Models/Individual.h"
#include "../Models/Organization.h"
#include "../FileManager/FileManager.h"
#include <iostream>
#include <iterator>
#include <algorithm>
class Menu {
private:
    int state;
    std::vector<Individual> IndividualData;
    std::vector<Organization> OrganizationData;
public:
    Menu()
    {
        readData(&IndividualData , &OrganizationData);
        this->state = 0;
    }


    void printMenu() {

         {
            switch (this->state) {
                case 0: {
                    int choice;
                    std::cout << "----MAIN MENU-----" << std::endl;
                    std::cout << "1.Add information" << std::endl;
                    std::cout << "2.Delete information" << std::endl;
                    std::cout << "3.Show all" << std::endl;
                    std::cout << "4.Search by values" << std::endl;
                    std::cout << "5.Sort data" << std::endl;
                    std::cout << "6.EXIT" << std::endl;
                    std::cout << "Enter you choice:";
                    std::cin >> choice;
                    this->setState(choice);
                    break;
                }
                case 1: {
                    int choice;
                    std::cout << "----ADD INFO MENU-----" << std::endl;
                    std::cout << "1.Add the Individual" << std::endl;
                    std::cout <<"2.Add the organization" << std::endl;
                    std::cout <<"3.Back to Main Menu" << std::endl;
                    std::cout << "4.EXIT" << std::endl;
                    std::cout <<"Enter your choice :" ;
                    std::cin >> choice;
                    switch (choice)
                    {
                        case 1: {
                            system("cls");
                            Individual i;
                            std::cin >> i;
                            IndividualData.push_back(i);
                            this->setState(0);
                            break;
                        }
                        case 2:
                        {
                            system("cls");
                          Organization o ;
                          std::cin >> o;
                          OrganizationData.push_back(o);
                          this->setState(0);
                          break;
                        }
                        case 3: this -> setState(0);break;
                        case 4: this->setState(6);break;
                    }
                    break;
                }
                case 2:
                    int choice;
                    std::cout << "----DELETING INFO MENU-----" << std::endl;
                    std::cout << "1.Delete the Individual" << std::endl;
                    std::cout <<"2.Delete the organization" << std::endl;
                    std::cout <<"3.Back to Main Menu" << std::endl;
                    std::cout << "4.EXIT" << std::endl;
                    std::cout <<"Enter your choice :" ;
                    std::cin >> choice;
                    switch (choice) {
                        case 1:
                        {
                            int ID;
                            std::cout << "Enter the ID of Individual you want to delete:";
                            std::cin >> ID;
                            for (auto it = getIndividualData().begin(); it != getIndividualData().end(); it++) {
                                if (it->getUniq_key() == ID) IndividualData.erase(it);
                            }
                            this->setState(0);
                            break;
                        }
                        case 2: {
                            int ID;
                            std::cout << "Enter the ID of Organization you want to delete:";
                            std::cin >> ID;
                            for (auto it = getOrganizationData().begin(); it != getOrganizationData().end(); it++) {
                                if (it->getID() == ID) OrganizationData.erase(it);
                            }
                            this->setState(0);
                            break;
                        }
                        case 3:this->setState(0);break;
                        case 4:this->setState(5);break;
                    }
                    break;
                case 3: {
                    int choice;
                    std::cout << "----SHOWING INFO MENU-----" << std::endl;
                    std::cout << "1.Show the Individual List" << std::endl;
                    std::cout <<"2.Show the organization List" << std::endl;
                    std::cout <<"3.Back to Main Menu" << std::endl;
                    std::cout << "4.EXIT" << std::endl;
                    std::cout <<"Enter your choice :" ;
                    std::cin >> choice;
                    switch(choice)
                    {
                        case 1: {
                            system("cls");
                            std::copy(IndividualData.begin(), IndividualData.end(),
                                      std::ostream_iterator<Individual>(std::cout, "\n"));
                            system("pause");
                            this->setState(0);
                            break;
                        }
                        case 2:
                        {
                            system("cls");
                            std::copy(OrganizationData.begin(), OrganizationData.end() , std::ostream_iterator<Organization>(std::cout , "\n"));
                            system("pause");
                            this->setState(0);
                            break;
                        }
                        case 3: this->setState(0);break;
                        case 4: this->setState(5);break;
                    }
                    break;

                }
                case 4: {
                    int choice;
                    std::cout << "----SEARCH INFO MENU-----" << std::endl;
                    std::cout << "1.Search the Individuals" << std::endl;
                    std::cout <<"2.Search the Organizations" << std::endl;
                    std::cout <<"3.Back to Main Menu" << std::endl;
                    std::cout << "4.EXIT" << std::endl;
                    std::cout <<"Enter your choice :" ;
                    std::cin >> choice;
                    switch (choice)
                    {
                        case 1:
                        {
                            system("cls");
                            int choice1;
                            std::cout << "----SEARCH INDIVIDUAL MENU-----" << std::endl;
                            std::cout << "1.Search by ID" << std::endl;
                            std::cout <<"2.Search by Name" << std::endl;
                            std::cout <<"3.Search by Surname" << std::endl;
                            std::cout <<"4.Search by Midname" << std::endl;
                            std::cout <<"5.Search by TIN" << std::endl;
                            std::cout <<"6.Search by Citizenship" << std::endl;
                            std::cout <<"7.Search by M_status" << std::endl;
                            std::cout <<"8.Search by Sex" << std::endl;
                            std::cout <<"9.Search by Age" << std::endl;
                            std::cout << "10.Back to Main Menu" << std::endl;
                            std::cout <<"Enter your choice :" ;
                            std::cin >> choice1;
                            switch (choice1)
                            {
                                case 1:
                                {
                                    system("cls");
                                    int ID;
                                    std::cout << "Enter the ID:";
                                    std::cin >> ID;
                                    for (auto it = getIndividualData().begin(); it != getIndividualData().end(); it++) {
                                        if (it->getUniq_key() == ID) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 2:
                                {
                                    system("cls");
                                    std::string name;
                                    std::cout << "Enter the Name:";
                                    std::cin >> name;
                                    for (auto it = getIndividualData().begin(); it != getIndividualData().end(); it++) {
                                        if (it->getName() == name) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 3:
                                {
                                    system("cls");
                                    std::string surname;
                                    std::cout << "Enter the Surname:";
                                    std::cin >> surname;
                                    for (auto it = getIndividualData().begin(); it != getIndividualData().end(); it++) {
                                        if (it->getSurname() == surname) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 4:
                                {
                                    system("cls");
                                    std::string midname;
                                    std::cout << "Enter the Midname:";
                                    std::cin >> midname;
                                    for (auto it = getIndividualData().begin(); it != getIndividualData().end(); it++) {
                                        if (it->getMidname() == midname) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 5:
                                {
                                    system("cls");
                                    std::string TIN;
                                    std::cout << "Enter the TIN:";
                                    std::cin >> TIN;
                                    for (auto it = getIndividualData().begin(); it != getIndividualData().end(); it++) {
                                        if (it->getTIN() == TIN) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 6:
                                {
                                    system("cls");
                                    std::string citizenship;
                                    std::cout << "Enter the citizenship:";
                                    std::cin >> citizenship;
                                    for (auto it = getIndividualData().begin(); it != getIndividualData().end(); it++) {
                                        if (it->getCitizenship() == citizenship) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 7:
                                {
                                    system("cls");
                                    std::string m_status;
                                    std::cout << "Enter the M_status:";
                                    std::cin >> m_status;
                                    for (auto it = getIndividualData().begin(); it != getIndividualData().end(); it++) {
                                        if (it->getM_status() == m_status) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 8:
                                {
                                    system("cls");
                                    char sex;
                                    std::cout << "Enter the Sex:";
                                    std::cin >> sex;
                                    for (auto it = getIndividualData().begin(); it != getIndividualData().end(); it++) {
                                        if (it->getSex() == sex) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 9:
                                {
                                    system("cls");
                                    int age;
                                    std::cout << "Enter the ID:";
                                    std::cin >> age;
                                    for (auto it = getIndividualData().begin(); it != getIndividualData().end(); it++) {
                                        if (it->getAge() == age) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 10 : this->setState(0);break;
                            }
                            break;
                        }
                        case 2:
                        {
                            system("cls");
                            int choice1;
                            std::cout << "----SEARCH INDIVIDUAL MENU-----" << std::endl;
                            std::cout << "1.Search by ID" << std::endl;
                            std::cout <<"2.Search by Name" << std::endl;
                            std::cout <<"3.Search by Phone Number" << std::endl;
                            std::cout <<"4.Search by Address" << std::endl;
                            std::cout <<"5.Search by Holder" << std::endl;
                            std::cout <<"6.Search by TIN" << std::endl;
                            std::cout << "7.Back to Main Menu" << std::endl;
                            std::cout <<"Enter your choice :" ;
                            std::cin >> choice1;
                            switch(choice1)
                            {
                                case 1:
                                {
                                    system("cls");
                                    int ID;
                                    std::cout << "Enter the ID:";
                                    std::cin >> ID;
                                    for (auto it = getOrganizationData().begin(); it != getOrganizationData().end(); it++) {
                                        if (it->getID() == ID) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;

                                }
                                case 2:
                                {
                                    system("cls");
                                    std::string name;
                                    std::cout << "Enter the Name:";
                                    std::cin >> name;
                                    for (auto it = getOrganizationData().begin(); it != getOrganizationData().end(); it++) {
                                        if (it->getName() == name) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 3:
                                {
                                    system("cls");
                                    std::string phone;
                                    std::cout << "Enter the Phone Number:";
                                    std::cin >> phone;
                                    for (auto it = getOrganizationData().begin(); it != getOrganizationData().end(); it++) {
                                        if (it->getPhone_number() == phone) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 4:
                                {
                                    system("cls");
                                    std::string address;
                                    std::cout << "Enter the Address:";
                                    std::cin >> address;
                                    for (auto it = getOrganizationData().begin(); it != getOrganizationData().end(); it++) {
                                        if (it->getAdrress() == address) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 5:
                                {
                                    system("cls");
                                    std::string holder;
                                    std::cout << "Enter the Holder:";
                                    std::cin >> holder;
                                    for (auto it = getOrganizationData().begin(); it != getOrganizationData().end(); it++) {
                                        if (it->getHolder() == holder) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 6:
                                {
                                    system("cls");
                                    std::string TIN;
                                    std::cout << "Enter the TIN:";
                                    std::cin >> TIN;
                                    for (auto it = getOrganizationData().begin(); it != getOrganizationData().end(); it++) {
                                        if (it->getTIN() == TIN) std::cout<< *it  << std::endl;
                                    }
                                    system("pause");
                                    this->setState(0);
                                    break;
                                }
                                case 7:this->setState(0);break;
                            }

                            break;
                        }
                        case 3:this->setState(0);break;
                        case 4:this->setState(6);break;
                    }
                    break;
                }
                case 5:
                {
                    int choice1;
                    std::cout << "----SORT INFO MENU-----" << std::endl;
                    std::cout << "1.Sort the Individuals" << std::endl;
                    std::cout <<"2.Sort the Organizations" << std::endl;
                    std::cout <<"3.Back to Main Menu" << std::endl;
                    std::cout << "4.EXIT" << std::endl;
                    std::cout <<"Enter your choice :" ;
                    std::cin >> choice1;
                    switch (choice1)
                    {
                        case 1: {
                            system("cls");
                            int choice2;
                            std::cout << "----SORT INDIVUAL MENU-----" << std::endl;
                            std::cout << "1.Sort by ID" << std::endl;
                            std::cout << "2.Sort by Surname" << std::endl;
                            std::cout <<"Enter your choice :" ;
                            std::cin >> choice2;
                            switch (choice2) {
                                case 1: {
                                    std::sort(IndividualData.begin() , IndividualData.end() , UKCompare);
                                    this->setState(0);
                                    break;
                                }
                                case 2: {
                                    std::sort(IndividualData.begin() , IndividualData.end() , SurnameCompare);
                                    this->setState(0);
                                    break;
                                }

                            }
                            break;
                        }
                        case 2:
                        {
                            system("cls");
                            int choice2;
                            std::cout << "----SORT ORGANIZATION MENU-----" << std::endl;
                            std::cout << "1.Sort by ID" << std::endl;
                            std::cout << "2.Sort by Name" << std::endl;
                            std::cout <<"Enter your choice :" ;
                            std::cin >> choice2;
                            switch(choice2)
                            {
                                case 1:
                                {
                                    std::sort(OrganizationData.begin() , OrganizationData.end() , IDCompare);
                                    this->setState(0);
                                    break;
                                }
                                case 2:
                                {
                                    std::sort(OrganizationData.begin() , OrganizationData.end() , NameCompare);
                                    this->setState(0);
                                    break;
                                }
                            }
                            break;
                        }
                        case 3:this->setState(0);break;
                        case 4:this->setState(6);break;

                    }
                    break;

                }
                case 6:
                {
                    writeData(IndividualData , OrganizationData);
                    exit(0);
                }
            }

        };
    }

    static bool IDCompare(Organization o1 ,Organization o2)
    {
        return o1.getID() > o2.getID();
    }

    static bool NameCompare(Organization o1, Organization o2)
    {
        return o1.getName() > o2.getName();
    }
    static bool UKCompare(Individual i1 , Individual i2)
    {
        return i1.getUniq_key() > i2.getUniq_key();
    }

    static bool SurnameCompare(Individual i1 , Individual i2)
    {
        return i1.getSurname() > i2.getSurname();
    }


    void setState(int state)
    {
        system("cls");
        this->state = state;
        this->printMenu();

    }

    const std::vector<Individual> &getIndividualData() const {
        return IndividualData;
    }

    const std::vector<Organization> &getOrganizationData() const {
        return OrganizationData;
    }
};
#endif //COURSE_MENU_H
