/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef PETMETHODS_H
#define PETMETHODS_H

namespace LuaPet
{
    /**
     * Returns the native [Pet] scale.
     *
     * @return Float scale
     */
    int GetNativeObjectScale(lua_State* L, Pet* pet)
    {
        Eluna::Push(L, pet->GetNativeObjectScale());
        return 1;
    }

    /**
     * Returns the [Pet] type.
     *
     * @return uint8 type : the actual [Pet] type
     */
    int GetPetType(lua_State* L, Pet* pet)
    {
        Eluna::Push(L, pet->getPetType());
        return 1;
    }

    /**
    * Set new [Pet] specified type.
    *
    * PetType // 8 Type
    * {
    *     SUMMON_PET                  = 0,
    *     HUNTER_PET                  = 1,
    *     MAX_PET_TYPE                = 4
    * }
    *
    * @param uint8 type : new type for [Pet]
    */
    int SetPetType(lua_State* L, Pet* pet)
    {
        uint8 type = Eluna::CHECKVAL<uint8>(L, 2);

        pet->setPetType((PetType)type);
        return 0;
    }

    /**
    * Return true or false if [Pet] is controlled
    *
    * @return bool is_controller : true or false if is controlled
    */
    int IsControlled(lua_State* L, Pet* pet)
    {
        Eluna::Push(L, pet->isControlled());
        return 1;
    }

    /**
    * Return true or false if [Pet] is temporary summoned
    *
    * @return bool is_temporary : true or false if is temporary summoned
    */
    int IsTemporarySummoned(lua_State* L, Pet* pet)
    {
        Eluna::Push(L, pet->isTemporarySummoned());
        return 1;
    }

    /**
    * Return true or false if [Pet] is permanent for [Player]
    *
    * @param [Player] player : player
    *
    * @return bool is_permanent : true or false if is permanent pet for [Player]
    */
    int IsPermanentPetFor(lua_State* L, Pet* pet)
    {
        Player* player = Eluna::CHECKOBJ<Player>(L, 2);
            Eluna::Push(L, pet->IsPermanentPetFor(player));
        return 1;
    }

    int SavePetToDB(lua_State* L, Pet* pet)
    {
        uint8 mode = Eluna::CHECKVAL<int>(L, 2, PET_SAVE_AS_DELETED);
        pet->SavePetToDB((PetSaveMode)mode);
        return 0;
    }

    /**
     * Remove [Pet] with PetSaveMode as a parameter to determine how a pet should be removed.
     *
     * enum PetSaveMode // 8 Mode
     * {
     *   PET_SAVE_AS_DELETED         = -1,                        // not saved in fact
     *   PET_SAVE_AS_CURRENT         =  0,                        // in current slot (with player)
     *   PET_SAVE_FIRST_STABLE_SLOT  =  1,
     *   PET_SAVE_LAST_STABLE_SLOT   =  MAX_PET_STABLES,          // last in DB stable slot index (including), all higher have same meaning as PET_SAVE_NOT_IN_SLOT
     *   PET_SAVE_NOT_IN_SLOT        =  100                       // for avoid conflict with stable size grow will use 100
     * };
     *
     * @param uint8 mode : entry of the creature you want for create [Pet]
     * @param bool return_reagent : the pet's summoning reagent (like a scroll or a whistle) is returned to the player's inventory.
     */
    int Remove(lua_State* L, Pet* pet)
    {
        uint8 mode = Eluna::CHECKVAL<int8>(L, 2, PET_SAVE_AS_DELETED);
        bool return_reagent = Eluna::CHECKVAL<bool>(L, 3, false);

        pet->Remove((PetSaveMode)mode, return_reagent);
        return 0;
    }

    int SetDuration(lua_State* L, Pet* pet)
    {
        uint32 duration = Eluna::CHECKVAL<uint32>(L, 2);
        pet->SetDuration(Milliseconds(duration));
        return 0;
    }
}


#endif
