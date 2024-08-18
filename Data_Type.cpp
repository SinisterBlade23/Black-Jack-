#include "functions.h"
#include <iostream>

int main()
{
    char input{};

    while (true)
    {
        std::cout << "Do you want to play Blackjack (y/n)? ";
        std::cin >> input;
        std::cout << '\n';

        if (input == 'y')
        {
            PlayBlackjack();
        }
        else
        {
            break;
        }
    }


    return 0;
}
