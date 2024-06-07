#pragma once
class Event
{
public:
	Event(std::string exposition, int affectedAttr, float effectVal, float proReq, float susReq, int odds);
	bool tryEvent();
	std::string getExposition();
	int getAffectedAttr();
	float getEffectVal();
	float getProgReq();
	float getSusReq();
private:
	std::string m_Exposition;
	int m_AffectedAttr;
	float m_EffectVal;
	float m_ProReq;
	float m_SusReq;
	int m_Odds;

};

