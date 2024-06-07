#include "pch.h"
#include "UI.h"
#include "Texture.h"

UI::UI(Texture* texture, Rectf textureRect) :
	m_Texture{ texture },
	m_TextureRect {textureRect}
{
}

void UI::Draw(Point2f location)
{
	m_Texture->Draw(m_TextureRect, Rectf{ 0,0, m_TextureRect.width, m_TextureRect.height });
}

Rectf UI::getRect()
{
	return m_TextureRect;
}

UI::~UI()
{
	delete m_Texture;
}
