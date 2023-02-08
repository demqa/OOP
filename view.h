#pragma once

#include <iostream>

class View {
    int x,y;

public:
    virtual void draw() = 0;
    virtual ~View() {};
};

class TextView: public View {
    void draw() {
        std::cout << "hello, world!" << std::endl;
    }

    ~TextView() {}
};

class GuiView: public View {
    void draw() {
        std::cout << "not implemented" << std::endl;
    }

    ~GuiView() {}
};
