#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <sstream>
#include "Ball.hpp"
#include "Paddle.hpp"

class Game
{
public:

	Game();

	void Initialize();
	void Run();

	void GetInput( sf::Time delta );
	void Update( sf::Time delta );
	void Render();

private:

	sf::RenderWindow window;
	sf::Event		 ev;

	Paddle leftPaddle;
	Paddle rightPaddle;
	Ball   ball;

	std::stringstream leftScoreStream;
	std::stringstream rightScoreStream;

	sf::Font font;
	sf::Text leftScoreText;
	sf::Text rightScoreText;

	int leftScore;
	int rightScore;
};

#endif  GAME_HPP