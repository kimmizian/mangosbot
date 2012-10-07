#pragma once

#include "strategy/actions/InventoryAction.h"

class Player;
class PlayerbotMgr;
class ChatHandler;

using namespace std;
using ai::InventoryAction;

class PlayerbotFactory : public InventoryAction
{
public:
    PlayerbotFactory(Player* bot, uint32 level, uint32 itemQuality) :
        bot(bot), level(level), itemQuality(itemQuality), InventoryAction(bot->GetPlayerbotAI(), "factory") {}

    static ObjectGuid GetRandomBot();
    void Randomize();
    void RandomizeForZone(uint32 mapId, float teleX, float teleY, float teleZ);

private:
    void InitSecondEquipmentSet();
    void InitEquipment();
    bool CanEquipItem(ItemPrototype const* proto, uint32 desiredQuality);
    bool CanEquipUnseenItem(uint8 slot, uint16 &dest, uint32 item);
    void InitSkills();
    void SetRandomSkill(uint16 id);
    void InitSpells();
    void ClearSpells();
    void InitAvailableSpells();
    void InitTalents();
    void InitTalents(uint32 specNo);
    void InitQuests();
    void InitPet();
    void ClearInventory();
    void InitAmmo();
    void InitMounts();
    void InitPotions();
    bool CanEquipArmor(ItemPrototype const* proto, uint8 slot);
    bool CanEquipWeapon(ItemPrototype const* proto, uint8 slot);
    void EnchantItem(Item* item);
    void AddItemStats(uint32 mod, uint8 &sp, uint8 &ap, uint8 &tank);
    bool CheckItemStats(uint8 sp, uint8 ap, uint8 tank);
    void CancelAuras();

private:
    Player* bot;
    uint32 level;
    uint32 itemQuality;
};