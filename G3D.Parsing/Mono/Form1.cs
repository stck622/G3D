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

namespace Mono
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //combox_port.DataSource = serialPort1.GetPortNames();
            btn_center.Enabled = false;
            btn_right.Enabled = false;
            btn_left.Enabled = false;
            btn_down.Enabled = false;
            btn_up.Enabled = false;
            btn_Print.Enabled = false;
            btn_Pause.Enabled = false;
            btn_Stop.Enabled = false;
            btn_application.Enabled = false;
            numericupdow_dstc.Enabled = false;
            numericupdow_spd.Enabled = false;

        }

        private void openFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            float x_float = 0, y_float = 0, e_float = 0;
            int g_int = 0, f_int = 0;
            string path, gcodes;
            int k = 0;
            int count_y = 0;

            openGcode.DefaultExt = "Gcode files";
            openGcode.Filter = "Gcode files (*.gcode*)|*.gcode*";
            openGcode.Multiselect = false;
            openGcode.ShowDialog();

            if (openGcode.FileName.Length > 0)
            {
                foreach (string filename in openGcode.FileNames)
                {
                    this.txtbox_file.Text = filename;
                }
            }

            path = this.txtbox_file.Text;
            try
            {
                gcodes = System.IO.File.ReadAllText(path);
            }
            catch
            {
                return;
            }
            txtbox_temp.Text = gcodes;

            //try
            //{
            //    CP2102.WriteLine(gcodes);

            //}
            //catch
            //{
            //    MessageBox.Show("현재 포트가 연결되어 있지 않습니다.", "에러", MessageBoxButtons.OK, MessageBoxIcon.Error);
            //}


            txtbox_temp.Text = Convert.ToString(txtbox_temp.Lines.Length);  //gcode 줄 수 세고 텍스트 박스에 띄우기
            int leng = Convert.ToInt32(txtbox_temp.Text);
            int max = gcodes.Length;                                       //max에 gcode의 길이를 저장
            progbar_ReTime.Maximum = max;                                  //프로그레스바 최대값을 gcode 줄 수로 설정

            ////--------------------------------------------------------------
            //string[] words = gcodes.Split('\n');

            //foreach (var word in words)
            //{
            //    txtbox_gcode.Text = $"{word}";

            //    progbar_ReTime.Value += 1;
            //}
            ////--------------------------------------------------------------

            for (int i = 0; i < max; i++)
            {
                progbar_ReTime.Value += 1;
                //--------------------------------------------------------------------G
                if (gcodes[i] == 'G')
                {
                    char[] g_char = new char[5];

                    for (int j = i + 1; j < leng; j++)
                    {
                        if (gcodes[j] == ' ' || gcodes[j] == '\r')
                            break;
                        else
                        {
                            g_char[k] = gcodes[j];
                            k++;
                        }
                    }
                    g_int = Int32.Parse(new string(g_char));
                    k = 0;
                }
                //--------------------------------------------------------------------X
                if (gcodes[i] == 'X')
                {
                    char[] x_char = new char[10];

                    for (int j = i + 1; j < leng; j++)
                    {
                        if (gcodes[j] == ' ' || gcodes[j] == '\r')
                            break;
                        else
                        {
                            x_char[k] = gcodes[j];
                            k++;
                        }
                    }
                    x_float = Single.Parse(new string(x_char));
                    k = 0;
                }
                //--------------------------------------------------------------------Y
                if (gcodes[i] == 'Y')
                {
                    char[] y_char = new char[10];

                    for (int j = i + 1; j < leng; j++)
                    {

                        count_y++;

                        if (gcodes[j] == ' ')
                        {
                            Console.WriteLine("gcodes[j] blank");
                        }      

                        if (gcodes[j] == ' ' || gcodes[j] == '\r')
                        { 
                            break;
                        }

                        else
                        {
                            y_char[k] = gcodes[j];
                            k++;
                        }
                    }

                    Console.WriteLine("y_char: " +  new string(y_char));
                    y_float = Single.Parse(new string(y_char));
                    k = 0;
                }
                //--------------------------------------------------------------------E
                if (gcodes[i] == 'E')
                {
                    char[] e_char = new char[10];
                    for (int j = i + 1; j < leng; j++)
                    {
                        if (gcodes[j] == ' ' || gcodes[j] == '\r')
                            break;
                        else
                        {
                            e_char[k] = gcodes[j];
                            k++;
                        }
                    }
                    e_float = Single.Parse(new string(e_char));
                    k = 0;
                }
                //--------------------------------------------------------------------F
                if (gcodes[i] == 'F')
                {
                    char[] f_char = new char[10];

                    for (int j = i + 1; j < leng; j++)
                    {
                        if (gcodes[j] == ' ' || gcodes[j] == '\r')
                            break;
                        else
                        {
                            f_char[k] = gcodes[j];
                            k++;
                        }
                    }
                    f_int = Int32.Parse(new string(f_char));
                    k = 0;
                }
                //--------------------------------------------------------------------
                if (progbar_ReTime.Value == max)
                {
                    progbar_ReTime.Value = 0;
                    MessageBox.Show("출력이 완료되었습니다.", "알림", MessageBoxButtons.OK, MessageBoxIcon.Information);
                }
            }


            //txtbox_gcode.Text = "G = " + Convert.ToString(g_int) + ", X = " + Convert.ToString(x_float) + ", Y = " + Convert.ToString(y_float) + ", E = " + Convert.ToString(e_float) + ", F = " + Convert.ToString(f_int);

            /*
            try
            {
                if (serialPort1.ReadLine() == "OK")
                    MessageBox.Show("Recived OK");
                    //serialPort1.WriteLine(gcodes);
            }
            catch
            {
                MessageBox.Show("현재 포트가 연결되어 있지 않습니다.", "에러", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            */
        }




        private void btn_Print_Click(object sender, EventArgs e)
        {

        }

        private void sendGcode(String gcode)
        {
            CP2102.WriteLine(gcode.ToString());
            lb_xy.Text = gcode;
        }

        private void btn_left_Click(object sender, EventArgs e)
        {
            sendGcode("G0 X300 Y0 F");
            //serialPort1.WriteLine("a");
        }

        private void btn_right_Click(object sender, EventArgs e)
        {
            sendGcode("G0 X-300 Y0 F");
            //serialPort1.WriteLine("d");
        }

        private void btn_down_Click(object sender, EventArgs e)
        {
            sendGcode("G0 X0 Y300 F");
            //serialPort1.WriteLine("s");
        }

        private void btn_up_Click(object sender, EventArgs e)
        {
            sendGcode("G0 X0 Y-300 F");
            //serialPort1.WriteLine("w");
        }

        private void btn_center_Click(object sender, EventArgs e)
        {
            sendGcode("G28 X0 Y0 F");

        }

        private void btn_Pause_Click(object sender, EventArgs e)
        {
            CP2102.WriteLine("Pause Print");
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void btn_Stop_Click(object sender, EventArgs e)
        {
            CP2102.WriteLine("Stop Print");
        }

        private void combox_port_SelectedIndexChanged(object sender, EventArgs e)
        {
            CP2102.Close();

            CP2102.PortName = combox_port.Text;
            //serialPort1.Open();
            try
            {
                CP2102.Open();
            }
            catch
            {
                MessageBox.Show(combox_port.Text + " 포트는 연결되지 않은 포트입니다.", "에러", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            btn_center.Enabled = true;
            btn_right.Enabled = true;
            btn_left.Enabled = true;
            btn_down.Enabled = true;
            btn_up.Enabled = true;
            btn_Print.Enabled = true;
            btn_Pause.Enabled = true;
            btn_Stop.Enabled = true;
            btn_application.Enabled = true;
            numericupdow_dstc.Enabled = true;
            numericupdow_spd.Enabled = true;
        }

        private void btn_application_Click(object sender, EventArgs e)
        {
            CP2102.WriteLine(numericupdow_dstc.Value.ToString() + numericupdow_spd.Value.ToString());
        }

        private void numericupdow_dstc_ValueChanged(object sender, EventArgs e)
        {

        }

        private void numericupdow_spd_ValueChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            CP2102.BaudRate = Convert.ToInt32(combo_baudrate.Text);
        }
    }
}
