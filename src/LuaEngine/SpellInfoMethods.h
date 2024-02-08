/*
* Copyright (C) 2010 - 2024 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef SPELLINFOMETHODS_H
#define SPELLINFOMETHODS_H

namespace LuaSpellInfo
{
    int HasAttribute(lua_State* L, SpellInfo* spell_info)
    {
        uint8 attributeType = Eluna::CHECKVAL<uint8>(L, 2);
        uint32 attribute    = Eluna::CHECKVAL<uint32>(L, 3);

        bool hasAttribute = false;
        switch(attributeType)
        {
            case 0:
                hasAttribute = spell_info->HasAttribute(static_cast<SpellAttr0>(attribute));
                break;
            case 1:
                hasAttribute = spell_info->HasAttribute(static_cast<SpellAttr1>(attribute));
                break;
            case 2:
                hasAttribute = spell_info->HasAttribute(static_cast<SpellAttr2>(attribute));
                break;
            case 3:
                hasAttribute = spell_info->HasAttribute(static_cast<SpellAttr3>(attribute));
                break;
            case 4:
                hasAttribute = spell_info->HasAttribute(static_cast<SpellAttr4>(attribute));
                break;
            case 5:
                hasAttribute = spell_info->HasAttribute(static_cast<SpellAttr5>(attribute));
                break;
            case 6:
                hasAttribute = spell_info->HasAttribute(static_cast<SpellAttr6>(attribute));
                break;
            case 7:
                hasAttribute = spell_info->HasAttribute(static_cast<SpellAttr7>(attribute));
                break;
            case 8:
                hasAttribute = spell_info->HasAttribute(static_cast<SpellCustomAttributes>(attribute));
                break;
        }

        Eluna::Push(L, hasAttribute);
        return 1;
    }

    int GetAttributes(lua_State* L, SpellInfo* spell_info)
    {
        uint8 attributeType = Eluna::CHECKVAL<uint8>(L, 2);
        uint32 attributes;

        switch(attributeType)
        {
            case 0:
                attributes = spell_info->Attributes;
                break;
            case 1:
                attributes = spell_info->AttributesEx;
                break;
            case 2:
                attributes = spell_info->AttributesEx2;
                break;
            case 3:
                attributes = spell_info->AttributesEx3;
                break;
            case 4:
                attributes = spell_info->AttributesEx4;
                break;
            case 5:
                attributes = spell_info->AttributesEx5;
                break;
            case 6:
                attributes = spell_info->AttributesEx6;
                break;
            case 7:
                attributes = spell_info->AttributesEx7;
                break;
            case 8:
                attributes = spell_info->AttributesCu;
                break;
        }

        Eluna::Push(L, attributes);
        return 1;
    }

    int GetName(lua_State* L, SpellInfo* spell_info)
    {
        uint8 locale = Eluna::CHECKVAL<uint8>(L, 2, DEFAULT_LOCALE);

        Eluna::Push(L, spell_info->SpellName[static_cast<LocaleConstant>(locale)]);
        return 1;
    }


};
#endif
