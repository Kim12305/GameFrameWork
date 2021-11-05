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
  //m_x -= -1;
  m_position.setX(m_position.getX()+1);
  m_currentFrame = ( (SDL_GetTicks() / 100) % 6);

  //x 값을 갱신 때마다 1씩 더하기
  m_velocity.setX(1);
  SDLGameObject::update(); //부모클래스 함수 호출
}

void Player::clean() {}
