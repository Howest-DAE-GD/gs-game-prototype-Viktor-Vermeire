#include "pch.h"
#include "Cult.h"

Cult::Cult()
{
	m_Progress = 0;
	m_Suspicion = 0;
}

float Cult::GetProgress()
{
	return m_Progress;
}

void Cult::addProgress(float progress)
{
	m_Progress += progress;
}

float Cult::GetSuspicion()
{
	return m_Suspicion;
}

void Cult::addSuspicion(float suspicion)
{
	m_Suspicion += suspicion;
}

/*Cult::~Cult()
{
}*/
