//
// Created by 김갑현 on 2021/10/20.
//
#include "Buzzy.h"
#include <cmath>

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
void Buzzy::checkCollision()
{

}