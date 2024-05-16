#ifndef _BASE64_H_
#define _BASE64_H_

#include <vector>
#include <string>
typedef unsigned char BYTE;

std::string base64_encode(BYTE const *buf, unsigned int bufLen);
void base64_decode(std::string const &, BYTE *buf, unsigned int bufLen);
std::vector<unsigned char> base64_decode(std::string const&);
#endif