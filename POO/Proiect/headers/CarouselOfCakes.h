#pragma once

#include <list>
#include <iostream>

#include "Cake.h"
using namespace std; 

//n-am mai folosit o clasa derivata din stl list, "standard library containers" nu au destructori virtuali


class CarouselOfCakes{
        std :: list <Cake> storage;
        const unsigned int maxCapacity = 10, lowLimit = 3;
    public:
        CarouselOfCakes(){}
        
        bool addCake(Cake command){
            try{
            if(storage.size() <= maxCapacity)
                storage.push_back(command);
            else
                throw "Storage is full!";
            }
            catch(char *message){
                std :: cout<<message;
            }
        }
        
        Cake getCake(char *name){

        }

        int getCurrentCapacity(){
            return maxCapacity - storage.size();
        }
        
};


