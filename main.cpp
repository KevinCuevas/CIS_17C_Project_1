/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kevin Cuevas
 *
 * Created on April 6, 2021, 8:59 AM
 */

#include <cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include "Cards.h"
using namespace std;

int playerCounter = 0;// Counts element position in playerDeck vector, reset when deck is shuffled 
int botCounter = 0;//Does the same thing as playerCounter but for botDeck vector.
int roundNum = 1;//Keep track number of rounds in the game

//Functions
int randomNum(int);

void war(vector<Cards> &, vector<Cards> &, vector<Cards> &, vector<Cards> &);//When draw war

void Maingame(vector<Cards> &, vector<Cards> &, vector<Cards> &, vector<Cards> &);//Start the game

int main()
{
    srand (unsigned(time(0)));
    char choice = 'y';//To start or end the game 
    
    cardObj.createdCards();
    
    //52 cards
    vector<Cards>deck = { Card0, Card1, Card2, Card3, Card4, Card5, Card6, Card7, Card8, Card9,
    Card10, Card11, Card12, Card13, Card14, Card15, Card16, Card17, Card18, Card19, Card20,
    Card21, Card22, Card23, Card24, Card25, Card26, Card27, Card28, Card29, Card30, Card31,
    Card32, Card33, Card34, Card35, Card36, Card37, Card38, Card39, Card40, Card41, Card42,
    Card43, Card44, Card45, Card46, Card47, Card48, Card49, Card50, Card51 };
   
    vector<Cards> playerDeck;
    vector<Cards> BotDeck;
    vector<Cards>gainedPlayerDeck;
    vector<Cards>gainedBotDeck;
    
    random_shuffle(deck.begin(), deck.end(), randomNum);// shuffles the deck
    
    while(true)// distributes the deck in half to the two players
    {
        for(int i=0;i<26;i++)//gives 26 cards the playerDeck
        {
            playerDeck.insert(playerDeck.end(), deck[i]);
        }
        deck.erase(deck.begin(), deck.begin() + 26);
        
        for(int i=0;i<26;i++)
        {
            BotDeck.insert(BotDeck.end(), deck[i]);
        }
        deck.erase(deck.begin(),deck.begin() + 26);
        
        break;
    }
    
    while(true) //Menu of the game to start the game or not
    {
        cout << "War Card Game" << endl;
        cout << "Ready to play? (y/n): ";
        cin >> choice;
        
        while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');//If user doesn't enter y or n
        {
            cout << "Please enter y or n: ";
            cin >> choice;
        }
        cout << endl;
        
        while(choice == 'y' || choice == 'Y' || choice == 'a' || choice == 'A')
        {
            Maingame(playerDeck, BotDeck, gainedPlayerDeck, gainedBotDeck);
            
            if(playerDeck.size() + gainedPlayerDeck.size() <= 0)//Player loses
            {
                cout << "\nplayer has lost the game!";
                break;
            }
            
            else if(BotDeck.size() + gainedBotDeck.size() <= 0)//Bot loses
            {
                cout <<"\nBot has lost the game!";
                break;
            }
            
            if(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
            {
                cout << "Play Again? (y/n or a (autoplay): ";
                cin >> choice;
                while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N' && choice != 'a' && choice != 'A')
                {
                    cout << "Please enter y, n, or a: ";
                    cin >> choice;
                }
            }
            cout << endl;
        }
        break;
    }
    return 0;
}

int randomNum(int i){
    return rand()%i;
}
void Maingame(vector<Cards> &x, vector<Cards> &y, vector<Cards> &j, vector<Cards> &k)//main game, vector x and j represent the player deck and vector y and k represent the bot deck
{
    cout << "   Round #" << roundNum << endl;
    cout << "Player Cards " << x.size() + j.size() << "/" << y.size() + k.size() << " Bot Cards" << endl << endl;
    
    if(playerCounter >= x.size())
    {
        for(int i=0;i<j.size();i++)// add cards from gainedPlayer to playerDeck
        {
            x.insert(x.end(), j[i]);
        }
        j.erase(j.begin(),j.begin() + j.size());//erase elements from gainedPlayerDeck after a shuffle
        random_shuffle(x.begin(), x.end(), randomNum);
        cout << " Player Deck Shuffled " << endl;
        playerCounter = 0; //counter reset
    }
    
    if(botCounter >= y.size())
    {
        for(int i=0;i<k.size();i++)// add cards from gainedBotDeck to BotDeck
        {
            y.insert(y.end(), k[i]);
        }
        k.erase(k.begin(),k.begin() + k.size());//erase elements from gainedBotDeck
        random_shuffle(y.begin(), y.end(), randomNum);
        cout << " Bot Deck Shuffled " << endl;
        playerCounter = 0; // counter reset
    }
    cout << "Player draws " << x[playerCounter].CardValues.cardnum << " of " << x[playerCounter].CardValues.cardType << endl;
    cout << "Bot draws " << y[botCounter].CardValues.cardnum << " of " << y[botCounter].CardValues.cardType << endl << endl;
    
    if(x[playerCounter].CardValues.cardVal < y[botCounter].CardValues.cardVal)//When bot win he gains the card from other player
    {
        cout << " Bot Wins!" << endl;
        k.insert(k.end(), x[playerCounter]);
        cout << "(" << k.back().CardValues.cardnum << " of " << k.back().CardValues.cardType << " was gained by Bot.)" << endl;
        x.erase(x.begin() + playerCounter);//remove the card from player
        botCounter ++;
    }
    
    else if(x[playerCounter].CardValues.cardVal > y[botCounter].CardValues.cardVal)//When player win he gains the card from other player
    {
         cout << " Player Wins!" << endl;
        j.insert(j.end(), y[botCounter]);
        cout << "(" << j.back().CardValues.cardnum << " of " << j.back().CardValues.cardType << " was gained by Player.)" << endl;
        j.erase(j.begin() + botCounter);//remove the card from bot
        playerCounter ++;
    }
    
    else//When draw
    {
        cout << "   WAR!   " << endl;
        war(x,y,j,k);
    }
    roundNum++;
}

/***********
 ***********/

void war(vector<Cards> &x, vector<Cards> &y, vector<Cards> &j, vector<Cards> &k )
{
    int loopcount = 0;
    //Draw and shuffle cards for player to start war 
    if(j.size() != 0)
    {
        x.insert(x.begin(), x[playerCounter]);//draws cards for the war
        x.erase(x.begin() + (playerCounter + 1));
        
        for(int i = 0;i<j.size();i++)//add the cards from gainedplayerdeck to playerdeck
        {
            x.insert(x.end(), j[i]);
        }
        j.erase(j.begin(), j.begin() + j.size());
        random_shuffle(x.begin() + 1, x.end(), randomNum);// shuffles all cards expect the first card or first element 
        cout << " Player Deck Shuffled" << endl;
        playerCounter = 0;// resetting the counter for player
    }
    //Draw and shuffle cards for bot to start war 
    if(k.size() != 0)
    {
        y.insert(y.begin(), y[botCounter]);//draws cards for the war
        y.erase(y.begin() + (botCounter + 1)); 
        for(int i = 0; i< k.size();i++)
        {
            y.insert(y.end(), k[i]);
        }
        k.erase(k.begin(), k.begin() + k.size());
        random_shuffle(y.begin() + 1, y.end(), randomNum);
        cout << " Bot Deck Shuffled" << endl;
        botCounter = 0;// resetting the counter for bot
    }
    
    while(x[playerCounter].CardValues.cardVal == y[botCounter].CardValues.cardVal)
    {
        loopcount++;
        int playerDeckSize = x.size();
        int botDeckSize = y.size();
        
        if(playerDeckSize - 4 * loopcount < 0)// player doesnt have no more cards
        {
            cout << endl << "Player has the lost game!";
            exit(0);//exits program
        }
        
        else if(botDeckSize - 4 * loopcount < 0)//bot doesnt have no more cards
        {
            cout << endl << "Bot has the lost game!";
            exit(0);//exits program
        }
        
        if(loopcount < 2)
        {
            playerCounter += 3;
            botCounter += 3;
        }
        
        else
        {
            playerCounter += 4;
            botCounter += 4;
        }
        cout << "Player draws 3 cards + " << x[playerCounter].CardValues.cardnum << " of " << x[playerCounter].CardValues.cardType << endl;
        cout << "Bot draws 3 cards + " << y[botCounter].CardValues.cardnum << " of " << y[botCounter].CardValues.cardType << endl;
        
        if(x[playerCounter].CardValues.cardVal < y[botCounter].CardValues.cardVal)// if bot wins war
        {
            cout << "Bot Wins War!" << endl << endl;
            
            for(int i = 0;i < 4 * loopcount;i++)
            {
                k.insert(k.end(), x[playerCounter - i]);
                cout << "(" << k.back().CardValues.cardnum << " of " << k.back().CardValues.cardType << " was gained by Bot.)" << endl;//Show the cards that were drawn in war and given to Bot
            }
            x.erase(x.begin(), x.begin() + (4 * loopcount));//removes cards player lost from the deck in war
            playerCounter -= 4 * loopcount;// compensate for element lost in vector due to losing cards
            break;
        }
        
        else if(x[playerCounter].CardValues.cardVal > y[botCounter].CardValues.cardVal)// if player wins war
        {
            cout << "Player Wins War!" << endl << endl;
            
            for(int i = 0;i < 4 * loopcount;i++)
            {
                j.insert(k.end(), y[playerCounter - i]);
                cout << "(" << j.back().CardValues.cardnum << " of " << j.back().CardValues.cardType << " was gained by Player.)" << endl;//Show the cards that were drawn in war and given to Player
            }
            y.erase(y.begin(), y.begin() + (4 * loopcount));//removes cards player lost from the deck in war
            botCounter -= 4 * loopcount;// compensate for element lost in vector due to losing cards
            break;
        }
    }
}

