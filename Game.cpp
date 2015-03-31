#include "Game.hpp"

Game::Game() {}

void Game::Initialize()
{
	window.create( sf::VideoMode( 1880, 800 ), "Pong" );

	leftPaddle = Paddle( 0, ( window.getSize().y / 2 ) );
	leftPaddle.loadTexture( "Resources/LeftPaddle.png" );

	rightPaddle = Paddle( ( window.getSize().x - 25 ), ( window.getSize().y / 2 ) );
	rightPaddle.loadTexture( "Resources/RightPaddle.png" );

	ball = Ball( window.getSize().x / 2, window.getSize().y / 2 );
	ball.loadTexture( "Resources/Ball.png" );

	font.loadFromFile( "Resources/ARCADE.ttf" );

	leftScoreText.setFont( font );
	leftScoreText.setCharacterSize( 60 );
	leftScoreText.setPosition( ( window.getSize().x / 2 ) - 200, 10 );
	leftScoreText.setColor( sf::Color( 0, 215, 255 ) );

	rightScoreText.setFont( font );
	rightScoreText.setCharacterSize( 60 );
	rightScoreText.setPosition( ( window.getSize().x / 2 ) + 140, 10 );
	rightScoreText.setColor( sf::Color( 100, 255, 150 ) );

	leftScore  = 0;
	rightScore = 0;
}

void Game::Run()
{
	sf::Clock clock;

	while ( window.isOpen() )
	{
		while ( window.pollEvent( ev ) )
		{
			if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
			{
				window.close();
			}

			if ( ev.type == sf::Event::Closed )
			{
				window.close();
			}
		}

		sf::Time elapsed = clock.restart();

		Update( elapsed );
		Render();
	}
}

void Game::GetInput( sf::Time delta )
{
	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )
	{
		leftPaddle.getSprite().move( 0.0f, -300.0f * delta.asSeconds() );
	}

	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::S ) )
	{
		leftPaddle.getSprite().move( 0.0f, 300.0f * delta.asSeconds() );
	}

	if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )
	{
		rightPaddle.getSprite().move( 0.0f, -300.0f * delta.asSeconds() );
	}

	else if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) )
	{
		rightPaddle.getSprite().move( 0.0f, 300.0f * delta.asSeconds() );
	}
}

void Game::Update( sf::Time delta )
{
	GetInput( delta );

	leftPaddle.Update();
	rightPaddle.Update();
	ball.Update( delta );

	if ( ball.getSprite().getGlobalBounds().intersects( leftPaddle.getSprite().getGlobalBounds() ) )
	{
		ball.setVelocity( -ball.getVelocity().x * 1.10f, ball.getVelocity().y );
	}

	if ( ball.getSprite().getGlobalBounds().intersects( rightPaddle.getSprite().getGlobalBounds() ) )
	{
		ball.setVelocity( -ball.getVelocity().x * 1.10f, ball.getVelocity().y );
	}

	if ( ball.getSprite().getPosition().x <= 0 )
	{
		ball.getSprite().setPosition( ( window.getSize().x / 2 ), ( window.getSize().y / 2 ) );
		ball.setVelocity( -300.0f, -300.0f );

		rightScore++;
	}

	if ( ball.getSprite().getPosition().x >= 5760 )
	{
		ball.getSprite().setPosition( ( window.getSize().x / 2 ), ( window.getSize().y / 2 ) );
		ball.setVelocity( 300.0f, 300.0f );

		leftScore++;
	}

	leftScoreStream << leftScore;
	std::string leftScoreBuffer = leftScoreStream.str();
	leftScoreText.setString( leftScoreBuffer.c_str() );
	leftScoreStream.str( std::string() );

	rightScoreStream << rightScore;
	std::string rightScoreBuffer = rightScoreStream.str();
	rightScoreText.setString( rightScoreBuffer.c_str() );
	rightScoreStream.str( std::string() );
}

void Game::Render()
{
	window.clear();
	window.draw( leftPaddle.getSprite() );
	window.draw( rightPaddle.getSprite() );
	window.draw( ball.getSprite() );
	window.draw( leftScoreText );
	window.draw( rightScoreText );
	window.display();
}