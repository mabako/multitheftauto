/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*               (Shared logic for modifications)
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/shared_logic/CWeaponNames.cpp
*  PURPOSE:     Weapon names class
*  DEVELOPERS:  Christian Myhre Lundheim <>
*
*****************************************************************************/

#include <StdInc.h>

using namespace std;

char szWeaponNameEmpty [] = "";

struct SWeaponName
{
    char szName [32];
};
struct SWeaponSlot
{
    char cSlot;
};

SWeaponName WeaponNames [] =
{ {"Melee"}, {"Brassknuckle"}, {"Golfclub"}, {"Nightstick"}, {"Knife"},
{"Bat"}, {"Shovel"}, {"Poolstick"}, {"Katana"}, {"Chainsaw"}, 
{"Dildo"}, {"Dildo"}, {"Vibrator"}, {"Vibrator"}, {"Flower"},
{"Cane"}, {"Grenade"}, {"Teargas"}, {"Molotov"}, {"Rocket"},
{"Rocket"}, {"Freefall Bomb"}, {"Colt 45"}, {"Silenced"}, {"Deagle"},
{"Shotgun"}, {"Sawed-off"}, {"Combat Shotgun"}, {"Uzi"}, {"MP5"},
{"AK-47"}, {"M4"}, {"Tec-9"}, {"Rifle"}, {"Sniper"},
{"Rocket Launcher"}, {"Rocket Launcher HS"}, {"Flamethrower"}, {"Minigun"}, {"Satchel"},
{"Bomb"}, {"Spraycan"}, {"Fire Extinguisher"}, {"Camera"}, {"Nightvision"}, {"Infrared"},
{"Parachute"}, {"Last Weapon"}, {"Armour"}, {"Rammed"}, {"Ranover"}, {"Explosion"}, {"Driveby"}, 
{"Drowned"}, {"Fall"}, {"Unknown"}, {"Melee"}, {"Weapon"}, {"Flare"}, { "Tank Grenade" } };

SWeaponSlot WeaponIDs [] =
{{0},{0},{1},{1},{1},{1},{1},{1},{1},{1},{10},{10},{10},{-1},{10},{10},{8},{8},
{8},{-1},{-1},{-1},{2},{2},{2},{3},{3},{3},{4},{4},{5},{5},{4},{6},{6},{7},
{7},{7},{7},{8},{12},{9},{9},{9},{11},{11},{11},{-1}};


unsigned char CWeaponNames::GetWeaponID ( const char* szName )
{
    // If the specified string was empty, return 0
    if ( szName [0] == 0 ) return 0xFF;

    // Look for it in our table
    for ( unsigned int i = 0; i < sizeof(WeaponNames); i++ )
    {
        if ( stricmp ( szName, WeaponNames [i].szName ) == 0 )
        {
            return i;
        }
    }

    return 0xFF;
}


const char* CWeaponNames::GetWeaponName ( unsigned char ucID )
{
    if ( ucID < sizeof(WeaponNames) )
    {
        return WeaponNames [ucID].szName;
    }

    return szWeaponNameEmpty;
}

char CWeaponNames::GetSlotFromWeapon ( unsigned char ucID )
{
    if ( ucID < sizeof(WeaponIDs) )
    {
        return WeaponIDs [ucID].cSlot;
    }

    return -1;
}