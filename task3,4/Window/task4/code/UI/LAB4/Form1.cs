using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;

namespace LAB4
{
    public partial class Form1 : Form
    {
        [DllImport("genk.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "genkey")]
        private static extern bool GenerateKey(string filenamepriv, string filenamepub, int typekey);


        [DllImport("sign.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "signa")]
        private static extern bool Signature(string pathprivkey, string pathdata, string data, string pathdatakeyb, string signatruepath, int choice, int choicepath);

        [DllImport("Verif.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "verifySignature")]
        private static extern bool Verifyy(string pathpub, string pathdata, string pathsig, int choice);


        public Form1()
        {
            InitializeComponent();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void pathpriv_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            saveFileDialog1.Filter = "DER (*.der)|*.der|PEM (*.pem)|*.pem";
            saveFileDialog1.Title = "Save a Key File";
            saveFileDialog1.FilterIndex = 1;
            saveFileDialog1.RestoreDirectory = true;
            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                txtPathpriv.Text = saveFileDialog1.FileName;
            }
        }

        private void pathpub_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog2 = new SaveFileDialog();
            saveFileDialog2.Filter = "DER (*.der)|*.der|PEM (*.pem)|*.pem";
            saveFileDialog2.Title = "Save a Key File";
            saveFileDialog2.FilterIndex = 1;
            saveFileDialog2.RestoreDirectory = true;
            if (saveFileDialog2.ShowDialog() == DialogResult.OK)
            {
                txtPathpub.Text = saveFileDialog2.FileName;
            }
        }

        private void Genkeyclik_Click(object sender, EventArgs e)
        {
            string Pathpriv = txtPathpriv.Text;
            string Pathpub = txtPathpub.Text;
            int choice;

            if(Pathpriv == "" || Pathpub == "")
            {
                MessageBox.Show("Please enter the path", "Warning!!!",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            if (keypem.Checked == true)
            {
                choice = 1;
            }
            else
            {
                choice = 2;
            }
            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();
            if (GenerateKey(Pathpriv, Pathpub, choice))
            {
                stopWatch.Stop();
                TimeSpan ts = stopWatch.Elapsed;
                string elapsedTime = ts.TotalMilliseconds.ToString();
                txtprintpath.Text = "[+] Your Private Key is saved at: " + Pathpriv + "\r\n" + "[+] Your Public Key is saved at: " + Pathpub;
                MessageBox.Show("Generate successful." + "\r\n" + "Total time: " + elapsedTime + "ms");
            }
            else
            {
                MessageBox.Show("Fail.");
            }
        }

        private void radioButton1_CheckedChanged_1(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog3 = new SaveFileDialog();
            saveFileDialog3.Filter = "All files (*.*)|*.*|Bin File (*.bin)|*.bin";
            saveFileDialog3.Title = "Save a Key File";
            saveFileDialog3.FilterIndex = 1;
            saveFileDialog3.RestoreDirectory = true;
            if (saveFileDialog3.ShowDialog() == DialogResult.OK)
            {
                txtsign.Text = saveFileDialog3.FileName;
            }
        }

        private void pathprivkey_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog4 = new OpenFileDialog();
            openFileDialog4.Title = "Select File";
            openFileDialog4.InitialDirectory = @"C:\";//--"C:\\";
            openFileDialog4.Filter = "DER (*.der)|*.der|PEM (*.pem)|*.pem";
            openFileDialog4.FilterIndex = 2;
            openFileDialog4.ShowDialog();
            if (openFileDialog4.FileName != "")
            { txtpriv.Text = openFileDialog4.FileName; }
            else
            { txtpriv.Text = "You didn't select the file!"; }
        }

        private void pathdata_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog5 = new OpenFileDialog();
            openFileDialog5.Title = "Select File";
            openFileDialog5.InitialDirectory = @"C:\";//--"C:\\";
            openFileDialog5.Filter = "All files (*.*)|*.*|Text File (*.txt)|*.txt";
            openFileDialog5.FilterIndex = 2;
            openFileDialog5.ShowDialog();
            if (openFileDialog5.FileName != "")
            { txtdata.Text = openFileDialog5.FileName; }
            else
            { txtdata.Text = "You didn't select the file!"; }
        }

        private void Signclik_Click(object sender, EventArgs e)
        {
            string pathprivkey = txtpriv.Text;
            string pathdata = txtdata.Text;
            string datakeyb = datakeybb.Text;
            string datakeybpath = txtpathsavedata.Text;
            string pathsig = txtsign.Text;
            int choice, choicekeyb;
            
            if(pathsig == "" || pathprivkey == "")
            {
                MessageBox.Show("Please enter the path", "Warning!!!",
                    MessageBoxButtons.OK, MessageBoxIcon.Error);
            }

            if (pemsig.Checked == true)
            {
                choice = 1;
            }
            else
            {
                choice = 2;
            }

            if(keyb.Checked == true)
            {
                if (datakeyb == "" || datakeybpath == "")
                {
                    MessageBox.Show("Please enter the path/data", "Warning!!!",
                        MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                choicekeyb = 2;
                Stopwatch stopWatch = new Stopwatch();
                stopWatch.Start();
                if (Signature(pathprivkey, null, datakeyb, datakeybpath, pathsig, choice, choicekeyb))
                {
                    stopWatch.Stop();
                    TimeSpan ts = stopWatch.Elapsed;
                    string elapsedTime = ts.TotalMilliseconds.ToString();
                    txtpathsig.Text = "[+] Your File is save at: " + pathsig;
                    MessageBox.Show("Signed successfully." + "\r\n" + "Total time: " + elapsedTime + "ms");
                }
                else
                {
                    MessageBox.Show("Fail.");
                }
            }
            else
            {
                if(pathdata == "")
                {
                    MessageBox.Show("Please enter the path", "Warning!!!",
                        MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                choicekeyb = 1;
                Stopwatch stopWatch = new Stopwatch();
                stopWatch.Start();
                if (Signature(pathprivkey, pathdata, null, null, pathsig, choice, choicekeyb))
                {
                    stopWatch.Stop();
                    TimeSpan ts = stopWatch.Elapsed;
                    string elapsedTime = ts.TotalMilliseconds.ToString();
                    txtpathsig.Text = "[+] Your File is save at: " + pathsig;
                    MessageBox.Show("Signed successfully." + "\r\n" + "Total time: " + elapsedTime + "ms");
                }
                else
                {
                    MessageBox.Show("Fail.");
                }
            }


        }

        private void button4_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog9 = new OpenFileDialog();
            openFileDialog9.Title = "Select File";
            openFileDialog9.InitialDirectory = @"C:\";//--"C:\\";
            openFileDialog9.Filter = "All files (*.*)|*.*|Bin File (*.bin)|*.bin";
            openFileDialog9.FilterIndex = 2;
            openFileDialog9.ShowDialog();
            if (openFileDialog9.FileName != "")
            { txtpathsigl.Text = openFileDialog9.FileName; }
        }

        private void pathpubl_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog7 = new OpenFileDialog();
            openFileDialog7.Title = "Select File";
            openFileDialog7.InitialDirectory = @"C:\";//--"C:\\";
            openFileDialog7.Filter = "DER (*.der)|*.der|PEM (*.pem)|*.pem";
            openFileDialog7.FilterIndex = 2;
            openFileDialog7.ShowDialog();
            if (openFileDialog7.FileName != "")
            { txtpathpubl.Text = openFileDialog7.FileName; }
        }

        private void pathdatal_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog8 = new OpenFileDialog();
            openFileDialog8.Title = "Select File";
            openFileDialog8.InitialDirectory = @"C:\";//--"C:\\";
            openFileDialog8.Filter = "All files (*.*)|*.*|Text File (*.txt)|*.txt";
            openFileDialog8.FilterIndex = 2;
            openFileDialog8.ShowDialog();
            if (openFileDialog8.FileName != "")
            { txtpathdatal.Text = openFileDialog8.FileName; }
        }

        private void Sigclik_Click(object sender, EventArgs e)
        {
            string pathpubl = txtpathpubl.Text;
            string pathdatal = txtpathdatal.Text;
            string pathsig = txtpathsigl.Text;
            int choice;
            if(pemv.Checked == true)
            {
                choice = 1;
            }
            else
            {
                choice = 2;
            }

            Stopwatch stopWatch = new Stopwatch();
            stopWatch.Start();
            if (Verifyy(pathpubl, pathdatal, pathsig, choice))
            {
                stopWatch.Stop();
                TimeSpan ts = stopWatch.Elapsed;
                string elapsedTime = ts.TotalMilliseconds.ToString();
                MessageBox.Show("Verified successfully." + "\r\n" + "Total time: " + elapsedTime + "ms");
            }
            else
            {
                MessageBox.Show("No");
            }
        }

        private void filedatakeyb_Click(object sender, EventArgs e)
        {
            SaveFileDialog saveFileDialog122 = new SaveFileDialog();
            saveFileDialog122.Filter = "All files (*.*)|*.*|Text File (*.txt)|*.txt";
            saveFileDialog122.Title = "Save a Key File";
            saveFileDialog122.FilterIndex = 1;
            saveFileDialog122.RestoreDirectory = true;
            if (saveFileDialog122.ShowDialog() == DialogResult.OK)
            {
                txtpathsavedata.Text = saveFileDialog122.FileName;
            }
        }

        private void bersig_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void txtsign_TextChanged(object sender, EventArgs e)
        {

        }

        private void datakeyb_Click(object sender, EventArgs e)
        {

        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }
    }
}
