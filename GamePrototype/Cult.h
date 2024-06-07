#pragma once
class Cult
{ 
public:
	Cult();
	float GetProgress();
	void addProgress(float progress);
	float GetSuspicion();
	void addSuspicion(float suspicion);
	//~Cult();

private:
	float m_Progress;
	float m_Suspicion;
};

