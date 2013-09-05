#include "ScriptPCH.h"

class survival_modes : public CreatureScript
{
public:
	survival_modes() : CreatureScript("survival_mode") {}

	bool OnGossipHello(Player* player, Creature* creature)
	{
		
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
	{

	}
};

void AddSC_survival_mode()
{
	new survival_modes;
}
