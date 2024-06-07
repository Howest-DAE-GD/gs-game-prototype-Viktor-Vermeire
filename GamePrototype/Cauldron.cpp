#include "pch.h"
#include "Cauldron.h"
#include "utils.h"

Cauldron::Cauldron(Rectf form, Color4f color):
	m_CauldronForm {form},
	m_Color {color}
{
}

void Cauldron::Draw()
{
	utils::SetColor(m_Color);
	utils::FillRect(m_CauldronForm);
}

Rectf Cauldron::getRect()
{
	return m_CauldronForm;
}

