#include "ScriptPCH.h"


#define MAX_PLAYERS		5

class survival_modes : public CreatureScript
{
public:
	survival_modes() : CreatureScript("survival_mode") {}
	std::list<Unit *> list;
	bool OnGossipHello(Player* player, Creature* creature)
	{
		 player->GetPartyMembers(list);
		 if (list.max_size() == MAX_PLAYERS)
		 {
			 if (player->GetCharmerOrOwnerGUID == player)
			 {
				 player->ADD_GOSSIP_ITEM();
			 }
		 }


	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
	{

	}
};
void AddSC_survival_mode()
{
	new survival_modes;
}
