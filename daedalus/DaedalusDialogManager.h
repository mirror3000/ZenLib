#pragma once
#include <vector>
#include <string>
#include <functional>
#include <set>
#include <zenload/zCCSLib.h>
#include "DaedalusGameState.h"

namespace ZenLoad
{
    struct oCMsgConversationData;
}

namespace Daedalus
{
    class DaedalusVM;


    namespace GameState
    {
        class DaedalusDialogManager
        {
        public:
            DaedalusDialogManager(Daedalus::DaedalusVM &vm, const std::string &ou_bin);

            /**
			 * Sets the given info-instance as "known" to the given NPC-Instance
			 */
            void setNpcInfoKnown(size_t npcInstance, size_t infoInstance);

            /**
             * Checks whether the given NPC knows the info passed here
             * @param npcInstance NPC to check
             * @param infoInstance Info to check
             * @return Whether the NPC knows
             */
            bool doesNpcKnowInfo(size_t npcInstance, size_t infoInstance);

            /**
             * get vector of InfoHandles for this npc
             * @param npc NPC to process infos for
             */
            std::vector<InfoHandle> getInfos(NpcHandle npc);

            /**
             * @return Map of NPC-Symbols -> All info they know
             */
            const std::map<size_t, std::set<size_t>>& getKnownNPCInformation(){ return m_KnownNpcInfoSymbolsByNpcSymbols; };

            /**
             * @return MessageLib
             */
            ZenLoad::zCCSLib& getMessageLib() { return m_MessageLib; }
        private:

            /**
			 * Gathers all C_Info-Instances and puts them into m_NpcInfosByNpcSymbols
			 */
            void gatherNpcInformation();

            /**
			 * Message library
			 */
            ZenLoad::zCCSLib m_MessageLib;

            /**
			 * Current daedalus VM
			 */
            Daedalus::DaedalusVM &m_VM;

            /**
			 * Map of NPC-Sym-Handles and their C_Infos
			 */
            std::map<size_t, std::vector<InfoHandle>> m_NpcInfosByNpcSymbols;
            std::map<size_t, std::set<size_t>> m_KnownNpcInfoSymbolsByNpcSymbols;
        };
    }
}