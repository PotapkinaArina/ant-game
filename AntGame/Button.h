#pragma once
#include <SFML/Graphics.hpp>

enum ButtonState {
    BTN_IDLE = 0,
    BTN_HOVER,
    BTN_ACTIVE,
    BTN_DISABLED
};

class Button {
public:
    Button(float x, float y, float width, float height,
        sf::Font* font, std::string text,
        sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    ~Button();

    //Accessors
    bool isPressed() const;

    //Functions
    void update(const sf::Vector2i& mousePos);
    void render(sf::RenderTarget* target);

private:
    short int buttonState;
    sf::RectangleShape shape;
    sf::Font* font;
    sf::Text text;
    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
};