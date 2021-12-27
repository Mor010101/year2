#pragma once

#include<string>

class CakeRecipe{
        std :: string name;
        int time;
    public:
        CakeRecipe(std :: string name, int time){
            this->name = name;
            this->time = time;
        }

        std :: string getName(){
            return name;
        }

        int getTime(){
            return time;
        }
};