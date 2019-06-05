#include <utility>

#include <utility>

//
// Created by User on 20.05.2019.
//

#ifndef COURSE_PERSON_H
#define COURSE_PERSON_H

#include <iostream>
#include <fstream>

class Individual {
private:
    std::string name;
    std::string surname;
    std::string midname;
    std::string TIN;
    std::string citizenship;
    std::string m_status;
    char sex;
    int age;
    unsigned int uniq_key;

public:

    Individual() {
        this->name = "";
        this->surname = "";
        this->midname = "";
        this->TIN = "";
        this->citizenship = "";
        this->m_status = "";
        this->age = 0;
        this->sex = 0;
        this->uniq_key = 0;
    }

    Individual(std::string name, std::string surname, std::string midname, std::string TIN, std::string citizenship,
               std::string m_status, int age, char sex, unsigned int uniq_key) {
        this->name = std::move(name);
        this->surname = std::move(surname);
        this->midname = std::move(midname);
        this->TIN = std::move(TIN);
        this->citizenship = std::move(citizenship);
        this->m_status = std::move(m_status);
        this->age = age;
        this->sex = sex;
        this->uniq_key = uniq_key;
    }

    ~Individual() = default;


    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        this->name = name;
    }

    const std::string &getSurname() const {
        return surname;
    }

    void setSurname(const std::string &surname) {
        this->surname = surname;
    }

    const std::string &getMidname() const {
        return midname;
    }

    void setMidname(const std::string &midname) {
        this->midname = midname;
    }

    const std::string &getTIN() const {
        return TIN;
    }

    void setTIN(const std::string &TIN) {
        this->TIN = TIN;
    }

    const std::string &getCitizenship() const {
        return citizenship;
    }

    void setCitizenship(const std::string &citizenship) {
        this->citizenship = citizenship;
    }

    const std::string &getM_status() const {
        return m_status;
    }

    void setM_status(const std::string &m_status) {
        this->m_status = m_status;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }

    char getSex() const {
        return sex;
    }

    void setSex(char sex) {
        this->sex = sex;
    }

    unsigned int getUniq_key() const {
        return uniq_key;
    }

    void setUniq_key(unsigned int uniq_key) {
        this->uniq_key = uniq_key;
    }

    friend std::ostream& operator<<(std::ostream& out , const Individual &i )
    {
        out <<"Individual "<< i.uniq_key << " "<< i.surname << " " << i.name << " " << i.midname << ":" << "\n\tage - " << i.age << "\n\tsex - " << i.sex << "\n\tcitizenship - " << i.citizenship << "\n\tTIN - " << i.TIN << "\n\tm-status - " << i.m_status << std::endl;
        return out;
    }

    friend std::istream&operator>>(std::istream& in , Individual &i)
    {
        std::cout << "Enter ID:";
        in >> i.uniq_key;
        std::cout << std::endl;
        std::cout << "Enter name:";
        in >> i.name ;
        std::cout << std::endl;
        std::cout << "Enter surname:";
        in >> i.surname ;
        std::cout << std::endl;
        std::cout << "Enter midname:";
        in >> i.midname ;
        std::cout << std::endl;
        std::cout << "Enter age:";
        in >> i.age ;
        std::cout << std::endl;
        std::cout << "Enter sex:";
        in >> i.sex ;
        std::cout << std::endl;
        std::cout << "Enter TIN:";
        in >> i.TIN ;
        std::cout << std::endl;
        std::cout << "Enter m_status:";
        in >> i.m_status ;
        std::cout << std::endl;
        std::cout << "Enter citizenship:";
        in >> i.citizenship ;
        std::cout << std::endl;
    }


};
#endif //COURSE_PERSON_H
