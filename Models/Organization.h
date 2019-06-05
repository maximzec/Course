//
// Created by User on 06.06.2019.
//

#ifndef COURSE_ORGANIZATION_H
#define COURSE_ORGANIZATION_H

#include <iostream>
class Organization
{
private:
    int ID;
    std::string name;
    std::string adrress;
    std::string phone_number;
    std::string holder;
    std::string TIN;
public:
    Organization()
    {
        this->ID = -1;
        this->name = "";
        this->adrress = "";
        this->phone_number = "";
        this->holder = "";
        this->TIN = "";
    }

    Organization(std::string address , std::string phone_number , std::string holder , std::string TIN)
    {
        this->adrress = address;
        this->phone_number = phone_number;
        this->holder = holder;
        this->TIN = TIN;
    }

    const std::string &getAdrress() const {
        return adrress;
    }

    void setAdrress(const std::string &adrress) {
        this->adrress = adrress;
    }

    const std::string &getPhone_number() const {
        return phone_number;
    }

    void setPhone_number(const std::string &phone_number) {
        this->phone_number = phone_number;
    }

    const std::string &getHolder() const {
        return holder;
    }

    void setHolder(const std::string &holder) {
        this->holder = holder;
    }

    const std::string &getTIN() const {
        return TIN;
    }

    void setTIN(const std::string &TIN) {
        this->TIN = TIN;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        this->name = name;
    }

    friend std::ostream &operator<<(std::ostream &os, const Organization &organization) {
        os <<"Organization "<< organization.ID << " "<< "name: " << organization.name << "\n\tadrress: " << organization.adrress << "\n\tphone_number: "
           << organization.phone_number << "\n\tholder: " << organization.holder << "\n\tTIN: " << organization.TIN;
        return os;
    }

    int getID() const {
        return ID;
    }

    void setID(int ID) {
        this->ID = ID;
    }

    friend std::istream &operator>>(std::istream &is , Organization &organization)
    {
        std::cout << "Enter the ID:";
        is >> organization.ID;
        std::cout << "\nEnter the name:";
        is >> organization.name;
        std::cout <<"\nEnter the address:";
        is >> organization.adrress;
        std::cout <<"\nEnter the phone number:";
        is>>organization.phone_number;
        std::cout << "\nEnter the holder:";
        is >> organization.holder;
        std::cout << "\nEnter the TIN:";
        is >> organization.TIN;
        return is;
    }
};
#endif //COURSE_ORGANIZATION_H
