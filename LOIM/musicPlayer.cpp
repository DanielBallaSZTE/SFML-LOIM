#include "musicPlayer.h"
#include <iostream>

MusicPlayer::MusicPlayer()
{
	for (int i = 0; i < MAX_MUSIC; i++)
	{
		musicList[i] = new musicStruct;
	}
	totalMusic = 0;
	loadAllMusic();
}

void MusicPlayer::loadAllMusic()
{
	// Main theme
	loadSingleMusic("music/focimdal.wav", "mainTheme");
	// Easy Questions
	loadSingleMusic("music/100to1000.wav", "easyQuestions");

	std::cout << "\nMusicPlayer::Successfully loaded " << totalMusic << " musictracks.";
}

void MusicPlayer::loadSingleMusic(std::string filename, std::string name)
{
	musicList[totalMusic]->name = name;
	musicList[totalMusic]->musicFile.openFromFile(filename);
	totalMusic++;
}

void MusicPlayer::playMusic(std::string name)
{
	for (int i = 0; i < totalMusic; i++)
	{
		if (musicList[i]->name == name)
		{
			musicList[i]->musicFile.play();
		}
	}
}

bool MusicPlayer::getMusicStatus(std::string name)
{
	for (int i = 0; i < totalMusic; i++)
	{
		if (musicList[i]->name == name)
		{
			return musicList[i]->musicFile.getStatus() ? true : false;
		}
	}

	return false;
}