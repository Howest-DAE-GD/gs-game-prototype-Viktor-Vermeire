#include "pch.h"
#include "Ingredient.h"
#include "utils.h"



Ingredient::Ingredient(std::string name, std::vector<effect> ingEffect, int price, Rectf location, Color4f colour, float ideal):
    m_Effect{ingEffect},
    m_Price{price},
    m_Name{name},
    m_StartLocation {location},
    m_CurrentLocation {location},
    m_StartColour {colour},
    m_CurrentColour {colour},
    m_IdealQuality {ideal}
{
    m_CurrentQuality = 0;
    m_Added = false;
}

std::string Ingredient::getName()
{
    return m_Name;
}

std::vector<Ingredient::effect> Ingredient::getEffect()
{
    return m_Effect;
}

int Ingredient::getPrice()
{
    return m_Price;
}

std::string Ingredient::getEffectName(effect effectName)
{
    switch (effectName) {
    case effect::healing: return "healing";
        break;
    case effect::enraging: return "enraging";
        break;
    case effect::hypnotising: return "hypnotising";
        break;
    case effect::soothing: return "soothing";
        break;
    case effect::paralysis: return "paralysis";
        break;
    case effect::dishearten: return "dishearten";
        break;
    case effect::nightVision: return "night vision";
        break;
    case effect::calming: return "calming";
        break;
    default:
        return "";
        break;
    }
}

void Ingredient::setLocation(Point2f location) {
    m_CurrentLocation.bottom = location.y;
    m_CurrentLocation.left = location.x;
}

void Ingredient::Cook(float change)
{
    m_CurrentQuality += change;
    if (m_CurrentQuality < m_IdealQuality) {
        m_CurrentColour.r = m_CurrentQuality / m_IdealQuality;
        m_CurrentColour.g = m_CurrentQuality / m_IdealQuality;
        m_CurrentColour.b = m_CurrentQuality / m_IdealQuality;
    }
    else {
        m_CurrentColour.r = m_IdealQuality / m_CurrentQuality;
        m_CurrentColour.g = m_IdealQuality / m_CurrentQuality;
        m_CurrentColour.b = m_IdealQuality / m_CurrentQuality;
    }
    
    
}

Rectf Ingredient::getRect()
{
    return m_CurrentLocation;
}

void Ingredient::Draw() {
    if (!m_Added) {
        utils::SetColor(m_CurrentColour);
        utils::FillRect(m_CurrentLocation);
    }
}

void Ingredient::setAdded() {
    m_Added = true;
}

void Ingredient::Reset() {
    m_CurrentQuality = 0;
    m_Added = false;
    m_CurrentLocation = m_StartLocation;
    m_CurrentColour = m_StartColour;
}

float Ingredient::getQuality()
{
    if (m_CurrentQuality < m_IdealQuality) {
        return m_CurrentQuality / m_IdealQuality;
    }
    else {
        return m_IdealQuality/ m_CurrentQuality;
    }
}
