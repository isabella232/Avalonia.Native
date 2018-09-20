#include "common.h"

class DraggingInfo : public ComSingleObject<IAvnDataObject, &IID_IAvnDataObject>
{
private:
    
    public:
    virtual HRESULT Contains(const wchar_t* dataFormat, bool* ret){return S_OK;};
    
    virtual HRESULT Get(const wchar_t* dataFormat, void** ret){return S_OK;};
    
    /**
     * Gets the data formats as strings.
     * The user calls this method twice, the first time ret is nullptr and the method returns the number of
     * strings to be returned. This is known as query mode. The second time the user calls it, ret is not
     * nullptr and will be the pointer will be set.
     */
    virtual HRESULT GetDataFormats (uint32_t* outNumStrings, void** retBuf){return S_OK;};
    
    virtual HRESULT GetFileNames(uint32_t* outNumStrings, uint32_t** bufOut){return S_OK;};
    
    virtual HRESULT GetText(uint32_t* outLength, void* ret){return S_OK;};
};


extern IAvnDataObject* CreateDraggingInfo()
{
    return  new DraggingInfo();
}
