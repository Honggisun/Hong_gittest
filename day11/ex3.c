#include <stdio.h>
#include <stdlib.h>

#include "map.h"

int main()
{
	char TitlePalette[] = {'.','#','@'};

	_S_MAP_HEADER carObj;
	map_init(&carObj);

	map_load(&carObj,"car.dat");
	puts("-------load complete-------");

	map_dump(&carObj,TitlePalette);
	
	

	return 0;
}
