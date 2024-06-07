#include "pch.h"
#include "Event.h"

Event::Event(std::string exposition, int affectedAttr, float effectVal, float proReq, float susReq, int odds) :
	m_Exposition{ exposition },
	m_AffectedAttr{ affectedAttr },
	m_EffectVal{ effectVal },
	m_ProReq {proReq},
	m_SusReq {susReq},
	m_Odds {odds}
{
}

bool Event::tryEvent()
{
	if (rand() % m_Odds == m_Odds - 1) {
		return true;
	}
	return false;
}

std::string Event::getExposition()
{
	return m_Exposition;
}

int Event::getAffectedAttr()
{
	return m_AffectedAttr;
}

float Event::getEffectVal()
{
	return m_EffectVal;
}

float Event::getProgReq()
{
	return m_ProReq;
}

float Event::getSusReq()
{
	return m_SusReq;
}
