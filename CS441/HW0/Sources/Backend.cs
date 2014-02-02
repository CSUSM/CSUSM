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
using System.Windows.Forms;

namespace CSUSM
{
    namespace CS441
    {
        namespace HW0
        {
            /// <summary>
            /// Holds helpers functions.
            /// </summary>
            public static class Backend
            {
                /// <summary>
                /// Converts an aggregate of encoded zip codes (see specs from HW0_Spring2014.pdf page 3)
                /// to an aggregate of "Zip".
                /// </summary>
                /// <param name="encoded">The raw zip.dat data.</param>
                /// <returns>An aggregate of Zip, holding all the informations from encoded.</returns>
                public static IList<Zip> Convert(IEnumerable<string> encoded)
                {
                    var ret = new List<Zip>();
                    foreach (string s in encoded)
                        ret.Add(new Zip(s));
                    return ret;
                }
                /// <summary>
                /// Count only unique zip code.
                /// As we don't want to store them, it will be pretty big, we just skip the duplicates.
                /// </summary>
                /// <param name="list">The list of zip codes.</param>
                /// <returns>The number of unique zip code.</returns>
                public static int CountUnique(IEnumerable<Zip> list)
                {
                    // The algorithm is pretty simple, but very space-efficient.
                    // THey should already be ordered, but we ensure it anyway.
                    var slist = list.OrderBy(x => x.Code);
                    int cnt = 0;
                    uint max = 0;
                    foreach (Zip z in slist) {
                        if (z.Code > max) {
                            max = z.Code;
                            ++cnt;
                        }
                    }
                    return cnt;
                }
            }
        }
    }
}