#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "model.h"
#include "view.h"

int main(int argc, char **argv) {

    if (argc > 1)
    {
        View *v = nullptr;
        Model model;

        if (std::string(argv[1]) == "base")
            v = new TUIView(model);
        else
            v = new GUIView(model);

        v->draw();

        delete v;
    }

    return 0;
}
