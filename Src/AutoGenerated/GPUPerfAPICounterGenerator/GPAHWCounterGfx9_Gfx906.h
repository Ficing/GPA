//==============================================================================
// Copyright (c) 2010-2019 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
/// \brief  Hardware counter info for GFX9_GFX906
//==============================================================================

// This file is autogenerated by the ConvertHWEnums project

#ifndef _GPA_HW_COUNTER_GFX9_GFX906_H_
#define _GPA_HW_COUNTER_GFX9_GFX906_H_

#include <set>

struct GPA_HardwareCounterDesc;
#include "GPAHWCounterGfx9.h"

namespace CounterGfx9_Gfx906
{
/// Uses the input ASIC type to determine if this data provides an ASIC specific version.
/// \param asicType The ASIC type that is currently in use.
/// \return True if the ASIC is matched by this file.
inline bool MatchAsic(GDT_HW_ASIC_TYPE asicType)
{
    static std::set<GDT_HW_ASIC_TYPE> asicsSupported = { GDT_GFX9_0_6 };

    if (asicsSupported.find(asicType) == asicsSupported.end())
    {
        return false;
    }

    return true;
}

    extern GPA_HardwareCounterDesc PA_SU0countersGfx9_Gfx906[]; ///< Array of internal counters for PA_SU0 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc PA_SU1countersGfx9_Gfx906[]; ///< Array of internal counters for PA_SU1 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc PA_SU2countersGfx9_Gfx906[]; ///< Array of internal counters for PA_SU2 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc PA_SU3countersGfx9_Gfx906[]; ///< Array of internal counters for PA_SU3 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc PA_SC0countersGfx9_Gfx906[]; ///< Array of internal counters for PA_SC0 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc PA_SC1countersGfx9_Gfx906[]; ///< Array of internal counters for PA_SC1 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc PA_SC2countersGfx9_Gfx906[]; ///< Array of internal counters for PA_SC2 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc PA_SC3countersGfx9_Gfx906[]; ///< Array of internal counters for PA_SC3 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC0countersGfx9_Gfx906[]; ///< Array of internal counters for TCC0 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC1countersGfx9_Gfx906[]; ///< Array of internal counters for TCC1 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC2countersGfx9_Gfx906[]; ///< Array of internal counters for TCC2 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC3countersGfx9_Gfx906[]; ///< Array of internal counters for TCC3 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC4countersGfx9_Gfx906[]; ///< Array of internal counters for TCC4 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC5countersGfx9_Gfx906[]; ///< Array of internal counters for TCC5 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC6countersGfx9_Gfx906[]; ///< Array of internal counters for TCC6 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC7countersGfx9_Gfx906[]; ///< Array of internal counters for TCC7 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC8countersGfx9_Gfx906[]; ///< Array of internal counters for TCC8 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC9countersGfx9_Gfx906[]; ///< Array of internal counters for TCC9 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC10countersGfx9_Gfx906[]; ///< Array of internal counters for TCC10 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC11countersGfx9_Gfx906[]; ///< Array of internal counters for TCC11 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC12countersGfx9_Gfx906[]; ///< Array of internal counters for TCC12 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC13countersGfx9_Gfx906[]; ///< Array of internal counters for TCC13 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC14countersGfx9_Gfx906[]; ///< Array of internal counters for TCC14 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc TCC15countersGfx9_Gfx906[]; ///< Array of internal counters for TCC15 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc IA0countersGfx9_Gfx906[]; ///< Array of internal counters for IA0 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc IA1countersGfx9_Gfx906[]; ///< Array of internal counters for IA1 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc RPBcountersGfx9_Gfx906[]; ///< Array of internal counters for RPB block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA0countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA0 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA1countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA1 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA2countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA2 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA3countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA3 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA4countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA4 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA5countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA5 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA6countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA6 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA7countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA7 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA8countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA8 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA9countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA9 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA10countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA10 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA11countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA11 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA12countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA12 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA13countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA13 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA14countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA14 block for Gfx9_Gfx906 family
    extern GPA_HardwareCounterDesc GCEA15countersGfx9_Gfx906[]; ///< Array of internal counters for GCEA15 block for Gfx9_Gfx906 family

/// Replaces count number of block instance counters at the destination with the overriding source counters.
/// \param pDestCounter Destination to update.
/// \param pSrcCounter Source to update from.
/// \param count Number of counters to update.
inline void ReplaceBlockInstanceCounters(GPA_HardwareCounterDesc* pDestCounter, GPA_HardwareCounterDesc* pSrcCounter, uint32_t count)
{
    for (uint32_t i = 0; i < count; i++)
    {
        pDestCounter[i] = pSrcCounter[i];
    }
}

/// If the requested ASIC type is supported, then the global GPU generation block instance counters are updated.
/// \param asicType The ASIC type that is currently in use.
/// \return True if the ASIC is matched by this file and block instances are updated, otherwise false.
inline bool OverrideBlockInstanceCounters(GDT_HW_ASIC_TYPE asicType)
{
    if (!MatchAsic(asicType))
    {
        return false;
    }

    ReplaceBlockInstanceCounters(CounterGfx9::PA_SU0countersGfx9, PA_SU0countersGfx9_Gfx906, 351);
    ReplaceBlockInstanceCounters(CounterGfx9::PA_SU1countersGfx9, PA_SU1countersGfx9_Gfx906, 351);
    ReplaceBlockInstanceCounters(CounterGfx9::PA_SU2countersGfx9, PA_SU2countersGfx9_Gfx906, 351);
    ReplaceBlockInstanceCounters(CounterGfx9::PA_SU3countersGfx9, PA_SU3countersGfx9_Gfx906, 351);
    ReplaceBlockInstanceCounters(CounterGfx9::PA_SC0countersGfx9, PA_SC0countersGfx9_Gfx906, 492);
    ReplaceBlockInstanceCounters(CounterGfx9::PA_SC1countersGfx9, PA_SC1countersGfx9_Gfx906, 492);
    ReplaceBlockInstanceCounters(CounterGfx9::PA_SC2countersGfx9, PA_SC2countersGfx9_Gfx906, 492);
    ReplaceBlockInstanceCounters(CounterGfx9::PA_SC3countersGfx9, PA_SC3countersGfx9_Gfx906, 492);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC0countersGfx9, TCC0countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC1countersGfx9, TCC1countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC2countersGfx9, TCC2countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC3countersGfx9, TCC3countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC4countersGfx9, TCC4countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC5countersGfx9, TCC5countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC6countersGfx9, TCC6countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC7countersGfx9, TCC7countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC8countersGfx9, TCC8countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC9countersGfx9, TCC9countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC10countersGfx9, TCC10countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC11countersGfx9, TCC11countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC12countersGfx9, TCC12countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC13countersGfx9, TCC13countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC14countersGfx9, TCC14countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::TCC15countersGfx9, TCC15countersGfx9_Gfx906, 282);
    ReplaceBlockInstanceCounters(CounterGfx9::IA0countersGfx9, IA0countersGfx9_Gfx906, 31);
    ReplaceBlockInstanceCounters(CounterGfx9::IA1countersGfx9, IA1countersGfx9_Gfx906, 31);
    ReplaceBlockInstanceCounters(CounterGfx9::RPBcountersGfx9, RPBcountersGfx9_Gfx906, 95);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA0countersGfx9, GCEA0countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA1countersGfx9, GCEA1countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA2countersGfx9, GCEA2countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA3countersGfx9, GCEA3countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA4countersGfx9, GCEA4countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA5countersGfx9, GCEA5countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA6countersGfx9, GCEA6countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA7countersGfx9, GCEA7countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA8countersGfx9, GCEA8countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA9countersGfx9, GCEA9countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA10countersGfx9, GCEA10countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA11countersGfx9, GCEA11countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA12countersGfx9, GCEA12countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA13countersGfx9, GCEA13countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA14countersGfx9, GCEA14countersGfx9_Gfx906, 83);
    ReplaceBlockInstanceCounters(CounterGfx9::GCEA15countersGfx9, GCEA15countersGfx9_Gfx906, 83);

    return true;
}
} // CounterGfx9_Gfx906

#endif  // _GPA_HW_COUNTER_GFX9_GFX906_H_
