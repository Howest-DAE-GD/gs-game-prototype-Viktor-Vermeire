#include "Ingredient.h"
#include "vector"
#pragma once
class Potion
{
public:
	Potion();
	std::vector<Ingredient*> getIngredient();
	void addIngredient(Ingredient* ingredient);
	std::vector<Ingredient::effect> getEffect();
	void ResetPotion();
private:
	std::vector<Ingredient*> m_Ingredients;
};

