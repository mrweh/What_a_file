#include <SFML/Graphics.hpp>
#include <list>
#include "vector"
#include "iostream"
#include <unordered_map>
#include <string>
#include <SFML/Window.hpp>
#pragma once
using namespace sf;
using namespace std;
class Singleton
{
private:
    std::unordered_map<string,sf::Image> Cache;
    Singleton() {}  // конструктор недоступен
    ~Singleton() {} // и деструктор
    Singleton(Singleton const&) = delete;
    Singleton& operator= (Singleton const&) = delete;
public:
    void load(string name)
    {
        string namePNG = name + ".jpg";
        
        Image image;
        //std::cout << namePNG << "\n";
        if(!image.loadFromFile(namePNG))
        {
            std::cout<<"ERROR: Can't load texture \n";
        }
        Cache[name] = image;
    }
    
    Image getTexture(string name)
    {
        //     std::cout << Cache[name] << "\n";
        return Cache[name];
    }
    
    static Singleton& Instance()
    {
        // согласно стандарту, этот код потокобезопасный
        static Singleton s;
        return s;
    }
};



class PlayMap
{
    public:
    int map[20][20];
    void drawmap(sf::RenderWindow &w,Singleton &Instance);
    int p = 3; // кол-во клеток, дороги + базы врага
    int aa;
    int bb;
    int map_forgif[20][20];
    int map_forgifff[20][20];
    void makegifmap();
    int mas_forgif[10][3];
    int tt = 1;

};
struct Cont
{
    public:
    int S  = 0;
    int L = 1;
    int mas2[400][2];
    int mas3[400][2];  
    
    std::list <int> listx;
    std::list <int> listy;
    int ii = 0;
    int h = 0;
};
class Enemy
{
    public:
    void enemymove(sf::RenderWindow &w, PlayMap &maps);
    std::list <int> mylist_x;
    std::list <int> mylist_y;
    int kx = 0;
    int ky = 0;
    bool Noway_nogame;
    int lastx = 19;
    int lasty = 19;
    int anyx = 0;
    int anyy = 0;
    bool way = false;
    Cont Mapfinder;
    int schetchik_kostil = 1;
    int write[2] = {0,0};
    void makegif(PlayMap &map,int y);
    
};
bool googlemap(PlayMap map, Enemy &enemy);
