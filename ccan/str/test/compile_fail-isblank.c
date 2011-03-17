#define CCAN_STR_DEBUG 1
#include <ccan/str/str.h>

int main(int argc, char *argv[])
{
#ifdef FAIL
#if !HAVE_BUILTIN_TYPES_COMPATIBLE_P || !HAVE_TYPEOF
#error We need typeof to check isblank.
#endif
	char
#else
	unsigned char
#endif
		c = argv[0][0];

#ifdef FAIL
	/* Fake fail on unsigned char platforms. */
	c = 255;
	BUILD_ASSERT(c < 0);
#endif

	return isblank(c);
}