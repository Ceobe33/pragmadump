#pragma once
#ifndef RPG_RPG_TOOL_H_
#define RPG_RPG_TOOL_H_

static class Tool {
public:
    /* where need this
      游戏中曲面是由许多平面构成，要求出光线在物体表面反射后的效果
      就得得出平面的单位法向量，法向量的长度平方R
      单位法向量 = 坐标值 / sqrt(R) = 坐标值 * rsqrt(R)
       ① 将值强转为可以进行二进制运算的long类型
       ② 通过减法和右移计算y的平方根倒数的近似值i
       ③ 将近似值i强转为float类型
       ④ 把y代入牛顿法计算更精确的值
       ⑤ 二次计算使结果更加精确
    */
    // quick reciprocal square root
    inline static float Q_rsqrt(float number) {
        long i;
        float x2, y;
        const float threehalfs = 1.5f;

        x2 = number * 0.5f;
        y = number;
        i = *(long*)&y;     // evil floating point bit level hacking    ①
        i = 0x5f3759df - (i >> 1);              // what the fuck?       ②
        y = *(float*)&i;                        //                      ③
        y = y * (threehalfs - (x2 * y * y));    // 1st iteration        ④
    //  y = y * (threehalfs - (x2 * y * y));    // 2nd iteration        ⑤
                                            // this can be removed

        return y;
    }
};

#endif // !RPG_RPG_TOOL_H_
