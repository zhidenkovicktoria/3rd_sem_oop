#include "solution.h"

int main() {
    // Создаем наблюдателей
    ScreenObserver screenObserver;
    FileObserver fileObserver("battle_log.txt");

    // Создаем список NPC через фабрику
    std::vector<std::unique_ptr<NPC>> npcs;
    npcs.push_back(NPCFactory::createNPC("Bear", "Bear1", 100, 100));
    npcs.push_back(NPCFactory::createNPC("Elf", "Elf1", 120, 110));
    npcs.push_back(NPCFactory::createNPC("Bandit", "Bandit1", 200, 200));

    // Вывод начального состояния NPC
    std::cout << "Initial state of NPCs:\n";
    for (const auto& npc : npcs) {
        std::cout << npc->getType() << " (" << npc->getName() << ") at (" 
                  << npc->getX() << ", " << npc->getY() << ")\n";
    }

    // Создаем CombatVisitor для ведения боевых действий
    CombatVisitor combatVisitor(150, screenObserver);  // Максимальное расстояние для сражений = 150

    std::cout << "\nStarting the battle:\n";
    
    // Бой между NPC
    combatVisitor.engage(*npcs[0], *npcs[1]);  // Медведь сражается с Эльфом
    combatVisitor.engage(*npcs[0], *npcs[2]);  // Медведь сражается с Бандитом
    combatVisitor.engage(*npcs[1], *npcs[2]);  // Эльф сражается с Бандитом

    // Выводим состояние NPC после сражений
    std::cout << "\nAfter the battle:\n";
    for (const auto& npc : npcs) {
        if (!npc->isDead()) {
            std::cout << npc->getType() << " (" << npc->getName() << ") at ("
                      << npc->getX() << ", " << npc->getY() << ")\n";
        }
    }

    return 0;
}
