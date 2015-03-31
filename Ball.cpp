#include "Ball.hpp"

Ball::Ball() {}

Ball::Ball( float x, float y )
{
	prevPosition = sf::Vector2f( 0, 0 );
	currPosition = sf::Vector2f( x, y );

	velocity = sf::Vector2f( -300.0f, -300.0f );

	sprite.setPosition( currPosition );
}

void Ball::Update( sf::Time delta )
{
	sprite.move( velocity * delta.asSeconds() );

	if ( sprite.getPosition().y <= 0 )
	{

		velocity.y = -velocity.y;
	}

	if ( ( sprite.getPosition().y + texture.getSize().y ) >= 800 )
	{
		velocity.y = -velocity.y;
	}
}

void Ball::loadTexture( std::string file )
{
	image.loadFromFile( file.c_str() );
	image.createMaskFromColor( sf::Color( 255, 0, 255 ) );

	texture.loadFromImage( image );

	sprite.setTexture( texture );
}