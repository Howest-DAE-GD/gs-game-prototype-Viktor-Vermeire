#pragma once
#include "Ingredient.h"
#include "vector"
class Potion;
class Event;
class Customer
{
public:
	Customer();
	std::vector<Ingredient::effect> getWantedEffects();
	void getNewRequest();
	bool hasRequest();
	void resetRequest();
	Point2f handOverPotion(Potion* potion);
	void applyEvent(Event* event);
private:
	std::vector<Ingredient::effect> m_WantedEffects;
	float m_Payout;
	bool m_HasRequest;
	float m_SusInc;
	float getPayout(float correctness, int badness);
	void addEffect(Ingredient::effect effect);
};

