

#include <Keyboard.hpp>
#include <iostream>

std::queue<int> Keyboard::stack;
// bool Keyboard::keys[5];
// memset(Keyboard::stack, 0, sizeof(key));

// void Keyboard::set_key(KEYS key, bool status)
// {
//     if(status)
//         Keyboard::stack.push(key);
// }

int Keyboard::get_key()
{
    if(!Keyboard::stack.empty())
    {
        int stack = Keyboard::stack.front();
        Keyboard::stack.pop();
        return stack;
    }
    return -1; 
}

// void Keyboard::set_key_status(KEYS key, bool status)
// {
//     Keyboard::keys[key] = status;
// }

void Keyboard::set_key(KEYS key)
{
    Keyboard::stack.push(key);
}

void Keyboard::draw()
{
    // std::cout << "\n" << keys[0] << " " << keys[1] << " " << keys[2] << " " << keys[3] << " " << keys[4];
    // std::queue<int> g = Keyboard::stack;
    // while(!g.empty())
    // {
    //     std::cout << '\t' << g.front();
    //     g.pop();
    // }
    // std::cout << '\n' << std::endl;
    // for(int i: Keyboard::stack)
    // {
    //     std::cout << i << " ";
    // }
}
