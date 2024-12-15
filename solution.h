#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

// Абстрактный класс Visitor для паттерна "Посетитель"
class Visitor {
public:
    virtual void visit(class Bear&) = 0;
    virtual void visit(class Elf&) = 0;
    virtual void visit(class Bandit&) = 0;
    virtual ~Visitor() = default;
};

// Абстрактный класс NPC
class NPC {
public:
    NPC(std::string name, int x, int y) : name(std::move(name)), x(x), y(y), m_isDead(false) {}
    virtual void accept(Visitor& visitor) = 0;
    virtual ~NPC() = default;

    const std::string& getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }
    bool isDead() const { return m_isDead; }  // Метод для проверки смерти
    void kill() { m_isDead = true; }  // Метод для убийства NPC
    virtual std::string getType() const = 0;

protected:
    std::string name;
    int x, y;
    bool m_isDead;  // Флаг, указывающий на смерть
};

// Классы-наследники NPC
class Bear : public NPC {
public:
    Bear(std::string name, int x, int y) : NPC(std::move(name), x, y) {}
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::string getType() const override { return "Bear"; }
};

class Elf : public NPC {
public:
    Elf(std::string name, int x, int y) : NPC(std::move(name), x, y) {}
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::string getType() const override { return "Elf"; }
};

class Bandit : public NPC {
public:
    Bandit(std::string name, int x, int y) : NPC(std::move(name), x, y) {}
    void accept(Visitor& visitor) override { visitor.visit(*this); }
    std::string getType() const override { return "Bandit"; }
};

// Наблюдатели для паттерна "Наблюдатель"
class Observer {
public:
    virtual void update(const NPC& winner, const NPC& loser) = 0;
    virtual ~Observer() = default;
};

class ScreenObserver : public Observer {
public:
    void update(const NPC& winner, const NPC& loser) override {
        std::cout << "Event: " << winner.getType() << " (" << winner.getName() << ") killed "
                  << loser.getType() << " (" << loser.getName() << ")\n";
    }
};

class FileObserver : public Observer {
public:
    explicit FileObserver(const std::string& filename) : file(filename, std::ios::out | std::ios::app) {}

    void update(const NPC& winner, const NPC& loser) override {
        file << "Event: " << winner.getType() << " (" << winner.getName() << ") killed "
             << loser.getType() << " (" << loser.getName() << ")\n";
    }

private:
    std::ofstream file;
};

// Класс CombatVisitor для реализации паттерна "Посетитель"
class CombatVisitor : public Visitor {
public:
    CombatVisitor(int maxDistance, Observer& observer) : maxDistance(maxDistance), observer(observer) {}

    void visit(Bear& bear) override { target = &bear; }
    void visit(Elf& elf) override { target = &elf; }
    void visit(Bandit& bandit) override { target = &bandit; }

    void engage(NPC& attacker, NPC& defender) {
        if (attacker.isDead() || defender.isDead()) {
            return;  // Если кто-то из NPC мертв, не проводим бой
        }

        double distance = std::sqrt(std::pow(attacker.getX() - defender.getX(), 2) +
                                    std::pow(attacker.getY() - defender.getY(), 2));
        if (distance <= maxDistance) {
            observer.update(attacker, defender);  // Сгенерируем событие
            defender.kill();  // Убиваем NPC
        }
    }

private:
    NPC* target = nullptr;
    int maxDistance;
    Observer& observer;
};

// Фабрика для создания NPC
class NPCFactory {
public:
    static std::unique_ptr<NPC> createNPC(const std::string& type, const std::string& name, int x, int y) {
        if (type == "Bear") {
            return std::make_unique<Bear>(name, x, y);
        } else if (type == "Elf") {
            return std::make_unique<Elf>(name, x, y);
        } else if (type == "Bandit") {
            return std::make_unique<Bandit>(name, x, y);
        }
        return nullptr;
    }
};

// Утилита для сохранения и загрузки NPC
class NPCManager {
public:
    static void saveToFile(const std::vector<std::unique_ptr<NPC>>& npcs, const std::string& filename) {
        std::ofstream file(filename);
        for (const auto& npc : npcs) {
            file << npc->getType() << " " << npc->getName() << " " << npc->getX() << " " << npc->getY() << "\n";
        }
    }

    static std::vector<std::unique_ptr<NPC>> loadFromFile(const std::string& filename) {
        std::vector<std::unique_ptr<NPC>> npcs;
        std::ifstream file(filename);
        std::string type, name;
        int x, y;
        while (file >> type >> name >> x >> y) {
            npcs.push_back(NPCFactory::createNPC(type, name, x, y));
        }
        return npcs;
    }
};

#endif // SOLUTION_H
