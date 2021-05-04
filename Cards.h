/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cards.h
 * Author: Kevin Cuevas
 *
 * Created on April 6, 2021, 9:00 AM
 */

#ifndef CARDS_H
#define CARDS_H
#include <string>
#include <iostream>
using namespace std;
class Cards{

public:
	//Values Cards Contain
	struct cardValues
	{
		string cardType;
		string cardnum;
		int cardVal;
	};

	cardValues CardValues;
	
	//Displays Values Contained in Cards
	void displayCard()
	{
		cout << "Card info: " << endl;
		cout << CardValues.cardType << endl;
		cout << CardValues.cardnum << endl;
		cout << CardValues.cardVal << endl;
		cout << endl;
	}
} card;

//Card Objects
Cards Card0; Cards Card1; Cards Card2;
Cards Card3; Cards Card4; Cards Card5;
Cards Card6; Cards Card7; Cards Card8;
Cards Card9; Cards Card10; Cards Card11;
Cards Card12; Cards Card13; Cards Card14;
Cards Card15; Cards Card16; Cards Card17;
Cards Card18; Cards Card19; Cards Card20;
Cards Card21; Cards Card22; Cards Card23;
Cards Card24; Cards Card25; Cards Card26;
Cards Card27; Cards Card28; Cards Card29;
Cards Card30; Cards Card31; Cards Card32;
Cards Card33; Cards Card34; Cards Card35;
Cards Card36; Cards Card37; Cards Card38;
Cards Card39; Cards Card40; Cards Card41;
Cards Card42; Cards Card43; Cards Card44;
Cards Card45; Cards Card46; Cards Card47;
Cards Card48; Cards Card49; Cards Card50;
Cards Card51;

class CardObjects
{

public:
	//Assigns Values to cards
	void createdCards()
	{
		//Cards of Clubs
		Card0.CardValues = { "Clubs", "2", 2 }; Card1.CardValues = { "Clubs", "3", 3 }; Card2.CardValues = { "Clubs", "4", 4 };
		Card3.CardValues = { "Clubs", "5", 5 }; Card4.CardValues = { "Clubs", "6", 6 }; Card5.CardValues = { "Clubs", "7", 7 };
		Card6.CardValues = { "Clubs", "8", 8 }; Card7.CardValues = { "Clubs", "9", 9 }; Card8.CardValues = { "Clubs", "10", 10 };
		Card9.CardValues = { "Clubs", "Jack", 11 }; Card10.CardValues = { "Clubs", "Queen", 12 }; Card11.CardValues = { "Clubs", "King", 13 };
		Card12.CardValues = { "Clubs", "Ace", 14 };

		//Cards of Hearts
		Card13.CardValues = { "Hearts", "2", 2 }; Card14.CardValues = { "Hearts", "3", 3 }; Card15.CardValues = { "Hearts", "4", 4 };
		Card16.CardValues = { "Hearts", "5", 5 }; Card17.CardValues = { "Hearts", "6", 6 }; Card18.CardValues = { "Hearts", "7", 7 };
		Card19.CardValues = { "Hearts", "8", 8 }; Card20.CardValues = { "Hearts", "9", 9 }; Card21.CardValues = { "Hearts", "10", 10 };
		Card22.CardValues = { "Hearts", "Jack", 11 }; Card23.CardValues = { "Hearts", "Queen", 12 }; Card24.CardValues = { "Hearts", "King", 13 };
		Card25.CardValues = { "Hearts", "Ace", 14 };

		//Cards of Spades
		Card26.CardValues = { "Spades", "2", 2 }; Card27.CardValues = { "Spades", "3", 3 }; Card28.CardValues = { "Spades", "4", 4 };
		Card29.CardValues = { "Spades", "5", 5 }; Card30.CardValues = { "Spades", "6", 6 }; Card31.CardValues = { "Spades", "7", 7 };
		Card32.CardValues = { "Spades", "8", 8 }; Card33.CardValues = { "Spades", "9", 9 }; Card34.CardValues = { "Spades", "10", 10 };
		Card35.CardValues = { "Spades", "Jack", 11 }; Card36.CardValues = { "Spades", "Queen", 12 }; Card37.CardValues = { "Spades", "King", 13 };
		Card38.CardValues = { "Spades", "Ace", 14 };

		//Cards of Diamonds
		Card39.CardValues = { "Diamonds", "2", 2 }; Card40.CardValues = { "Diamonds", "3", 3 }; Card41.CardValues = { "Diamonds", "4", 4 };
		Card42.CardValues = { "Diamonds", "5", 5 }; Card43.CardValues = { "Diamonds", "6", 6 }; Card44.CardValues = { "Diamonds", "7", 7 };
		Card45.CardValues = { "Diamonds", "8", 8 }; Card46.CardValues = { "Diamonds", "9", 9 }; Card47.CardValues = { "Diamonds", "10", 10 };
		Card48.CardValues = { "Diamonds", "Jack", 11 }; Card49.CardValues = { "Diamonds", "Queen", 12 }; Card50.CardValues = { "Diamonds", "King", 13 };
		Card51.CardValues = { "Diamonds", "Ace", 14 };
	}
} cardObj;

#endif /* CARDS_H */
