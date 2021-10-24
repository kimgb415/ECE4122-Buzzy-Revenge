#include <SFML/Graphics.hpp>
#include <cmath>
#include "loadFile.hpp"
#include "Buzzy.h"

enum class GameStatus
{
    initial,
    start,
    buzzyReleased,
};

GameStatus status;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Buzzy's Revenge");
    // load all the textures and sprites required
    loadEverything();
    placeEverything();



    // initial status of the game will be status
    status = GameStatus::initial;
    // control the user input
    bool enterPressed = false;

    // control the power gauge
    bool chargeGauge = false;
    // set the minimum velocity as 5.f
    Buzzy myBuzzy(sf::Vector2<float>(5.f, 0.f), smallBuzzy.getPosition(), smallBuzzy);
    Buzzy flyingInsect(sf::Vector2<float>(50.f, 10.f), insect.getPosition(), insect);
    // clcok and time element
    sf::Clock clock;

    // variables to control the bee
    sf::Clock insectClock;
    float before = 0.f;
    sf::Time afterRelease;
    float beeVertical = 0.1f;


    // run the program as long as the window is open
    while (window.isOpen())
    {
        // end game if used up all the lives
        if (myBuzzy.getLife() == 0)
        {
            return 0;
        }
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased)
            {
                if (enterPressed)
                {
                    for (auto& obj: textVec)
                    {
                        obj.draw = false;
                    }
                    // change the status of the game to start
                    status = GameStatus::start;
                }
                // take action if the space key is released
                if (chargeGauge)
                {
                    // change the game status
                    status = GameStatus::buzzyReleased;
                    // stop charging the gauge
                    chargeGauge = false;
                    // begin the timer
                    clock.restart();
                    insectClock.restart();
                    // minimum velocity is 600.f, max is 500.f
                    float totalVel = powerInner.getSize().x / powerOuter.getSize().x * 500.0f + 100.f;
                    // convert from degree to radian
                    float angle = smallBuzzy.getRotation() * 3.141592 / 180;
                    sf::Vector2<float> initVel(totalVel*cos(angle), totalVel*sin(angle));
                    // set the initial info of the buzzy
                    myBuzzy.setInit(initVel, smallBuzzy.getPosition());
                }
            }

        }

        // according to each game status
        // handle the user input
        // update the scene setting
        switch (status) {
            // before starting the game
            case GameStatus::initial:
                // start the game if user press enter
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                {
                    enterPressed = true;
                }
                break;
            // before releasing the buzzy
            case GameStatus::start:
                if (spriteVec[INSECT].draw)
                {
                    // insect flying
                    flyingInsect.randomFlying(insectClock.getElapsedTime(), before, beeVertical);
                    before = (int) insectClock.getElapsedTime().asSeconds();
                }

                // change the angle of the buzzy by pressing up/down arrow
                // angle range is from [0, 60] & [300, 360]
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    smallBuzzy.rotate(-0.1f);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    smallBuzzy.rotate(0.1f);
                }
                // charge the power gauge if user pressing the space
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    // start charging the gauge
                    chargeGauge = true;
                }
                // keep charging the gauge until user release the key
                if (chargeGauge)
                {
                    // advance the power indicator
                    sf::Vector2<float> powerSize = powerInner.getSize();
                    // keep advancing the indicator until the max
                    if (powerSize.x < powerOuter.getSize().x)
                    {
                        powerSize.x += 0.3f;
                        powerInner.setSize(powerSize);
                    }
                }
                break;
            case GameStatus::buzzyReleased:
                if (spriteVec[INSECT].draw)
                {
                    // insect flying
                    flyingInsect.randomFlying(insectClock.getElapsedTime(), before, beeVertical);
                    before = (int) insectClock.getElapsedTime().asSeconds();
                }

                myBuzzy.launch(clock.getElapsedTime());
                if (myBuzzy.checkCollision(clock.getElapsedTime()))
                {
                    status = GameStatus::start;
                }
                break;
            default:
                break;
        }


        // clear, draw and display the screen
        window.clear(sf::Color::Black);
        drawScreen(window, myBuzzy.getLife());
        window.display();


    }

    return 0;
}

