//
// Created by 김갑현 on 2021/10/19.
//
#include <iostream>
#include <random>
#include <algorithm>
#include "loadFile.hpp"
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
sf::Sprite buzzyLife1;
sf::Sprite buzzyLife2;
sf::Sprite buzzyLife3;
sf::Sprite buzzyLife4;
sf::Sprite buzzyLife5;
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

// vector for different kinds of objects
std::vector<object<sf::Sprite>> spriteVec;
std::vector<object<sf::Sprite>> lifeVec;
std::vector<object<sf::Text>> textVec;



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
    buzzyLife1.setTexture(buzzyLifeT);
    buzzyLife2.setTexture(buzzyLifeT);
    buzzyLife3.setTexture(buzzyLifeT);
    buzzyLife4.setTexture(buzzyLifeT);
    buzzyLife5.setTexture(buzzyLifeT);


    // add all the sprites that can be collided with smallBuzzy
    spriteVec.push_back(object<sf::Sprite>(&angryUnicorn, true, UNICORN));
    spriteVec.push_back(object<sf::Sprite>(&bunny, true, BUNNY));
    spriteVec.push_back(object<sf::Sprite>(&chicken, true, CHICKEN));
    spriteVec.push_back(object<sf::Sprite>(&dog, true, DOG));
    spriteVec.push_back(object<sf::Sprite>(&frog, true, FROG));
    spriteVec.push_back(object<sf::Sprite>(&sheep, true, SHEEP));
    spriteVec.push_back(object<sf::Sprite>(&pig, true, PIG));
    spriteVec.push_back(object<sf::Sprite>(&mouse, true, MOUSE));
    spriteVec.push_back(object<sf::Sprite>(&insect, true, INSECT));
    spriteVec.push_back(object<sf::Sprite>(&bulldog, true, BULLDOG));
    spriteVec.push_back(object<sf::Sprite>(&tiger, true, TIGER));



    // add all the lives
    lifeVec.push_back(object<sf::Sprite>(&buzzyLife1, true, 1));
    lifeVec.push_back(object<sf::Sprite>(&buzzyLife2, true, 2));
    lifeVec.push_back(object<sf::Sprite>(&buzzyLife3, true, 3));
    lifeVec.push_back(object<sf::Sprite>(&buzzyLife4, true, 4));
    lifeVec.push_back(object<sf::Sprite>(&buzzyLife5, true, 5));
    for (auto& obj: lifeVec)
    {
        obj.obj->setScale(0.3, 0.3);
    }


    // set the origin of the smallBuzzy
    sf::Vector2<float> buzzyOrigin(smallBuzzy.getLocalBounds().width, smallBuzzy.getLocalBounds().height/2.f);
    smallBuzzy.setOrigin(buzzyOrigin);


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
    scoreNum.setString("0");
    power.setString("Power");


    // add all the texts that should disappear after game starts
    textVec.push_back(object<sf::Text>(&buzzyRevenge, true, REVENGE));
    textVec.push_back(object<sf::Text>(&pressEnter, true, ENTER));
    textVec.push_back(object<sf::Text>(&pressEsc, true, ESC));
    textVec.push_back(object<sf::Text>(&pressSpace, true, SPACE));
    textVec.push_back(object<sf::Text>(&pressUp, true, UP));
    textVec.push_back(object<sf::Text>(&createdBy, true, CREATED));
    textVec.push_back(object<sf::Text>(&myName, true, MYNAME));


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
    buzzyLife1.setPosition(110.f, 50.f);
    buzzyLife2.setPosition(150.f, 50.f);
    buzzyLife3.setPosition(190.f, 50.f);
    buzzyLife4.setPosition(230.f, 50.f);
    buzzyLife5.setPosition(270.f, 50.f);
    chicken.setPosition(1800.f, 900.f);
    dog.setPosition(1600.f, 700.f);
    frog.setPosition(1800.f, 600.f);
    bulldog.setPosition(1800.f, 700.f);
    insect.setPosition(1825.f, 200.f);
    mouse.setPosition(1600.f, 900.f);
    pig.setPosition(1800.f, 800.f);
    sheep.setPosition(1600.f, 500.f);
    smallBuzzy.setPosition(smallBuzzy.getLocalBounds().width, 540.f);
    tiger.setPosition(1600.f, 800.f);
    tiger.scale(0.1f, 0.1f);

    // flip the insect
    insect.setScale(-1.4f, 1.4f);

    // place the rectangles
    powerOuter.setPosition(150.f, 1000.f);
    powerInner.setPosition(150.f, 1000.f);
};

void drawScreen(sf::RenderWindow& window, int lifeCount)
{
    // draw background first
    window.draw(background);

    // draw text
    window.draw(lives);
    window.draw(power);
    window.draw(score);
    window.draw(scoreNum);
    for (auto obj: textVec)
    {
        if (obj.draw)
        {
            window.draw(*obj.obj);
        }
    }

    // draw rectangles
    window.draw(powerOuter);
    window.draw(powerInner);

    // draw sprites
    window.draw(smallBuzzy);
    for (auto obj: spriteVec)
    {
        if (obj.draw)
        {
            window.draw(*obj.obj);
        }
    }
    for (auto obj:  lifeVec)
    {
        if (obj.oID <= lifeCount)
        {
            obj.draw = true;
        }
        else
        {
            obj.draw = false;
        }
        if (obj.draw)
        {
            window.draw(*obj.obj);
        }
    }


    return;
};

void recreateLevel(unsigned timeSeed)
{
    std::random_device myRandomDevice;
    unsigned seed = myRandomDevice();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0,1);
    // place one evil mascot for each column
    int bulldogColumn = distribution(generator);
    bulldog.setPosition(1600.f + 200.f*bulldogColumn, 0.f);
    tiger.setPosition(1600.f + 200.f*(1-bulldogColumn), 0.f);
    std::vector<int> whereColumn;
    std::vector<int> whereRow;
    for (int i = 0; i < 8; i++)
    {
        if (i < 5)
        {
            whereRow.push_back(i);
        }
        whereColumn.push_back(i);
    }
    std::shuffle(whereColumn.begin(), whereColumn.end(), std::default_random_engine(timeSeed));
    std::shuffle(whereRow.begin(), whereRow.end(), std::default_random_engine(timeSeed));

    // pick the column for the rest
    for (int i = 0 ; i < 8; i++)
    {
        if (i < 4)
        {
            spriteVec[i].obj->setPosition(1600.f, 0.f);
        }
        else
        {
            spriteVec[i].obj->setPosition(1800.f, 0.f);
        }
    }

    // pick the row for each object in first column
    for (int i = 0; i < 4; i++)
    {
        for (auto &obj: spriteVec)
        {
            if (!obj.draw && obj.obj->getPosition().x == 1600.f)
            {
                obj.draw = true;
                obj.obj->setPosition(1600.f, 500.f + 100.f * whereRow[i]);
                break;
            }
        }
    }
    if (!bulldogColumn)
    {
        bulldog.setPosition(1600.f, 500.f + 100.f * whereRow[4]);
    }
    else
    {
        tiger.setPosition(1600.f, 500.f + 100.f * whereRow[4]);
    }

    std::shuffle(whereRow.begin(), whereRow.end(), std::default_random_engine(timeSeed));
    // pick the row for each object in second column
    for (int i = 0; i < 4; i++)
    {
        for (auto &obj: spriteVec)
        {
            if (!obj.draw && obj.obj->getPosition().x == 1800.f)
            {
                obj.draw = true;
                obj.obj->setPosition(1800.f, 500.f + 100.f * whereRow[i]);
                break;
            }
        }
    }
    if (bulldogColumn)
    {
        bulldog.setPosition(1800.f, 500.f + 100.f * whereRow[4]);
    }
    else
    {
        tiger.setPosition(1800.f, 500.f + 100.f * whereRow[4]);
    }

    // set tiger and bulldog drawable again
    spriteVec[TIGER].draw = true;
    spriteVec[BULLDOG].draw = true;

    spriteVec[INSECT].obj->setPosition(1825.f, 200.f);
    spriteVec[INSECT].draw = true;
}