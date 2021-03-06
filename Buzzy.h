/*
Author: <Gabhyun Kim>
Class: ECE4122
Last Date Modified: <10/24/2021>
Description:
    class definition for the Buzzy Class
    Buzzy class will be used to implement the small buzzy and the flying insect
*/

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

    int score;
    int lives;


public:
    // constructor
    Buzzy(sf::Vector2<float> initVel, sf::Vector2<float> initLoc, sf::Sprite& buzzySprite):  \
        initVel(initVel), initLoc(initLoc), velocity(initVel), location(initLoc), buzzySprite(buzzySprite), score(0), lives(5) {};

    void setInit(sf::Vector2<float> vel, sf::Vector2<float> loc)
    {
        initVel = vel;
        initLoc = loc;
    }

    int getLife() const;
    void launch(sf::Time);
    bool checkCollision(sf::Time);
    void randomFlying(sf::Time, int, float&);

    ~Buzzy() {};

};


#endif //LAB3_BUZZY_H
