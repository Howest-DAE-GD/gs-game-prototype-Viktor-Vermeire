#pragma once
class Cauldron
{
public:
	Cauldron(Rectf form, Color4f color);
	void Draw();
	Rectf getRect();
private:
	Rectf m_CauldronForm;
	Color4f m_Color;

};

