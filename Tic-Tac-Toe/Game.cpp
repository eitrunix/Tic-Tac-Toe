#include "Game.h"
#include "playerComputer.h"
#include "playerHuman.h"
#include <iostream>

using namespace std;
// Sets up a game, with the first player ready.

class Player;

//constructor for the game, sets current to first, and sets number of players to NULL
Game::Game() :
	m_Current(FIRST)
{
	for (int i = 0; i < NUM_PLAYERS; ++i)
	{
		m_pPlayers[i] = NULL;
	}
}
//
Game::~Game()
{
	ClearPlayers();
}


// The game runs while these are not true
bool Game::IsPlaying() const
{
	return (!m_Board.IsFull() && !m_Board.IsWinner(m_pPlayers[FIRST]->GetPiece()) && !m_Board.IsWinner(m_pPlayers[SECOND]->GetPiece()));
}
// Game ties if the board is full but there is no winning combos to trigger the win condition
bool Game::IsTie() const
{
	return (m_Board.IsFull() && !m_Board.IsWinner(m_pPlayers[FIRST]->GetPiece()) && !m_Board.IsWinner(m_pPlayers[SECOND]->GetPiece()));
}
void Game::ClearPlayers()
{
	for (int i = 0; i < NUM_PLAYERS; i++)
	{
		delete m_pPlayers[i];
		m_pPlayers[i] = NULL;
	}
}

void Game::SetPlayers()
{
	ClearPlayers();

	cout << "Who shall wage this epic fight? ";
	cout << "Declare opponents..." << endl;

	for (int i = 0; i < NUM_PLAYERS; ++i)
	{
		cout << "Player " << i + 1;
		cout << " - human or computer? (h/c): ";
		char playerType;
		cin >> playerType;

		if (playerType == 'h')
		{
			m_pPlayers[i] = new PlayerHuman();
		}
		else if (playerType == 'c')
		{
			m_pPlayers[i] = new PlayerComputer();
		}
		else
		{
			cout << "Please enter 'h' or 'c' to identify player types!" << endl;
			SetPlayers();
			return;
		}
	}
}

// Tell the player how to play
void Game::DisplayInstructions() const
{
	cout << "\tWelcome to the ultimate intellectual";
	cout << "showdown: Tic-Tac-Toe." << endl << endl;

	cout << "Make your move by enterting a number, 0-8. The number" << endl;
	cout << "corresponds with board postion, as illustrated:" << endl << endl;

	cout << endl << "\t" << "0 | 1 | 2";
	cout << endl << "\t" << "---------";
	cout << endl << "\t" << "3 | 4 | 5";
	cout << endl << "\t" << "---------";
	cout << endl << "\t" << "6 | 7 | 8";

	cout << endl << endl;
	cout << "Perpare yourself. THe battle is about to begin.";
	cout << endl << endl;
}
// to change first and second player 
void Game::NextPlayer()
{
	m_Current = (m_Current + 1) % NUM_PLAYERS;
}
// Announce the winner or if its a tie
void Game::AnnounceWinner() const
{
	cout << "The raging battle has come to a final end.";
	cout << endl;
	//if tie.
	if (IsTie())
	{
		cout << "Sadly, no plater emerged victorious.";
		cout << endl;
	}
	else //else announce winner
	{
		cout << "The winnder of this climatic";
		cout << "confrontation is Player ";

		if (m_Board.IsWinner(m_pPlayers[FIRST]->GetPiece()))
		{
			cout << m_pPlayers[FIRST]->GetPiece() << "!";
			cout << endl;
		}
		else
		{
			cout << m_pPlayers[SECOND]->GetPiece() << "!";
			cout << endl;
		}
	}
}
// We Sets First player, resets the board incase we played before, while it is "playing" Display the board, tell the player to make a move, then swap players.
void Game::Play()
{
	m_Current = FIRST;
	m_Board.Reset();
	while (IsPlaying())
	{
		m_Board.Display();
		m_pPlayers[m_Current]->MakeMove(m_Board);
		NextPlayer();
	}
	// Display the filled board and announce winner.
	m_Board.Display();
	AnnounceWinner();
}

