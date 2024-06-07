#include "utils.h"
#pragma once
class Ingredient
{
public:
	enum effect { healing, soothing, enraging, hypnotising, calming, dishearten, nightVision, paralysis};
	Ingredient(std::string name, std::vector<effect> ingEffect, int price, Rectf location, Color4f colour, float ideal);
	std::string getName();
	std::vector<Ingredient::effect> getEffect();
	int getPrice();
	static std::string getEffectName(effect effectName);
	void Draw();
	Rectf getRect();
	void setAdded();
	void setLocation(Point2f location);
	void Cook(float change);
	void Reset();
	float getQuality();

	
private:
	std::string m_Name;
	std::vector<effect> m_Effect;
	int m_Price;
	Rectf m_StartLocation;
	Rectf m_CurrentLocation;
	Color4f m_StartColour;
	Color4f m_CurrentColour;
	bool m_Added;
	float m_IdealQuality;
	float m_CurrentQuality;
};

