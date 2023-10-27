#pragma once
#ifndef RPG_RPG_TOOL_H_
#define RPG_RPG_TOOL_H_

static class Tool {
public:
    /* where need this
      ��Ϸ�������������ƽ�湹�ɣ�Ҫ���������������淴����Ч��
      �͵õó�ƽ��ĵ�λ���������������ĳ���ƽ��R
      ��λ������ = ����ֵ / sqrt(R) = ����ֵ * rsqrt(R)
       �� ��ֵǿתΪ���Խ��ж����������long����
       �� ͨ�����������Ƽ���y��ƽ���������Ľ���ֵi
       �� ������ֵiǿתΪfloat����
       �� ��y����ţ�ٷ��������ȷ��ֵ
       �� ���μ���ʹ������Ӿ�ȷ
    */
    // quick reciprocal square root
    inline static float Q_rsqrt(float number) {
        long i;
        float x2, y;
        const float threehalfs = 1.5f;

        x2 = number * 0.5f;
        y = number;
        i = *(long*)&y;     // evil floating point bit level hacking    ��
        i = 0x5f3759df - (i >> 1);              // what the fuck?       ��
        y = *(float*)&i;                        //                      ��
        y = y * (threehalfs - (x2 * y * y));    // 1st iteration        ��
    //  y = y * (threehalfs - (x2 * y * y));    // 2nd iteration        ��
                                            // this can be removed

        return y;
    }
};

#endif // !RPG_RPG_TOOL_H_
