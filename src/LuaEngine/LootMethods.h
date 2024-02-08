/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef LOOTMETHODS_H
#define LOOTMETHODS_H

namespace LuaLoot
{
    int IsLooted(lua_State* L, Loot* loot)
    {
        Eluna::Push(L, loot->isLooted());
        return 1;
    }
    
    int AddItem(lua_State* L, Loot* loot)
    {
        uint32 itemid = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 min_count = Eluna::CHECKVAL<uint32>(L, 3);
        uint32 max_count = Eluna::CHECKVAL<uint32>(L, 4);
        float chance = Eluna::CHECKVAL<float>(L, 5);
        uint16 loot_mode = Eluna::CHECKVAL<bool>(L, 6);
        bool needs_quest = Eluna::CHECKVAL<bool>(L, 7, false);
        
        for (LootItem& lootitem : loot->items)
        {
            if (lootitem.itemid == itemid && lootitem.count < 255)
            {
                lootitem.count += lootitem.count + min_count;
                return 0;
            }
        }
        
        LootStoreItem newLootStoreItem(itemid, 0, chance, needs_quest, loot_mode, 0, min_count, max_count);
        loot->AddItem(newLootStoreItem);
        return 0;
    }
    
    int HasItem(lua_State* L, Loot* loot)
    {
        uint32 itemid = Eluna::CHECKVAL<uint32>(L, 2, false);
        bool has_item = false;
        
        if ( itemid )
        {
            for (LootItem& lootitem : loot->items)
            {
                if (lootitem.itemid == itemid)
                    has_item = true;
            }
        }
        else
        {
            for (LootItem& lootitem : loot->items)
            {
                if (lootitem.itemid && lootitem.itemid != 0)
                has_item = true;
            }
        }

        Eluna::Push(L, has_item);
        return 1;
    }
    
    int RemoveItem(lua_State* L, Loot* loot)
    {
        uint32 itemid = Eluna::CHECKVAL<uint32>(L, 2);
        loot->items.erase(
          std::remove_if(
              loot->items.begin(), loot->items.end(), [itemid](const LootItem& item)
                {
                return item.itemid == itemid;
              }), loot->items.end());
        return 0;
    }
    
    int GetMoney(lua_State* L, Loot* loot)
    {
        Eluna::Push(L, loot->gold);
        return 1;
    }
    
    int SetMoney(lua_State* L, Loot* loot)
    {
        uint32 money = Eluna::CHECKVAL<uint32>(L, 2);
        loot->gold = money;
        return 0;
    }
    
    int GenerateMoney(lua_State* L, Loot* loot)
    {
        uint32 min = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 max = Eluna::CHECKVAL<uint32>(L, 3);
        loot->generateMoneyLoot(min, max);
        return 0;
    }
}

#endif
