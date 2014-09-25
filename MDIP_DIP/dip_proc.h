#include "image_lib.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
class pixel{
public:
	pixel(int r,int g,int b):red(r),green(g),blue(b){}
	pixel(){}
	int red;
	int green;
	int blue;
};

void encode(int *f,int w,int h,int *g)
{
	int i0,j0;
	int *b,wb,hb;

	wb=w/4;
	hb=h/4;
	b=new int[wb*hb];

	i0=w/4;
	j0=h/4;

	block_get(f,w,h,b,wb,hb,i0,j0);
	contrast(b,wb,hb,1.5);
	copy(f,w,h,g);
	block_put(b,wb,hb,g,w,h,i0,j0);
}
int** Grayscale(int **f,int w,int h)
{
	int **g = new int*[3];
	*(g) = new int[w*h];
	*(g + 1) = new int[w*h];
	*(g + 2) = new int[w*h];
	for(int i = 0,j;i < 3;i++){
		for(j = 0;j < h*w;j++){
			*(*(g + i) + j) = (int)(0.299 * *(*(f) + j) + 0.587 * *(*(f + 1) + j) + 0.114 * *(*(f + 2) + j) + 0.5);
		}
	}
	return g;
}
int** Invert(int **f,int w,int h)
{
	int **g = new int*[3];
	*(g) = new int[w*h];
	*(g + 1) = new int[w*h];
	*(g + 2) = new int[w*h];
	for(int i = 0,j;i < 3;i++){
		for(j = 0;j < h*w;j++){
			*(*(g + i) + j) = 255 - *(*(f + i) + j);
		}
	}
	return g;
}
int** BitPlane(int **f,int w,int h, int bit)
{
	int **g = new int*[3];
	*(g) = new int[w*h];
	*(g + 1) = new int[w*h];
	*(g + 2) = new int[w*h];
	for(int i = 0,j;i < 3;i++){
		for(j = 0;j < h*w;j++){
			*(*(g + i) + j) = ((*(*(f + i) + j) & (1 << bit)) ? 255:0);
		}
	}
	return g;
}
int** BitDepth(int **f,int w,int h, int bit)
{
	int **g = new int*[3];
	*(g) = new int[w*h];
	*(g + 1) = new int[w*h];
	*(g + 2) = new int[w*h];
	int value;
	value = 256/pow(2, bit);
	for(int i = 0,j;i < 3;i++){
		for(j = 0;j < h*w;j++){
			*(*(g + i) + j) = *(*(f + i) + j)/value;
			if(*(*(g + i) + j)==0)
				*(*(g + i) + j) = *(*(g + i) + j)*0;
			else
				*(*(g + i) + j) = (*(*(g + i) + j)+1)*value-1;
		}
	}
	return g;
}
int** Filter(int **f,int w,int h, float *mask, int length = 3)
{
	int **g = new int*[3];
	*(g) = new int[w*h];
	*(g + 1) = new int[w*h];
	*(g + 2) = new int[w*h];
	int af = -1;
	int bf = 2;int look;
	double *fdata = new double[length * length];
	for(int i = 0,j,k,m;i < 3;i++){
		for(j = 0;j < h*w;j++){
			m = 0;
			for(k = af;k < bf;k++){
				*(fdata + m++) = (((k == -1) && (j % w) == 0) || (k == 1 && j % w == w -1) || (j < w) ? 0:*(*(f + i) + j - w + k));

			}
			for(k = af;k < bf;k++){
				*(fdata + m++) = (((k == -1) && (j % w) == 0) || (k == 1 && j % w == w -1) ? 0:*(*(f + i) + j + k));
			}
			for(k = af;k < bf;k++){
				*(fdata + m++) = (((k == -1) && (j % w) == 0) || (k == 1 && j % w == w -1) || j >= w * (h - 1) ? 0:*(*(f + i) + j + w + k));
			}
			m = 0;
			for(k = 0;k < length * length;k++) m += *(fdata + k) * *(mask + k);
			*(*(g + i) + j) = (abs(m) > 255 ? 255:abs(m));
		}
	}
	return g;
}
inline void sortPoints(double* data, int length){
	for(int i = 0, j, x,tmp;i < length;i++){
		for(j = i + 1,x = i;j < length;j++){
			if(data[x] > data[j]) x = j;
		}
		if(x != i){
			tmp = data[x];
			data[x] = data[i];
			data[i] = tmp;

		}
	}
}
int** Median(int **f,int w,int h, int len = 3)
{
	int **g = new int*[3];
	*(g) = new int[w*h];
	*(g + 1) = new int[w*h];
	*(g + 2) = new int[w*h];
	int af = -1;
	int bf = 2;int look;
	double *fdata = new double[len * len];
	for(int i = 0,j,k,m;i < 3;i++){
		for(j = 0;j < h*w;j++){
			m = 0;
			for(k = af;k < bf;k++){
				*(fdata + m++) = (((k == -1) && (j % w) == 0) || (k == 1 && j % w == w -1) || (j < w) ? 0:*(*(f + i) + j - w + k));

			}
			for(k = af;k < bf;k++){
				*(fdata + m++) = (((k == -1) && (j % w) == 0) || (k == 1 && j % w == w -1) ? 0:*(*(f + i) + j + k));
			}
			for(k = af;k < bf;k++){
				*(fdata + m++) = (((k == -1) && (j % w) == 0) || (k == 1 && j % w == w -1) || j >= w * (h - 1) ? 0:*(*(f + i) + j + w + k));
			}
			m = 0;
			sortPoints(fdata,len * len);
			*(*(g + i) + j) = *(fdata + 4);
		}
	}
	return g;
}
int** histogramEqualization(int **f,int w,int h)
{
	int **g = new int*[3];
	*(g) = new int[w*h];
	*(g + 1) = new int[w*h];
	*(g + 2) = new int[w*h];
	int colorBit[256];
	double corNum = 256.0 / (h * w);
	int tmp;
	for(int i = 0,j,k,m;i < 3;i++){
		for(j = 0;j < 256;j++) colorBit[j] = 0;
		for(j = 0;j < h*w;j++) colorBit[*(*(f + i) + j)]++;
		colorBit[0] = (round(colorBit[0] * corNum) > 255 ? 255:round(colorBit[0] * corNum));
		if(colorBit[0] != 255){
			for(j = 1;j < 256;j++) colorBit[j] = (colorBit[j] * corNum + colorBit[j - 1] > 255 ? 255:round(colorBit[j] * corNum + colorBit[j - 1]));
			for(j = 0;j < w*h;j++) *(*(g + i) + j) = colorBit[*(*(f + i) + j)];
		}
		else{
			for(j = 0;j < w*h;j++) *(*(g + i) + j) = 0;
		}
	}
	return g;
}
int** interpolationScale(int **img,int width,int height, double wfactor = 1, double hfactor = 1)
{
	int **newImg = new int*[3];
	int newWidth = (width * wfactor), newHeight = (height * hfactor);
	float dw((width - 1.0) / (newWidth - 1.0)), dh((height - 1.0) / (newHeight - 1.0));

	*(newImg) = new int[newWidth * newHeight];
	*(newImg + 1) = new int[newWidth * newHeight];
	*(newImg + 2) = new int[newWidth * newHeight];
	for(int i = 0,j;i < 3;i++){
		for(j = 0;j < newWidth * newHeight;j++){
			*(*(newImg + i) + j) = *(*(img + i) + (round(dh * (j / newWidth))) * width + (round(dw * (j % newWidth))));
		}
	}
	return newImg;
}
int** linaerScale(int **img,int width,int height, double wfactor = 1, double hfactor = 1)
{

	int newWidth = (width * wfactor), newHeight = (height * hfactor);
	float dw((width - 1.0) / (newWidth - 1.0)), dh((height - 1.0) / (newHeight - 1.0)), x, y, u, v;
	int a, b, c, d, fx, fy, cx, cy;
	double p1, p2;

	int **newImg = new int*[3], NewImgSize(newWidth * newHeight);
	*(newImg) = new int[newWidth * newHeight];
	*(newImg + 1) = new int[newWidth * newHeight];
	*(newImg + 2) = new int[newWidth * newHeight];
	if(wfactor <= 1)
		for(int i = 0,j;i < 3 ;i++){
			for(j = 0;j < NewImgSize;j++){
				x = (dw * (j % newWidth)), y = (dh * (j / newWidth));
				u = (x - floor(x)), v = (y - floor(y));

				p1 = *(*(img + i) + (int)(floor(x) + floor(y) * width)) * (1 - u) +
					*(*(img + i) + (int)(ceil(x) + floor(y) * width)) * u;
				p2 = *(*(img + i) + (int)(floor(x) + ceil(y) * width)) * (1 - u) +
					*(*(img + i) + (int)(ceil(x) + ceil(y) * width)) * u;

				*(*(newImg + i) + j) = p1 * (1 - v) + p2 * v;
			}
		}
	else
		for(int j = 0,i;j < NewImgSize;j++){
			x = (dw * (j % newWidth)), y = (dh * (j / newWidth));
			u = (x - floor(x)), v = (y - floor(y));
			/*
			for(i = 0;i < 3;i++){
			p1 = *(*(img + i) + (int)(floor(x) + floor(y) * width)) * (1 - u) +
			*(*(img + i) + (int)(ceil(x) + floor(y) * width)) * u;
			p2 = *(*(img + i) + (int)(floor(x) + ceil(y) * width)) * (1 - u) +
			*(*(img + i) + (int)(ceil(x) + ceil(y) * width)) * u;

			*(*(newImg + i) + j) = p1 * (1 - v) + p2 * v;
			}*/
			fx = x;
			fy = y;
			cx = (x < newWidth ? x + 1:newWidth);
			cy = (y < newHeight - 1 ? y + 1:newHeight - 1);

			a = (fx + fy * width);
			b = (cx + fy * width);
			c = (fx + cy * width);
			d = (cx + cy * width);
			/*
			a = (floor(x) + floor(y) * width);
			b = (ceil(x) + floor(y) * width);
			c = (floor(x) + ceil(y) * width);
			d = (ceil(x) + ceil(y) * width);
			*/
			p1 = *(*(img + 0) + a) * (1 - u) +	*(*(img + 0) + b) * u;
			p2 = *(*(img + 0) + c) * (1 - u) +	*(*(img + 0) + d) * u;
			*(*(newImg + 0) + j) = p1 * (1 - v) + p2 * v;

			p1 = *(*(img + 1) + a) * (1 - u) +	*(*(img + 1) + b) * u;
			p2 = *(*(img + 1) + c) * (1 - u) +	*(*(img + 1) + d) * u;
			*(*(newImg + 1) + j) = p1 * (1 - v) + p2 * v;

			p1 = *(*(img + 2) + a) * (1 - u) +	*(*(img + 2) + b) * u;
			p2 = *(*(img + 2) + c) * (1 - u) +	*(*(img + 2) + d) * u;
			*(*(newImg  + 2) + j) = p1 * (1 - v) + p2 * v;
		}
		return newImg;
}
int** noiseSaltAndPepper(int **img,int width,int height, float noise)
{
	int **newImg = new int*[3];
	*(newImg) = new int[width * height];
	*(newImg + 1) = new int[width * height];
	*(newImg + 2) = new int[width * height];
	srand(time(NULL));

	for(int i = 0,j;i < 3;i++){
		for(j = 0;j < width * height;j++){
			*(*(newImg + i) + j) = *(*(img + i) + j);
		}
	}
	int tmp;
	for(int i = 0;i < width * height * noise;i++){
		tmp = rand() * rand() % (width * height);
		for(int j = 0; j < 3;j++)
			*(*(newImg + j) + tmp) = (tmp % 2 ? 0:255);
	}
	return newImg;
}
int** luminanceTemperature(int **img,int width,int height)
{
	const int totalColor(8);
	const pixel colorMap[] = {
		pixel(0, 0, 0),
		pixel(255, 0, 255),
		pixel(0, 0, 255),
		pixel(0, 255, 255),
		pixel(0, 255, 0),
		pixel(255, 255, 0),
		pixel(255, 0, 0),
		pixel(255, 255, 255)};

	int **newImg = new int*[3];
	*(newImg) = new int[width * height];
	*(newImg + 1) = new int[width * height];
	*(newImg + 2) = new int[width * height];

	const int colorRange(256.0 * 3.0);
	double colorDivade(256.0 * 3.0 / (totalColor - 1));

	int intensity, layer;
	double alpha;
	double x,y,z,a,b,c,d,e;
	for(int i = 0,j;i < width * height;i++){
		intensity = *(*(img + 0) + i) + *(*(img + 1) + i) + *(*(img + 2) + i);
		layer = intensity / colorDivade;
		alpha = (intensity * 1.0 - colorDivade * layer) / colorDivade;

		*(*(newImg + 0) + i) = (colorMap[layer].red == colorMap[layer + 1].red ? colorMap[layer].red : ((1.0 - alpha) * colorMap[layer].red + alpha * colorMap[layer + 1].red));
		*(*(newImg + 1) + i) = (colorMap[layer].green == colorMap[layer + 1].green ? colorMap[layer].green : ((1.0 - alpha) * colorMap[layer].green + alpha * colorMap[layer + 1].green));
		*(*(newImg + 2) + i) = (colorMap[layer].blue == colorMap[layer + 1].blue ? colorMap[layer].blue : ((1.0 - alpha) * colorMap[layer].blue + alpha * colorMap[layer + 1].blue));

		x = *(*(newImg + 0) + i);
		y = *(*(newImg + 1) + i);
		z = *(*(newImg + 2) + i);
	}
	return newImg;
}
int** histogram(int **img,int width,int height)
{
	const int newWidth(256), newHeight(256);
	int **newImg = new int*[3], imgSize(width * height), NewImgSize(newWidth * newHeight);
	*(newImg) = new int[NewImgSize];
	*(newImg + 1) = new int[NewImgSize];
	*(newImg + 2) = new int[NewImgSize];

	int colorbit[3][newWidth] = {};
	double maxHeight = 0;
	//statistic
	for(int i = 0,j;i < 3;i++){
		for(j = 0;j < imgSize;j++){
			colorbit[i][*(*(img + i) + j)]++;
		}
	}
	//mean
	for(int i = 0;i < newWidth;i++){
		maxHeight += (colorbit[0][i] + colorbit[1][i] + colorbit[2][i]) * 2.5;
	}
	maxHeight /= newWidth;
	//init newImage
	for(int i = 0,j;i < 3;i++){
		for(j = 0;j < NewImgSize;j++){
			*(*(newImg + i) + j) = 128;
		}
	}
	//produce
	double ruler = newHeight / maxHeight;
	for(int i(0),j,x(0),tmp;i < newWidth;i++){
		for(x = 0;x < 3;x++){
			j = (newHeight - 1) - (colorbit[x][i] * ruler);
			if(j < 0) j = 0;
			for(;j < newHeight && j >= 0;j++){
				//*(*(newImg + x) + (j * newWidth - (j == 0 ? 1:0)) + i) = 255;
				tmp = (j * newWidth - (j == 0 ? 1:0)) + i;
				*(*(newImg + x) + tmp) = 255;
				*(*(newImg + ((x + 1) % 3)) + tmp) = (*(*(newImg + ((x + 1) % 3)) + tmp) == 255 ? 255:0);
				*(*(newImg + ((x + 2) % 3)) + tmp) = (*(*(newImg + ((x + 2) % 3)) + tmp) == 255 ? 255:0);
			}
		}
	}

	return newImg;
}
int** colorMask(int **img,int width,int height, int red = 0, int green = 0, int blue = 0)
{
	int **newImg = new int*[3], imgSize(width * height);
	*(newImg) = new int[imgSize];
	*(newImg + 1) = new int[imgSize];
	*(newImg + 2) = new int[imgSize];
	pixel mask(red, green, blue);
	int tmp;

	for(int j = 0;j < imgSize;j++){
		tmp = *(*(img + 0) + j) - mask.red;
		*(*(newImg + 0) + j) = (tmp < 0 ? 0:tmp);

		tmp = *(*(img + 1) + j) - mask.green;
		*(*(newImg + 1) + j) = (tmp < 0 ? 0:tmp);

		tmp = *(*(img + 2) + j) - mask.blue;
		*(*(newImg + 2) + j) = (tmp < 0 ? 0:tmp);
	}

	return newImg;
}

int** otsu(int **img,int width,int height, double threshold[])
{
	int **newImg = new int*[3], imgSize(width * height);
	*(newImg) = new int[imgSize];
	*(newImg + 1) = new int[imgSize];
	*(newImg + 2) = new int[imgSize];

	//	double threshold[3] = {0, 0, 0};
	double omega[2] = {}, mu[2] = {}, muforall;
	int colorBit[256]={};

	for(int i = 0,j,k,tmp;i < 3;i++){
		for(j = 0;j < 256;j++) colorBit[j] = 0;
		for(j = 0;j < imgSize;j++){
			colorBit[*(*(img + i) + j)]++;
		}
		for(j = 0,muforall = 0;j < 256;j++){
			muforall += colorBit[j] * j;
		}
		muforall /= imgSize;
		//decide threshold

		for(j = 0,tmp = 0;j <= 256;j++){
			omega[0] = omega[1] = mu[0] = mu[1] = 0;
			for(k = 0;k < j;k++){
				omega[0] += colorBit[k];
				mu[0] += colorBit[k] * k;
			}
			for(k = j;k < 256;k++){
				omega[1] += colorBit[k];
				mu[1] += colorBit[k] * k;
			}
			omega[0] /= imgSize, omega[1] /= imgSize;
			mu[0] /= omega[0], mu[1] /= omega[1];

			//			if(!j) tmp = omega[0] * abs(mu[0]) + omega[1] * abs(mu[1]);
			if(tmp < omega[0] * abs(mu[0]) + omega[1] * abs(mu[1])){
				tmp = omega[0] * abs(mu[0]) + omega[1] * abs(mu[1]);
				threshold[i] = j;
			}
		}
	}
	for(int i = 0,j;i < 3;i++){
		for(j = 0;j < imgSize;j++){
			*(*(newImg + i) + j) = (*(*(img + i) + j) >= threshold[i] ? 255:0);//*(*(img + i) + j)
		}
	}
	return newImg;
}

int** ObjectsDetection(int **img,int width,int height, int &number)
{
	double t[3];
	int imgSize(width * height);
	int **newImg = otsu(img,width,height,t);
	int *objectMap = new int[imgSize];
	int counter = 0;
	bool objectFoundedFlag = false;
	number = 0;

	//    imgshow(newImg, width, height);

	for(int i(0);i < imgSize;i++){
		*(objectMap + i) = 0;
	}

	for(int i(0), j(0);j < imgSize; j++)
	{
		if(*(*(newImg + i) + j) != 0)
		{
			objectFoundedFlag = false;

			if(j - width >= 0 && *(objectMap + j - width) != 0)
			{
				*(objectMap + j) = *(objectMap + j - width);
				objectFoundedFlag = true;
			}
			if(j % width && *(objectMap + j - 1) != 0)
			{
				*(objectMap + j) = *(objectMap + j - 1);
				if(objectFoundedFlag) number--;
				else objectFoundedFlag = true;
			}
			else if(!objectFoundedFlag)
			{
				*(objectMap + j) = ++counter;
				number++;
			}
		}
	}
	/*
	delete [] *(newImg);
	delete [] *(newImg + 1);
	delete [] *(newImg + 2);

	*(newImg) = *(newImg + 1) = *(newImg + 2) = objectMap;
	*/
	return newImg;
}

int** dilation(int **img,int width,int height)
{
	int **newImg = new int*[3], imgSize(width * height);
	*(newImg) = new int[imgSize];
	*(newImg + 1) = new int[imgSize];
	*(newImg + 2) = new int[imgSize];
	double th[3];

	img = otsu(img, width, height, th);

	const int length = 3;
	double mask[length * length] = {0,1,0,1,0,1,0,1,0};
	int af = -1;
	int bf = 2;int look;
	double *fdata = new double[length * length];
	for(int i = 0,j,k,m;i < 3;i++){
		for(j = 0;j < imgSize;j++){
			m = 0;
			for(k = af;k < bf;k++){
				*(fdata + m++) = (((k == -1) && (j % width) == 0) || (k == 1 && j % width == width -1) || (j < width) ? 0:*(*(img + i) + j - width + k));

			}
			for(k = af;k < bf;k++){
				*(fdata + m++) = (((k == -1) && (j % width) == 0) || (k == 1 && j % width == width -1) ? 0:*(*(img + i) + j + k));
			}
			for(k = af;k < bf;k++){
				*(fdata + m++) = (((k == -1) && (j % width) == 0) || (k == 1 && j % width == width -1) || j >= width * (height - 1) ? 0:*(*(img + i) + j + width + k));
			}
			m = 0;
			for(k = 0;k < length * length;k++) m += *(fdata + k) * *(mask + k);

			*(*(newImg + i) + j) = (m > 0 ? 255:*(*(img + i) + j));
		}
	}

	return newImg;
}
int** erosion(int **img,int width,int height)
{
	int **newImg = new int*[3], imgSize(width * height);
	*(newImg) = new int[imgSize];
	*(newImg + 1) = new int[imgSize];
	*(newImg + 2) = new int[imgSize];
	double th[3];

	img = otsu(img, width, height, th);

	const int length = 3;
	double mask[length * length] = {0,1,0,1,0,1,0,1,0};
	int af = -1;
	int bf = 2;int look;
	double *fdata = new double[length * length];
	for(int i = 0,j,k,m;i < 3;i++){
		for(j = 0;j < imgSize;j++){
			m = 0;
			for(k = af;k < bf;k++){
				*(fdata + m++) = (((k == -1) && (j % width) == 0) || (k == 1 && j % width == width -1) || (j < width) ? 0:*(*(img + i) + j - width + k));

			}
			for(k = af;k < bf;k++){
				*(fdata + m++) = (((k == -1) && (j % width) == 0) || (k == 1 && j % width == width -1) ? 0:*(*(img + i) + j + k));
			}
			for(k = af;k < bf;k++){
				*(fdata + m++) = (((k == -1) && (j % width) == 0) || (k == 1 && j % width == width -1) || j >= width * (height - 1) ? 0:*(*(img + i) + j + width + k));
			}
			m = 0;
			for(k = 0;k < length * length;k++) m += *(fdata + k) * *(mask + k);

			*(*(newImg + i) + j) = (m >= 1000 ? 255:0);
		}
	}

	return newImg;
}

int** rotate(int **img,int width,int height,int wh[2],double alpha)
{
	int imgSize(width * height);
	int newHeight, newWidth;
//	alpha %= 360;
	double theta(alpha);
	
	theta *=  (3.1415926 / 180);
	double rsin(sin(theta)), rcos(cos(theta));
	int x_disp(0), y_disp(0);

	if(alpha <= 90){
		newHeight = (abs(width * sin(theta) + height * cos(theta)));
		newWidth = abs(width * cos(theta) + height * sin(theta));
		x_disp = -height * rsin;
	}
	else if(alpha <= 180){
		alpha = 180 - alpha;
		alpha *= (3.1415926 / 180);

		newHeight = (abs(width * sin(alpha) + height * cos(alpha)));
		newWidth = abs(width * cos(alpha) + height * sin(alpha));
		x_disp = -newWidth, y_disp = -height * cos(alpha);
	}
	else if(alpha <= 270){
		alpha = alpha - 180;
		alpha *= (3.1415926 / 180);

		newHeight = (abs(width * sin(alpha) + height * cos(alpha)));
		newWidth = abs(width * cos(alpha) + height * sin(alpha));
		x_disp = -width * cos(alpha), y_disp = -newHeight;
	}
	else if(alpha <= 360){
		alpha = 360 - alpha;
		alpha *= (3.1415926 / 180);

		newHeight = (abs(width * sin(alpha) + height * cos(alpha)));
		newWidth = abs(width * cos(alpha) + height * sin(alpha));
		y_disp = -width * sin(alpha);
	}






	int newImgSize(newHeight * newWidth);
	int **newImg = new int*[3];
	*(newImg) = new int[newImgSize];
	*(newImg + 1) = new int[newImgSize];
	*(newImg + 2) = new int[newImgSize];

	
	int x,y, u, v;
	for(int i = 0,j;i < 3 ;i++){
		for(j = 0;j < newImgSize;j++){
			x = (j % newWidth) + x_disp, y = (j / newWidth) + y_disp;
			u = (x * rcos + y * rsin + 0.5), v = (-x * rsin + y * rcos + 0.5);
			if(u < width && v < height && u >= 0 && v >= 0)
				*(*(newImg + i) + j) = *(*(img + i) + v * width + u);
			else *(*(newImg + i) + j) = 0;
		}
	}



	wh[0] = newWidth, wh[1] = newHeight;
	return newImg;
}








//for template use!!!
int** duplicate(int **img,int width,int height)
{
	int **newImg = new int*[3], imgSize(width * height);
	*(newImg) = new int[imgSize];
	*(newImg + 1) = new int[imgSize];
	*(newImg + 2) = new int[imgSize];

	double y = 1.1;
	int x;
	x = y;
	for(int i = 0,j;i < 3;i++){
		for(j = 0;j < imgSize;j++){
			*(*(newImg + i) + j) = (x <= 1 ? 0:*(*(img + i) + j));
		}
	}
	return newImg;
}
