#include "Player.h"
#include "GameBoard.h"

void Player::Reset(){
	position = GameBoard::GO;
	has_gojf_chance_card = false;
	has_gojf_community_chest_card = false;
}

void Player::SetPosition(int new_pos){
	position = new_pos;
}

int Player::GetPosition() const{
	return position;
}

void Player::Move(int amount){
	position += amount;
	position %= GameBoard::NUM_TILES;
}

bool Player::HasGetOutOfJailFreeCard() const{
	return (has_gojf_chance_card || has_gojf_community_chest_card);
}

void Player::GoToJail(){
	position = GameBoard::IN_JAIL;
	failed_jail_rolls = 0;
}

bool Player::IsInJail() const{
	return (position == GameBoard::IN_JAIL);
}

bool Player::FailedMaxJailRolls() const{
	return (failed_jail_rolls >= 3);
}

void Player::FailJailRoll(){
	failed_jail_rolls++;
}