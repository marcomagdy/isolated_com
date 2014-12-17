using System;
using System.Runtime.InteropServices;
using System.Text;

namespace Decoder
{
    [ComVisible(true)]
    public interface IDecoder {
        string decode(string input);
        string encode(string input);
        string echo(string input);

    }

    [ComVisible(true)]
    public class StringDecoder : IDecoder
    {
        public string decode(string input) {
            var bytes = Convert.FromBase64String(input);
            return Encoding.Unicode.GetString(bytes);
        }

        public string encode(string input) {
            var bytes = Encoding.Unicode.GetBytes(input);
            return Convert.ToBase64String(bytes);
        }


        public string echo(string input) {
            return input;
        }
    }
}