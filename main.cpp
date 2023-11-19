#include <iostream>
#include "math.h"
#include <SFML/Graphics.hpp>


double f(double_t x)
{
    //return (sin(x));
    return pow((x-1),2)-0;
}

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    int SX=1000;
    int SY=700;
    int mas=50;//масштаб - mas пикселей на единичный отрезок
    sf::RenderWindow window( sf::VideoMode(SX,SY), "Graphic");
    //рисование осей по центру окна
    {
        sf::Vertex lineX[] =
                {
                        sf::Vertex(sf::Vector2f(0, SY / 2)),
                        sf::Vertex(sf::Vector2f(SX * 1, SY / 2))
                };
        sf::Vertex lineY[] =
                {
                        sf::Vertex(sf::Vector2f(SX / 2, 0)),
                        sf::Vertex(sf::Vector2f(SX / 2, SY / 1))
                };
        sf::Vertex lineMy[] =
                {
                        sf::Vertex(sf::Vector2f((SX / 2 + mas) * 1.f, (SY / 2 - mas / 2) * 1.f)),
                        sf::Vertex(sf::Vector2f((SX / 2 + mas) * 1.f, (SY / 2 + mas / 2) * 1.f))
                };
        sf::Vertex lineMx[] =
                {
                        sf::Vertex(sf::Vector2f((SX / 2 - mas / 2) * 1.f, (SY / 2 - mas) * 1.f)),
                        sf::Vertex(sf::Vector2f((SX / 2 + mas / 2) * 1.f, (SY / 2 - mas) * 1.f))
                };
    }
    int s=10; int p=-SX/s*2;
    double xc=0,yc;//координаты центра графика
    //массивы для компьютерных координат
    int *x=new int[SX/s];
    int *y=new int[SX/s];
    //ищем "центр" графика
    for (int i = -SX/s; i <= SX/s; ++i) {
        double d1=f((double)(-SX/2+p-s)/mas)*mas;
        double d2=f((double)(-SX/2+p)/mas)*mas;
        double d3=f((double)(-SX/2+p+s)/mas)*mas;
        if ((d1-d2)*(d2-d3)<=0) {xc=p;
            //printf("%i %i",p,(-SX/2+p+s)/mas);
            break;}
        p+=s;
    }
    yc=(int)(-f((double)(-SX/2+xc)/mas)*mas);
    //printf("%f %f",xc,yc);
    //рисование осей по центру окна

        sf::Vertex lineX[] =
                {
                        sf::Vertex(sf::Vector2f(0, SY / 2-yc)),
                        sf::Vertex(sf::Vector2f(SX , SY / 2-yc))
                };
        sf::Vertex lineY[] =
                {
                        sf::Vertex(sf::Vector2f(SX-xc, 0)),
                        sf::Vertex(sf::Vector2f(SX-xc, SY ))
                };


    //обсчет графика
    for (int i = 0; i <= SX/s; ++i) {
        x[i]=s*i;
        double d=f((double)(xc-SX+x[i])/mas)*mas;
        y[i]=(int)(SY/2-d-yc);
    }
    float a=0,b=0.1;
    while (window. isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if ((a>255)||(a<0)) b=b*(-1);
        a+=b;
        for (int i = 0; i < SX/s; ++i) {
            sf::Vertex line[] =
                    {
                            sf::Vertex(sf::Vector2f(x[i], y[i])),
                            sf::Vertex(sf::Vector2f(x[i+1], y[i+1]))
                    };


            line[0].color=sf::Color::Red;
            //line[0].color=sf::Color(200,a,10,255);
            line[1].color=line[0].color;

            window.draw(line, 2, sf::Lines);
        }

        //window.clear();

        window.draw(lineX, 2, sf::Lines);
        window.draw(lineY, 2, sf::Lines);
         /*
        window.draw(lineMy, 2, sf::Lines);
        window.draw(lineMx, 2, sf::Lines);
*/

        window.display();
    }


    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
