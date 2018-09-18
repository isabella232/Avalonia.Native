using System;
using System.Threading.Tasks;
using Avalonia.Input;
using Avalonia.Input.Platform;

namespace Avalonia.Native
{
    public class DragSource : IPlatformDragSource
    {
        public Task<DragDropEffects> DoDragDrop(IDataObject data, DragDropEffects allowedEffects)
        {
            throw new NotImplementedException();
        }
    }
}
