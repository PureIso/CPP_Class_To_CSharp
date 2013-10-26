using System;
using System.Windows.Forms;
using oNativeLib;

namespace NativeTest
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            oManaged_Reader a = new oManaged_Reader(@"C:\Users\ola\Desktop\Dropbox\Programming\botnet.txt");
            textBox1.Text = a.ReadAllLines();
            a.Dispose();
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            oManaged_Reader a = new oManaged_Reader(@"C:\Users\ola\Desktop\Dropbox\Programming\botnet.txt");
            textBox2.Text = a.ReadLine(int.Parse(numericUpDown1.Value.ToString()));
            a.Dispose();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            oManaged_FileAndDirectory.FileCopy(@"C:\Users\ola\Desktop\Dropbox\Programming\botnet.txt",
                @"C:\Users\ola\Desktop\Dropbox\aa.txt");
        }

        private void button3_Click(object sender, EventArgs e)
        {
            oManaged_FileAndDirectory.oMoveFileNetwork("C:\\Users\\ola\\Desktop\\Dropbox\\Programming\\botnet.txt",
                "\\\\192.168.1.14\\media", "pi", "raspberry");
        }
    }
}
