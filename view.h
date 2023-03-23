#pragma once

#include <asm-generic/ioctls.h>
#include <cstddef>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <chrono>
#include <thread>

#include <sys/ioctl.h>
#include <SFML/Graphics.hpp>

#include "model.h"

const char default_char = '$';
const char snake_char = '*';
const char rabbits_char = '?';

const size_t default_timeout = 0;

class View {
protected:
    size_t width, height;
    Model model;

public:
    View(Model model_): model(model_) {};

    virtual void draw() = 0;
    virtual ~View() {};
};

class TUIView: public View {
    std::pair<unsigned, unsigned> getWindowSize()
    {
        winsize size = {};

        int status = ioctl(1, TIOCGWINSZ, &size);
        if (status == -1)
            perror("Cannot read window size");

        return {size.ws_col, size.ws_row};
    }

    void clearScreen() {
        std::fprintf(stderr, "\e[2J");
    }

    void draw() {
        drawHLine(1,      1,  width);
        drawHLine(1, height,  width);

        drawVLine(    1,  1, height);
        drawVLine(width,  1, height);

        drawSnake();
        drawRabbits();
    };

    void drawSnake() {
        for (auto cell: model.snake()) {
            putXY(cell.x(), cell.y(), snake_char);
        }
    }

    void drawRabbits() {
        for (auto cell: model.rabbits()) {
            putXY(cell.x(), cell.y(), rabbits_char);
        }
    }

    void putXY(size_t x, size_t y, char symb = default_char) {
        std::fprintf(stderr, "\e[%lu;%luH", y, x);
        std::fprintf(stderr, "%c", symb);
    }

    void drawVLine(size_t x, size_t y, size_t len, char symb = default_char) {
        for (size_t i = 0; i < len; i++) {
            assert(y + i <= height);
            assert(x <= width);

            std::fprintf(stderr, "\e[%lu;%luH", y + i, x);
            std::fprintf(stderr, "%c", symb);

            std::this_thread::sleep_for(std::chrono::milliseconds(default_timeout));
        }
    }

    void drawHLine(size_t x, size_t y, size_t len, char symb = default_char) {
        std::fprintf(stderr, "\e[%lu;%luH", y, x);

        for (size_t i = 0; i < len; i++) {
            std::fprintf(stderr, "%c", symb);
            std::this_thread::sleep_for(std::chrono::milliseconds(default_timeout));
        }
    }

 public:
    TUIView(Model model_): View(model_)
    {
        auto size = getWindowSize();
        width = size.first; height = size.second;

        std::fprintf(stderr, "\e7");

        clearScreen();
    }

    ~TUIView() {
        std::fprintf(stderr, "\n");
        std::fprintf(stderr, "\e8");
    }
};

class GUIView: public View {
    void draw() {
        sf::RenderWindow window(sf::VideoMode(1200, 900), "Snake GAME!");

        // sf::CircleShape shape(100.f);
        // shape.setFillColor(sf::Color::Green);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();

            drawRabbits(window);
            drawSnake();

            window.display();
        }

    //     drawHLine(1,      1,  width);
    //     drawHLine(1, height,  width);

    //     drawVLine(    1,  1, height);
    //     drawVLine(width,  1, height);

    //     drawSnake();
    };

    void drawRabbits(sf::RenderWindow &window) {
        for (auto cell: model.rabbits()) {
            rabbit_sprite.setPosition(40 * cell.x(), 30 * cell.y());
            window.draw(rabbit_sprite);
        }

        // rabbit_sprite.setPosition(cell.x(), cell.y());
        // window.draw(rabbit_sprite);
    }

    void drawSnake() {

    }

    sf::Texture rabbit_texture;
    sf::Sprite rabbit_sprite;

public:
    GUIView(Model model_): View(model_)
    {
        rabbit_texture.loadFromFile("cursed_rabbit.jpg");
        rabbit_sprite.setTexture(rabbit_texture);
    }

    ~GUIView() {}
};
