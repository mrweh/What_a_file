#include "circles.hpp"
#include "iostream"
using namespace sf;
using namespace std;
void PlayMap::drawmap(sf::RenderWindow &w,Singleton &Instance)
{
    int b;
    
    sf::Texture texture0;
    sf::Texture texture1;
    sf::Texture texture4;
    sf::Texture texture5;
    sf::Texture texture7;
    sf::Texture texture8;
    sf::Texture texture9;
    sf::Texture texture88;
    sf::Texture texture2;// Подгружаем рисунки
    
    texture9.loadFromImage(Instance.getTexture("image3"));
    texture8.loadFromImage(Instance.getTexture("image4"));
    texture7.loadFromImage(Instance.getTexture("enemy"));
    texture0.loadFromImage(Instance.getTexture("image0"));
    texture4.loadFromImage(Instance.getTexture("red"));
    texture5.loadFromImage(Instance.getTexture("wood"));
    texture88.loadFromImage(Instance.getTexture("rip"));
    sf::RectangleShape rectangle0(sf::Vector2f(50, 50));
    rectangle0.setTexture(&texture0); 
    rectangle0.setTextureRect(sf::IntRect(10, 10, 100, 100));

    
    texture1.loadFromFile("image1.jpg");
    sf::RectangleShape rectangle1(sf::Vector2f(50, 50));
    rectangle1.setTexture(&texture1); 
    rectangle1.setTextureRect(sf::IntRect(10, 10, 100, 100));

    
    texture2.loadFromFile("image2.jpg");
     sf::RectangleShape rectangle2(sf::Vector2f(50, 50));
    rectangle2.setTexture(&texture2); 

    
    
    sf::RectangleShape rectangle7(sf::Vector2f(50, 50));


    
    
    sf::RectangleShape rectangle3(sf::Vector2f(50, 50));
    rectangle3.setTextureRect(sf::IntRect(0, 0, 1250, 750));
    rectangle3.setTexture(&texture9); 
   
    sf::RectangleShape rectangle8(sf::Vector2f(50, 50));
    rectangle8.setFillColor(sf::Color::Magenta);
   
   
    sf::RectangleShape rectangle4(sf::Vector2f(50, 50));
    rectangle4.setTextureRect(sf::IntRect(0, 0, 500, 500));
    rectangle4.setTexture(&texture8); 
    // Подгружаем рисунки
    sf::RectangleShape rectangle5(sf::Vector2f(50, 50));
    rectangle5.setTextureRect(sf::IntRect(0, 0, 300, 200));
    rectangle5.setTexture(&texture88);
    //sf::Texture texture6;// Подгружаем рисунки
  
    //texture6.loadFromFile("enemy.jpg");
    
    sf::RectangleShape rectangle6(sf::Vector2f(50, 50));
    //rectangle6.setTexture(&texture6); 
    
    rectangle6.setTextureRect(sf::IntRect(0, 0, 500, 500));
    rectangle6.setTexture(&texture7); 
    

    
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            
            b = PlayMap::map[i][j];
            switch (b)
            {
                case 0:
                    rectangle0.setPosition(sf::Vector2f(i * 50, j* 50));
                    rectangle0.setTextureRect(sf::IntRect(i*25, j*25, 25, 25));
                    w.draw(rectangle0);
                    break;
                case 1:
                    rectangle1.setPosition(sf::Vector2f(i * 50, j* 50));
                    rectangle1.setTextureRect(sf::IntRect(i*50, j*50, 50, 50));
                    w.draw(rectangle1);
                    break;
                case 2: 
                    rectangle2.setPosition(sf::Vector2f(i * 50, j* 50));
                    rectangle2.setTextureRect(sf::IntRect(i*50, j*50, 50, 50));
                    w.draw(rectangle2);
                    break;
                case 3:
                    rectangle3.setPosition(sf::Vector2f(i * 50, j* 50));
                    w.draw(rectangle3);
                    break;
                case 4:
                    rectangle4.setPosition(sf::Vector2f(i * 50, j* 50));
                    w.draw(rectangle4);
                    break;
                case 5:
                    rectangle5.setPosition(sf::Vector2f(i * 50, j* 50));
                    w.draw(rectangle5);
                    break;
                case 6:
                    rectangle6.setPosition(sf::Vector2f(i * 50, j* 50));
                    w.draw(rectangle6);
                    break;
                case 7:
                    
                    
                    switch (PlayMap::tt)
                    {
                        case 1:
                            
                            rectangle7.setPosition(sf::Vector2f(i * 50, j* 50));
                            rectangle7.setTextureRect(sf::IntRect(0, 0, 500, 500));
                            rectangle7.setTexture(&texture4); 
                            w.draw(rectangle7);
                            
                            
                            break;
                        case 2:
                            rectangle2.setPosition(sf::Vector2f(i * 50, j* 50));
                            rectangle2.setTextureRect(sf::IntRect(i*50, j*50, 50, 50));
                            w.draw(rectangle2);
                            break;
                        case 3:
                            rectangle7.setPosition(sf::Vector2f(i * 50, j* 50));
                            rectangle7.setTextureRect(sf::IntRect(0, 0, 500, 1000));
                            rectangle7.setTexture(&texture5); 
                            w.draw(rectangle7);
                            
                            break;
                        case 4:
                            rectangle2.setPosition(sf::Vector2f(i * 50, j* 50));
                            rectangle2.setTextureRect(sf::IntRect(i*50, j*50, 50, 50));
                            w.draw(rectangle2);
                            break;
                    }
                    break;
            }
        }
    } // Рисуем карту
   
    
    
   
}

void Enemy::enemymove(sf::RenderWindow &w, PlayMap &maps)
{
    maps.map[Enemy::Mapfinder.mas2[Enemy::schetchik_kostil][0]][Enemy::Mapfinder.mas2[Enemy::schetchik_kostil][1]] = 6;
    maps.map[Enemy::lastx][Enemy::lasty] = 5;
    Enemy::lastx = Enemy::Mapfinder.mas2[Enemy::schetchik_kostil][0];
    Enemy::lasty = Enemy::Mapfinder.mas2[Enemy::schetchik_kostil][1];
    Enemy::mylist_x.push_back(Enemy::Mapfinder.mas2[Enemy::schetchik_kostil][0]);
    Enemy::mylist_y.push_back(Enemy::Mapfinder.mas2[Enemy::schetchik_kostil][1]);
    Enemy::schetchik_kostil++;
}

bool googlemap(PlayMap map, Enemy &enemy)
{
        for (int l = 0; l < 20; l++)
        {
            for (int c = 0; c < 20; c++)
            {
              
                if( enemy.Mapfinder.ii < 400)
                {
                    if(map.map[l][c] == 1 || map.map[l][c] == 3 || map.map[l][c] == 4 )
                    {
                       
                        bool z;
                        z = true;
                        for (int f = 0; f < (enemy.Mapfinder.ii + 1); f++)
                        {
                            if ( l == enemy.Mapfinder.mas3[f][0] && c == enemy.Mapfinder.mas3[f][1])
                            {
                                z = false;
                            }
                            //else
                            //{
                            //  z = true;
                                
                            //}
                        }	
                        if (z == true)
                        {
                            
                            
                            if ((enemy.Mapfinder.mas3[enemy.Mapfinder.ii][0] + 1 == l  && enemy.Mapfinder.mas3[enemy.Mapfinder.ii][1] == c )
                            || 
                            (enemy.Mapfinder.mas3[enemy.Mapfinder.ii][0] - 1 == l  && enemy.Mapfinder.mas3[enemy.Mapfinder.ii][1] == c )
                            ||
                            (enemy.Mapfinder.mas3[enemy.Mapfinder.ii][0] == l  && enemy.Mapfinder.mas3[enemy.Mapfinder.ii][1] + 1 == c )
                            ||
                            (enemy.Mapfinder.mas3[enemy.Mapfinder.ii][0] == l  && enemy.Mapfinder.mas3[enemy.Mapfinder.ii][1] - 1 == c ))
                            {
                                std::cout << "    " << l << "    " << c;
                                if (l == map.aa && c == map.bb)
                                {
                                    enemy.Mapfinder.ii++;
                                    enemy.Mapfinder.mas3[enemy.Mapfinder.ii][0] = map.aa;
                                    enemy.Mapfinder.mas3[enemy.Mapfinder.ii][1] = map.bb;
                                    
                                    if (enemy.Mapfinder.S == 0)
                                    {
                                        //int g;
                                        cout << "I find the way!";
                                        enemy.Mapfinder.S = enemy.Mapfinder.ii;
                                        for (int r = 0; r <  enemy.Mapfinder.ii + 1; r++)
                                        {
                                            enemy.Mapfinder.mas2[r][0] = enemy.Mapfinder.mas3[r][0];
                                            enemy.Mapfinder.mas2[r][1] = enemy.Mapfinder.mas3[r][1];
                                            //g = mas2[r];
                                            //cout << g;
                                            //cout << "  ";
                                        }
                                        //cout << "\n";
                                        //std::cout << 7 << "                                                                                                    ";
                                    }
                                    else
                                    {
                                        if (enemy.Mapfinder.S > enemy.Mapfinder.ii)
                                        {
                                            //int g;
                                            cout << "I find the way!";
                                            enemy.Mapfinder.S = enemy.Mapfinder.ii;
                                            for (int r = 0; r <  enemy.Mapfinder.ii + 1; r++)
                                            {
                                                enemy.Mapfinder.mas2[r][0] = enemy.Mapfinder.mas3[r][0];
                                                enemy.Mapfinder.mas2[r][1] = enemy.Mapfinder.mas3[r][1];
                                                //g = mas2[r];
                                                //cout << g;
                                                //cout << "  ";
                                            }
                                            //cout << "\n";
                                            //std::cout << 5 << "                                                                                          ";
                                        }
                                    }
                                    enemy.way = true;
                                    enemy.Mapfinder.ii--;
                                }
                                else
                                {
                                    enemy.Mapfinder.ii++;
                                    enemy.Mapfinder.mas3[ enemy.Mapfinder.ii][0] = l;
                                    enemy.Mapfinder.mas3[ enemy.Mapfinder.ii][1] = c;
                                     //std::cout << "    @" <<enemy.Mapfinder.mas3[ enemy.Mapfinder.ii][0]  << "    @" << enemy.Mapfinder.mas3[ enemy.Mapfinder.ii][1];
                                    enemy.way = googlemap(map,enemy);
                                    /*for (int k = 0; k < enemy.Mapfinder.ii+1; k++)
                                    {
                                        enemy.Mapfinder.mas6[k][0] = enemy.Mapfinder.mas3[k][0];
                                        enemy.Mapfinder.mas6[k][1] = enemy.Mapfinder.mas3[k][1];
                                        
                                    }
                                    //delete[]enemy.Mapfinder.mas3;
                                    
                                    for (int k = 0; k < enemy.Mapfinder.ii; k++)
                                    {
                                        enemy.Mapfinder.mas3[k][0] = enemy.Mapfinder.mas6[k][0];
                                       enemy.Mapfinder.mas3[k][1] = enemy.Mapfinder.mas6[k][1];
                                        
                                    }
                                    //delete[]enemy.Mapfinder.mas6;*/
                                    
                                    std::cout <<  "  " << enemy.Mapfinder.ii;
                                    
                                    enemy.Mapfinder.ii--;
                                }
                            }
                        }
                    }
                }
            }
        }
        
    return enemy.way;
}

void Enemy::makegif(PlayMap &map,int y)
{
    int i = 0;
    bool End = true;
    while(End == true )
    {
                    if(Enemy::Mapfinder.mas2[i][0] == map.aa && Enemy::Mapfinder.mas2[i][1] == map.bb)
                    {
                        End = false;
                        
                    }
                    else
                    {
                        if(End == true)
                        {
                            map.map_forgif[Enemy::Mapfinder.mas2[i][0]][Enemy::Mapfinder.mas2[i][1]] +=1;
                        }
                    }
                    i++;
    
    }
    int v = 0 - y;
    int g = y + 1;
    int qq = 0;
    int ww = 0;
    
    for(int q  = 0; q < 20; q++)
    {
        for(int w = 0; w < 20; w++)
        {
            if(map.map_forgif[q][w] > 0 )
            {  
                for(int m = 0; m < map.map_forgif[q][w]; m++)
                {
                    for(int i = v; i < g; i++)
                    {
                        for(int j = v; j < g; j++)
                        {
                            
                            qq = q + i;
                            ww = w + j;
                            map.map_forgifff[qq][ww]++;
                        }
                    }
                }
            }
        }
    }
}

void PlayMap::makegifmap()
{
    
    
    
    int z = 0;
    bool k = false;
    int l = 0;
    int n = 0;
    for(int uu = 0; uu < 3; uu++)
    {
        for(int ff = 0; ff < 10; ff++)
        {
            PlayMap::mas_forgif[ff][uu] = 0;
        }
    }
    for(int q  = 0; q < 20; q++)
    {
        for(int w = 0; w < 20; w++)
        {
            l = 0;
            z = PlayMap::mas_forgif[l][0];
            k = false;
            if(PlayMap::map[q][w] == 2)
            {
                
                while(k == false)
                {
                    if(PlayMap::map_forgifff[q][w] < z)
                    {
                       
                        if(l != 0)
                        {
                            for(int r = 0; r < l; r++)
                            {
                                n = r + 1;
                                PlayMap::mas_forgif[r ][0] = PlayMap::mas_forgif[n][0];
                                PlayMap::mas_forgif[r ][1] = PlayMap::mas_forgif[n][1];
                                PlayMap::mas_forgif[r ][2] = PlayMap::mas_forgif[n][2];
                            }
                                PlayMap::mas_forgif[l][0] = PlayMap::map_forgifff[q][w];
                                PlayMap::mas_forgif[l][1] = q;
                                PlayMap::mas_forgif[l][2] = w;
                                
                        }
                        k = true;
                    }
                    else
                    {
                        
                        if(l  == 9 && PlayMap::map_forgifff[l][w] >= z)
                        {
                            for(int r = 0; r < l; r++)
                            {
                                n = r + 1;
                                PlayMap::mas_forgif[r ][0] = PlayMap::mas_forgif[n][0];
                                PlayMap::mas_forgif[r ][1] = PlayMap::mas_forgif[n][1];
                                PlayMap::mas_forgif[r ][2] = PlayMap::mas_forgif[n][2];
                            }
                                PlayMap::mas_forgif[l][0] = PlayMap::map_forgifff[q][w];
                                PlayMap::mas_forgif[l][1] = q;
                                PlayMap::mas_forgif[l][2] = w;
                            k = true;
                        }
                        else
                        {
                            if(l >= 9)
                            {
                                k = true;
                            }
                            else
                            {
                                l++;
                                z = PlayMap::mas_forgif[l][0];
                            } 
                        }
                    }
                }
            }
        }
    }
    
    for(int t = 0; t < 10; t++)
    {
        PlayMap::map[PlayMap::mas_forgif[t][1]][PlayMap::mas_forgif[t][2]] = 7;
    }
    
}