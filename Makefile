CXX=g++

CXXFLAGS = -Wall -std=c++11 -g

POTIONS.O = potions_health.o potions_special.o potions_combat.o

WEAPONS.O = weapons_magic_sword.o weapons_alcohol_bottle.o\
		weapons_katar_dagger.o weapons_upgrade.o

MONSTERS.O = angry_spider.o berserker.o bulky_orc.o goblin.o\
		chimera.o green_slime.o necromancer.o skeleton_king.o\
		golem.o skeleton_soldier.o
OBJS = dungeon.o final_battle.o doggo.o floor.o merchant.o inventory.o\
		chest.o ability_scroll.o lamp.o herb.o feather.o potions_combat.o\
		potions_health.o potions_special.o weapons_alcohol_bottle.o\
		weapons_katar_dagger.o weapons_magic_sword.o weapons_upgrade.o\
		armor_upgrade.o armour_basic_armour.o ladder.o no_event.o battle.o\
		$(MONSTERS.O) items.o adventurer.o assassin.o alcoholic.o character.o\
		special_moves.o event.o monster.o

main: main.o dungeon.o adventurer.o assassin.o alcoholic.o
	$(CXX) $(CXXFLAGS) -o main main.o $(OBJS)

main.o: $(OBJS)
	$(CXX) $(CXXFLAGS) -c main.cpp

dungeon.o: dungeon.cpp dungeon.h floor.o character.o inventory.o final_battle.o
	$(CXX) $(CXXFLAGS) -c dungeon.cpp

final_battle.o: final_battle.cpp final_battle.h battle.o doggo.o
	$(CXX) $(CXXFLAGS) -c final_battle.cpp

doggo.o: doggo.cpp doggo.h monster.o
	$(CXX) $(CXXFLAGS) -c doggo.cpp 

floor.o: floor.cpp floor.h character.o inventory.o no_event.o battle.o\
		 ladder.o merchant.o chest.o
	$(CXX) $(CXXFLAGS) -c floor.cpp

merchant.o: merchant.cpp merchant.h items.o inventory.o event.o
	$(CXX) $(CXXFLAGS) -c merchant.cpp

inventory.o: inventory.cpp inventory.h character.o items.o $(POTIONS.O)\
			 $(WEAPONS.O) lamp.o herb.o feather.o
	$(CXX) $(CXXFLAGS) -c inventory.cpp

chest.o: chest.cpp chest.h event.o weapons_upgrade.o\
		 armor_upgrade.o lamp.o herb.o ability_scroll.o
	$(CXX) $(CXXFLAGS) -c chest.cpp

ability_scroll.o: ability_scroll.cpp ability_scroll.h items.o
	$(CXX) $(CXXFLAGS) -c ability_scroll.cpp

lamp.o: lamp.cpp lamp.h items.o
	$(CXX) $(CXXFLAGS) -c lamp.cpp

herb.o: herb.cpp herb.h items.o
	$(CXX) $(CXXFLAGS) -c herb.cpp 

feather.o: feather.cpp feather.h items.o
	$(CXX) $(CXXFLAGS) -c feather.cpp 

potions_combat.o: potions_combat.cpp potions_combat.h items.o
	$(CXX) $(CXXFLAGS) -c potions_combat.cpp 

potions_health.o: potions_health.cpp potions_health.h items.o
	$(CXX) $(CXXFLAGS) -c potions_health.cpp

potions_special.o: potions_special.cpp potions_special.h items.o
	$(CXX) $(CXXFLAGS) -c potions_special.cpp

weapons_alcohol_bottle.o: weapons_alcohol_bottle.cpp weapons_alcohol_bottle.h items.o
	$(CXX) $(CXXFLAGS) -c weapons_alcohol_bottle.cpp

weapons_katar_dagger.o: weapons_katar_dagger.cpp weapons_katar_dagger.h items.o
	$(CXX) $(CXXFLAGS) -c weapons_katar_dagger.cpp

weapons_magic_sword.o: weapons_magic_sword.cpp weapons_magic_sword.h items.o
	$(CXX) $(CXXFLAGS) -c weapons_magic_sword.cpp

weapons_upgrade.o: weapons_upgrade.cpp weapons_upgrade.h items.o
	$(CXX) $(CXXFLAGS) -c weapons_upgrade.cpp

armor_upgrade.o: armor_upgrade.cpp armor_upgrade.h items.o
	$(CXX) $(CXXFLAGS) -c armor_upgrade.cpp

armour_basic_armour.o: armour_basic_armour.cpp armour_basic_armour.h items.o
	$(CXX) $(CXXFLAGS) -c armour_basic_armour.cpp

ladder.o: ladder.cpp ladder.h event.o
	$(CXX) $(CXXFLAGS) -c ladder.cpp

no_event.o: no_event.cpp no_event.h event.o
	$(CXX) $(CXXFLAGS) -c no_event.cpp

battle.o: battle.cpp battle.h event.o $(MONSTERS.O)
	$(CXX) $(CXXFLAGS) -c battle.cpp

angry_spider.o: angry_spider.cpp angry_spider.h monster.o
	$(CXX) $(CXXFLAGS) -c angry_spider.cpp

berserker.o: berserker.cpp berserker.h monster.o
	$(CXX) $(CXXFLAGS) -c berserker.cpp

bulky_orc.o: bulky_orc.cpp bulky_orc.cpp monster.o
	$(CXX) $(CXXFLAGS) -c bulky_orc.cpp

goblin.o: goblin.cpp goblin.h monster.o
	$(CXX) $(CXXFLAGS) -c goblin.cpp

chimera.o: chimera.cpp chimera.h monster.o
	$(CXX) $(CXXFLAGS) -c chimera.cpp

green_slime.o: green_slime.cpp green_slime.h monster.o
	$(CXX) $(CXXFLAGS) -c green_slime.cpp

necromancer.o: necromancer.cpp necromancer.h monster.o
	$(CXX) $(CXXFLAGS) -c necromancer.cpp 

skeleton_king.o: skeleton_king.cpp skeleton_king.h monster.o
	$(CXX) $(CXXFLAGS) -c skeleton_king.cpp 

golem.o: golem.cpp golem.h monster.o
	$(CXX) $(CXXFLAGS) -c golem.cpp

skeleton_soldier.o: skeleton_soldier.cpp skeleton_soldier.h monster.o
	$(CXX) $(CXXFLAGS) -c skeleton_soldier.cpp
	
items.o: items.cpp items.h character.o
	$(CXX) $(CXXFLAGS) -c items.cpp

adventurer.o: adventurer.cpp adventurer.h character.o
	$(CXX) $(CXXFLAGS) -c adventurer.cpp

assassin.o: assassin.cpp assassin.h character.o
	$(CXX) $(CXXFLAGS) -c assassin.cpp

alcoholic.o: alcoholic.cpp alcoholic.h character.h
	$(CXX) $(CXXFLAGS) -c alcoholic.cpp

character.o: character.cpp character.h special_moves.o monster.o
	$(CXX) $(CXXFLAGS) -c character.cpp

special_moves.o: special_moves.cpp special_moves.h
	$(CXX) $(CXXFLAGS) -c special_moves.cpp

event.o: event.cpp event.h
	$(CXX) $(CXXFLAGS) -c event.cpp

monster.o: monster.cpp monster.h
	$(CXX) $(CXXFLAGS) -c monster.cpp

clean:
	rm -f *.o main