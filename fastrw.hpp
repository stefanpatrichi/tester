//
//  HEADER BEGINS HERE
//

#ifndef INCLUDE_TESTER_FASTRW_H
#define INCLUDE_TESTER_FASTRW_H

#include <array>
#include <fstream>

const int BUFSIZE = 4096;

class InParser {
public:
    InParser(const char*);
    friend InParser& operator>>(InParser&, int&);
private:
    std::array<char, BUFSIZE> rbuf; int rpos; 
    std::ifstream fin;

    char GetChar();
    int GetInt();
};

#endif  // INCLUDE_TESTER_FASTRW_H

//
//  HEADER ENDS HERE
//

#ifdef FASTRW_IMPLEMENTATION

// private funcs

char InParser::GetChar() {
    if (++rpos == rbuf.size()) { fin.read(rbuf.data(), rbuf.size()); rpos = 0; }
    return rbuf[rpos];
}

int InParser::GetInt() {
    char ch; int retval = 0;
    while (!isdigit(ch = GetChar()));
    do retval = retval * 10 + ch - '0'; while (isdigit(ch = GetChar()));
    return retval;
}


// public funcs

InParser::InParser(const char* name) : rpos(rbuf.size() - 1), fin(name) { }

InParser& operator>>(InParser& in, int& num) {
    num = in.GetInt();
    return in;
}


#endif  // FASTRW_IMPLEMENTATION