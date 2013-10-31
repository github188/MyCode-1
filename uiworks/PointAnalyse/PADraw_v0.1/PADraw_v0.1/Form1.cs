using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace PADraw_v0._1
{
    public partial class Form1 : Form
    {
        public double dis(double x, double y, double xx, double yy)
        {
            return Math.Sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
        }
        double[] e = new double[100];
        double[] d = new double[100];
        bool[] used = new bool[100];
        int[] pos = new int[100];
        int[] pos1 = new int[100];
        double maxlen;

        private void dfs(int o, int num, double len, int p)
        {
            if (o == num)
            {
                if (len < maxlen)
                {
                    maxlen = len;
                    for (int i = 0; i < num; i++) pos1[i] = pos[i]; 
                }
                return;
            }
            for (int i=0;i<p;i++)
                if (!used[i])
                {
                    pos[o] = i;
                    used[i] = true;
                    double dis = Math.Sqrt((d[o * 2] - e[i * 2]) * (d[o * 2] - e[i * 2]) + (d[o * 2] - e[i * 2] + 1) * (d[o * 2] - e[i * 2]+1));
                    dfs(o + 1, num, len + dis, p);
                    used[i] = false;
                }
            pos[o] = -1;
            dfs(o + 1, num, len + 1e7, p);

        }

        public Form1()
        {
            InitializeComponent();
            Bitmap bmp = new Bitmap(900, 600);
            Graphics g = Graphics.FromImage(bmp);
            System.Drawing.SolidBrush myBrush = new System.Drawing.SolidBrush(System.Drawing.Color.White);
            g.FillRectangle(myBrush, 0, 0, 900, 600);
            int p = 0;
            StreamReader sr = new StreamReader("两点曲线1中out.txt");
            while (!sr.EndOfStream)
            {
                string s=sr.ReadLine();
                string[] ss = s.Split(new char[] { ' ' });
                int num = Convert.ToInt32(ss[0]);
                for (int i = 0; i < num * 2; i++) e[i] = Convert.ToDouble(ss[i + 1]);
                maxlen = 1e9;
                for (int i = 0; i < num; i++) used[i] = false;
                dfs(0, p, 0, num);
                
                for (int i = 0; i < p; i ++ )
                {
                    if (pos1[i]>=0)
                    {
                        Pen pen = new Pen(Color.Black, 2);
                        //if (Math.Abs(d[i] - e[i]) > 5) { e[i] = d[i] + 5 * (e[i] - d[i]) / Math.Abs(d[i] - e[i]); }
                        //if (Math.Abs(d[i + 1] - e[i + 1]) > 5) { e[i + 1] = d[i + 1] + 5 * (e[i + 1] - d[i + 1]) / Math.Abs(d[i + 1] - e[i + 1]); }
                        g.DrawLine(pen, Convert.ToInt32(d[i*2]), Convert.ToInt32(d[i*2 + 1]), Convert.ToInt32(e[pos1[i]*2]), Convert.ToInt32(e[pos1[i]*2+1]));
                    }
                }
                p = num;
                for (int i = 0; i < p * 2; i++) d[i] = e[i];
            }

            bmp.Save("两点曲线1中out.jpg", System.Drawing.Imaging.ImageFormat.Jpeg);
            g.Dispose();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
