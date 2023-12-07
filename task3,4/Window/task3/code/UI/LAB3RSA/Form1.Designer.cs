namespace LAB3RSA
{
    partial class MainFont
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
            this.Lab3 = new System.Windows.Forms.TabControl();
            this.GenKey = new System.Windows.Forms.TabPage();
            this.savepri = new System.Windows.Forms.Button();
            this.savepub = new System.Windows.Forms.Button();
            this.txtKey = new System.Windows.Forms.TextBox();
            this.pathpriv = new System.Windows.Forms.TextBox();
            this.pathpubl = new System.Windows.Forms.TextBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.BER = new System.Windows.Forms.RadioButton();
            this.PEM = new System.Windows.Forms.RadioButton();
            this.GenKeyclik = new System.Windows.Forms.Button();
            this.Enc = new System.Windows.Forms.TabPage();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.cipscreen = new System.Windows.Forms.TextBox();
            this.Encryptclik = new System.Windows.Forms.Button();
            this.txtPath3 = new System.Windows.Forms.TextBox();
            this.button3 = new System.Windows.Forms.Button();
            this.txtPath2 = new System.Windows.Forms.TextBox();
            this.button2 = new System.Windows.Forms.Button();
            this.txtPath1 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.screencip = new System.Windows.Forms.RadioButton();
            this.filecip = new System.Windows.Forms.RadioButton();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.base64cip = new System.Windows.Forms.RadioButton();
            this.hexcip = new System.Windows.Forms.RadioButton();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.pemcip = new System.Windows.Forms.RadioButton();
            this.bercip = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.keyboardpl = new System.Windows.Forms.RadioButton();
            this.pathpl = new System.Windows.Forms.RadioButton();
            this.Dec = new System.Windows.Forms.TabPage();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.plbox = new System.Windows.Forms.TextBox();
            this.Decryptclik = new System.Windows.Forms.Button();
            this.txtPath6 = new System.Windows.Forms.TextBox();
            this.button5 = new System.Windows.Forms.Button();
            this.txtPath5 = new System.Windows.Forms.TextBox();
            this.button6 = new System.Windows.Forms.Button();
            this.txtPath4 = new System.Windows.Forms.TextBox();
            this.button7 = new System.Windows.Forms.Button();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.screenpl = new System.Windows.Forms.RadioButton();
            this.filepl = new System.Windows.Forms.RadioButton();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.base64pl = new System.Windows.Forms.RadioButton();
            this.hexpl = new System.Windows.Forms.RadioButton();
            this.groupBox7 = new System.Windows.Forms.GroupBox();
            this.pempl = new System.Windows.Forms.RadioButton();
            this.berpl = new System.Windows.Forms.RadioButton();
            this.groupBox8 = new System.Windows.Forms.GroupBox();
            this.keyboardcip = new System.Windows.Forms.RadioButton();
            this.pathcip = new System.Windows.Forms.RadioButton();
            this.Lab3.SuspendLayout();
            this.GenKey.SuspendLayout();
            this.Enc.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.Dec.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.groupBox7.SuspendLayout();
            this.groupBox8.SuspendLayout();
            this.SuspendLayout();
            // 
            // Lab3
            // 
            this.Lab3.Controls.Add(this.GenKey);
            this.Lab3.Controls.Add(this.Enc);
            this.Lab3.Controls.Add(this.Dec);
            this.Lab3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.Lab3.Location = new System.Drawing.Point(0, 0);
            this.Lab3.Name = "Lab3";
            this.Lab3.SelectedIndex = 0;
            this.Lab3.Size = new System.Drawing.Size(1192, 672);
            this.Lab3.TabIndex = 0;
            // 
            // GenKey
            // 
            this.GenKey.Controls.Add(this.savepri);
            this.GenKey.Controls.Add(this.savepub);
            this.GenKey.Controls.Add(this.txtKey);
            this.GenKey.Controls.Add(this.pathpriv);
            this.GenKey.Controls.Add(this.pathpubl);
            this.GenKey.Controls.Add(this.textBox1);
            this.GenKey.Controls.Add(this.BER);
            this.GenKey.Controls.Add(this.PEM);
            this.GenKey.Controls.Add(this.GenKeyclik);
            this.GenKey.Location = new System.Drawing.Point(4, 25);
            this.GenKey.Name = "GenKey";
            this.GenKey.Size = new System.Drawing.Size(1184, 643);
            this.GenKey.TabIndex = 0;
            this.GenKey.Text = "Gen Key";
            this.GenKey.UseVisualStyleBackColor = true;
            this.GenKey.Click += new System.EventHandler(this.tabPage1_Click);
            // 
            // savepri
            // 
            this.savepri.Location = new System.Drawing.Point(55, 396);
            this.savepri.Name = "savepri";
            this.savepri.Size = new System.Drawing.Size(209, 40);
            this.savepri.TabIndex = 11;
            this.savepri.Text = "Path PrivateKey";
            this.savepri.UseVisualStyleBackColor = true;
            this.savepri.Click += new System.EventHandler(this.savepri_Click);
            // 
            // savepub
            // 
            this.savepub.Location = new System.Drawing.Point(55, 177);
            this.savepub.Name = "savepub";
            this.savepub.Size = new System.Drawing.Size(209, 40);
            this.savepub.TabIndex = 10;
            this.savepub.Text = "Path PublicKey";
            this.savepub.UseVisualStyleBackColor = true;
            this.savepub.Click += new System.EventHandler(this.savepub_Click);
            // 
            // txtKey
            // 
            this.txtKey.Location = new System.Drawing.Point(694, 495);
            this.txtKey.Multiline = true;
            this.txtKey.Name = "txtKey";
            this.txtKey.Size = new System.Drawing.Size(482, 118);
            this.txtKey.TabIndex = 9;
            this.txtKey.TextChanged += new System.EventHandler(this.textBox2_TextChanged_2);
            // 
            // pathpriv
            // 
            this.pathpriv.Location = new System.Drawing.Point(301, 393);
            this.pathpriv.Multiline = true;
            this.pathpriv.Name = "pathpriv";
            this.pathpriv.Size = new System.Drawing.Size(875, 43);
            this.pathpriv.TabIndex = 6;
            // 
            // pathpubl
            // 
            this.pathpubl.Location = new System.Drawing.Point(301, 174);
            this.pathpubl.Multiline = true;
            this.pathpubl.Name = "pathpubl";
            this.pathpubl.Size = new System.Drawing.Size(875, 43);
            this.pathpubl.TabIndex = 5;
            this.pathpubl.TextChanged += new System.EventHandler(this.textBox2_TextChanged);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(272, 177);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(0, 22);
            this.textBox1.TabIndex = 4;
            // 
            // BER
            // 
            this.BER.AutoSize = true;
            this.BER.Font = new System.Drawing.Font("Montserrat Black", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.BER.Location = new System.Drawing.Point(877, 28);
            this.BER.Name = "BER";
            this.BER.Size = new System.Drawing.Size(91, 39);
            this.BER.TabIndex = 3;
            this.BER.TabStop = true;
            this.BER.Text = "BER";
            this.BER.UseVisualStyleBackColor = true;
            // 
            // PEM
            // 
            this.PEM.AutoSize = true;
            this.PEM.Font = new System.Drawing.Font("Montserrat Black", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.PEM.Location = new System.Drawing.Point(301, 28);
            this.PEM.Name = "PEM";
            this.PEM.Size = new System.Drawing.Size(96, 39);
            this.PEM.TabIndex = 2;
            this.PEM.TabStop = true;
            this.PEM.Text = "PEM";
            this.PEM.UseVisualStyleBackColor = true;
            this.PEM.CheckedChanged += new System.EventHandler(this.PEM_CheckedChanged);
            // 
            // GenKeyclik
            // 
            this.GenKeyclik.Font = new System.Drawing.Font("Montserrat Black", 15F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.GenKeyclik.Location = new System.Drawing.Point(408, 517);
            this.GenKeyclik.Name = "GenKeyclik";
            this.GenKeyclik.Padding = new System.Windows.Forms.Padding(25);
            this.GenKeyclik.Size = new System.Drawing.Size(245, 96);
            this.GenKeyclik.TabIndex = 0;
            this.GenKeyclik.Text = "GEN KEY";
            this.GenKeyclik.UseVisualStyleBackColor = true;
            this.GenKeyclik.Click += new System.EventHandler(this.GenKeyclik_Click);
            // 
            // Enc
            // 
            this.Enc.Controls.Add(this.label3);
            this.Enc.Controls.Add(this.label2);
            this.Enc.Controls.Add(this.label1);
            this.Enc.Controls.Add(this.cipscreen);
            this.Enc.Controls.Add(this.Encryptclik);
            this.Enc.Controls.Add(this.txtPath3);
            this.Enc.Controls.Add(this.button3);
            this.Enc.Controls.Add(this.txtPath2);
            this.Enc.Controls.Add(this.button2);
            this.Enc.Controls.Add(this.txtPath1);
            this.Enc.Controls.Add(this.button1);
            this.Enc.Controls.Add(this.groupBox4);
            this.Enc.Controls.Add(this.groupBox3);
            this.Enc.Controls.Add(this.groupBox2);
            this.Enc.Controls.Add(this.groupBox1);
            this.Enc.Location = new System.Drawing.Point(4, 25);
            this.Enc.Name = "Enc";
            this.Enc.Padding = new System.Windows.Forms.Padding(3);
            this.Enc.Size = new System.Drawing.Size(1184, 643);
            this.Enc.TabIndex = 1;
            this.Enc.Text = "Encrypt";
            this.Enc.UseVisualStyleBackColor = true;
            this.Enc.Click += new System.EventHandler(this.Enc_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(46, 314);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(70, 16);
            this.label3.TabIndex = 14;
            this.label3.Text = "Public Key";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(46, 250);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(46, 16);
            this.label2.TabIndex = 13;
            this.label2.Text = "Cipher";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(46, 191);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(57, 16);
            this.label1.TabIndex = 12;
            this.label1.Text = "Plaintext";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // cipscreen
            // 
            this.cipscreen.Location = new System.Drawing.Point(350, 372);
            this.cipscreen.Multiline = true;
            this.cipscreen.Name = "cipscreen";
            this.cipscreen.Size = new System.Drawing.Size(817, 263);
            this.cipscreen.TabIndex = 11;
            // 
            // Encryptclik
            // 
            this.Encryptclik.Location = new System.Drawing.Point(19, 483);
            this.Encryptclik.Name = "Encryptclik";
            this.Encryptclik.Size = new System.Drawing.Size(274, 93);
            this.Encryptclik.TabIndex = 10;
            this.Encryptclik.Text = "ENCRYPT";
            this.Encryptclik.UseVisualStyleBackColor = true;
            this.Encryptclik.Click += new System.EventHandler(this.Encryptclik_Click);
            // 
            // txtPath3
            // 
            this.txtPath3.Location = new System.Drawing.Point(258, 311);
            this.txtPath3.Multiline = true;
            this.txtPath3.Name = "txtPath3";
            this.txtPath3.Size = new System.Drawing.Size(900, 24);
            this.txtPath3.TabIndex = 9;
            this.txtPath3.TextChanged += new System.EventHandler(this.txtPath3_TextChanged);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(129, 307);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(123, 30);
            this.button3.TabIndex = 8;
            this.button3.Text = "Open";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // txtPath2
            // 
            this.txtPath2.Location = new System.Drawing.Point(258, 247);
            this.txtPath2.Multiline = true;
            this.txtPath2.Name = "txtPath2";
            this.txtPath2.Size = new System.Drawing.Size(900, 24);
            this.txtPath2.TabIndex = 7;
            this.txtPath2.TextChanged += new System.EventHandler(this.textBox2_TextChanged_1);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(129, 242);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(123, 32);
            this.button2.TabIndex = 6;
            this.button2.Text = "Save";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // txtPath1
            // 
            this.txtPath1.Location = new System.Drawing.Point(258, 183);
            this.txtPath1.Multiline = true;
            this.txtPath1.Name = "txtPath1";
            this.txtPath1.Size = new System.Drawing.Size(900, 25);
            this.txtPath1.TabIndex = 5;
            this.txtPath1.TextChanged += new System.EventHandler(this.txtPath1_TextChanged);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(129, 183);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(123, 33);
            this.button1.TabIndex = 4;
            this.button1.Text = "Open/Data";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.screencip);
            this.groupBox4.Controls.Add(this.filecip);
            this.groupBox4.Location = new System.Drawing.Point(320, 31);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(196, 114);
            this.groupBox4.TabIndex = 3;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Output Cipher";
            // 
            // screencip
            // 
            this.screencip.AutoSize = true;
            this.screencip.Location = new System.Drawing.Point(43, 70);
            this.screencip.Name = "screencip";
            this.screencip.Size = new System.Drawing.Size(71, 20);
            this.screencip.TabIndex = 7;
            this.screencip.TabStop = true;
            this.screencip.Text = "Screen";
            this.screencip.UseVisualStyleBackColor = true;
            // 
            // filecip
            // 
            this.filecip.AutoSize = true;
            this.filecip.Location = new System.Drawing.Point(43, 21);
            this.filecip.Name = "filecip";
            this.filecip.Size = new System.Drawing.Size(50, 20);
            this.filecip.TabIndex = 6;
            this.filecip.TabStop = true;
            this.filecip.Text = "File";
            this.filecip.UseVisualStyleBackColor = true;
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.base64cip);
            this.groupBox3.Controls.Add(this.hexcip);
            this.groupBox3.Location = new System.Drawing.Point(971, 31);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(196, 114);
            this.groupBox3.TabIndex = 2;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Type Cipher";
            // 
            // base64cip
            // 
            this.base64cip.AutoSize = true;
            this.base64cip.Location = new System.Drawing.Point(40, 70);
            this.base64cip.Name = "base64cip";
            this.base64cip.Size = new System.Drawing.Size(78, 20);
            this.base64cip.TabIndex = 5;
            this.base64cip.TabStop = true;
            this.base64cip.Text = "BASE64";
            this.base64cip.UseVisualStyleBackColor = true;
            // 
            // hexcip
            // 
            this.hexcip.AutoSize = true;
            this.hexcip.Location = new System.Drawing.Point(40, 21);
            this.hexcip.Name = "hexcip";
            this.hexcip.Size = new System.Drawing.Size(55, 20);
            this.hexcip.TabIndex = 4;
            this.hexcip.TabStop = true;
            this.hexcip.Text = "HEX";
            this.hexcip.UseVisualStyleBackColor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.pemcip);
            this.groupBox2.Controls.Add(this.bercip);
            this.groupBox2.Location = new System.Drawing.Point(647, 31);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(202, 114);
            this.groupBox2.TabIndex = 1;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Type Key";
            // 
            // pemcip
            // 
            this.pemcip.AutoSize = true;
            this.pemcip.Location = new System.Drawing.Point(35, 70);
            this.pemcip.Name = "pemcip";
            this.pemcip.Size = new System.Drawing.Size(57, 20);
            this.pemcip.TabIndex = 5;
            this.pemcip.TabStop = true;
            this.pemcip.Text = "PEM";
            this.pemcip.UseVisualStyleBackColor = true;
            // 
            // bercip
            // 
            this.bercip.AutoSize = true;
            this.bercip.Location = new System.Drawing.Point(35, 21);
            this.bercip.Name = "bercip";
            this.bercip.Size = new System.Drawing.Size(56, 20);
            this.bercip.TabIndex = 4;
            this.bercip.TabStop = true;
            this.bercip.Text = "BER";
            this.bercip.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.keyboardpl);
            this.groupBox1.Controls.Add(this.pathpl);
            this.groupBox1.Location = new System.Drawing.Point(19, 31);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(196, 114);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Plain Text";
            // 
            // keyboardpl
            // 
            this.keyboardpl.AutoSize = true;
            this.keyboardpl.Location = new System.Drawing.Point(30, 70);
            this.keyboardpl.Name = "keyboardpl";
            this.keyboardpl.Size = new System.Drawing.Size(87, 20);
            this.keyboardpl.TabIndex = 5;
            this.keyboardpl.TabStop = true;
            this.keyboardpl.Text = "Keyboard";
            this.keyboardpl.UseVisualStyleBackColor = true;
            // 
            // pathpl
            // 
            this.pathpl.AutoSize = true;
            this.pathpl.Location = new System.Drawing.Point(30, 21);
            this.pathpl.Name = "pathpl";
            this.pathpl.Size = new System.Drawing.Size(55, 20);
            this.pathpl.TabIndex = 4;
            this.pathpl.TabStop = true;
            this.pathpl.Text = "Path";
            this.pathpl.UseVisualStyleBackColor = true;
            // 
            // Dec
            // 
            this.Dec.Controls.Add(this.label4);
            this.Dec.Controls.Add(this.label5);
            this.Dec.Controls.Add(this.label6);
            this.Dec.Controls.Add(this.plbox);
            this.Dec.Controls.Add(this.Decryptclik);
            this.Dec.Controls.Add(this.txtPath6);
            this.Dec.Controls.Add(this.button5);
            this.Dec.Controls.Add(this.txtPath5);
            this.Dec.Controls.Add(this.button6);
            this.Dec.Controls.Add(this.txtPath4);
            this.Dec.Controls.Add(this.button7);
            this.Dec.Controls.Add(this.groupBox5);
            this.Dec.Controls.Add(this.groupBox6);
            this.Dec.Controls.Add(this.groupBox7);
            this.Dec.Controls.Add(this.groupBox8);
            this.Dec.Location = new System.Drawing.Point(4, 25);
            this.Dec.Name = "Dec";
            this.Dec.Padding = new System.Windows.Forms.Padding(3);
            this.Dec.Size = new System.Drawing.Size(1184, 643);
            this.Dec.TabIndex = 2;
            this.Dec.Text = "Derypt";
            this.Dec.UseVisualStyleBackColor = true;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(45, 302);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(75, 16);
            this.label4.TabIndex = 29;
            this.label4.Text = "Private Key";
            this.label4.Click += new System.EventHandler(this.label4_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(46, 243);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(46, 16);
            this.label5.TabIndex = 28;
            this.label5.Text = "Cipher";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(46, 188);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(57, 16);
            this.label6.TabIndex = 27;
            this.label6.Text = "Plaintext";
            // 
            // plbox
            // 
            this.plbox.Location = new System.Drawing.Point(349, 360);
            this.plbox.Multiline = true;
            this.plbox.Name = "plbox";
            this.plbox.Size = new System.Drawing.Size(817, 263);
            this.plbox.TabIndex = 26;
            // 
            // Decryptclik
            // 
            this.Decryptclik.Location = new System.Drawing.Point(18, 471);
            this.Decryptclik.Name = "Decryptclik";
            this.Decryptclik.Size = new System.Drawing.Size(274, 93);
            this.Decryptclik.TabIndex = 25;
            this.Decryptclik.Text = "DECRYPT";
            this.Decryptclik.UseVisualStyleBackColor = true;
            this.Decryptclik.Click += new System.EventHandler(this.Decryptclik_Click);
            // 
            // txtPath6
            // 
            this.txtPath6.Location = new System.Drawing.Point(257, 299);
            this.txtPath6.Multiline = true;
            this.txtPath6.Name = "txtPath6";
            this.txtPath6.Size = new System.Drawing.Size(900, 24);
            this.txtPath6.TabIndex = 24;
            // 
            // button5
            // 
            this.button5.Location = new System.Drawing.Point(128, 295);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(123, 30);
            this.button5.TabIndex = 23;
            this.button5.Text = "Open";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // txtPath5
            // 
            this.txtPath5.Location = new System.Drawing.Point(257, 235);
            this.txtPath5.Multiline = true;
            this.txtPath5.Name = "txtPath5";
            this.txtPath5.Size = new System.Drawing.Size(900, 24);
            this.txtPath5.TabIndex = 22;
            // 
            // button6
            // 
            this.button6.Location = new System.Drawing.Point(128, 230);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(123, 32);
            this.button6.TabIndex = 21;
            this.button6.Text = "Open/Data";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // txtPath4
            // 
            this.txtPath4.Location = new System.Drawing.Point(257, 171);
            this.txtPath4.Multiline = true;
            this.txtPath4.Name = "txtPath4";
            this.txtPath4.Size = new System.Drawing.Size(900, 25);
            this.txtPath4.TabIndex = 20;
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(128, 171);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(123, 33);
            this.button7.TabIndex = 19;
            this.button7.Text = "Save";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.screenpl);
            this.groupBox5.Controls.Add(this.filepl);
            this.groupBox5.Location = new System.Drawing.Point(970, 19);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(196, 114);
            this.groupBox5.TabIndex = 18;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "Output Plaintext";
            // 
            // screenpl
            // 
            this.screenpl.AutoSize = true;
            this.screenpl.Location = new System.Drawing.Point(43, 70);
            this.screenpl.Name = "screenpl";
            this.screenpl.Size = new System.Drawing.Size(71, 20);
            this.screenpl.TabIndex = 7;
            this.screenpl.TabStop = true;
            this.screenpl.Text = "Screen";
            this.screenpl.UseVisualStyleBackColor = true;
            // 
            // filepl
            // 
            this.filepl.AutoSize = true;
            this.filepl.Location = new System.Drawing.Point(43, 21);
            this.filepl.Name = "filepl";
            this.filepl.Size = new System.Drawing.Size(50, 20);
            this.filepl.TabIndex = 6;
            this.filepl.TabStop = true;
            this.filepl.Text = "File";
            this.filepl.UseVisualStyleBackColor = true;
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.base64pl);
            this.groupBox6.Controls.Add(this.hexpl);
            this.groupBox6.Location = new System.Drawing.Point(294, 19);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(196, 114);
            this.groupBox6.TabIndex = 17;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "Type Cipher";
            // 
            // base64pl
            // 
            this.base64pl.AutoSize = true;
            this.base64pl.Location = new System.Drawing.Point(40, 70);
            this.base64pl.Name = "base64pl";
            this.base64pl.Size = new System.Drawing.Size(78, 20);
            this.base64pl.TabIndex = 5;
            this.base64pl.TabStop = true;
            this.base64pl.Text = "BASE64";
            this.base64pl.UseVisualStyleBackColor = true;
            // 
            // hexpl
            // 
            this.hexpl.AutoSize = true;
            this.hexpl.Location = new System.Drawing.Point(40, 21);
            this.hexpl.Name = "hexpl";
            this.hexpl.Size = new System.Drawing.Size(55, 20);
            this.hexpl.TabIndex = 4;
            this.hexpl.TabStop = true;
            this.hexpl.Text = "HEX";
            this.hexpl.UseVisualStyleBackColor = true;
            // 
            // groupBox7
            // 
            this.groupBox7.Controls.Add(this.pempl);
            this.groupBox7.Controls.Add(this.berpl);
            this.groupBox7.Location = new System.Drawing.Point(646, 19);
            this.groupBox7.Name = "groupBox7";
            this.groupBox7.Size = new System.Drawing.Size(202, 114);
            this.groupBox7.TabIndex = 16;
            this.groupBox7.TabStop = false;
            this.groupBox7.Text = "Type Key";
            // 
            // pempl
            // 
            this.pempl.AutoSize = true;
            this.pempl.Location = new System.Drawing.Point(35, 70);
            this.pempl.Name = "pempl";
            this.pempl.Size = new System.Drawing.Size(57, 20);
            this.pempl.TabIndex = 5;
            this.pempl.TabStop = true;
            this.pempl.Text = "PEM";
            this.pempl.UseVisualStyleBackColor = true;
            // 
            // berpl
            // 
            this.berpl.AutoSize = true;
            this.berpl.Location = new System.Drawing.Point(35, 21);
            this.berpl.Name = "berpl";
            this.berpl.Size = new System.Drawing.Size(56, 20);
            this.berpl.TabIndex = 4;
            this.berpl.TabStop = true;
            this.berpl.Text = "BER";
            this.berpl.UseVisualStyleBackColor = true;
            // 
            // groupBox8
            // 
            this.groupBox8.Controls.Add(this.keyboardcip);
            this.groupBox8.Controls.Add(this.pathcip);
            this.groupBox8.Location = new System.Drawing.Point(18, 19);
            this.groupBox8.Name = "groupBox8";
            this.groupBox8.Size = new System.Drawing.Size(196, 114);
            this.groupBox8.TabIndex = 15;
            this.groupBox8.TabStop = false;
            this.groupBox8.Text = "Cipher Text";
            // 
            // keyboardcip
            // 
            this.keyboardcip.AutoSize = true;
            this.keyboardcip.Location = new System.Drawing.Point(30, 70);
            this.keyboardcip.Name = "keyboardcip";
            this.keyboardcip.Size = new System.Drawing.Size(87, 20);
            this.keyboardcip.TabIndex = 5;
            this.keyboardcip.TabStop = true;
            this.keyboardcip.Text = "Keyboard";
            this.keyboardcip.UseVisualStyleBackColor = true;
            // 
            // pathcip
            // 
            this.pathcip.AutoSize = true;
            this.pathcip.Location = new System.Drawing.Point(30, 21);
            this.pathcip.Name = "pathcip";
            this.pathcip.Size = new System.Drawing.Size(55, 20);
            this.pathcip.TabIndex = 4;
            this.pathcip.TabStop = true;
            this.pathcip.Text = "Path";
            this.pathcip.UseVisualStyleBackColor = true;
            // 
            // MainFont
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1192, 672);
            this.Controls.Add(this.Lab3);
            this.Name = "MainFont";
            this.Text = "LAB3";
            this.Lab3.ResumeLayout(false);
            this.GenKey.ResumeLayout(false);
            this.GenKey.PerformLayout();
            this.Enc.ResumeLayout(false);
            this.Enc.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.Dec.ResumeLayout(false);
            this.Dec.PerformLayout();
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.groupBox7.ResumeLayout(false);
            this.groupBox7.PerformLayout();
            this.groupBox8.ResumeLayout(false);
            this.groupBox8.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabControl Lab3;
        private System.Windows.Forms.TabPage GenKey;
        private System.Windows.Forms.TabPage Enc;
        private System.Windows.Forms.TabPage Dec;
        private System.Windows.Forms.Button GenKeyclik;
        private System.Windows.Forms.RadioButton PEM;
        private System.Windows.Forms.RadioButton BER;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox pathpubl;
        private System.Windows.Forms.TextBox pathpriv;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.RadioButton pemcip;
        private System.Windows.Forms.RadioButton bercip;
        private System.Windows.Forms.RadioButton keyboardpl;
        private System.Windows.Forms.RadioButton pathpl;
        private System.Windows.Forms.RadioButton screencip;
        private System.Windows.Forms.RadioButton filecip;
        private System.Windows.Forms.RadioButton base64cip;
        private System.Windows.Forms.RadioButton hexcip;
        private System.Windows.Forms.TextBox txtPath1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox txtPath2;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox txtPath3;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button Encryptclik;
        private System.Windows.Forms.TextBox cipscreen;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox plbox;
        private System.Windows.Forms.Button Decryptclik;
        private System.Windows.Forms.TextBox txtPath6;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.TextBox txtPath5;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.TextBox txtPath4;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.RadioButton screenpl;
        private System.Windows.Forms.RadioButton filepl;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.RadioButton base64pl;
        private System.Windows.Forms.RadioButton hexpl;
        private System.Windows.Forms.GroupBox groupBox7;
        private System.Windows.Forms.RadioButton pempl;
        private System.Windows.Forms.RadioButton berpl;
        private System.Windows.Forms.GroupBox groupBox8;
        private System.Windows.Forms.RadioButton keyboardcip;
        private System.Windows.Forms.RadioButton pathcip;
        private System.Windows.Forms.TextBox txtKey;
        private System.Windows.Forms.Button savepri;
        private System.Windows.Forms.Button savepub;
    }
}

