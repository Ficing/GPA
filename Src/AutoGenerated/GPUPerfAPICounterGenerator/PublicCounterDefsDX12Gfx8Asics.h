//==============================================================================
// Copyright (c) 2010-2019 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
/// \brief PublicCounterDefinitions ASIC file for DX12GFX8
//==============================================================================

#ifndef _PUBLIC_COUNTER_DEFS_DX12GFX8_ASICS_H_
#define _PUBLIC_COUNTER_DEFS_DX12GFX8_ASICS_H_

//*** Note, this is an auto-generated file. Do not edit. Execute PublicCounterCompiler to rebuild.

#include "GPADerivedCounters.h"

#include "PublicCounterDefsDX12Gfx8_Baffin.h"
#include "PublicCounterDefsDX12Gfx8_Carrizo.h"
#include "PublicCounterDefsDX12Gfx8_Ellesmere.h"
#include "PublicCounterDefsDX12Gfx8_Fiji.h"
#include "PublicCounterDefsDX12Gfx8_Iceland.h"
#include "PublicCounterDefsDX12Gfx8_Tonga.h"

namespace DX12Gfx8Asics
{
    /// Updates default GPU generation derived counters with ASIC specific derived counters if available.
    /// \param desiredGeneration Hardware generation currently in use.
    /// \param asicType The ASIC type that is currently in use.
    /// \param c Returned set of derived counters, if available.
    /// \return True if the ASIC matched one available, and c was updated.
    inline void UpdatePublicAsicSpecificCounters(GDT_HW_GENERATION desiredGeneration, GDT_HW_ASIC_TYPE asicType, GPA_DerivedCounters& c)
    {
        if (DX12Gfx8_Baffin::UpdatePublicAsicSpecificCounters(desiredGeneration, asicType, c))
        {
            return;
        }

        if (DX12Gfx8_Carrizo::UpdatePublicAsicSpecificCounters(desiredGeneration, asicType, c))
        {
            return;
        }

        if (DX12Gfx8_Ellesmere::UpdatePublicAsicSpecificCounters(desiredGeneration, asicType, c))
        {
            return;
        }

        if (DX12Gfx8_Fiji::UpdatePublicAsicSpecificCounters(desiredGeneration, asicType, c))
        {
            return;
        }

        if (DX12Gfx8_Iceland::UpdatePublicAsicSpecificCounters(desiredGeneration, asicType, c))
        {
            return;
        }

        if (DX12Gfx8_Tonga::UpdatePublicAsicSpecificCounters(desiredGeneration, asicType, c))
        {
            return;
        }
    }

}  // namespace DX12Gfx8Asics

#endif  // _PUBLIC_COUNTER_DEFS_DX12GFX8_ASICS_H_
