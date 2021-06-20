// BattleSim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int main()
{
	
	
	// float's are decimals for example (1.23f) where as int's are nondecimals or whole numbers & can use doubles for really big numbers!!


	default_random_engine randomGen(time(NULL));					// Can use these 2 lines for any 
	uniform_real_distribution<float>  AttackRoll(0.0f, 1.0f);    // random generator i need in any game!!

	//uniform_int_distribution<int>    I can use this setup for Intagers (int)'s instead of float's.

	//dwarf properties

	float DwarfAttack = 0.1f;
	float DwarfHealth = 10.0f;
	float DwarfDamage = 10.0f;
	float currentDwarfHealth = DwarfHealth;
	
	
	// dragon properties

	
	
	float DragHealth = 210.0f;
	float DragAttack = 0.75f;
	float DragDamage = 150.0f;
	float currentDragonHealth = DragHealth;
	
	//number of units

	int startDwarf;
	int startDragon;

	int DwarfAmt;
	int DragonAmt;
	
	float attackResult;

	char turn = 'D';

	
	
	cout << "DWARVES VS. DRAGONS\n\n\n";
	cout << "How many Dwarves are in this army?: "; 
	cin >> DwarfAmt;
	startDwarf = DwarfAmt;
	cout << "How many Dragons are in this army?: ";
	cin >> DragonAmt;
	startDragon = DragonAmt;
	cout << "The horror of swords, shields and dwarven war screams ";
	cout << "pierce the air as Dragon fire fills the battlefield!";
	cout << "\n\n\n";

	// figuring out the combat stuff

	while ((DwarfAmt > 0) && (DragonAmt > 0))
	{    
		//get the attack result
		attackResult = AttackRoll(randomGen);
		
		// Dwarf turn
		if (turn == 'D')
		{
			
			
			// check if attack was a sucess
			if (attackResult <= DwarfAttack)
			{
				currentDragonHealth -= DwarfDamage;
				if (currentDragonHealth < 0)
				{
					DragonAmt--;								// any int or float ++ is an iteration of 1 or -- is minus 1
					currentDragonHealth = DragHealth;
				}
			}
			turn = 'S';
		}
		else
		{
			if (attackResult <= DragAttack)
			{
				currentDwarfHealth -= DragDamage;
				
				if (currentDwarfHealth < 0)
				{
					DwarfAmt--;
					currentDwarfHealth = DwarfHealth;
				}
			}
			turn = 'D';
		}
		
	}
	if (DwarfAmt > 0)
	{
		cout << "The Dwarven Kings for ages, are proud of the surviving warriors!!\n";
		cout << "The Dwarves win with " << DwarfAmt << " left!!\n";
	}
	else
	{
		cout << "The Dragons reign victorious and keep all treasure in there abodes!!\n";
		cout << "The dragons are victorious with " << DragonAmt << " left!!\n";
	}
	cout << startDwarf - DwarfAmt << " Dwarves and " << startDragon - DragonAmt << " dragons lost there lives!\n\n";
	
	system("PAUSE");
		return 0;
}


