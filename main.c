#include "deque.h"

int main()
{
	deque d1, d2, d3;

	d1 = createDeque();

	userTypeDeque k, t, h;

	pushFrontDeque(d1, 3);
	//pushBackDeque(d1, 5);
	//pushFrontDeque(d1, 1);

	popFrontDeque(d1, &h);
	printf("%d\n", valueFrontDeque(d1, &k));


	printf("%d\n\n", popBackDeque(d1, &t) );


	printf("h=%d. %d:%d\n", h, k, t);

	printf("%d\n", checkFullDeque(d1));

	return 0;
}
