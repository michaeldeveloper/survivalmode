#include "ScriptPCH.h"

#define MAX_PLAYERS		2

class survival_modes : public CreatureScript
{
public:
	survival_modes() : CreatureScript("survival_mode") {}
	std::list<Unit *> list;
	bool OnGossipHello(Player* player, Creature* creature)
	{
		creature->MonsterYell("WHY YOU SPEAK?!", LANG_UNIVERSAL, 0);
		player->GetPartyMembers(list);
		if (list.size() == MAX_PLAYERS)
		{
			creature->MonsterSay("You have right amount of players, of 2.", LANG_UNIVERSAL, 0);
			uint64 player_guid = player->GetGUID();	
			if (player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GROUP_LEADER))
			{
				creature->MonsterSay("Gay leader you have.", LANG_UNIVERSAL, 0);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_BATTLE, "Survival Game", GOSSIP_SENDER_MAIN, 0);
				player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Nevermind", GOSSIP_SENDER_MAIN, 1);
			}
		}
		player->SEND_GOSSIP_MENU(1, creature->GetGUID());

		list.clear();
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
	{
		return true;
	}
};
void AddSC_survival_mode()
{
	new survival_modes;
}
