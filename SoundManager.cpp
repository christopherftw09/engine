//
// Project: Game Engine.
// Developer: Chris Mooney
//
// File: SoundManager
//

//
// SoundManager.cpp
// Game Engine
//
// Created by Chris Mooney.
// Copyright (c) 2016 Chris Mooney. All rights reserved.
//

#include <iostream>
#include "SoundManager.h"

SoundManager::SoundManager()
{
	cout << "Initializing Sound Manager... ";

	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 4, 4096) < 0)
	{
		printf("Failed.\n*** We encountered an error while opening the Sound Manager! (Error Messsage: %s) ***\n", Mix_GetError());
	}
	
	//cout << mSound.begin->GetVolume() << endl;
	cout << "Done." << endl;
}

int SoundManager::Play()
{
	//mSound.push_back(new Sound("music.wav"));
	return 1;
}

SoundManager::~SoundManager()
{
	// clear the sound list.
	//mSound.clear();

	Mix_Quit();
}