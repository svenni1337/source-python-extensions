/**
* =============================================================================
* Eventscripts Extensions
* Copyright (C) 2009 Deniz "your-name-here" Sezen.  All rights reserved.
* =============================================================================
*
* This program is free software; you can redistribute it and/or modify it under
* the terms of the GNU General Public License, version 3.0, as published by the
* Free Software Foundation.
* 
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
* details.
*
* You should have received a copy of the GNU General Public License along with
* this program.  If not, see <http://www.gnu.org/licenses/>.
*
* As a special exception, I (Deniz Sezen) give you permission to link the
* code of this program (as well as its derivative works) to "Half-Life 2," the
* "Source Engine," and any Game MODs that run on software
* by the Valve Corporation.  You must obey the GNU General Public License in
* all respects for all other code used.  Additionally, I (Deniz Sezen) grants
* this exception to all derivative works.  
*/

#ifndef SPE_PLAYER_MANAGER_H
#define SPE_PLAYER_MANAGER_H

#include <eiface.h>
#include <iplayerinfo.h>
#include "spe_globals.h"

class CPlayerManager
{
	public:
		/* Constructor and Destructor */
		CPlayerManager();

		/* Returns the edict of a player */
		edict_t* GetPlayerByUserID( int userid );

/* Needed by L4D */
#if defined( ENGINE_LEFT4DEAD )
		inline int IndexOfEdict(const edict_t *pEdict)
		{
			return (int)(pEdict - playerinfomanager->GetGlobalVars()->baseEdict);
		}
		
		inline edict_t *PEntityOfEntIndex(int iEntIndex)
		{
			if (iEntIndex >= 0 && iEntIndex < playerinfomanager->GetGlobalVars()->maxEntities)
			{
				return (edict_t *)(playerinfomanager->GetGlobalVars()->baseEdict + iEntIndex);
			}
			return NULL;
		}
#endif

};

extern CPlayerManager* gPlayerManager;

#endif

