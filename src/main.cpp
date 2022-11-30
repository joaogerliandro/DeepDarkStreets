#include <game.h>

int main()
{
    DeepDarkStreets::Config config;

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Deep Dark Streets", sf::Style::Default, config.get_settings());

    DeepDarkStreets::Game main_game(window, config);

    main_game.run();

    return {};
}
