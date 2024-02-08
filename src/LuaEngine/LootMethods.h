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
}

#endif
