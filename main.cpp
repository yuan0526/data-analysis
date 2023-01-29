#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double summation(double a[], int k) //總和 //變數分別為數據、數據數量
{
    long double sum = 0;

    for (int i = 0; i < k; i++)
    {
        sum += a[i];
    }

    return sum;
}

double summation2(double a[], int k) //平方和 //變數分別為數據、數據數量
{
    long double sum2 = 0;

    for (int i = 0; i < k; i++)
    {
        sum2 += pow(a[i], 2);
    }

    return sum2;
}

void arrange(double a[], int k) //一維數據由小排到大
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (a[i] < a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}

void arrange2(double a[], double b[], int k) //二維數據的由小排到大
{
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (a[i] < a[j])
            {
                swap(a[i], a[j]);
                swap(b[i], b[j]);
            }
        }
    }
}

int main()
{
    /*輸入*/
    double x[10000], y[10000], delta; //變數宣告：數據，數據變量的判別數

    while (true)
    {
        cout << "數據分析形式,一維請輸入1,二維請輸入2\n";
        cin >> delta;
        if (delta == 1 || delta == 2)
        {
            break;
        }
        else
        {
            cout << "錯誤,請重新輸入\n";
        }
    } //以上在確認輸入一維數據或二維數據

    int i, k;      //變數宣告：迴圈變數
    int deltas, n; //變數宣告：資料確認的判別數、數據數量

    while (true)
    {

        if (delta == 1)
        {
            cout << "輸入數據數量: ";
            cin >> n;
            cout << "請輸入數據\n";
            for (i = 0; i < n; i++)
            {
                cout << "第" << i + 1 << "個數據";
                cin >> x[i];
            }

            cout << "確認資料: \n";
            for (k = 0; k < n; k++)
            {
                cout << x[k] << " ";
            }
            cout << "\n無誤請輸入0;有誤請輸入1,並重新輸入: ";
            cin >> deltas;
        } //一維數據的數據輸入
        else if (delta == 2)
        {
            cout << "輸入數據組數: ";
            cin >> n;
            cout << "請將兩變量交錯輸入\n";
            for (int i = 0; i < n; i++)
            {
                cout << "第" << i + 1 << "組數據\n";
                cout << "x:";
                cin >> x[i];
                cout << "y:";
                cin >> y[i];
            }
            
            cout << "確認資料: \n";
            for (k = 0; k < n; k++)
            {
                cout << "(" << x[k] << "," << y[k] << ")";
            }
            cout << "\n無誤請輸入0;有誤請輸入1,並重新輸入: ";
            cin >> deltas;
        } //二維數據的數據輸入

        if(deltas == 1)
        {
            while (true)
            {
                if (deltas == 0)
                {
                    break;
                }
                if (deltas == 1)
                {
                    cout << "數據分析形式,一維請輸入1,二維請輸入2\n";
                    while (cin >> delta)
                    {
                        if (delta == 1 || delta == 2)
                        {
                            break;
                        }
                        else
                        {
                            cout << "錯誤,請重新輸入\n";
                            cout << "數據分析形式,一維請輸入1,二維請輸入2\n";
                        }
                    }
                    break;
                }
                else
                {
                    cout << "錯誤,請重新輸入,資料正確請輸入0,資料錯誤請輸入1\n";
                    cin >> deltas;
                }
            }
        } //資料確認：錯誤，重新輸入

        if (deltas == 0)
        {
            break;
        } //資料確認：正確，脫離迴圈
    }

    /*平均、變異數、標準差*/
    double ave[2] = {0, 0}, var[2] = {0, 0}, stdev[2] = {0, 0}, stdevs[2] = {0, 0}; //宣告變數：資料平均、資料變異數、資料標準差

    if (delta == 1) //一維數據
    {
        ave[0] = summation(x, n) / n;                                                          //平均
        var[0] = summation2(x, n) / n - pow(ave[0], 2);                                        //變異數
        stdev[0] = sqrt(var[0]);                                                               //標準差
        stdevs[0] = sqrt(summation2(x, n) / (n - 1) - ((double)n / (n - 1)) * pow(ave[0], 2)); //樣本標準差
    }
    else if (delta == 2) //二維數據
    {
        ave[0] = summation(x, n) / n;
        ave[1] = summation(y, n) / n; //平均
        var[0] = summation2(x, n) / n - pow(ave[0], 2);
        var[1] = summation2(y, n) / n - pow(ave[1], 2); //變異數
        stdev[0] = sqrt(var[0]);
        stdev[1] = sqrt(var[1]); //標準差
        stdevs[0] = sqrt(summation2(x, n) / (n - 1) - (n / (n - 1)) * pow(ave[0], 2));
        stdevs[1] = sqrt(summation2(y, n) / (n - 1) - (n / (n - 1)) * pow(ave[1], 2)); //樣本標準差
    }

    /*由小排到大*/
    double xp[10000], yp[10000];
    for (i = 0; i < n; i++)
    {
        xp[i] = x[i];
        yp[i] = y[i];
    } //將原數據複製一份，以複製版做操作

    if (delta == 1)
    {
        arrange(xp, n);
    }

    /*百分位數、四分位數*/
    int t;
    double P[100], Q[4]; //變數宣告：百分位數、四分位數
    P[0] = 0;
    Q[0] = 0;
    for (i = 1; i <= 99; i++) //百分位數
    {
        t = n * i / 100;
        if ((n * i) % 100 == 0) //當數據數量乘百分比是整數時
        {
            t -= 1;
            P[i] = (xp[t] + xp[t + 1]) / 2;
        }
        else //當數據數量乘百分比非整數時
        {
            P[i] = xp[t];
        }
    }
    for (k = 1; k <= 3; k++) //四分位數
    {
        Q[k] = P[25 * k];
    }

    /*全距、四分位距*/
    double R, QD;
    R = xp[n - 1] - xp[0];
    QD = Q[3] - Q[1];

    /*資料的標準化*/
    double xst[10000], yst[10000];
    for (i = 0; i < n; i++)
    {
        if (delta == 1)
        {
            xst[i] = (x[i] - ave[0]) / stdev[0];
        }
        else if (delta == 2)
        {
            xst[i] = (x[i] - ave[0]) / stdev[0];
            yst[i] = (y[i] - ave[1]) / stdev[1];
        }
    }

    /*相關係數*/
    double r, sumOfxy = 0;

    if (delta == 2)
    {
        for (int i = 0; i < n; i++)
        {
            sumOfxy += x[i] * y[i]; //兩變量相乘
        }

        r = (sumOfxy - n * ave[0] * ave[1]) / (n * stdev[0] * stdev[1]);
    }

    /*輸出*/
    string output; //變數宣告：輸出的資料
    char target;   //分辨變量
    int flag = 0;  //旗標變數

    if (delta == 1)
    {
        cout << "\n數據處理:\n總和\t\tsum\n平均數\t\taverage\n標準差\t\tstdevp\n樣本標準差\tstdevs\n變異數\t\tvar\n全距\t\tR\n四分位距\tQD\n百分位數\tP\n四分位數\tQ\n"
             << "\n資料處理:\n由小排到大\tarrange\n標準化資料\tstandard\n";
        cout << "\n請輸入代號取得資訊\n"; //說明文字
        cin >> output;
    }
    if (delta == 2)
    {
        cout << "\n數據處理:\n總和\t\tsum\n平均數\t\taverage\n標準差\t\tstdevp\n樣本標準差\tstdevs\n變異數\t\tvar\n"
             << "\n資料處理:\n由小排到大\tarrange\n標準化資料\tstandard\n"
             << "\n二維數據:\n相關係數\tr\n回歸直線\tfitline\n";
        cout << "\n請輸入代號取得資訊\n";
        cin >> output;
    }

    while (true)
    {
        flag = 0;
        if (delta == 1)
        {
            cout << "\n";

            if (output == "sum") //總和
            {
                cout << summation(x, n);
            }
            else if (output == "average") //平均
            {
                cout << ave[0];
            }
            else if (output == "stdevp") //標準差
            {
                cout << stdev[0];
            }
            else if (output == "stdevs") //樣本標準差
            {
                cout << stdevs[0];
            }
            else if (output == "var") //變異數
            {
                cout << var[0];
            }
            else if (output == "R") //全距
            {
                cout << R;
            }
            else if (output == "QD") //四分位距
            {
                cout << QD;
            }
            else if (output == "P") //百分位數
            {
                cout << "第？百分位數:";
                while (true)
                {
                    cin >> k;
                    if (k >= 100 || k <= 0)
                    {
                        cout << "\n輸入介於1與100之間的數:";
                    }
                    else
                    {
                        cout << "\n";
                        cout << P[k];
                        break;
                    }
                }
            }
            else if (output == "Q") //四分位數
            {
                cout << "第？四分位數";
                cin >> k;
                if (k >= 4 || k <= 0)
                {
                    flag = 1;
                    cout << "請輸入1或2或3";
                }
                else
                {
                    cout << "\n"
                         << Q[k];
                }
            }
            else if (output == "arrange") //由小排到大
            {
                for (i = 0; i < n; i++)
                {
                    cout << xp[i] << " ";
                }
            }
            else if (output == "standard") //資料標準化
            {
                for (i = 0; i < n; i++)
                {
                    cout << xst[i] << " ";
                }
            }
            else
            {
                flag = 1;
            }
        }
        if (delta == 2)
        {
            cout << "\n";

            if (output == "sum" || output == "average" || output == "stdevp" || output == "stdevs" || output == "var")
            {
                cout << "分析的變量(x or y):";
                cin >> target;
                cout << "\n";
                while (true)
                {
                    if (target == 'x')
                    {
                        if (output == "sum") //總和
                        {
                            cout << summation(x, n);
                        }
                        else if (output == "average") //平均
                        {
                            cout << ave[0];
                        }
                        else if (output == "stdevp") //標準差
                        {
                            cout << stdev[0];
                        }
                        else if (output == "stdevs") //樣本標準差
                        {
                            cout << stdevs[0];
                        }
                        else if (output == "var") //變異數
                        {
                            cout << var[0];
                        }
                        break;
                    }
                    else if (target == 'y')
                    {
                        if (output == "sum") //總和
                        {
                            cout << summation(y, n);
                        }
                        else if (output == "average") //平均
                        {
                            cout << ave[1];
                        }
                        else if (output == "stdevp") //標準差
                        {
                            cout << stdev[1];
                        }
                        else if (output == "stdevs") //樣本標準差
                        {
                            cout << stdevs[1];
                        }
                        else if (output == "var") //變異數
                        {
                            cout << var[1];
                        }
                        break;
                    }
                    else
                    {
                        cout << "錯誤,請重新輸入";
                        cin >> target;
                    }
                }
            }
            else if (output == "arrange") //由小排到大
            {
                cout << "排列的變量(x or y):";
                cin >> target;
                while (true)
                {
                    if (target == 'x')
                    {
                        arrange2(xp, yp, n);
                        break;
                    }
                    else if (target == 'y')
                    {
                        arrange2(yp, xp, n);
                        break;
                    }
                    else
                    {
                        cout << "錯誤,請重新輸入";
                        cin >> target;
                    }
                }

                if (flag == 0) //輸出
                {
                    for (i = 0; i < n; i++)
                    {
                        cout << "(" << xp[i] << "," << yp[i] << ") ";
                    }
                }
            }
            else if (output == "standard") //資料的標準化
            {
                for (i = 0; i < n; i++)
                {
                    cout << "(" << xst[i] << "," << yst[i] << ") ";
                }
            }
            else if (output == "r") //相關係數
            {
                cout << r;
            }
            else if (output == "fitline") //回歸直線
            {
                double temp = -r * (stdev[1] / stdev[0]) * ave[0] + ave[1]; //常數項
                char PN;                                                    //判斷正負
                if (temp >= 0)
                {
                    PN = '+';
                }
                else if (temp < 0)
                {
                    PN = '-';
                    temp = -temp;
                }
                cout << "y=" << r * stdev[1] / stdev[0] << "x" << PN << temp;
            }
            else
            {
                flag = 1;
            }
        }

        if (flag == 0)
        {
            cout << "\n欲結束輸入 finish, 或輸入代碼繼續\n";
            cin >> output;
        }
        if (flag == 1)
        {
            cout << "錯誤,請重新輸入\n";
            cin >> output;
        }
        if (output == "finish")
        {
            break;
        }
    }

    return 0;
}
