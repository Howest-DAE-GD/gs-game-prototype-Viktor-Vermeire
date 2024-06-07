#include "vector"
#pragma once
class Event;
class EventManager
{
public:
	EventManager();
	void addEvent(Event* event);
	Event* getEvent();
	~EventManager();
private:
	std::vector<Event*> m_EventList;
};

