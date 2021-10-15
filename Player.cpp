#include "Player.h"

void Player::load(int x, int y, int width, int height,
std::string textureID)
{
  GameObject::load(x, y, width, height, textureID);
}

//멤버함수 재정의 - 기존 부모코드사용
void Player::draw(SDL_Renderer* pRenderer)
{
  GameObject::draw(pRenderer);
}

//멤버함수 재정의 - 기존 부모코드사용
void Player::update()
{
  m_x -= -1;
}
