#pragma once
#ifndef RPG_DEBUG_H_

class Debug
{
public:
    void log(string);
    void print(string);
    static Debug debug;
};

#endif // !RPG_DEBUG_H_
