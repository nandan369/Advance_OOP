#ifndef screenSaver_h
#define screenSaver_h

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

//The Parent Class!
class ScreenSaver {
private:
  //this is the object that will be drawn on the screen
  //IMPORTANT: check out the documentation for sf::CircleShape in order to understand how to use this.
  sf::CircleShape shape;

public:
  //Constructors
  ScreenSaver();
  ScreenSaver(float radius, sf::Vector2f cVelocity, sf::Color color);
  
  //public member variable
  sf::Vector2f velocity;

  //Getter for shape
  sf::CircleShape &getShape();

  //nifty function, see screenSaver.cpp for more details
  void checkWallCollision(int screenWidth, int screenHeight);

  /*This is the most important function!
      It is a pure virtual function, meaning that it MUST be overriden by child classes
      Every child class will have it's own definition for this function*/
  virtual void update(float deltaTime, int screenWidth, int screenHeight) = 0;
  
  //See screenSaver.cpp for details
  void draw(sf::RenderWindow &window);

  //All parent classes should have a deconstructor, even if it is empty
  virtual ~ScreenSaver() {} 
};

//TODO Define the ClassicSaver class as a child class of ScreenSaver
//  Define the Constructor ClassicSaver(float radius, sf::Vector2f velocity, sf::Color color)
//  override the update function from ScreenSaver, and define the intended functionality

class ClassicSaver : public ScreenSaver {
public:
    // Constructor
    ClassicSaver(float radius, sf::Vector2f velocity, sf::Color color);

    // Override the update function
    void update(float deltaTime, int screenWidth, int screenHeight) override;
};


//TODO Define the ColorChangingSaver class as a child class of ClassicSaver (Multiple Inheritance)
//  Define the Constructor ColorChangingSaver(float radius, sf::Vector2f velocity, float colorSpeed)
//  override the update function from ClassicSaver, and define the intended functionality

class ColorChangingSaver : public ClassicSaver {
private:
    float colorSpeed;  // Speed of color transition
    float colorPhase;  // A variable to track color cycling phase

public:
    // Constructor
    ColorChangingSaver(float radius, sf::Vector2f velocity, float colorSpeed);

    // Override the update function to add color changing behavior
    void update(float deltaTime, int screenWidth, int screenHeight) override;
};


//TODO Define the CustomSaver class as a child class of ScreenSaver
//  Define the Constructor CustomSaver(float someFloat, sf::Vector2f someVector, float someOtherFloat)
//    NOTE: Since the behavior of this class is up to you, the way you use these parameters in the constructor is up to you.
// CustomSaver class represents a screensaver that moves in a circular path while changing its size.
// The radius of the circle and the speed of the size change can be controlled via the constructor parameters.

class CustomSaver : public ScreenSaver {
private:
    float radius;           // Radius of the circular path
    float sizeChangeRate;   // Rate at which the size changes
    float currentAngle;     // Current angle for circular movement
    float minSize;          // Minimum size of the shape
    float maxSize;          // Maximum size of the shape

public:
    // Constructor
    CustomSaver(float radius, sf::Vector2f velocity, float sizeChangeRate);

    // Override the update function to implement circular movement and size change
    void update(float deltaTime, int screenWidth, int screenHeight) override;
};

#endif
