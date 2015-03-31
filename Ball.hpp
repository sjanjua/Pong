#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

class Ball
{
public:

	Ball();
	Ball( float x, float y );

	void Update( sf::Time delta );

	void loadTexture( std::string file );

	void setVelocity( float x, float y ) { velocity.x = x; velocity.y = y; }

	sf::Image   &getImage()        { return image; }
	sf::Texture &getTexture()      { return texture; }
	sf::Sprite  &getSprite()       { return sprite; }
	sf::Vector2f getPrevPosition() { return prevPosition; }
	sf::Vector2f getCurrPosition() { return currPosition; }
	sf::Vector2f getVelocity()     { return velocity; }

private:

	sf::Image   image;
	sf::Texture texture;
	sf::Sprite  sprite;

	sf::Vector2f prevPosition;
	sf::Vector2f currPosition;

	sf::Vector2f velocity;
};

#endif  BALL_HPP