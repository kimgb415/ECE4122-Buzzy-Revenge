//
// Created by 김갑현 on 2021/10/19.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef LAB3_LOADFILE_H
#define LAB3_LOADFILE_H


#endif //LAB3_LOADFILE_H

#define UNICORN 0
#define BUNNY 1
#define CHICKEN 2
#define DOG 3
#define FROG 4
#define SHEEP 5
#define PIG 6
#define MOUSE 7
#define INSECT 8
#define BULLDOG 9
#define TIGER 10

#define REVENGE 11
#define ENTER 12
#define ESC 13
#define SPACE 14
#define UP 15
#define CREATED 16
#define MYNAME 17

template <typename T>
class object
{
public:
    T* obj;
    bool draw;
    int oID;

    object(T* obj, bool draw, int oID): obj(obj), draw(draw), oID(oID) {};

    ~object() {};
};


// sprites required
extern sf::Sprite angryUnicorn;
extern sf::Sprite background;
extern sf::Sprite bunny;
extern sf::Sprite chicken;
extern sf::Sprite cloud;
extern sf::Sprite dog;
extern sf::Sprite frog;
extern sf::Sprite bulldog;
extern sf::Sprite insect;
extern sf::Sprite mouse;
extern sf::Sprite pig;
extern sf::Sprite sheep;
extern sf::Sprite smallBuzzy;
extern sf::Sprite tiger;
extern sf::Sprite buzzyLife1;
extern sf::Sprite buzzyLife2;
extern sf::Sprite buzzyLife3;
extern sf::Sprite buzzyLife4;
extern sf::Sprite buzzyLife5;


extern sf::RectangleShape powerOuter;
extern sf::RectangleShape powerInner;


extern sf::Text lives;
extern sf::Text buzzyRevenge;
extern sf::Text pressEnter;
extern sf::Text pressEsc;
extern sf::Text pressSpace;
extern sf::Text pressUp;
extern sf::Text createdBy;
extern sf::Text myName;
extern sf::Text score;
extern sf::Text scoreNum;
extern sf::Text power;


extern std::vector<object<sf::Sprite>> spriteVec;
extern std::vector<object<sf::Sprite>> lifeVec;
extern std::vector<object<sf::Text>> textVec;

// function declaration to load every object
void loadEverything();
// function declaration to place every object
void placeEverything();
// function declaration to draw all the objects
void drawScreen(sf::RenderWindow&, int);
// recreate the level
void recreateLevel(unsigned);
