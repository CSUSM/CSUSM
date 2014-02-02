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

namespace CSUSM
{
    namespace CS441
    {
        namespace HW0
        {
            partial class MainWindow
            {
                /// <summary>
                /// Variable nécessaire au concepteur.
                /// </summary>
                private System.ComponentModel.IContainer components = null;

                /// <summary>
                /// Nettoyage des ressources utilisées.
                /// </summary>
                /// <param name="disposing">true si les ressources managées doivent être supprimées ; sinon, false.</param>
                protected override void Dispose(bool disposing)
                {
                    if (disposing && (components != null)) {
                        components.Dispose();
                    }
                    base.Dispose(disposing);
                }

                #region Code généré par le Concepteur Windows Form

                /// <summary>
                /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
                /// le contenu de cette méthode avec l'éditeur de code.
                /// </summary>
                private void InitializeComponent()
                {
            this.btn_openFile = new System.Windows.Forms.Button();
            this.txt_zipCount = new System.Windows.Forms.TextBox();
            this.lbl_count = new System.Windows.Forms.Label();
            this.lbl_file = new System.Windows.Forms.Label();
            this.txt_file = new System.Windows.Forms.TextBox();
            this.dtg_display = new System.Windows.Forms.DataGridView();
            this.btn_find = new System.Windows.Forms.Button();
            this.btn_poboxes = new System.Windows.Forms.Button();
            this.txt_search = new System.Windows.Forms.TextBox();
            this.chk_displayType = new System.Windows.Forms.CheckBox();
            this.btn_export = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dtg_display)).BeginInit();
            this.SuspendLayout();
            // 
            // btn_openFile
            // 
            this.btn_openFile.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btn_openFile.Location = new System.Drawing.Point(25, 369);
            this.btn_openFile.Name = "btn_openFile";
            this.btn_openFile.Size = new System.Drawing.Size(75, 23);
            this.btn_openFile.TabIndex = 0;
            this.btn_openFile.Text = "Open file";
            this.btn_openFile.UseVisualStyleBackColor = true;
            this.btn_openFile.Click += new System.EventHandler(this.OpenFile_Click);
            // 
            // txt_zipCount
            // 
            this.txt_zipCount.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txt_zipCount.Location = new System.Drawing.Point(167, 63);
            this.txt_zipCount.Name = "txt_zipCount";
            this.txt_zipCount.ReadOnly = true;
            this.txt_zipCount.Size = new System.Drawing.Size(308, 20);
            this.txt_zipCount.TabIndex = 1;
            this.txt_zipCount.Text = "0";
            // 
            // lbl_count
            // 
            this.lbl_count.AutoSize = true;
            this.lbl_count.Location = new System.Drawing.Point(22, 66);
            this.lbl_count.Name = "lbl_count";
            this.lbl_count.Size = new System.Drawing.Size(139, 13);
            this.lbl_count.TabIndex = 2;
            this.lbl_count.Text = "Number of valid ZIP codes :";
            // 
            // lbl_file
            // 
            this.lbl_file.AutoSize = true;
            this.lbl_file.Location = new System.Drawing.Point(22, 33);
            this.lbl_file.Name = "lbl_file";
            this.lbl_file.Size = new System.Drawing.Size(29, 13);
            this.lbl_file.TabIndex = 3;
            this.lbl_file.Text = "File :";
            // 
            // txt_file
            // 
            this.txt_file.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txt_file.Location = new System.Drawing.Point(167, 33);
            this.txt_file.Name = "txt_file";
            this.txt_file.ReadOnly = true;
            this.txt_file.Size = new System.Drawing.Size(308, 20);
            this.txt_file.TabIndex = 4;
            this.txt_file.Text = "(none)";
            // 
            // dtg_display
            // 
            this.dtg_display.AllowUserToOrderColumns = true;
            this.dtg_display.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.dtg_display.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dtg_display.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.dtg_display.Location = new System.Drawing.Point(25, 89);
            this.dtg_display.Name = "dtg_display";
            this.dtg_display.ReadOnly = true;
            this.dtg_display.Size = new System.Drawing.Size(450, 274);
            this.dtg_display.TabIndex = 5;
            // 
            // btn_find
            // 
            this.btn_find.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btn_find.Location = new System.Drawing.Point(310, 369);
            this.btn_find.Name = "btn_find";
            this.btn_find.Size = new System.Drawing.Size(75, 23);
            this.btn_find.TabIndex = 6;
            this.btn_find.Text = "Find";
            this.btn_find.UseVisualStyleBackColor = true;
            this.btn_find.Click += new System.EventHandler(this.Find_Click);
            // 
            // btn_poboxes
            // 
            this.btn_poboxes.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.btn_poboxes.Location = new System.Drawing.Point(106, 369);
            this.btn_poboxes.Name = "btn_poboxes";
            this.btn_poboxes.Size = new System.Drawing.Size(105, 23);
            this.btn_poboxes.TabIndex = 7;
            this.btn_poboxes.Text = "Show P.O. boxes";
            this.btn_poboxes.UseVisualStyleBackColor = true;
            this.btn_poboxes.Click += new System.EventHandler(this.btn_poboxes_Click);
            // 
            // txt_search
            // 
            this.txt_search.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.txt_search.Location = new System.Drawing.Point(217, 371);
            this.txt_search.Name = "txt_search";
            this.txt_search.Size = new System.Drawing.Size(86, 20);
            this.txt_search.TabIndex = 8;
            // 
            // chk_displayType
            // 
            this.chk_displayType.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.chk_displayType.AutoSize = true;
            this.chk_displayType.Checked = true;
            this.chk_displayType.CheckState = System.Windows.Forms.CheckState.Checked;
            this.chk_displayType.Location = new System.Drawing.Point(391, 373);
            this.chk_displayType.Name = "chk_displayType";
            this.chk_displayType.Size = new System.Drawing.Size(83, 17);
            this.chk_displayType.TabIndex = 9;
            this.chk_displayType.Text = "Display type";
            this.chk_displayType.UseVisualStyleBackColor = true;
            this.chk_displayType.CheckedChanged += new System.EventHandler(this.displayType_Triggered);
            // 
            // btn_export
            // 
            this.btn_export.Location = new System.Drawing.Point(25, 398);
            this.btn_export.Name = "btn_export";
            this.btn_export.Size = new System.Drawing.Size(75, 23);
            this.btn_export.TabIndex = 10;
            this.btn_export.Text = "Export";
            this.btn_export.UseVisualStyleBackColor = true;
            this.btn_export.Click += new System.EventHandler(this.btn_export_Click);
            // 
            // MainWindow
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(505, 430);
            this.Controls.Add(this.btn_export);
            this.Controls.Add(this.chk_displayType);
            this.Controls.Add(this.txt_search);
            this.Controls.Add(this.btn_poboxes);
            this.Controls.Add(this.btn_find);
            this.Controls.Add(this.dtg_display);
            this.Controls.Add(this.txt_file);
            this.Controls.Add(this.lbl_file);
            this.Controls.Add(this.lbl_count);
            this.Controls.Add(this.txt_zipCount);
            this.Controls.Add(this.btn_openFile);
            this.Name = "MainWindow";
            this.Text = "HW0";
            ((System.ComponentModel.ISupportInitialize)(this.dtg_display)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

                }

                #endregion

                private System.Windows.Forms.Button btn_openFile;
                private System.Windows.Forms.TextBox txt_zipCount;
                private System.Windows.Forms.Label lbl_count;
                private System.Windows.Forms.Label lbl_file;
                private System.Windows.Forms.TextBox txt_file;
                private System.Windows.Forms.DataGridView dtg_display;
                private System.Windows.Forms.Button btn_find;
                private System.Windows.Forms.Button btn_poboxes;
                private System.Windows.Forms.TextBox txt_search;
                private System.Windows.Forms.CheckBox chk_displayType;
                private System.Windows.Forms.Button btn_export;
            }
        }
    }
}