/* ============================================================
 *  测试程序：检查 DoctorArray 能不能正常用
 *
 *  运行前请确认：当前工作目录下有 data/doctors.txt
 *  （在 VS 里按 F5 运行时，工作目录默认是项目目录，
 *    所以把 data 文件夹放在项目目录下就行）
 * ============================================================ */

#include <iostream>
#include "container/DoctorArray.h"

using namespace std;

int main()
{
    DoctorArray doctors;

    /* ===== 1. 加载数据 ===== */
    cout << "===== 1. 加载医生数据 =====" << endl;
    int n = doctors.loadDoctors("data/doctors.txt");
    if (n < 0)
    {
        cout << "加载失败！检查 data/doctors.txt 的路径对不对" << endl;
        return 1;
    }
    cout << "一共加载了 " << n << " 位医生" << endl;

    /* ===== 2. 打印全部医生 ===== */
    cout << endl << "===== 2. 全部医生 =====" << endl;
    doctors.printDoctors();

    /* ===== 3. 按编号查（编号唯一，最多查到 1 个）===== */
    cout << endl << "===== 3. 查编号 D005 =====" << endl;
    Doctor buf[10];                                     /* 准备一个数组装查询结果 */
    int num = doctors.findById("D005", buf, 10);        /* num = 找到几条 */
    for (int i = 0; i < num; ++i)
    {
        cout << "  " << buf[i].id << "  " << buf[i].name
             << "  " << buf[i].dept << "  " << buf[i].title << endl;
    }

    /* ===== 4. 按科室查（一个科室可能有多个医生）===== */
    cout << endl << "===== 4. 查骨科 =====" << endl;
    num = doctors.findByDepartment("骨科", buf, 10);
    for (int i = 0; i < num; ++i)
    {
        cout << "  " << buf[i].id << "  " << buf[i].name
             << "  " << buf[i].title << endl;
    }

    /* ===== 5. 按擅长查（输入一小段就能匹配）===== */
    cout << endl << "===== 5. 查擅长'高血压' =====" << endl;
    num = doctors.findByGoodAt("高血压", buf, 10);
    for (int i = 0; i < num; ++i)
    {
        cout << "  " << buf[i].id << "  " << buf[i].name
             << "  " << buf[i].goodAt << endl;
    }

    /* ===== 6. 边界测试：查一个不存在的编号 ===== */
    cout << endl << "===== 6. 查不存在的编号 D999 =====" << endl;
    num = doctors.findById("D999", buf, 10);
    cout << "  找到 " << num << " 条（应该是 0）" << endl;

    /* ===== 7. 边界测试：结果数组给小一点 ===== */
    cout << endl << "===== 7. 查骨科，但数组只给 2 个位置 =====" << endl;
    num = doctors.findByDepartment("骨科", buf, 2);
    cout << "  返回 " << num << " 条（应该是 2，不会越界）" << endl;

    return 0;
}
