#pragma once //ensures header is not inserted multiple times

#include<list>
#include<iostream>
#include "CommandTaker.h" 

#include "CakeRecipe.h"


class CommanPanel{
        std :: list <CakeRecipe> recipe;
    public:
        void showProducts(){
            for(auto &i : recipe)
                std :: cout<<i.getName()<<" Durata: "<<i.getTime()<<"\n";
        }

        void selectProduct(std :: string name);
            

};