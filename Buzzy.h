//
// Created by 김갑현 on 2021/10/20.
//
#ifndef LAB3_BUZZY_H
#define LAB3_BUZZY_H

#include <SFML/Graphics.hpp>

class Buzzy {
private:
    // initial information of the buzzy
    // velocity contains horizontal and vertical
    sf::Vector2<float> initVel;
    sf::Vector2<float> initLoc;
    // current information of the buzzy
    sf::Vector2<float> velocity;
    sf::Vector2<float> location;
    sf::Sprite &buzzySprite;


public:
    // constructor
    Buzzy(sf::Vector2<float> initVel, sf::Vector2<float> initLoc, sf::Sprite& buzzySprite):  \
        initVel(initVel), initLoc(initLoc), velocity(initVel), location(initLoc), buzzySprite(buzzySprite) {};

    void setInit(sf::Vector2<float> vel, sf::Vector2<float> loc)
    {
        initVel = vel;
        initLoc = loc;
    }

    void launch(sf::Time);

    ~Buzzy() {};

};


#endif //LAB3_BUZZY_H
