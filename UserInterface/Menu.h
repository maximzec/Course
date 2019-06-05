//
// Created by User on 30.05.2019.
//

#ifndef COURSE_MENU_H
#define COURSE_MENU_H

#include <vector>
#include "../Models/Individual.h"
#include "../Models/Organization.h"
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
        this->state = 0;
    }
    Menu(int state)
    {
        this->state = state;
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
                    std::cout << "5.EXIT" << std::endl;
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
                        case 4:exit(0);
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
                            break;
                        }
                        case 2: {
                            int ID;
                            std::cout << "Enter the ID of Organization you want to delete:";
                            std::cin >> ID;
                            for (auto it = getOrganizationData().begin(); it != getOrganizationData().end(); it++) {
                                if (it->getID() == ID) OrganizationData.erase(it);
                            }
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
                        case 4:exit(0);
                    }
                    break;

                }
                case 4: {
                    break;
                }
                case 5:
                {
                    ///добавить сохранение данных в файл и его перезапись
                    exit(0);

                }
            }

        };
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
