#pragma once

#include <cxxabi.h>

#ifndef QT_CORE_LIB
#error
#endif

/// @defgroup object Object
/// @brief generic @ref ograph element
/// @{
struct Object {
    /// @name fields
    QString value;               /// scalar: object name, string/number value
    vector<Object*> nest;        /// vector: list = stack = nested AST
    map<QString, Object*> slot;  /// associative array: map = AST attributes

    /// @name garbage collector
    size_t ref;           /// ref counter
    static Object* pool;  /// global object pool /linked list/
    Object* next;         /// next item on @ref pool

    /// @name constructor
    Object();               /// construct with empty @ref value
    Object(QString value);  /// construct with name
    virtual ~Object();      /// clean up for nested elements

    /// @name dump/stringify
    virtual QString tag();
    virtual QString val();
    QString head(QString prefix = "");
    QString dump(size_t depth = 0, QString prefix = "");
};
/// @}
