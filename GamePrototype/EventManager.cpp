#include "pch.h"
#include "EventManager.h"
#include "Event.h"

EventManager::EventManager():
	m_EventList{}
{
}

void EventManager::addEvent(Event* event)
{
	m_EventList.push_back(event);
}

Event* EventManager::getEvent()
{
	int val = rand();
	if (m_EventList[val % m_EventList.size()]->tryEvent()) {
		return m_EventList[val % m_EventList.size()];
	}
	return nullptr;
}

EventManager::~EventManager()
{
	for (int looper{ 0 }; looper < m_EventList.size(); ++looper) {
		delete m_EventList[looper];
	}
}
