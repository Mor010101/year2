#include<string.h>

class Cake{
        char *name;
    public:
        Cake(char *name){
            strcpy(this->name, name);
        }

        char *getName(){
            return name;
        }
};