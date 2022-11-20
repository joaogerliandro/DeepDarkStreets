#include <game.h>

int main()
{
    DeepDarkStreets::Config config;

    sf::Window window(sf::VideoMode::getDesktopMode(), "Deep Dark Streets", sf::Style::Close, config.get_settings());

    DeepDarkStreets::Game main_game(window, config);

    main_game.run();

    return {};
}
