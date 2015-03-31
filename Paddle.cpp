#include "Paddle.hpp"

Paddle::Paddle() {}

Paddle::Paddle( float x, float y )
{
	prevPosition = sf::Vector2f( 0, 0 );
	currPosition = sf::Vector2f( x, y );

	sprite.setPosition( currPosition );
}


void Paddle::Update()
{
	prevPosition = currPosition;
	currPosition = sprite.getPosition();

	if ( sprite.getPosition().y < 0 )
	{
		currPosition = prevPosition;
		sprite.setPosition( currPosition );
	}

	if ( ( sprite.getPosition().y + texture.getSize().y ) > 800 )
	{
		currPosition = prevPosition;
		sprite.setPosition( currPosition );
	}
}

void Paddle::loadTexture( std::string file )
{
	image.loadFromFile( file.c_str() );
	image.createMaskFromColor( sf::Color( 255, 0, 255 ) );

	texture.loadFromImage( image );

	sprite.setTexture( texture );
}