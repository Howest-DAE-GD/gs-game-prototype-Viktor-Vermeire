#pragma once
class Texture;
class UI
{
public:
	UI(Texture* texture, Rectf textureRect);
	void Draw(Point2f location);
	Rectf getRect();
	~UI();
private:
	Texture* m_Texture;
	Rectf m_TextureRect;
};

