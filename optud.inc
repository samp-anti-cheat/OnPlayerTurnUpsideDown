/*
OnPlayerTurnUpsideDown.
*/

#if defined _OPTUD_included
    #endinput
#endif
#define _OPTUD_included

#include <a_samp>
#include <Pawn.RakNet>

#if ! defined PAWNRAKNET_INC_
    #error You must have Pawn.Raknet include in order to use this one.
#endif

forward OnAntiCheatTurnUpsideDown(playerid, Float:angle);

static ARQ_callback[MAX_PLAYERS];

/*OnIncomingPacket*/
public OnIncomingPacket(playerid, packetid, BitStream:bs)
{
    if(packetid == 0xCF)
    {
        new ARQ_onFootSync[PR_OnFootSync];

        BS_IgnoreBits(bs, 0x8);
        BS_ReadOnFootSync(bs, ARQ_onFootSync);
            
        new const Float:ARQ_angle = atan2(2 * ((ARQ_onFootSync[PR_quaternion][2] * ARQ_onFootSync[PR_quaternion][3]) + (ARQ_onFootSync[PR_quaternion][0] * ARQ_onFootSync[PR_quaternion][1])), (ARQ_onFootSync[PR_quaternion][0] * ARQ_onFootSync[PR_quaternion][0]) - (ARQ_onFootSync[PR_quaternion][1] * ARQ_onFootSync[PR_quaternion][1]) - (ARQ_onFootSync[PR_quaternion][2] * ARQ_onFootSync[PR_quaternion][2]) + (ARQ_onFootSync[PR_quaternion][3] * ARQ_onFootSync[PR_quaternion][3]));
            
        if(GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_NONE) 
        {
            if(ARQ_angle > 85.0 || ARQ_angle < -85.0)
            {
                if(gettime() > ARQ_callback[playerid])
                {
                    ARQ_callback[playerid] = gettime();
                    OnAntiCheatTurnUpsideDown(playerid, ARQ_angle);
                }
            }
        }
    }
    #if defined ARQ_OnIncomingPacket
        return ARQ_OnIncomingPacket(playerid, packetid, bs);
    #else
        return 1;
    #endif
}

/*Hooks*/
#if defined _ALS_OnIncomingPacket
#undef OnIncomingPacket
#else
#define _ALS_OnIncomingPacket
#endif
#define OnIncomingPacket ARQ_OnIncomingPacket

#if defined ARQ_OnIncomingPacket
forward ARQ_OnIncomingPacket(playerid, packetid, BitStream:bs);
#endif
