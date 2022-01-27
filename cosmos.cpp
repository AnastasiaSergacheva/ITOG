#include "sputnik.hpp"

#include <iostream>
#include <vector>
#include <thread>       
#include <chrono>      
#include <SFML/Graphics.hpp>


using namespace space;

const int win_size_x = 900;
const int win_size_y = 600;

int main()
{
    double time = 0;
    const int win_center_x = win_size_x / 2;
    const int win_center_y = win_size_y / 2;

    //       
    sf::RenderWindow window(sf::VideoMode(win_size_x, win_size_y), "COSMOS");
    //   
    sf::Texture texture;
    if (!texture.loadFromFile("img/back.png"))
    {
        std::cout << "ERROR when loading back.png" << std::endl;
        return false;
    }
    sf::Sprite back_sprite;
    back_sprite.setTexture(texture);

    //  
    sf::Image icon;
    if (!icon.loadFromFile("img/icon.jpg"))
    {
        return 1;
    }
    window.setIcon(40, 40, icon.getPixelsPtr());


    //   
    std::vector<Universe*> objects;
    objects.push_back(new Universe(1, 1, win_center_x, win_center_y, 0));
    if (!objects.back()->init("img/mars.png", 0.5))
        return 1;

    objects.push_back(new Universe(200, 200, win_center_x, win_center_y, 1));
    if (!objects.back()->init("img/sputnik.png", 0.2))
        return 1;

    //     ,   
    while (window.isOpen())
    {
        //   
        sf::Event event;

        //   
        window.clear();

        //  
        window.draw(back_sprite);

        for (size_t i = 0; i < objects.size(); i++)
        {
            objects[i]->draw(time, &window);
        }

        //    ,    
        window.display();

        //    
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        time += 0.01;
    }
    //  
    for (size_t i = 0; i < objects.size(); i++)
    {
        delete objects[i];
    }
}
