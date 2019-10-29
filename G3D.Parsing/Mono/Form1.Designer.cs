namespace Mono
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.btn_Print = new System.Windows.Forms.Button();
            this.btn_Pause = new System.Windows.Forms.Button();
            this.btn_Stop = new System.Windows.Forms.Button();
            this.lb_BedTem = new System.Windows.Forms.Label();
            this.lb_ShoBedTem = new System.Windows.Forms.Label();
            this.lb_NozTem = new System.Windows.Forms.Label();
            this.lb_ShoNozTem = new System.Windows.Forms.Label();
            this.progbar_ReTime = new System.Windows.Forms.ProgressBar();
            this.lb_ReTime = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.btn_left = new System.Windows.Forms.Button();
            this.btn_right = new System.Windows.Forms.Button();
            this.btn_up = new System.Windows.Forms.Button();
            this.btn_down = new System.Windows.Forms.Button();
            this.btn_center = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.btn_application = new System.Windows.Forms.Button();
            this.numericupdow_dstc = new System.Windows.Forms.NumericUpDown();
            this.numericupdow_spd = new System.Windows.Forms.NumericUpDown();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.lb_SetNozTem = new System.Windows.Forms.Label();
            this.lb_SetBedTem = new System.Windows.Forms.Label();
            this.numericupdow_bedTem = new System.Windows.Forms.NumericUpDown();
            this.numericupdow_nozTem = new System.Windows.Forms.NumericUpDown();
            this.fIleToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.openFileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip2 = new System.Windows.Forms.MenuStrip();
            this.infoToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tableLayoutPanel4 = new System.Windows.Forms.TableLayoutPanel();
            this.openGcode = new System.Windows.Forms.OpenFileDialog();
            this.txtbox_file = new System.Windows.Forms.TextBox();
            this.CP2102 = new System.IO.Ports.SerialPort(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.lb_xy = new System.Windows.Forms.Label();
            this.tableLayoutPanel6 = new System.Windows.Forms.TableLayoutPanel();
            this.combox_port = new System.Windows.Forms.ComboBox();
            this.lb_baudrate = new System.Windows.Forms.Label();
            this.combo_baudrate = new System.Windows.Forms.ComboBox();
            this.tableLayoutPanel3 = new System.Windows.Forms.TableLayoutPanel();
            this.txtbox_gcode = new System.Windows.Forms.TextBox();
            this.txtbox_temp = new System.Windows.Forms.TextBox();
            this.groupBox1.SuspendLayout();
            this.tableLayoutPanel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericupdow_dstc)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericupdow_spd)).BeginInit();
            this.groupBox2.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericupdow_bedTem)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericupdow_nozTem)).BeginInit();
            this.menuStrip2.SuspendLayout();
            this.tableLayoutPanel4.SuspendLayout();
            this.tableLayoutPanel6.SuspendLayout();
            this.tableLayoutPanel3.SuspendLayout();
            this.SuspendLayout();
            // 
            // btn_Print
            // 
            this.btn_Print.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_Print.BackColor = System.Drawing.SystemColors.Control;
            this.btn_Print.Font = new System.Drawing.Font("D2Coding ligature", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btn_Print.Location = new System.Drawing.Point(3, 3);
            this.btn_Print.Name = "btn_Print";
            this.btn_Print.Size = new System.Drawing.Size(92, 37);
            this.btn_Print.TabIndex = 2;
            this.btn_Print.Text = "출력";
            this.btn_Print.UseVisualStyleBackColor = false;
            this.btn_Print.Click += new System.EventHandler(this.btn_Print_Click);
            // 
            // btn_Pause
            // 
            this.btn_Pause.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_Pause.BackColor = System.Drawing.SystemColors.Control;
            this.btn_Pause.Font = new System.Drawing.Font("D2Coding ligature", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btn_Pause.Location = new System.Drawing.Point(101, 3);
            this.btn_Pause.Name = "btn_Pause";
            this.btn_Pause.Size = new System.Drawing.Size(93, 37);
            this.btn_Pause.TabIndex = 3;
            this.btn_Pause.Text = "일시정지";
            this.btn_Pause.UseVisualStyleBackColor = false;
            this.btn_Pause.Click += new System.EventHandler(this.btn_Pause_Click);
            // 
            // btn_Stop
            // 
            this.btn_Stop.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_Stop.BackColor = System.Drawing.SystemColors.Control;
            this.btn_Stop.Font = new System.Drawing.Font("D2Coding ligature", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btn_Stop.Location = new System.Drawing.Point(200, 3);
            this.btn_Stop.Name = "btn_Stop";
            this.btn_Stop.Size = new System.Drawing.Size(94, 37);
            this.btn_Stop.TabIndex = 4;
            this.btn_Stop.Text = "정지";
            this.btn_Stop.UseVisualStyleBackColor = false;
            this.btn_Stop.Click += new System.EventHandler(this.btn_Stop_Click);
            // 
            // lb_BedTem
            // 
            this.lb_BedTem.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.lb_BedTem.AutoSize = true;
            this.lb_BedTem.ForeColor = System.Drawing.Color.LightGray;
            this.lb_BedTem.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.lb_BedTem.Location = new System.Drawing.Point(11, 19);
            this.lb_BedTem.Name = "lb_BedTem";
            this.lb_BedTem.Size = new System.Drawing.Size(93, 12);
            this.lb_BedTem.TabIndex = 5;
            this.lb_BedTem.Text = "현재 배드 온도 :";
            this.lb_BedTem.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lb_ShoBedTem
            // 
            this.lb_ShoBedTem.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.lb_ShoBedTem.AutoSize = true;
            this.lb_ShoBedTem.ForeColor = System.Drawing.Color.LightGray;
            this.lb_ShoBedTem.Location = new System.Drawing.Point(110, 19);
            this.lb_ShoBedTem.Name = "lb_ShoBedTem";
            this.lb_ShoBedTem.Size = new System.Drawing.Size(31, 12);
            this.lb_ShoBedTem.TabIndex = 6;
            this.lb_ShoBedTem.Text = "87ºC";
            this.lb_ShoBedTem.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lb_NozTem
            // 
            this.lb_NozTem.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.lb_NozTem.AutoSize = true;
            this.lb_NozTem.ForeColor = System.Drawing.Color.LightGray;
            this.lb_NozTem.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.lb_NozTem.Location = new System.Drawing.Point(11, 69);
            this.lb_NozTem.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
            this.lb_NozTem.Name = "lb_NozTem";
            this.lb_NozTem.Size = new System.Drawing.Size(93, 12);
            this.lb_NozTem.TabIndex = 7;
            this.lb_NozTem.Text = "현재 노즐 온도 :";
            this.lb_NozTem.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lb_ShoNozTem
            // 
            this.lb_ShoNozTem.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.lb_ShoNozTem.AutoSize = true;
            this.lb_ShoNozTem.ForeColor = System.Drawing.Color.LightGray;
            this.lb_ShoNozTem.Location = new System.Drawing.Point(110, 69);
            this.lb_ShoNozTem.Margin = new System.Windows.Forms.Padding(3, 5, 3, 5);
            this.lb_ShoNozTem.Name = "lb_ShoNozTem";
            this.lb_ShoNozTem.Size = new System.Drawing.Size(37, 12);
            this.lb_ShoNozTem.TabIndex = 8;
            this.lb_ShoNozTem.Text = "178ºC";
            this.lb_ShoNozTem.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // progbar_ReTime
            // 
            this.progbar_ReTime.Location = new System.Drawing.Point(3, 27);
            this.progbar_ReTime.Name = "progbar_ReTime";
            this.progbar_ReTime.Size = new System.Drawing.Size(291, 19);
            this.progbar_ReTime.TabIndex = 9;
            // 
            // lb_ReTime
            // 
            this.lb_ReTime.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.lb_ReTime.AutoSize = true;
            this.lb_ReTime.Font = new System.Drawing.Font("D2Coding ligature", 11F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.lb_ReTime.ForeColor = System.Drawing.Color.Silver;
            this.lb_ReTime.Location = new System.Drawing.Point(3, 3);
            this.lb_ReTime.Margin = new System.Windows.Forms.Padding(3);
            this.lb_ReTime.Name = "lb_ReTime";
            this.lb_ReTime.Size = new System.Drawing.Size(50, 18);
            this.lb_ReTime.TabIndex = 10;
            this.lb_ReTime.Text = "진행도";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.tableLayoutPanel1);
            this.groupBox1.ForeColor = System.Drawing.Color.LightGray;
            this.groupBox1.Location = new System.Drawing.Point(12, 131);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(456, 260);
            this.groupBox1.TabIndex = 11;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "노즐 움직임";
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.ColumnCount = 5;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel1.Controls.Add(this.btn_left, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.btn_right, 2, 1);
            this.tableLayoutPanel1.Controls.Add(this.btn_up, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.btn_down, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this.btn_center, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.label3, 3, 0);
            this.tableLayoutPanel1.Controls.Add(this.label4, 3, 1);
            this.tableLayoutPanel1.Controls.Add(this.btn_application, 4, 2);
            this.tableLayoutPanel1.Controls.Add(this.numericupdow_dstc, 4, 0);
            this.tableLayoutPanel1.Controls.Add(this.numericupdow_spd, 4, 1);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(5, 20);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 3;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(444, 234);
            this.tableLayoutPanel1.TabIndex = 13;
            // 
            // btn_left
            // 
            this.btn_left.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btn_left.BackColor = System.Drawing.SystemColors.Control;
            this.btn_left.Font = new System.Drawing.Font("굴림", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btn_left.ForeColor = System.Drawing.Color.Black;
            this.btn_left.Location = new System.Drawing.Point(3, 81);
            this.btn_left.Name = "btn_left";
            this.btn_left.Size = new System.Drawing.Size(72, 72);
            this.btn_left.TabIndex = 2;
            this.btn_left.Text = "←";
            this.btn_left.UseVisualStyleBackColor = false;
            this.btn_left.Click += new System.EventHandler(this.btn_left_Click);
            // 
            // btn_right
            // 
            this.btn_right.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btn_right.BackColor = System.Drawing.SystemColors.Control;
            this.btn_right.Font = new System.Drawing.Font("굴림", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btn_right.ForeColor = System.Drawing.Color.Black;
            this.btn_right.Location = new System.Drawing.Point(159, 81);
            this.btn_right.Name = "btn_right";
            this.btn_right.Size = new System.Drawing.Size(72, 72);
            this.btn_right.TabIndex = 3;
            this.btn_right.Text = "→";
            this.btn_right.UseVisualStyleBackColor = false;
            this.btn_right.Click += new System.EventHandler(this.btn_right_Click);
            // 
            // btn_up
            // 
            this.btn_up.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btn_up.BackColor = System.Drawing.SystemColors.Control;
            this.btn_up.Font = new System.Drawing.Font("굴림", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btn_up.ForeColor = System.Drawing.Color.Black;
            this.btn_up.Location = new System.Drawing.Point(81, 3);
            this.btn_up.Name = "btn_up";
            this.btn_up.Size = new System.Drawing.Size(72, 72);
            this.btn_up.TabIndex = 0;
            this.btn_up.Text = "↑";
            this.btn_up.UseVisualStyleBackColor = false;
            this.btn_up.Click += new System.EventHandler(this.btn_up_Click);
            // 
            // btn_down
            // 
            this.btn_down.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btn_down.BackColor = System.Drawing.SystemColors.Control;
            this.btn_down.Font = new System.Drawing.Font("굴림", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.btn_down.ForeColor = System.Drawing.Color.Black;
            this.btn_down.Location = new System.Drawing.Point(81, 159);
            this.btn_down.Name = "btn_down";
            this.btn_down.Size = new System.Drawing.Size(72, 72);
            this.btn_down.TabIndex = 1;
            this.btn_down.Text = "↓";
            this.btn_down.UseVisualStyleBackColor = false;
            this.btn_down.Click += new System.EventHandler(this.btn_down_Click);
            // 
            // btn_center
            // 
            this.btn_center.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btn_center.BackColor = System.Drawing.SystemColors.Control;
            this.btn_center.Font = new System.Drawing.Font("맑은 고딕", 15.75F, System.Drawing.FontStyle.Bold);
            this.btn_center.ForeColor = System.Drawing.Color.Black;
            this.btn_center.Location = new System.Drawing.Point(81, 81);
            this.btn_center.Name = "btn_center";
            this.btn_center.Size = new System.Drawing.Size(72, 72);
            this.btn_center.TabIndex = 4;
            this.btn_center.Text = "H";
            this.btn_center.UseVisualStyleBackColor = false;
            this.btn_center.Click += new System.EventHandler(this.btn_center_Click);
            // 
            // label3
            // 
            this.label3.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.label3.AutoSize = true;
            this.label3.ForeColor = System.Drawing.Color.LightGray;
            this.label3.Location = new System.Drawing.Point(237, 33);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(117, 12);
            this.label3.TabIndex = 22;
            this.label3.Text = "움직이는 거리 설정 :";
            // 
            // label4
            // 
            this.label4.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.label4.AutoSize = true;
            this.label4.ForeColor = System.Drawing.Color.LightGray;
            this.label4.Location = new System.Drawing.Point(261, 111);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(93, 12);
            this.label4.TabIndex = 25;
            this.label4.Text = "모터 속도 설정 :";
            // 
            // btn_application
            // 
            this.btn_application.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.btn_application.BackColor = System.Drawing.SystemColors.Control;
            this.btn_application.ForeColor = System.Drawing.Color.Black;
            this.btn_application.Location = new System.Drawing.Point(363, 183);
            this.btn_application.Name = "btn_application";
            this.btn_application.Size = new System.Drawing.Size(75, 23);
            this.btn_application.TabIndex = 26;
            this.btn_application.Text = "적용";
            this.btn_application.UseVisualStyleBackColor = false;
            this.btn_application.Click += new System.EventHandler(this.btn_application_Click);
            // 
            // numericupdow_dstc
            // 
            this.numericupdow_dstc.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.numericupdow_dstc.Font = new System.Drawing.Font("맑은 고딕", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.numericupdow_dstc.Location = new System.Drawing.Point(360, 27);
            this.numericupdow_dstc.Maximum = new decimal(new int[] {
            200,
            0,
            0,
            0});
            this.numericupdow_dstc.Name = "numericupdow_dstc";
            this.numericupdow_dstc.Size = new System.Drawing.Size(82, 23);
            this.numericupdow_dstc.TabIndex = 27;
            this.numericupdow_dstc.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.numericupdow_dstc.ValueChanged += new System.EventHandler(this.numericupdow_dstc_ValueChanged);
            // 
            // numericupdow_spd
            // 
            this.numericupdow_spd.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.numericupdow_spd.Font = new System.Drawing.Font("맑은 고딕", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.numericupdow_spd.Location = new System.Drawing.Point(360, 105);
            this.numericupdow_spd.Maximum = new decimal(new int[] {
            200,
            0,
            0,
            0});
            this.numericupdow_spd.Name = "numericupdow_spd";
            this.numericupdow_spd.Size = new System.Drawing.Size(82, 23);
            this.numericupdow_spd.TabIndex = 28;
            this.numericupdow_spd.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.numericupdow_spd.ValueChanged += new System.EventHandler(this.numericupdow_spd_ValueChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.tableLayoutPanel2);
            this.groupBox2.ForeColor = System.Drawing.Color.LightGray;
            this.groupBox2.Location = new System.Drawing.Point(474, 171);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(196, 220);
            this.groupBox2.TabIndex = 12;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "온도";
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.tableLayoutPanel2.ColumnCount = 2;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 59.11111F));
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 40.88889F));
            this.tableLayoutPanel2.Controls.Add(this.lb_SetNozTem, 0, 3);
            this.tableLayoutPanel2.Controls.Add(this.lb_ShoNozTem, 1, 1);
            this.tableLayoutPanel2.Controls.Add(this.lb_BedTem, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.lb_NozTem, 0, 1);
            this.tableLayoutPanel2.Controls.Add(this.lb_SetBedTem, 0, 2);
            this.tableLayoutPanel2.Controls.Add(this.lb_ShoBedTem, 1, 0);
            this.tableLayoutPanel2.Controls.Add(this.numericupdow_bedTem, 1, 2);
            this.tableLayoutPanel2.Controls.Add(this.numericupdow_nozTem, 1, 3);
            this.tableLayoutPanel2.Location = new System.Drawing.Point(8, 14);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 4;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(182, 200);
            this.tableLayoutPanel2.TabIndex = 13;
            // 
            // lb_SetNozTem
            // 
            this.lb_SetNozTem.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.lb_SetNozTem.AutoSize = true;
            this.lb_SetNozTem.ForeColor = System.Drawing.Color.LightGray;
            this.lb_SetNozTem.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.lb_SetNozTem.Location = new System.Drawing.Point(19, 169);
            this.lb_SetNozTem.Name = "lb_SetNozTem";
            this.lb_SetNozTem.Size = new System.Drawing.Size(85, 12);
            this.lb_SetNozTem.TabIndex = 10;
            this.lb_SetNozTem.Text = "노즐 온도 설정";
            this.lb_SetNozTem.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lb_SetBedTem
            // 
            this.lb_SetBedTem.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.lb_SetBedTem.AutoSize = true;
            this.lb_SetBedTem.ForeColor = System.Drawing.Color.LightGray;
            this.lb_SetBedTem.ImageAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.lb_SetBedTem.Location = new System.Drawing.Point(19, 119);
            this.lb_SetBedTem.Name = "lb_SetBedTem";
            this.lb_SetBedTem.Size = new System.Drawing.Size(85, 12);
            this.lb_SetBedTem.TabIndex = 9;
            this.lb_SetBedTem.Text = "배드 온도 설정";
            this.lb_SetBedTem.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // numericupdow_bedTem
            // 
            this.numericupdow_bedTem.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.numericupdow_bedTem.Location = new System.Drawing.Point(110, 114);
            this.numericupdow_bedTem.Maximum = new decimal(new int[] {
            200,
            0,
            0,
            0});
            this.numericupdow_bedTem.Name = "numericupdow_bedTem";
            this.numericupdow_bedTem.Size = new System.Drawing.Size(65, 21);
            this.numericupdow_bedTem.TabIndex = 11;
            this.numericupdow_bedTem.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // numericupdow_nozTem
            // 
            this.numericupdow_nozTem.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.numericupdow_nozTem.Location = new System.Drawing.Point(110, 164);
            this.numericupdow_nozTem.Maximum = new decimal(new int[] {
            200,
            0,
            0,
            0});
            this.numericupdow_nozTem.Name = "numericupdow_nozTem";
            this.numericupdow_nozTem.Size = new System.Drawing.Size(65, 21);
            this.numericupdow_nozTem.TabIndex = 12;
            this.numericupdow_nozTem.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // fIleToolStripMenuItem
            // 
            this.fIleToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openFileToolStripMenuItem,
            this.exitToolStripMenuItem});
            this.fIleToolStripMenuItem.Name = "fIleToolStripMenuItem";
            this.fIleToolStripMenuItem.Size = new System.Drawing.Size(43, 20);
            this.fIleToolStripMenuItem.Text = "파일";
            // 
            // openFileToolStripMenuItem
            // 
            this.openFileToolStripMenuItem.Name = "openFileToolStripMenuItem";
            this.openFileToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.openFileToolStripMenuItem.Text = "열기";
            this.openFileToolStripMenuItem.Click += new System.EventHandler(this.openFileToolStripMenuItem_Click);
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.exitToolStripMenuItem.Text = "끝내기";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(55, 20);
            this.helpToolStripMenuItem.Text = "도움말";
            // 
            // menuStrip2
            // 
            this.menuStrip2.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fIleToolStripMenuItem,
            this.infoToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.menuStrip2.Location = new System.Drawing.Point(0, 0);
            this.menuStrip2.Name = "menuStrip2";
            this.menuStrip2.Size = new System.Drawing.Size(940, 24);
            this.menuStrip2.TabIndex = 1;
            this.menuStrip2.Text = "menuStrip2";
            // 
            // infoToolStripMenuItem
            // 
            this.infoToolStripMenuItem.Name = "infoToolStripMenuItem";
            this.infoToolStripMenuItem.Size = new System.Drawing.Size(43, 20);
            this.infoToolStripMenuItem.Text = "정보";
            // 
            // tableLayoutPanel4
            // 
            this.tableLayoutPanel4.ColumnCount = 1;
            this.tableLayoutPanel4.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel4.Controls.Add(this.lb_ReTime, 0, 0);
            this.tableLayoutPanel4.Controls.Add(this.progbar_ReTime, 0, 1);
            this.tableLayoutPanel4.Location = new System.Drawing.Point(402, 27);
            this.tableLayoutPanel4.Name = "tableLayoutPanel4";
            this.tableLayoutPanel4.RowCount = 2;
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel4.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel4.Size = new System.Drawing.Size(297, 49);
            this.tableLayoutPanel4.TabIndex = 14;
            // 
            // txtbox_file
            // 
            this.txtbox_file.Location = new System.Drawing.Point(12, 27);
            this.txtbox_file.Name = "txtbox_file";
            this.txtbox_file.ReadOnly = true;
            this.txtbox_file.Size = new System.Drawing.Size(282, 21);
            this.txtbox_file.TabIndex = 15;
            // 
            // label1
            // 
            this.label1.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.label1.AutoSize = true;
            this.label1.ForeColor = System.Drawing.Color.LightGray;
            this.label1.Location = new System.Drawing.Point(4, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 12);
            this.label1.TabIndex = 16;
            this.label1.Text = "연결된 포트 :";
            // 
            // label2
            // 
            this.label2.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.label2.AutoSize = true;
            this.label2.ForeColor = System.Drawing.Color.LightGray;
            this.label2.Location = new System.Drawing.Point(3, 47);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(78, 12);
            this.label2.TabIndex = 18;
            this.label2.Text = "현재 Gcode :";
            // 
            // lb_xy
            // 
            this.lb_xy.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.lb_xy.AutoSize = true;
            this.lb_xy.ForeColor = System.Drawing.Color.LightGray;
            this.lb_xy.Location = new System.Drawing.Point(87, 47);
            this.lb_xy.Name = "lb_xy";
            this.lb_xy.Size = new System.Drawing.Size(91, 12);
            this.lb_xy.TabIndex = 19;
            this.lb_xy.Text = "G0 X0 Y0 E0 F0";
            // 
            // tableLayoutPanel6
            // 
            this.tableLayoutPanel6.ColumnCount = 3;
            this.tableLayoutPanel6.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel6.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33334F));
            this.tableLayoutPanel6.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33334F));
            this.tableLayoutPanel6.Controls.Add(this.btn_Stop, 2, 0);
            this.tableLayoutPanel6.Controls.Add(this.btn_Print, 0, 0);
            this.tableLayoutPanel6.Controls.Add(this.btn_Pause, 1, 0);
            this.tableLayoutPanel6.Location = new System.Drawing.Point(402, 82);
            this.tableLayoutPanel6.Name = "tableLayoutPanel6";
            this.tableLayoutPanel6.RowCount = 1;
            this.tableLayoutPanel6.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel6.Size = new System.Drawing.Size(297, 43);
            this.tableLayoutPanel6.TabIndex = 20;
            // 
            // combox_port
            // 
            this.combox_port.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.combox_port.FormattingEnabled = true;
            this.combox_port.Items.AddRange(new object[] {
            "COM1",
            "COM2",
            "COM3",
            "COM4",
            "COM5",
            "COM6",
            "COM7",
            "COM8",
            "COM9",
            "/dev/ttyUSB0",
            "/dev/ttyAMA0",
            "/dev/ttyUSB1"});
            this.combox_port.Location = new System.Drawing.Point(87, 7);
            this.combox_port.Name = "combox_port";
            this.combox_port.Size = new System.Drawing.Size(76, 20);
            this.combox_port.TabIndex = 21;
            this.combox_port.Text = "COM5";
            this.combox_port.SelectedIndexChanged += new System.EventHandler(this.combox_port_SelectedIndexChanged);
            // 
            // lb_baudrate
            // 
            this.lb_baudrate.Anchor = System.Windows.Forms.AnchorStyles.Right;
            this.lb_baudrate.AutoSize = true;
            this.lb_baudrate.ForeColor = System.Drawing.Color.LightGray;
            this.lb_baudrate.Location = new System.Drawing.Point(184, 11);
            this.lb_baudrate.Name = "lb_baudrate";
            this.lb_baudrate.Size = new System.Drawing.Size(73, 12);
            this.lb_baudrate.TabIndex = 22;
            this.lb_baudrate.Text = "보드레이트 :";
            // 
            // combo_baudrate
            // 
            this.combo_baudrate.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.combo_baudrate.FormattingEnabled = true;
            this.combo_baudrate.Items.AddRange(new object[] {
            "300",
            "1200",
            "2400",
            "4800",
            "9600",
            "19200",
            "38400",
            "74880",
            "115200",
            "230400",
            "250000",
            "500000",
            "1000000",
            "2000000"});
            this.combo_baudrate.Location = new System.Drawing.Point(263, 7);
            this.combo_baudrate.Name = "combo_baudrate";
            this.combo_baudrate.Size = new System.Drawing.Size(115, 20);
            this.combo_baudrate.TabIndex = 23;
            this.combo_baudrate.Text = "9600";
            this.combo_baudrate.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // tableLayoutPanel3
            // 
            this.tableLayoutPanel3.ColumnCount = 4;
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel3.Controls.Add(this.label1, 0, 0);
            this.tableLayoutPanel3.Controls.Add(this.combo_baudrate, 3, 0);
            this.tableLayoutPanel3.Controls.Add(this.combox_port, 1, 0);
            this.tableLayoutPanel3.Controls.Add(this.lb_baudrate, 2, 0);
            this.tableLayoutPanel3.Controls.Add(this.label2, 0, 1);
            this.tableLayoutPanel3.Controls.Add(this.lb_xy, 1, 1);
            this.tableLayoutPanel3.Location = new System.Drawing.Point(12, 54);
            this.tableLayoutPanel3.Name = "tableLayoutPanel3";
            this.tableLayoutPanel3.RowCount = 2;
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel3.Size = new System.Drawing.Size(385, 71);
            this.tableLayoutPanel3.TabIndex = 24;
            // 
            // txtbox_gcode
            // 
            this.txtbox_gcode.Location = new System.Drawing.Point(707, 31);
            this.txtbox_gcode.Multiline = true;
            this.txtbox_gcode.Name = "txtbox_gcode";
            this.txtbox_gcode.ReadOnly = true;
            this.txtbox_gcode.Size = new System.Drawing.Size(221, 189);
            this.txtbox_gcode.TabIndex = 25;
            // 
            // txtbox_temp
            // 
            this.txtbox_temp.Location = new System.Drawing.Point(707, 254);
            this.txtbox_temp.Multiline = true;
            this.txtbox_temp.Name = "txtbox_temp";
            this.txtbox_temp.Size = new System.Drawing.Size(221, 191);
            this.txtbox_temp.TabIndex = 26;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.DarkGreen;
            this.ClientSize = new System.Drawing.Size(940, 452);
            this.Controls.Add(this.txtbox_temp);
            this.Controls.Add(this.txtbox_gcode);
            this.Controls.Add(this.tableLayoutPanel3);
            this.Controls.Add(this.tableLayoutPanel6);
            this.Controls.Add(this.txtbox_file);
            this.Controls.Add(this.tableLayoutPanel4);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.menuStrip2);
            this.HelpButton = true;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = " 삼디 출력기";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericupdow_dstc)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericupdow_spd)).EndInit();
            this.groupBox2.ResumeLayout(false);
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.numericupdow_bedTem)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericupdow_nozTem)).EndInit();
            this.menuStrip2.ResumeLayout(false);
            this.menuStrip2.PerformLayout();
            this.tableLayoutPanel4.ResumeLayout(false);
            this.tableLayoutPanel4.PerformLayout();
            this.tableLayoutPanel6.ResumeLayout(false);
            this.tableLayoutPanel3.ResumeLayout(false);
            this.tableLayoutPanel3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button btn_Print;
        private System.Windows.Forms.Button btn_Pause;
        private System.Windows.Forms.Button btn_Stop;
        private System.Windows.Forms.Label lb_BedTem;
        private System.Windows.Forms.Label lb_ShoBedTem;
        private System.Windows.Forms.Label lb_NozTem;
        private System.Windows.Forms.Label lb_ShoNozTem;
        private System.Windows.Forms.ProgressBar progbar_ReTime;
        private System.Windows.Forms.Label lb_ReTime;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button btn_right;
        private System.Windows.Forms.Button btn_left;
        private System.Windows.Forms.Button btn_down;
        private System.Windows.Forms.Button btn_up;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Button btn_center;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.Label lb_SetNozTem;
        private System.Windows.Forms.Label lb_SetBedTem;
        private System.Windows.Forms.ToolStripMenuItem fIleToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openFileToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.MenuStrip menuStrip2;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel4;
        private System.Windows.Forms.ToolStripMenuItem infoToolStripMenuItem;
        private System.Windows.Forms.OpenFileDialog openGcode;
        private System.Windows.Forms.TextBox txtbox_file;
        private System.IO.Ports.SerialPort CP2102;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label lb_xy;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel6;
        private System.Windows.Forms.ComboBox combox_port;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button btn_application;
        private System.Windows.Forms.NumericUpDown numericupdow_dstc;
        private System.Windows.Forms.NumericUpDown numericupdow_spd;
        private System.Windows.Forms.Label lb_baudrate;
        private System.Windows.Forms.ComboBox combo_baudrate;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel3;
        private System.Windows.Forms.NumericUpDown numericupdow_bedTem;
        private System.Windows.Forms.NumericUpDown numericupdow_nozTem;
        private System.Windows.Forms.TextBox txtbox_gcode;
        private System.Windows.Forms.TextBox txtbox_temp;
    }
}

