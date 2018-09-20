#include "common.h"
#include "DraggingInfo.hpp"

DraggingInfo::DraggingInfo (id<NSDraggingInfo> draggingInfo)
{
}

HRESULT DraggingInfo::Contains(const wchar_t* dataFormat, bool* ret)
{
    return S_OK;
}

HRESULT DraggingInfo::Get(const wchar_t* dataFormat, void** ret)
{
    return S_OK;
}

HRESULT DraggingInfo::GetDataFormats (uint32_t* outNumStrings, void** retBuf)
{
    return S_OK;
}

HRESULT DraggingInfo::GetFileNames(uint32_t* outNumStrings, uint32_t** bufOut)
{
    return S_OK;
}

HRESULT DraggingInfo::GetText(uint32_t* outLength, void* ret)
{
    return S_OK;
}

AvnPoint DraggingInfo::GetLocation()
{
    auto pt = [_draggingInfo draggingLocation];
    
    return AvnPoint{ pt.x, pt.y };
}

AvnDragDropEffects DraggingInfo::ConvertDragOperation(NSDragOperation d)
{
    int result = AvnDragDropEffects::AvnDragDropNone;
    
    if (d & AvnDragDropEffects::AvnDragDropCopy)
    {
        result |= AvnDragDropEffects::AvnDragDropCopy;
    }
    
    if(d & AvnDragDropEffects::AvnDragDropLink)
    {
        result |= AvnDragDropEffects::AvnDragDropLink;
    }
    
    if(d & AvnDragDropEffects::AvnDragDropMove)
    {
        result |= AvnDragDropEffects::AvnDragDropMove;
    }
    
    return (AvnDragDropEffects) result;
}

NSDragOperation DraggingInfo::ConvertDragOperation(AvnDragDropEffects d)
{
    int result = NSDragOperationNone;
    
    if(d & AvnDragDropCopy)
    {
        result |= NSDragOperationCopy;
    }
    
    if (d & AvnDragDropLink)
    {
        result |= NSDragOperationLink;
    }
    
    if(d & AvnDragDropMove)
    {
        result |= NSDragOperationMove;
    }
    
    return result;
}

