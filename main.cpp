#include<bits/stdc++.h>
using namespace std;
#include <windows.h>
#include <GL/glut.h>
#define PI                  acos(-1)
///the function you need to change for your name and id starts at 118th line
int rot=100;
int iter=0;
float _ultx=0;
void draw_solid_arc(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy, GLfloat st, GLfloat en){
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(cx,cy, 0.0f);
    for(float i=st;i<=en;i+=1.0){
        float angle=2.0f*3.1416f*i/100.0f;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex3f(x+cx,y+cy, 0.0f);
    }
    glEnd();
}
void draw_void_arc(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy, GLfloat st, GLfloat en){
    glBegin(GL_LINE_LOOP);
    glVertex3f(cx,cy, 0.0f);
    for(float i=st;i<=en;i+=1.0){
        float angle=2.0f*3.1416f*i/100.0f;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex3f(x+cx,y+cy, 0.0f);
    }
    glEnd();
}
void draw_solid_circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy){
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(cx,cy, 0.0f);
    for(float i=0;i<=101;i+=1.0){
        float angle=2.0f*3.1416f*i/100.0f;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex3f(x+cx,y+cy, 0.0f);
    }
    glEnd();
}
void draw_void_circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy){
    glBegin(GL_LINE_LOOP);
    //glVertex3f(cx,cy, 0.0f);
    for(float i=0;i<101;i+=1.0){
        float angle=2.0f*3.1416f*i/100.0f;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex3f(x+cx,y+cy, 0.0f);
    }
    glEnd();
}
void draw_trapezoid(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat x3, GLfloat y3, GLfloat x4, GLfloat y4){
    glBegin(GL_QUADS);
    glVertex3f(x1,y1,0.0f);
    glVertex3f(x2,y2,0.0f);
    glVertex3f(x3,y3,0.0f);
    glVertex3f(x4,y4,0.0f);
    glEnd();
}
void draw_rectangle(GLfloat x1, GLfloat y1, GLfloat x3, GLfloat y3){
    float x2=x3,y2=y1,x4=x1,y4=y3;
    glBegin(GL_QUADS);
    glVertex3f(x1,y1,0.0f);
    glVertex3f(x2,y2,0.0f);
    glVertex3f(x3,y3,0.0f);
    glVertex3f(x4,y4,0.0f);
    glEnd();
}
void draw_square(GLfloat x1, GLfloat y1, GLfloat len){
    float x3=x1+len,y3=y1+len;
    float x2=x3,y2=y1,x4=x1,y4=y3;
    glBegin(GL_QUADS);
    glVertex3f(x1,y1,0.0f);
    glVertex3f(x2,y2,0.0f);
    glVertex3f(x3,y3,0.0f);
    glVertex3f(x4,y4,0.0f);
    glEnd();
}
void draw_line(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, GLfloat sz){
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glVertex3f(x1, y1, 0.0);
    glVertex3f(x2, y2, 0.0);
    glEnd();
}
void print_string(char *s, GLfloat x, GLfloat y){
    int len=strlen(s);
    glRasterPos2f(x,y);
    for(int i=0;i<len;i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
    }
}
void StackPages(GLfloat x, char *s){
    ///Stack
        glColor3f (0.40, 0.40, 0.40);
        draw_rectangle(212.0f+x, 63.0f,
                       562.0f+x, 588.0f);
        glColor3f (0.50, 0.50, 0.50);
        draw_rectangle(209.0f+x, 66.0f,
                       559.0f+x, 591.0f);
        glColor3f (0.60, 0.60, 0.60);
        draw_rectangle(206.0f+x, 69.0f,
                       556.0f+x, 594.0f);
        glColor3f (0.80, 0.80, 0.80);
        draw_rectangle(203.0f+x, 72.0f,
                       553.0f+x, 597.0f);
    ///Stack
    ///Welcome Page
        glColor3f (1.0, 1.0, 1.0);
        draw_rectangle(200.0f+x, 75.0f,
                       550.0f+x, 600.0f);
        glColor3f (0.0, 0.0, 0.0);
        print_string(s,325.0+x,337.0);
    ///Welcome Page
}
void IDPage(GLfloat x){ ///Change your name and ID here
    glColor3f (0.0, 0.0, 0.0);
    draw_rectangle(800.0f+x, 75.0f,
                   1150.0f+x, 600.0f);
    glColor3f (1.0, 1.0, 1.0);
    char *s="Tanima Hossain";
    print_string(s,900.0+x,347.0); ///Change the value of 2nd parameter to change the horizontal position of the string i.e.:lower value should be added to x to shift it to left
    char *ID="ID:181-15-10733";
    print_string(ID,900.0+x,327.0); ///Change the value of 2nd parameter to change the horizontal position of the string i.e.:lower value should be added to x to shift it to left
}
vector<pair<double,double> >lifeline{
                                      {884.0f,340.0f},
                                      {886.0f,340.0f},
                                      {890.0f,340.0f},
                                      {894.0f,340.0f},
                                      {898.0f,340.0f},
                                      {902.0f,340.0f},
                                      {906.0f,340.0f},
                                      {908.0f,344.0f},
                                      {910.0f,348.0f},
                                      {912.0f,352.0f},
                                      {914.0f,356.0f},
                                      {914.4f,352.0f},
                                      {914.8f,348.0f},
                                      {915.2f,344.0f},
                                      {915.6f,340.0f},
                                      {916.0f,336.0f},
                                      {916.4f,332.0f},
                                      {916.8f,328.0f},
                                      {917.2f,324.0f},
                                      {917.6f,320.0f},
                                      {918.0f,316.0f},
                                      {918.4f,312.0f},
                                      {918.8f,308.0f},
                                      {919.2f,304.0f},
                                      {919.6f,300.0f},
                                      {920.0f,296.0f},
                                      {920.4f,292.0f},
                                      {920.8f,288.0f},
                                      {921.2f,284.0f},
                                      {921.6f,280.0f},
                                      {922.0f,276.0f},
                                      {922.2f,280.0f},
                                      {922.4f,284.0f},
                                      {922.6f,288.0f},
                                      {922.8f,292.0f},
                                      {923.0f,296.0f},
                                      {923.2f,300.0f},
                                      {923.4f,304.0f},
                                      {923.6f,308.0f},
                                      {923.8f,312.0f},
                                      {924.0f,316.0f},
                                      {924.2f,320.0f},
                                      {924.4f,324.0f},
                                      {924.6f,328.0f},
                                      {924.8f,332.0f},
                                      {925.0f,336.0f},
                                      {925.2f,340.0f},
                                      {925.4f,344.0f},
                                      {925.6f,348.0f},
                                      {925.8f,352.0f},
                                      {926.0f,356.0f},
                                      {926.2f,360.0f},
                                      {926.4f,364.0f},
                                      {926.6f,368.0f},
                                      {926.8f,372.0f},
                                      {927.0f,376.0f},
                                      {927.2f,380.0f},
                                      {927.4f,384.0f},
                                      {927.6f,388.0f},
                                      {927.8f,392.0f},
                                      {928.0f,396.0f},
                                      {928.2f,400.0f},
                                      {928.4f,404.0f},
                                      {928.6f,408.0f},
                                      {928.8f,412.0f},
                                      {929.0f,416.0f},
                                      {929.2f,420.0f},
                                      {929.4f,424.0f},
                                      {929.6f,428.0f},
                                      {929.8f,432.0f},
                                      {930.0f,436.0f},
                                      {930.4f,432.0f},
                                      {930.8f,428.0f},
                                      {931.2f,424.0f},
                                      {931.6f,420.0f},
                                      {932.0f,416.0f},
                                      {932.4f,412.0f},
                                      {932.8f,408.0f},
                                      {933.2f,404.0f},
                                      {933.6f,400.0f},
                                      {934.0f,396.0f},
                                      {934.4f,392.0f},
                                      {934.8f,388.0f},
                                      {935.2f,384.0f},
                                      {935.6f,380.0f},
                                      {936.0f,376.0f},
                                      {936.4f,372.0f},
                                      {936.8f,368.0f},
                                      {937.2f,364.0f},
                                      {937.6f,360.0f},
                                      {938.0f,356.0f},
                                      {938.4f,352.0f},
                                      {938.8f,348.0f},
                                      {939.2f,344.0f},
                                      {939.6f,340.0f},
                                      {952.0f,340.0f},
                                      {960.0f,340.0f},
                                      {968.0f,340.0f},
                                      {976.0f,340.0f},
                                      {984.0f,340.0f},
                                      {992.0f,340.0f},
                                      {992.4f,344.0f},
                                      {992.8f,348.0f},
                                      {993.2f,352.0f},
                                      {993.6f,356.0f},
                                      {994.0f,360.0f},
                                      {994.4f,364.0f},
                                      {994.8f,368.0f},
                                      {995.2f,372.0f},
                                      {995.6f,376.0f},
                                      {996.0f,380.0f},
                                      {996.4f,384.0f},
                                      {996.8f,388.0f},
                                      {997.2f,392.0f},
                                      {997.6f,396.0f},
                                      {998.0f,400.0f},
                                      {998.4f,404.0f},
                                      {998.8f,408.0f},
                                      {999.2f,412.0f},
                                      {999.6f,416.0f},
                                      {1000.0f,420.0f},
                                      {1000.4f,416.0f},
                                      {1000.8f,412.0f},
                                      {1001.2f,408.0f},
                                      {1001.6f,404.0f},
                                      {1002.0f,400.0f},
                                      {1002.4f,396.0f},
                                      {1002.8f,392.0f},
                                      {1003.2f,388.0f},
                                      {1003.6f,384.0f},
                                      {1004.0f,380.0f},
                                      {1004.4f,376.0f},
                                      {1004.8f,372.0f},
                                      {1005.2f,368.0f},
                                      {1005.6f,364.0f},
                                      {1006.0f,360.0f},
                                      {1006.4f,356.0f},
                                      {1006.8f,352.0f},
                                      {1007.2f,348.0f},
                                      {1007.6f,344.0f},
                                      {1008.0f,340.0f},
                                      {1008.4f,336.0f},
                                      {1008.8f,332.0f},
                                      {1009.2f,328.0f},
                                      {1009.6f,324.0f},
                                      {1010.0f,320.0f},
                                      {1010.4f,316.0f},
                                      {1010.8f,312.0f},
                                      {1011.2f,308.0f},
                                      {1011.6f,304.0f},
                                      {1012.0f,300.0f},
                                      {1012.4f,296.0f},
                                      {1012.8f,292.0f},
                                      {1013.2f,288.0f},
                                      {1013.6f,284.0f},
                                      {1014.0f,280.0f},
                                      {1014.4f,276.0f},
                                      {1014.8f,272.0f},
                                      {1015.2f,268.0f},
                                      {1015.6f,264.0f},
                                      {1016.0f,260.0f},
                                      {1016.4f,264.0f},
                                      {1016.8f,268.0f},
                                      {1017.2f,272.0f},
                                      {1017.6f,276.0f},
                                      {1018.0f,280.0f},
                                      {1018.4f,284.0f},
                                      {1018.8f,288.0f},
                                      {1019.2f,292.0f},
                                      {1019.6f,296.0f},
                                      {1020.0f,300.0f},
                                      {1020.4f,304.0f},
                                      {1020.8f,308.0f},
                                      {1021.2f,312.0f},
                                      {1021.6f,316.0f},
                                      {1022.0f,320.0f},
                                      {1022.4f,324.0f},
                                      {1022.8f,328.0f},
                                      {1023.2f,332.0f},
                                      {1023.6f,336.0f},
                                      {1024.0f,340.0f},
                                      {1028.0f,340.0f},
                                      {1032.0f,340.0f},
                                      {1036.0f,340.0f},
                                      {1040.0f,340.0f},
                                      {1044.0f,340.0f},
                                      {1048.0f,340.0f},
                                      {1052.0f,340.0f},
                                      {1056.0f,340.0f},
                                      {1060.0f,340.0f},
                                      {1064.0f,340.0f},
                                      {1068.0f,340.0f},
                                      {1072.0f,340.0f},
                                      {1076.0f,340.0f},
                                      {1080.0f,340.0f},
                                      {1084.0f,340.0f},
                                      {1088.0f,340.0f},
                                      {1092.0f,340.0f},
                                      {1096.0f,340.0f},
                                      {1100.0f,340.0f},
                                      {1104.0f,340.0f},
                                      {1108.0f,340.0f},
                                      {1112.0f,340.0f},
                                      {1116.0f,340.0f},
                                      {1120.0f,340.0f},
                                      {1124.0f,340.0f},
                                      {1128.0f,340.0f},
                                      {1130.0f,340.0f},
                                      };
float lifelen=1,lifesz;
void Page1(GLfloat x){
    glColor3f (1.0, 1.0, 1.0);
    draw_rectangle(800.0f+x, 75.0f,
                   1150.0f+x, 600.0f);
    glColor3f (1.0, 0.0, 0.0);
    draw_solid_circle(80,80,890.0f+x,400.0f);
    draw_solid_circle(80,80,1050.0f+x,400.0f);
    draw_trapezoid(970.0f+x,200.0f,
                   970.0f+x,200.0f,
                   1113.0f+x,350.0f,
                   827.0f+x,350.0f);
    draw_square(950.0f+x,340.f,70.0f);
    glColor3f (1.0, 1.0, 1.0);
    draw_solid_circle(4,4,882.0f+x,340.f);
    lifesz=(int)lifeline.size();
    for(int i=1;i<lifelen;i++){
        if(lifeline[i].first>1105)
            glColor3f (0.0, 0.0, 0.0);
        draw_line(lifeline[i-1].first+x,lifeline[i-1].second,
                  lifeline[i].first+x,lifeline[i].second,1.0);
    } lifelen+=0.5;
    if(lifelen>lifesz){
        lifelen-=lifesz;
    }
}
void Page2(GLfloat x){
    glColor3f (0.0, 0.0, 0.0);
    draw_rectangle(800.0f+x, 75.0f,
                   1150.0f+x, 600.0f);
    glColor3f (1.0, 1.0, 1.0);
    print_string("Life is short.",910.0+x,373.0);
    print_string("So, If it's your story",868.0+x,347.0);
    print_string("Make it the best seller.",861.0+x,322.0);
}
int fam=0;
void Page3(GLfloat x){
    glColor3f (1.0, 1.0, 1.0);
    draw_rectangle(800.0f+x, 75.0f,
                   1150.0f+x, 600.0f);
    if(fam<25)
        glColor3f(0.12, 0.78, 0.12);
    else
        glColor3f(0.05, 0.35, 0.05);
    ///Parents Body
    draw_trapezoid(860.0f+x,290.0f,
                   1072.0f+x,290.0f,
                   1072.0f+x,480.0f,
                   906.0f+x,480.0f);
    ///Parents Hands
    ///Left arm
    draw_trapezoid(842.0f+x,380.0f,
                   994.5f+x,380.0f,
                   906.0f+x,452.0f,
                   866.0f+x,452.0f);
    draw_solid_circle(40.0,30.0,907.0f+x,450.0f);
    draw_solid_arc(21.5,20.0,863.0f+x,380.0f,50,100);
    ///Right arm
    draw_rectangle(1072.0f+x,350.0f,
                   1112.0f+x,452.0f);
    draw_solid_circle(40.0,30.0,1072.0f+x,450.0f);
    draw_solid_arc(20.0,20.0,1092.0f+x,350.0f,50,100);
    ///Parent's Head
    glColor3f (1.0, 1.0, 1.0);
    draw_solid_circle(42.0,42.0,945.0f+x,516.0f);
    draw_solid_circle(42.0,42.0,1025.0f+x,516.0f);
    if(fam<25)
        glColor3f(0.12, 0.78, 0.12);
    else
        glColor3f(0.05, 0.35, 0.05);
    draw_solid_circle(35.0,35.0,945.0f+x,516.0f);
    draw_solid_circle(35.0,35.0,1025.0f+x,516.0f);
    ///Parent's leg
    draw_rectangle(906.0f+x,200.0f,
                   1072.0f+x,350.0f);
    draw_solid_circle(20.0,20.0,926.0f+x,200.0f);
    draw_solid_circle(20.0,20.0,965.0f+x,200.0f);
    draw_solid_circle(20.0,20.0,1012.0f+x,200.0f);
    draw_solid_circle(20.0,20.0,1052.0f+x,200.0f);
    ///Child's body with leg
    if(fam<25)
        glColor3f(0.05, 0.35, 0.05);
    else
        glColor3f(0.12, 0.78, 0.12);
    draw_rectangle(965.0f+x,200.0f,
                   1015.0f+x,350.0f);
    draw_solid_circle(12.5,12.5,977.5f+x,200.0f);
    draw_solid_circle(12.5,12.5,1002.5f+x,200.0f);
    ///Child's arm
    draw_rectangle(1015.0f+x,270.0f,
                   1035.0f+x,337.5f);
    draw_rectangle(945.0f+x,270.0f,
                   965.0f+x,337.5f);
    draw_solid_circle(10,10,955.0f+x,270.0f);
    draw_solid_circle(10,10,1025.0f+x,270.0f);
    draw_solid_circle(16,12.5,1018.0f+x,337.5f);
    draw_solid_circle(16,12.5,961.0f+x,337.5f);
    ///Child's Head
    if(fam<25)
        glColor3f(0.12, 0.78, 0.12);
    else
        glColor3f(0.05, 0.35, 0.05);
    draw_solid_circle(22.0,22.0,990.0f+x,365.0f);
    if(fam<25)
        glColor3f(0.05, 0.35, 0.05);
    else
        glColor3f(0.12, 0.78, 0.12);
    draw_solid_circle(18.0,18.0,990.0f+x,365.0f);
    fam++; fam%=50;
}
void Page4(GLfloat x){
    glColor3f (0.0, 0.0, 0.0);
    draw_rectangle(800.0f+x, 75.0f,
                   1150.0f+x, 600.0f);
    glColor3f (1.0, 1.0, 1.0);
    print_string("Family means you will",865.0+x,373.0);
    print_string("love and be loved",890.0+x,347.0);
    print_string("for the Rest of your life.",861.0+x,322.0);
}
float cltm=100.0,currtm=100.0;
void Page5(GLfloat x){
    glColor3f (1.0, 1.0, 1.0);
    draw_rectangle(800.0f+x, 75.0f,
                   1150.0f+x, 600.0f);
    glColor3f (0.0, 0.0, 0.0);
    draw_solid_circle(150,150,975.0f+x,337.0f);
    glColor3f (0.70, 0.97, 0.70);
    draw_solid_circle(130,130,975.0f+x,337.0f);
    glColor3f (0.0, 0.0, 0.0);
    draw_solid_circle(5,5,975.0f+x,337.0f);
    print_string("3",1085.0f+x,332.0f);
    print_string("12",962.0f+x,442.0f);
    print_string("9",865.0f+x,332.0f);
    print_string("6",970.0f+x,217.0f);
    draw_trapezoid(975.0f+x,337.0f,
                   985.0f+x,412.0f,
                   975.0f+x,432.0f,
                   965.0f+x,412.0f);
    draw_trapezoid(975.0f+x,337.0f,
                   1040.0f+x,322.0f,
                   1080.0f+x,337.0f,
                   1040.0f+x,352.0f);
    float angle=2.0f*3.1416f*currtm/100.0f;
    float x1 = 110.0 * cosf(angle);
    float y1 = 110.0 * sinf(angle);
    draw_line(x+x1+975.0f,y1+337.0f,975.0f+x,337.0f,2.0);
    cltm-=.01;
    if(abs(currtm-cltm)>1.0)
        currtm=cltm;
    if(cltm>100)
        currtm=cltm=100.0;
}
void Page6(GLfloat x){
    glColor3f (0.0, 0.0, 0.0);
    draw_rectangle(800.0f+x, 75.0f,
                   1150.0f+x, 600.0f);
    glColor3f (1.0, 1.0, 1.0);
    print_string("Your Time is Limited",882.0+x,373.0);
    print_string("Don't waste it",905.0+x,347.0);
    print_string("living someone else's life",858.0+x,322.0);
}
int scrn=0;
void Page7(GLfloat x){
    glColor3f (1.0, 1.0, 1.0);
    draw_rectangle(800.0f+x, 75.0f,
                   1150.0f+x, 600.0f);

    glColor3f (0.25, 0.30, 0.40);
    draw_solid_circle(10,10,850.0+x,280.0f);
    draw_solid_circle(10,10,1100.0+x,280.0f);
    draw_solid_circle(10,10,870.0+x,260.0f);
    draw_solid_circle(10,10,1080.0+x,260.0f);
    draw_trapezoid(870.0f+x,250.0f,
                   1080.0+x,250.0f,
                   1100.0f+x,290.0f,
                   850.0+x,290.0f);
    draw_trapezoid(860.0f+x,254.0f,
                   1090.0+x,254.0f,
                   1107.0f+x,273.0f,
                   843.0+x,273.0f);
    draw_solid_circle(10,10,870.0f+x,310.0f);
    draw_solid_circle(10,10,1080.0f+x,310.0f);
    draw_solid_circle(10,10,870.0f+x,430.0f);
    draw_solid_circle(10,10,1080.0f+x,430.0f);
    draw_rectangle(860.0f+x,310.0f,1090.0f+x,430.0f);
    draw_rectangle(870.0f+x,300.0f,1080.0+x,440.0f);
    if(scrn<20)
        glColor3f (0.03, 0.03, 0.18);
    else
        glColor3f (1.0, 0.98, 0.60);
    draw_rectangle(880.0f+x,320.0f,1070.0f+x,420.0f);
    glColor3f (0.0, 0.0, 0.0);
    if(scrn>20){ ///If the screen is on
        ///Blink
        glColor3f (1.0, 0.98, 0.40);
        if((scrn/10)%2){
            draw_trapezoid(865.0f+x,450.0f,
                           875.0f+x,455.0f,
                           855.0f+x,495.0f,
                           845.0f+x,490.0f);
            draw_trapezoid(905.0f+x,464.0f,
                           915.0f+x,466.0f,
                           907.0f+x,506.0f,
                           897.0f+x,504.0f);
            draw_trapezoid(945.0f+x,469.0f,
                           955.0f+x,470.0f,
                           954.0f+x,510.0f,
                           944.0f+x,509.0f);
            draw_trapezoid(985.0f+x,470.0f,
                           995.0f+x,469.0f,
                           996.0f+x,509.0f,
                           986.0f+x,510.0f);
            draw_trapezoid(1025.0f+x,466.0f,
                           1035.0f+x,464.0f,
                           1043.0f+x,504.0f,
                           1033.0f+x,506.0f);
            draw_trapezoid(1065.0f+x,455.0f,
                           1075.0f+x,450.0f,
                           1095.0f+x,490.0f,
                           1085.0f+x,495.0f);
        } else{
            draw_trapezoid(885.0f+x,458.0f,
                           895.0f+x,462.0f,
                           883.0f+x,494.0f,
                           873.0f+x,490.0f);
            draw_trapezoid(925.0f+x,467.0f,
                           935.0f+x,468.0f,
                           933.0f+x,500.0f,
                           923.0f+x,498.0f);
            draw_trapezoid(965.0f+x,470.0f,
                           975.0f+x,470.0f,
                           975.0f+x,500.0f,
                           965.0f+x,500.0f);
            draw_trapezoid(1005.0f+x,468.0f,
                           1015.0f+x,467.0f,
                           1017.0f+x,498.0f,
                           1007.0f+x,500.0f);
            draw_trapezoid(1045.0f+x,462.0f,
                           1055.0f+x,458.0f,
                           1067.0f+x,490.0f,
                           1057.0f+x,494.0f);

        }
        ///Code Symbol
        glColor3f (0.0, 0.0, 0.0);
        draw_trapezoid(937.0f+x,410.0f,
                       907.0f+x,380.0f,
                       917.0f+x,370.0f,
                       947.0f+x,400.0f);
        draw_trapezoid(907.0f+x,380.0f,
                       897.0f+x,370.0f,
                       937.0f+x,330.0f,
                       947.0f+x,340.0f);
        draw_trapezoid(982.0f+x,410.0f,
                       952.0f+x,330.0f,
                       967.0f+x,330.0f,
                       997.0f+x,410.0f);
        draw_trapezoid(1012.0f+x,410.0f,
                       1002.0f+x,400.0f,
                       1032.0f+x,370.0f,
                       1042.0f+x,380.0f);
        draw_trapezoid(1042.0f+x,380.0f,
                       1002.0f+x,340.0f,
                       1012.0f+x,330.0f,
                       1052.0f+x,370.0f);
    }
    scrn++; scrn%=200;
}
void Page8(GLfloat x){
    glColor3f (0.0, 0.0, 0.0);
    draw_rectangle(800.0f+x, 75.0f,
                   1150.0f+x, 600.0f);
    glColor3f (1.0, 1.0, 1.0);
    print_string("Programming is the art of",850.0+x,373.0);
    print_string("algorithm design and the craft",830.0+x,347.0);
    print_string("of debugging errant code.",855.0+x,322.0);
}
void draw_book(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b){
    glColor3f (r, g, b);
    draw_rectangle(x-64,y,x+64,y+64);
    draw_solid_circle(9.0,9.0,x,y+6.0f);
    draw_trapezoid(x-62,y+2,x,y+2,x+1.0,y+65,x-62,y+68);
    draw_trapezoid(x+62,y+2,x,y+2,x+1.0,y+65,x+62,y+68);
    glColor3f (1.0, 1.0, 1.0);
    draw_trapezoid(x-61,y+3,x-.2,y+3,x-.2,y+64,x-61,y+67);
    draw_trapezoid(x+61,y+3,x+.2,y+3,x+.2,y+64,x+61,y+67);
    glColor3f (r, g, b);
    draw_trapezoid(x-59,y+5,x,y+2,x+1.0,y+65,x-59,y+71);
    draw_trapezoid(x+59,y+5,x,y+2,x+1.0,y+65,x+59,y+71);
    glColor3f (1.0, 1.0, 1.0);
    draw_trapezoid(x-58,y+6,x-.2,y+3,x-.2,y+64,x-58,y+70);
    draw_trapezoid(x+58,y+6,x+.2,y+3,x+.2,y+64,x+58,y+70);
    glColor3f (r, g, b);
    draw_trapezoid(x-53,y+8,x,y+2,x+1.0,y+65,x-53,y+74);
    draw_trapezoid(x+53,y+8,x,y+2,x+1.0,y+65,x+53,y+74);
    glColor3f (1.0, 1.0, 1.0);
    draw_trapezoid(x-52,y+9,x-.2,y+3,x-.2,y+64,x-52,y+73);
    draw_trapezoid(x+52,y+9,x+.2,y+3,x+.2,y+64,x+52,y+73);
}
float ang_a=0.0,ang_b=33.0,ang_c=67.0;
void Page9(GLfloat x){
    glColor3f (1.0, 1.0, 1.0);
    draw_rectangle(800.0f+x, 75.0f,
                   1150.0f+x, 600.0f);
    float angle=2.0f*3.1416f*ang_a/100.0f;
    float x1 = 85.0 * cosf(angle);
    float y1 = 85.0 * sinf(angle);
    draw_book(x+x1+975.0f,y1+330.0f,1.0,0.0,0.0);
    angle=2.0f*3.1416f*ang_b/100.0f;
    x1 = 85.0 * cosf(angle);
    y1 = 85.0 * sinf(angle);
    draw_book(x+x1+975.0f,y1+330.0f,0.0,0.0,1.0);
    angle=2.0f*3.1416f*ang_c/100.0f;
    x1 = 85.0 * cosf(angle);
    y1 = 85.0 * sinf(angle);
    draw_book(x+x1+975.0f,y1+330.0f,0.0,1.0,0.0);
    ang_a+=0.10;
    ang_b+=0.10;
    ang_c+=0.10;

}
void Page10(GLfloat x){
    glColor3f (0.0, 0.0, 0.0);
    draw_rectangle(800.0f+x, 75.0f,
                   1150.0f+x, 600.0f);
    glColor3f (1.0, 1.0, 1.0);
    print_string("There are worse crime than",845.0+x,373.0);
    print_string("burning a book. One of them",830.0+x,347.0);
    print_string("is, not reading them.",870.0+x,322.0);
}
pair<float,float> rotate_point(GLfloat px, GLfloat py,GLfloat theta, GLfloat x, GLfloat y){
    float s = sin(theta);
    float c = cos(theta);
    px-=x; py-=y;
    float newx=px*c-py*s;
    float newy=px*s+py*c;
    px=newx+x;
    py=newy+y;
    return {px,py};
}
void draw_musical_notes(GLfloat x, GLfloat y, GLfloat r, GLfloat angle){
    pair<float,float>p1,p2,p3,p4;
    p1=rotate_point(x,y,angle,x,y);
    p2=rotate_point(x+r,y+r/10.0,angle,x,y);
    p3=rotate_point(x+r,y+r/10.0-r/4.0,angle,x,y);
    p4=rotate_point(x,y-r/4.0,angle,x,y);
    draw_trapezoid(p1.first,p1.second,
                   p2.first,p2.second,
                   p3.first,p3.second,
                   p4.first,p4.second);
    p1=rotate_point(x,y-r/4.0,angle,x,y);
    p2=rotate_point(x+r/10.0,y+r/20.0,angle,x,y);
    p3=rotate_point(x+r/10.0,y-r,angle,x,y);
    p4=rotate_point(x,y-r,angle,x,y);
    draw_trapezoid(p1.first,p1.second,
                   p2.first,p2.second,
                   p3.first,p3.second,
                   p4.first,p4.second);
    p1=rotate_point(x-r/4.0+r/10.0,y-r,angle,x,y);
    draw_solid_circle(r/4.0,r/4.0,p1.first,p1.second);
    draw_solid_circle(r/4.0,r/4.0,p1.first,p1.second);
    p1=rotate_point(x+r-r/10.0,y+r/10.0-r/4.0,angle,x,y);
    p2=rotate_point(x+r,y+r/10.0-r/4.0,angle,x,y);
    p3=rotate_point(x+r,y+r/10.0-r,angle,x,y);
    p4=rotate_point(x+r-r/10.0,y+r/10.0-r,angle,x,y);
    draw_trapezoid(p1.first,p1.second,
                   p2.first,p2.second,
                   p3.first,p3.second,
                   p4.first,p4.second);
    auto p=rotate_point(x-r/4.0+r,y-r+r/10.0,angle,x,y);
    draw_solid_circle(r/4.0,r/4.0,p.first,p.second);
}
float clr_r=1.0,clr_g=0.0,clr_b=0.0;
int clrcnt=0,angcnt=0;
void Page11(GLfloat x){
    glColor3f (1.0, 1.0, 1.0);
    draw_rectangle(800.0f+x, 75.0f,
                   1150.0f+x, 600.0f);

    glColor3f (clr_r, clr_g, clr_b);
    if(angcnt<25)
        draw_musical_notes(1000.0+x,320.0,80.0,20.0*PI/180.0);
    else
        draw_musical_notes(1000.0+x,320.0,80.0,340.0*PI/180.0);
    swap(clr_r,clr_g);
    swap(clr_g,clr_b);
    glColor3f (clr_r, clr_g, clr_b);

    if(angcnt<25)
        draw_musical_notes(900.0+x,390.0,60.0,340*PI/180.0);
    else
        draw_musical_notes(900.0+x,390.0,60.0,20*PI/180.0);
    swap(clr_r,clr_g);
    swap(clr_g,clr_b);
    glColor3f (clr_r, clr_g, clr_b);
    if(angcnt<25)
        draw_musical_notes(1000.0+x,450.0,40.0,20.0*PI/180.0);
    else
        draw_musical_notes(1000.0+x,450.0,40.0,340.0*PI/180.0);
    swap(clr_r,clr_g);
    swap(clr_g,clr_b);
    if(clrcnt==0){
        swap(clr_r,clr_g);
        swap(clr_g,clr_b);
    }
    clrcnt++; clrcnt%=25;
    angcnt++; angcnt%=50;
}
void Page12(GLfloat x){
    glColor3f (0.0, 0.0, 0.0);
    draw_rectangle(800.0f+x, 75.0f,
                   1150.0f+x, 600.0f);
    glColor3f (1.0, 1.0, 1.0);
    print_string("Music is the divine way to",845.0+x,373.0);
    print_string("Tell Beautiful poetic things",835.0+x,347.0);
    print_string("to the heart.",910.0+x,322.0);
}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	StackPages(0.0f,"Welcome");
	StackPages(600.0f,"Thank you");
    ///Pages
    if(iter==0){
        Page1(0.0);
        IDPage(_ultx);
    } else if(iter==1){
        IDPage(-600.0);
        Page2(0.0);
        Page1(_ultx);
    } else if(iter==2){
        Page1(-600.0);
        Page3(0.0);
        Page2(_ultx);
    } else if(iter==3){
        Page2(-600.0);
        Page4(0.0);
        Page3(_ultx);
    } else if(iter==4){
        Page3(-600.0);
        Page5(0.0);
        Page4(_ultx);
    } else if(iter==5){
        Page4(-600.0);
        Page6(0.0);
        Page5(_ultx);
    } else if(iter==6){
        Page5(-600.0);
        Page7(0.0);
        Page6(_ultx);
    } else if(iter==7){
        Page6(-600.0);
        Page8(0.0);
        Page7(_ultx);
    } else if(iter==8){
        Page7(-600.0);
        Page9(0.0);
        Page8(_ultx);
    } else if(iter==9){
        Page8(-600.0);
        Page10(0.0);
        Page9(_ultx);
    } else if(iter==10){
        Page9(-600.0);
        Page11(0.0);
        Page10(_ultx);
    } else if(iter==11){
        Page10(-600.0);
        Page12(0.0);
        Page11(_ultx);
    } else if(iter==12){
        Page11(-600.0);
        Page12(_ultx);
    }
    ///Pages
    glFlush ();
}

void init (void){
    ///select clearing (background) color
    glClearColor (0.667, 0.271, .302, 1.0);
    ///initialize viewing values
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1350.0, 0.0, 675.0, 0.0, 100.0);
}
int pcnt=0,last=13;
void update(int value) {
	_ultx-=2.0;
    if(_ultx<-600){
        if(iter%2||iter+1==last){
            if(pcnt==150){
                _ultx=0;
                pcnt=0;
                iter++;
            } else{
                _ultx+=2.0;
                pcnt++;
            }
        } else{
            _ultx=0;
            pcnt=0;
            iter++;
        }
    }
    iter%=last;
	glutPostRedisplay(); ///Tell GLUT that the scene has changed
	glutTimerFunc(6, update, 0); ///Set time in msec
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1350, 675);
    glutInitWindowPosition (0, 35);
    glutCreateWindow ("Inspiring Quotes");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(30, update, 0);
    glutMainLoop();
    return 0;
}
