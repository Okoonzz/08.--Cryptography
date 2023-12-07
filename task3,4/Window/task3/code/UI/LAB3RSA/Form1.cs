using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;

namespace LAB3RSA
{
    public partial class MainFont : Form
    {
        [DllImport("keygen.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "KeyGen")]
        private static extern bool GenerateKey(string filePriv, string filePub, int choice);

        [DllImport("enc.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "Encrypt")]
        private static extern void EncryptData(string filenamedata, string filenamecipher, string filenamekey, int wheredata, int wherecipher, int typepubkey, int typecipher, StringBuilder str , int maxLen);

        [DllImport("Decr.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "Decrypt")]
        private static extern void DecryptData(string filenamedata, string filenamecipher, string filenamekey, int wherecip, int wherecipherout, int typeprivkey, int typecipher, StringBuilder str, int maxLen);

        public MainFont()
        {
            InitializeComponent();
        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void checkedListBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void PEM_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void GenKeyclik_Click(object sender, EventArgs e)
        {
            string filePrivPath = pathpriv.Text;
            string filePubPath = pathpubl.Text;
            int choice;
            if(filePrivPath == "" || filePubPath == "")
            {
                MessageBox.Show("Please enter the path", "Warning!!!",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            if (BER.Checked == true)
            {
                choice = 1;
            }
            else
            {
                choice = 2;
            }
            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();
            if (GenerateKey(filePrivPath, filePubPath, choice))
            {
                stopWatch.Stop();
                TimeSpan ts = stopWatch.Elapsed;
                string elapsedTime = ts.TotalMilliseconds.ToString();
                txtKey.Text = "[+] Your Private Key is saved at: " + filePrivPath + "\r\n" + "[+] Your Public Key is saved at: " + filePubPath;
                MessageBox.Show("Generate successful." + "\r\n" + "Total time: " + elapsedTime + "ms");
            }
            else
            {
                MessageBox.Show("Fail.");
            }
        }

        private void Enc_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog1 = new OpenFileDialog();
            openFileDialog1.Title = "Select File";
            openFileDialog1.InitialDirectory = @"C:\";//--"C:\\";
            openFileDialog1.Filter = "All files (*.*)|*.*|Text File (*.txt)|*.txt";
            openFileDialog1.FilterIndex = 2;
            openFileDialog1.ShowDialog();
            if (openFileDialog1.FileName != "")
            { txtPath1.Text = openFileDialog1.FileName; }
        }

        private void button2_Click(object sender, EventArgs e)
        {

            SaveFileDialog saveFileDialog21 = new SaveFileDialog();
            saveFileDialog21.Filter = "All files (*.*)|*.*|Text File (*.txt)|*.txt";
            saveFileDialog21.Title = "Save a Cipher File";
            saveFileDialog21.FilterIndex = 1;
            saveFileDialog21.RestoreDirectory = true;
            if (saveFileDialog21.ShowDialog() == DialogResult.OK)
            {
                txtPath2.Text = saveFileDialog21.FileName;
            }
        }

        private void txtPath1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void txtPath3_TextChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog3 = new OpenFileDialog();
            openFileDialog3.Title = "Select File";
            openFileDialog3.InitialDirectory = @"C:\";//--"C:\\";
            openFileDialog3.Filter = "All files (*.*)|*.*|BER (*.ber)|*.ber|PEM (*.pem)|*.pem";
            openFileDialog3.FilterIndex = 2;
            openFileDialog3.ShowDialog();
            if (openFileDialog3.FileName != "")
            { txtPath3.Text = openFileDialog3.FileName; }
        }

        private void Encryptclik_Click(object sender, EventArgs e)
        {
            int STRING_MAX_LENGTH = 5000;
            string PathPlaintext = txtPath1.Text;
            string Pathcipher = txtPath2.Text;
            string PathKeypub = txtPath3.Text;
            int choicedata, choicecipout, choicekey, choiceciptype;

            if (PathPlaintext == "" || PathKeypub == "")
            {
                MessageBox.Show("Please enter the path", "Warning!!!",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            //data
            if (pathpl.Checked == true)
            {
                choicedata = 1;
            }
            else
            {
                choicedata = 2;
            }

            //type key
            if (bercip.Checked == true)
            {
                choicekey = 1;
            }
            else
            {
                choicekey = 2;
            }

            //type cipher
            if(hexcip.Checked == true)
            {
                choiceciptype = 1;
            }
            else
            {
                choiceciptype = 2;
            }

            //where cipher
            if (filecip.Checked == true)
            {
                if(Pathcipher == "")
                {
                    MessageBox.Show("Please enter the path", "Warning!!!",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                choicecipout = 1;
                StringBuilder str = new StringBuilder(STRING_MAX_LENGTH);
                Stopwatch stopWatch = new Stopwatch();
                stopWatch.Start();
                EncryptData(PathPlaintext, Pathcipher, PathKeypub, choicedata, choicecipout, choicekey, choiceciptype,str ,0);
                stopWatch.Stop();
                TimeSpan ts = stopWatch.Elapsed;
                string elapsedTime = ts.TotalMilliseconds.ToString();
                cipscreen.Text = "[+] Your file has been saved: " + Pathcipher;
                MessageBox.Show("Encrypt successful." + "\r\n" + "Total time: " + elapsedTime + "ms");
            }
            else
            {
                choicecipout = 2;
                StringBuilder str = new StringBuilder(STRING_MAX_LENGTH);
                Stopwatch stopWatch = new Stopwatch();
                stopWatch.Start();
                EncryptData(PathPlaintext, Pathcipher, PathKeypub, choicedata, choicecipout, choicekey, choiceciptype, str, STRING_MAX_LENGTH);
                stopWatch.Stop();
                TimeSpan ts = stopWatch.Elapsed;
                string elapsedTime = ts.TotalMilliseconds.ToString();
                cipscreen.Text = str.ToString();
                MessageBox.Show("Encrypt successful." + "\r\n" + "Total time: " + elapsedTime +"ms");
            }
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        private void button7_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog12 = new SaveFileDialog();
            saveFileDialog12.Filter = "All files (*.*)|*.*|Text File (*.txt)|*.txt";
            saveFileDialog12.Title = "Save a Plaintext File";
            saveFileDialog12.FilterIndex = 1;
            saveFileDialog12.RestoreDirectory = true;
            if (saveFileDialog12.ShowDialog() == DialogResult.OK)
            {
                txtPath4.Text = saveFileDialog12.FileName;
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog5 = new OpenFileDialog();
            openFileDialog5.Title = "Select File";
            openFileDialog5.InitialDirectory = @"C:\";//--"C:\\";
            openFileDialog5.Filter = "All files (*.*)|*.*|Text File (*.txt)|*.txt";
            openFileDialog5.FilterIndex = 2;
            openFileDialog5.ShowDialog();
            if (openFileDialog5.FileName != "")
            { txtPath5.Text = openFileDialog5.FileName; }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog6 = new OpenFileDialog();
            openFileDialog6.Title = "Select File";
            openFileDialog6.InitialDirectory = @"C:\";//--"C:\\";
            openFileDialog6.Filter = "All files (*.*)|*.*|BER (*.ber)|*.ber|PEM (*.pem)|*.pem";
            openFileDialog6.FilterIndex = 2;
            openFileDialog6.ShowDialog();
            if (openFileDialog6.FileName != "")
            { txtPath6.Text = openFileDialog6.FileName; }
        }

        private void Decryptclik_Click(object sender, EventArgs e)
        {
            int STRING_MAX_LENGTH = 5000;
            string dataPath = txtPath4.Text;
            string cipPath = txtPath5.Text;
            string keyPath = txtPath6.Text;
            int choicecip, choicetypecip, choicetypekey, choiceout;

            if (cipPath == "" || keyPath == "")
            {
                MessageBox.Show("Please enter the path", "Warning!!!",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            //where cipher
            if (pathcip.Checked == true)
            {
                choicecip = 1;
            }
            else
            {
                choicecip = 2;
            }

            //type cipher
            if(hexpl.Checked == true)
            {
                choicetypecip = 1;
            }
            else
            {
                choicetypecip= 2;
            }

            //type key
            if (berpl.Checked == true)
            {
                choicetypekey = 1;
            }
            else
            {
                choicetypekey= 2;
            }

            //where plaintext
            if(filepl.Checked == true)
            {
                if(dataPath == "")
                {
                    MessageBox.Show("Please enter the path", "Warning!!!",
                        MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                choiceout = 1;
                StringBuilder str = new StringBuilder(STRING_MAX_LENGTH);
                Stopwatch stopWatch = new Stopwatch();
                stopWatch.Start();
                DecryptData(dataPath, cipPath, keyPath, choicecip, choiceout, choicetypekey, choicetypecip, str, 0);
                stopWatch.Stop();
                TimeSpan ts = stopWatch.Elapsed;
                string elapsedTime = ts.TotalMilliseconds.ToString();
                plbox.Text = "[+] Your file has been saved: " + dataPath;
                MessageBox.Show("Decrypt successful." + "\r\n" + "Total time: " + elapsedTime + "ms");
            }
            else
            {
                choiceout = 2;
                StringBuilder str = new StringBuilder(STRING_MAX_LENGTH);
                Stopwatch stopWatch = new Stopwatch();
                stopWatch.Start();
                DecryptData(dataPath, cipPath, keyPath, choicecip, choiceout, choicetypekey, choicetypecip, str, STRING_MAX_LENGTH);
                stopWatch.Stop();
                TimeSpan ts = stopWatch.Elapsed;
                string elapsedTime = ts.TotalMilliseconds.ToString();
                plbox.Text = str.ToString();
                MessageBox.Show("Decrypt successful." + "\r\n" + "Total time: " + elapsedTime + "ms");
            }

        }

        private void textBox2_TextChanged_2(object sender, EventArgs e)
        {

        }

        private void savepub_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            saveFileDialog1.Filter = "All files (*.*)|*.*|BER (*.ber)|*.ber|PEM (*.pem)|*.pem";
            saveFileDialog1.Title = "Save a Key File";
            saveFileDialog1.FilterIndex = 1;
            saveFileDialog1.RestoreDirectory = true;
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                pathpubl.Text = saveFileDialog1.FileName;
            }
        }

        private void savepri_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog2 = new SaveFileDialog();
            saveFileDialog2.Filter = "All files (*.*)|*.*|BER (*.ber)|*.ber|PEM (*.pem)|*.pem";
            saveFileDialog2.Title = "Save a Key File";
            saveFileDialog2.FilterIndex = 1;
            saveFileDialog2.RestoreDirectory = true;
            if (saveFileDialog2.ShowDialog() == DialogResult.OK)
            {
                pathpriv.Text = saveFileDialog2.FileName;
            }
        }
    }
}



