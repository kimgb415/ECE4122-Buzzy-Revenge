//
// Created by 김갑현 on 2021/10/20.
//
#include "Buzzy.h"
#include <cmath>
#include <string>
#include "loadFile.hpp"
#include <random>

int Buzzy::getLife() const
{
    return lives;
}

void Buzzy::launch(sf::Time t)
{
    float time = t.asSeconds();
    float g = 9.8f * 10;
    // update
    location.y = initLoc.y + initVel.y * time + 0.5 * g * time * time;
    velocity.y = initVel.y + g * time;
    location.x = initLoc.x + initVel.x * time;
    velocity.x = initVel.x;

    // set the position of the sprite
    buzzySprite.setPosition(location);

    // set the rotation
    // obtain the tangent of the trajectory
    buzzySprite.setRotation(atan2(velocity.y, velocity.x) * 180 / 3.141592);

    return;
}

// check collision
bool Buzzy::checkCollision(sf::Time time)
{
    for (auto &object: spriteVec) {
        if (!object.draw)
        {
            continue;
        }
        // if collide with object
        if (object.obj->getGlobalBounds().contains(buzzySprite.getPosition())) {
            // if it is flying insect
            if (object.oID == INSECT) {
                // get 75 points
                score += 75;
                // insect disappear
                object.draw = false;
                object.obj->setPosition(1825.f, 200.f);
            }
            else if (object.oID == UNICORN)
            {
                // extra life
                if (lives < 5) {
                    lives++;
                }
                // mad unicorn disappear
                object.draw = false;
                // images above drop
            }
            else if (object.oID == TIGER || object.oID == BULLDOG)
            {
                // get 25 points
                score += 25;
                for (auto &obj: spriteVec)
                {
                    // whole column disappear
                    if (object.obj->getPosition().x == obj.obj->getPosition().x) {
                        obj.draw = false;
                    }
                }
                // if both evil mascots were hit
                if (!spriteVec[TIGER].draw && !spriteVec[BULLDOG].draw)
                {
                    // levels recreated and insect appears again
                    recreateLevel((unsigned)time.asMilliseconds());
                }
            }
            else
            {
                object.draw = false;
                // lose one life
                --lives;
            }

            // reset the buzzy to the beginning position
            buzzySprite.setPosition(smallBuzzy.getLocalBounds().width, 540.f);
            buzzySprite.setRotation(0.f);
            powerInner.setSize(sf::Vector2f(20.f, 30.f));
            scoreNum.setString(std::to_string(score));

            return true;
        }
    }

    // if buzzy leaves the screen
    float centerY = buzzySprite.getPosition().y - buzzySprite.getLocalBounds().height / 2.0f;
    float centerX = buzzySprite.getPosition().x - buzzySprite.getLocalBounds().width / 2.0f;
    if (centerX > 1920.f || centerX < 0.f || centerY < 0.f || centerY > 1080.f)
    {
        lives--;
        // reset the buzzy to the beginning position
        buzzySprite.setPosition(smallBuzzy.getLocalBounds().width, 540.f);
        buzzySprite.setRotation(0.f);
        powerInner.setSize(sf::Vector2f(20.f, 30.f));
        scoreNum.setString(std::to_string(score));

        return true;
    }

    return false;
}

void Buzzy::randomFlying(sf::Time t, int before, float& beeVertical)
{
    int time = (int) t.asSeconds();
    std::random_device myRandomDevice;
    unsigned seed = myRandomDevice();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0,1);

    float x = buzzySprite.getPosition().x;
    float y = buzzySprite.getPosition().y;
    // move if the insect is inside the screen
    if (x > 0.f && y > 0.f && y < 1080.f)
    {
        if (before != time)
        {
            beeVertical = distribution(generator) ? -0.05f : 0.1f;
        }
        buzzySprite.move(-0.2f, beeVertical);
    }
    // make it disappear if it is no more inside the screen
    else
    {
        spriteVec[INSECT].draw = false;
        spriteVec[INSECT].obj->setPosition(sf::Vector2<float>(1825.f, 200.f));
    }

    return;
}
