#include "com.h"
#include <stdint.h>

#define AVNCOM(name, id) COMINTERFACE(name, 2e2cda0a, 9ae5, 4f1b, 8e, 20, 08, 1a, 04, 27, 9f, id)

struct IAvnWindowEvents;
struct IAvnWindow;
struct IAvnPlatformDragSource;
struct IAvnPlatformDragSourceEvents;
struct IAvnDataObject;
struct IAvnMacOptions;
struct IAvnPlatformThreadingInterface;

struct AvnSize
{
    double Width, Height;
};

struct AvnRect
{
    double X, Y, Width, Height;
};

struct AvnVector
{
    double X, Y;
};

struct AvnPoint
{
    double X, Y;
};

enum AvnRawMouseEventType
{
    LeaveWindow,
    LeftButtonDown,
    LeftButtonUp,
    RightButtonDown,
    RightButtonUp,
    MiddleButtonDown,
    MiddleButtonUp,
    Move,
    Wheel,
    NonClientLeftButtonDown
};

enum AvnInputModifiers
{
    None = 0,
    Alt = 1,
    Control = 2,
    Shift = 4,
    Windows = 8,
    LeftMouseButton = 16,
    RightMouseButton = 32,
    MiddleMouseButton = 64
};

enum AvnDragDropEffects
{
    AvnDragDropNone = 0x0,
    AvnDragDropCopy = 0x1,
    AvnDragDropMove = 0x2,
    AvnDragDropLink = 0x4
};

enum AvnRawDragEventType
{
    DragEnter,
    DragOver,
    DragLeave,
    Drop
};

AVNCOM(IAvaloniaNativeFactory, 01) : virtual IUnknown
{
public:
    virtual HRESULT Initialize() = 0;
    virtual IAvnMacOptions* GetMacOptions() = 0;
    virtual HRESULT CreateWindow(IAvnWindowEvents* cb, IAvnWindow** ppv) = 0;
    virtual HRESULT CreatePlatformThreadingInterface(IAvnPlatformThreadingInterface** ppv) = 0;
};

AVNCOM(IAvnWindowBase, 02) : virtual IUnknown
{
    virtual HRESULT Show() = 0;
    virtual HRESULT Close() = 0;
    virtual HRESULT GetClientSize(AvnSize*ret) = 0;
    virtual HRESULT Resize(double width, double height) = 0;
    virtual void Invalidate (AvnRect rect) = 0;
    virtual void BeginMoveDrag () = 0;
};

AVNCOM(IAvnWindow, 03) : virtual IAvnWindowBase
{
    virtual HRESULT SetCanResize(bool value) = 0;
    virtual HRESULT SetHasDecorations(bool value) = 0;
};

AVNCOM(IAvnWindowBaseEvents, 04) : IUnknown
{
    virtual HRESULT SoftwareDraw(void* ptr, int stride, int pixelWidth, int pixelHeight, const AvnSize& logicalSize) = 0;
    virtual void Closed() = 0;
    virtual void Activated() = 0;
    virtual void Deactivated() = 0;
    virtual void Resized(const AvnSize& size) = 0;
    virtual void RawMouseEvent (AvnRawMouseEventType type,
                                unsigned int timeStamp,
                                AvnInputModifiers modifiers,
                                AvnPoint point,
                                AvnVector delta) = 0;
    virtual AvnDragDropEffects RawDragEvent (AvnRawDragEventType type,
                               AvnPoint point,
                               IAvnDataObject* info,
                               AvnDragDropEffects operation,
                               AvnInputModifiers modifiers) = 0;
};


AVNCOM(IAvnWindowEvents, 05) : IAvnWindowBaseEvents
{

};

AVNCOM(IAvnMacOptions, 06) : virtual IUnknown
{
    virtual HRESULT SetShowInDock(int show) = 0;
};

AVNCOM(IAvnActionCallback, 07) : IUnknown
{
    virtual void Run() = 0;
};

AVNCOM(IAvnSignaledCallback, 08) : IUnknown
{
    virtual void Signaled(int priority, bool priorityContainsMeaningfulValue) = 0;
};


AVNCOM(IAvnLoopCancellation, 09) : virtual IUnknown
{
    virtual void Cancel() = 0;
};

AVNCOM(IAvnPlatformThreadingInterface, 0a) : virtual IUnknown
{
    virtual bool GetCurrentThreadIsLoopThread() = 0;
    virtual void SetSignaledCallback(IAvnSignaledCallback* cb) = 0;
    virtual IAvnLoopCancellation* CreateLoopCancellation() = 0;
    virtual void RunLoop(IAvnLoopCancellation* cancel) = 0;
    // Can't pass int* to sharpgentools for some reason
    virtual void Signal(int priority) = 0;
    virtual IUnknown* StartTimer(int priority, int ms, IAvnActionCallback* callback) = 0;
};

AVNCOM(IAvnPlatformDragSource, 0b) : virtual IUnknown
{
    virtual void DoDragDrop(IAvnDataObject* data, AvnDragDropEffects allowedEffects) = 0;
};

AVNCOM(IAvnPlatformDragSourceEvents, 0c) : virtual IUnknown
{
    virtual void OnDragDropCompleted () = 0;
};

AVNCOM(IAvnDataObject, 0d) : virtual IUnknown
{
    virtual HRESULT Contains(const wchar_t* dataFormat, bool* retOut) = 0;
    
    virtual HRESULT Get(const wchar_t* dataFormat, void** retOut) = 0;
    
    /**
     * Gets the data formats as strings.
     * The user calls this method twice, the first time ret is nullptr and the method returns the number of
     * strings to be returned. This is known as query mode. The second time the user calls it, ret is not
     * nullptr and will be the pointer will be set.
     */
    virtual HRESULT GetDataFormats (uint32_t* outNumStrings, void** retBuf) = 0;
    
    virtual HRESULT GetFileNames(uint32_t* outNumStrings, uint32_t** bufOut)= 0;
    
    virtual HRESULT GetText(void** outPtr)= 0;
};

extern "C" IAvaloniaNativeFactory* CreateAvaloniaNative();
