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

	virtual void defend(object& attacker) {

		int reducedDamage = attacker.damage / 2;
		health -= reducedDamage;
		std::cout << name << " defends against " << attacker.name << "'s attack, reducing the damage to " << reducedDamage << "!" << std::endl;
		std::cout << name << "'s health is now " << health << "." << std::endl;
	}
};
class goblin : public object {
public:
	goblin(std::string n) : object(n, 100, 40) {}

	void attack(object& enemy) override {
		std::cout << name << " \nsneaks up from the shadows, throwing a poisoned dagger at " << enemy.name << ", landing a sneak attack that deals " << damage << " damage!" << std::endl;
		enemy.health -= damage;
		std::cout << enemy.name << "\n feels the poison seep through their veins, health reduced to " << enemy.health << "!" << std::endl;
	}
	void defend(object& attacker) override {
		int reducedDamage = attacker.damage / 2; // Goblins are quite tough!
		health -= reducedDamage;
		std::cout << '\n' << name << "raises a rusty shield, blocking some of the attack and reducing damage to " << reducedDamage << "!" << std::endl;
		std::cout << '\n' << name << "'s health is now " << health << "." << std::endl;
	}
};

class assassin : public object {
public:
	assassin(std::string n) : object(n, 200, 50)
	{}

	void attack(object& enemy) override {
		std::cout << '\n' << name << " blends into the shadows, reappearing behind " << enemy.name << " in an instant and delivering a deadly strike that inflicts " << damage << " damage!" << std::endl;
		enemy.health -= damage;
		std::cout << '\n' << enemy.name << " barely realizes what happened, their health dropping to " << enemy.health << "!" << std::endl;
	}
	void defend(object& attacker) override {
		// Assassins are agile and can dodge attacks
		int reducedDamage = attacker.damage / 3; // Reduced damage due to agility
		health -= reducedDamage;
		std::cout << '\n' << name << " swiftly dodges, narrowly avoiding most of the attack, reducing the damage to " << reducedDamage << "!" << std::endl;
		std::cout << '\n' << name << "'s health is now " << health << "." << std::endl;
	}
};

class fairy : public object {
public:
	fairy(std::string n) : object(n, 100, 10) {}
	void attack(object& enemy) override {
		std::cout << '\n' << name << " flutters gracefully into the air, summoning a whirlwind of magical sparkles that swirl around " << enemy.name << ", causing " << damage << " damage with a burst of magic!" << std::endl;
		enemy.health -= damage;
		std::cout << '\n' << enemy.name << " is momentarily dazed by the dazzling display, their health is now " << enemy.health << "!" << std::endl;
	}
	void defend(object& attacker) override {
		// Fairies rely on magic to protect themselves
		int reducedDamage = attacker.damage / 3; // Magic shield reduces damage
		health -= reducedDamage;
		std::cout << '\n' << name << " conjures a shimmering magic barrier, reducing the damage to " << reducedDamage << "!" << std::endl;
		std::cout << '\n' << name << "'s health is now " << health << "." << std::endl;
	}
};

class magician : public object {
public:
	magician(std::string n) : object(n, 100, 30) {}

	void attack(object& enemy) override {
		std::cout << '\n' << name << " raises their staff, casting a powerful arcane spell that strikes " << enemy.name << " with a burst of raw energy, causing " << damage << " points of damage!" << std::endl;
		enemy.health -= damage;
		std::cout << '\n' << enemy.name << " is left stunned by the arcane blast, their health reduced to " << enemy.health << "!" << std::endl;
	}
	void defend(object& attacker) override {
		// Magicians have a magic shield to absorb part of the damage
		int reducedDamage = attacker.damage / 2; // Shield reduces damage
		health -= reducedDamage;
		std::cout << '\n' << name << " summons a magical shield, absorbing part of the attack and reducing the damage to " << reducedDamage << "!" << std::endl;
		std::cout << '\n' << name << "'s health is now " << health << "." << std::endl;
	}
};

class witch : public object {
public:
	witch(std::string n) : object(n, 100, 15) {}
	void attack(object& enemy) override {
		std::cout << '\n' << name << " cackles wickedly as she raises her gnarled staff, summoning a dark, swirling mist to engulf " << enemy.name << ", dealing " << damage << " points of magical damage!" << std::endl;
		enemy.health -= damage;
		std::cout << '\n' << enemy.name << " struggles to breathe through the thick fog, their health now at " << enemy.health << "!" << std::endl;
	}
	void defend(object& attacker) override {
		// Witches can summon a dark shield to defend
		int reducedDamage = attacker.damage / 2; // Dark shield reduces damage
		health -= reducedDamage;
		std::cout << '\n' << name << " casts a dark shield, absorbing some of the attack and reducing the damage to " << reducedDamage << "!" << std::endl;
		std::cout << '\n' << name << "'s health is now " << health << "." << std::endl;
	}
};

class tree : public object {
public:
	tree(std::string n) : object(n, 100, 16) {}
	void attack(object& enemy) override {
		std::cout << '\n' << name << " creaks as its massive roots burst from the ground, slamming into " << enemy.name << " with a powerful blow, dealing " << damage << " points of earth-shattering damage!" << std::endl;
		enemy.health -= damage;
		std::cout << '\n' << enemy.name << " is knocked back by the force, their health now at " << enemy.health << "!" << std::endl;
	}

	void defend(object& attacker) override {
		// Trees have tough bark that reduces damage
		int reducedDamage = attacker.damage / 4; // Reduced by 75% because of their tough bark
		health -= reducedDamage;
		std::cout << '\n' << name << "'s bark absorbs most of the attack, reducing the damage to " << reducedDamage << "!" << std::endl;
		std::cout << '\n' << name << "'s health is now " << health << "." << std::endl;
	}
};
class Item {
public:
	std::string name;
	std::string type;
	std::string description;



	Item(std::string n, std::string t, std::string d) : name(n), type(t), description(d) {}

	virtual void useItem(Item& item, object& enemy) {

		int effect = enemy.health -= 5;
		std::cout << '\n' << item.name << " pulses with a mysterious energy as it's used, sending a surge of power into the enemy. ";
		std::cout << '\n' << "The enemy stumbles, grimacing in pain, as their health is reduced to a mere " << effect << "!";
		std::cout << '\n' << " They now seem weaker, their strength waning under the effects of the " << item.name << "!" << std::endl;
	}

};

class Helper : public Item {
public:
	Helper(std::string n, std::string t, std::string d) : Item(n, t, d) {}

	virtual void useItem(Item& item, object& enemy) {
		int effect = enemy.health += 10;
		std::cout << '\n' << item.name << " gleams with a fiery aura as it is swung, cutting through the air with incredible force. ";
		std::cout << '\n' << "With a mighty slash, the blade lands on " << enemy.name << ", causing them to stagger back, blood spilling from the wound. ";
		std::cout << '\n' << "Their health is reduced to a mere " << effect << ", and they seem rattled, their confidence shattered by the sheer power of the blow!" << std::endl;
	}
};

class Destroyer : public Item {
public:
	Destroyer(std::string n, std::string t, std::string d) : Item(n, t, d) {}

	virtual void useItem(Item& item, object& enemy) {
		int effect = enemy.health -= 5;
		std::cout << '\n' << item.name << " gleams with a fiery aura as it is swung, cutting through the air with incredible force. ";
		std::cout << '\n' << "With a mighty slash, the blade lands on " << enemy.name << ", causing them to stagger back, blood spilling from the wound. ";
		std::cout << '\n' << "Their health is reduced to a mere " << effect << ", and they seem rattled, their confidence shattered by the sheer power of the blow!" << std::endl;
	}
};

class Sword : public Destroyer {
public:

	Sword(std::string n, std::string t, std::string d) : Destroyer(n, t, d) {}

	void useItem(Item& item, object& enemy) override {
		int effect = enemy.health -= 5;
		std::cout << '\n' << item.name << " gleams with a fiery aura as it is swung, cutting through the air with incredible force. ";
		std::cout << '\n' << "With a mighty slash, the blade lands on " << enemy.name << ", causing them to stagger back, blood spilling from the wound. ";
		std::cout << '\n' << "Their health is reduced to a mere " << effect << ", and they seem rattled, their confidence shattered by the sheer power of the blow!" << std::endl;
	}


};

class Potion : public Helper {
public:
	Potion(std::string n, std::string t, std::string d) : Helper(n, t, d) {}
	void useItem(Item& item, object& enemy) override {
		int effect = enemy.health += 10;

		std::cout << '\n' << item.name << " bubbles and fizzes as it's opened, releasing a pungent aroma of strange herbs and exotic ingredients. ";
		std::cout << "As " << enemy.name << " drinks the potion, a warm, soothing sensation spreads through their body. ";
		std::cout << '\n' << "Their health rapidly regenerates, returning to " << effect << " as the alchemical brew restores their vitality!" << std::endl;
	}



};

class Amulet : public Helper {
public:
	Amulet(std::string n, std::string t, std::string d) : Helper(n, t, d) {}

	void useItem(Item& item, object& enemy) override {
		int effect = enemy.health += 10;

		std::cout << '\n' << item.name << " glows with an ethereal light as it is activated, a soft hum of ancient power reverberating through the air. ";
		std::cout << '\n' << "The amulet's magic courses through " << enemy.name << "'s body, strengthening their resolve and spirit. ";
		std::cout << '\n' << "Their health has been restored to " << effect << ", as if a blessing has been bestowed upon them by forces unseen!" << std::endl;
	}

};

class Dagger : public Destroyer {
public:
	Dagger(std::string n, std::string t, std::string d) : Destroyer(n, t, d) {}

	void useItem(Item& item, object& enemy) override {
		int effect = enemy.health -= 5;
		std::cout << '\n' << item.name << " gleams with dark intent as it's driven swiftly into the enemy's side, barely making a sound. ";
		std::cout << '\n' << "The blade sinks deep, and the enemy gasps, their face twisting in surprise and pain. ";
		std::cout << '\n' << "Their health is now " << effect << ", the poison from the blade beginning to take hold. They stagger, their body slowing under the dagger's vicious bite." << std::endl;
	}

};

class Herb : public Helper {
public:
	Herb(std::string n, std::string t, std::string d) : Helper(n, t, d) {}

	void useItem(Item& item, object& enemy) override {
		int effect = enemy.health += 10;

		std::cout << '\n' << item.name << " is crushed and its essence released, filling the air with a fresh, earthy scent. ";
		std::cout << '\n' << "The healing power of the herb flows through " << enemy.name << "'s veins, revitalizing their body. ";
		std::cout << '\n' << "Their health has now surged to " << effect << ", the wounds closing as nature's magic takes root!" << std::endl;
	}

};

class Bow : public Destroyer {
public:

	Bow(std::string n, std::string t, std::string d) : Destroyer(n, t, d) {}

	void useItem(Item& item, object& enemy) override
	{
		int effect = enemy.health -= 5;
		std::cout << '\n' << item.name << " hums with tension as the arrow is drawn back, its tip gleaming in the light. ";
		std::cout << '\n' << "With a sharp twang, the bow releases, sending the arrow whistling through the air and striking " << enemy.name << " squarely in the chest. ";
		std::cout << '\n' << "They gasp in pain as the arrow lodges deep, their health plummeting to " << effect << ". The enemy stumbles, their breath shallow and erratic from the precision strike!" << std::endl;

	}


};


void pauseScreen();
void clearScreen();
void defend(std::vector<object*>mainlist, assassin& myassassin, std::vector<Destroyer*>& inventory, std::vector<Helper*>& resource);
std::vector<object*> list;
void initializeCharacterRoster(std::vector<object*>& list);
std::vector<Destroyer*>inventories;
std::vector<Helper*> resources;
void inventory(std::vector<Destroyer*>& inventories);
void resource(std::vector<Helper*>& resources);
void useItem(object& enemy, Destroyer& destroyer);
void useHelper(assassin& myassasin, Helper& helper);
int main() {
	initializeCharacterRoster(list);
	assassin* myassassin = new assassin("Seraphis the Phantom");

	std::vector<Destroyer*> inventories;
	std::vector<Helper*> resources;
	inventory(inventories);
	resource(resources);
	defend(list, *myassassin, inventories, resources);

}


void pauseScreen()
{

	std::cin.ignore();
	std::cin.get();
}
void clearScreen()
{
	system("CLS");
}
void defend(std::vector<object*>mainlist, assassin& myassassin, std::vector<Destroyer*>& inventory, std::vector<Helper*>& resource)
{
	std::random_device seed;
	std::default_random_engine e(seed());
	std::uniform_int_distribution<int> d(0, 4);




	while (myassassin.health > 0)
	{
		int randompick = d(e);
		std::cout << "\nThe ground trembles beneath your feet... brace yourself, a random enemy emerges from the mist! Press Enter to prepare for battle..." << std::endl;
		pauseScreen();
		std::cout << "\nSuddenly, from the shadows, " << mainlist[randompick]->name << " steps forward, their presence overwhelming the air around you... " << mainlist[randompick]->name << " has arrived!" << std::endl;
		auto currentfoe = mainlist[randompick]->name;
		std::random_device seedofDestroyer;
		std::default_random_engine r(seed());
		std::uniform_int_distribution<int> dee(0, 2);

		if (inventory.empty()) {
			std::cout << "Error: Inventory is empty!" << std::endl;
			return;
		}

		int weapons = dee(r);
		auto gun = inventory.at(weapons);



		std::random_device seedofHelper;
		std::default_random_engine t(seed());
		std::uniform_int_distribution<int> wee(0, 2);

		if (resource.empty()) {
			std::cout << "Error: Resource Box is empty!" << std::endl;
			return;
		}

		int potions = wee(t);
		auto box = resource.at(potions);





		std::cout << "\nThe air grows tense as the battle looms ahead. ";
		std::cout << "Do you wish to use a resource to aid you in this fight, ";
		std::cout << "or will you engage your enemy with a weapon? Choose carefully: ";
		std::cout << "\n(R)esource/(W)eapon): ";
		char answer;
		std::cin >> answer;
		switch (answer)
		{
		case 'r':
		case 'R':

			useHelper(myassassin, *box);
			break;

		case 'w':
		case 'W':
			useItem(myassassin, *gun);
			break;


		}


		std::random_device seed2;
		std::default_random_engine e2(seed2());
		std::uniform_int_distribution<int> d2(0, 1);

		int strategy = d2(e2);
		switch (strategy)
		{
		case 0:
			mainlist[randompick]->defend(myassassin);
			break;

		case 1:
			mainlist[randompick]->attack(myassassin);
			break;
		}

		bool enemiesLeft = false;
		for (auto& enemies : mainlist)
		{
			if (enemies->health > 0)
			{
				enemiesLeft = true;
			}
		}
		if (!enemiesLeft)
		{
			std::cout << "\nThe echoes of battle fade into the stillness of the mist... you stand victorious, the last of your foes vanquished. The realm is quiet once more." << std::endl;
		}
		if (mainlist[randompick]->health == 0)
		{
			mainlist.erase(mainlist.begin() + randompick);
			std::cout << "\nWith a final, resounding crash, "
				<< mainlist[randompick]->name << " crumbles to the ground, their life force extinguished. The air grows eerily silent as their presence fades from the world." << std::endl;

		}

		std::cout << "\n\nYour current health is: " << myassassin.health << " HP. You feel the weight of every wound, yet your resolve remains unbroken." << std::endl;

		std::cout << "\nThe enemies that stand before you, each with their own fates, are as follows:" << std::endl;
		for (auto& enemies : mainlist)
		{
			std::cout << enemies->name << " is at " << enemies->health << " HP" << std::endl;
		}




	}
}
void initializeCharacterRoster(std::vector<object*>& list) {
	goblin* mygoblin = new goblin("Grogar the Grim");
	assassin* myassassin = new assassin("Seraphis the Phantom");
	fairy* myfairy = new fairy("Ariella Moonwhisper");
	magician* mymagic = new magician("Oryn the Mystic");
	tree* mytree = new tree("Alderon the Eternal Root");
	witch* mywitch = new witch("Thalindra the Witch Queen");



	list.push_back(mygoblin);
	list.push_back(myfairy);
	list.push_back(mymagic);
	list.push_back(mytree);
	list.push_back(mywitch);





}

void inventory(std::vector<Destroyer*>& inventories)
{


	// Create Sword item
	Sword* sword = new Sword("Excalibur", "Weapon", "A legendary sword forged from the finest steel.");



	// Create Dagger item
	Dagger* dagger = new Dagger("Shadow Dagger", "Weapon", "A swift and deadly dagger, perfect for surprise attacks.");

	// Create Bow item
	Bow* bow = new Bow("Elven Longbow", "Weapon", "A bow crafted by the elves, capable of shooting arrows with perfect precision.");




	inventories.push_back(sword);
	inventories.push_back(dagger);
	inventories.push_back(bow);


}

void resource(std::vector<Helper*>& resources)
{
	Herb* herb = new Herb("Healing Herb", "Herb", "A magical herb that heals wounds.");

	// Create Potion item
	Potion* potion = new Potion("Potion of Vitality", "Potion", "A revitalizing potion that restores health.");
	// Create Amulet item
	Amulet* amulet = new Amulet("Amulet of Fortitude", "Accessory", "An amulet that boosts defense and protects from damage.");
	resources.push_back(herb);
	resources.push_back(potion);
	resources.push_back(amulet);
}

void useItem(object& enemy, Destroyer& destroyer)
{
	destroyer.useItem(destroyer, enemy);
}

void useHelper(assassin& myassasin, Helper& helper)
{
	helper.useItem(helper, myassasin);
}

