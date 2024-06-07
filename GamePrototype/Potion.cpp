#include "pch.h"
#include "potion.h"
#include "Ingredient.h"

Potion::Potion()
{
}

std::vector<Ingredient*> Potion::getIngredient()
{
	return m_Ingredients;
}

void Potion::addIngredient(Ingredient* ingredient)
{
	bool found = false;
	for (int looper{ 0 }; looper < m_Ingredients.size(); ++looper) {
		if (ingredient == m_Ingredients[looper]) {
			found = true;
			break;
		}
	}
	if (!found) {
		m_Ingredients.push_back(ingredient);
		ingredient->setAdded();
	}
}

std::vector<Ingredient::effect> Potion::getEffect()
{
	std::vector<Ingredient::effect> effects;
	for (int looper{ 0 }; looper < m_Ingredients.size(); ++looper) {
		for (int innerLooper{ 0 }; innerLooper < m_Ingredients[looper]->getEffect().size(); ++innerLooper) {
			effects.push_back(m_Ingredients[looper]->getEffect()[innerLooper]);
		}
		
	}
	return effects;
}

void Potion::ResetPotion()
{
	m_Ingredients.clear();
}
