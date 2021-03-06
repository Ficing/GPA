//==============================================================================
// Copyright (c) 2015-2018 Advanced Micro Devices, Inc. All rights reserved.
/// \author AMD Developer Tools Team
/// \file
/// \brief  DX11 utility function implementation
//==============================================================================

#include "DX11Utils.h"
#include "DxxExtUtils.h"
#include "GPACommonDefs.h"

bool DX11Utils::GetD3D11Device(IUnknown* pInterfacePointer, ID3D11Device** ppD3D11Device)
{
    *ppD3D11Device = nullptr;
    bool success   = false;

    // Check to see if it's an ID3D11Device
    HRESULT hr = pInterfacePointer->QueryInterface(__uuidof(ID3D11Device), reinterpret_cast<void**>(ppD3D11Device));

    if (hr == E_NOINTERFACE)
    {
        // It's not an ID3D11device, so see if it is an ID3D11DeviceChild-derived interface
        ID3D11DeviceChild* pDeviceChild = nullptr;
        hr                              = pInterfacePointer->QueryInterface(__uuidof(ID3D11DeviceChild), reinterpret_cast<void**>(&pDeviceChild));

        if (SUCCEEDED(hr))
        {
            // Note: GetDevice increments a ref on out parameter
            pDeviceChild->GetDevice(ppD3D11Device);
            (*ppD3D11Device)->Release();
            pDeviceChild->Release();
        }
    }

    if (SUCCEEDED(hr))
    {
        success = true;
        (*ppD3D11Device)->Release();
    }

    return success;
}

bool DX11Utils::IsFeatureLevelSupported(ID3D11Device* pD3D11Device)
{
    bool isSupported = true;

    // Get the current feature level in use by the application
    D3D_FEATURE_LEVEL level = pD3D11Device->GetFeatureLevel();

    // DX9 feature level is not supported
    if (level == D3D_FEATURE_LEVEL_9_1 || level == D3D_FEATURE_LEVEL_9_2 || level == D3D_FEATURE_LEVEL_9_3)
    {
        GPA_LogError("GPUPerfAPI does not support D3D_FEATURE_LEVEL_9_1, _9_2, and _9_3.");
        isSupported = false;
    }

    return isSupported;
}

bool DX11Utils::GetTimestampFrequency(ID3D11Device* pD3D11Device, UINT64& timestampFrequency)
{
    bool success = false;

    if (nullptr != pD3D11Device)
    {
        ID3D11Query*     timeStampDisjointQuery = nullptr;
        D3D11_QUERY_DESC timeStampDesc;
        timeStampDesc.Query     = D3D11_QUERY_TIMESTAMP_DISJOINT;
        timeStampDesc.MiscFlags = 0;

        HRESULT hr = E_FAIL;
        hr         = pD3D11Device->CreateQuery(&timeStampDesc, &timeStampDisjointQuery);

#ifdef _DEBUG
        D3D_SET_OBJECT_NAME_A(timeStampDisjointQuery, "GPA_TimestampFrequencyQuery");
#endif

        if (SUCCEEDED(hr))
        {
            // get immediate context
            ID3D11DeviceContext* pD3DContext = nullptr;
            pD3D11Device->GetImmediateContext(&pD3DContext);

            if (nullptr != pD3DContext)
            {
                //Submit the query
                pD3DContext->Begin(timeStampDisjointQuery);
                pD3DContext->End(timeStampDisjointQuery);

                // need to loop on checking the values, it may not be immediately available.
                HRESULT dataReady = S_OK;

                do
                {
                    dataReady = pD3DContext->GetData(timeStampDisjointQuery, nullptr, 0, 0);

                    if (FAILED(dataReady))
                    {
                        GPA_LogError("Call to ID3D11DeviceContext::GetData failed.");
                        return false;
                    }

                } while (S_FALSE == dataReady);  // S_OK == data ready; S_FALSE == data not ready

                D3D11_QUERY_DATA_TIMESTAMP_DISJOINT timeStampDisjoint;
                assert(timeStampDisjointQuery->GetDataSize() == sizeof(D3D11_QUERY_DATA_TIMESTAMP_DISJOINT));

                hr                 = pD3DContext->GetData(timeStampDisjointQuery, &timeStampDisjoint, sizeof(D3D11_QUERY_DATA_TIMESTAMP_DISJOINT), 0);
                timestampFrequency = timeStampDisjoint.Frequency;
                assert(SUCCEEDED(hr));
                success = true;

                pD3DContext->Release();
                timeStampDisjointQuery->Release();
                timeStampDisjointQuery = nullptr;
            }
            else
            {
                GPA_LogError("ERROR: Immediate Context is NULL.");
            }
        }
        else
        {
            GPA_LogError("Call to ID3D11Device::CreateQuery failed.");
        }
    }
    else
    {
        GPA_LogError("DX11 Device is NULL.");
    }

    return success;
}
