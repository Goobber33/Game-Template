#include <SFML/Graphics.hpp>

void startGame() {
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "My Game - Opening Screen");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/background.jpg")) {
    }
    sf::Sprite background(backgroundTexture);

    sf::Font font;
    if (!font.loadFromFile("assets/Roboto-Bold.ttf")) {
    }
    sf::Text title("My Game", font, 50);
    title.setPosition(200, 100);

    sf::Text prompt("Press Enter to start", font, 20);
    prompt.setPosition(200, 300);

    bool gameStarted = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                gameStarted = true;
                // Start the game or transition to the main game loop
            }
        }

        window.clear();
        if (!gameStarted) {
            // If game hasn't started, show the opening screen
            window.draw(background);
            window.draw(title);
            window.draw(prompt);
        } else {
            // The game has started, run the game loop
            startGame();  
        }
        window.display();
    }

    return 0;
}
