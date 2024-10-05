#include "screenSaver.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cmath>

//Self-explanatory
ScreenSaver::ScreenSaver() {
  shape = sf::CircleShape(10.f);
  velocity = sf::Vector2f(0.0f, 0.0f);
  shape.setFillColor(sf::Color::White);
}

//Self-explanatory
ScreenSaver::ScreenSaver(float radius, sf::Vector2f cVelocity, sf::Color color) {
  shape = sf::CircleShape(radius);
  velocity = cVelocity;
  shape.setFillColor(color);
}

//We have to return shape as a reference!
sf::CircleShape &ScreenSaver::getShape() { return shape; }

//this will draw the sf::CircleShape member of ScreenSaver to the screen
//this will be inherited by all derived class, and shouldn't have to be overriden
void ScreenSaver::draw(sf::RenderWindow &window) { window.draw(getShape()); }

/*Here's some nifty code to resolve any collsions with a wall, by reversing
the velocity of the object to mimic bouncing, you can call this function
in your update functions to make sure your ScreenSaver doesn't wander off-screen*/
void ScreenSaver::checkWallCollision(int screenWidth, int screenHeight){
  sf::Vector2f position = getShape().getPosition();
  float diameter = getShape().getRadius() * 2;

  // Check if the circle hits the right wall
  if (position.x + diameter > screenWidth)
  {
    getShape().setPosition(screenWidth - diameter, position.y);
    velocity.x *= -1.f;
  }

  // Check if the circle hits the left wall
  if (position.x < 0)
  {
    getShape().setPosition(0, position.y);
    velocity.x *= -1.f;
  }

  // Check if the circle hits the top wall
  if (position.y < 0)
  {
    getShape().setPosition(position.x, 0);
    velocity.y *= -1.f;
  }

  // Check if the circle hits the bottom wall
  if (position.y + diameter > screenHeight)
  {
    getShape().setPosition(position.x, screenHeight - diameter);
    velocity.y *= -1.f;
  }
}


//TODO Define all necessary member functions for ClassicSaver, ColorChangingSaver, and CustomSaver Here
// Constructor for ClassicSaver

ClassicSaver::ClassicSaver(float radius, sf::Vector2f velocity, sf::Color color)
    : ScreenSaver(radius, velocity, color) {
    // Initial setup can be done in the constructor
}


/*----------------------------------------------------------------------------------
 * Function : update() Override update method for ClassicSaver
 * Usage    : update(deltaTime, screenWidth, screenHeight)
 * ---------------------------------------------------------------------------
 * This function moves the shape based on its velocity scaled by deltaTime for smooth, 
 * frame-independent movement. 
 * Check for wall collisions to reverse velocity as needed, ensuring the saver bounces 
 * off window edges.
*------------------------------------------------------------------------------------*/
void ClassicSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    getShape().move(velocity.x * deltaTime, velocity.y * deltaTime);
    checkWallCollision(screenWidth, screenHeight);
}

// Constructor for ColorChangingSaver
ColorChangingSaver::ColorChangingSaver(float radius, sf::Vector2f velocity, float colorSpeed)
    : ClassicSaver(radius, velocity, sf::Color::White), colorSpeed(colorSpeed), colorPhase(0.f) {
    // No additional setup required, using the base class constructor
}

/*----------------------------------------------------------------------------------
 * Function : update() Override update method for ColorChangingSaver
 * Usage    : update(deltaTime, screenWidth, screenHeight)
 * ---------------------------------------------------------------------------
 * This function calls the ClassicSaver's update method to manage movement and wall 
 * collisions, then cycles through colors smoothly using a sine function based on 
 * colorPhase, which is updated by colorSpeed and deltaTime. 
 * The colorPhase is normalized to stay within the range of 0 to 1, allowing for 
 * continuous RGB transitions, creating a rainbow effect.
 *------------------------------------------------------------------------------------*/
void ColorChangingSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    ClassicSaver::update(deltaTime, screenWidth, screenHeight);
    colorPhase += colorSpeed * deltaTime * 0.001f;  // Adjust colorSpeed factor for smoother transition
    if (colorPhase > 1.0f) colorPhase -= 1.0f; // Normalize the colorPhase to stay within the range of 0 to 1
    sf::Uint8 red = static_cast<sf::Uint8>(std::sin(2.0f * 3.14159f * (colorPhase + 0.0f / 3.0f)) * 127 + 128);
    sf::Uint8 green = static_cast<sf::Uint8>(std::sin(2.0f * 3.14159f * (colorPhase + 1.0f / 3.0f)) * 127 + 128);
    sf::Uint8 blue = static_cast<sf::Uint8>(std::sin(2.0f * 3.14159f * (colorPhase + 2.0f / 3.0f)) * 127 + 128);
    getShape().setFillColor(sf::Color(red, green, blue)); // Set the new color to the shape
}


// Constructor for CustomSaver
CustomSaver::CustomSaver(float radius, sf::Vector2f velocity, float sizeChangeRate)
    : ScreenSaver(radius, velocity, sf::Color::Cyan), // Initialize with a starting color
      radius(radius), sizeChangeRate(sizeChangeRate), currentAngle(0.0f), minSize(10.0f), maxSize(50.0f) {
    // Set the initial size of the shape
    getShape().setRadius(minSize);
}

/*----------------------------------------------------------------------------------
 * Function : update() Override update method for CustomSaver
 * Usage    : update(deltaTime, screenWidth, screenHeight)
 * ---------------------------------------------------------------------------
 * This function updates the position of the shape to move in a circular path, 
 * calculated using trigonometric equations based on the current angle.
 * It also smoothly changes the size of the shape between minSize and maxSize 
 * using a sine function for a dynamic visual effect.
 *------------------------------------------------------------------------------------*/
void CustomSaver::update(float deltaTime, int screenWidth, int screenHeight) {
    currentAngle += velocity.x * deltaTime * 0.001f; // Scale the movement by deltaTime for smoothness
    float x = screenWidth / 2 + radius * std::cos(currentAngle); // Circular X position
    float y = screenHeight / 2 + radius * std::sin(currentAngle); // Circular Y position

    getShape().setPosition(x, y); // Update the shape's position

    float newSize = minSize + (maxSize - minSize) * (0.5f + 0.5f * std::sin(currentAngle)); // Change size smoothly between minSize and maxSize
    getShape().setRadius(newSize);
}
