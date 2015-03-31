#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

class Paddle
{
public:

	Paddle();
	Paddle( float x, float y );

	void Update();

	void loadTexture( std::string file );

	sf::Image   &getImage()        { return image; }
	sf::Texture &getTexture()	   { return texture; }
	sf::Sprite  &getSprite()       { return sprite; }
	
	sf::Vector2f getPrevPosition() { return prevPosition; }
	sf::Vector2f getCurrPosition() { return currPosition; }

private:

	sf::Image   image;
	sf::Texture texture;
	sf::Sprite  sprite;

	sf::Vector2f prevPosition;
	sf::Vector2f currPosition;
};

#endif  PADDLE_HPP