#include <iostream>
#include <string>

// Animal class
class Animal {
protected:
    std::string name;
    int age;
    std::string species;

public:
    Animal(std::string name, int age, std::string species)
        : name(name), age(age), species(species) {}

    std::string getName() const { return name; }
    int getAge() const { return age; }
    std::string getSpecies() const { return species; }

    void setName(const std::string& name) { this->name = name; }
    void setAge(int age) { this->age = age; }
    void setSpecies(const std::string& species) { this->species = species; }

    virtual void makeSound() const = 0; // Pure virtual function for subclasses to override
};

// Hyena class
class Hyena : public Animal {
private:
    bool isLaughing;

public:
    Hyena(std::string name, int age, bool isLaughing)
        : Animal(name, age, "Hyena"), isLaughing(isLaughing) {}

    bool getIsLaughing() const { return isLaughing; }
    void setIsLaughing(bool isLaughing) { this->isLaughing = isLaughing; }

    void makeSound() const override {
        if (isLaughing) {
            std::cout << name << " is laughing!" << std::endl;
        } else {
            std::cout << name << " is quiet." << std::endl;
        }
    }
};

// Lion class
class Lion : public Animal {
private:
    int maneSize;

public:
    Lion(std::string name, int age, int maneSize)
        : Animal(name, age, "Lion"), maneSize(maneSize) {}

    int getManeSize() const { return maneSize; }
    void setManeSize(int maneSize) { this->maneSize = maneSize; }

    void makeSound() const override {
        std::cout << name << " roars!" << std::endl;
    }
};

// Tiger class
class Tiger : public Animal {
private:
    bool isStriped;

public:
    Tiger(std::string name, int age, bool isStriped)
        : Animal(name, age, "Tiger"), isStriped(isStriped) {}

    bool getIsStriped() const { return isStriped; }
    void setIsStriped(bool isStriped) { this->isStriped = isStriped; }

    void makeSound() const override {
        std::cout << name << " growls!" << std::endl;
    }
};

// Bear class
class Bear : public Animal {
private:
    int hibernationPeriod;

public:
    Bear(std::string name, int age, int hibernationPeriod)
        : Animal(name, age, "Bear"), hibernationPeriod(hibernationPeriod) {}

    int getHibernationPeriod() const { return hibernationPeriod; }
    void setHibernationPeriod(int hibernationPeriod) { this->hibernationPeriod = hibernationPeriod; }

    void makeSound() const override {
        std::cout << name << " growls loudly!" << std::endl;
    }
};

int main() {
    Hyena hyena("Shenzi", 5, true);
    Lion lion("Simba", 8, 30);
    Tiger tiger("Shere Khan", 6, true);
    Bear bear("Baloo", 10, 5);

    hyena.makeSound();
    lion.makeSound();
    tiger.makeSound();
    bear.makeSound();

    return 0;
}
