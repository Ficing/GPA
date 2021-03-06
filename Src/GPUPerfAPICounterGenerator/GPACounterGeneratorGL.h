//==============================================================================
// Copyright (c) 2016-2019 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
/// \brief  Class for GL counter generation
//==============================================================================

#ifndef _GPA_COUNTER_GENERATOR_GL_H_
#define _GPA_COUNTER_GENERATOR_GL_H_

#include "GPACounterGeneratorBase.h"

/// The OpenGL-specific counter generator
class GPA_CounterGeneratorGL : public GPA_CounterGeneratorBase
{
public:
    /// Constructor
    GPA_CounterGeneratorGL();

    //Destructor
    virtual ~GPA_CounterGeneratorGL();

protected:
    /// \copydoc GPA_CounterGeneratorBase::GeneratePublicCounters
    GPA_Status GeneratePublicCounters(GDT_HW_GENERATION    desiredGeneration,
                                      GDT_HW_ASIC_TYPE     asicType,
                                      gpa_uint8            generateAsicSpecificCounters,
                                      GPA_DerivedCounters* pPublicCounters) override;

    /// \copydoc GPA_CounterGeneratorBase::GenerateHardwareCounters
    GPA_Status GenerateHardwareCounters(GDT_HW_GENERATION     desiredGeneration,
                                        GDT_HW_ASIC_TYPE      asicType,
                                        gpa_uint8             generateAsicSpecificCounters,
                                        GPA_HardwareCounters* pHardwareCounters) override;

    /// \copydoc GPA_CounterGeneratorBase::GenerateSoftwareCounters
    GPA_Status GenerateSoftwareCounters(GDT_HW_GENERATION     desiredGeneration,
                                        GDT_HW_ASIC_TYPE      asicType,
                                        gpa_uint8             generateAsicSpecificCounters,
                                        GPA_SoftwareCounters* pSoftwareCounters) override;

    /// \copydoc GPA_CounterGeneratorBase::GenerateHardwareExposedCounters
    GPA_Status GenerateHardwareExposedCounters(GDT_HW_GENERATION     desiredGeneration,
                                               GDT_HW_ASIC_TYPE      asicType,
                                               gpa_uint8             generateAsicSpecificCounters,
                                               GPA_HardwareCounters* pHardwareCounters) override;

#ifdef AMDT_INTERNAL
    /// \copydoc GPA_CounterGeneratorBase::GenerateInternalDerivedCounters
    GPA_Status GenerateInternalDerivedCounters(GDT_HW_GENERATION    desiredGeneration,
                                               GDT_HW_ASIC_TYPE     asicType,
                                               gpa_uint8            generateAsicSpecificCounters,
                                               GPA_DerivedCounters* pPublicCounters) override;
#endif

private:
    /// Helper function to generate the driver-supplied counters
    /// \param pHardwareCounters the list of hardware counters to augment with the driver-supplied counters
    /// \return true on success, false on failure
    bool GenerateDriverSuppliedInternalCounters(GPA_HardwareCounters* pHardwareCounters);

    /// Helper function to generate the internal counters
    /// \param pHardwareCounters the list of hardware counters to augment with the driver-supplied counters
    /// \param generation the hardware generation whose internal counters are needed
    /// \return true on success, false on failure
    GPA_Status GenerateInternalCounters(GPA_HardwareCounters* pHardwareCounters, GDT_HW_GENERATION generation);

    /// Helper function to cleanup and release memory
    void Cleanup();

    GPA_CounterGroupDesc*                   m_pDriverSuppliedGroups;     ///< driver-supplied counter groups
    unsigned int                            m_driverSuppliedGroupCount;  ///< number of driver-supplied counter groups
    std::vector<GPA_HardwareCounterDescExt> m_driverSuppliedCounters;    ///< list of driver-supplied counters

    // the following vectors are used to track and free allocated memory
    std::vector<GPA_CounterGroupDesc*>    m_counterGroupDescs;     ///< allocated GPA_CounterGroupDescs
    std::vector<GPA_HardwareCounterDesc*> m_hardwareCounterDescs;  ///< allocated GPA_HardwareCounterDescs
    std::vector<char*>                    m_counterBuffers;        ///< allocated driver supplied counter buffers
};

#endif  //_GPA_COUNTER_GENERATOR_GL_H_
