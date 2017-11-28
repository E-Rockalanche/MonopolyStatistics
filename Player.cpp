#include "Player.h"
#include "GameBoard.h"

void Player::Reset(){
	position = GameBoard::GO;
	has_get_out_of_jail_free_chance_card = false;
	has_get_out_of_jail_free_community_chest_card = false;
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
	return (has_get_out_of_jail_free_chance_card || has_get_out_of_jail_free_community_chest_card);
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