#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include "../engine/engine2d.h"

typedef struct 
{
	int m_nSkima; //파일 버전
	int m_nWidth;
	int m_nHeight;
} _S_MAP_HEADER;


typedef struct 
{
	_S_MAP_HEADER m_header;
	char *m_pBuf;
} _S_MAP_OBJECT;

_S_MAP_OBJECT MapObject;
int main()
{
	int bLoop=1;

	MapObject.m_header.m_nSkima = 1;
	MapObject.m_pBuf = NULL;
	char TilePalette[] = {'.','#','@','%'};
	
	while(bLoop)
	{
		char szCmd[32];
		gets(szCmd);
		char *pTemp = strtok(szCmd," ");
		if(!strcmp(pTemp,"exit")) {
			bLoop = 0;
			if(MapObject.m_pBuf) {
				free(MapObject.m_pBuf);
			}
		}
		else if(!strcmp(pTemp,"dump")) {
			putTile(0,MapObject.m_header.m_nHeight,
			0,MapObject.m_header.m_nWidth,
			MapObject.m_header.m_nWidth,
			MapObject.m_pBuf,
			TilePalette	
			);
		}
		else if(!strcmp(pTemp,"new")) {
			//ex) new 8 4
			if(MapObject.m_pBuf !=NULL) {free(MapObject.m_pBuf); }
			MapObject.m_header.m_nWidth = atoi(strtok(NULL," "));
			MapObject.m_header.m_nHeight = atoi(strtok(NULL," "));
			MapObject.m_pBuf = malloc(
			MapObject.m_header.m_nHeight * MapObject.m_header.m_nWidth ) ;
			
			for(int i=0;i<MapObject.m_header.m_nHeight * MapObject.m_header.m_nWidth;i++ ) {
				MapObject.m_pBuf[i] = 0;
			}
		}
		else if(!strcmp(pTemp,"put")) {
			//put 1 2 1 (x y tile_index)
			int x,y,tile_index;
			x = atoi(strtok(NULL," "));
			y= atoi(strtok(NULL," "));
			tile_index = atoi(strtok(NULL," "));

			MapObject.m_pBuf[y*MapObject.m_header.m_nWidth + x] = tile_index;
			}
		else if(!strcmp(pTemp,"hline")) {
			//hline 1 2 
			int xpos,tile_index;
			xpos = atoi(strtok(NULL," "));
			tile_index = atoi(strtok(NULL," "));
			for(int iy=0;iy<MapObject.m_header.m_nHeight+xpos;iy++ ) {
				MapObject.m_pBuf[iy* MapObject.m_header.m_nWidth + xpos ] = tile_index;
			}
		}
		else if(!strcmp(pTemp,"vline")) {
			//hline 1 2 
			int ypos,tile_index;
			ypos = atoi(strtok(NULL," "));
			tile_index = atoi(strtok(NULL," "));
			for(int ix=0;ix<MapObject.m_header.m_nWidth;ix++ ) {
				MapObject.m_pBuf[ypos * MapObject.m_header.m_nHeight + ix ] = tile_index;
			}
		}
		/*else if(!strcmp(pTemp."save")) {
			//save filename	
			char filename[20];
			FILE *fp1, *fp2;
			while(2)
			{
			fprintf("%s",filename);
			fp1=fopen(filename,"r");
			if(fp1==NULL)
			printf("파일 저장 했다.");
			else
			break;
			}
		}*/
		else if(!strcmp(pTemp,"load")) {
			//load filename
			char filename[20];
			FILE *fp1, *fp2;
			while(1)
			{
				scanf("%s",filename);
				fp1=fopen(filename,"r");
				if(fp1==NULL)
					printf("해당 파일이 없다.");
				else
					break;
			}
		}
	}	
	return 0;
}
