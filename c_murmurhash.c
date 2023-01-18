#include "phone.h"

/**
 * MurmurHash2 - takes an input key and a seed value, and generates a 32-bit or 64-bit hash code depending on the implementation.
 * @key: pointer to the key
 * @len: length of the key
 * @seed: seed value as input
 */
unsigned int MurmurHash2(const void *key, int len, unsigned int seed)
{
	// 'm' and 'r' are mixing constants generated offline
	// They're notraelly 'magic', they just happen to work well
	const unsigned int m = 0x5bd1e995;
	const int r = 24;
	unsigned int h = seed ^ len;
	const unsigned char *data = (const unsigned char *)key;

	while(len >= 4)
	{
		unsigned int k = *(unsigned int *)data;
		k *= m;
		k ^= k >> r;
		k *= m;
		h *= m;
		h ^= k;
		data += 4;
		len -= 4;
	}

	switch(len)
	{
		case 3: h ^= data[2] << 16;
		case 2: h ^= data[1] << 8;
		case 1: h ^= data[0];
		    h *= m;
	}

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h;
}
