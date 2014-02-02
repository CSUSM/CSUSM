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
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;


namespace CSUSM
{
    namespace CS441
    {
        namespace HW0
        {
            public partial class MainWindow : Form
            {
                /// <summary>
                /// Event types
                /// </summary>
                /// <param name="path">The path to the file to load.</param>
                private delegate void FileLoadEvent(string path);

                /// <summary>
                /// We need this to access all the fonctionnality of the Datagrid (namely filtering) efficiently.
                /// </summary>
                private IList<Zip> Original;

                /// <summary>
                /// Event handler, called when the user has choosen a file.
                /// </summary>
                private event FileLoadEvent OnFileLoad;

                public MainWindow()
                {
                    InitializeComponent();
                    this.OnFileLoad += new FileLoadEvent(loadFile);
                }

                /// <summary>
                /// Listener called when the "Open File" button is clicked.
                /// </summary>
                /// <param name="sender">The caller item (VS-generated)</param>
                /// <param name="e">Arguments (VS-Generated)</param>
                private void OpenFile_Click(object sender, EventArgs e)
                {
                    var dialog = new OpenFileDialog();
                    dialog.Filter = "All files|*";
                    if (dialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
                        OnFileLoad(dialog.FileName);
                }

                /// <summary>
                /// Listener, load a file into the application.
                /// </summary>
                /// <param name="path">Path to the zip.dat file.</param>
                private void loadFile(string path)
                {
                    try {
                        var rawData = File.ReadAllLines(path);
                        // We skip the 2 header line and the footer (2 lines as well).
                        this.Original = Backend.Convert(rawData.Skip(2).Take(rawData.Length - 4));
                        this.txt_file.Text = path;
                        this.txt_zipCount.Text = Backend.CountUnique(this.Original).ToString();
                        // As we have an IEnumerable<Struct>, this uses reflection and does all the work for us.
                        this.dtg_display.DataSource = this.Original;
                    } catch (Exception e) {
                        // Catch all the exception.
                        // Most of the time the error will be on the parsing (user entered an invalid file).
                        // But it could also be some other kind of failure (network / disk failure...).
                        MessageBox.Show(e.Message, "Error on reading the file", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        this.txt_file.Text = "(none)";
                        this.txt_zipCount.Text = "0";
                        this.chk_displayType.Checked = true;
                        this.dtg_display.DataSource = null;
                        this.Original = null;
                    }
                }

                /// <summary>
                /// Find the items with the specified Zip number, using LINQ.
                /// </summary>
                private void Find_Click(object sender, EventArgs e)
                {
                    if (this.Original != null) {
                        if (this.txt_search.Text == string.Empty) {
                            this.dtg_display.DataSource = this.Original;
                        } else {
                            try {
                                this.dtg_display.DataSource =
                                    (from data in this.Original
                                     where data.Code.ToString() == this.txt_search.Text
                                     select data).ToList();
                            } catch (Exception) {
                                this.dtg_display.DataSource = this.Original;
                            }
                        }
                    }
                }

                /// <summary>
                /// Show or hide the "Type" column.
                /// </summary>
                private void displayType_Triggered(object sender, EventArgs e)
                {
                    // If it fails, that's not critical
                    try {
                        this.dtg_display.Columns[3].Visible = (this.chk_displayType.Checked);
                    } catch (Exception) { }
                }

                /// <summary>
                /// Only display P.O. Boxes.
                /// </summary>
                private void btn_poboxes_Click(object sender, EventArgs e)
                {
                    if (this.Original != null) {
                        this.dtg_display.DataSource = (from data in this.Original
                                                       where data.Type == Zip.ZipType.POBox
                                                       select data).ToList();
                        this.chk_displayType.Checked = false;
                    }
                }

                /// <summary>
                /// Export the currently displayed list of items.
                /// </summary>
                private void btn_export_Click(object sender, EventArgs e)
                {
                    // This can be improved in the future: separate thread, usage of reflexivity.
                    var dialog = new SaveFileDialog();
                    dialog.Filter = "All Files|*";
                    if (dialog.ShowDialog() != System.Windows.Forms.DialogResult.OK)
                        return;
                    var encoded = new List<string>();
                    foreach (var item in (this.dtg_display.DataSource as IList<Zip>))
                        encoded.Add(string.Format("{0}, {1}, {2}", item.City, item.State, item.Code.ToString()));
                    File.WriteAllLines(dialog.FileName, encoded);
                }
            }
        }
    }
}