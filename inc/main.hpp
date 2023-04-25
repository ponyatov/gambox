#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <vector>
#include <map>
#include <stack>
using namespace std;

/// @brief print command line argument
extern void arg(int argc, char* argv);

/// @brief system initialize
extern void init(int& argc, char* argv[]);

/// @brief system finalize & exit
extern int fini(int err = 0);
