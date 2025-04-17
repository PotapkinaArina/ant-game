#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <filesystem>
#include "Anthill.h"
#include "EnemyGroup.h"
#include "Button.h"
#include "Ant.h"

// Constants
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 700;
const int GRID_SIZE = 15;
const int CELL_SIZE = 40;

// Function to clear the screen (SFML doesn't need this, but I'm keeping it for consistency)
void clearScreen() {}

// Function to draw the anthill grid using SFML
void drawAnthillGrid(sf::RenderWindow& window, Anthill& anthill) {
    int gridSize = anthill.sizeCheck();

    // Draw grid cells
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            cell.setPosition(j * CELL_SIZE, i * CELL_SIZE);
            cell.setFillColor(sf::Color(100, 150, 100)); // A nicer green
            window.draw(cell);
        }
    }

    // Place ants on the grid
    auto liveAnts = anthill.getLiveAnts();
    int antCount = 0; // To track ant placement

    for (Ant* ant : liveAnts) {
        int x = ant->getX();
        int y = ant->getY();

        if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
            // Calculate grid position for structured layout
            int gridX = antCount % GRID_SIZE;
            int gridY = antCount / GRID_SIZE;

            sf::RectangleShape antShape(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            antShape.setPosition(gridX * CELL_SIZE, gridY * CELL_SIZE); // Use calculated grid position

            // Determine color based on role
            switch (ant->getCurrentRoleIndex()) {
            case 0: antShape.setFillColor(sf::Color::White); break;     // Baby
            case 1: antShape.setFillColor(sf::Color::Cyan); break;    // Nanny
            case 2: antShape.setFillColor(sf::Color::Green); break;  // Soldier
            case 3: antShape.setFillColor(sf::Color::Red); break; // Shepherd
            case 4: antShape.setFillColor(sf::Color(148, 0, 211)); break;    // Gatherer (Сиреневый)
            case 5: antShape.setFillColor(sf::Color(139, 69, 19)); break;   // Builder (Коричневый)
            case 6: antShape.setFillColor(sf::Color(255, 165, 0)); break;   // Cleaner (Оранжевый)
            default: antShape.setFillColor(sf::Color::Green); break;   // Default
            }

            window.draw(antShape);
            antCount++; // Increment ant count
        }
    }
}

// Function to draw anthill information using SFML
void drawAnthillInfo(sf::RenderWindow& window, Anthill& anthill, int year) {
    sf::Font font;
    std::string fontPath = "C:/Users/anans/Desktop/Ants/x64/Debug/arial.ttf";

    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Failed to load font from path: " << fontPath << std::endl;
        std::cerr << "Current working directory: " << std::filesystem::current_path() << std::endl;
        return;
    }

    std::stringstream ss;
    ss << "Year: " << year << "\n"
        << "Ants: " << anthill.getLiveAnts().size() << "\n"
        << "Food: " << anthill.eatCheck() << "\n"
        << "Wood: " << anthill.branchesCheck() << "\n"
        << "Aphids: " << anthill.aphidCheck() << "\n"
        << "Garbage: " << anthill.garbageCheck() << "\n"
        << "------------------------\n"
        << anthill.getEventMessage();

    sf::Text text(ss.str(), font, 20);
    text.setFillColor(sf::Color::White);
    text.setPosition(GRID_SIZE * CELL_SIZE + 20, 20);
    window.draw(text);
}
// Function to draw enemies (visual implementation)
void drawEnemies(sf::RenderWindow& window) {
    sf::CircleShape enemy(20);
    enemy.setFillColor(sf::Color::Black);
    enemy.setPosition(400, 100);
    window.draw(enemy);

}

// Function to apply fire damage to the anthill
void applyFire(Anthill& anthill)
{
    int damage = rand() % 2 + 1;
    anthill.aphidMinus(damage);
    anthill.eatMinus(damage * 2);
    anthill.branchMinus(damage);
    anthill.sizeMinus(damage);

    auto liveAnts = anthill.getLiveAnts();
    for (Ant* ant : liveAnts) {
        ant->healthMinus(10);
    }

}
void enemiesAttack(Anthill& anthill) {
    // Логика набега врагов (можете адаптировать из старого кода)
    //  Например: уменьшение ресурсов, здоровья муравьев, и т.д.
    int damage = rand() % 5 + 1;
    anthill.aphidMinus(damage);
    anthill.eatMinus(damage * 3);
    anthill.branchMinus(damage);
    anthill.sizeMinus(damage);
    auto liveAnts = anthill.getLiveAnts();
    for (Ant* ant : liveAnts) {
        int damageAnt = rand() % 10;
        ant->healthMinus(damageAnt);
    }
}
// Function to draw fire (visual implementation)
void drawFire(sf::RenderWindow& window) {
    sf::CircleShape fire(20);
    fire.setFillColor(sf::Color::Red);
    fire.setPosition(300, 100);
    window.draw(fire);

}

int main() {
    srand(time(0));

    Anthill anthill;
    int year = 1;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ant Game");
    window.setFramerateLimit(60);

    // Load font
    sf::Font font;
    std::string fontPath = "C:/Users/anans/Desktop/Ants/x64/Debug/arial.ttf";
    if (!font.loadFromFile(fontPath)) {
        std::cerr << "Failed to load font arial.ttf\n";
        return -1;
    }

    // Load background texture
    sf::Texture backgroundTexture;

    sf::Texture stormTexture;
    if (!stormTexture.loadFromFile("C:/Users/anans/Desktop/Ants/x64/Debug/storm.png")) {
        std::cerr << "Failed to load storm.png\n";
        return -1;
    }
    sf::Sprite stormSprite(stormTexture);
    stormSprite.setPosition(100, 100);
    stormSprite.setColor(sf::Color(255, 255, 255, 128));

    // Load fire texture
    sf::Texture fireTexture;
    if (!fireTexture.loadFromFile("C:/Users/anans/Desktop/Ants/x64/Debug/fire.png")) {
        std::cerr << "Failed to load fire.png\n";
        return -1;
    }
    sf::Sprite fireSprite(fireTexture);
    fireSprite.setPosition(100, 100);
    fireSprite.setColor(sf::Color(255, 255, 255, 128));

    // Create Button
    Button nextYearButton(
        GRID_SIZE * CELL_SIZE + 20, 500, 150, 50,
        &font, "Next Year",
        sf::Color(70, 70, 70), sf::Color(150, 150, 150), sf::Color(20, 20, 20)
    );

    bool nextYearClicked = false;
    bool fireEvent = false;
    int enemyDisplayTime = 0;
    bool stormEvent = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Draw background


        drawAnthillGrid(window, anthill);
        drawAnthillInfo(window, anthill, year);
        // Draw fire if event occurred
        if (fireEvent) {
            window.draw(fireSprite);
        }
        if (stormEvent) {
            window.draw(stormSprite);
        }
        // Draw enemies if attack occurs
        if (anthill.getShowEnemies() && enemyDisplayTime > 0) {
            drawEnemies(window);
            enemyDisplayTime--; // Уменьшаем время отображения врагов
        }
        else {
            anthill.setShowEnemies(false);
        }

        // Update and render button
        nextYearButton.update(sf::Mouse::getPosition(window));
        nextYearButton.render(&window);

        window.display();
        if (anthill.getLiveAnts().size() == 0) {
            anthill.addEventMessage("Game Over! All ants are dead.");
            drawAnthillInfo(window, anthill, year);
            window.display();
            sf::sleep(sf::seconds(60)); // Подождем 60 секунд, чтобы игрок успел прочитать сообщение
            window.close();
            break; // Завершаем основной цикл
        }

        // Button click logic
        if (nextYearButton.isPressed() && !nextYearClicked) {
            stormEvent = false;
            fireEvent = false; // Reset fire event

            // Generate random event message
            int randomEvent = rand() % 6;
            switch (randomEvent) {
            case 0:
                anthill.addEventMessage("Aphids ate some crops.");
                anthill.setShowEnemies(true);
                enemyDisplayTime = 5;
                enemiesAttack(anthill);
                break;
            case 1:
                anthill.addEventMessage("Found a new source of food.");
                anthill.performWork();
                break;
            case 2:
                anthill.addEventMessage("A storm destroyed some branches.");
                stormEvent = true;
                anthill.performWork();
                break;
            case 3:
                anthill.addEventMessage("A new baby ant was born.");
                anthill.performWork();
                break;
            case 4:
                anthill.addEventMessage("Nothing happened this year.");
                anthill.performWork();
                break;
            case 5:
                anthill.addEventMessage("Fire broke out in the anthill!");
                fireEvent = true;
                applyFire(anthill);
                anthill.performWork();
                break;
            default:
                anthill.addEventMessage("Unknown event.");
                anthill.performWork();
                break;
            }
            if (randomEvent % 7 == 0) {
                anthill.setShowEnemies(true);

            }
            else {
                anthill.setShowEnemies(false);
            }

            year++;
            nextYearClicked = true;
        }
        else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            nextYearClicked = false;
        }
    }

    return 0;
}