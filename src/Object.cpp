#include "gambox.hpp"

Object::Object() {
    ref = 0;
    next = pool;
    pool = this;
}

Object::~Object() {}

QString Object::tag() {
    return QString(abi::__cxa_demangle(typeid(*this).name(), 0, 0, nullptr))
        .toLower();
}
