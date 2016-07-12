#include <stdio.h>
#include <stdlib.h>
#include "../mapEditor/map.h"

int main()
{
	char Tilepalette[] = {'.','#','@'};
	_S_MAP_OBJECT screenBuffer;
	map_init(&screenBuffer);
	map_new(&screenBuffer,16,16);

	_S_MAP_OBJECT carObj;map_init(&carObj);map_load(&carObj,"car.dat");

	puts("\r\n-----------------------");
	{
		_S_MAP_OBJECT *pObj = &carObj;
		for(int iy=0;iy < pObj->m_header.m_nHeight;iy++) {
			for(int ix=0;ix < pObj->m_header.m_nWidth;ix++) {
				map_PutTile(&screenBuffer,iy+5,ix+5,
						pObj->m_pBuf[iy * pObj->m_header.m_nWidth + ix]);
			}
		}
	}

	//map_dump(&carObj,Tilepalette);

	map_dump(&screenBuffer,Tilepalette);

	return 0;

}
