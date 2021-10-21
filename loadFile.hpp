//
// Created by 김갑현 on 2021/10/19.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#ifndef LAB3_LOADFILE_H
#define LAB3_LOADFILE_H

#endif //LAB3_LOADFILE_H

// sprites required
extern sf::Sprite angryUnicorn;
extern sf::Sprite background;
extern sf::Sprite bunny;
extern sf::Sprite buzzyLife;
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

// function declaration to load every object
void loadEverything();
// function declaration to place every object
void placeEverything();
// function declaration to draw the intial screen
void drawScreen(sf::RenderWindow&);
