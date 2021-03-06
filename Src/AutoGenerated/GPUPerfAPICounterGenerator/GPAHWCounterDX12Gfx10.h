//==============================================================================
// Copyright (c) 2010-2019 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
/// \brief  DX12 counter definitions for GFX10
//==============================================================================

// This file is autogenerated by the ConvertHWEnums project

#ifndef _GPA_HW_COUNTER_DX12_GFX10_H_
#define _GPA_HW_COUNTER_DX12_GFX10_H_

#include <windows.h>
#pragma warning (push)
#pragma warning (disable: 4201)
#include <AmdExtGpaInterface.h>
#pragma warning (pop)

#include <set>

struct GPA_HardwareCounterDesc;
struct GPA_CounterGroupDesc;
struct GPA_SQCounterGroupDesc;

namespace CounterGfx10
{
    extern GPA_HardwareCounterDesc*           DX12CounterGroupArrayGfx10[]; ///< Array of hardware counter groups for DX12 for Gfx10 family
    extern GPA_HardwareCounterDesc*           DX12ExposedCountersGroupArrayGfx10[]; ///< Array of hardware exposed counter groups for DX12 for Gfx10 family
    extern GPA_CounterGroupDesc               HWDX12GroupsGfx10[]; ///< Array of counter groups for DX12 for Gfx10 family
    extern GPA_CounterGroupExposedCounterDesc HWDX12ExposedCountersByGroupGfx10[]; ///< Array of exposed counter groups for DX12 for Gfx10 family
    extern GPA_PaddedCounterDesc              DX12PaddedCounterByGroupGfx10[]; ///< Array of reserved counter for DX12 for Gfx10 family
    extern GPA_SQCounterGroupDesc             HWDX12SQGroupsGfx10[]; ///< Array of SQ groups for DX12 for Gfx10 family
    extern unsigned int                       HWDX12SQIsolatedGroupsGfx10[]; ///< Array of counter groups isolated from SQ counter groups for DX12 for Gfx10 family
    extern AmdExtGpuBlock                     HWDX12DriverEnumGfx10[]; ///< Array of driver enum values per group for DX12 for Gfx10 family
    extern const unsigned int                 HWDX12GputimeBottomToBottomDurationIndexGfx10; ///< Index of delta between the previous command reaching bottom of pipe and the current command reaching bottom of pipe, will not include latency of first data to travel through pipeline, best for large data sets. for DX12 for Gfx10 family
    extern const unsigned int                 HWDX12GputimeBottomToBottomStartIndexGfx10; ///< Index of time of the previous command reaching bottom of pipe for DX12 for Gfx10 family
    extern const unsigned int                 HWDX12GputimeBottomToBottomEndIndexGfx10; ///< Index of time of the current command reaching bottom of pipe for DX12 for Gfx10 family
    extern const unsigned int                 HWDX12GputimeTopToBottomDurationIndexGfx10; ///< Index of execution duration of the current command from top of pipe to bottom of pipe, may include overhead of time in queue for DX12 for Gfx10 family
    extern const unsigned int                 HWDX12GputimeTopToBottomStartIndexGfx10; ///< Index of time that the current command reaches the top of pipe for DX12 for Gfx10 family
    extern const unsigned int                 HWDX12GputimeTopToBottomEndIndexGfx10; ///< Index of time that the current command reaches the bottom of pipe for DX12 for Gfx10 family
    extern const std::set<unsigned int>       HWDX12TimestampBlockIdsGfx10; ///< Timestamp block id's for DX12 for Gfx10 family
    extern const std::set<unsigned int>       HWDX12TimeCounterIndicesGfx10; ///< Timestamp counter indices for DX12 for Gfx10 family
    extern const unsigned int                 HWDX12GroupCountGfx10; ///< Hardware Group Count for DX12 for Gfx10 family
    extern const unsigned int                 HWDX12ExposedCountersGroupCountGfx10; ///< Whitelist hardware counter Group Count for DX12 for Gfx10 family
    extern const unsigned int                 DX12PaddedCounterGroupCountGfx10; ///< reserved counter group count for DX12 for Gfx10 family
    extern const unsigned int                 HWDX12SQGroupCountGfx10; ///< Hardware SQ Group Count for DX12 for Gfx10 family
    extern const unsigned int                 HWDX12SQIsolatedGroupCountGfx10; ///< Hardware Isolated Group Count for DX12 for Gfx10 family
}; // namespace

#endif  // _GPA_HW_COUNTER_DX12_GFX10_H_
