#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <random>

class object {
public:
	std::string name;
	int health;
	int damage;

	object(std::string n, int h, int d) : name(n), health(h), damage(d) {}

	virtual void attack(object& enemy) {
		std::cout << name << "sneaks up " << enemy.name << " inflicts" << damage << std::endl;
	}

};
class goblin : public object {
public:
	goblin(std::string n) : object(n, 100, 40) {}

	void attack(object& enemy) override {
		std::cout << name << " sneaks up from the shadows, throwing a poisoned dagger at " << enemy.name << ", landing a sneak attack that deals " << damage << " damage!" << std::endl;
		enemy.health -= damage;
		std::cout << enemy.name << " feels the poison seep through their veins, health reduced to " << enemy.health << "!" << std::endl;
	}

};

class assassin : public object {
public:
	assassin(std::string n) : object(n, 100, 20) {}

	void attack(object& enemy) override {
		std::cout << name << " blends into the shadows, reappearing behind " << enemy.name << " in an instant and delivering a deadly strike that inflicts " << damage << " damage!" << std::endl;
		enemy.health -= damage;
		std::cout << enemy.name << " barely realizes what happened, their health dropping to " << enemy.health << "!" << std::endl;
	}
};

class fairy : public object {
public:
	fairy(std::string n) : object(n, 100, 10) {}
	void attack(object& enemy) override {
		std::cout << name << " flutters gracefully into the air, summoning a whirlwind of magical sparkles that swirl around " << enemy.name << ", causing " << damage << " damage with a burst of magic!" << std::endl;
		enemy.health -= damage;
		std::cout << enemy.name << " is momentarily dazed by the dazzling display, their health is now " << enemy.health << "!" << std::endl;
	}
};

class magician : public object {
public:
	magician(std::string n) : object(n, 100, 30) {}

	void attack(object& enemy) override {
		std::cout << name << " raises their staff, casting a powerful arcane spell that strikes " << enemy.name << " with a burst of raw energy, causing " << damage << " points of damage!" << std::endl;
		enemy.health -= damage;
		std::cout << enemy.name << " is left stunned by the arcane blast, their health reduced to " << enemy.health << "!" << std::endl;
	}
};

class witch : public object {
public:
	witch(std::string n) : object(n, 100, 15) {}
	void attack(object& enemy) override {
		std::cout << name << " cackles wickedly as she raises her gnarled staff, summoning a dark, swirling mist to engulf " << enemy.name << ", dealing " << damage << " points of magical damage!" << std::endl;
		enemy.health -= damage;
		std::cout << enemy.name << " struggles to breathe through the thick fog, their health now at " << enemy.health << "!" << std::endl;
	}
};

class tree : public object {
public:
	tree(std::string n) : object(n, 100, 16) {}
	void attack(object& enemy) override {
		std::cout << name << " creaks as its massive roots burst from the ground, slamming into " << enemy.name << " with a powerful blow, dealing " << damage << " points of earth-shattering damage!" << std::endl;
		enemy.health -= damage;
		std::cout << enemy.name << " is knocked back by the force, their health now at " << enemy.health << "!" << std::endl;
	}
};

void attackStrategy();
int main() {
	attackStrategy();

}
void attackStrategy() {
	goblin* mygoblin = new goblin("Grogar the Grim");
	assassin* myassassin = new assassin("Seraphis the Phantom");
	fairy* myfairy = new fairy("Ariella Moonwhisper");
	magician* mymagic = new magician("Oryn the Mystic");
	tree* mytree = new tree("Alderon the Eternal Root");
	witch* mywitch = new witch("Thalindra the Witch Queen");

	std::vector<object*> list;

	list.push_back(mygoblin);
	list.push_back(myfairy);
	list.push_back(mymagic);
	list.push_back(mytree);
	list.push_back(mywitch);

	std::cout << " Choose your adversary wisely, for only one will emerge victorious in this battle!" << std::endl;

	for (int i{ 0 }; i < list.size(); i++) {
		std::cout << i + 1 << " " << list[i]->name << std::endl;
	}
	int command;
	std::cin >> command;

	switch (command) {
	case 1:
		myassassin->attack(*mygoblin);
		break;
	case 2:
		myassassin->attack(*myfairy);
		break;
	case 3:
		myassassin->attack(*mymagic);
		break;
	case 4:
		myassassin->attack(*mytree);
		break;
	case 5:
		myassassin->attack(*mywitch);
		break;
	}



}