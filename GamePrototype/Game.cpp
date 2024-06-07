#include "pch.h"
#include "Game.h"
#include "Ingredient.h"
#include "Customer.h"
#include "iostream"
#include "utils.h"
#include "Cauldron.h"
#include "UI.h"
#include "Texture.h"
#include "EventManager.h"
#include "Event.h"

Game::Game( const Window& window ) 
	:BaseGame{ window },
	m_AllIngredients{}
{
	m_EventManager = new EventManager();
	Initialize();
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_Cult = new Cult();
	m_Customer = new Customer();
	m_Potion = new Potion();
	m_Selected_Ingredient = nullptr;
	m_Cauldron = new Cauldron(Rectf{ 100,100,150,150 }, Color4f{ 50,0,20,20 });
	m_Ui = new UI(new Texture{ "Hand_In.png" }, Rectf{100,50,100,50});

	PrepIngredients();
	PrepEvents();

}

void Game::Cleanup( )
{
	for (int looper{ 0 }; looper < m_AllIngredients.size(); ++looper) {
		delete m_AllIngredients[looper];
	}
	delete m_Potion;
	delete m_Cauldron;
	delete m_Cult;
	delete m_EventManager;
	delete m_Customer;
	delete m_Ui;
}

void Game::Update( float elapsedSec )
{
	if (!m_Customer->hasRequest()) {
		std::cout << "\nProgress: " << m_Cult->GetProgress() << "\nSuspicion: " << m_Cult->GetSuspicion();
		m_Customer->getNewRequest();
		m_CurrentEvent = m_EventManager->getEvent();
		if (m_CurrentEvent != nullptr) {
			if (m_Cult->GetProgress() >= m_CurrentEvent->getProgReq() && m_Cult->GetSuspicion() >= m_CurrentEvent->getSusReq()) {
				m_Customer->applyEvent(m_CurrentEvent);
				std::cout << "\n" << m_CurrentEvent->getExposition();
			}
			
		}
		std::printf("\nI would like: ");
		for (int looper{ 0 }; looper < m_Customer->getWantedEffects().size(); ++looper) {
			std::cout << Ingredient::getEffectName(m_Customer->getWantedEffects()[looper])<< ", ";
		}
	}
	if (m_Selected_Ingredient != nullptr) {
		if (utils::IsOverlapping(m_Selected_Ingredient->getRect(), m_Cauldron->getRect())) {
			m_Selected_Ingredient->Cook(elapsedSec);
		}
	}
	
}

void Game::Draw( ) const
{
	ClearBackground();
	m_Cauldron->Draw();
	m_Ui->Draw(Point2f{ 100.f,50.f });
	for (int looper{ 0 }; looper < m_AllIngredients.size(); ++looper) {
		m_AllIngredients[looper]->Draw();
	}
	
	
	
	
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	if (m_Selected_Ingredient != nullptr) {
		Point2f mouseLocation = Point2f{ (float)e.x, (float)e.y };
		m_Selected_Ingredient->setLocation(mouseLocation);
	}
	
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	Point2f mouseLocation = Point2f{ (float)e.x, (float)e.y };
	switch (e.button) {
	case SDL_BUTTON_LEFT:
		for (int looper = { 0 }; looper < m_AllIngredients.size(); ++looper)
		{
			if (utils::IsPointInRect(mouseLocation, m_AllIngredients[looper]->getRect())) {
				m_Selected_Ingredient = m_AllIngredients[looper];
				std::cout << "\n" << m_Selected_Ingredient->getName();
			}
		}
		if (utils::IsPointInRect(mouseLocation, m_Ui->getRect())) {
			Point2f result = m_Customer->handOverPotion(m_Potion);
			m_Cult->addProgress(result.x);
			m_Cult->addSuspicion(result.y);
			Reset();
		}
	}
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	if (m_Selected_Ingredient != nullptr) {
		if (utils::IsOverlapping(m_Selected_Ingredient->getRect(), m_Cauldron->getRect())) {
			m_Potion->addIngredient(m_Selected_Ingredient);
		}
		m_Selected_Ingredient = nullptr;
	}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::Reset()
{
	m_Customer->resetRequest();
	m_Potion->ResetPotion();
	for (int looper = { 0 }; looper < m_AllIngredients.size(); ++looper) {
		m_AllIngredients[looper]->Reset();
	}
	m_CurrentEvent = nullptr;
}

void Game::PrepIngredients()
{
	m_AllIngredients.push_back(new Ingredient("carrot", { Ingredient::effect::healing }, 5, Rectf{ 50,400,50,50 }, Color4f{ 0.90f,0,0,1 }, 8));
	m_AllIngredients.push_back(new Ingredient("Nightshade", { Ingredient::effect::hypnotising }, 8, Rectf{ 150,400,50,50 }, Color4f{ 0,0.90f,0,1 }, 3));
	m_AllIngredients.push_back(new Ingredient("Honey", { Ingredient::effect::soothing }, 4, Rectf{ 250,400,50,50 }, Color4f{ 0.90f,0.90f,0,1 }, 6));
	m_AllIngredients.push_back(new Ingredient("Blonde Hair", { Ingredient::effect::enraging }, 3, Rectf{ 350,400,50,50 }, Color4f{ 0,0,0.90f,1 }, 10));
	m_AllIngredients.push_back(new Ingredient("essence of star", { Ingredient::effect::calming }, 3, Rectf{ 450,400,50,50 }, Color4f{ 0,0.90f,0.90f,1 }, 10));
	m_AllIngredients.push_back(new Ingredient("Children's tears", { Ingredient::effect::soothing, Ingredient::effect::healing }, 3, Rectf{ 550,400,50,50 }, Color4f{ 0.90f,0,0.90f,1 }, 10));
	m_AllIngredients.push_back(new Ingredient("Juniper Berries", { Ingredient::effect::nightVision, Ingredient::effect::enraging }, 3, Rectf{ 650,400,50,50 }, Color4f{ 0.20f,0.20f,0.90f,1 }, 10));
	m_AllIngredients.push_back(new Ingredient("Moon Sugar", { Ingredient::effect::paralysis, Ingredient::effect::hypnotising }, 3, Rectf{ 750,400,50,50 }, Color4f{ 0.10f,0.40f,0.90f,1 }, 10));
}

void Game::PrepEvents()
{
	m_EventManager->addEvent(new Event{ "event1: sus * 2, chance in 5, no Req", 1, 2, 0,0,5 });
	m_EventManager->addEvent(new Event{ "event2: prog * 0.5, chance in 3, progreq 10 susreq 2", 0, 0.5f, 10,2,3 });
	m_EventManager->addEvent(new Event{ "event3: pay * 2, chance in 1, ro req ", 2, 4, 0,0,1 });
	m_EventManager->addEvent(new Event{ "event4: susgain* 0.1, chance in 8, no req", 1, 0.1f, 0,0,8 });
}
