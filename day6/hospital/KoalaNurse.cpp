    /*
** EPITECH PROJECT, 2022
** hospital
** File description:
** KoalaNurse
*/

#include <iostream>
#include <ostream>
#include <fstream>
#include "KoalaNurse.hpp"
#include "SickKoala.hpp"

KoalaNurse::KoalaNurse(int id)
{
    id_ = id;
    time_to_work_ = true;
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << id_ << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string str, SickKoala *koala)
{
    koala->takeDrug(str);
}

std::string KoalaNurse::readReport(std::string file_name)
{
    int pos = 0;
    std::string patient_name;
    std::string drug;
    std::ifstream file(file_name);

    patient_name = file_name;
    if (pos = patient_name.find(".report", 0) != std::string::npos);
    {
        patient_name.erase(5, 7);
        if (file.is_open()) {
            std::getline(file, drug);
            std::cout << "Nurse " << id_ 
            << ": Kreog! Mr." << patient_name 
            << " needs a " << drug << "!" << std::endl;
        
        }
    }
    return (drug);
}

void KoalaNurse::timeCheck(void)
{
    if (time_to_work_ == true)
        std::cout << "Nurse " << id_ << ": Time to get to work!" << std::endl;
    if (time_to_work_ == false)
        std::cout << "Nurse " << id_ << ": Time to go home to my eucalyptus forest!" << std::endl;
    time_to_work_ = !time_to_work_;
}