#pragma once

/// @brief
struct Primitive : Object {
    Primitive(QString value);
};

struct Sym : Primitive {
    Sym(QString value);
};
