#pragma once
#include <list>
#include "BMS.h"

void CanMsg::setAdress(int id){
    adress=id;
}
//Voltage
Voltage::Voltage(){
    setAdress();
}
void readMsg(){

    }
virtual void saveMsg(){

    }
list displayMsg(){

    }
list History(){

    }

//Temperature
Temperature::Temperature(){
    setAdress(0x186955F4);
}
void readMsg(){

    }
virtual void saveMsg(){

    }
list displayMsg(){

    }
list History(){

    }

//SoC
SoC::SoC(){
    setAdress(0x186555F4);
}
void SoC::readMsg(){

    }
virtual void SoC::saveMsg(){

    }
list SoC::displayMsg(){

    }
list SoC::History(){

    }
