namespace LAB4
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.Genkeyclik = new System.Windows.Forms.Button();
            this.txtprintpath = new System.Windows.Forms.TextBox();
            this.txtPathpub = new System.Windows.Forms.TextBox();
            this.txtPathpriv = new System.Windows.Forms.TextBox();
            this.pathpub = new System.Windows.Forms.Button();
            this.pathpriv = new System.Windows.Forms.Button();
            this.keyber = new System.Windows.Forms.RadioButton();
            this.keypem = new System.Windows.Forms.RadioButton();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.Signclik = new System.Windows.Forms.Button();
            this.pathdata = new System.Windows.Forms.Button();
            this.txtdata = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.pathprivkey = new System.Windows.Forms.Button();
            this.txtsign = new System.Windows.Forms.TextBox();
            this.txtpriv = new System.Windows.Forms.TextBox();
            this.bersig = new System.Windows.Forms.RadioButton();
            this.pemsig = new System.Windows.Forms.RadioButton();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.Vericlik = new System.Windows.Forms.Button();
            this.pathdatal = new System.Windows.Forms.Button();
            this.txtpathdatal = new System.Windows.Forms.TextBox();
            this.button4 = new System.Windows.Forms.Button();
            this.pathpubl = new System.Windows.Forms.Button();
            this.txtpathsigl = new System.Windows.Forms.TextBox();
            this.txtpathpubl = new System.Windows.Forms.TextBox();
            this.berv = new System.Windows.Forms.RadioButton();
            this.pemv = new System.Windows.Forms.RadioButton();
            this.filedatakeyb = new System.Windows.Forms.Button();
            this.txtpathsavedata = new System.Windows.Forms.TextBox();
            this.datakeybb = new System.Windows.Forms.TextBox();
            this.datakeyb = new System.Windows.Forms.Button();
            this.keyb = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.flpl = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.txtpathsig = new System.Windows.Forms.TextBox();
            this.tabControl1.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Controls.Add(this.tabPage2);
            this.tabControl1.Controls.Add(this.tabPage3);
            this.tabControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tabControl1.Location = new System.Drawing.Point(0, 0);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(1201, 590);
            this.tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.Genkeyclik);
            this.tabPage1.Controls.Add(this.txtprintpath);
            this.tabPage1.Controls.Add(this.txtPathpub);
            this.tabPage1.Controls.Add(this.txtPathpriv);
            this.tabPage1.Controls.Add(this.pathpub);
            this.tabPage1.Controls.Add(this.pathpriv);
            this.tabPage1.Controls.Add(this.keyber);
            this.tabPage1.Controls.Add(this.keypem);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(1193, 561);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "Gen Key";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // Genkeyclik
            // 
            this.Genkeyclik.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.Genkeyclik.Location = new System.Drawing.Point(187, 412);
            this.Genkeyclik.Name = "Genkeyclik";
            this.Genkeyclik.Size = new System.Drawing.Size(343, 141);
            this.Genkeyclik.TabIndex = 8;
            this.Genkeyclik.Text = "GENERATE KEY";
            this.Genkeyclik.UseVisualStyleBackColor = true;
            this.Genkeyclik.Click += new System.EventHandler(this.Genkeyclik_Click);
            // 
            // txtprintpath
            // 
            this.txtprintpath.Location = new System.Drawing.Point(690, 412);
            this.txtprintpath.Multiline = true;
            this.txtprintpath.Name = "txtprintpath";
            this.txtprintpath.Size = new System.Drawing.Size(495, 141);
            this.txtprintpath.TabIndex = 7;
            // 
            // txtPathpub
            // 
            this.txtPathpub.Location = new System.Drawing.Point(340, 302);
            this.txtPathpub.Multiline = true;
            this.txtPathpub.Name = "txtPathpub";
            this.txtPathpub.Size = new System.Drawing.Size(845, 36);
            this.txtPathpub.TabIndex = 5;
            // 
            // txtPathpriv
            // 
            this.txtPathpriv.Location = new System.Drawing.Point(340, 189);
            this.txtPathpriv.Multiline = true;
            this.txtPathpriv.Name = "txtPathpriv";
            this.txtPathpriv.Size = new System.Drawing.Size(845, 36);
            this.txtPathpriv.TabIndex = 4;
            // 
            // pathpub
            // 
            this.pathpub.Location = new System.Drawing.Point(97, 302);
            this.pathpub.Name = "pathpub";
            this.pathpub.Size = new System.Drawing.Size(199, 36);
            this.pathpub.TabIndex = 3;
            this.pathpub.Text = "Public Key";
            this.pathpub.UseVisualStyleBackColor = true;
            this.pathpub.Click += new System.EventHandler(this.pathpub_Click);
            // 
            // pathpriv
            // 
            this.pathpriv.Location = new System.Drawing.Point(97, 189);
            this.pathpriv.Name = "pathpriv";
            this.pathpriv.Size = new System.Drawing.Size(199, 36);
            this.pathpriv.TabIndex = 2;
            this.pathpriv.Text = "Private Key";
            this.pathpriv.UseVisualStyleBackColor = true;
            this.pathpriv.Click += new System.EventHandler(this.pathpriv_Click);
            // 
            // keyber
            // 
            this.keyber.AutoSize = true;
            this.keyber.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.keyber.Location = new System.Drawing.Point(915, 60);
            this.keyber.Name = "keyber";
            this.keyber.Size = new System.Drawing.Size(109, 43);
            this.keyber.TabIndex = 1;
            this.keyber.TabStop = true;
            this.keyber.Text = "BER";
            this.keyber.UseVisualStyleBackColor = true;
            // 
            // keypem
            // 
            this.keypem.AutoSize = true;
            this.keypem.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.keypem.Location = new System.Drawing.Point(215, 60);
            this.keypem.Name = "keypem";
            this.keypem.Size = new System.Drawing.Size(112, 43);
            this.keypem.TabIndex = 0;
            this.keypem.TabStop = true;
            this.keypem.Text = "PEM";
            this.keypem.UseVisualStyleBackColor = true;
            this.keypem.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.txtpathsig);
            this.tabPage2.Controls.Add(this.groupBox2);
            this.tabPage2.Controls.Add(this.groupBox1);
            this.tabPage2.Controls.Add(this.datakeybb);
            this.tabPage2.Controls.Add(this.datakeyb);
            this.tabPage2.Controls.Add(this.txtpathsavedata);
            this.tabPage2.Controls.Add(this.filedatakeyb);
            this.tabPage2.Controls.Add(this.Signclik);
            this.tabPage2.Controls.Add(this.pathdata);
            this.tabPage2.Controls.Add(this.txtdata);
            this.tabPage2.Controls.Add(this.button2);
            this.tabPage2.Controls.Add(this.pathprivkey);
            this.tabPage2.Controls.Add(this.txtsign);
            this.tabPage2.Controls.Add(this.txtpriv);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(1193, 561);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Sign";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // Signclik
            // 
            this.Signclik.Font = new System.Drawing.Font("Microsoft Sans Serif", 25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.Signclik.Location = new System.Drawing.Point(209, 451);
            this.Signclik.Name = "Signclik";
            this.Signclik.Size = new System.Drawing.Size(343, 102);
            this.Signclik.TabIndex = 8;
            this.Signclik.Text = "SIGN";
            this.Signclik.UseVisualStyleBackColor = true;
            this.Signclik.Click += new System.EventHandler(this.Signclik_Click);
            // 
            // pathdata
            // 
            this.pathdata.Location = new System.Drawing.Point(63, 340);
            this.pathdata.Name = "pathdata";
            this.pathdata.Size = new System.Drawing.Size(121, 29);
            this.pathdata.TabIndex = 7;
            this.pathdata.Text = "Open file";
            this.pathdata.UseVisualStyleBackColor = true;
            this.pathdata.Click += new System.EventHandler(this.pathdata_Click);
            // 
            // txtdata
            // 
            this.txtdata.Location = new System.Drawing.Point(209, 340);
            this.txtdata.Multiline = true;
            this.txtdata.Name = "txtdata";
            this.txtdata.Size = new System.Drawing.Size(976, 29);
            this.txtdata.TabIndex = 6;
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(63, 404);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(121, 29);
            this.button2.TabIndex = 5;
            this.button2.Text = "Signature path";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // pathprivkey
            // 
            this.pathprivkey.Location = new System.Drawing.Point(63, 273);
            this.pathprivkey.Name = "pathprivkey";
            this.pathprivkey.Size = new System.Drawing.Size(121, 33);
            this.pathprivkey.TabIndex = 4;
            this.pathprivkey.Text = "Privatekey";
            this.pathprivkey.UseVisualStyleBackColor = true;
            this.pathprivkey.Click += new System.EventHandler(this.pathprivkey_Click);
            // 
            // txtsign
            // 
            this.txtsign.Location = new System.Drawing.Point(209, 407);
            this.txtsign.Multiline = true;
            this.txtsign.Name = "txtsign";
            this.txtsign.Size = new System.Drawing.Size(976, 29);
            this.txtsign.TabIndex = 3;
            this.txtsign.TextChanged += new System.EventHandler(this.txtsign_TextChanged);
            // 
            // txtpriv
            // 
            this.txtpriv.Location = new System.Drawing.Point(209, 273);
            this.txtpriv.Multiline = true;
            this.txtpriv.Name = "txtpriv";
            this.txtpriv.Size = new System.Drawing.Size(976, 33);
            this.txtpriv.TabIndex = 2;
            // 
            // bersig
            // 
            this.bersig.AutoSize = true;
            this.bersig.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.bersig.Location = new System.Drawing.Point(161, 38);
            this.bersig.Name = "bersig";
            this.bersig.Size = new System.Drawing.Size(86, 33);
            this.bersig.TabIndex = 1;
            this.bersig.TabStop = true;
            this.bersig.Text = "BER";
            this.bersig.UseVisualStyleBackColor = true;
            this.bersig.CheckedChanged += new System.EventHandler(this.bersig_CheckedChanged);
            // 
            // pemsig
            // 
            this.pemsig.AutoSize = true;
            this.pemsig.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.pemsig.Location = new System.Drawing.Point(16, 38);
            this.pemsig.Name = "pemsig";
            this.pemsig.Size = new System.Drawing.Size(89, 33);
            this.pemsig.TabIndex = 0;
            this.pemsig.TabStop = true;
            this.pemsig.Text = "PEM";
            this.pemsig.UseVisualStyleBackColor = true;
            this.pemsig.CheckedChanged += new System.EventHandler(this.radioButton1_CheckedChanged_1);
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.Vericlik);
            this.tabPage3.Controls.Add(this.pathdatal);
            this.tabPage3.Controls.Add(this.txtpathdatal);
            this.tabPage3.Controls.Add(this.button4);
            this.tabPage3.Controls.Add(this.pathpubl);
            this.tabPage3.Controls.Add(this.txtpathsigl);
            this.tabPage3.Controls.Add(this.txtpathpubl);
            this.tabPage3.Controls.Add(this.berv);
            this.tabPage3.Controls.Add(this.pemv);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(1193, 561);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Verify";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // Vericlik
            // 
            this.Vericlik.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.Vericlik.Location = new System.Drawing.Point(476, 441);
            this.Vericlik.Name = "Vericlik";
            this.Vericlik.Size = new System.Drawing.Size(343, 102);
            this.Vericlik.TabIndex = 17;
            this.Vericlik.Text = "VERIFY";
            this.Vericlik.UseVisualStyleBackColor = true;
            this.Vericlik.Click += new System.EventHandler(this.Sigclik_Click);
            // 
            // pathdatal
            // 
            this.pathdatal.Location = new System.Drawing.Point(35, 235);
            this.pathdatal.Name = "pathdatal";
            this.pathdatal.Size = new System.Drawing.Size(121, 29);
            this.pathdatal.TabIndex = 16;
            this.pathdatal.Text = "Data";
            this.pathdatal.UseVisualStyleBackColor = true;
            this.pathdatal.Click += new System.EventHandler(this.pathdatal_Click);
            // 
            // txtpathdatal
            // 
            this.txtpathdatal.Location = new System.Drawing.Point(181, 235);
            this.txtpathdatal.Multiline = true;
            this.txtpathdatal.Name = "txtpathdatal";
            this.txtpathdatal.Size = new System.Drawing.Size(976, 29);
            this.txtpathdatal.TabIndex = 15;
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(35, 310);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(121, 29);
            this.button4.TabIndex = 14;
            this.button4.Text = "Signature path";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // pathpubl
            // 
            this.pathpubl.Location = new System.Drawing.Point(35, 147);
            this.pathpubl.Name = "pathpubl";
            this.pathpubl.Size = new System.Drawing.Size(121, 29);
            this.pathpubl.TabIndex = 13;
            this.pathpubl.Text = "PublicKey";
            this.pathpubl.UseVisualStyleBackColor = true;
            this.pathpubl.Click += new System.EventHandler(this.pathpubl_Click);
            // 
            // txtpathsigl
            // 
            this.txtpathsigl.Location = new System.Drawing.Point(181, 313);
            this.txtpathsigl.Multiline = true;
            this.txtpathsigl.Name = "txtpathsigl";
            this.txtpathsigl.Size = new System.Drawing.Size(976, 29);
            this.txtpathsigl.TabIndex = 12;
            // 
            // txtpathpubl
            // 
            this.txtpathpubl.Location = new System.Drawing.Point(181, 147);
            this.txtpathpubl.Multiline = true;
            this.txtpathpubl.Name = "txtpathpubl";
            this.txtpathpubl.Size = new System.Drawing.Size(976, 29);
            this.txtpathpubl.TabIndex = 11;
            // 
            // berv
            // 
            this.berv.AutoSize = true;
            this.berv.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.berv.Location = new System.Drawing.Point(813, 62);
            this.berv.Name = "berv";
            this.berv.Size = new System.Drawing.Size(86, 33);
            this.berv.TabIndex = 10;
            this.berv.TabStop = true;
            this.berv.Text = "BER";
            this.berv.UseVisualStyleBackColor = true;
            // 
            // pemv
            // 
            this.pemv.AutoSize = true;
            this.pemv.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.pemv.Location = new System.Drawing.Point(369, 62);
            this.pemv.Name = "pemv";
            this.pemv.Size = new System.Drawing.Size(89, 33);
            this.pemv.TabIndex = 9;
            this.pemv.TabStop = true;
            this.pemv.Text = "PEM";
            this.pemv.UseVisualStyleBackColor = true;
            // 
            // filedatakeyb
            // 
            this.filedatakeyb.Location = new System.Drawing.Point(63, 213);
            this.filedatakeyb.Name = "filedatakeyb";
            this.filedatakeyb.Size = new System.Drawing.Size(121, 29);
            this.filedatakeyb.TabIndex = 9;
            this.filedatakeyb.Text = "Save dataKb";
            this.filedatakeyb.UseVisualStyleBackColor = true;
            this.filedatakeyb.Click += new System.EventHandler(this.filedatakeyb_Click);
            // 
            // txtpathsavedata
            // 
            this.txtpathsavedata.Location = new System.Drawing.Point(209, 213);
            this.txtpathsavedata.Multiline = true;
            this.txtpathsavedata.Name = "txtpathsavedata";
            this.txtpathsavedata.Size = new System.Drawing.Size(976, 29);
            this.txtpathsavedata.TabIndex = 10;
            // 
            // datakeybb
            // 
            this.datakeybb.Location = new System.Drawing.Point(209, 155);
            this.datakeybb.Multiline = true;
            this.datakeybb.Name = "datakeybb";
            this.datakeybb.Size = new System.Drawing.Size(976, 29);
            this.datakeybb.TabIndex = 12;
            // 
            // datakeyb
            // 
            this.datakeyb.Location = new System.Drawing.Point(63, 152);
            this.datakeyb.Name = "datakeyb";
            this.datakeyb.Size = new System.Drawing.Size(121, 29);
            this.datakeyb.TabIndex = 11;
            this.datakeyb.Text = "Enter data";
            this.datakeyb.UseVisualStyleBackColor = true;
            this.datakeyb.Click += new System.EventHandler(this.datakeyb_Click);
            // 
            // keyb
            // 
            this.keyb.AutoSize = true;
            this.keyb.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.keyb.Location = new System.Drawing.Point(6, 36);
            this.keyb.Name = "keyb";
            this.keyb.Size = new System.Drawing.Size(142, 33);
            this.keyb.TabIndex = 13;
            this.keyb.TabStop = true;
            this.keyb.Text = "Keyboard";
            this.keyb.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.pemsig);
            this.groupBox1.Controls.Add(this.bersig);
            this.groupBox1.Location = new System.Drawing.Point(829, 20);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(253, 109);
            this.groupBox1.TabIndex = 14;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Type Key";
            // 
            // flpl
            // 
            this.flpl.AutoSize = true;
            this.flpl.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.flpl.Location = new System.Drawing.Point(172, 35);
            this.flpl.Name = "flpl";
            this.flpl.Size = new System.Drawing.Size(75, 33);
            this.flpl.TabIndex = 15;
            this.flpl.TabStop = true;
            this.flpl.Text = "File";
            this.flpl.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.keyb);
            this.groupBox2.Controls.Add(this.flpl);
            this.groupBox2.Location = new System.Drawing.Point(182, 23);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(253, 106);
            this.groupBox2.TabIndex = 16;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Input Data";
            this.groupBox2.Enter += new System.EventHandler(this.groupBox2_Enter);
            // 
            // txtpathsig
            // 
            this.txtpathsig.Location = new System.Drawing.Point(587, 453);
            this.txtpathsig.Multiline = true;
            this.txtpathsig.Name = "txtpathsig";
            this.txtpathsig.Size = new System.Drawing.Size(598, 102);
            this.txtpathsig.TabIndex = 17;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1201, 590);
            this.Controls.Add(this.tabControl1);
            this.Name = "Form1";
            this.Text = "LAB4";
            this.tabControl1.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl tabControl1;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.RadioButton keypem;
        private System.Windows.Forms.RadioButton keyber;
        private System.Windows.Forms.TextBox txtPathpub;
        private System.Windows.Forms.TextBox txtPathpriv;
        private System.Windows.Forms.Button pathpub;
        private System.Windows.Forms.Button pathpriv;
        private System.Windows.Forms.TextBox txtprintpath;
        private System.Windows.Forms.Button Genkeyclik;
        private System.Windows.Forms.RadioButton bersig;
        private System.Windows.Forms.RadioButton pemsig;
        private System.Windows.Forms.Button pathdata;
        private System.Windows.Forms.TextBox txtdata;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button pathprivkey;
        private System.Windows.Forms.TextBox txtsign;
        private System.Windows.Forms.TextBox txtpriv;
        private System.Windows.Forms.Button Signclik;
        private System.Windows.Forms.Button Vericlik;
        private System.Windows.Forms.Button pathdatal;
        private System.Windows.Forms.TextBox txtpathdatal;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button pathpubl;
        private System.Windows.Forms.TextBox txtpathsigl;
        private System.Windows.Forms.TextBox txtpathpubl;
        private System.Windows.Forms.RadioButton berv;
        private System.Windows.Forms.RadioButton pemv;
        private System.Windows.Forms.TextBox txtpathsavedata;
        private System.Windows.Forms.Button filedatakeyb;
        private System.Windows.Forms.TextBox datakeybb;
        private System.Windows.Forms.Button datakeyb;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton keyb;
        private System.Windows.Forms.RadioButton flpl;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox txtpathsig;
    }
}

