#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

#include <string>
#include "../Constants.h"
#include <QImage>
#include <memory>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

class Pen {
protected:
    unsigned char foreR, foreG, foreB;
    int penStyle, lineWidth;
public:

    Pen() : foreR(255), foreG(0), foreB(0),penStyle(PENSTYLE::SOLID),lineWidth(4){

    }

    Pen(unsigned char foreR, unsigned char foreG, unsigned char foreB, int penStyle, int lineWidth) : foreR(foreR), foreG(foreG), foreB(foreB), penStyle(penStyle),lineWidth(lineWidth) {}


    unsigned char getForeR() const {
        return foreR;
    }

    void setForeR(unsigned char foreR) {
        Pen::foreR = foreR;
    }

    unsigned char getForeG() const {
        return foreG;
    }

    void setForeG(unsigned char foreG) {
        Pen::foreG = foreG;
    }

    unsigned char getForeB() const {
        return foreB;
    }

    void setForeB(unsigned char foreB) {
        Pen::foreB = foreB;
    }

    int getPenStyle() const {
        return penStyle;
    }

    void setPenStyle(int penStyle) {
        Pen::penStyle = penStyle;
    }

    int getLineWidth() const {
        return lineWidth;
    }

    void setLineWidth(int lineWidth) {
        Pen::lineWidth = lineWidth;
    }
};

class Brush {
protected:
    unsigned char backR, backG, backB;
    int brushStyle;
public:

    Brush():backR(255), backG(255), backB(0),brushStyle(BRUSHSTYLE::SOLIDPATTERN){}

    Brush(unsigned char backR, unsigned char backG, unsigned char backB, int brushStyle) : backR(backR), backG(backG),backB(backB),brushStyle(brushStyle) {}

    unsigned char getBackR() const {
        return backR;
    }

    void setBackR(unsigned char backR) {
        Brush::backR = backR;
    }

    unsigned char getBackG() const {
        return backG;
    }

    void setBackG(unsigned char backG) {
        Brush::backG = backG;
    }

    unsigned char getBackB() const {
        return backB;
    }

    void setBackB(unsigned char backB) {
        Brush::backB = backB;
    }

    int getBrushStyle() const {
        return brushStyle;
    }

    void setBrushStyle(int brushStyle) {
        Brush::brushStyle = brushStyle;
    }
};

class BaseShape {
protected:
    int posX, posY;
    int type;
    string name;
    double scaleX, scaleY, angle;
public:
    BaseShape(double posX, double posY, int type, const string &name, double scaleX, double scaleY, double angle) : posX(posX), posY(posY), type(type), name(name), scaleX(scaleX), scaleY(scaleY), angle(angle) {}

    void Move(int x ,int y)
    {
        posX+=x;
        posY+=y;
    }

    void Scale(double scaleX,double scaleY)
    {
        this->scaleX*=scaleX;
        this->scaleY*=scaleY;
    }

    void Rotate(double angle)
    {
        this->angle+=angle;
        if(this->angle<0) this->angle+=360;
        if(this->angle>360) this->angle-=360;
    }

    void setPosX(int posX) {
        BaseShape::posX = posX;
    }

    void setPosY(int posY) {
        BaseShape::posY = posY;
    }

    int getType() const {
        return type;
    }

    int getPosX() const {
        return posX;
    }


    int getPosY() const {
        return posY;
    }

    void setType(int type) {
        BaseShape::type = type;
    }

    void setName(const string &name) {
        BaseShape::name = name;
    }

    string getName()const
    {
        return name;
    }

    double getScaleX() const {
        return scaleX;
    }

    void setScaleX(double scaleX) {
        BaseShape::scaleX = scaleX;
    }

    double getScaleY() const {
        return scaleY;
    }

    void setScaleY(double scaleY) {
        BaseShape::scaleY = scaleY;
    }

    double getAngle() const {
        return angle;
    }

    void setAngle(double angle) {
        BaseShape::angle = angle;
    }
};

class Line : public BaseShape {
protected:
    Pen pen;
    int x1, y1, x2, y2;
public:
    Line(int posX,int posY, int type, const string &name, double scaleX, double scaleY, double angle, const Pen &pen,
         int x1, int y1, int x2, int y2) : BaseShape(posX, posY, type, name, scaleX, scaleY, angle),
        pen(pen),  x1(x1), y1(y1), x2(x2), y2(y2) {}

    const Pen &getPen() const {
        return pen;
    }

    void setPen(const Pen &pen) {
        Line::pen = pen;
    }

    int getX1() const {
        return x1;
    }

    void setX1(int x1) {
        Line::x1 = x1;
    }

    int getY1() const {
        return y1;
    }

    void setY1(int y1) {
        Line::y1 = y1;
    }

    int getX2() const {
        return x2;
    }

    void setX2(int x2) {
        Line::x2 = x2;
    }

    int getY2() const {
        return y2;
    }

    void setY2(int y2) {
        Line::y2 = y2;
    }

};
class Ellipse:public BaseShape
{
protected:
    Pen pen;
    Brush brush;
    int a,b;
public:
    Ellipse(int posX, int posY, int type, const string &name, double scaleX, double scaleY, double angle, const Pen &pen,const Brush &brush,
            int a, int b) : BaseShape(posX, posY, type, name, scaleX, scaleY, angle),
        pen(pen),brush(brush),  a(a), b(b){}
    void setBrushColor(unsigned char r,unsigned char g,unsigned char b)
    {
        brush.setBackR(r);
        brush.setBackG(g);
        brush.setBackB(b);
    }

    void setBrushStyle(int newStyle)
    {
        brush.setBrushStyle(newStyle);
    }

    const Pen &getPen() const {
        return pen;
    }

    void setPen(const Pen &pen) {
        Ellipse::pen = pen;
    }
    const Brush &getBrush()const{
        return brush;
    }
    void setBrush(const Brush &brush){
        Ellipse::brush=brush;
    }

    int getA() const {
        return a;
    }

    void setA(int a) {
        Ellipse::a = a;
    }

    int getB() const {
        return b;
    }

    void setB(int b) {
        Ellipse::b = b;
    }

};

class Rect:public BaseShape
{
protected:
    Pen pen;
    Brush brush;
    int width, height;

public:
    Rect(int posX, int posY, int type, const string &name, double scaleX, double scaleY, double angle, const Pen &pen,const Brush &brush,
         int width, int height):BaseShape(posX, posY, type, name, scaleX, scaleY, angle),
        pen(pen),brush(brush), width(width), height(height){}

    const Pen &getPen() const {
        return pen;

    }
    void setBrushColor(unsigned char r,unsigned char g,unsigned char b)
    {
        brush.setBackR(r);
        brush.setBackG(g);
        brush.setBackB(b);
    }

    void setBrushStyle(int newStyle)
    {
        brush.setBrushStyle(newStyle);
    }

    const Brush &getBrush()const{
        return brush;
    }

    void setPen(const Pen &pen) {
        Rect::pen = pen;
    }

    int getWidth() const {
        return width;
    }

    void setWidth(int width){
        Rect::width = width;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int height){
        Rect::height = height;
    }
};
class Text:public BaseShape{
protected:
    Pen pen;
    Brush brush;
    string text;
public:
    Text(int posX, int posY, int type, const string &name, double scaleX, double scaleY, double angle, const Pen &pen,const Brush &brush,
         string text):BaseShape(posX, posY, type, name, scaleX, scaleY, angle),
        pen(pen),brush(brush), text(text){}
    void setBrushColor(unsigned char r,unsigned char g,unsigned char b)
    {
        brush.setBackR(r);
        brush.setBackG(g);
        brush.setBackB(b);
    }

    void setBrushStyle(int newStyle)
    {
        brush.setBrushStyle(newStyle);
    }

    const Pen &getPen() const {
        return pen;
    }

    void setPen(const Pen &pen) {
        Text::pen = pen;
    }
    const Brush &getBrush()const{
        return brush;
    }
    void setBrush(const Brush &brush){
        Text::brush=brush;
    }
    const string &gettext()const{
        return text;
    }
    void setText(const string &text){
        Text::text=text;
    }

};

typedef unsigned char UNUM8;	//8???????????????
typedef unsigned short UNUM16;	//16???????????????
typedef unsigned int UNUM32;	//32???????????????
typedef signed char SNUM8;		//8???????????????
typedef signed short SNUM16;	//16???????????????
typedef signed int SNUM32;		//32???????????????
typedef struct {
    UNUM8 r, g, b, a,empty;
}Pixel32b;

class Pixmap:public BaseShape
{
    unsigned int height, width, format;	//height??????????????? width??????????????? format?????????
    UNUM8 *r, *g, *b, *a;	//r???g???b???a???4?????????????????? ??????????????????????????????????????????
public:
    Pixmap(int posX, int posY, int type, const string &name, double scaleX, double scaleY, double angle,unsigned int width, unsigned int height,unsigned char value=0);
    Pixmap(const string &name,string fileName);
    Pixmap(const Pixmap &pixmap) :BaseShape(pixmap),width(0), height(0), r(NULL), g(NULL), b(NULL), a(NULL), format(PIXMAP::FMT_NULL) { Load(pixmap); }
    Pixmap(unsigned int width, unsigned int height, unsigned char value=0) :BaseShape(0, 0, SHAPE::PIXMAP, string("image"), 1.0, 1.0, 0),width(width), height(height), r(NULL), g(NULL), b(NULL), a(NULL), format(PIXMAP::FMT_NULL)
    {
        r = (UNUM8*)malloc(sizeof(UNUM8)*width*height);
        g = (UNUM8*)malloc(sizeof(UNUM8)*width*height);
        b = (UNUM8*)malloc(sizeof(UNUM8)*width*height);
        a = (UNUM8*)malloc(sizeof(UNUM8)*width*height);
        memset(r, value, width*height);
        memset(g, value, width*height);
        memset(b, value, width*height);
        memset(a, value, width*height);
        format = PIXMAP::FMT_RGB;
    }

    ~Pixmap() { FreePixmap(); }
    int Load(const Pixmap &pixmap);
    int Load(const QImage &image);
    void FreePixmap();	//????????????
    shared_ptr<QImage> Output();
    unsigned int GetFormat(){return format;}
    unsigned int GetWidth(){return width;}
    unsigned int GetHeight(){return height;}

    //void FreePixmap();	//????????????

    int ConvertFormat(unsigned int newFormat, int thre=-1);	//????????????
    int ConvertToYUV();     //?????????YUV????????????
    int ConvertToRGB();     //?????????RGB????????????
    int ConvertToGrey();	//???YUV??????Y????????????RGB????????????????????????
    unsigned char OtsuGetThre();	//?????????????????????
    int ConvertToBin(int thre=-1);	//???????????????thre??????0~255?????????????????????????????????????????????
    void ChangeLuma(int del);	//??????YUV????????????Y????????????????????????
    int InverseColor();	//??????
    int LogOperation();	//????????????
    int HistoEqualizing();	//???????????????
    static double Gaussian(double x,double r);//??????????????????


    shared_ptr<Pixmap> AddBorder(unsigned int borderWidth,int mode=0) const;	//??????????????????
    shared_ptr<Pixmap> Convolution(double * filter, unsigned int filterSize, int normalization=1,double **outR=NULL,double **outG=NULL,double **outB=NULL) const;	//??????
    shared_ptr<Pixmap> ConvolutionGet(double * filter, unsigned int filterSize, int normalization=1,double **outR=NULL,double **outG=NULL,double **outB=NULL);	//??????
    shared_ptr<Pixmap> LaplacianEnhance(double * filter=NULL, unsigned int filterSize=0) ;	//????????????????????????
    shared_ptr<Pixmap> BilateralFiltering(int filterSize=-1,double intenPara=-1,double spacePara=-1) ;//????????????

    //????????????????????????


    int Nostalgic();//????????????
    int Fleeting(); //????????????
    int Lighting(int centerX,int centerY,int radius,int strength); //????????????
    int BuildingBlock();//????????????
    int Comic();//???????????????
    int LowLight();//????????????
    int Casting();//????????????
    int NeonLight();//????????????
    int Exposal();//????????????
    int Freezing();//????????????
    int OilPaint();//????????????


    //????????????
    int FSRCNN(int x,string aimPic);
    int ESPCN(int x,string aimPic);
    int EDSR(int x,string aimPic);
    int LapSRN(int x,string aimPic);



    const unsigned char *getRHead() const { return r; }	//??????r??????
    const unsigned char *getGHead() const { return g; }	//??????g??????
    const unsigned char *getBHead() const { return b; }	//??????b??????
    const unsigned char *getAHead() const { return a; }	//??????a??????

    unsigned char *getRHead() { return r; }	//???????????? ??????r??????
    unsigned char *getGHead() { return g; }	//???????????? ??????g??????
    unsigned char *getBHead() { return b; }	//???????????? ??????b??????
    unsigned char *getAHead() { return a; }	//???????????? ??????a??????

    unsigned int getFormat() const { return format; }	//????????????

    const unsigned char *getR(unsigned int x, unsigned int y) const { if (x < width&&y < height) return r + y*width + x; return NULL; }//??????(x,y)????????????r?????????
    const unsigned char *getG(unsigned int x, unsigned int y) const { if (x < width&&y < height)return g + y*width + x; return NULL; } //??????(x,y)????????????g?????????
    const unsigned char *getB(unsigned int x, unsigned int y) const { if (x < width&&y < height) return b + y*width + x; return NULL; } //??????(x,y)????????????b?????????
    const unsigned char *getA(unsigned int x, unsigned int y) const { if (x < width&&y < height) return a + y*width + x; return NULL; } //??????(x,y)????????????a?????????
    Pixel32b getPixel(unsigned int x,unsigned int y) const;	//??????(x,y)?????????????????????

    unsigned char *getR(unsigned int x, unsigned int y) { if (x < width&&y < height) return r + y*width + x; return NULL; } //???????????? ??????(x,y)????????????r?????????
    unsigned char *getG(unsigned int x, unsigned int y) { if (x < width&&y < height) return g + y*width + x; return NULL; }//???????????? ??????(x,y)????????????g?????????
    unsigned char *getB(unsigned int x, unsigned int y) { if (x < width&&y < height) return b + y*width + x; return NULL; }//???????????? ??????(x,y)????????????b?????????
    unsigned char *getA(unsigned int x, unsigned int y) { if (x < width&&y < height) return a + y*width + x; return NULL; }//???????????? ??????(x,y)????????????a?????????

};


class Histogram3c
{
    unsigned int *hgR, *hgG, *hgB;	//3??????????????????
public:
    Histogram3c();
    Histogram3c(Pixmap &pixmap,unsigned char select=PIXMAP::SELECT_R|PIXMAP::SELECT_G|PIXMAP::SELECT_B);
    ~Histogram3c() { FreeHistogram3c(); }
    void FreeHistogram3c();
    void LoadPixmap(Pixmap &pixmap, unsigned char select = PIXMAP::SELECT_R|PIXMAP::SELECT_G|PIXMAP::SELECT_B);	//???Pixmap??????????????????
    unsigned int* CalcHistogram(unsigned int total,const unsigned char *color);
    unsigned int getRCount(unsigned char r) const;
    unsigned int getGCount(unsigned char g) const;
    unsigned int getBCount(unsigned char b) const;
    unsigned int *getRHead() { return hgR; }
    unsigned int *getGHead() { return hgG; }
    unsigned int *getBHead() { return hgB; }
};
class DoneInfo{
    int layoutindex,beforelayoutindex;
    shared_ptr<BaseShape> aftershape,beforeshape;
    int commandtype;
public:
    DoneInfo(int commandtype,int layoutindex,shared_ptr<BaseShape> aftershape=nullptr,shared_ptr<BaseShape> beforeshape=nullptr,int beforelayoutindex=-1):commandtype(commandtype),
        layoutindex(layoutindex),aftershape(aftershape),beforeshape(beforeshape),beforelayoutindex(beforelayoutindex){}
    int getlayoutindex()const{
        return layoutindex;
    }
    void setlayoutindex(int layoutindex){
        this->layoutindex=layoutindex;
    }
    int getbeforelayoutindexx()const{
        return beforelayoutindex;
    }
    void setbeforelayoutindex(int beforelayoutindex){
        this->beforelayoutindex=beforelayoutindex;
    }

    shared_ptr<BaseShape> getaftershape() const{
        return aftershape;
    }
    void setaftershape(shared_ptr<BaseShape> aftershape){
        this->aftershape=aftershape;
    }
    shared_ptr<BaseShape> getbeforeshape() const{
        return beforeshape;
    }
    void setbeforeshape(shared_ptr<BaseShape> beforeshape){
        this->beforeshape=beforeshape;
    }
    int getcommandtype()const{
        return commandtype;
    }
    void setcommandtype(int commandtype){
        this->commandtype=commandtype;
    }
};
#endif // DATASTRUCTURE_H
