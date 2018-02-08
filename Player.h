#ifndef PLAYER_H
#define Player_H

class Player{
private:
	int position;
	int failed_jail_rolls;
	
public:
	bool has_gojf_chance_card;
	bool has_gojf_community_chest_card;

	void Reset();
	void SetPosition(int new_pos);
	int GetPosition() const;
	void Move(int amount);
	bool HasGetOutOfJailFreeCard() const;
	void GoToJail();
	bool IsInJail() const;
	bool FailedMaxJailRolls() const;
	void FailJailRoll();
};

#endif