

#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <queue>

#include <Keys.h>

class Keyboard
{
    public:
        static std::queue<int> stack;
        // static bool keys[5];
        static int get_key();
        // static void set_key_status(KEYS key,bool status);
        static void set_key(KEYS key);
        static void draw();
};

#endif
