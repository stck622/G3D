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
using System.Threading;

namespace Mono
{
    public partial class Form1 : Form
    {
        Control[] gcodeControls;

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            gcodeControls =
            new Control[] {
                btn_center, btn_right, btn_left, btn_down, btn_up, btn_Print
            };

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
        string path;
        private void openFileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string gcodes;

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
        }

        Thread Print_thread;
        bool Printing = false;

        
        private void Print()
        {
            string gcodes;

            try
            {
                gcodes = System.IO.File.ReadAllText(path);
            }
            catch
            {
                return;
            }

            Invoke(new MethodInvoker(delegate()
            {
                txtbox_temp.Text = gcodes;

                txtbox_temp.Text = Convert.ToString(txtbox_temp.Lines.Length);  //gcode 줄 수 세고 텍스트 박스에 띄우기
                int leng = Convert.ToInt32(txtbox_temp.Text);
                int max = gcodes.Length;                                       //max에 gcode의 길이를 저장
                progbar_ReTime.Maximum = max;                                  //프로그레스바 최대값을 gcode 줄 수로 설정
                txtbox_temp.Text = "max : " + max.ToString() + "\n leng : " + leng.ToString();

            }));
            
            try
            {
                foreach (string line in gcodes.Replace('\r','\n').Split('\n'))
                {
                    CP2102.Write(line);
                }
            }
            catch
            {
                MessageBox.Show("현재 포트가 연결되어 있지 않습니다.", "에러", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }


            Invoke(new MethodInvoker(delegate ()
            {
                foreach (Control ctrl in gcodeControls)
                {
                    ctrl.Enabled = true;
                }
            }));
        }

        private void btn_Print_Click(object sender, EventArgs e)
        {
            foreach (Control ctrl in gcodeControls)
            {
                ctrl.Enabled = false;
            }

            Printing = true;
            Print_thread = new Thread(new ThreadStart(Print));
            Print_thread.Start();
        }

        private void sendGcode(String gcode)
        {
            CP2102.WriteLine(gcode.ToString());
            lb_xy.Text = gcode;
        }

        private void btn_left_Click(object sender, EventArgs e)
        {
            try
            {
                CP2102.Write("a");
            }
            catch
            {
                MessageBox.Show("현재 포트가 연결되어 있지 않습니다.", "에러", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
            
        }

        private void btn_right_Click(object sender, EventArgs e)
        {
            try
            {
                CP2102.Write("d");
            }
            catch
            {
                MessageBox.Show("현재 포트가 연결되어 있지 않습니다.", "에러", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
        }

        private void btn_down_Click(object sender, EventArgs e)
        {
            try
            {
                CP2102.Write("s");
            }
            catch
            {
                MessageBox.Show("현재 포트가 연결되어 있지 않습니다.", "에러", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
        }

        private void btn_up_Click(object sender, EventArgs e)
        {
            try
            {
                CP2102.Write("w");
            }
            catch
            {
                MessageBox.Show("현재 포트가 연결되어 있지 않습니다.", "에러", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return;
            }
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
            try
            {
                Print_thread.Abort();
            }
            catch
            {
                if (MessageBox.Show("출력을 정지할 수 없습니다.\n출력을 정지하려면 프로그램을 강제종료 하시겠습니까?", "예기치 못한 오류", MessageBoxButtons.YesNo, MessageBoxIcon.Error) == DialogResult.Yes)
                {
                    this.Close();
                }
                else
                {
                    return;
                }
            }
            
            foreach (Control ctrl in gcodeControls)
            {
                ctrl.Enabled = true;
            }


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

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            try
            {
                Print_thread.Abort();
            }
            catch
            {
                return;
            }
            
        }

        private void helpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("연결할 포트를 선택한 뒤, 보드레이트를 설정하세요. 그 다음 출력할 파일을 상단의 파일 탭의 열기를 클릭해 선택하고, 출력 버튼을 누르면 출력이 됩니다.", "도움말", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void infoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("G3D 프린터를 이용해 주셔서 감사합니다. \r\n오류가 발생하면 스태프에게 알려주시길 바랍니다.", "정보", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }
    }
}
