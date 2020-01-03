#include "circles.hpp"
#include <list>
#include <vector>
#include <windows.h>
#include <iostream>
using namespace sf;
using namespace std;


int main(){
    RenderWindow window(VideoMode(1000, 1000), "Lab03"); 
    int Templmap[20][20] = {
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    { 0,3,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,3,0},
    { 0,1,2,1,2,1,2,1,2,1,2,1,2,0,2,0,2,0,2,0},
    { 0,1,1,1,1,1,1,1,1,1,2,1,0,2,2,2,2,2,0,0},
    { 0,1,2,1,2,1,2,1,2,2,2,1,2,0,2,0,2,0,2,0},
    { 0,1,1,1,2,1,1,1,2,2,2,1,1,1,1,1,1,1,1,0},
    { 0,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,0,1,0},
    { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,2,0,1,0},
    { 0,1,0,0,0,2,2,2,2,2,0,0,0,0,1,0,2,0,1,0},
    { 0,1,1,1,0,2,2,2,2,2,0,1,1,1,1,0,2,0,1,0},
    { 0,2,2,1,0,2,2,2,2,2,0,1,0,0,0,0,2,0,1,0},
    { 0,2,2,1,0,2,2,2,2,2,0,1,2,2,2,2,2,0,1,0},
    { 0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    { 0,1,2,2,2,2,0,2,0,2,0,0,2,0,2,2,2,0,1,0},
    { 0,1,2,0,0,0,0,2,2,2,2,2,0,2,2,0,2,0,1,0},
    { 0,1,2,2,2,2,2,0,2,0,2,2,2,2,2,2,0,0,1,0},
    { 0,1,0,0,0,2,2,0,2,0,2,2,0,2,2,0,2,0,1,0},
    { 0,1,2,2,2,2,2,0,2,0,2,2,0,2,2,0,0,2,1,0},
    { 0,4,0,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0},
    { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
     
    };
    PlayMap mapp;
    Enemy en1;
    Enemy en2;
    Enemy en3;

    Singleton& Instance = Singleton::Instance();
    
    Instance.load("image3");
    Instance.load("image4");
    Instance.load("enemy");
    Instance.load("image0");
    Instance.load("red");
    Instance.load("wood");
    Instance.load("rip");
    
    
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20 ; j++)
        {
            mapp.map[i][j] = Templmap[i][j];
            if(mapp.map[i][j] == 4)
            {
                mapp.aa = i;
                mapp.bb = j;
            }
            if(mapp.map[i][j] == 3 && en1.kx == 0 && en1.ky == 0)
            {
                en1.kx = i;
                en1.ky = j;

            }
            else
            {
                if(mapp.map[i][j] == 3 && en2.kx == 0 && en2.ky == 0)
                {
                    en2.kx = i;
                    en2.ky = j;
                    
                }
                else
                {
                    if(mapp.map[i][j] == 3 && en3.kx == 0 && en3.ky == 0)
                    {
                        en3.kx = i;
                        en3.ky = j;

                    }
                }
            }
        }
    }
    std::cout <<"   " <<  en1.kx <<"   " << en1.ky <<"   " ;
    std::cout <<"   " <<  en2.kx <<"   "  << en2.ky <<"   " ;
    std::cout <<"   " <<  en3.kx <<"   " << en3.ky <<"   " ;
    
    std::cout <<"   " <<  mapp.aa <<"   "  <<  mapp.bb <<"   " ;
    
     // Сделать отдельно интовый список по х и у
    

    
    
        en1.Mapfinder.mas3[0][0] = en1.kx;
        en1.Mapfinder.mas3[0][1] = en1.ky;
        en2.Mapfinder.mas3[0][0] = en2.kx;
        en2.Mapfinder.mas3[0][1] = en2.ky;
        en3.Mapfinder.mas3[0][0] = en3.kx;
        en3.Mapfinder.mas3[0][1] = en3.ky;
    

    en1.way =  googlemap(mapp, en1);
   
    en2.way =  googlemap(mapp, en2);
    en3.way =  googlemap(mapp, en3);
    
    for(int uu = 0; uu < 20; uu++)
    {
        for(int ff = 0; ff < 20; ff++)
        {
            mapp.map_forgif[ff][uu] = 0;
        }
    }
    for(int uu = 0; uu < 20; uu++)
    {
        for(int ff = 0; ff < 20; ff++)
        {
            mapp.map_forgifff[ff][uu] = 0;
        }
    }
    en1.makegif(mapp,3);
    en1.makegif(mapp,3);
    en1.makegif(mapp,3);
    std::vector <int> my;
    my.push_back(1);
    my.push_back(2);
    my.push_back(3);
    my.push_back(4);
    mapp.tt = my.front();
    std::cout <<"GG";
    mapp.makegifmap();
    std::cout << "FF";
    //////////////заполняем
    
    bool End1 = true;
    bool End2 = true;
    bool End3 = true;
    bool End = true;
    while(End == true )
    {

           
                /*if(en1.Mapfinder.mas2[en1.schetchik_kostil][0] == mapp.aa && en1.Mapfinder.mas2[en1.schetchik_kostil][0] == mapp.bb 
                && en2.Mapfinder.mas2[en2.schetchik_kostil][0] == mapp.aa && en2.Mapfinder.mas2[en2.schetchik_kostil][0] == mapp.bb
                && en3.Mapfinder.mas2[en3.schetchik_kostil][0] == mapp.aa && en3.Mapfinder.mas2[en3.schetchik_kostil][0] == mapp.bb)
                {
                    End = false; 
                }
                else
                { */
                    mapp.drawmap(window, Instance);
                    my.erase(my.begin());
                    my.push_back(mapp.tt);
                    mapp.tt = my.front();
                    window.display();
                    Sleep(2);
                    window.clear();
                    if(en1.Mapfinder.mas2[en1.schetchik_kostil][0] == mapp.aa && en1.Mapfinder.mas2[en1.schetchik_kostil][1] == mapp.bb)
                    {
                        End1 = false;
                        
                    }
                    else
                    {
                        if(End1 == true)
                        {
                            en1.enemymove(window,mapp);
                            
                        }
                        
                    }
                    mapp.drawmap(window, Instance);
                    my.erase(my.begin());
                    my.push_back(mapp.tt);
                    mapp.tt = my.front();
                    window.display();
                    Sleep(2);
                    window.clear();
                    if(en2.Mapfinder.mas2[en2.schetchik_kostil][0] == mapp.aa && en2.Mapfinder.mas2[en2.schetchik_kostil][1] == mapp.bb)
                    {
                        End2 = false;
                        
                    }
                    else
                    {
                        if(End2 == true)
                        {
                            en2.enemymove(window,mapp);
                            
                        }
                        
                    }
                    mapp.drawmap(window, Instance);
                    my.erase(my.begin());
                    my.push_back(mapp.tt);
                    mapp.tt = my.front();
                    window.display();
                    Sleep(2);
                    window.clear();
                    if(en3.Mapfinder.mas2[en3.schetchik_kostil][0] == mapp.aa && en3.Mapfinder.mas2[en3.schetchik_kostil][1] == mapp.bb)
                    {
                        End3 = false;
                        
                    }
                    else
                    {
                        if(End3 == true)
                        {
                            en3.enemymove(window,mapp);
                            
                        }
                        
                    }
                    mapp.drawmap(window, Instance);
                    my.erase(my.begin());
                    my.push_back(mapp.tt);
                    mapp.tt = my.front();
                    window.display();
                    Sleep(2);
                    window.clear();
                    if(End1 == false && End2 == false && End3 == false)
                    {
                        End = false;
                    }
                    
                //}
                
                
                
            
    }
    while (window.isOpen())
    {
       
        
           
       
           
            Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close(); 
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
            {
                window.close(); 
            }
        }
                
        
    }
   
}