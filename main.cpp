#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "view.h"

void some();

int main(int argc, char **argv) {

    if (argc > 1)
    {
        View *v = nullptr;

        if (std::string(argv[1]) == "base")
            v = new TUIView;
        else
            v = new GUIView;

        v->draw();
        delete v;
    }

    return 0;
}
