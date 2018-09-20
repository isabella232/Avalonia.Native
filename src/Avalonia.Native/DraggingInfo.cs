using System;
using System.Collections.Generic;
using Avalonia.Input;
using Avalonia.Input.Raw;
using Avalonia.Native.Interop;

namespace Avalonia.Native
{
    public class DraggingInfo : IDataObject
    {
        IAvnDataObject _native;

        public DraggingInfo(IAvnDataObject native)
        {
            _native = native;
        }

        public bool Contains(string dataFormat) => _native.Contains(dataFormat);

        public object Get(string dataFormat)
        {
           return _native.Get(dataFormat); // todo intptr to object???
        }

        public IEnumerable<string> GetDataFormats()
        {
            throw new NotSupportedException();
        }

        public IEnumerable<string> GetFileNames()
        {
            throw new NotImplementedException();
        }

        public string GetText()
        {
            _native.GetText(out uint length);

            return "";
        }
    }
}
