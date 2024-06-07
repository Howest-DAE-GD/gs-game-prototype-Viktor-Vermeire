#pragma once
#include "BaseGame.h"
#include "Cult.h"
#include "Customer.h"
#include "potion.h"
#include "vector"

class Ingredient;
class Cauldron;
class UI;
class EventManager;
class Game : public BaseGame
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	// http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rh-override
	~Game();

	void Update( float elapsedSec ) override;
	void Draw( ) const override;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e ) override;
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e ) override;
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e ) override;
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e ) override;

private:

	// FUNCTIONS
	void Initialize();
	void Cleanup( );
	void ClearBackground( ) const;
	void Reset();
	void PrepIngredients();
	void PrepEvents();
	Potion* m_Potion;
	Cult* m_Cult;
	Customer* m_Customer;
	std::vector<Ingredient*> m_AllIngredients;
	Ingredient* m_Selected_Ingredient;
	Cauldron* m_Cauldron;
	UI* m_Ui;
	EventManager* m_EventManager;
	Event* m_CurrentEvent;
};