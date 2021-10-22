#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

//멤버함수 재정의 - 기존 부모코드사용
void Player::draw()
{
  SDLGameObject::draw();
}

//멤버함수 재정의 - 기존 부모코드사용
void Player::update()
{
  m_x -= -1;
  m_currentFrame = ( (SDL_GetTicks() / 100) % 6);
}

void Player::clean() {}
