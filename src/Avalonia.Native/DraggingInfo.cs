using System;
using System.Collections.Generic;
using Avalonia.Input;

namespace Avalonia.Native
{
    public class DraggingInfo : IDataObject
    {
        public bool Contains(string dataFormat)
        {
            throw new NotImplementedException();
        }

        public object Get(string dataFormat)
        {
            throw new NotImplementedException();
        }

        public IEnumerable<string> GetDataFormats()
        {
            throw new NotImplementedException();
        }

        public IEnumerable<string> GetFileNames()
        {
            throw new NotImplementedException();
        }

        public string GetText()
        {
            throw new NotImplementedException();
        }
    }
}
