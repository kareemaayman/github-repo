#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Character {
protected:
    std::string name; // Character's name
    int health;       // Character's health points
    int energy;       // Character's energy points

public:
    // Constructor to initialize the character's name, health, and energy
    Character(std::string n, int h, int e) : name(n), health(h), energy(e) {}

    // Pure virtual function for attacking an opponent
    virtual void attack(Character &opponent) = 0;

    // Pure virtual function for using a shield to mitigate damage
    virtual void useShield(int &damage, const std::string &weapon) = 0;

    // Check if the character is still alive
    bool isAlive() { return health > 0; }

    // Get the character's name
    std::string getName() { return name; }

    // Get the character's current health
    int getHealth() { return health; }

    // Get the character's current energy
    int getEnergy() { return energy; }

    // Reduce the character's health by the specified damage amount
    void takeDamage(int damage) { health -= damage; }

    // Reduce the character's energy by the specified amount
    void consumeEnergy(int amount) { energy -= amount; }
};

class Batman : public Character {
private:
    int grappleGunUses = 5; // Number of uses allowed for the Grapple Gun
    int explosiveGelUses = 3; // Number of uses allowed for the Explosive Gel
    int batclawUses = 1; // Number of uses allowed for the Batclaw
    int smokePelletUses = 2; // Number of uses allowed for the Smoke Pellet

public:
    // Constructor to initialize Batman with specific name, health, and energy
    Batman() : Character("Batman", 100, 500) {}

    // Override the attack function to define Batman's attack behavior
    void attack(Character &opponent) override {
        int choice = rand() % 4; // Randomly choose a weapon
        int damage = 0;
        int energyCost = 0;
        std::string weapon;

        switch (choice) {
            case 0:
                weapon = "Batarang";
                damage = 11;
                energyCost = 50;
                break;
            case 1:
                if (grappleGunUses > 0) {
                    weapon = "Grapple Gun";
                    damage = 18;
                    energyCost = 88;
                    grappleGunUses--;
                } else {
                    attack(opponent); // Retry with another weapon
                    return;
                }
                break;
            case 2:
                if (explosiveGelUses > 0) {
                    weapon = "Explosive Gel";
                    damage = 10;
                    energyCost = 92;
                    explosiveGelUses--;
                } else {
                    attack(opponent); // Retry with another weapon
                    return;
                }
                break;
            case 3:
                if (batclawUses > 0) {
                    weapon = "Batclaw";
                    damage = 20;
                    energyCost = 120;
                    batclawUses--;
                } else {
                    attack(opponent); // Retry with another weapon
                    return;
                }
                break;
        }

        if (energy >= energyCost) {
            std::cout << name << " attacks with " << weapon << ", causing " << damage << " damage.\n";
            consumeEnergy(energyCost);
            std::cout << name << " has " << energy << " energy remaining.\n";
            opponent.useShield(damage, weapon);
            opponent.takeDamage(damage);
            std::cout << opponent.getName() << " has " << opponent.getHealth() << " health remaining.\n";
        } else {
            std::cout << name << " does not have enough energy to use " << weapon << ".\n";
        }
    }

    // Override the useShield function to define Batman's shield behavior
    void useShield(int &damage, const std::string &weapon) override {
        int choice = rand() % 2; // Randomly choose a shield
        int energyCost = 0;
        int damageReduction = 0;
        std::string shield;

        switch (choice) {
            case 0:
                shield = "Cape Glide";
                damageReduction = damage * 0.4;
                energyCost = 20;
                break;
            case 1:
                if (smokePelletUses > 0) {
                    shield = "Smoke Pellet";
                    damageReduction = damage * 0.9;
                    energyCost = 50;
                    smokePelletUses--;
                } else {
                    useShield(damage, weapon); // Retry with another shield
                    return;
                }
                break;
        }

        if (energy >= energyCost) {
            damage -= damageReduction;
            consumeEnergy(energyCost);
            std::cout << name << " uses " << shield << ", reducing damage by " << damageReduction << ".\n";
            std::cout << name << " has " << energy << " energy remaining.\n";
        } else {
            std::cout << name << " does not have enough energy to use " << shield << ".\n";
        }
    }
};

class Joker : public Character {
private:
    int laughingGasUses = 8; // Number of uses allowed for the Laughing Gas
    int acidFlowerUses = 3; // Number of uses allowed for the Acid Flower
    int rubberChickenUses = 3; // Number of uses allowed for the Rubber Chicken

public:
    // Constructor to initialize Joker with specific name, health, and energy
    Joker() : Character("Joker", 100, 500) {}

    // Override the attack function to define Joker's attack behavior
    void attack(Character &opponent) override {
        int choice = rand() % 3; // Randomly choose a weapon
        int damage = 0;
        int energyCost = 0;
        std::string weapon;

        switch (choice) {
            case 0:
                weapon = "Joy Buzzer";
                damage = 8;
                energyCost = 40;
                break;
            case 1:
                if (laughingGasUses > 0) {
                    weapon = "Laughing Gas";
                    damage = 13;
                    energyCost = 56;
                    laughingGasUses--;
                } else {
                    attack(opponent); // Retry with another weapon
                    return;
                }
                break;
            case 2:
                if (acidFlowerUses > 0) {
                    weapon = "Acid Flower";
                    damage = 22;
                    energyCost = 100;
                    acidFlowerUses--;
                } else {
                    attack(opponent); // Retry with another weapon
                    return;
                }
                break;
        }

        if (energy >= energyCost) {
            std::cout << name << " attacks with " << weapon << ", causing " << damage << " damage.\n";
            consumeEnergy(energyCost);
            std::cout << name << " has " << energy << " energy remaining.\n";
            opponent.useShield(damage, weapon);
            opponent.takeDamage(damage);
            std::cout << opponent.getName() << " has " << opponent.getHealth() << " health remaining.\n";
        } else {
            std::cout << name << " does not have enough energy to use " << weapon << ".\n";
        }
    }

    // Override the useShield function to define Joker's shield behavior
    void useShield(int &damage, const std::string &weapon) override {
        int choice = rand() % 2; // Randomly choose a shield
        int energyCost = 0;
        int damageReduction = 0;
        std::string shield;

        switch (choice) {
            case 0:
                if (weapon != "Batclaw") {
                    shield = "Trick Shield";
                    damageReduction = damage * 0.32;
                    energyCost = 15;
                }
                break;
            case 1:
                if (weapon != "Batclaw" && rubberChickenUses > 0) {
                    shield = "Rubber Chicken";
                    damageReduction = damage * 0.8;
                    energyCost = 40;
                    rubberChickenUses--;
                } else {
                    useShield(damage, weapon); // Retry with another shield
                    return;
                }
                break;
        }

        if (energy >= energyCost && !shield.empty()) {
            damage -= damageReduction;
            consumeEnergy(energyCost);
            std::cout << name << " uses " << shield << ", reducing damage by " << damageReduction << ".\n";
            std::cout << name << " has " << energy << " energy remaining.\n";
        } else {
            std::cout << name << " does not have enough energy to use " << shield << ".\n";
        }
    }
};

void fight(Character &c1, Character &c2) {
    while (c1.isAlive() && c2.isAlive() && c1.getEnergy() > 20 && c2.getEnergy() > 15) {
        c1.attack(c2);
        if (!c2.isAlive()) {
            std::cout << c1.getName() << " wins!\n";
            break;
        }
        if (c2.getEnergy() <= 15) { //Joker can't perform any action with energy less than 215
            std::cout << c2.getName() << " doesn't have enough energy \n";
            std::cout << c1.getName() << " wins!\n";
            break;
        }

        c2.attack(c1);
        if (!c1.isAlive()) {
            std::cout << c2.getName() << " wins!\n";
            break;
        }
        if (c1.getEnergy() <= 20) { //Batman can't perform any action with energy less than 20
            std::cout << c1.getName() << " doesn't have enough energy \n";
            std::cout << c2.getName() << " wins!\n";
            break;
        }
    }
    std::cout << "Final State:\n";
    std::cout << c1.getName() << " - Health: " << c1.getHealth() << ", Energy: " << c1.getEnergy() << "\n";
    std::cout << c2.getName() << " - Health: " << c2.getHealth() << ", Energy: " << c2.getEnergy() << "\n";
}

int main() {
    srand(time(0)); // Seed for random number generation
    Batman batman;
    Joker joker;
    fight(batman, joker);
    return 0;
}
