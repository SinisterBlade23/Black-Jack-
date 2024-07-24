#include "functions.h"
#include <iostream>
#include <random>

int PlayCard()
{
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution card{ 1, 10 };
    int drawnCard = card(mt);
    std::cout << "Drew a card: " << drawnCard << '\n';

    return drawnCard;
}

void PlayBlackjack()
{
    int playerTotal{ 0 };
    int dealerTotal{ 0 };
    char input{};

    // Player's turn
    while (true)
    {
        std::cout << "Your total is " << playerTotal << ". Do you want to draw a card (y/n)? ";
        std::cin >> input;

        if (input == 'y')
        {
            playerTotal += PlayCard();
            if (playerTotal > 21)
            {
                std::cout << "You busted with " << playerTotal << "!\n";
                return;
            }
        }
        else
        {
            break;
        }
    }

    // Dealer's turn (dealer draws until reaching 17)
    while (dealerTotal < 17)
    {
        dealerTotal += PlayCard();
    }

    std::cout << "Dealer's total is " << dealerTotal << ".\n";

    // Determine the winner
    if (dealerTotal > 21)
    {
        std::cout << "Dealer busted. You win!\n";
    }
    else if (playerTotal > dealerTotal)
    {
        std::cout << "You win with " << playerTotal << " against dealer's " << dealerTotal << "!\n";
    }
    else if (playerTotal < dealerTotal)
    {
        std::cout << "Dealer wins with " << dealerTotal << " against your " << playerTotal << ".\n";
    }
    else
    {
        std::cout << "It's a tie with both at " << playerTotal << "!\n";
    }
}
