#pragma once

#include <asm-generic/ioctls.h>
#include <cstddef>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <chrono>
#include <thread>

#include <sys/ioctl.h>

const char default_char = '.';
const size_t default_timeout = 0;

class View {
public:
    size_t width, height;

public:
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

    void draw() {};

    void putXY(size_t x, size_t y, char symb = default_char) {
        std::fprintf(stderr, "\e[%lu;%luH", y, x);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        std::fprintf(stderr, "%c", symb);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    void putVerticalLine(size_t x, size_t y, size_t len, char symb = default_char) {
        for (size_t i = 0; i < len; i++) {
            assert(y + i <= height);
            assert(x <= width);

            std::fprintf(stderr, "\e[%lu;%luH", y + i, x);
            std::fprintf(stderr, "%c", symb);

            std::this_thread::sleep_for(std::chrono::milliseconds(default_timeout));
        }
    }

    void putHorizontalLine(size_t x, size_t y, size_t len, char symb = default_char) {
        std::fprintf(stderr, "\e[%lu;%luH", y, x);

        for (size_t i = 0; i < len; i++) {
            std::fprintf(stderr, "%c", symb);
            std::this_thread::sleep_for(std::chrono::milliseconds(default_timeout));
        }
    }

 public:
    TUIView()
    {
        auto size = getWindowSize();
        width = size.first; height = size.second;

        std::fprintf(stderr, "\e7");

        clearScreen();

        putHorizontalLine(1, 1, width);
        putHorizontalLine(1, height, width);

        putVerticalLine(1, 1, height);
        putVerticalLine(width, 1, height);
    }

    ~TUIView() {
        std::fprintf(stderr, "\n");
        std::fprintf(stderr, "\e8");
    }
};

class GUIView: public View {
    void draw() {
        std::cout << "not implemented" << std::endl;
    }

    ~GUIView() {}
};
