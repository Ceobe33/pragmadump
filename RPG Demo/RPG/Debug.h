#pragma once
#ifndef RPG_DEBUG_H_

class Debug
{
public:
    void log(string);
    template <typename... Args>
    void prints(Args...);
    static Debug debug;
};

template<typename... Args>
inline void Debug::prints(Args... args)
{
    int arr[] = { (cout << args, 0)... };
}

#endif // !RPG_DEBUG_H_
