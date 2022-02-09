/*
** EPITECH PROJECT, 2022
** hospital
** File description:
** KoalaDoctor
*/

#include <iostream>
#include <fstream>
#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
    _name = name;
    std::cout << "Dr." << _name << ": I'm Dr." << _name << "! How do you kreog?" << std::endl;   
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *sickkoala)
{
    std::string report_name = sickkoala->getName() += ".report";
    std::ofstream report(report_name);
    std::string drug_to_give[] = {"Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf"};

    std::cout << "Dr." << _name << ": So what's goerking you Mr." << sickkoala->getName() << "?" << std::endl;
    sickkoala->poke();
    if (report) {
        report << drug_to_give[random()%5] << std::endl;
        report.close();
    }

}

void KoalaDoctor::timeCheck()
{
    if (time_to_work)
    std::cout << "Dr."<< _name << ": Time to get to work!" << std::endl;
  else if (!time_to_work)
    std::cout << "Dr."<< _name << ": Time to go home to my eucalyptus forest!" << std::endl;
  time_to_work = !time_to_work;
}