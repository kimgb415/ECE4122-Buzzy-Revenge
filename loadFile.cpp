//
// Created by 김갑현 on 2021/10/19.
//
#include <iostream>
#include <SFML/Graphics.hpp>

sf::Texture angryUnicornT;
sf::Texture backgroundT;
sf::Texture bunnyT;
sf::Texture buzzyLifeT;
sf::Texture chickenT;
sf::Texture cloudT;
sf::Texture dogT;
sf::Texture frogT;
sf::Texture bulldogT;
sf::Texture insectT;
sf::Texture mouseT;
sf::Texture pigT;
sf::Texture sheepT;
sf::Texture smallBuzzyT;
sf::Texture tigerT;

sf::Sprite angryUnicorn;
sf::Sprite background;
sf::Sprite bunny;
sf::Sprite buzzyLife;
sf::Sprite chicken;
sf::Sprite cloud;
sf::Sprite dog;
sf::Sprite frog;
sf::Sprite bulldog;
sf::Sprite insect;
sf::Sprite mouse;
sf::Sprite pig;
sf::Sprite sheep;
sf::Sprite smallBuzzy;
sf::Sprite tiger;
sf::RectangleShape powerOuter;
sf::RectangleShape powerInner;

sf::Font font;

sf::Text lives;
sf::Text buzzyRevenge;
sf::Text pressEnter;
sf::Text pressEsc;
sf::Text pressSpace;
sf::Text pressUp;
sf::Text createdBy;
sf::Text myName;
sf::Text score;
sf::Text scoreNum;
sf::Text power;



void loadEverything()
{
    // load all the textures
    angryUnicornT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/angry_unicorn.png");
    backgroundT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/background.png");
    bunnyT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/bunny.png");
    buzzyLifeT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/buzzy life.png");
    chickenT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/chicken.png");
    cloudT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/cloud.png");
    dogT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/dog.png");
    frogT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/frog.png");
    bulldogT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/Georgia_Bulldogs_logo_dog_g.png");
    insectT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/insect.png");
    mouseT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/mouse.png");
    pigT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/pig.png");
    sheepT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/sheep.png");
    smallBuzzyT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/smallbuzzy.png");
    if (!tigerT.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/graphics/tiger.png"))
    {
        std::cout << "cannot load file" << std::endl;
    }

    // set all the sprites
    angryUnicorn.setTexture(angryUnicornT);
    background.setTexture(backgroundT);
    bunny.setTexture(bunnyT);
    buzzyLife.setTexture(buzzyLifeT);
    chicken.setTexture(chickenT);
    cloud.setTexture(cloudT);
    dog.setTexture(dogT);
    frog.setTexture(frogT);
    bulldog.setTexture(bulldogT);
    insect.setTexture(insectT);
    mouse.setTexture(mouseT);
    pig.setTexture(pigT);
    sheep.setTexture(sheepT);
    smallBuzzy.setTexture(smallBuzzyT);
    tiger.setTexture(tigerT);


    // set the rectangles
    // outer bound
    powerOuter.setSize(sf::Vector2f(300.f, 30.f));
    powerOuter.setFillColor(sf::Color::Transparent);
    powerOuter.setOutlineThickness(5.f);
    powerOuter.setOutlineColor(sf::Color::Black);
    // inner gauge
    powerInner.setSize(sf::Vector2f(20.f, 30.f));
    powerInner.setFillColor(sf::Color::Red);


    // load the font
    font.loadFromFile("/Users/gav/Desktop/GAV/2021_2_조지아텍/Adv Prog/LAB/LAB3/LAB3/Lab3/fonts/KOMIKAP_.ttf");

    // set the font
    lives.setFont(font);
    buzzyRevenge.setFont(font);
    pressEnter.setFont(font);
    pressEsc.setFont(font);
    pressSpace.setFont(font);
    pressUp.setFont(font);
    createdBy.setFont(font);
    myName.setFont(font);
    score.setFont(font);
    scoreNum.setFont(font);
    power.setFont(font);

    // set the string
    lives.setString("Lives");
    buzzyRevenge.setString("Buzzy's Revenge");
    pressEnter.setString("Press Enter to Restart Game");
    pressEsc.setString("Press Esc to exit");
    pressSpace.setString("Press Space to Powerup");
    pressUp.setString("Press up/down arrow to aim");
    createdBy.setString("created by");
    myName.setString("Gabhyun Kim");
    score.setString("Score: ");
    scoreNum.setString("99");
    power.setString("Power");

    // adjust the color of text
    buzzyRevenge.setFillColor(sf::Color::Red);


    return;
};


void placeEverything()
{
    // place all the texts first
    lives.setPosition(10.f, 50.f);
    buzzyRevenge.setPosition(500.f, 300.f);
    pressEnter.setPosition(500.f, 400.f);
    pressEsc.setPosition(500.f, 500.f);
    pressSpace.setPosition(500.f, 600.f);
    pressUp.setPosition(500.f, 700.f);
    createdBy.setPosition(500.f, 800.f);
    myName.setPosition(500.f, 900.f);
    power.setPosition(10.f, 1000.f);
    score.setPosition(1600.f, 50.f);
    scoreNum.setPosition(1800.f, 50.f);

    // place all the sprites
    angryUnicorn.setPosition(1800.f, 500.f);
    bunny.setPosition(1600.f, 600.f);
    buzzyLife.setPosition(30.f, 50.f);
    chicken.setPosition(1800.f, 900.f);
    dog.setPosition(1600.f, 700.f);
    frog.setPosition(1800.f, 600.f);
    bulldog.setPosition(1800.f, 700.f);
    insect.setPosition(1825.f, 200.f);
    mouse.setPosition(1600.f, 900.f);
    pig.setPosition(1800.f, 800.f);
    sheep.setPosition(1600.f, 500.f);
    smallBuzzy.setPosition(0.f, 540.f);
    tiger.setPosition(1600.f, 800.f);
    tiger.scale(0.1f, 0.1f);


    // place the rectangles
    powerOuter.setPosition(150.f, 1000.f);
    powerInner.setPosition(150.f, 1000.f);
};

void drawScreen(sf::RenderWindow& window)
{
    // draw background first
    window.draw(background);

    // draw text
    window.draw(lives);
    window.draw(buzzyRevenge);
    window.draw(pressEnter);
    window.draw(pressEsc);
    window.draw(pressSpace);
    window.draw(pressUp);
    window.draw(createdBy);
    window.draw(myName);
    window.draw(power);
    window.draw(score);
    window.draw(scoreNum);

    // draw rectangles
    window.draw(powerOuter);
    window.draw(powerInner);

    // draw sprites
    window.draw(angryUnicorn);
    window.draw(bunny);
    window.draw(buzzyLife);
    window.draw(chicken);
//    window.draw(cloud);
    window.draw(dog);
    window.draw(frog);
    window.draw(bulldog);
    window.draw(insect);
    window.draw(mouse);
    window.draw(pig);
    window.draw(sheep);
    window.draw(smallBuzzy);
    window.draw(tiger);



    return;
};