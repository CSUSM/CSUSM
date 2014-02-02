/// Copyright (c) 2014 Mathias LANG
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CSUSM
{
    namespace CS441
    {
        namespace HW0
        {
            public class Zip
            {
                public enum ZipType
                {
                    Standard,
                    POBox,
                    Unique,
                    APO_FPO
                }

                /// <summary>
                /// Translate the encoded value from zip.dat to an enum.
                /// </summary>
                /// <param name="c">The encoded value.</param>
                /// <returns>A valid ZipType.</returns>
                public static ZipType DecodeType(char c)
                {
                    switch (c) {
                        case 'P':
                            return ZipType.POBox;
                        case 'U':
                            return ZipType.Unique;
                        case 'M':
                            return ZipType.APO_FPO;
                        case ' ':
                            return ZipType.Standard;
                        default:
                            throw new ArgumentOutOfRangeException("Error: The index has an unexpected value");
                    }
                }
                /// <summary>
                /// Decode a line from zip.dat
                /// </summary>
                /// <param name="line">An line encoded according to the PDF. </param>
                public Zip(string line)
                {
                    this.Code = uint.Parse(line.Substring(0, 5));
                    this.State = line.Substring(5, 2);
                    this.City = line.Substring(7, 28).Trim();
                    this.Type = DecodeType(line[35]);
                }

                public string City { get; set; }
                public string State { get; set; }
                public uint Code { get; set; }
                public ZipType Type { get; set; }
            }
        }
    }
}