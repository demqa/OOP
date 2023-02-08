#include <iostream>
#include "view.h"

int main(int argc, char **argv) {

    if (argc > 1)
    {
        View *v;
        if (std::string(argv[1]) == "base")
        {
            v = new TextView;
        }
        else
        {
            v = new GuiView;
        }
        v->draw();
        delete v;
    }

    return 0;
}
