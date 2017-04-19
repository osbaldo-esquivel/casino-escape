//Osbaldo Esquivel
// 15MAR2015

#include <iomanip>
#include "Room.h"
#include "Bathroom.h"
#include "BlackJack.h"
#include "Craps.h"
#include "Gym.h"
#include "Poker.h"
#include "Slot.h"
#include "SportsBar.h"
#include "Vault.h"
#include "Vip.h"
#include "Gift.h"
#include "Person.h"
#include "Dice.h"

int main()
{
	Person user; // create player object
	std::string userName; // hold user name
	Room *currRoom; // pointer to current location

    Bathroom *room1 = new Bathroom("BATHROOM"); // allocate new Bathroom object
    BlackJack *room2 = new BlackJack("BLACKJACK ROOM");
    Craps *room3 = new Craps("CRAPS ROOM");
    Gym *room4 = new Gym("GYM");
    Poker *room5 = new Poker("POKER ROOM");
    Slot *room6 = new Slot("SLOTS ROOM");
    SportsBar *room7 = new SportsBar("SPORTS BAR");
    Vault *room8 = new Vault("VAULT ROOM");
    Vip *room9 = new Vip("VIP ROOM");
    Gift *room10 = new Gift("GIFT SHOP");

    room1->setWest(room2); // set location of exit and next room
    room2->setSouth(room3);
    room3->setEast(room4);
    room4->setEast(room5);
    room5->setSouth(room6);
    room6->setEast(room7);
    room7->setSouth(room8);
    room8->setWest(room9);
    room9->setWest(room10);

	currRoom = room1; // set current location of user

	std::cout << "                    Casino Dash                     \n"
			  << "====================================================\n"
			  << "\nYou wake up in a bathroom with a beer in your hand\n"
			  << "and realize you have blacked out drunk. You look in\n"
			  << "your pocket and find a text message on your phone that\n"
			  << "says \"Hurry to the Gift Shop before I get arrested!\"\n"
			  << "\nYou reach into your pocket and find only $500 in your\n"
			  << "pocket. Make your way to the Gift Shop with any of your\n"
			  << "money or your friend will be arrested!" << std::endl;

	std::cout << "\nPlease enter your name: ";
	std::cin >> userName;

	user.setName(userName);

	std::cout << "\nYou'd better hurry up, " << user.getName() << ", or your"
			  << " friend may not make it!" << std::endl;

    std::cout << "\nDon't forget, you only have $" << std::fixed
              << std::setprecision(2) << user.getCash() << "!" << std::endl;

    std::cin.ignore();
    std::cout << "\nPress Enter to begin: ";
    std::cin.get();

    // loop until user runs out of money or reaches exit
    while(!currRoom->isExit())
    {
        char dir; // hold direction

        std::cout << std::string(50, '\n'); // clear screen

        currRoom->display(); // show exit and non-exits

        if(currRoom->getVal() == 1) // options for bathroom
        {
            int choice = 0;

            std::cout << "\nYou see a man standing in the corner.\n"
                      << "\t1. Talk to man\n"
                      << "\t2. Exit room\n"
                      << "Enter your choice: ";
            std::cin >> choice;

            switch(choice)
            {
                case 1: { std::cout << "\nYou had to give $100.00 to the"
                      << " bathroom attendant!" << std::endl;
                    user.removeCash(100.00); // remove cash from user
                    break;}
                case 2: { std::cout << "\nYou lose $50.00 for skipping this room!"
                    << std::endl;
                    user.removeCash(50.00);
                    break;}
                default: { std::cout << "\nThat's not a choice!" << std::endl;}
            }
            std::cout << "\nYou have $" << user.getCash() << " left."
                      << std::endl;
        }
        else if(currRoom->getVal() == 2) // options for blackjack room
        {
            int choice = 0;

            std::cout << "\nYou look around and see a single blackjack table\n"
                      << "\t1. Play blackjack\n"
                      << "\t2. Exit room\n"
                      << "Enter your choice: ";
            std::cin >> choice;

            switch(choice)
            {
                case 1: {
                int rollOne = 0, rollTwo = 0; // hold card values
                double wager = 0.00;
                Dice dieOne(21), dieTwo(21); // create dice objects

                std::cout << "\nHow much would you like to wager from your $"
                          << user.getCash() << ": $";
                std::cin >> wager;

                rollOne = dieOne.rollDice(); // roll first dice
                rollTwo = dieTwo.rollDice();

                std::cout << "\nThe dealer got a " << rollOne << "!\n"
                          << "You got a " << rollTwo << "!" << std::endl;

                if(rollOne > rollTwo)
                {
                    user.removeCash(wager); // if user loses
                }
                else if(rollOne == rollTwo)
                {
                    std::cout << "\nIt was a push! Exiting room...\n"; // if tie
                }
                else if(rollTwo == 21)
                {
                    user.addCash(wager * 1.5); // if blackjack
                }
                else if(rollOne < rollTwo && rollTwo != 21)
                {
                    user.addCash(wager); // user wins
                }

                std::cout << "\nYou now have $" << user.getCash() << std::endl;
                    break;}

                case 2: { std::cout << "\nYou lose $100.00 for skipping this"
                                    << " room!";
                            user.removeCash(100.00);
                            break;}
                default: { std::cout << "\nThat's not a choice!" << std::endl;}
            }
        }
        else if(currRoom->getVal() == 3) // options for craps room
        {
            int choice = 0;

            std::cout << "\nYou only see a single craps table in this room\n"
                      << "\t1. Play Craps\n"
                      << "\t2. Exit room \n"
                      << "Enter your choice: ";
            std::cin >> choice;

            switch(choice)
            {
                case 1: {
                int rollOne = 0; int rollTwo = 0, totalRoll = 0;
                double wager = 0.00;
                Dice dieOne(6), dieTwo(6);

                std::cout << "\nHow much would you like to wager from your $"
                          << user.getCash() << ": $";
                std::cin >> wager;

                rollOne = dieOne.rollDice();
                rollTwo = dieTwo.rollDice();

                totalRoll = rollOne + rollTwo; // sum of dice

                std::cout << "\nYou rolled a " << totalRoll << "!" << std::endl;

                if(totalRoll == 2 || totalRoll == 3 || totalRoll == 12)
                {
                    std::cout << "\nYou lose!" << std::endl;
                    user.removeCash(wager); // if user rolls 2, 3, 12 they lose
                }
                else if(totalRoll == 7 || totalRoll == 11)
                {
                    std::cout << "\nYou win!" << std::endl;
                }
                else
                {
                    std::cout << "\nYou didn't win or lose!" << std::endl;
                }

                std::cout << "\nYou now have $" << user.getCash() << std::endl;
                break;}
                case 2: { std::cout << "\nYou lose $150.00 for skipping this"
                                    << "room!";
                            user.removeCash(150.00);
                            break;}
                default: { std::cout << "\nThat's not a choice!" << std::endl;}
            }
        }
        else if(currRoom->getVal() == 4) // options for gym room
        {
            int choice = 0;

            std::cout << "\nYou see an old man with two dice in his hand:\n"
                      << "\t1. Approach man\n"
                      << "\t2. Exit room\n"
                      << "Enter your choice: ";
            std::cin >> choice;

            switch(choice)
            {
                case 1: {
                int randNum, pOne, pTwo;
                double wager;

                std::cout << "\nThe old man asks you for a random number between\n"
                          << "1 and 12: ";
                std::cin >> randNum;

                Dice dieOne(randNum), dieTwo(randNum);

                pOne = dieOne.rollDice();
                pTwo = dieTwo.rollDice();

                std::cout << "\nThe old man asks you to bet money on playing"
                          << " high-low\nwith him. You still have $" << user.getCash()
                          << ". Enter your wager: $";
                std::cin >> wager;

                std::cout << "\nYou rolled a " << pOne << "!"
                          << "\nThe old man rolled a " << pTwo << "!" << std::endl;

                std::cout << "\nYou now have $" << user.getCash() << " left."
                          << std::endl;

                break;}
                case 2: { std::cout << "\nYou lost $200.00 for skipping this level!";
                          user.removeCash(200.00);
                          break;}
                default: { std::cout << "\nThat's not a choice!" << std::endl;}
            }
        }
        else if(currRoom->getVal() == 5) // options for poker room
        {
            int choice = 0;
            int card1, card2, card3, card4, totOne, totTwo;
            double wager;
            Dice cardOne(14), cardTwo(14), cardThree(14), cardFour(14);

            std::cout << "\nYou see a single poker table in the center of the room:\n"
                      << "\t1. Play Poker\n"
                      << "\t2. Exit room\n"
                      << "Enter your choice: ";
            std::cin >> choice;

            switch(choice)
            {
                case 1: {
                std::cout << "\nYou have $" << user.getCash() << ". Enter your wager: $";
                std::cin >> wager;

                std::cout << "\nIn four-card poker, J = 11, Q = 12, K = 13, A = 14\n"
                          << "You are dealt two cards and the dealer gets two cards\n"
                          << "The sum of each hand determines the winner:"
                          << std::endl;

                card1 = cardOne.rollDice();
                card2 = cardTwo.rollDice();
                card3 = cardThree.rollDice();
                card4 = cardFour.rollDice();

                totOne = card1 + card2; // sum of two cards
                totTwo = card3 + card4;

                std::cout << "\nYou are dealt two cards: " << card1 << " "
                          << card2 << std::endl;

                std::cout << "\nThe dealer is dealt two cards: " << card3
                          << " " << card4 << std::endl;

                if(totOne > totTwo)
                {
                    std::cout << "\nYou win!" << std::endl;
                    user.addCash(wager);
                }
                else if(totOne == totTwo)
                {
                    std::cout << "\nIt was a tie!" << std::endl;
                }
                else if(totOne < totTwo)
                {
                    std::cout << "\nYou lose!" << std::endl;
                    user.removeCash(wager);
                }
                break;}
                case 2: { std::cout << "\nYou lose $" << user.getCash() << " for\n"
                                    << "skipping this level!" << std::endl;
                break;}
                default: { std::cout << "\nThat's not a choice!" << std::endl;}
            }
            std::cout << "\nYou have $" << user.getCash() << " left." << std::endl;
        }
        else if(currRoom->getVal() == 6) // options for slot room
        {
            int choice = 0, first, second, third;
            Dice rollOne(7), rollTwo(7), rollThree(7);

            first = rollOne.rollDice(); // generate three values
            second = rollTwo.rollDice();
            third = rollThree.rollDice();

            std::cout << "\nYou see a slot machine in the corner of this room:\n"
                      << "\t1. Play Slots\n"
                      << "\t2. Exit room\n"
                      << "Enter choice: ";
            std::cin >> choice;

            switch(choice)
            {
                case 1: {
                std::cout << "\nRoll any two similar numbers and win $100.00"
                          << " otherwise\nyou lose $150.00." << std::endl;

                std::cin.ignore();
                std::cout << "\nPress Enter to pull lever: ";
                std::cin.get();

                std::cout << "You have rolled: " << first << " " << second << " "
                          << third << std::endl;

                if((first == second || first == third) && (second == third))
                {
                    std::cout << "\nYou win!";
                    user.addCash(100.00); // if any two are the same user wins
                }
                else
                {
                    std::cout << "\nYou lose!";
                    user.removeCash(150.00);
                }
                break;}
                case 2: { std::cout << "\nYou lose $200.00 for skipping this room!";
                user.removeCash(200.00);
                break;}
                default: { std::cout << "\nThat's not a choice!" << std::endl;}
            }
            std::cout << "\nYou have $" << user.getCash() << " left." << std::endl;
        }
        else if(currRoom->getVal() == 7) // options for sports room
        {
            int choice = 0, padTotal, yankTotal;
            double wager;
            int uno, dos, tres, cuatro, cinco, seis, siete, ocho, nueve, dies;
            int once, doce, trese, catorse, quince, sixTeen, sevenTeen, eighTeen;
            Dice one(5), two(5), three(5), four(5), five(5), six(5), seven(5);
            Dice eight(5), nine(5), ten(5), eleven(5), twelve(5), thirteen(5);
            Dice fourteen(5), fifteen(5), sixteen(5), seventeen(5), eighteen(5);

            std::cout << "\nYou see a baseball game on TV. Padres vs Yankees:\n"
                      << "\t1. Sports bet\n"
                      << "\t2. Exit room\n"
                      << "Enter your choice: ";
            std::cin >> choice;

            switch(choice)
            {
                case 1: {
                    std::cout << "\nYou have $" <<  user.getCash() << ". Enter your wager\n"
                              << "that the Padres win: $";
                    std::cin >> wager;

                    uno = one.rollDice(); // generate inning scores
                    dos = two.rollDice();
                    tres = three.rollDice();
                    cuatro = four.rollDice();
                    cinco = five.rollDice();
                    seis = six.rollDice();
                    siete = seven.rollDice();
                    ocho = eight.rollDice();
                    nueve = nine.rollDice();
                    dies = ten.rollDice();
                    once = eleven.rollDice();
                    doce = twelve.rollDice();
                    trese = thirteen.rollDice();
                    catorse = fourteen.rollDice();
                    quince = fifteen.rollDice();
                    sixTeen = sixteen.rollDice();
                    sevenTeen = seventeen.rollDice();
                    eighTeen = eighteen.rollDice();

                    std::cout << "\nPadres: " << uno << " " << dos << " " << tres << " "
                              << cuatro << " " << cinco << " " << seis << " " << siete
                              << " " << ocho << " " << nueve << std::endl;
                    std::cout << "\nYankees: " << dies << " " << once << " " << doce
                              << " " << trese << " " << catorse << " " << quince << " "
                              << sixTeen << " " << sevenTeen << " " << eighTeen << std::endl;

                    padTotal = uno + dos + tres + cuatro + cinco + seis + siete + ocho + nueve;
                    yankTotal = dies + once + doce + trese + catorse + quince + sixTeen + sevenTeen
                                + eighTeen; // sum inning scores for total runs scored

                    if(padTotal > yankTotal)
                    {
                        std::cout << "\nYou have won!" << std::endl;
                        user.addCash(wager);
                    }
                    else if(padTotal == yankTotal)
                    {
                        std::cout << "\nIt was a tie!" << std::endl;
                    }
                    else if(padTotal < yankTotal)
                    {
                        std::cout << "\nYou have lost!" << std::endl;
                        user.removeCash(wager);
                    }
                    break;}
                case 2: {std::cout << "\nYou lose $200.00 for skipping this room!"
                                   << std::endl;
                          user.removeCash(200.00);
                          break;}
                default: {std::cout << "\nThat is not an option!" << std::endl;}
            }
            std::cout << "\nYou have $" << user.getCash() << " left." << std::endl;
        }
        else if(currRoom->getVal() == 8) // options for vault
        {
            int choice = 0;

            std::cout << "\nYou look around a see a drawer that is closed:\n"
                      << "\t1. Open drawer\n"
                      << "\t2. Exit room\n"
                      << "Enter your choice: ";
            std::cin >> choice;

            switch(choice)
            {
                case 1: {
                std::cout << "\nYou find $50.00!" << std::endl;
                user.addCash(50.00);
                break;}
                case 2: { std::cout << "\nYou lose $200.00 for skipping this room!"
                                    << std::endl;
                          user.removeCash(200.00);
                          break;}
                default: {std::cout << "\nThat is not an option!" << std::endl;}
            }
            std::cout << "\nYou have $" << user.getCash() << " left." << std::endl;
        }
        else if(currRoom->getVal() == 9) // options for VIP room
        {
            std::cout << "\nYou are charged $100.00 to enter the VIP room to dance!"
                      << std::endl;

            user.removeCash(100.00);

            std::cout << "\nYou have $" << user.getCash() << " left." << std::endl;
        }

        std::cout << "\nIn what direction would you like to head"
                  << " (N, S, E, W): "; // user selects direction to check
        std::cin >> dir;

        if(dir == 'N' || dir == 'n')
        {
            if(currRoom->getNorth() == NULL) // if pointer is NULL let user know
            {
                std::cout << "\nYou cannot go North!" << std::endl;
                std::cout << "\nStaying in this room." << std::endl;
            }
            else
            {
                currRoom = currRoom->getNorth();
            }
        }
        else if(dir == 'S' || dir == 's')
        {
            if(currRoom->getSouth() == NULL)
            {
                std::cout << "\nYou cannot go South!" << std::endl;
                std::cout << "\nStaying in this room." << std::endl;
            }
            else
                currRoom = currRoom->getSouth();
        }
        else if(dir == 'E' || dir == 'e')
        {
            if(currRoom->getEast() == NULL)
            {
                std::cout << "\nYou cannot go East!" << std::endl;
                std::cout << "\nStaying in this room." << std::endl;
            }
            else
                currRoom = currRoom->getEast();
        }
        else if(dir == 'W' || dir == 'w')
        {
            if(currRoom->getWest() == NULL)
            {
                std::cout << "\nYou cannot go West!" << std::endl;
                std::cout << "\nStaying in this room." << std::endl;
            }
            else
                currRoom = currRoom->getWest();
        }
        else
            std::cout << "\nThat is not a direction!" << std::endl;

        if(user.getCash() <= 0) // if user runs out of money end game
        {
            std::cout << "\nYou've run out of money and let your friend\n"
                      << "go to jail. Good job!" << std::endl;

            return 0;
        }
    }

    // if user makes it to room 10 with any money they win
    std::cout << "\nYou found your friend in the gift shop about to"
              << " be arrested\nbut you manage to convince the"
              << " security guard with a couple bucks to let them go. Congrats!" << std::endl;

    std::cout << "\nYou ended with $" << std::fixed << std::setprecision(2)
              << user.getCash() << "." << std::endl;

	return 0;
}
