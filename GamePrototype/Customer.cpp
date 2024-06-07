#include "pch.h"
#include "iostream"
#include "Customer.h"
#include "Ingredient.h"
#include "Potion.h"
#include "Event.h"
#include "utils.h"

Customer::Customer()
{
	m_WantedEffects;
	m_Payout = 1;
	m_HasRequest = false;
}

std::vector<Ingredient::effect> Customer::getWantedEffects()
{
	return m_WantedEffects;
}

float Customer::getPayout(float correctness, int badness)
{
	return (m_Payout * correctness) - badness;
}

void Customer::addEffect(Ingredient::effect effect)
{
	bool found = false;
	for (int looper{ 0 }; looper < m_WantedEffects.size(); ++looper) {
		if (m_WantedEffects[looper] == effect) {
			found = true;
		}
	}
	if (!found) {
		m_WantedEffects.push_back(effect);
	}
}

void Customer::getNewRequest()
{
	int val = 1;
	while (val != 0 && m_WantedEffects.size() != 8) {
		switch (rand() % 8) {
		case 0: addEffect(Ingredient::effect::enraging);
			break;
		case 1: addEffect(Ingredient::effect::healing);
			break;
		case 2: addEffect(Ingredient::effect::soothing);
			break;
		case 3: addEffect(Ingredient::effect::hypnotising);
			break;
		case 4: addEffect(Ingredient::effect::calming);
			break;
		case 5: addEffect(Ingredient::effect::dishearten);
			break;
		case 6: addEffect(Ingredient::effect::nightVision);
			break;
		case 7: addEffect(Ingredient::effect::paralysis);
			break;
		}
		val = rand() % 2;
	}
	m_Payout = (int)((rand() % 5) + 1);
	m_HasRequest = true;
}

bool Customer::hasRequest()
{
	return m_HasRequest;
}

void Customer::resetRequest()
{
	m_WantedEffects.clear();
	m_HasRequest = false;
}

Point2f Customer::handOverPotion(Potion* potion)
{
	float counter = 0;
	std::vector<Ingredient::effect> potionEffects = potion->getEffect();
	for (int looper{ 0 }; looper < m_WantedEffects.size(); ++looper) {
		for (int innerLooper{ 0 }; innerLooper < potionEffects.size(); ++innerLooper) {
			if (potionEffects[innerLooper] == m_WantedEffects[looper]) {
				++counter;
				potionEffects.erase(potionEffects.begin() + innerLooper);
			}
		}
	}
	std::cout << potionEffects.size();
	return Point2f{ getPayout(counter / m_WantedEffects.size(), potionEffects.size()),(float)potionEffects.size() };
}

void Customer::applyEvent(Event* event)
{
	switch (event->getAffectedAttr()) {
	case 0:
		m_Payout*=event->getEffectVal();
		break;
	case 1:
		m_SusInc*=event->getEffectVal();
		break;
	case 2:
		m_Payout*=event->getEffectVal();
		break;
	default:
		break;
	}
}


