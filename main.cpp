#include <iostream>
#include "math.h"
#include <SFML/Graphics.hpp>


double f(double_t x)
{
    return (sin(x));
}

int main() {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    int SX=1000;
    int SY=700;
    int mas=50;//масштаб - mas пикселей на 1
    sf::RenderWindow window( sf::VideoMode(SX,SY), "Graphic");
    sf::Vertex lineX[] =
            {
                    sf::Vertex(sf::Vector2f(0, SY/2)),
                    sf::Vertex(sf::Vector2f(SX*1, SY/2))
            };
    sf::Vertex lineY[] =
            {
                    sf::Vertex(sf::Vector2f(SX/2, 0)),
                    sf::Vertex(sf::Vector2f(SX/2, SY/1))
            };
    sf::Vertex lineMy[] =
            {
                    sf::Vertex(sf::Vector2f((SX/2+mas)*1.f, (SY/2-mas/2)*1.f)),
                    sf::Vertex(sf::Vector2f((SX/2+mas)*1.f, (SY/2+mas/2)*1.f))
            };
    sf::Vertex lineMx[] =
            {
                    sf::Vertex(sf::Vector2f((SX/2-mas/2)*1.f, (SY/2-mas)*1.f)),
                    sf::Vertex(sf::Vector2f((SX/2+mas/2)*1.f, (SY/2-mas)*1.f))
            };
    int s=5;
    int *x=new int[SX/s];
    int *y=new int[SX/s];
    double l;

    for (int i = 0; i <= SX/s; ++i) {
        x[i]=s*i;
        double d=f((double)(-SX/2+x[i])/mas)*mas;
        y[i]=(int)(SY/2-d);
        //printf("%i %i %f\n", x[i], y[i],d);
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
            //line->color=sf::Color(20,10,y[i],255);

            //line[0].color=sf::Color::Red;


            line[0].color=sf::Color(200,a,10,255);
            line[1].color=line[0].color;

            window.draw(line, 2, sf::Lines);
        }

        //window.clear();
        window.draw(lineX, 2, sf::Lines);
        window.draw(lineY, 2, sf::Lines);
        window.draw(lineMy, 2, sf::Lines);
        window.draw(lineMx, 2, sf::Lines);


        window.display();
    }


    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
