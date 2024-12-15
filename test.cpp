#include "solution.h"
#include <gtest/gtest.h>
#include <sstream>
#include <fstream>
#include <iostream>

// Заглушка для Observer
class DummyObserver : public Observer {
public:
    void update(const NPC& winner, const NPC& loser) override {
        // Пустая реализация для теста
    }
};

// Тест для фабрики
TEST(NPCFactoryTest, CreateBear) {
    auto bear = NPCFactory::createNPC("Bear", "Bear1", 0, 0);
    ASSERT_NE(bear, nullptr);
    EXPECT_EQ(bear->getType(), "Bear");
    EXPECT_EQ(bear->getName(), "Bear1");
    EXPECT_EQ(bear->getX(), 0);
    EXPECT_EQ(bear->getY(), 0);
}

// Тест для создания разных NPC
TEST(NPCFactoryTest, CreateDifferentNPCs) {
    auto bear = NPCFactory::createNPC("Bear", "Bear1", 0, 0);
    auto elf = NPCFactory::createNPC("Elf", "Elf1", 10, 10);
    auto bandit = NPCFactory::createNPC("Bandit", "Bandit1", 20, 20);

    ASSERT_NE(bear, nullptr);
    ASSERT_NE(elf, nullptr);
    ASSERT_NE(bandit, nullptr);

    EXPECT_EQ(bear->getType(), "Bear");
    EXPECT_EQ(elf->getType(), "Elf");
    EXPECT_EQ(bandit->getType(), "Bandit");
}

// Тест для боевого режима: Медведь убивает Эльфа
TEST(CombatVisitorTest, BearKillsElf) {
    DummyObserver observer;
    CombatVisitor combat(50, observer);

    auto bear = NPCFactory::createNPC("Bear", "Bear1", 0, 0);
    auto elf = NPCFactory::createNPC("Elf", "Elf1", 10, 10);

    // Имитируем бой
    combat.engage(*bear, *elf);

    // Проверка: Эльф должен быть убит
    EXPECT_TRUE(elf->isDead());
}

// Тест для боевого режима: Разбойник убивает Разбойника
TEST(CombatVisitorTest, BanditKillsBandit) {
    DummyObserver observer;
    CombatVisitor combat(50, observer);

    auto bandit1 = NPCFactory::createNPC("Bandit", "Bandit1", 0, 0);
    auto bandit2 = NPCFactory::createNPC("Bandit", "Bandit2", 10, 10);

    // Имитируем бой
    combat.engage(*bandit1, *bandit2);

    // Проверка: Один из разбойников должен быть убит
    EXPECT_TRUE(bandit2->isDead() || bandit1->isDead());
}

// Тест для сохранения и загрузки NPC
TEST(NPCManagerTest, SaveAndLoadNPCs) {
    std::vector<std::unique_ptr<NPC>> npcs;
    npcs.push_back(NPCFactory::createNPC("Bear", "Bear1", 0, 0));
    npcs.push_back(NPCFactory::createNPC("Elf", "Elf1", 10, 10));

    // Сохраняем NPC в файл
    NPCManager::saveToFile(npcs, "npcs.txt");

    // Загружаем NPC из файла
    auto loadedNpcs = NPCManager::loadFromFile("npcs.txt");

    // Проверка: количество загруженных NPC должно совпасть
    EXPECT_EQ(npcs.size(), loadedNpcs.size());
    EXPECT_EQ(npcs[0]->getName(), loadedNpcs[0]->getName());
    EXPECT_EQ(npcs[1]->getName(), loadedNpcs[1]->getName());
}

// Тест для записи событий в файл: FileObserver
TEST(FileObserverTest, RecordKillEventToFile) {
    // Создаем наблюдателя для записи в файл
    FileObserver fileObserver("test_log.txt");

    DummyObserver observer;
    CombatVisitor combat(150, fileObserver);

    auto bear = NPCFactory::createNPC("Bear", "Bear1", 0, 0);
    auto elf = NPCFactory::createNPC("Elf", "Elf1", 100, 100);

    // Имитируем бой
    combat.engage(*bear, *elf);

    // Проверка: после боя должно быть записано событие в файл
    std::ifstream file("test_log.txt");
    std::string line;
    ASSERT_TRUE(std::getline(file, line));
    EXPECT_NE(line.find("Event: Bear (Bear1) killed Elf (Elf1)"), std::string::npos);
}

// Тест для вывода события на экран: ScreenObserver
TEST(ScreenObserverTest, PrintKillEventToScreen) {
    // Захватываем вывод в строковый поток
    std::stringstream ss;
    std::streambuf* originalCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());  // Перенаправляем на строковый поток

    ScreenObserver screenObserver;
    DummyObserver observer;
    CombatVisitor combat(150, screenObserver);

    auto bear = NPCFactory::createNPC("Bear", "Bear1", 0, 0);
    auto elf = NPCFactory::createNPC("Elf", "Elf1", 100, 100);

    // Имитируем бой
    combat.engage(*bear, *elf);

    // Проверка: событие должно быть напечатано на экран
    std::string output = ss.str();
    EXPECT_NE(output.find("Event: Bear (Bear1) killed Elf (Elf1)"), std::string::npos);

    // Восстанавливаем стандартный вывод
    std::cout.rdbuf(originalCout);
}
