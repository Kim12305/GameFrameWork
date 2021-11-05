#include "Enemy.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Enemy::draw()
{
  SDLGameObject::draw();
}

void Enemy::update()
{
  //m_position.setX(m_position.getX()+1);
  //m_position.setY(m_position.getX()+1);
  m_currentFrame = ( (SDL_GetTicks() / 100) % 6);

  m_velocity.setX(1);
  SDLGameObject::update(); //부모클래스 함수 호출
}

void Enemy::clean() {}
