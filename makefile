CXX=g++

CXXFLAGS = -Wall -std=c++11 -g

POTIONS.O = potions_health.o potions_special.o potions_combat.o

WEAPONS.O = weapons_magic_sword.o weapons_alcohol_bottle.o\
		weapons_katar_dagger.o weapons_upgrade.o

MONSTERS.O = angry_spider.o berserker.o bulky_orc.o goblin.o\
		chimera.o green_slime.o necromamcer.o skeleton_king.o\
		golem.o skeleton_soldier.o

main.o: dungeon.o adventurer.o assassin.o alcoholic.o
	$(CXX) $(CXXFLAGS) -o main main.cpp

dungeon.o: floor.o character.o inventory.o final_battle.o
	$(CXX) $(CXXFLAGS) dungeon.h

final_battle.o: battle.o doggo.o
	$(CXX) $(CXXFLAGS) final_battle.h

doggo.o: monster.o
	$(CXX) $(CXXFLAGS) doggo.h

floor.o: character.o inventory.o no_event.o battle.o ladder.o\
		merchant.o chest.o
	$(CXX) $(CXXFLAGS) floor.h

merchant.o: items.o inventory.o event.o
	$(CXX) $(CXXFLAGS) merchant.h

inventory.o: character.o items.o $(POTIONS.O) $(WEAPONS.O)\
		lamp.o herb.o feather.o
	$(CXX) $(CXXFLAGS) inventory.h

chest.o: event.o weapons_upgrade.o armor_upgrade.o\
		lamp.o herb.o ability_scroll.o
	$(CXX) $(CXXFLAGS) chest.h

ability_scroll.o: items.o
	$(CXX) $(CXXFLAGS) ability_scroll.h

lamp.o: items.o
	$(CXX) $(CXXFLAGS) lamp.h

herb.o: items.o
	$(CXX) $(CXXFLAGS) herb.h

feather.o: items.o
	$(CXX) $(CXXFLAGS) feather.h

potions_combat.o: items.o
	$(CXX) $(CXXFLAGS) potions_combat.h

potions_health.o: items.o
	$(CXX) $(CXXFLAGS) potions_health.h

potions_special.o: items.o
	$(CXX) $(CXXFLAGS) potions_special.h

weapons_alcohol_bottle.o: items.o
	$(CXX) $(CXXFLAGS) weapons_alcohol_bottle.h

weapons_katar_dagger.o: items.o
	$(CXX) $(CXXFLAGS) weapons_katar_dagger.h

weapons_magic_sword.o: items.o
	$(CXX) $(CXXFLAGS) weapons_magic_sword.h

weapons_upgrade.o: items.o
	$(CXX) $(CXXFLAGS) weapons_upgrade.h

ladder.o: event.o
	$(CXX) $(CXXFLAGS) ladder.h

no_event.o: event.o
	$(CXX) $(CXXFLAGS) no_event.h

battle.o: event.o $(MONSTERS.O)
	$(CXX) $(CXXFLAGS) battle.h

angry_spider.o: monster.o
	$(CXX) $(CXXFLAGS) angry_spider.h

berserker.h: monster.o
	$(CXX) $(CXXFLAGS) berserker.h

bulky_orc.h: monster.o
	$(CXX) $(CXXFLAGS) bulky_orc.h

goblin.o: monster.o
	$(CXX) $(CXXFLAGS) goblin.h

chimera.o: monster.o
	$(CXX) $(CXXFLAGS) chimera.h

green_slime.o: monster.o
	$(CXX) $(CXXFLAGS) green_slime.h

necromancer.o: monster.o
	$(CXX) $(CXXFLAGS) necromancer.h

skeleton_king.o: monster.o
	$(CXX) $(CXXFLAGS) skeleton_king.h

golem.o: monster.o
	$(CXX) $(CXXFLAGS) golem.h

skeleton_soldier.o: monster.o
	$(CXX) $(CXXFLAGS) skeleton_soldier.h
	
items.o: character.o
	$(CXX) $(CXXFLAGS) items.h

adventurer.o: character.o
	$(CXX) $(CXXFLAGS) adventurer.h

assassin.o: character.o
	$(CXX) $(CXXFLAGS) assasin.h

alcoholic.o: character.o
	$(CXX) $(CXXFLAGS) alcoholic.h

character.o: special_moves.o monster.o
	$(CXX) $(CXXFLAGS) character.h

              
