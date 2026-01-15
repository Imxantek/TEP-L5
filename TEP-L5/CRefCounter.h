#pragma once
#ifndef CREFCOUNTER_H_
#define CREFCOUNTER_H_

class CRefCounter
{
public:
	CRefCounter() { i_count = 0; }
	int iAdd() { return(++i_count); }
	int iDec() { return(--i_count); }
	int iGet() { return(i_count); }
private:
	int i_count;
};

#endif // !CREFCOUNTER_H_