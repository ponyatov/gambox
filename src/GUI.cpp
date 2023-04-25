#include "gambox.hpp"

GUI* GUI::gui = nullptr;

App* GUI::app = nullptr;

Window* GUI::wMain = nullptr;

GUI::GUI() : Object() {
    assert(!app);
    assert(app = new App());
}
