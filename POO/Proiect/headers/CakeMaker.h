#pragma once

#include<iostream>
#include<unistd.h>
#include<cstring>

#include "Cake.h"
#include "CakeRecipe.h"

class CakeMaker{
    public:
        Cake takeCommand(CakeRecipe recipe){
            for(uint i = recipe.getTime(); i>=0 ; i--){
                std :: cout<<"Se prepara "<<recipe.getName()<<" timp ramas: "<<i<<"\n";
                sleep(1);
                //   <<move cursor up 1 line << delete line
                std :: cout << "\x1b[1A"<<"\x1b[2K";
            }
            
            char name[recipe.getName().length()];
            strcpy(name,recipe.getName().c_str());

            std :: cout<<name<<" este pregatit/a!\n";

            return Cake(name);
        }
};