#include<iostream>
#include<string>
#include<unistd.h>
#include<iomanip>

int main()
{
    std:: cout<<"filler text\nfiller text\nfiller text\nfiller text\n";
    for(int i = 5; i>=0 ; i--){
                
                std :: cout<<"Se prepara altceva timp ramas: "<<i<<"\n";
                sleep(1);
                //   <<move cursor up 1 line << delete line
                std :: cout << "\x1b[1A"<<"\x1b[2K";
            }
    std :: cout<<"Command is ready\n";
    return 0;
}