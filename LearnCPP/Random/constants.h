#ifndef CONSTANTS_H
#define CONSTANTS_H

enum class rank
{
	_2,
	_3,
	_4,
	_5,
	_6,
	_7,
	_8,
	_9,
	_10,
	_J,
	_Q,
	_K,
	_A,
	max_ranks
};

enum class suit
{
	C,
	D,
	H,
	S,
	max_suits
};

struct card
{
	rank r;
	suit s;
};

#endif