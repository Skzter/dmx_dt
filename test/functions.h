#include <DmxSimple.h>

void farbeRGB(int, int, int, int);
void drehen(int, int, int, int);
int channelStart(int);
void white(int);
void dimmen(int, int);

void dimmen(int proz, int nr){
	int channel_start = channelStart(nr);
	switch(nr){
		case 1: case 4:
			DmxSimple.write(channel_start, float(proz) / 100 * 255);
			break;
		case 2: case 3:
			DmxSimple.write(channel_start, float(proz) / 100 * 127 + 7);
			break;
  }
}
void drehen(int x, int y, int speed, int nr){
        int channel_start = channelStart(nr) - 5;
        DmxSimple.write(channel_start + 4, (1 - float(speed) / 100) * 255);
        DmxSimple.write(channel_start, float(x) / 540 * 255);
        DmxSimple.write(channel_start + 2, float(y) / 180 * 255);
}

void white(int nr){
    int channel_start = channelStart(nr);
    DmxSimple.write(channel_start, 255);
    DmxSimple.write(channel_start + 4, 255);
}

void farbeRGB(int red, int green, int blue, int nr){
  int channel_start = channelStart(nr);
        DmxSimple.write(channel_start, 255);
        DmxSimple.write(channel_start + 1, red);
        DmxSimple.write(channel_start + 2, green);
        DmxSimple.write(channel_start + 3, blue);

}

int channelStart(int i){
    switch(i){
      case 1:
        return 1;
        break;
      case 2:
        return 14;
        break;
      case 3:
        return 28;
        break;
      case 4:
        return 37;
        break;
  }
}		
