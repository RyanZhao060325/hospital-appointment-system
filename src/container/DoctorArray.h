#pragma once

#include <string>
#include "entity.h"

/* ============================================================
 *  DoctorArray：用一个定长数组存医生
 *      data_  ：装医生的数组
 *      count_ ：实际装了几个（0 ~ kMaxDoctor）
 * ============================================================ */
class DoctorArray
{
public:
    DoctorArray();                                  /* 构造函数：把 count_ 清成 0 */

    int loadDoctors(const std::string& path);       /* 读 txt 加载，返回条数；-1 = 打开失败 */
    int getSize() const;                            /* 现在装了几个医生 */

    /* 查询：把找到的医生写进调用方给的 out 数组，返回找到几条
       注意 findById 是按编号查，编号唯一，所以最多返回 1 条 */
    int findById(const std::string& id, Doctor* out, int cap);
    int findByDepartment(const std::string& dept, Doctor* out, int cap);
    int findByTitle(const std::string& title, Doctor* out, int cap);
    int findByGoodAt(const std::string& goodAt, Doctor* out, int cap);

    int printDoctors() const;                       /* 打印全部医生，返回条数 */

private:
    /* 最多能装多少个医生。
       用【类内常量】而不是 #define ——
       宏一旦定义就对整个文件生效，很容易和别的文件里的同名宏打架 */
    static constexpr int kMaxDoctor = 256;

    Doctor data_[kMaxDoctor];
    int    count_;
};
