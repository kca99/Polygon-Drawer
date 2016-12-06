#include <iostream>
#include "client.h"
#include <cmath>    //round, sin/cos functions
#include <stdlib.h> //abs
#include <cstdlib>  //srand, rand
#include <time.h>   //time(NULL) for random seed
#include <string>   //getchar,getline
#include <fstream> //fileopeninggo
#include <cstring> //tokenize


Client::Client(Drawable *drawable)
{
    this->drawable = drawable;
}


void Client::nextPage() {

    static int pageNumber = 0;
    pageNumber++;
    std::cout << "PageNumber " << pageNumber << std::endl;

    switch(pageNumber % 9) {
    case 1:
        draw_rect(0, 0, 750, 750, 0xffffffff);
        draw_rect(50,50,650,650,0xff000000);
        //wiremesh(50, 50,650, 650);
        readsimp("testfile.simp"); //REMEMBER TO SET WORKING DIRECTORY TO CURRENT DIRECTORY!!
        //drawTriangleBresVersion2(500,250,50, 500,500,200, 250,500,50, 0,255,0, 255,0,0,0,0,255);
        drawable->updateScreen();   // you must call this to make the display change.
        break;
    case 2:
    {
        draw_rect(0, 0, 750, 750, 0xffffffff);
        draw_rect(50,50,650,650,0xff000000);
        //readsimp("testfile.simp");
        //rotate('x', 45);

        float trianglenorm[4];
        drawTriangleBresVersion2(500,250,200, 500,500,0, 250,600,0,0,255,0,255,0,0,0,0,255);
        //CalculateFaceNormal(500,250,200,500,500,0, 250,600,0, trianglenorm);


        float centerx= (500+500+250)/3;
        float centery= (250+500+600)/3;
        float centerz= (200+0+0)/3;
        normalize(centerx,centery,centerz, trianglenorm );
        for(int i =0; i<3; i++){
            std::cout<<trianglenorm[i] <<std::endl;
        }
        draw_lineBres(centerx , centery, centerz, trianglenorm[0]*centerx, trianglenorm[1]*centery, trianglenorm[2]*centerz, 250, 0, 0,0,255,0);
        //draw_lineBres(50, 400, 0,centerx , centery, centerz, 255, 255, 0,255,255,0);
        //draw_lineBres(centerx, centery, centerz,400 , 50, 200, 255, 255, 0,255,255,0);

        //draw_lineBres(trianglenorm[0], trianglenorm[1], 0,250 , 600, 50, 250, 0, 0,0,255,0);
        //float cosTheta = dot(trianglenorm[0], trianglenorm[1],trianglenorm[2], VECTOR A B C); //MAKE FUNCTION TO FIND UNIT VECTOR!
         //filledinmesh(50, 50,650, 650);
        drawable->updateScreen();   // you must call this to make the display change.
        break;
    }
    case 3:
        draw_rect(0, 0, 750, 750, 0xffffffff);
        draw_rect(50,50,650,650,0xff000000);
        //drawTriangleBresVersion2(350, 350, 350, 250, 250 ,250 , 255, 0, 0,255, 0, 0,255,0,0);
        //drawTriangleBresVersion2(350, 350, 250, 350, 250 ,250 ,0 , 255, 0,0, 255, 0,0,255,0);
        //draw_rect(350,350,400,400, 0xffff0000);
        //draw_rect(200,200,300,300, 0xffff0000);
        readmesh("box");
        drawable->updateScreen();   // you must call this to make the display change.
        break;
    case 4:
        draw_rect(0, 0, 750, 750, 0xffffffff);
        draw_rect(50,50,650,650,0xff000000);
        //drawTriangleBresVersion2(350, 350, 350, 250, 250 ,250 , 255, 0, 0,255, 0, 0,255,0,0);
        //drawTriangleBresVersion2(350, 350, 250, 350, 250 ,250 ,0 , 255, 0,0, 255, 0,0,255,0);
        draw_rect(350,350,400,400, 0xffff0000);
        draw_rect(200,200,300,300, 0xffff0000);
        //translate(10, 10, 0);
        //translate(200,-100,0);
        //translate(0,50,0);
        rotate('x', 45);
        //rotate('x', -100);

        //translate(+200,-100,0);
        //translate(-190,240,0);
        drawable->updateScreen();   // you must call this to make the display change.
        break;
    case 5:
        draw_rect(0, 0, 750, 750, 0xffffffff);
        draw_rect(50,50,650,650,0xff000000);
        drawable->updateScreen();   // you must call this to make the display change.
        break;
    case 6:
        draw_rect(0, 0, 750, 750, 0xffffffff);
        draw_rect(50,50,650,650,0xff000000);
        drawable->updateScreen();   // you must call this to make the display change.
        break;
    case 7:
        draw_rect(0, 0, 750, 750, 0xffffffff);
        draw_rect(50,50,650,650,0xff000000);
        drawable->updateScreen();   // you must call this to make the display change.
        break;
    case 8:
        draw_rect(0, 0, 750, 750, 0xffffffff);
        draw_rect(50,50,650,650,0xff000000);
        drawable->updateScreen();   // you must call this to make the display change.
        break;
    case 9:


    default:
        draw_rect(0, 0, 750, 750, 0xffffffff);
        draw_rect(400, 400, 700, 700, 0xff00ff40);
        drawable->updateScreen();
    }
}

void Client::readmesh(const char * filepath){
    std::ifstream meshfile;
    std::cout<<"created meshfile variable" <<std::endl;
    meshfile.open(filepath, std::ifstream::in);
    if (!meshfile){
        std::cout<<"Error opening file." <<std::endl;
        return;
    }
    std::string line,floatline;

    int linecount = 0 ;
    //std::cout<<"before while loop" <<std::endl;
    //std::cout<<"line[0] after declaring = "<<line[0] <<std::endl;
    float rowmesh;
    float columnmesh;
    std::string s;
    std::cout<<"file was ok" <<std::endl;
    //std::cout<<"rowmesh = "<<rowmesh <<std::endl;
    //std::cout<<"columnmesh = "<<columnmesh <<std::endl;
    while (std::getline(meshfile,line)){
        //std::cout<<"in while loop" <<std::endl;
        //std::cout<<"linecount = "<<linecount <<std::endl;
        //std::cout<<"line[0] out of if = "<<line[0] <<std::endl;
        if (linecount == 0){ //color

        }
        if (linecount == 1){ //row count
            //std::cout<<"line[0] in if = "<<line[0] <<std::endl;
            s =(&line)[0];
            //std::cout<<"s = "<<s <<std::endl;
            rowmesh = std::stof(s);
            //std::cout<<"rowmesh = "<<rowmesh <<std::endl;
        }
        else if (linecount == 2){ //column count
            s =(&line)[0];
            columnmesh = std::stof(s);
            //std::cout<<"columnmesh = "<<columnmesh <<std::endl;
        }
        else{ //every line after

            char * cnewstring = new char[line.length()+1];
            std::strcpy (cnewstring, line.c_str());
            char *token = std::strtok(cnewstring, " ");
            float x = atof(token);
            float y,z;
            int counter=1;
            while (token != NULL) {
               counter ++;
               token = std::strtok(NULL, " ");

               if (counter == 2){
                   y = atof(token);
               }
               if (counter == 3){
                   z = atof(token);
               }
            }

            std::cout<< "(" << x << ", " << y << ", " << z << ")" <<std::endl;
            //NOW WHAT??
        }
        linecount++;
    }
}

void Client::readsimp(const char * filepath){
    //int token;
    //std::cout<<filepath <<std::endl;
    std::ifstream simpfile;
    //char* simpname = "testfile.simp";
    simpfile.open(filepath, std::ifstream::in);

    if (!simpfile){
        std::cout<<"Error opening file." <<std::endl;
        return;
    }
    std::string line;
    int linecount;
    //std::cout<<"before while loop" <<std::endl;

    while (std::getline(simpfile,line)){
        //std::cout<<"in while loop" <<std::endl;
        linecount = line.length();
        //std::cout<<linecount <<std::endl;
        //======================WORD DETECTION=======================//

        //1. Define StringSearch
        //Use find to see if the substring is in the main string. Returns position if found
        //else returns npos
        std::size_t findCamerastring = line.find("camera");
        std::size_t findLightstring = line.find("light");
        std::size_t findLinestring = line.find("line");
        std::size_t findPolygonstring = line.find("polygon");
        std::size_t findMeshstring = line.find("mesh");
        std::size_t findSurfacestring = line.find("surface");
        std::size_t findAmbientstring = line.find("ambient");
        std::size_t findPhongstring = line.find("phong");
        std::size_t findGouraudstring = line.find("gouraud");
        std::size_t findFlatstring = line.find("flat");

        std::size_t findRotatestring = line.find("rotate");
        std::size_t findTranslatestring = line.find("translate");
        //=======================END DETECTION=======================//

        if (findCamerastring !=std::string::npos){
            //find camera values
        }
        if (findLightstring !=std::string::npos){
            //find Light values
        }
        if (findLinestring !=std::string::npos){
            //find Line values
            float x1, y1, z1, r1,g1,b1;
            float x2, y2, z2, r2,g2,b2;
            std::string newstring=line.substr(findLinestring+5,linecount);
           // std::cout<< newstring <<std::endl;
            char * cnewstring = new char[newstring.length()+1];
            std::strcpy (cnewstring, newstring.c_str());
            char *token = std::strtok(cnewstring, " (),");
            x1 = atof(token);
            int counter=1;
            while (token != NULL) {
                //std::cout << token << '\n';
                counter++;
                token = std::strtok(NULL, " (),");

                if (counter == 2){
                    y1 = atof(token);
                }
                if (counter ==3){
                    z1 = atof(token);
                }
                if (counter ==4){
                    r1 = atof(token);
                }
                if (counter ==5){
                    g1 = atof(token);
                }
                if (counter ==6){
                    b1 = atof(token);
                }

                if (counter == 7){
                    x2 = atof(token);
                }
                if (counter == 8){
                    y2 = atof(token);
                }
                if (counter ==9){
                    z2 = atof(token);
                }
                if (counter ==10){
                    r2 = atof(token);
                }
                if (counter ==11){
                    g2 = atof(token);
                }
                if (counter ==12){
                    b2 = atof(token);
                }

            }
            //std::cout<<x1 << " " << y1 << " " << z1 << " " << r1 << " " << g1 << " " << b1 <<std::endl;
            //std::cout<<x2 << " " << y2 << " " << z2 << " " << r2 << " " << g2 << " " << b2 <<std::endl;
            draw_lineBres(x1,y1,z1, x2,y2,z2,r1,g1,b1,r2,g2, b2);
        }

        if (findPolygonstring != std::string::npos){
            //find Polygon values
            float x0, y0, z0, r0,g0,b0;
            float x1, y1, z1, r1,g1,b1;
            float x2, y2, z2, r2,g2,b2;
            std::string newstring=line.substr(findPolygonstring+8,linecount);
            std::cout<< newstring <<std::endl;
            char * cnewstring = new char[newstring.length()+1];
            std::strcpy (cnewstring, newstring.c_str());
            char *token = std::strtok(cnewstring, " (),");
            x0= atof(token);
            int counter=1;
            while (token != NULL) {
                //std::cout << token << '\n';
                counter++;
                token = std::strtok(NULL, " (),");

                if (counter == 2){
                    y0 = atof(token);
                }
                if (counter ==3){
                    z0 = atof(token);
                }
                if (counter ==4){
                    r0 = atof(token);
                }
                if (counter ==5){
                    g0 = atof(token);
                }
                if (counter ==6){
                    b0 = atof(token);
                }

                if (counter == 7){
                    x1 = atof(token);
                }
                if (counter == 8){
                    y1 = atof(token);
                }
                if (counter ==9){
                    z1 = atof(token);
                }
                if (counter ==10){
                    r1 = atof(token);
                }
                if (counter ==11){
                    g1 = atof(token);
                }
                if (counter ==12){
                    b1 = atof(token);
                }

                if (counter == 13){
                    x2 = atof(token);
                }
                if (counter == 14){
                    y2 = atof(token);
                }
                if (counter ==15){
                    z2 = atof(token);
                }
                if (counter ==16){
                    r2 = atof(token);
                }
                if (counter ==17){
                    g2 = atof(token);
                }
                if (counter ==18){
                    b2 = atof(token);
                }
            }
            drawTriangleBresVersion2(x0, y0,z0,x1, y1,z1, x2, y2,z2, r0, g0, b0, r1, g1, b1, r2, g2, b2);
        }

        if (findMeshstring !=std::string::npos){
            //Open Mesh File
        }
        if (findSurfacestring !=std::string::npos){
            //find surface values
        }
        if (findAmbientstring !=std::string::npos){
            //find ambient values
        }
        if (findPhongstring !=std::string::npos){
            //set rendering style to phong
        }
        if (findGouraudstring !=std::string::npos){
            //set rendering style to gouraud
        }
        if (findFlatstring !=std::string::npos){
            //set rendering style to flat
        }
        if (findRotatestring !=std::string::npos){
            //rotate
            char axis;
            float angle;
            std::string newstring=line.substr(findLinestring+9,linecount);
            //std::cout<< newstring <<std::endl;
            char * cnewstring = new char[newstring.length()+1];
            std::strcpy (cnewstring, newstring.c_str());
            char *token = std::strtok(cnewstring, " ");
            axis = token[0];
            //std::cout << axis <<std::endl;
            while (token != NULL) {
                token = std::strtok(NULL, " ");
                angle = atof(token);
                break;
            }
            //std::cout <<angle <<std::endl;
            rotate( axis, angle);
        }
        if (findTranslatestring !=std::string::npos){
            //translate
            float tx,ty,tz;
            std::string newstring=line.substr(findLinestring+11,linecount);
            //std::cout<< newstring <<std::endl;
            char * cnewstring = new char[newstring.length()+1];
            std::strcpy (cnewstring, newstring.c_str());
            char *token = std::strtok(cnewstring, " ");
            tx = atof(token);
            int counter = 0;
            while (token != NULL) {
                counter++;
                token = std::strtok(NULL, " ");
                if (counter == 1){
                    ty= atof(token);
                }
                if (counter == 2){
                    tz = atof(token);
                }
            }
            std::cout <<tx << " " << ty << " " << tz <<std::endl;
            translate(tx,ty,tz);
        }
    }
}

int Client::lerp(int color1, int color2, int currentvalue, int finalvalue)
{
    float currentvaluefloat = currentvalue;
    float finalvaluefloat = finalvalue;
    // std::cout<< "currentvalue = " << currentvaluefloat <<std::endl;
    // std::cout<< "finalvalue = " << finalvaluefloat <<std::endl;
    float divide = ( currentvaluefloat / finalvaluefloat);
    //std::cout<< "divide = " << divide <<std::endl;
    float lerpedcolor = (color2 - color1) * divide + color1;

   // std::cout<< "lerpedcolor " << lerpedcolor <<std::endl;
    int roundlerp= (round(lerpedcolor));

   // std::cout<< "roundlerp " << roundlerp <<std::endl;
    return roundlerp;
}

void Client::wiremesh(const int p1x, const int p1y, const int p2x, const int p2y){
   /* int xcoords[11], ycoords[11];
    int dx = (p2x - p1x)/10;
    for(int x = 0; x<11; x++){
        if (x != 0 || x != 10){
            int x_random = rand()%25 +(-12);
            xcoords[x] = p1x + x*dx +x_random;
        }
        else{
             xcoords[x] = p1x + x*dx;
        }
        draw_lineBres(xcoords[x], 50, xcoords[x], 650, 255, 0, 0,0, 0, 255);
    }
    for(int y =0; y<11; y++){
        if(y != 0 || y !=10){
            int y_random = rand()%25 +(-12);
            ycoords[y] = p1y + y*dx +y_random;
        }
        else{
            ycoords[y] = p1y + y*dx;
        }
        draw_lineBres(50, ycoords[y], 650, ycoords[y], 255, 0, 0,0, 0, 255);
    }*/

    int xcoords[11][11];
    int ycoords[11][11];
    int dx = (p2x - p1x)/10;

    for (int x= 0; x<11; x++){ //generate values for x and y
         for (int y=0; y<11; y++){
                if (x==0 || x==10){
                    xcoords[x][y] = p1x + x*dx;
                }
                else{
                    int xrand = rand()%25 +(-12);
                    xcoords[x][y] = p1x + x*dx + xrand;
                }
                if (y==0 || y==10){
                    ycoords[x][y] = p1x + y*dx;
                }
                else{
                    int yrand = rand()%25 +(-12);
                    ycoords[x][y] = p1x + y*dx + yrand;
                }  
            }
    }
    for( int y = 0; y<10; y++){ //plot lines for each x and y that was generated
       for (int x=0; x<10; x++){
            //diagonal lines
            unsigned int r1 = rand() % 256;
            unsigned int g1 = rand() % 256;
            unsigned int b1 = rand() % 256;
            unsigned int r2 = rand() % 256;
            unsigned int g2 = rand() % 256;
            unsigned int b2 = rand() % 256;
            int p1x = xcoords[x][y];
            int p1y = ycoords[x][y];
            int p2x =  xcoords[x+1][y+1];
            int p2y = ycoords[x+1][y+1];
            draw_lineBres(p1x, p1y, 0, p2x, p2y, 0, r1, g1, b1,r2,g2 , b2);

            //horizontal lines
            unsigned int r3 = rand() % 256;
            unsigned int g3 = rand() % 256;
            unsigned int b3 = rand() % 256;
            unsigned int r4 = rand() % 256;
            unsigned int g4 = rand() % 256;
            unsigned int b4 = rand() % 256;
            int p3x =  xcoords[x][y];
            int p3y = ycoords[x][y];
            int p4x =  xcoords[x+1][y];
            int p4y = ycoords[x+1][y];
            draw_lineBres(p3x, p3y,0, p4x, p4y, 0,  r3, g3, b3,r4,g4 , b4);

           //vertical lines
            unsigned int r5 = rand() % 256;
            unsigned int g5 = rand() % 256;
            unsigned int b5 = rand() % 256;
            unsigned int r6 = rand() % 256;
            unsigned int g6 = rand() % 256;
            unsigned int b6 = rand() % 256;
           int p5x =  xcoords[x][y];
           int p5y = ycoords[x][y];
           int p6x =  xcoords[x][y+1];
           int p6y = ycoords[x][y+1];
           draw_lineBres(p5x, p5y,0, p6x, p6y,0, r5, g5, b5,r6,g6 , b6);


       }
    }

}
void Client::filledinmesh(const int p1x, const int p1y, const int p2x, const int p2y){
    int xcoords[11][11];
    int ycoords[11][11];
    unsigned int r[11][11];
    unsigned int g[11][11];
    unsigned int b[11][11];
    int dx = (p2x - p1x)/10;

    for (int x= 0; x<11; x++){ //generate values for x and y
         for (int y=0; y<11; y++){
                if (x==0 || x==10){
                    xcoords[x][y] = p1x + x*dx;
                }
                else{
                    int xrand = rand()%25 +(-12);
                    xcoords[x][y] = p1x + x*dx + xrand;
                }
                if (y==0 || y==10){
                    ycoords[x][y] = p1x + y*dx;
                }
                else{
                    int yrand = rand()%25 +(-12);
                    ycoords[x][y] = p1x + y*dx + yrand;
                }
            }
    }
    for (int x= 0; x<11; x++){ //generate random colors for each vertex
         for (int y=0; y<11; y++){
             r[x][y] = rand() % 256;
             g[x][y]= rand() % 256;
             b[x][y]= rand() % 256;
         }
    }
    for( int y = 0; y<10; y++){ //plot lines for each x and y that was generated
       for (int x=0; x<10; x++){

           drawTriangleBresVersion2( xcoords[x][y],  ycoords[x][y],0,  xcoords[x+1][y],  ycoords[x+1][y],0, xcoords[x+1][y+1], ycoords[x+1][y+1],0, r[x][y],g[x][y],b[x][y], r[x+1][y],g[x+1][y],b[x+1][y], r[x+1][y+1],g[x+1][y+1],b[x+1][y+1]);

           drawTriangleBresVersion2( xcoords[x][y],  ycoords[x][y],0,  xcoords[x][y+1],  ycoords[x][y+1],0, xcoords[x+1][y+1], ycoords[x+1][y+1],0, r[x][y],g[x][y],b[x][y], r[x][y+1],g[x][y+1],b[x][y+1], r[x+1][y+1],g[x+1][y+1],b[x+1][y+1]);
       }
    }
}

void Client::draw_rect(int x1, int y1, int x2, int y2, unsigned int color) {
    for(int x = x1; x<x2; x++) {
        for(int y=y1; y<y2; y++) {
            drawable->setPixel(x, y, color);
        }
    }
}

void Client::draw_lineDDA(int x1, int y1, int x2, int y2, unsigned int color){
    if((y2 > y1) && (x2>x1)){ //bottom right
        double m = float(y2 - y1) / float(x2 - x1);
        //std::cout << "m = " << m << std::endl;
        double b = y1 - (m *x1);
        //std::cout << "B = " << b << std::endl;

        for (double x = x1; x<x2; x++){
            double y = m*x + b;
            drawable->setPixel(x, round(y),color);
        }
        for (double y = y1; y<y2; y++){
            double x = (y - b)/m;
            drawable->setPixel(round(x), y,color);
        }
    }
    else if(((y2 > y1)) && (x2<x1)){ //bottom left
        double m = float(y2 - y1) / float(x2 - x1);
        //std::cout << "m = " << m << std::endl;
        double b = y1 - (m *x1);
        //std::cout << "B = " << b << std::endl;
        for (double x = x1; x>x2; x--){
            double y = m*x + b;
            drawable->setPixel(x, round(y),color);
        }
        for (double y = y1; y<y2; y++){
            double x = (y - b)/m;
            drawable->setPixel(round(x), y,color);
        }
    }
    else  if(((y2 < y1)) && (x2>x1)){ //top right
        double m = float(y2 - y1) / float(x2 - x1);
        //std::cout << "m = " << m << std::endl;
        double b = y1 - (m *x1);
        //std::cout << "B = " << b << std::endl;
        for (double y = y1; y>y2; y--){
            double x = (y - b)/m;
            drawable->setPixel(round(x), y,color);
        }
        for (double x = x1; x<x2; x++){
            double y = m*x + b;
            drawable->setPixel(x, round(y),color);
        }
    }
    else  if(((y2 < y1)) && (x2<x1)){ //top left
        double m = float(y2 - y1) / float(x2 - x1);
        //std::cout << "m = " << m << std::endl;
        double b = y1 - (m *x1);
        //std::cout << "B = " << b << std::endl;
        for (double y = y1; y>y2; y--){
            double x = (y - b)/m;
            drawable->setPixel(x, round(y),color);
        }
        for (double x = x1; x>x2; x--){
            double y = m*x + b;
            drawable->setPixel(x, round(y),color);
        }
    }
    else if(x2 == x1){//straight up or down
        //std::cout << "condition1" << std::endl;
        if(y2 < y1){ //up
            //std::cout << "condition2 " << std::endl;
            for (double y=y1; y>y2; y--){
                drawable->setPixel(x1, y,color);
            }
        }
        else if (y2 > y1){ //y2 >y1
            for (double y=y1; y<y2; y++){
                drawable->setPixel(x1, y,color);
            }
        }
    }
    else if (y2 == y1){ //straight across left or right
        if( x2 < x1){
            for (double x=x1; x>x2; x--){
                drawable->setPixel(x, y2,color);
            }
        }
        else if ( x2 > x1){
            for (double x=x1; x<x2; x++){
                drawable->setPixel(x, y2,color);
            }
        }
    }
}

void Client::draw_lineBres(int x1, int y1, int z1, int x2, int y2, int z2, unsigned int ri, unsigned int gi, unsigned int bi,unsigned int rf, unsigned int gf, unsigned int bf){
    double dx = abs(x2 - x1); //we just want to distance of dx and dy
    //std::cout << "dx = " << dx << std::endl;
    double dy = abs(y2 - y1);
    double two_dx = 2*(dx);
    double two_dy = 2*(dy);

    double t2, error;
    t2 = two_dy - two_dx; //we compare the distances if 2dx > 2dy  then the long portion is along the x axis
    error = two_dy - dx;
    double y =y1;
    double x = x1;

    float z;
    z=z1;
    float zdiff = (1- (z/200));
    unsigned int r = ri * zdiff;
    //std::cout<<"ri = " <<r<< std::endl;
    unsigned int g = gi * zdiff;
    //std::cout<<"gi = " <<gi<< std::endl;
    unsigned int b = bi * zdiff;
   // std::cout<<"bi = " <<bi<< std::endl;
    unsigned int color = (0xff << 24) + (r << 16) + (g << 8) + b;
    if(x1 >= 50){
        if(y1>=50){
            drawable->setPixel(x1, y1,color);
        }
    }
    if(t2>0){ //dx longer than dy
        if(y2>y1){ //octant 2
            for(int y=y1+1; y<=y2; y++){
                if(x2 == x1){ //vertical line down
                    float z;
                    if (z1 != z2){
                        z = lerp(z1,z2,y-y1,y2-y1);
                    }
                    else{
                        z = z1;
                    }
                    float zdiff = (1- (z/200));
                    //std::cout<<"z = " <<z<< std::endl;
                    r=lerp(ri,rf,y-y1,y2-y1);
                    g=lerp(gi,gf,y-y1,y2-y1);
                    b=lerp(bi,bf,y-y1,y2-y1);
                    r *=  zdiff;
                    g *=  zdiff;
                    b *=  zdiff;
                    color = (0xff << 24) + (r << 16) + (g << 8) + b;

                    //std::cout<<"color = " <<color<< std::endl;
                    //drawable->setPixel(x1, y,color);

                }
                else if (error <= 0){
                    error += t2;
                    if (x2>x1){
                        x++;
                        //std::cout<<"1"<<std::endl;
                        float z;
                        if (z1 != z2){
                            z = lerp(z1,z2,y-y1,y2-y1);
                        }
                        else{
                            z = z1;
                        }
                        float zdiff = (1- (z/200));
                       // std::cout<<"z = " <<z<< std::endl;
                        r=lerp(ri,rf,y-y1,y2-y1);
                        g=lerp(gi,gf,y-y1,y2-y1);
                        b=lerp(bi,bf,y-y1,y2-y1);
                        r *=  zdiff;
                        g *=  zdiff;
                        b *=  zdiff;
                        color = (0xff << 24) + (r << 16) + (g << 8) + b;
                    }
                    else{
                        x--;
                        //std::cout<<"2"<<std::endl;
                        float z;
                        if (z1 != z2){
                            z = lerp(z1,z2,y-y1,y2-y1);
                        }
                        else{
                            z = z1;
                        }
                        float zdiff = (1- (z/200));
                       // std::cout<<"z = " <<z<< std::endl;
                        r=lerp(ri,rf,y-y1,y2-y1);
                        g=lerp(gi,gf,y-y1,y2-y1);
                        b=lerp(bi,bf,y-y1,y2-y1);
                        r *=  zdiff;
                        g *=  zdiff;
                        b *=  zdiff;
                        color = (0xff << 24) + (r << 16) + (g << 8) + b;
                    }
                }
                else{
                    error -=two_dx;
                    //std::cout<<"what1"<<std::endl;
                    float z;
                    if (z1 != z2){
                        z = lerp(z1,z2,y-y1,y2-y1);
                    }
                    else{
                        z = z1;
                    }
                    float zdiff = (1- (z/200));
                    r=lerp(ri,rf,y-y1,y2-y1);
                    g=lerp(gi,gf,y-y1,y2-y1);
                    b=lerp(bi,bf,y-y1,y2-y1);
                    r *=  zdiff;
                    g *=  zdiff;
                    b *=  zdiff;
                    color = (0xff << 24) + (r << 16) + (g << 8) + b;
                }

                if(x >=50){
                    if(y >=50){
                        drawable->setPixel(x, y,color);
                    }
                }
            }
        }
        else{ //dy<0 right octants
            for(int y=y1-1; y>=y2; y--){
                if (error <= 0){
                    error += t2;
                    if (x2>=x1){
                        x++;
                        //std::cout<<"3"<<std::endl;
                        float z;
                        if (z1 != z2){
                            z = lerp(z1,z2,y1-y,y1-y2);
                        }
                        else{
                            z = z1;
                        }
                        float zdiff = (1- (z/200));
                        r=lerp(ri,rf,y1-y,y1-y2);
                        g=lerp(gi,gf,y1-y,y1-y2);
                        b=lerp(bi,bf,y1-y,y1-y2);
                        r *=  zdiff;
                        g *=  zdiff;
                        b *=  zdiff;
                        color = (0xff << 24) + (r << 16) + (g << 8) + b;
                    }
                    else{
                        x--;
                       //std::cout<<"4"<<std::endl;
                        float z;
                        if (z1 != z2){
                            z = lerp(z1,z2,y1-y,y1-y2);
                        }
                        else{
                            z = z1;
                        }
                        float zdiff = (1- (z/200));
                        r=lerp(ri,rf,y1-y,y1-y2);
                        g=lerp(gi,gf,y1-y,y1-y2);
                        b=lerp(bi,bf,y1-y,y1-y2);
                        r *=  zdiff;
                        g *=  zdiff;
                        b *=  zdiff;
                        color = (0xff << 24) + (r << 16) + (g << 8) + b;
                    }
                }
                else{
                    error -=two_dx;
                    //std::cout<<"what2"<<std::endl;
                    float z;
                    if (z1 != z2){
                        z = lerp(z1,z2,y1-y,y1-y2);
                    }
                    else{
                        z = z1;
                    }

                    float zdiff = (1- (z/200));
                    r=lerp(ri,rf,y1-y,y1-y2);
                    g=lerp(gi,gf,y1-y,y1-y2);
                    b=lerp(bi,bf,y1-y,y1-y2);
                    r *=  zdiff;
                    g *=  zdiff;
                    b *=  zdiff;
                    color = (0xff << 24) + (r << 16) + (g << 8) + b;
                }
                if(x >=50){
                    if(y >=50){
                        drawable->setPixel(x, y,color);
                    }
                }
            }
        }
    }
    else{//t2<0 , dy is longer than dx
        if(x2>x1){ //octant 1
            for( int x=x1+1; x<=x2; x++){
                if(y2 == y1){ //horizontal line across
                        //std::cout<<"here"<<std::endl;
                        float z;
                        if (z1 != z2){
                            z = lerp(z1,z2,x-x1,x2-x1);
                        }
                        else{
                            z = z1;
                        }
                       // std::cout<<"z = "<<z<<std::endl;
                        float zdiff = (1- (z/200));
                      //  std::cout<<"zdiff = "<<zdiff<<std::endl;
                        r=lerp(ri,rf,x-x1,x2-x1);
                        g=lerp(gi,gf,x-x1,x2-x1);
                        b=lerp(bi,bf,x-x1,x2-x1);
                        r *=  zdiff;
                        g *=  zdiff;
                        b *=  zdiff;
                      //  std::cout<<"r = "<<r<<std::endl;
                       // std::cout<<"g = "<<g<<std::endl;
                      //  std::cout<<"b = "<<b<<std::endl;
                         color = (0xff << 24) + (r << 16) + (g << 8) + b;

                         //std::cout<<"color = " <<color<< std::endl;
                         //drawable->setPixel(x1, y,color);

                }
                else if (error >= 0){
                    error += t2;
                    if (y2>y1){
                        y++;
                        //std::cout<<"5"<<std::endl;
                        float z;
                        if (z1 != z2){
                            z = lerp(z1,z2,x-x1,x2-x1);
                        }
                        else{
                            z = z1;
                        }
                        //std::cout<<"z = "<<z<<std::endl;
                        float zdiff = (1- (z/200));
                       // std::cout<<"zdiff = "<<zdiff<<std::endl;
                        r=lerp(ri,rf,x-x1,x2-x1);
                        r = r * zdiff;
                       // std::cout<<"r = " <<r<< std::endl;
                        g=lerp(gi,gf,x-x1,x2-x1);
                        g *=  zdiff;
                       // std::cout<<"g = " <<g<< std::endl;
                        b=lerp(bi,bf,x-x1,x2-x1);
                        b *=  zdiff;
                       // std::cout<<"b = " <<b<< std::endl;
                        color = (0xff << 24) + (r << 16) + (g << 8) + b;
                    }
                    else{
                        y--;
                       // std::cout<<"6"<<std::endl;
                        float z;
                        if (z1 != z2){
                            z = lerp(z1,z2,x-x1,x2-x1);
                        }
                        else{
                            z = z1;
                        }
                        float zdiff = (1- (z/200));
                        r=lerp(ri,rf,x-x1,x2-x1);
                        r = r * zdiff;
                        //std::cout<<"r = " <<r<< std::endl;
                        g=lerp(gi,gf,x-x1,x2-x1);
                        g *=  zdiff;
                        //std::cout<<"g = " <<g<< std::endl;
                        b=lerp(bi,bf,x-x1,x2-x1);
                        b *=  zdiff;
                        //std::cout<<"b = " <<b<< std::endl;
                        color = (0xff << 24) + (r << 16) + (g << 8) + b;
                    }
                }
                else{
                    error +=two_dy;
                    //std::cout<<"what3"<<std::endl;
                    float z;
                    if (z1 != z2){
                        z = lerp(z1,z2,x-x1,x2-x1);
                    }
                    else{
                        z = z1;
                    }
                    float zdiff = (1- (z/200));
                    r=lerp(ri,rf,x-x1,x2-x1);
                    //std::cout<<"r = " <<r<< std::endl;
                    g=lerp(gi,gf,x-x1,x2-x1);
                    //std::cout<<"g = " <<g<< std::endl;
                    b=lerp(bi,bf,x-x1,x2-x1);
                    r *=  zdiff;
                    g *=  zdiff;
                    b *=  zdiff;
                    //std::cout<<"b = " <<b<< std::endl;
                    color = (0xff << 24) + (r << 16) + (g << 8) + b;
                }
                if(x >=50){
                    if(y >=50){
                        drawable->setPixel(x, y,color);
                    }
                }
            }
        }
        else{ //dy<0
            for( int x=x1-1; x>=x2; x--){
                if (error >= 0){
                    error += t2;
                    if (y2>=y1){
                        y++;
                        //std::cout<<"7"<<std::endl;
                        float z;
                        if (z1 != z2){
                            z = lerp(z1,z2,x1-x,x1-x2);
                        }
                        else{
                            z = z1;
                        }
                         float zdiff = (1- (z/200));
                        r=lerp(ri,rf,x1-x,x1-x2);
                       // std::cout<<"r = " << r <<std::endl;
                        g=lerp(gi,gf,x1-x,x1-x2);
                       // std::cout<<"g = " << g <<std::endl;
                        b=lerp(bi,bf,x1-x,x1-x2);
                       // std::cout<<"b = " << b <<std::endl;
                        r *=  zdiff;
                        g *=  zdiff;
                        b *=  zdiff;
                        color = (0xff << 24) + (r << 16) + (g << 8) + b;
                    }
                    else{
                        y--;
                        //std::cout<<"8"<<std::endl;
                        float z;
                        if (z1 != z2){
                            z = lerp(z1,z2,x1-x,x1-x2);
                        }
                        else{
                            z = z1;
                        }
                        float zdiff = (1- (z/200));
                        r=lerp(ri,rf,x1-x,x1-x2);
                       // std::cout<<"r = " << r <<std::endl;
                        g=lerp(gi,gf,x1-x,x1-x2);
                       // std::cout<<"g = " << g <<std::endl;
                        b=lerp(bi,bf,x1-x,x1-x2);
                       // std::cout<<"b = " << b <<std::endl;
                        r *=  zdiff;
                        g *=  zdiff;
                        b *=  zdiff;
                        color = (0xff << 24) + (r << 16) + (g << 8) + b;
                    }
                }
                else{
                    error +=two_dy;
                    //std::cout<<"what4"<<std::endl;
                    float z;
                    if (z1 != z2){
                        z = lerp(z1,z2,x1-x,x1-x2);
                    }
                    else{
                        z = z1;
                    }
                    float zdiff = (1- (z/200));
                    r=lerp(ri,rf,x1-x,x1-x2);
                   // std::cout<<"r = " << r <<std::endl;

                    g=lerp(gi,gf,x1-x,x1-x2);
                   // std::cout<<"g = " << g <<std::endl;
                    b=lerp(bi,bf,x1-x,x1-x2);
                   // std::cout<<"b = " << b <<std::endl;
                    r *=  zdiff;
                    g *=  zdiff;
                    b *=  zdiff;
                    color = (0xff << 24) + (r << 16) + (g << 8) + b;
                }

                if(x >=50){
                    if(y >=50){
                        drawable->setPixel(x, y,color);
                    }
                }
            }
        }
    }
 }

//old triangle drawer was here from my first attempt, it was giving me erros while compiling
//so i just deleted it since i deleted it as it was unneeded.

void Client::drawTriangleDDA(const int x0, const int y0, const int x1, const int y1,const int x2, const int y2, unsigned int color){
    double m1 = float(y1 - y0) / float(x1 - x0);
    double m2 = float(y2 - y0) / float(x2 - x0);
    double b1 = y1 - (m1 *x1);
    double b2 = y2 - (m2 *x2);

    double m3 = (float(y2 - y1) / float(x2 - x1));
    double b3 = y1 + (m3 * x1);

    if(x1 >= x0 && y1 >= y0 && x2 >= x0 && y2 >= y0){ //bottom right
        for (double xline1 = x0; xline1<=x1; xline1++){
               for (double xline2 = x0; xline2<=x2; xline2++){
                   double yline1 = m1*xline1 + b1;
                   drawable->setPixel(xline1, round(yline1),color);
                   double yline2 = m2*xline2 + b2;
                   drawable->setPixel(xline2, round(yline2),color);
                   draw_lineDDA(xline1, round(yline1), xline2, round(yline2), color);
               }

        }
    }

    if(x1 <= x0 && y1 >= y0 && x2 <= x0 && y2 >=y0){  // bottom left
        for (double xline1 = x0; xline1>=x1; xline1--){
               for (double xline2 = x0; xline2>=x2; xline2--){
                   double yline1 = m1*xline1 + b1;
                   drawable->setPixel(xline1, round(yline1),color);
                   double yline2 = m2*xline2 + b2;
                   drawable->setPixel(xline2, round(yline2),color);
                   draw_lineDDA(xline1, round(yline1), xline2, round(yline2), color);
               }

        }
    }
    if(x1 <= x0 && y1 <= y0 && x2 <= x0 && y2 <= y0){
        for (double yline1 = y0; yline1>y1; yline1--){ //top left
            for (double yline2 = y0; yline2>y2; yline2--){
                double xline1 = (yline1 - b1) / m1;
                drawable->setPixel(round(xline1), yline1,color);
                double xline2 = (yline2 - b2) / m2;
                drawable->setPixel(round(xline2), yline2,color);
                draw_lineDDA(round(xline2), yline2, round(xline1), yline1, color);
            }
         }
    }

    if(x1 >= x0 && y1 <= y0 && x2 >= x0 && y2 <= y0){
        for (double yline1 = y0; yline1>=y1; yline1--){ //top right
            for (double yline2 = y0; yline2>=y2; yline2--){
                double xline1 = (yline1 - b1) / m1;
                drawable->setPixel(round(xline1), yline1,color);
                double xline2 = (yline2 - b2) / m2;
                drawable->setPixel(round(xline2), yline2,color);         
                draw_lineDDA(round(xline1), yline1, round(xline2), yline2, color);
            }
         }
    }
}

void Client::drawTriangleBresVersion2( int x0,  int y0, int z0,  int x1,  int y1, int z1, int x2, int y2, int z2, unsigned int r0, unsigned int g0, unsigned int b0,unsigned int r1, unsigned int g1, unsigned int b1,unsigned int r2, unsigned int g2, unsigned int b2){
    //first sort triangle by increasing y values

    //begin sort
    int temp_y;
    int temp_x;
    int temp_z;
    unsigned int temp_r;
    unsigned int temp_g;
    unsigned int temp_b;
    if(y0 > y2){
        temp_y = y2;
        y2=y0;
        y0=temp_y;

        temp_z = z2;
        z2=z0;
        z0=temp_z;

        temp_x = x2;
        x2=x0;
        x0=temp_x;

        temp_r = r2;
        r2=r0;
        r0=temp_r;

        temp_g = g2;
        g2=g0;
        g0=temp_g;

        temp_b = b2;
        b2=b0;
        b0=temp_b;

    }
    if(y0 > y1){
        temp_y = y1;
        y1=y0;
        y0=temp_y;

        temp_z = z1;
        z1=z0;
        z0=temp_z;

        temp_x = x1;
        x1=x0;
        x0=temp_x;

        temp_r = r1;
        r1=r0;
        r0=temp_r;

        temp_g= g1;
        g1=g0;
        g0=temp_g;

        temp_b = b1;
        b1=b0;
        b0=temp_b;
    }
    if(y1>y2){
        temp_y = y2;
        y2=y1;
        y1=temp_y;

        temp_z = z1;
        z2=z1;
        z1=temp_z;

        temp_x= x2;
        x2=x1;
        x1=temp_x;

        temp_r= r2;
        r2=r1;
        r1=temp_r;

        temp_g= g2;
        g2=g1;
        g1=temp_g;

        temp_b= b2;
        b2=b1;
        b1=temp_b;
    }

    std::cout<< "x0 = " << x0 << ", y0 = " << y0 << ", z0 = " << z0 << ", r0 = " << r0 << ", g0 = " << g0 << ", b0 = " << b0 <<std::endl;
    std::cout<< "x1 = " << x1 << ", y1 = " << y1 << ", z1 = " << z1 << ", r1 = " << r1 << ", g1 = " << g1 << ", b1 = " << b1 << std::endl;
    std::cout<< "x2 = " << x2 << ", y2 = " << y2 << ", z1 = " << z2 << ", r2 = " << r2 << ", g2 = " << g2 << ", b2 = " << b2 << std::endl;

    //end sort

    if(y1 == y2){ //triangle is going down
        std::cout<<"1"<<std::endl;
        float slope1 = float(x1-x0)/float(y1-y0);
        float slope2 = float(x2-x0)/float(y2-y0);

        float xline1 = x0;
        float xline2 = x0;

        for (int y = y0; y<=y1; y++){


            unsigned int temp_r1=lerp(r0,r1,y-y0,y1-y0);
            unsigned int temp_g1=lerp(g0,g1,y-y0,y1-y0);
            unsigned int temp_b1=lerp(b0,b1,y-y0,y1-y0);

            unsigned int temp_r2=lerp(r0,r2,y-y0,y1-y0);
            unsigned int temp_g2=lerp(g0,g2,y-y0,y1-y0);
            unsigned int temp_b2=lerp(b0,b2,y-y0,y1-y0);

            unsigned int temp_z1 = lerp(z0,z1,y-y0,y1-y0);
            unsigned int temp_z2 = lerp(z0,z2,y-y0,y1-y0);

            draw_lineBres(int(xline1), y, temp_z1, int(xline2), y, temp_z2, temp_r1 , temp_g1 , temp_b1, temp_r2, temp_g2, temp_b2);
            xline1+=slope1;
            xline2+=slope2;
        }
    }
    else if(y0 == y1){ //triangle is going up
        std::cout<<"2"<<std::endl;
        float slope1 = float(x2-x0)/float(y2-y0);
        float slope2 = float(x2-x1)/float(y2-y1);

        float xline1 = x2;
        float xline2 = x2;

        for (int y = y2; y>=y0; y--){


            unsigned int temp_r1=lerp(r2,r1,y2-y,y2-y0);
            unsigned int temp_g1=lerp(g2,g1,y2-y,y2-y0);
            unsigned int temp_b1=lerp(b2,b1,y2-y,y2-y0);

            unsigned int temp_r2=lerp(r2,r0,y2-y,y2-y0);
            unsigned int temp_g2=lerp(g2,g0,y2-y,y2-y0);
            unsigned int temp_b2=lerp(b2,b0,y2-y,y2-y0);

            unsigned int temp_z1 = lerp(z2,z1,y2-y,y2-y0);
            unsigned int temp_z2 = lerp(z2,z0,y2-y,y2-y0);

           //std::cout<<"r1 = " << r1<<std::endl;
            //std::cout<<"g1 = " << g1 <<std::endl;
            //std::cout<<"b1 = " << b1 <<std::endl;
            draw_lineBres(int(xline1), y, temp_z2, int(xline2), y, temp_z1,   temp_r2 , temp_g2 , temp_b2, temp_r1, temp_g1, temp_b1);
            xline1-=slope1;
            xline2-=slope2;
        }
    }
    else{ // find point on longest line that is on the same y as the middle point, splits up triangle into 2 parts
        float slope3 = float(y1-y0)/ float(y2-y0);
        int x3 = x0 + slope3 * (x2-x0);
        int y3 = y1;

        float slope1 = float(x1-x0)/float(y1-y0);
        float slope2 = float(x3-x0)/float(y3-y0);

        float xline1 = x0;
        float xline2 = x0;


        float rmidpoint = lerp(r0,r2,y1-y0,y2-y0); //(r1-r0)/slope2;
        float gmidpoint = lerp(g0,g2,y1-y0,y2-y0);
        float bmidpoint = lerp(b0,b2,y1-y0,y2-y0);

        float zmidpoint = lerp(z0,z2,y1-y0,y2-y0);
       // std::cout<< "rmid point = " <<rmidpoint<< std::endl;
       // std::cout<< "gmid point = " <<gmidpoint<< std::endl;
       // std::cout<< "bmid point = " <<bmidpoint<< std::endl;

        for (int y = y0; y<=y1; y++){


            unsigned int temp_r1=lerp(r0,r1,y-y0,y1-y0);
            unsigned int temp_g1=lerp(g0,g1,y-y0,y1-y0);
            unsigned int temp_b1=lerp(b0,b1,y-y0,y1-y0);

            unsigned int temp_r2=lerp(r0,rmidpoint,y-y0,y1-y0);
            unsigned int temp_g2=lerp(g0,gmidpoint,y-y0,y1-y0);
            unsigned int temp_b2=lerp(b0,bmidpoint,y-y0,y1-y0);

            unsigned int temp_z1 = lerp(z0,z1,y-y0,y1-y0);
            unsigned int temp_z2 = lerp(z0,zmidpoint,y-y0,y1-y0);

            draw_lineBres(int(xline1), y, temp_z1, int(xline2), y, temp_z2, temp_r1 , temp_g1 , temp_b1, temp_r2, temp_g2, temp_b2);
            xline1+=slope1;
            xline2+=slope2;
        }

        slope1 = float(x2-x1)/float(y2-y1);
        slope2 = float(x2-x3)/float(y2-y3);

        xline1 = x2;
        xline2 = x2;


        for (int y = y2; y>=y1; y--){


            unsigned int temp_r1=lerp(r2,rmidpoint,y2-y,y2-y1);
            unsigned int temp_g1=lerp(g2,gmidpoint,y2-y,y2-y1);
            unsigned int temp_b1=lerp(b2,bmidpoint,y2-y,y2-y1);

            unsigned int temp_r2=lerp(r2,r1,y2-y,y2-y1);
            unsigned int temp_g2=lerp(g2,g1,y2-y,y2-y1);
            unsigned int temp_b2=lerp(b2,b1,y2-y,y2-y1);

            unsigned int temp_z1 = lerp(z2,zmidpoint,y2-y,y2-y1);
            unsigned int temp_z2 = lerp(z2,z1,y2-y,y2-y1);

           //std::cout<<"r1 = " << r1<<std::endl;
            //std::cout<<"g1 = " << g1 <<std::endl;
            //std::cout<<"b1 = " << b1 <<std::endl;
            draw_lineBres(int(xline1), y, temp_z2, int(xline2), y, temp_z1,   temp_r2 , temp_g2 , temp_b2, temp_r1, temp_g1, temp_b1);
            xline1-=slope1;
            xline2-=slope2;
        }
    }


    float centerx= (x0+x1+x2)/3;
    float centery= (y0+y1+y2)/3;
    float centerz= (z0+z1+z2)/3;

    if(centerx >=50){
        if(centery >=50){
            drawable->setPixel(centerx, centery,0xffffffff);
            drawable->setPixel(centerx+1, centery,0xffffffff);
            drawable->setPixel(centerx-1, centery,0xffffffff);
            drawable->setPixel(centerx, centery+1,0xffffffff);
            drawable->setPixel(centerx, centery-1,0xffffffff);

        }
    }


}

void Client::translate( float tx, float ty, float tz){
   std::cout<<"we in1"  <<std::endl;
   unsigned int  temp_color;
   std::cout<<"we in2"  <<std::endl;
   unsigned int*  colorx =new unsigned int[422500];
   unsigned int*  colory =new unsigned int[422500];
   unsigned int*  color =new unsigned int[422500];
   int i =0;
   for( int y = 50; y<650; y++){
       for(int x = 50; x< 650; x++){
           temp_color = drawable->getPixel(x, y);
           //std::cout<<"temp_color = "<<temp_color <<std::endl;
           if(temp_color != 0xff000000){//pixel isnt black, we translate
               colorx[i]= x;
               //std::cout<<"colorx[1] = "<<colorx[1] <<std::endl;
               colory[i]= y;
               //std::cout<<"colory[1] = "<<colory[1] <<std::endl;
               color[i]=temp_color;
               i++;
               if(x >=50){
                   if(y >=50){
                       drawable->setPixel(x,y,0xff000000);
                   }
               }
           }
       }
    }
   for (int j = 0; j<i+1; j++){
       //std::cout<< i <<std::endl;
       unsigned int r = ((color[j] >> 16) & 255) * (1- (tz/200));
       unsigned int g = ((color[j] >> 8) & 255) * (1- (tz/200));
       unsigned int b = (color[j] & 255) * (1- (tz/200));

       unsigned int newcolor = (0xff << 24) + (r << 16) + (g << 8) + b;

       if(colorx[j]+tx >=50){
           if(colory[j]+ty >=50){
               drawable->setPixel(colorx[j]+tx,colory[j]+ty,newcolor);
           }
       }

   }
   delete[] colorx;
   delete[] colory;
   delete[] color;
}

void Client::rotate( char axis, int angle){
   double  temp_color;

   //std::cout<<"we in"  <<std::endl;
   double*  colorx =new double[422500];
   double*  colory =new double[422500];
   double*  color =new double[422500];
   double radians = angle * M_PI /180;
   int i =0;
   //std::cout<<"Radians = " << radians <<std::endl;
   for( int y = 50; y<650; y++){
       for(int x = 50; x< 650; x++){
           temp_color = drawable->getPixel(x, y);
           //std::cout<<"temp_color = "<<temp_color <<std::endl;
           if(temp_color != 0xff000000){
               colorx[i]= x;
               //std::cout<<"colorx[1] = "<<colorx[1] <<std::endl;
               colory[i]= y;
               //std::cout<<"colory[1] = "<<colory[1] <<std::endl;
               color[i]=temp_color;
               i++;
               drawable->setPixel(x,y,0xff000000);
            }
       }
    }
  // std::cout<<"colorx[0] = "<<colorx[0] <<std::endl;
  // std::cout<<"colory[0] = "<<colory[0] <<std::endl;

    /*std::cout<<"DONE COPY" <<std::endl;
    std::cout<<"DONE COPY" <<std::endl;
    std::cout<<"________________________________________________________________________" <<std::endl;
    std::cout<<"DONE COPY" <<std::endl;
    std::cout<<"DONE COPY" <<std::endl

   std::cout<<"colorx[0] = " << colorx[0] <<std::endl;
   std::cout<<"colory[0] = " << colory[0] <<std::endl;
   std::cout<<"cos(radians) = " << cos(radians) <<std::endl;
   std::cout<<"sin(radians) = " << sin(radians) <<std::endl;*/
   for (int j = 0; j<i+1; j++){
        double xcoord = 350 + (colorx[j]-350)* cos(radians) - (colory[j]-350)*sin(radians);
        //std::cout<<"Xcoord = " << xcoord <<std::endl;
        double ycoord = 350 + (colorx[j]-350)* sin(radians) + (colory[j]-350)*cos(radians);
       // std::cout<<"Ycoord = " << ycoord <<std::endl;
        if(xcoord >=50){
            if(ycoord >=50){
                drawable->setPixel(xcoord,ycoord,color[j]);
            }
        }
   }
   delete[] colorx;
   delete[] colory;
   delete[] color;
}

float* Client::CalculateFaceNormal(float x0, float y0, float z0, float x1, float y1, float z1,float x2, float y2, float z2, float normal[]){
   /* float ux = x1 - x0;
    float uy = y1 - y0;
    float uz = z1 - z0;

    float vx = x2 - x1;
    float vy = y2 - y1;
    float vz = z2 - z1;

    float xval = (uy * vz) - (uz * vy); //perpendicular x, cross product of two edges of a polygon
    float yval = (uz * vx) - (ux * vz); // y
    float zval = (ux * vy) - (uy * vx); //z*/

    normalize((x1-x0) * (x2-x0),(y1-y0) * (y2-y0),(z1-z0) * (z2-z0), normal );

    /*normal[0] = xval/(abs(xval)+abs(yval)+abs(zval));
    normal[1] = yval/(abs(xval)+abs(yval)+abs(zval));
    normal[2] = zval/(abs(xval)+abs(yval)+abs(zval));*/

   /* float distance = sqrt(pow(xval,2.0) + pow(yval,2.0) +pow(zval,2.0));
    std::cout <<distance <<std::endl;

    float distance2 = sqrt((xval*xval)+(yval+yval)+(zval+zval));
    std::cout <<distance2 <<std::endl;


    normal[0] = xval/distance2;
    normal[1] = yval/distance2;
    normal[2] = zval/distance2;*/
    return normal;
}

float Client::dot(float x1, float y1, float z1, float x2, float y2, float z2){
    float result = (x1 * x2) + (y1 * y2) + (z1*z2);
    return result;
}

float* Client::normalize(float x, float y, float z,float normal[] ){
    float x2 = x*x;
    float y2=y*y;
    float z2=z*z;

    float length = sqrt((x2+y2+z2));

    normal[0] =x/length;
    normal[1] =y/length;
    normal[2] =z/length;
    return normal;
}
